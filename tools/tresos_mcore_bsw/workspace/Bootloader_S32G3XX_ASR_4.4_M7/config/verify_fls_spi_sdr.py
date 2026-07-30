# -*- coding: utf-8 -*-
"""verify_fls_spi_sdr.py - static verification of the converted SPI-SDR Fls.xdm"""
import io, re, sys
import xml.etree.ElementTree as ET

PATH = r"D:\work\NXP_S32DS\HPC_PFE\Hpc_m7_prj\tools\tresos_mcore_bsw\workspace\Bootloader_S32G3XX_ASR_4.4_M7\config\Fls.xdm"

fails = []
def check(name, cond, detail=""):
    print("  [%s] %s %s" % ("PASS" if cond else "FAIL", name, detail))
    if not cond:
        fails.append(name)

print("== 1. XML well-formedness ==")
try:
    tree = ET.parse(PATH)
    check("XML parse", True)
except Exception as e:
    check("XML parse", False, str(e))
    sys.exit(1)

with io.open(PATH, "r", encoding="utf-8") as f:
    text = f.read()

print("== 2. No residual octal/DDR artifacts ==")
check("no PADS_8", "QSPI_IP_LUT_PADS_8" not in text)
check("no PADS_4", "QSPI_IP_LUT_PADS_4" not in text)
check("no CMD_DDR", "QSPI_IP_LUT_INSTR_CMD_DDR" not in text)
check("no ADDR_DDR", "QSPI_IP_LUT_INSTR_ADDR_DDR" not in text)
check("no READ_DDR", "QSPI_IP_LUT_INSTR_READ_DDR" not in text)
check("no WRITE_DDR", "QSPI_IP_LUT_INSTR_WRITE_DDR" not in text)
check("no DATA_RATE_DDR", "QSPI_IP_DATA_RATE_DDR" not in text)
check("no EXTERNAL_DQS", "QSPI_IP_READ_MODE_EXTERNAL_DQS" not in text)
check("no DLL_AUTO_UPDATE", "QSPI_IP_DLL_AUTO_UPDATE" not in text)

print("== 3. Controller settings ==")
check("2x DATA_RATE_SDR", text.count('value="QSPI_IP_DATA_RATE_SDR"') == 2,
      "found %d" % text.count('value="QSPI_IP_DATA_RATE_SDR"'))
check("4x LOOPBACK", text.count('value="QSPI_IP_READ_MODE_LOOPBACK"') == 4,
      "found %d" % text.count('value="QSPI_IP_READ_MODE_LOOPBACK"'))
check("no ByteSwapping=true",
      re.search(r'FlsHwUnitByteSwapping" type="BOOLEAN"\s*\n?\s*value="true"', text) is None)
check("4x DLL_BYPASSED", text.count('value="QSPI_IP_DLL_BYPASSED"') == 4,
      "found %d" % text.count('value="QSPI_IP_DLL_BYPASSED"'))

print("== 4. Key values preserved ==")
check("FlsQspiDeviceId=3834306 (C2 81 3A)", 'value="3834306"' in text)
check("MemCfgReadIdSize=3", '<d:var name="MemCfgReadIdSize" type="INTEGER" value="3"/>' in text)
check("initConfiguration empty", '<d:lst name="initConfiguration" type="MAP"/>' in text)
check("FlsController_0 -> ControllerCfg_1",
      'value="ASPath:/Fls/Fls/FlsConfigSet/FlsExternalDriver/ControllerCfg_1"/>' in text)

print("== 5. LUT sequences (decoded) ==")
root = tree.getroot()
def lname(e):
    return e.tag.split('}')[-1] if '}' in e.tag else e.tag
def find_ctr(name):
    for e in root.iter():
        if lname(e) == 'ctr' and e.get('name') == name:
            return e
    return None
def get_lut(name):
    ctr = find_ctr(name)
    if ctr is None:
        return None
    pairs = []
    for pair in ctr.iter():
        if lname(pair) == 'ctr' and (pair.get('name') or '').startswith('FlsInstructionOperandPair_'):
            instr = pad = oper = None
            for v in pair:
                if lname(v) == 'var':
                    n = v.get('name'); val = v.get('value')
                    if n == 'FlsLUTInstruction': instr = val
                    elif n == 'FlsLUTPad': pad = val
                    elif n == 'FlsLUTOperand': oper = val
            if instr is not None and pad is not None:
                pairs.append((instr.replace("QSPI_IP_LUT_INSTR_", ""),
                              pad.replace("QSPI_IP_LUT_PADS_", "P"),
                              int(oper)))
    return pairs

EXPect = {
    "Read_dopi":        [("CMD","P1",3),("ADDR","P1",24),("READ","P1",16)],
    "Write_dopi":       [("CMD","P1",2),("ADDR","P1",24),("WRITE","P1",16)],
    "Erase_dopi":       [("CMD","P1",32),("ADDR","P1",24)],
    "ReadSR_dopi":      [("CMD","P1",5),("READ","P1",1)],
    "WriteSR_dopi":     [("CMD","P1",1),("WRITE","P1",1)],
    "WriteEnable_dopi": [("CMD","P1",6)],
    "ResetEnable_dopi": [("CMD","P1",102)],
    "Reset_dopi":       [("CMD","P1",153)],
    "FastRead":         [("CMD","P1",11),("ADDR","P1",24),("DUMMY","P1",8),("READ","P1",16)],
    "FastWrite":        [("CMD","P1",2),("ADDR","P1",24),("WRITE","P1",16)],
    "ReadId_dopi":      [("CMD","P1",159),("READ","P1",3)],
    "WriteEnable":      [("CMD","P1",6)],
    "ReadSR":           [("CMD","P1",5),("READ","P1",1)],
}
for name, exp in EXPect.items():
    got = get_lut(name)
    ok = got == exp
    check("LUT %s" % name, ok, "" if ok else "got %s expected %s" % (got, exp))

print("== 6. LUT indexes unique & contiguous ==")
idx = [int(v) for v in re.findall(r'<d:var name="FlsLUTIndex" type="INTEGER" value="(\d+)"', text)]
check("15 LUTs idx 0..14", sorted(idx) == list(range(15)), str(sorted(idx)))

print("== 7. All ASPath references resolve to existing containers ==")
refs = set(re.findall(r'ASPath:/Fls/Fls/FlsConfigSet/FlsExternalDriver/MemCfg_0/([A-Za-z_0-9]+)', text))
ctrs = set(re.findall(r'<d:ctr name="([A-Za-z_0-9]+)" type="IDENTIFIABLE">', text))
missing = refs - ctrs
check("all LUT refs resolve", not missing, "missing: %s" % missing if missing else "")

print("== 8. resetSettings points to ResetEnable_dopi (0x66 then 0x99) ==")
m = re.search(r'<d:ctr name="resetSettings".*?value="ASPath:[^"]*/([A-Za-z_0-9]+)"', text, re.S)
check("resetSettings -> ResetEnable_dopi", m and m.group(1) == "ResetEnable_dopi",
      m.group(1) if m else "not found")

print()
if fails:
    print("RESULT: %d FAILURES: %s" % (len(fails), fails))
    sys.exit(1)
print("RESULT: ALL CHECKS PASSED")
