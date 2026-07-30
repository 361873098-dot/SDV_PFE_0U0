# -*- coding: utf-8 -*-
"""convert_fls_to_spi_sdr.py
Convert Bootloader Fls.xdm from octal-DOPI(DDR) config to 1-line SPI SDR config,
matching the OLD BL's proven-working QSPI setup (CMD 0x03 + 24-bit ADDR + PADS_1 + SDR).

Container names are preserved so all ASPath references stay valid.
Input : Fls.xdm (octal version, backed up as Fls.xdm.bak_octal_20260728)
Output: Fls.xdm (in place)
"""
import re, sys, io

PATH = r"D:\work\NXP_S32DS\HPC_PFE\Hpc_m7_prj\tools\tresos_mcore_bsw\workspace\Bootloader_S32G3XX_ASR_4.4_M7\config\Fls.xdm"

with io.open(PATH, "r", encoding="utf-8") as f:
    text = f.read()

orig = text
changes = []

# ---------------------------------------------------------------
# 1. Controller-level settings (both ControllerCfg_0 and _1)
# ---------------------------------------------------------------
n = text.count('value="QSPI_IP_DATA_RATE_DDR"')
text = text.replace('value="QSPI_IP_DATA_RATE_DDR"', 'value="QSPI_IP_DATA_RATE_SDR"')
changes.append(("FlsHwUnitReadMode DDR->SDR", n))

n = text.count('value="QSPI_IP_READ_MODE_EXTERNAL_DQS"')
text = text.replace('value="QSPI_IP_READ_MODE_EXTERNAL_DQS"', 'value="QSPI_IP_READ_MODE_LOOPBACK"')
changes.append(("SamplingMode EXTERNAL_DQS->LOOPBACK", n))

n = text.count('value="QSPI_IP_FLASH_DATA_ALIGN_2X_REFCLK"')
text = text.replace('value="QSPI_IP_FLASH_DATA_ALIGN_2X_REFCLK"', 'value="QSPI_IP_FLASH_DATA_ALIGN_REFCLK"')
changes.append(("Tdh 2X_REFCLK->REFCLK", n))

n = text.count('value="QSPI_IP_DLL_AUTO_UPDATE"')
text = text.replace('value="QSPI_IP_DLL_AUTO_UPDATE"', 'value="QSPI_IP_DLL_BYPASSED"')
changes.append(("DllMode AUTO_UPDATE->BYPASSED", n))

# ByteSwapping true -> false (exists only once with value true, in ControllerCfg_1)
pat_bs = re.compile(r'(<d:var name="FlsHwUnitByteSwapping" type="BOOLEAN"\s*\n\s*value=")true(")')
text, n = pat_bs.subn(r"\1false\2", text)
changes.append(("ByteSwapping true->false", n))

# ---------------------------------------------------------------
# 2. resetSettings: point to ResetEnable_dopi (0x66 first, then 0x99)
# ---------------------------------------------------------------
old_ref = ('<d:ref name="resetCmdLut" type="REFERENCE" \n'
           '                               value="ASPath:/Fls/Fls/FlsConfigSet/FlsExternalDriver/MemCfg_0/Reset_dopi">')
new_ref = ('<d:ref name="resetCmdLut" type="REFERENCE" \n'
           '                               value="ASPath:/Fls/Fls/FlsConfigSet/FlsExternalDriver/MemCfg_0/ResetEnable_dopi">')
n = text.count(old_ref)
text = text.replace(old_ref, new_ref)
changes.append(("resetSettings ref Reset_dopi->ResetEnable_dopi", n))

# ---------------------------------------------------------------
# 3. Rewrite LUT instruction pairs to 1-line SPI SDR
# ---------------------------------------------------------------
# (instruction, pads, operand)
CMD, ADDR, READ, WRITE, DUMMY = ("QSPI_IP_LUT_INSTR_CMD", "QSPI_IP_LUT_INSTR_ADDR",
                                 "QSPI_IP_LUT_INSTR_READ", "QSPI_IP_LUT_INSTR_WRITE",
                                 "QSPI_IP_LUT_INSTR_DUMMY")
P1 = "QSPI_IP_LUT_PADS_1"

