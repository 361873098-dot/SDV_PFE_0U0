
IPA constant propagation start:
Determining dynamic type for call: _2 = check_entry_type_vals (entry_18, type_19(D), port_20(D), seq_id_21(D), rx_22(D));
  Starting walk at: _2 = check_entry_type_vals (entry_18, type_19(D), port_20(D), seq_id_21(D), rx_22(D));
  instance pointer: entry_18  Outer instance pointer: entry_18 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_18 = isa_item (_1, index_11);
  Function call may change dynamic type:oal_mutex_lock.part.0 (40);
  Function call may change dynamic type:entry_18 = isa_item (_1, index_11);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  oal_mutex_unlock.part.0/230:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  oal_mutex_lock.part.0/229:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  isa_release/228:
  Jump functions of caller  isa_reserve/227:
  Jump functions of caller  isa_init/226:
  Jump functions of caller  autolibc_memset/225:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/224:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/223:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/222:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/221:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/220:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/219:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/218:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/217:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/216:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/215:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/214:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/213:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/212:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/211:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/210:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/209:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/208:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/207:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/206:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/205:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/204:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/203:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/202:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/201:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/200:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/199:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/198:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/197:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/196:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/195:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/194:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/193:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/192:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/191:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/190:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/189:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/188:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/187:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/186:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/185:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/184:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/183:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/182:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/181:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/180:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/179:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/178:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/177:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/176:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/175:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/174:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/173:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/172:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/171:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/170:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/169:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/168:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/167:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/166:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/165:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/164:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/163:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/162:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/161:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/160:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/159:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/158:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/157:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/156:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/155:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/154:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/153:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/152:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/151:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/150:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/149:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/148:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/147:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/146:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/145:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/144:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/143:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/142:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/141:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/140:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/139:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/138:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/137:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/136:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/135:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/134:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/133:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/132:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/131:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/130:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/129:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/128:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/127:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/126:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/125:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/124:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/123:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/122:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/121:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/120:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/119:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/118:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/117:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/116:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/115:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/114:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/113:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/112:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/111:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/110:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/109:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/108:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/107:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/106:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/105:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/104:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/103:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/102:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/101:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/100:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/99:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/98:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/97:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/96:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/95:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/94:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/93:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/92:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/91:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/90:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/89:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/88:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/87:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/86:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/85:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/84:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/83:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/82:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/81:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/80:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/79:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/78:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/77:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/76:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/75:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/74:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/73:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/72:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/71:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/70:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/69:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/68:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/67:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/66:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/65:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/64:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/63:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/62:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/61:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/60:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/59:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/58:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/57:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/56:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/55:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/54:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/53:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/52:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/51:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/50:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/49:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/48:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/47:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/46:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/45:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/44:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/43:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/42:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/41:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/40:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/39:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/38:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/37:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/36:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/35:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/34:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/33:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/32:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/31:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/30:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/29:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/28:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/27:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/26:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/25:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/24:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/23:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/22:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/21:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/20:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/19:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/18:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/17:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/16:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/15:
  Jump functions of caller  isa_release_subscript/14:
  Jump functions of caller  isa_item/13:
  Jump functions of caller  pfe_hif_ptp_ts_db_pop/12:
    callsite  pfe_hif_ptp_ts_db_pop/12 -> oal_mutex_unlock.part.0/230 : 
       param 0: CONST: 40
         value: 0x28, mask: 0x0
         Unknown VR
    callsite  pfe_hif_ptp_ts_db_pop/12 -> check_entry_type_vals/6 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 4: PASS THROUGH: 6, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_hif_ptp_ts_db_pop/12 -> oal_mutex_lock.part.0/229 : 
       param 0: CONST: 40
         value: 0x28, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_ptp_ts_db_push_ts/11:
    callsite  pfe_hif_ptp_ts_db_push_ts/11 -> oal_mutex_unlock.part.0/230 : 
       param 0: CONST: 39
         value: 0x27, mask: 0x0
         Unknown VR
    callsite  pfe_hif_ptp_ts_db_push_ts/11 -> oal_mutex_lock.part.0/229 : 
       param 0: CONST: 39
         value: 0x27, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_ptp_ts_db_push_msg/10:
    callsite  pfe_hif_ptp_ts_db_push_msg/10 -> oal_mutex_unlock.part.0/230 : 
       param 0: CONST: 38
         value: 0x26, mask: 0x0
         Unknown VR
    callsite  pfe_hif_ptp_ts_db_push_msg/10 -> oal_mutex_lock.part.0/229 : 
       param 0: CONST: 38
         value: 0x26, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_ptp_ts_db_fini/9:
    callsite  pfe_hif_ptp_ts_db_fini/9 -> oal_mutex_unlock.part.0/230 : 
       param 0: CONST: 37
         value: 0x25, mask: 0x0
         Unknown VR
    callsite  pfe_hif_ptp_ts_db_fini/9 -> oal_mutex_lock.part.0/229 : 
       param 0: CONST: 37
         value: 0x25, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_ptp_ts_db_init/8:
  Jump functions of caller  pfe_hif_ptp_ts_db_tick_iteration/7:
    callsite  pfe_hif_ptp_ts_db_tick_iteration/7 -> oal_mutex_unlock.part.0/230 : 
       param 0: CONST: 36
         value: 0x24, mask: 0x0
         Unknown VR
    callsite  pfe_hif_ptp_ts_db_tick_iteration/7 -> oal_mutex_lock.part.0/229 : 
       param 0: CONST: 36
         value: 0x24, mask: 0x0
         Unknown VR
  Jump functions of caller  check_entry_type_vals/6:

 Propagating constants:

Not considering pfe_hif_ptp_ts_db_pop for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_ptp_ts_db_push_ts for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_ptp_ts_db_push_msg for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_ptp_ts_db_fini for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_ptp_ts_db_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_ptp_ts_db_tick_iteration for cloning; -fipa-cp-clone disabled.

overall_size: 192, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: oal_mutex_unlock.part.0/230:
    param [0]: 36 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               37 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               38 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               39 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               40 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x28, mask = 0xf
         const oal_mutex_t [36, 40]
        AGGS VARIABLE
  Node: oal_mutex_lock.part.0/229:
    param [0]: 36 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               37 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               38 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               39 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               40 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x28, mask = 0xf
         const oal_mutex_t [36, 40]
        AGGS VARIABLE
  Node: pfe_hif_ptp_ts_db_pop/12:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [5]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [6]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_ptp_ts_db_push_ts/11:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_ptp_ts_db_push_msg/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [5]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_ptp_ts_db_fini/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_ptp_ts_db_init/8:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_ptp_ts_db_tick_iteration/7:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: check_entry_type_vals/6:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

Propagated bits info for function oal_mutex_unlock.part.0/230:
 param 0: value = 0x28, mask = 0xf
Propagated bits info for function oal_mutex_lock.part.0/229:
 param 0: value = 0x28, mask = 0xf

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