LUTS = {
    # AHB/IP read: standard READ 0x03, 24-bit addr, no dummy  (== OLD BL live LUT)
    "Read_dopi":        [(CMD, P1, 3),   (ADDR, P1, 24), (READ, P1, 16)],
    # Page program 0x02
    "Write_dopi":       [(CMD, P1, 2),   (ADDR, P1, 24), (WRITE, P1, 16)],
    # Sector erase 4KB 0x20
    "Erase_dopi":       [(CMD, P1, 32),  (ADDR, P1, 24)],
    # RDSR 0x05
    "ReadSR_dopi":      [(CMD, P1, 5),   (READ, P1, 1)],
    # WRSR 0x01
    "WriteSR_dopi":     [(CMD, P1, 1),   (WRITE, P1, 1)],
    # WREN 0x06
    "WriteEnable_dopi": [(CMD, P1, 6)],
    # RSTEN 0x66
    "ResetEnable_dopi": [(CMD, P1, 102)],
    # RST 0x99
    "Reset_dopi":       [(CMD, P1, 153)],
    # FAST READ 0x0B, 24-bit addr, 8 dummy cycles
    "FastRead":         [(CMD, P1, 11),  (ADDR, P1, 24), (DUMMY, P1, 8), (READ, P1, 16)],
    # PP 0x02 (plain SPI)
    "FastWrite":        [(CMD, P1, 2),   (ADDR, P1, 24), (WRITE, P1, 16)],
    # RDID 0x9F, read 3 bytes
    "ReadId_dopi":      [(CMD, P1, 159), (READ, P1, 3)],
    # RDCR2 / WRCR2 / WriteEnable / ReadSR are already PADS_1 SPI -> untouched
}

IND_LST  = " " * 26   # <d:lst name="FlsInstructionOperandPair" ...>
IND_CTR  = " " * 28   # <d:ctr name="FlsInstructionOperandPair_N" ...>
IND_VAR  = " " * 30   # <d:var ...>

def build_pairs_block(pairs):
    out = []
    out.append(IND_LST + '<d:lst name="FlsInstructionOperandPair" type="MAP">')
    for i, (instr, pad, oper) in enumerate(pairs):
        out.append(IND_CTR + '<d:ctr name="FlsInstructionOperandPair_%d" ' % i)
        out.append(IND_CTR + '       type="IDENTIFIABLE">')
        out.append(IND_VAR + '<d:var name="FlsInstrOperPairIndex" ')
        out.append(IND_VAR + '       type="INTEGER" value="%d"/>' % i)
        out.append(IND_VAR + '<d:var name="FlsLUTInstruction" ')
        out.append(IND_VAR + '       type="ENUMERATION" ')
        out.append(IND_VAR + '       value="%s"/>' % instr)
        out.append(IND_VAR + '<d:var name="FlsLUTPad" type="ENUMERATION" ')
        out.append(IND_VAR + '       value="%s"/>' % pad)
        out.append(IND_VAR + '<d:var name="FlsLUTOperand" type="INTEGER" ')
        out.append(IND_VAR + '       value="%d"/>' % oper)
        out.append(IND_CTR + '</d:ctr>')
    out.append(IND_LST + '</d:lst>')
    return "\n".join(out)

def find_block(text, ctr_name, start=0):
    """Return (blk_start, blk_end) of <d:ctr name="ctr_name" ...> ... matching </d:ctr>."""
    m = re.search(r'<d:ctr name="%s" type="IDENTIFIABLE">' % re.escape(ctr_name), text[start:])
    if not m:
        return None
    s = start + m.start()
    depth = 0
    pos = s
    tag = re.compile(r'<d:ctr\b|</d:ctr>')
    while True:
        m2 = tag.search(text, pos)
        if not m2:
            raise RuntimeError("unbalanced ctr for " + ctr_name)
        if m2.group(0).startswith("<d:ctr"):
            depth += 1
        else:
            depth -= 1
            if depth == 0:
                return (s, m2.end())
        pos = m2.end()

for name, pairs in LUTS.items():
    blk = find_block(text, name)
    if blk is None:
        print("ERROR: LUT container not found:", name)
        sys.exit(1)
    s, e = blk
    block = text[s:e]
    # locate inner FlsInstructionOperandPair list
    m = re.search(r'[ \t]*<d:lst name="FlsInstructionOperandPair" type="MAP">.*?</d:lst>',
                  block, re.S)
    if not m:
        print("ERROR: pair list not found in", name)
        sys.exit(1)
    new_block = block[:m.start()] + build_pairs_block(pairs) + block[m.end():]
    text = text[:s] + new_block + text[e:]
    changes.append(("LUT %s -> %d SPI pairs" % (name, len(pairs)), 1))

with io.open(PATH, "w", encoding="utf-8", newline="") as f:
    f.write(text)

print("== conversion done ==")
for what, cnt in changes:
    flag = "OK " if cnt > 0 else "!!!"
    print("  [%s] %-50s x%d" % (flag, what, cnt))
print("file size: %d -> %d" % (len(orig), len(text)))