oal_mutex_unlock.part.0/230 (oal_mutex_unlock.part.0) @070bc540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_hif_ptp_ts_db_pop/12 (98121212 (estimated locally),1.00 per call) pfe_hif_ptp_ts_db_push_ts/11 (72338040 (estimated locally),1.00 per call) pfe_hif_ptp_ts_db_push_msg/10 (512926469 (estimated locally),0.48 per call) pfe_hif_ptp_ts_db_fini/9 (1073741824 (estimated locally),1.00 per call) pfe_hif_ptp_ts_db_tick_iteration/7 (118111601 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
oal_mutex_lock.part.0/229 (oal_mutex_lock.part.0) @06e74d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_hif_ptp_ts_db_pop/12 (98121214 (estimated locally),1.00 per call) pfe_hif_ptp_ts_db_push_ts/11 (72338042 (estimated locally),1.00 per call) pfe_hif_ptp_ts_db_push_msg/10 (512926469 (estimated locally),0.48 per call) pfe_hif_ptp_ts_db_fini/9 (1073741824 (estimated locally),1.00 per call) pfe_hif_ptp_ts_db_tick_iteration/7 (118111600 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
isa_release/228 (isa_release) @07281b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_ptp_ts_db_pop/12 (12512651 (estimated locally),0.13 per call) 
  Calls: 
isa_reserve/227 (isa_reserve) @072818c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_ptp_ts_db_push_msg/10 (512926469 (estimated locally),0.48 per call) 
  Calls: 
isa_init/226 (isa_init) @07281620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_ptp_ts_db_init/8 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memset/225 (autolibc_memset) @07281540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_ptp_ts_db_fini/9 (1073741824 (estimated locally),1.00 per call) pfe_hif_ptp_ts_db_fini/9 (1073741824 (estimated locally),1.00 per call) pfe_hif_ptp_ts_db_init/8 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/224 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @07281380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/223 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @072812a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/222 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @072811c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/221 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @072810e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/220 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @07281000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/219 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @07054ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/218 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @07054e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/217 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @07054d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/216 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @07054c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/215 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @07054b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/214 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @07054a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/213 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @070549a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/212 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @070548c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/211 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @070547e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/210 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @07054700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/209 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @07054620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/208 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @07054540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/207 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @07054460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/206 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @07054380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/205 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @070542a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/204 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @070541c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/203 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @070540e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/202 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @07054000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/201 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @07053ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/200 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @07053e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/199 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @07053d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/198 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @07053c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/197 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @07053b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/196 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @07053a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/195 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @070539a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/194 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @070538c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/193 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @070537e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/192 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @07053700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/191 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @07053620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/190 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @07053540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/189 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @07053460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/188 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @07053380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/187 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @070532a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/186 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @070531c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/185 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @070530e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/184 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @07053000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/183 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @07052ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/182 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @07052e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/181 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @07052d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/180 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @07052c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/179 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @07052b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/178 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @07052a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/177 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @070529a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/176 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @070528c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/175 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @070527e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/174 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @07052700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/173 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @07052620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/172 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @07052540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/171 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @07052460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/170 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @07052380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/169 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @070522a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/168 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @070521c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/167 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @070520e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/166 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @07052000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/165 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @07051ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/164 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @07051e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/163 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @07051d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/162 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @07051c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/161 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @07051b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/160 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @07051a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/159 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @070519a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/158 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @070518c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/157 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @070517e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/156 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @07051700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/155 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @07051620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/154 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @07051540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/153 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @07051460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/152 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @07051380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/151 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @070512a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/150 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @070511c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/149 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @070510e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/148 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @07051000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/147 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @0704ec40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/146 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @07050ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/145 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @07050e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/144 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @07050d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/143 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @07050c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/142 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @07050b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/141 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @07050a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/140 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @070509a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/139 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @070508c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/138 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @070507e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/137 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @07050700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/136 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @07050620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/135 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @07050540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/134 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @07050460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/133 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @07050380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/132 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @070502a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/131 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @070501c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/130 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @070500e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/129 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @07050000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/128 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @0704eee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/127 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @0704ee00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/126 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @0704ed20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/125 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @0704eb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/124 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @0704ea80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/123 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @0704e9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/122 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @0704e8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/121 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @0704e7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/120 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @0704e700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/119 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @0704e540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/118 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @0704e460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/117 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @0704e380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/116 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @0704e2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/115 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @0704e1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/114 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @0704e0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/113 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @0704e000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/112 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @0704cee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/111 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @0704ce00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/110 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @0704cd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/109 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @0704cc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/108 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @0704cb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/107 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @0704ca80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/106 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @0704c9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/105 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @0704c8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/104 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @0704c7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/103 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @0704c700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/102 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @0704c620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/101 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @0704c540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/100 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @0704c460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/99 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @0704c380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/98 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @0704c2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/97 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @0704c1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/96 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @0704c0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/95 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @0704c000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/94 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @0704bee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/93 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @0704be00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/92 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @0704bd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/91 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @0704bc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/90 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @0704bb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/89 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @0704ba80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/88 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @0704b9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/87 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @0704b8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/86 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @0704b7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/85 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @0704b700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/84 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @0704b620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/83 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @0704b540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/82 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @0704b460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/81 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @0704b380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/80 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @0704b2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/79 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @0704b1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/78 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @0704b0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/77 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @0704b000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/76 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @0704aee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/75 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @0704ae00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/74 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @0704ad20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/73 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @0704ac40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/72 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @0704ab60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/71 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @0704aa80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/70 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @0704a9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/69 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @0704a8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/68 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @0704a7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/67 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @0704a700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/66 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @0704a620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/65 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @0704a540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/64 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @0704a460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/63 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @0704a380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/62 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @0704a2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/61 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @0704a1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/60 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @0704a0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/59 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @0704a000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/58 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @07049ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/57 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @07049e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/56 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @07049d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/55 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @07049c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/54 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @07049b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/53 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @07049a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/52 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @070499a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/51 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @070498c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/50 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @070497e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/49 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @07049700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/48 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @07049620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/47 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @07049540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/46 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @07049460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/45 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @07049380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/44 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @070492a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/43 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @070491c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/42 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @070490e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/41 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @07049000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/40 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @07042ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/39 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @07048ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/38 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @07048e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/37 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @07048d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/36 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @07048c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/35 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @07048b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/34 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @07048a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/33 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @070489a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/32 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @070488c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/31 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @070487e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/30 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @07048700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/29 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @07048620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/28 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @07048540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/27 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @07048460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/26 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @07048380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/25 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @070482a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/24 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @070481c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/23 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @070480e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/22 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @07048000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/21 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @070420e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/20 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @07042e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/19 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @07042d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/18 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @07042c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/17 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @07042b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/16 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @07042a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/15 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @070429a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
isa_release_subscript/14 (isa_release_subscript) @070427e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_ptp_ts_db_tick_iteration/7 (220750581 (estimated locally),1.87 per call) 
  Calls: 
isa_item/13 (isa_item) @07042700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_ptp_ts_db_pop/12 (1014686024 (estimated locally),10.34 per call) pfe_hif_ptp_ts_db_push_ts/11 (1014686025 (estimated locally),14.03 per call) pfe_hif_ptp_ts_db_tick_iteration/7 (955630223 (estimated locally),8.09 per call) 
  Calls: 
pfe_hif_ptp_ts_db_pop/12 (pfe_hif_ptp_ts_db_pop) @070422a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:98121214 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/230 (98121212 (estimated locally),1.00 per call) isa_release/228 (12512651 (estimated locally),0.13 per call) check_entry_type_vals/6 (710280217 (estimated locally),7.24 per call) isa_item/13 (1014686024 (estimated locally),10.34 per call) oal_mutex_lock.part.0/229 (98121214 (estimated locally),1.00 per call) 
pfe_hif_ptp_ts_db_push_ts/11 (pfe_hif_ptp_ts_db_push_ts) @07042000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:72338042 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/230 (72338040 (estimated locally),1.00 per call) isa_item/13 (1014686025 (estimated locally),14.03 per call) oal_mutex_lock.part.0/229 (72338042 (estimated locally),1.00 per call) 
pfe_hif_ptp_ts_db_push_msg/10 (pfe_hif_ptp_ts_db_push_msg) @07032b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/230 (512926469 (estimated locally),0.48 per call) isa_reserve/227 (512926469 (estimated locally),0.48 per call) oal_mutex_lock.part.0/229 (512926469 (estimated locally),0.48 per call) 
pfe_hif_ptp_ts_db_fini/9 (pfe_hif_ptp_ts_db_fini) @07032620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/230 (1073741824 (estimated locally),1.00 per call) autolibc_memset/225 (1073741824 (estimated locally),1.00 per call) autolibc_memset/225 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/229 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_ptp_ts_db_init/8 (pfe_hif_ptp_ts_db_init) @07032d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: isa_init/226 (1073741824 (estimated locally),1.00 per call) autolibc_memset/225 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_ptp_ts_db_tick_iteration/7 (pfe_hif_ptp_ts_db_tick_iteration) @07032a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/230 (118111601 (estimated locally),1.00 per call) isa_release_subscript/14 (220750581 (estimated locally),1.87 per call) isa_item/13 (955630223 (estimated locally),8.09 per call) oal_mutex_lock.part.0/229 (118111600 (estimated locally),1.00 per call) 
check_entry_type_vals/6 (check_entry_type_vals) @070327e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_hif_ptp_ts_db_pop/12 (710280217 (estimated locally),7.24 per call) 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @07010ca8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/120 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/121 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/122 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/123 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/124 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/125 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/126 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/127 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/128 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/129 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/130 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/131 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/132 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/133 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/134 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/135 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/136 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/137 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/138 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/139 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/140 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/141 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/142 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/143 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/144 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/145 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/146 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/147 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/148 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/149 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/150 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/151 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/152 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/153 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/154 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/155 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/156 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/157 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/158 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/159 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/160 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/161 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/162 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/163 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/164 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/165 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/166 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/167 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/168 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/169 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/170 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/171 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/172 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/173 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/174 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/175 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/176 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/177 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/178 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/179 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/180 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/181 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/182 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/183 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/184 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/185 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/186 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/187 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/188 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/189 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/190 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/191 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/192 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/193 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/194 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/195 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/196 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/197 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/198 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/199 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/200 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/201 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/202 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/203 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/204 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/205 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/206 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/207 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/208 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/209 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/210 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/211 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/212 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/213 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/214 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/215 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/216 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/217 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/218 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/219 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/220 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/221 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/222 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/223 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/224 (addr)
  Referring: oal_mutex_unlock.part.0/230 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @07010bd0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/15 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/16 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/17 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/18 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/19 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/20 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/21 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/22 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/23 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/24 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/25 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/26 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/27 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/28 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/29 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/30 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/31 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/32 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/33 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/34 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/35 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/36 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/37 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/38 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/39 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/40 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/41 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/42 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/43 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/44 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/45 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/46 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/47 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/48 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/49 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/50 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/51 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/52 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/53 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/54 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/55 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/56 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/57 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/58 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/59 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/60 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/61 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/62 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/63 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/64 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/65 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/66 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/67 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/68 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/69 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/70 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/71 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/72 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/73 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/74 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/75 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/76 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/77 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/78 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/79 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/80 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/81 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/82 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/83 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/84 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/85 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/86 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/87 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/88 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/89 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/90 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/91 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/92 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/93 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/94 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/95 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/96 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/97 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/98 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/99 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/100 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/101 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/102 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/103 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/104 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/105 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/106 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/107 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/108 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/109 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/110 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/111 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/112 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/113 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/114 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/115 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/116 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/117 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/118 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/119 (addr)
  Referring: oal_mutex_lock.part.0/229 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function oal_mutex_lock.part.0 (oal_mutex_lock.part.0, funcdef_no=11, decl_uid=7463, cgraph_uid=228, symbol_order=229)

Modification phase of node oal_mutex_lock.part.0/229
Adjusting mask for param 0 to 0xf
Setting value range of param 0 [36, 40]
oal_mutex_lock.part.0 (const oal_mutex_t mutex)
{
  void (*<T4e6>) (void) _2;

  <bb 4> [local count: 1073741824]:

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID[mutex_1(D)];
  _2 ();

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function oal_mutex_unlock.part.0 (oal_mutex_unlock.part.0, funcdef_no=12, decl_uid=7468, cgraph_uid=229, symbol_order=230)

Modification phase of node oal_mutex_unlock.part.0/230
Adjusting mask for param 0 to 0xf
Setting value range of param 0 [36, 40]
oal_mutex_unlock.part.0 (const oal_mutex_t mutex)
{
  void (*<T4e6>) (void) _2;

  <bb 4> [local count: 1073741824]:

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID[mutex_1(D)];
  _2 ();

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_ptp_ts_db_tick_iteration (pfe_hif_ptp_ts_db_tick_iteration, funcdef_no=5, decl_uid=7321, cgraph_uid=6, symbol_order=7)

Modification phase of node pfe_hif_ptp_ts_db_tick_iteration/7
pfe_hif_ptp_ts_db_tick_iteration (void * arg)
{
  uint32_t index;
  struct pfe_hif_ptp_ts_db_entry_t * entry;
  struct pfe_isa_t * _1;
  long unsigned int _2;
  long unsigned int _3;
  unsigned char _4;
  unsigned char _5;
  long unsigned int _7;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG db => arg_11(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 36
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (36);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  index_13 = MEM[(struct pfe_hif_ptp_ts_db_t *)arg_11(D)].entries.occupied_items_count;
  # DEBUG index => index_13
  goto <bb 10>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _1 = &MEM[(struct pfe_hif_ptp_ts_db_t *)arg_11(D)].entries;
  _2 = index_8 + 4294967295;
  entry_15 = isa_item (_1, _2);
  # DEBUG entry => entry_15
  # DEBUG BEGIN_STMT
  if (entry_15 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 4> [local count: 668941156]:
  # DEBUG BEGIN_STMT
  _3 = entry_15->ticks;
  if (_3 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 220750581]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  isa_release_subscript (_1, _2);
  # DEBUG BEGIN_STMT
  _4 = MEM[(struct pfe_hif_ptp_ts_db_t *)arg_11(D)].count;
  # DEBUG BEGIN_STMT
  _5 = _4 + 255;
  MEM[(struct pfe_hif_ptp_ts_db_t *)arg_11(D)].count = _5;
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 448190574]:
  # DEBUG BEGIN_STMT
  _7 = _3 + 4294967295;
  entry_15->ticks = _7;

  <bb 8> [local count: 955630223]:
  # index_9 = PHI <_2(6), _2(5), _2(3)>

  <bb 10> [local count: 1073741824]:
  # index_8 = PHI <index_9(8), index_13(2)>
  # DEBUG index => index_8
  # DEBUG BEGIN_STMT
  if (index_8 != 0)
    goto <bb 3>; [89.00%]
  else
    goto <bb 9>; [11.00%]

  <bb 9> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 36
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (36);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_hif_ptp_ts_db_init (pfe_hif_ptp_ts_db_init, funcdef_no=6, decl_uid=7296, cgraph_uid=7, symbol_order=8)

Modification phase of node pfe_hif_ptp_ts_db_init/8
pfe_hif_ptp_ts_db_init (struct pfe_hif_ptp_ts_db_t * db)
{
  pfe_isa_index_t[60] * _1;
  struct pfe_hif_ptp_ts_db_entry_t[60] * _2;
  struct pfe_isa_t * _3;
  struct pfe_isa_definition_t * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  autolibc_memset (db_6(D), 0, 1596);
  # DEBUG BEGIN_STMT
  db_6(D)->entries_isa_def.item_count = 60;
  # DEBUG BEGIN_STMT
  db_6(D)->entries_isa_def.item_size = 24;
  # DEBUG BEGIN_STMT
  db_6(D)->entries_isa_def.flags.ordered = 1;
  # DEBUG BEGIN_STMT
  _1 = &db_6(D)->entries_pool_index;
  db_6(D)->entries_isa_def.item_indexes = _1;
  # DEBUG BEGIN_STMT
  _2 = &db_6(D)->entries_pool;
  db_6(D)->entries_isa_def.items = _2;
  # DEBUG BEGIN_STMT
  db_6(D)->entries_isa_def.clear_cb = 0B;
  # DEBUG BEGIN_STMT
  _3 = &db_6(D)->entries;
  _4 = &db_6(D)->entries_isa_def;
  isa_init (_3, _4);
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_hif_ptp_ts_db_fini (pfe_hif_ptp_ts_db_fini, funcdef_no=7, decl_uid=7298, cgraph_uid=8, symbol_order=9)

Modification phase of node pfe_hif_ptp_ts_db_fini/9
pfe_hif_ptp_ts_db_fini (struct pfe_hif_ptp_ts_db_t * db)
{
  struct pfe_isa_t * _1;
  struct pfe_isa_definition_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 37
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (37);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = &db_4(D)->entries;
  autolibc_memset (_1, 0, 8);
  # DEBUG BEGIN_STMT
  _2 = &db_4(D)->entries_isa_def;
  autolibc_memset (_2, 0, 24);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 37
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (37);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_hif_ptp_ts_db_push_msg (pfe_hif_ptp_ts_db_push_msg, funcdef_no=8, decl_uid=7305, cgraph_uid=9, symbol_order=10)

Modification phase of node pfe_hif_ptp_ts_db_push_msg/10
pfe_hif_ptp_ts_db_push_msg (struct pfe_hif_ptp_ts_db_t * db, bool_t rx, uint16_t refnum, uint8_t type, uint16_t port, uint16_t seq_id)
{
  struct pfe_hif_ptp_ts_db_entry_t * entry;
  errno_t ret;
  unsigned char _1;
  struct pfe_isa_t * _2;
  unsigned char _3;
  unsigned char _4;
  unsigned char _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = db_11(D)->count;
  if (_1 > 59)
    goto <bb 9>; [52.23%]
  else
    goto <bb 3>; [47.77%]

  <bb 3> [local count: 512926469]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 38
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (38);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _2 = &db_11(D)->entries;
  entry_13 = isa_reserve (_2);
  # DEBUG entry => entry_13
  # DEBUG BEGIN_STMT
  if (entry_13 == 0B)
    goto <bb 8>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 4> [local count: 359048528]:
  # DEBUG BEGIN_STMT
  entry_13->refnum = refnum_14(D);
  # DEBUG BEGIN_STMT
  entry_13->type = type_16(D);
  # DEBUG BEGIN_STMT
  entry_13->port = port_18(D);
  # DEBUG BEGIN_STMT
  entry_13->seq_id = seq_id_20(D);
  # DEBUG BEGIN_STMT
  entry_13->ts_valid = 0;
  # DEBUG BEGIN_STMT
  entry_13->ticks = 1;
  # DEBUG BEGIN_STMT
  entry_13->rx = rx_24(D);
  # DEBUG BEGIN_STMT
  _3 = db_11(D)->count;
  _4 = _3 + 1;
  db_11(D)->count = _4;
  # DEBUG BEGIN_STMT
  if (_4 > 50)
    goto <bb 5>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 5> [local count: 179524264]:
  _5 = db_11(D)->reported;
  if (_5 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 6> [local count: 89762132]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  db_11(D)->reported = 1;

  <bb 8> [local count: 512926469]:
  # ret_6 = PHI <11(3), 0(5), 0(4), 0(6)>
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 38
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (38);

  <bb 9> [local count: 1073741824]:
  # ret_7 = PHI <113(2), ret_6(8)>
  # DEBUG mutex => NULL
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  return ret_7;

}



;; Function pfe_hif_ptp_ts_db_push_ts (pfe_hif_ptp_ts_db_push_ts, funcdef_no=9, decl_uid=7311, cgraph_uid=10, symbol_order=11)

Modification phase of node pfe_hif_ptp_ts_db_push_ts/11
pfe_hif_ptp_ts_db_push_ts (struct pfe_hif_ptp_ts_db_t * db, bool_t rx, uint16_t refnum, uint32_t ts_sec, uint32_t ts_nsec)
{
  uint32_t index;
  bool_t found;
  struct pfe_hif_ptp_ts_db_entry_t * entry;
  struct pfe_isa_t * _1;
  short unsigned int _2;
  unsigned char _3;
  long unsigned int _4;
  errno_t iftmp.0_7;

  <bb 2> [local count: 72338042]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG found => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 39
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (39);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  # DEBUG index => 0
  goto <bb 8>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _1 = &db_11(D)->entries;
  entry_13 = isa_item (_1, index_6);
  # DEBUG entry => entry_13
  # DEBUG BEGIN_STMT
  if (entry_13 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 4> [local count: 710280217]:
  # DEBUG BEGIN_STMT
  _2 = entry_13->refnum;
  if (_2 == refnum_14(D))
    goto <bb 5>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 5> [local count: 241495274]:
  _3 = entry_13->rx;
  if (_3 == rx_15(D))
    goto <bb 6>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 6> [local count: 13282240]:
  # entry_22 = PHI <entry_13(5)>
  # DEBUG BEGIN_STMT
  # DEBUG found => 1
  # DEBUG BEGIN_STMT
  entry_22->ts_sec = ts_sec_16(D);
  # DEBUG BEGIN_STMT
  entry_22->ts_nsec = ts_nsec_18(D);
  # DEBUG BEGIN_STMT
  entry_22->ts_valid = 1;
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 1001403785]:
  # DEBUG BEGIN_STMT
  index_21 = index_6 + 1;
  # DEBUG index => index_21

  <bb 8> [local count: 1073741824]:
  # index_6 = PHI <0(2), index_21(7)>
  # DEBUG index => index_6
  # DEBUG BEGIN_STMT
  _4 = db_11(D)->entries.occupied_items_count;
  if (_4 > index_6)
    goto <bb 3>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 9> [local count: 72338040]:
  # found_5 = PHI <1(6), 0(8)>
  # DEBUG found => found_5
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 39
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (39);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  if (found_5 != 0)
    goto <bb 11>; [65.00%]
  else
    goto <bb 10>; [35.00%]

  <bb 10> [local count: 25318314]:

  <bb 11> [local count: 72338040]:
  # iftmp.0_7 = PHI <0(9), 2(10)>
  return iftmp.0_7;

}



;; Function pfe_hif_ptp_ts_db_pop (pfe_hif_ptp_ts_db_pop, funcdef_no=10, decl_uid=7319, cgraph_uid=11, symbol_order=12)

Modification phase of node pfe_hif_ptp_ts_db_pop/12
pfe_hif_ptp_ts_db_pop (struct pfe_hif_ptp_ts_db_t * db, uint8_t type, uint16_t port, uint16_t seq_id, uint32_t * ts_sec, uint32_t * ts_nsec, bool_t rx)
{
  uint32_t index;
  struct pfe_hif_ptp_ts_db_entry_t * entry;
  errno_t ret_val;
  struct pfe_isa_t * _1;
  unsigned char _2;
  unsigned char _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  struct pfe_isa_t * _7;
  unsigned char _8;
  unsigned char _9;
  unsigned char _10;

  <bb 2> [local count: 98121214]:
  # DEBUG BEGIN_STMT
  # DEBUG ret_val => 2
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 40
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (40);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  # DEBUG index => 0
  goto <bb 8>; [100.00%]

  <bb 3> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  _1 = &db_16(D)->entries;
  entry_18 = isa_item (_1, index_11);
  # DEBUG entry => entry_18
  # DEBUG BEGIN_STMT
  if (entry_18 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 4> [local count: 710280217]:
  # DEBUG BEGIN_STMT
  _2 = check_entry_type_vals (entry_18, type_19(D), port_20(D), seq_id_21(D), rx_22(D));
  if (_2 == 1)
    goto <bb 5>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 5> [local count: 39065412]:
  # entry_34 = PHI <entry_18(4)>
  # DEBUG BEGIN_STMT
  _3 = entry_34->ts_valid;
  if (_3 == 1)
    goto <bb 6>; [32.03%]
  else
    goto <bb 11>; [67.97%]

  <bb 6> [local count: 12512651]:
  # DEBUG BEGIN_STMT
  # DEBUG ret_val => 0
  # DEBUG BEGIN_STMT
  _4 = entry_34->ts_sec;
  *ts_sec_24(D) = _4;
  # DEBUG BEGIN_STMT
  _5 = entry_34->ts_nsec;
  *ts_nsec_26(D) = _5;
  # DEBUG entry => entry_34
  # DEBUG ret_val => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = &db_16(D)->entries;
  isa_release (_7, entry_34);
  # DEBUG BEGIN_STMT
  _8 = db_16(D)->count;
  _9 = _8 + 255;
  db_16(D)->count = _9;
  # DEBUG BEGIN_STMT
  if (_9 <= 12)
    goto <bb 9>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 7> [local count: 975620612]:
  # DEBUG BEGIN_STMT
  index_28 = index_11 + 1;
  # DEBUG index => index_28

  <bb 8> [local count: 1073741824]:
  # index_11 = PHI <0(2), index_28(7)>
  # DEBUG index => index_11
  # DEBUG entry => NULL
  # DEBUG BEGIN_STMT
  _6 = db_16(D)->entries.occupied_items_count;
  if (_6 > index_11)
    goto <bb 3>; [94.50%]
  else
    goto <bb 11>; [5.50%]

  <bb 9> [local count: 6256326]:
  _10 = db_16(D)->reported;
  if (_10 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 3128163]:
  # DEBUG BEGIN_STMT
  db_16(D)->reported = 0;

  <bb 11> [local count: 98121212]:
  # ret_val_33 = PHI <2(8), 0(6), 0(9), 0(10), 118(5)>
  # DEBUG entry => NULL
  # DEBUG ret_val => NULL
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 40
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (40);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  return ret_val_33;

}


