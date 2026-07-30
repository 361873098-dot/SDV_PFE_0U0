
IPA constant propagation start:
Determining dynamic type for call: err_10 = fci_init_param_validate.isra.0 (&context);
  Starting walk at: err_10 = fci_init_param_validate.isra.0 (&context);
  instance pointer: &context  Outer instance pointer: context offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: fci_init_context_info (&context, info_13(D));
  Starting walk at: fci_init_context_info (&context, info_13(D));
  instance pointer: &context  Outer instance pointer: context offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_15 = fci_owner_init (info_13(D));
  Function call may change dynamic type:err_12 = fci_core_init (identifier_8(D));
  Function call may change dynamic type:err_10 = fci_init_param_validate.isra.0 (&context);
Determining dynamic type for call: fci_init_context_info (&context, info_13(D));
  Starting walk at: fci_init_context_info (&context, info_13(D));
  instance pointer: info_13(D)  Outer instance pointer: info_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_15 = fci_owner_init (info_13(D));
  Function call may change dynamic type:err_12 = fci_core_init (identifier_8(D));
  Function call may change dynamic type:err_10 = fci_init_param_validate.isra.0 (&context);
Determining dynamic type for call: ret_32 = fci_check_credentials (&passed_vars, &fci_ret, &reply_buf_len_ptr, &reply_retval_ptr);
  Starting walk at: ret_32 = fci_check_credentials (&passed_vars, &fci_ret, &reply_buf_len_ptr, &reply_retval_ptr);
  instance pointer: &passed_vars  Outer instance pointer: passed_vars offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_32 = fci_check_credentials (&passed_vars, &fci_ret, &reply_buf_len_ptr, &reply_retval_ptr);
  Starting walk at: ret_32 = fci_check_credentials (&passed_vars, &fci_ret, &reply_buf_len_ptr, &reply_retval_ptr);
  instance pointer: &fci_ret  Outer instance pointer: fci_ret offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_32 = fci_check_credentials (&passed_vars, &fci_ret, &reply_buf_len_ptr, &reply_retval_ptr);
  Starting walk at: ret_32 = fci_check_credentials (&passed_vars, &fci_ret, &reply_buf_len_ptr, &reply_retval_ptr);
  instance pointer: &reply_buf_len_ptr  Outer instance pointer: reply_buf_len_ptr offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_32 = fci_check_credentials (&passed_vars, &fci_ret, &reply_buf_len_ptr, &reply_retval_ptr);
  Starting walk at: ret_32 = fci_check_credentials (&passed_vars, &fci_ret, &reply_buf_len_ptr, &reply_retval_ptr);
  instance pointer: &reply_retval_ptr  Outer instance pointer: reply_retval_ptr offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_34 = execute_fci_cmd (msg_22(D), &fci_ret, &reply_buf_ptr, &reply_buf_len_ptr);
  Starting walk at: ret_34 = execute_fci_cmd (msg_22(D), &fci_ret, &reply_buf_ptr, &reply_buf_len_ptr);
  instance pointer: msg_22(D)  Outer instance pointer: msg_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_32 = fci_check_credentials (&passed_vars, &fci_ret, &reply_buf_len_ptr, &reply_retval_ptr);
Determining dynamic type for call: ret_34 = execute_fci_cmd (msg_22(D), &fci_ret, &reply_buf_ptr, &reply_buf_len_ptr);
  Starting walk at: ret_34 = execute_fci_cmd (msg_22(D), &fci_ret, &reply_buf_ptr, &reply_buf_len_ptr);
  instance pointer: &fci_ret  Outer instance pointer: fci_ret offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_32 = fci_check_credentials (&passed_vars, &fci_ret, &reply_buf_len_ptr, &reply_retval_ptr);
Determining dynamic type for call: ret_34 = execute_fci_cmd (msg_22(D), &fci_ret, &reply_buf_ptr, &reply_buf_len_ptr);
  Starting walk at: ret_34 = execute_fci_cmd (msg_22(D), &fci_ret, &reply_buf_ptr, &reply_buf_len_ptr);
  instance pointer: &reply_buf_ptr  Outer instance pointer: reply_buf_ptr offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_32 = fci_check_credentials (&passed_vars, &fci_ret, &reply_buf_len_ptr, &reply_retval_ptr);
Determining dynamic type for call: ret_34 = execute_fci_cmd (msg_22(D), &fci_ret, &reply_buf_ptr, &reply_buf_len_ptr);
  Starting walk at: ret_34 = execute_fci_cmd (msg_22(D), &fci_ret, &reply_buf_ptr, &reply_buf_len_ptr);
  instance pointer: &reply_buf_len_ptr  Outer instance pointer: reply_buf_len_ptr offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_32 = fci_check_credentials (&passed_vars, &fci_ret, &reply_buf_len_ptr, &reply_retval_ptr);
Determining dynamic type for call: ret_35 = fci_authorize_and_lock (reply_buf_len_ptr_32(D), _7, fci_ret_33(D), &fci_cmd_execute, sender_phy_if_id.5_8);
  Starting walk at: ret_35 = fci_authorize_and_lock (reply_buf_len_ptr_32(D), _7, fci_ret_33(D), &fci_cmd_execute, sender_phy_if_id.5_8);
  instance pointer: reply_buf_len_ptr_32(D)  Outer instance pointer: reply_buf_len_ptr_32(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_31 = fci_sender_get_phy_if_id (_2, &sender_phy_if_id);
  Function call may change dynamic type:ret_28 = fci_owner_mutex_lock ();
Determining dynamic type for call: ret_35 = fci_authorize_and_lock (reply_buf_len_ptr_32(D), _7, fci_ret_33(D), &fci_cmd_execute, sender_phy_if_id.5_8);
  Starting walk at: ret_35 = fci_authorize_and_lock (reply_buf_len_ptr_32(D), _7, fci_ret_33(D), &fci_cmd_execute, sender_phy_if_id.5_8);
  instance pointer: _7  Outer instance pointer: vars_29(D) offset: 64 (bits) vtbl reference: 
  Function call may change dynamic type:ret_31 = fci_sender_get_phy_if_id (_2, &sender_phy_if_id);
  Function call may change dynamic type:ret_28 = fci_owner_mutex_lock ();
Determining dynamic type for call: ret_35 = fci_authorize_and_lock (reply_buf_len_ptr_32(D), _7, fci_ret_33(D), &fci_cmd_execute, sender_phy_if_id.5_8);
  Starting walk at: ret_35 = fci_authorize_and_lock (reply_buf_len_ptr_32(D), _7, fci_ret_33(D), &fci_cmd_execute, sender_phy_if_id.5_8);
  instance pointer: fci_ret_33(D)  Outer instance pointer: fci_ret_33(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_31 = fci_sender_get_phy_if_id (_2, &sender_phy_if_id);
  Function call may change dynamic type:ret_28 = fci_owner_mutex_lock ();
Determining dynamic type for call: ret_35 = fci_authorize_and_lock (reply_buf_len_ptr_32(D), _7, fci_ret_33(D), &fci_cmd_execute, sender_phy_if_id.5_8);
  Starting walk at: ret_35 = fci_authorize_and_lock (reply_buf_len_ptr_32(D), _7, fci_ret_33(D), &fci_cmd_execute, sender_phy_if_id.5_8);
  instance pointer: &fci_cmd_execute  Outer instance pointer: fci_cmd_execute offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_31 = fci_sender_get_phy_if_id (_2, &sender_phy_if_id);
  Function call may change dynamic type:ret_28 = fci_owner_mutex_lock ();

IPA structures before propagation:

Jump functions:
  Jump functions of caller  fci_init_param_validate.isra.0/309:
  Jump functions of caller  oal_mutex_unlock.part.0/296:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  oal_mutex_lock.part.0/295:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  pfe_if_db_unlock/294:
  Jump functions of caller  pfe_if_db_lock/293:
  Jump functions of caller  fci_core_fini/292:
  Jump functions of caller  fci_hm_cb_deregister/291:
  Jump functions of caller  fci_routes_drop_all/290:
  Jump functions of caller  fci_rt_db_init/289:
  Jump functions of caller  fci_fp_db_init/288:
  Jump functions of caller  autolibc_memset/287:
  Jump functions of caller  fci_hm_cb_register/286:
  Jump functions of caller  fci_owner_init/285:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/284:
  Jump functions of caller  pfe_hm_report/283:
  Jump functions of caller  fci_core_init/282:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/281:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/280:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/279:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/278:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/277:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/276:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/275:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/274:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/273:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/272:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/271:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/270:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/269:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/268:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/267:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/266:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/265:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/264:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/263:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/262:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/261:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/260:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/259:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/258:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/257:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/256:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/255:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/254:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/253:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/252:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/251:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/250:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/249:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/248:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/247:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/246:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/245:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/244:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/243:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/242:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/241:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/240:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/239:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/238:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/237:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/236:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/235:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/234:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/233:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/232:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/231:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/230:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/229:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/228:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/227:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/226:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/225:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/224:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/223:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/222:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/221:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/220:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/219:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/218:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/217:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/216:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/215:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/214:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/213:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/212:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/211:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/210:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/209:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/208:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/207:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/206:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/205:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/204:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/203:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/202:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/201:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/200:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/199:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/198:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/197:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/196:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/195:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/194:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/193:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/192:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/191:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/190:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/189:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/188:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/187:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/186:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/185:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/184:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/183:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/182:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/181:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/180:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/179:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/178:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/177:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/176:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/175:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/174:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/173:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/172:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/171:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/170:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/169:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/168:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/167:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/166:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/165:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/164:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/163:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/162:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/161:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/160:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/159:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/158:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/157:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/156:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/155:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/154:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/153:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/152:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/151:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/150:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/149:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/148:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/147:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/146:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/145:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/144:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/143:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/142:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/141:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/140:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/139:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/138:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/137:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/136:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/135:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/134:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/133:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/132:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/131:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/130:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/129:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/128:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/127:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/126:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/125:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/124:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/123:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/122:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/121:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/120:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/119:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/118:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/117:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/116:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/115:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/114:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/113:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/112:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/111:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/110:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/109:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/108:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/107:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/106:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/105:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/104:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/103:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/102:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/101:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/100:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/99:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/98:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/97:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/96:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/95:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/94:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/93:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/92:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/91:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/90:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/89:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/88:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/87:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/86:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/85:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/84:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/83:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/82:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/81:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/80:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/79:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/78:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/77:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/76:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/75:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/74:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/73:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/72:
  Jump functions of caller  fci_timer_owner_unlock_cmd/71:
  Jump functions of caller  fci_timer_owner_lock_cmd/70:
  Jump functions of caller  fci_l2br_flush_cmd/69:
  Jump functions of caller  fci_qos_policer_shp_cmd/68:
  Jump functions of caller  fci_qos_policer_wred_cmd/67:
  Jump functions of caller  fci_qos_policer_flow_cmd/66:
  Jump functions of caller  fci_qos_policer_cmd/65:
  Jump functions of caller  fci_mirror_cmd/64:
  Jump functions of caller  fci_qos_shaper_cmd/63:
  Jump functions of caller  fci_qos_scheduler_cmd/62:
  Jump functions of caller  fci_qos_queue_cmd/61:
  Jump functions of caller  fci_fw_features_element_cmd/60:
  Jump functions of caller  fci_fw_features_cmd/59:
  Jump functions of caller  fci_fp_rule_cmd/58:
  Jump functions of caller  fci_fp_table_cmd/57:
  Jump functions of caller  fci_l2br_static_entry_cmd/56:
  Jump functions of caller  fci_l2br_domain_cmd/55:
  Jump functions of caller  fci_routes_drop_all_ipv6/54:
  Jump functions of caller  fci_routes_drop_all_ipv4/53:
  Jump functions of caller  fci_connections_ipv6_ct_cmd/52:
  Jump functions of caller  fci_connections_ipv4_ct_cmd/51:
  Jump functions of caller  fci_connections_ipv4_timeout_cmd/50:
  Jump functions of caller  fci_routes_cmd/49:
  Jump functions of caller  fci_interfaces_mac_cmd/48:
  Jump functions of caller  fci_interfaces_phy_cmd/47:
  Jump functions of caller  fci_interfaces_log_cmd/46:
  Jump functions of caller  fci_interfaces_session_cmd/45:
  Jump functions of caller  pfe_class_put_data/44:
  Jump functions of caller  autolibc_memcpy/43:
  Jump functions of caller  fci_owner_get_floating_lock/42:
  Jump functions of caller  fci_owner_authorize/41:
  Jump functions of caller  fci_owner_session_cmd/40:
  Jump functions of caller  fci_sender_get_phy_if_id/39:
  Jump functions of caller  fci_owner_mutex_lock/38:
  Jump functions of caller  fci_owner_mutex_unlock/37:
  Jump functions of caller  fci_owner_clear_floating_lock/36:
  Jump functions of caller  fci_fini/35:
    callsite  fci_fini/35 -> oal_mutex_unlock.part.0/296 : 
       param 0: CONST: 98
         value: 0x62, mask: 0x0
         Unknown VR
    callsite  fci_fini/35 -> oal_mutex_lock.part.0/295 : 
       param 0: CONST: 98
         value: 0x62, mask: 0x0
         Unknown VR
    callsite  fci_fini/35 -> oal_mutex_unlock.part.0/296 : 
       param 0: CONST: 98
         value: 0x62, mask: 0x0
         Unknown VR
    callsite  fci_fini/35 -> oal_mutex_lock.part.0/295 : 
       param 0: CONST: 98
         value: 0x62, mask: 0x0
         Unknown VR
  Jump functions of caller  fci_init/34:
    callsite  fci_init/34 -> fci_init_context_info/30 : 
       param 0: CONST: &context
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_init/34 -> fci_fini/35 : 
    callsite  fci_init/34 -> fci_fini/35 : 
    callsite  fci_init/34 -> fci_init_param_validate.isra.0/309 : 
       param 0: CONST: &context
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  fci_process_ipc_message/33:
    callsite  fci_process_ipc_message/33 -> execute_fci_cmd/29 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffe
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  fci_process_ipc_message/33 -> fci_check_credentials/32 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffe
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  fci_check_credentials/32:
    callsite  fci_check_credentials/32 -> fci_authorize_and_lock/31 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 4: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  fci_authorize_and_lock/31:
  Jump functions of caller  fci_init_context_info/30:
  Jump functions of caller  execute_fci_cmd/29:
    callsite  execute_fci_cmd/29 -> oal_mutex_unlock.part.0/296 : 
       param 0: CONST: 97
         value: 0x61, mask: 0x0
         Unknown VR
    callsite  execute_fci_cmd/29 -> oal_mutex_lock.part.0/295 : 
       param 0: CONST: 97
         value: 0x61, mask: 0x0
         Unknown VR
    callsite  execute_fci_cmd/29 -> oal_mutex_unlock.part.0/296 : 
       param 0: CONST: 97
         value: 0x61, mask: 0x0
         Unknown VR
    callsite  execute_fci_cmd/29 -> oal_mutex_lock.part.0/295 : 
       param 0: CONST: 97
         value: 0x61, mask: 0x0
         Unknown VR
    callsite  execute_fci_cmd/29 -> oal_mutex_unlock.part.0/296 : 
       param 0: CONST: 97
         value: 0x61, mask: 0x0
         Unknown VR
    callsite  execute_fci_cmd/29 -> oal_mutex_lock.part.0/295 : 
       param 0: CONST: 97
         value: 0x61, mask: 0x0
         Unknown VR
    callsite  execute_fci_cmd/29 -> oal_mutex_unlock.part.0/296 : 
       param 0: CONST: 97
         value: 0x61, mask: 0x0
         Unknown VR
    callsite  execute_fci_cmd/29 -> oal_mutex_lock.part.0/295 : 
       param 0: CONST: 97
         value: 0x61, mask: 0x0
         Unknown VR
    callsite  execute_fci_cmd/29 -> oal_mutex_unlock.part.0/296 : 
       param 0: CONST: 97
         value: 0x61, mask: 0x0
         Unknown VR
    callsite  execute_fci_cmd/29 -> oal_mutex_lock.part.0/295 : 
       param 0: CONST: 97
         value: 0x61, mask: 0x0
         Unknown VR
    callsite  execute_fci_cmd/29 -> oal_mutex_unlock.part.0/296 : 
       param 0: CONST: 97
         value: 0x61, mask: 0x0
         Unknown VR
    callsite  execute_fci_cmd/29 -> oal_mutex_lock.part.0/295 : 
       param 0: CONST: 97
         value: 0x61, mask: 0x0
         Unknown VR

 Propagating constants:

Not considering fci_fini for cloning; -fipa-cp-clone disabled.
Not considering fci_init for cloning; -fipa-cp-clone disabled.
Not considering fci_process_ipc_message for cloning; -fipa-cp-clone disabled.

overall_size: 631, max_new_size: 11001
 - context independent values, size: 26, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 35, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: fci_init_param_validate.isra.0/309:
    param [0]: &context [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct fci_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: oal_mutex_unlock.part.0/296:
    param [0]: 97 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               98 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x62, mask = 0x3
         const oal_mutex_t [97, 98]
        AGGS VARIABLE
  Node: oal_mutex_lock.part.0/295:
    param [0]: 97 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               98 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x62, mask = 0x3
         const oal_mutex_t [97, 98]
        AGGS VARIABLE
  Node: fci_fini/35:
  Node: fci_init/34:
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
  Node: fci_process_ipc_message/33:
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
  Node: fci_check_credentials/32:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct fci_vars_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffe
         uint16_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint32_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint16_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_authorize_and_lock/31:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint32_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         bool_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffe
         uint16_t * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         bool_t * ~[0B, 0B]
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: fci_init_context_info/30:
    param [0]: &context [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct fci_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: execute_fci_cmd/29:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffe
         uint16_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint32_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint32_t * * ~[0B, 0B]
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of fci_init_param_validate.isra.0/309 for all known contexts.
    replacing param #0 fci_context with const &context
 - Creating a specialized node of fci_init_context_info/30 for all known contexts.
    replacing param #0 fci_context with const &context
Propagated bits info for function fci_init_context_info.constprop/313:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_init_param_validate.isra.0.constprop/312:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_init_param_validate.isra.0/309:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function oal_mutex_unlock.part.0/296:
 param 0: value = 0x62, mask = 0x3
Propagated bits info for function oal_mutex_lock.part.0/295:
 param 0: value = 0x62, mask = 0x3
Propagated bits info for function fci_check_credentials/32:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffe
 param 2: value = 0x0, mask = 0xfffffffc
 param 3: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_authorize_and_lock/31:
 param 0: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffe
Propagated bits info for function fci_init_context_info/30:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function execute_fci_cmd/29:
 param 1: value = 0x0, mask = 0xfffffffe
 param 2: value = 0x0, mask = 0xfffffffc
 param 3: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions: fci_init_param_validate.isra.0/309 fci_init_context_info/30
Reclaiming variables:
Clearing address taken flags:
Symbol table:

fci_init_context_info.constprop.0/313 (fci_init_context_info.constprop) @073b20e0
  Type: function definition analyzed
  Visibility:
  References: context/27 (addr)
  Referring: 
  Clone of fci_init_context_info/30
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: fci_init/34 (131211251 (estimated locally),0.12 per call) 
  Calls: fci_fp_db_init/288 (1073741824 (estimated locally),1.00 per call) fci_rt_db_init/289 (751619278 (estimated locally),0.70 per call) 
fci_init_param_validate.isra.0.constprop.0/312 (fci_init_param_validate.isra.0.constprop) @079780e0
  Type: function definition analyzed
  Visibility: artificial
  References: context/27 (addr)
  Referring: 
  Clone of fci_init_param_validate.isra.0/309
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: fci_init/34 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_hm_report/283 (233216724 (estimated locally),0.22 per call) oal_util_raise_dem_for_drv_runtime_err/284 (233216724 (estimated locally),0.22 per call) autolibc_memset/287 (840525101 (estimated locally),0.78 per call) 
fci_init_param_validate.isra.0/309 (fci_init_param_validate.isra.0) @07393a80
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
oal_mutex_unlock.part.0/296 (oal_mutex_unlock.part.0) @070a8540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: fci_fini/35 (73890617 (estimated locally),0.07 per call) fci_fini/35 (73890617 (estimated locally),0.07 per call) execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
oal_mutex_lock.part.0/295 (oal_mutex_lock.part.0) @06e50d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: fci_fini/35 (73890617 (estimated locally),0.07 per call) fci_fini/35 (73890617 (estimated locally),0.07 per call) execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
pfe_if_db_unlock/294 (pfe_if_db_unlock) @07948380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_fini/35 (365072221 (estimated locally),0.34 per call) 
  Calls: 
pfe_if_db_lock/293 (pfe_if_db_lock) @079482a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_fini/35 (365072220 (estimated locally),0.34 per call) 
  Calls: 
fci_core_fini/292 (fci_core_fini) @079481c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_fini/35 (195204116 (estimated locally),0.18 per call) 
  Calls: 
fci_hm_cb_deregister/291 (fci_hm_cb_deregister) @079480e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_fini/35 (73890617 (estimated locally),0.07 per call) 
  Calls: 
fci_routes_drop_all/290 (fci_routes_drop_all) @07948000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_fini/35 (73890617 (estimated locally),0.07 per call) fci_fini/35 (73890617 (estimated locally),0.07 per call) 
  Calls: 
fci_rt_db_init/289 (fci_rt_db_init) @0793de00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_init_context_info.constprop/313 (751619278 (estimated locally),0.70 per call) 
  Calls: 
fci_fp_db_init/288 (fci_fp_db_init) @0793dd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_init_context_info.constprop/313 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memset/287 (autolibc_memset) @0793db60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_init_param_validate.isra.0.constprop/312 (840525101 (estimated locally),0.78 per call) fci_fini/35 (365072221 (estimated locally),0.34 per call) 
  Calls: 
fci_hm_cb_register/286 (fci_hm_cb_register) @0793d9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_init/34 (262422502 (estimated locally),0.24 per call) 
  Calls: 
fci_owner_init/285 (fci_owner_init) @0793d8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_init/34 (262422502 (estimated locally),0.24 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/284 (oal_util_raise_dem_for_drv_runtime_err) @0793d7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_init_param_validate.isra.0.constprop/312 (233216724 (estimated locally),0.22 per call) fci_init/34 (262422502 (estimated locally),0.24 per call) 
  Calls: 
pfe_hm_report/283 (pfe_hm_report) @0793d700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_init_param_validate.isra.0.constprop/312 (233216724 (estimated locally),0.22 per call) fci_init/34 (262422502 (estimated locally),0.24 per call) 
  Calls: 
fci_core_init/282 (fci_core_init) @0793d620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_init/34 (524845004 (estimated locally),0.49 per call) 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/281 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @0793d460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/280 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @0793d380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/279 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @0793d2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/278 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @0793d1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/277 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @0793d0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/276 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @0793d000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/275 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @0793bee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/274 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @0793be00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/273 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @0793bd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/272 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @0793bc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/271 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @0793bb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/270 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @0793ba80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/269 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @0793b9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/268 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @0793b8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/267 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @0793b7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/266 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @0793b700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/265 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @0793b620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/264 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @0793b540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/263 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @0793b460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/262 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @0793b380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/261 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @0793b2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/260 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @0793b1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/259 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @0793b0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/258 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @0793b000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/257 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @0793aee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/256 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @0793ae00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/255 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @0793ad20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/254 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @0793ac40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/253 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @0793ab60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/252 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @0793aa80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/251 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @0793a9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/250 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @0793a8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/249 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @0793a7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/248 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @0793a700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/247 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @0793a620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/246 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @0793a540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/245 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @0793a460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/244 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @0793a380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/243 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @0793a2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/242 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @0793a1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/241 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @0793a0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/240 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @0793a000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/239 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @07939ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/238 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @07939e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/237 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @07939d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/236 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @07939c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/235 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @07939b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/234 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @07939a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/233 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @079399a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/232 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @079398c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/231 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @079397e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/230 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @07939700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/229 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @07939620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/228 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @07939540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/227 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @07939460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/226 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @07939380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/225 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @079392a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/224 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @079391c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/223 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @079390e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/222 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @07939000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/221 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @07938ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/220 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @07938e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/219 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @07938d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/218 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @07938c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/217 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @07938b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/216 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @07938a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/215 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @079389a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/214 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @079388c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/213 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @079387e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/212 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @07938700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/211 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @07938620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/210 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @07938540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/209 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @07938460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/208 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @07938380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/207 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @079382a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/206 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @079381c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/205 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @079380e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/204 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @07938000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/203 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @07936d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/202 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @07937ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/201 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @07937e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/200 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @07937d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/199 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @07937c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/198 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @07937b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/197 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @07937a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/196 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @079379a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/195 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @079378c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/194 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @079377e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/193 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @07937700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/192 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @07937620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/191 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @07937540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/190 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @07937460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/189 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @07937380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/188 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @079372a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/187 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @079371c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/186 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @079370e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/185 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @07937000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/184 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @07936ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/183 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @07936e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/182 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @07936c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/181 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @07936b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/180 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @07936a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/179 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @079369a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/178 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @079368c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/177 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @079367e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/176 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @07936620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/175 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @07936540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/174 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @07936460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/173 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @07936380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/172 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @079362a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/171 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @079361c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/170 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @079360e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/169 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @07936000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/168 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @07935ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/167 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @07935e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/166 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @07935d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/165 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @07935c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/164 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @07935b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/163 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @07935a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/162 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @079359a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/161 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @079358c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/160 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @079357e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/159 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @07935700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/158 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @07935620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/157 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @07935540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/156 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @07935460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/155 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @07935380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/154 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @079352a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/153 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @079351c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/152 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @079350e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/151 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @07935000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/150 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @07934ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/149 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @07934e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/148 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @07934d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/147 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @07934c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/146 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @07934b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/145 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @07934a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/144 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @079349a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/143 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @079348c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/142 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @079347e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/141 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @07934700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/140 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @07934620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/139 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @07934540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/138 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @07934460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/137 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @07934380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/136 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @079342a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/135 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @079341c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/134 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @079340e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/133 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @07934000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/132 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @07933ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/131 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @07933e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/130 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @07933d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/129 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @07933c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/128 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @07933b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/127 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @07933a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/126 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @079339a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/125 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @079338c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/124 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @079337e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/123 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @07933700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/122 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @07933620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/121 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @07933540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/120 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @07933460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/119 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @07933380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/118 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @079332a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/117 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @079331c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/116 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @079330e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/115 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @07933000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/114 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @07932ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/113 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @07932e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/112 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @07932d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/111 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @07932c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/110 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @07932b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/109 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @07932a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/108 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @079329a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/107 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @079328c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/106 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @079327e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/105 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @07932700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/104 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @07932620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/103 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @07932540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/102 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @07932460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/101 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @07932380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/100 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @079322a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/99 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @079321c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/98 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @079320e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/97 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @07932000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/96 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @0792cee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/95 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @07930ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/94 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @07930e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/93 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @07930d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/92 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @07930c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/91 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @07930b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/90 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @07930a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/89 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @079309a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/88 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @079308c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/87 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @079307e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/86 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @07930700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/85 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @07930620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/84 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @07930540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/83 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @07930460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/82 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @07930380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/81 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @079302a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/80 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @079301c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/79 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @079300e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/78 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @07930000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/77 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @0792ce00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/76 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @0792cd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/75 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @0792cc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/74 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @0792cb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/73 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @0792ca80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/72 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @0792c9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
fci_timer_owner_unlock_cmd/71 (fci_timer_owner_unlock_cmd) @0792c7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_timer_owner_lock_cmd/70 (fci_timer_owner_lock_cmd) @0792c700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_l2br_flush_cmd/69 (fci_l2br_flush_cmd) @0792c620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_qos_policer_shp_cmd/68 (fci_qos_policer_shp_cmd) @0792c540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_qos_policer_wred_cmd/67 (fci_qos_policer_wred_cmd) @0792c460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_qos_policer_flow_cmd/66 (fci_qos_policer_flow_cmd) @0792c380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_qos_policer_cmd/65 (fci_qos_policer_cmd) @0792c2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_mirror_cmd/64 (fci_mirror_cmd) @0792c1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_qos_shaper_cmd/63 (fci_qos_shaper_cmd) @0792c0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_qos_scheduler_cmd/62 (fci_qos_scheduler_cmd) @0792c000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_qos_queue_cmd/61 (fci_qos_queue_cmd) @0792aee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_fw_features_element_cmd/60 (fci_fw_features_element_cmd) @0792ae00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_fw_features_cmd/59 (fci_fw_features_cmd) @0792ad20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_fp_rule_cmd/58 (fci_fp_rule_cmd) @0792ac40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_fp_table_cmd/57 (fci_fp_table_cmd) @0792ab60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_l2br_static_entry_cmd/56 (fci_l2br_static_entry_cmd) @0792aa80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_l2br_domain_cmd/55 (fci_l2br_domain_cmd) @0792a9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_routes_drop_all_ipv6/54 (fci_routes_drop_all_ipv6) @0792a8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_routes_drop_all_ipv4/53 (fci_routes_drop_all_ipv4) @0792a7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_connections_ipv6_ct_cmd/52 (fci_connections_ipv6_ct_cmd) @0792a700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_connections_ipv4_ct_cmd/51 (fci_connections_ipv4_ct_cmd) @0792a620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_connections_ipv4_timeout_cmd/50 (fci_connections_ipv4_timeout_cmd) @0792a540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_routes_cmd/49 (fci_routes_cmd) @0792a460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_interfaces_mac_cmd/48 (fci_interfaces_mac_cmd) @0792a380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_interfaces_phy_cmd/47 (fci_interfaces_phy_cmd) @0792a2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_interfaces_log_cmd/46 (fci_interfaces_log_cmd) @0792a1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
fci_interfaces_session_cmd/45 (fci_interfaces_session_cmd) @0792a0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (35755603 (estimated locally),0.03 per call) 
  Calls: 
pfe_class_put_data/44 (pfe_class_put_data) @0792a000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (11799349 (estimated locally),0.01 per call) 
  Calls: 
autolibc_memcpy/43 (autolibc_memcpy) @07908a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: execute_fci_cmd/29 (11799349 (estimated locally),0.01 per call) 
  Calls: 
fci_owner_get_floating_lock/42 (fci_owner_get_floating_lock) @079089a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_authorize_and_lock/31 (177167400 (estimated locally),0.16 per call) 
  Calls: 
fci_owner_authorize/41 (fci_owner_authorize) @079088c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_authorize_and_lock/31 (1073741821 (estimated locally),1.00 per call) 
  Calls: 
fci_owner_session_cmd/40 (fci_owner_session_cmd) @07908700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_check_credentials/32 (72638634 (estimated locally),0.07 per call) 
  Calls: 
fci_sender_get_phy_if_id/39 (fci_sender_get_phy_if_id) @07908620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_check_credentials/32 (354334802 (estimated locally),0.33 per call) 
  Calls: 
fci_owner_mutex_lock/38 (fci_owner_mutex_lock) @07908540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_check_credentials/32 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
fci_owner_mutex_unlock/37 (fci_owner_mutex_unlock) @07908380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_process_ipc_message/33 (45942143 (estimated locally),0.04 per call) fci_check_credentials/32 (116930485 (estimated locally),0.11 per call) 
  Calls: 
fci_owner_clear_floating_lock/36 (fci_owner_clear_floating_lock) @079082a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_process_ipc_message/33 (45942143 (estimated locally),0.04 per call) 
  Calls: 
fci_fini/35 (fci_fini) @07978c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: context/27 (read)context/27 (read)context/27 (read)context/27 (write)context/27 (write)context/27 (read)context/27 (write)context/27 (read)context/27 (write)context/27 (write)context/27 (read)context/27 (write)context/27 (write)context/27 (read)context/27 (write)context/27 (write)context/27 (write)context/27 (read)context/27 (write)context/27 (addr)context/27 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: fci_init/34 (131211251 (estimated locally),0.12 per call) fci_init/34 (262422502 (estimated locally),0.24 per call) 
  Calls: autolibc_memset/287 (365072221 (estimated locally),0.34 per call) oal_mutex_unlock.part.0/296 (73890617 (estimated locally),0.07 per call) fci_routes_drop_all/290 (73890617 (estimated locally),0.07 per call) oal_mutex_lock.part.0/295 (73890617 (estimated locally),0.07 per call) pfe_if_db_unlock/294 (365072221 (estimated locally),0.34 per call) pfe_if_db_lock/293 (365072220 (estimated locally),0.34 per call) fci_core_fini/292 (195204116 (estimated locally),0.18 per call) fci_hm_cb_deregister/291 (73890617 (estimated locally),0.07 per call) oal_mutex_unlock.part.0/296 (73890617 (estimated locally),0.07 per call) fci_routes_drop_all/290 (73890617 (estimated locally),0.07 per call) oal_mutex_lock.part.0/295 (73890617 (estimated locally),0.07 per call) 
fci_init/34 (fci_init) @07978700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: context/27 (addr)context/27 (write)context/27 (addr)context/27 (write)context/27 (write)context/27 (write)context/27 (write)context/27 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: fci_hm_cb_register/286 (262422502 (estimated locally),0.24 per call) fci_init_context_info.constprop/313 (131211251 (estimated locally),0.12 per call) fci_fini/35 (131211251 (estimated locally),0.12 per call) fci_owner_init/285 (262422502 (estimated locally),0.24 per call) fci_fini/35 (262422502 (estimated locally),0.24 per call) oal_util_raise_dem_for_drv_runtime_err/284 (262422502 (estimated locally),0.24 per call) pfe_hm_report/283 (262422502 (estimated locally),0.24 per call) fci_core_init/282 (524845004 (estimated locally),0.49 per call) fci_init_param_validate.isra.0.constprop/312 (1073741824 (estimated locally),1.00 per call) 
fci_process_ipc_message/33 (fci_process_ipc_message) @07978e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: fci_owner_mutex_unlock/37 (45942143 (estimated locally),0.04 per call) fci_owner_clear_floating_lock/36 (45942143 (estimated locally),0.04 per call) execute_fci_cmd/29 (226986874 (estimated locally),0.21 per call) fci_check_credentials/32 (217325345 (estimated locally),0.20 per call) 
fci_check_credentials/32 (fci_check_credentials) @07978b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_process_ipc_message/33 (217325345 (estimated locally),0.20 per call) 
  Calls: fci_owner_mutex_unlock/37 (116930485 (estimated locally),0.11 per call) fci_authorize_and_lock/31 (104528767 (estimated locally),0.10 per call) fci_owner_session_cmd/40 (72638634 (estimated locally),0.07 per call) fci_sender_get_phy_if_id/39 (354334802 (estimated locally),0.33 per call) fci_owner_mutex_lock/38 (1073741824 (estimated locally),1.00 per call) 
fci_authorize_and_lock/31 (fci_authorize_and_lock) @079788c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741821 (estimated locally) body local optimize_size
  Called by: fci_check_credentials/32 (104528767 (estimated locally),0.10 per call) 
  Calls: fci_owner_get_floating_lock/42 (177167400 (estimated locally),0.16 per call) fci_owner_authorize/41 (1073741821 (estimated locally),1.00 per call) 
fci_init_context_info/30 (fci_init_context_info) @07978620
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
execute_fci_cmd/29 (execute_fci_cmd) @07978380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/27 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_process_ipc_message/33 (226986874 (estimated locally),0.21 per call) 
  Calls: fci_timer_owner_unlock_cmd/71 (35755603 (estimated locally),0.03 per call) fci_timer_owner_lock_cmd/70 (35755603 (estimated locally),0.03 per call) fci_l2br_flush_cmd/69 (35755603 (estimated locally),0.03 per call) fci_qos_policer_shp_cmd/68 (35755603 (estimated locally),0.03 per call) fci_qos_policer_wred_cmd/67 (35755603 (estimated locally),0.03 per call) fci_qos_policer_flow_cmd/66 (35755603 (estimated locally),0.03 per call) fci_qos_policer_cmd/65 (35755603 (estimated locally),0.03 per call) fci_mirror_cmd/64 (35755603 (estimated locally),0.03 per call) fci_qos_shaper_cmd/63 (35755603 (estimated locally),0.03 per call) fci_qos_scheduler_cmd/62 (35755603 (estimated locally),0.03 per call) fci_qos_queue_cmd/61 (35755603 (estimated locally),0.03 per call) fci_fw_features_element_cmd/60 (35755603 (estimated locally),0.03 per call) fci_fw_features_cmd/59 (35755603 (estimated locally),0.03 per call) fci_fp_rule_cmd/58 (35755603 (estimated locally),0.03 per call) fci_fp_table_cmd/57 (35755603 (estimated locally),0.03 per call) fci_l2br_static_entry_cmd/56 (35755603 (estimated locally),0.03 per call) fci_l2br_domain_cmd/55 (35755603 (estimated locally),0.03 per call) oal_mutex_unlock.part.0/296 (35755603 (estimated locally),0.03 per call) fci_routes_drop_all_ipv6/54 (35755603 (estimated locally),0.03 per call) oal_mutex_lock.part.0/295 (35755603 (estimated locally),0.03 per call) oal_mutex_unlock.part.0/296 (35755603 (estimated locally),0.03 per call) fci_routes_drop_all_ipv4/53 (35755603 (estimated locally),0.03 per call) oal_mutex_lock.part.0/295 (35755603 (estimated locally),0.03 per call) oal_mutex_unlock.part.0/296 (35755603 (estimated locally),0.03 per call) fci_connections_ipv6_ct_cmd/52 (35755603 (estimated locally),0.03 per call) oal_mutex_lock.part.0/295 (35755603 (estimated locally),0.03 per call) oal_mutex_unlock.part.0/296 (35755603 (estimated locally),0.03 per call) fci_connections_ipv4_ct_cmd/51 (35755603 (estimated locally),0.03 per call) oal_mutex_lock.part.0/295 (35755603 (estimated locally),0.03 per call) oal_mutex_unlock.part.0/296 (35755603 (estimated locally),0.03 per call) fci_connections_ipv4_timeout_cmd/50 (35755603 (estimated locally),0.03 per call) oal_mutex_lock.part.0/295 (35755603 (estimated locally),0.03 per call) oal_mutex_unlock.part.0/296 (35755603 (estimated locally),0.03 per call) fci_routes_cmd/49 (35755603 (estimated locally),0.03 per call) oal_mutex_lock.part.0/295 (35755603 (estimated locally),0.03 per call) fci_interfaces_mac_cmd/48 (35755603 (estimated locally),0.03 per call) fci_interfaces_phy_cmd/47 (35755603 (estimated locally),0.03 per call) fci_interfaces_log_cmd/46 (35755603 (estimated locally),0.03 per call) fci_interfaces_session_cmd/45 (35755603 (estimated locally),0.03 per call) pfe_class_put_data/44 (11799349 (estimated locally),0.01 per call) autolibc_memcpy/43 (11799349 (estimated locally),0.01 per call) 
context/27 (context) @07972318
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: fci_fini/35 (write)execute_fci_cmd/29 (read)fci_fini/35 (read)fci_fini/35 (read)fci_fini/35 (read)fci_fini/35 (write)fci_fini/35 (write)fci_fini/35 (read)fci_fini/35 (write)fci_fini/35 (read)fci_fini/35 (write)fci_fini/35 (write)fci_fini/35 (read)fci_fini/35 (write)fci_fini/35 (write)fci_fini/35 (read)fci_fini/35 (write)fci_fini/35 (write)fci_fini/35 (write)fci_fini/35 (read)fci_fini/35 (write)fci_fini/35 (addr)fci_init/34 (addr)fci_init/34 (write)fci_init/34 (addr)fci_init/34 (write)fci_init/34 (write)fci_init/34 (write)fci_init/34 (write)fci_init/34 (write)fci_init_param_validate.isra.0.constprop.0/312 (addr)fci_init_context_info.constprop.0/313 (addr)
  Availability: available
  Varpool flags: initialized
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @06ff0d38
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/177 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/178 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/179 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/180 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/181 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/182 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/183 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/184 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/185 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/186 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/187 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/188 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/189 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/190 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/191 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/192 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/193 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/194 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/195 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/196 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/197 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/198 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/199 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/200 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/201 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/202 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/203 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/204 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/205 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/206 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/207 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/208 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/209 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/210 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/211 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/212 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/213 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/214 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/215 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/216 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/217 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/218 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/219 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/220 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/221 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/222 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/223 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/224 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/225 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/226 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/227 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/228 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/229 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/230 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/231 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/232 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/233 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/234 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/235 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/236 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/237 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/238 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/239 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/240 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/241 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/242 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/243 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/244 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/245 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/246 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/247 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/248 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/249 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/250 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/251 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/252 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/253 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/254 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/255 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/256 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/257 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/258 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/259 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/260 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/261 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/262 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/263 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/264 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/265 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/266 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/267 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/268 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/269 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/270 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/271 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/272 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/273 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/274 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/275 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/276 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/277 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/278 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/279 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/280 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/281 (addr)
  Referring: oal_mutex_unlock.part.0/296 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @06ff0c60
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/72 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/73 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/74 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/75 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/76 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/77 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/78 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/79 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/80 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/81 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/82 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/83 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/84 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/85 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/86 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/87 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/88 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/89 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/90 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/91 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/92 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/93 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/94 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/95 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/96 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/97 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/98 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/99 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/100 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/101 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/102 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/103 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/104 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/105 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/106 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/107 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/108 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/109 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/110 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/111 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/112 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/113 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/114 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/115 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/116 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/117 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/118 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/119 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/120 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/121 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/122 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/123 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/124 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/125 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/126 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/127 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/128 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/129 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/130 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/131 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/132 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/133 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/134 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/135 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/136 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/137 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/138 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/139 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/140 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/141 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/142 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/143 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/144 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/145 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/146 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/147 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/148 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/149 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/150 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/151 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/152 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/153 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/154 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/155 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/156 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/157 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/158 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/159 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/160 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/161 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/162 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/163 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/164 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/165 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/166 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/167 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/168 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/169 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/170 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/171 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/172 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/173 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/174 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/175 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/176 (addr)
  Referring: oal_mutex_lock.part.0/295 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function oal_mutex_lock.part.0 (oal_mutex_lock.part.0, funcdef_no=32, decl_uid=13138, cgraph_uid=292, symbol_order=295)

Modification phase of node oal_mutex_lock.part.0/295
Adjusting mask for param 0 to 0x3
Setting value range of param 0 [97, 98]
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



;; Function oal_mutex_unlock.part.0 (oal_mutex_unlock.part.0, funcdef_no=33, decl_uid=13143, cgraph_uid=293, symbol_order=296)

Modification phase of node oal_mutex_unlock.part.0/296
Adjusting mask for param 0 to 0x3
Setting value range of param 0 [97, 98]
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



;; Function fci_process_ipc_message (fci_process_ipc_message, funcdef_no=29, decl_uid=12086, cgraph_uid=30, symbol_order=33)

Modification phase of node fci_process_ipc_message/33
fci_process_ipc_message (struct fci_msg_t * msg, struct fci_msg_t * rep_msg)
{
  struct fci_vars_t passed_vars;
  uint16_t * reply_retval_ptr;
  uint32_t * reply_buf_len_ptr;
  uint32_t * reply_buf_ptr;
  uint16_t fci_ret;
  errno_t ret;
  uint8_t * _1;
  uint32_t * _2;
  <unnamed type> _3;
  unsigned char _4;
  <unnamed type> _5;
  unsigned char _6;
  uint32_t * reply_buf_len_ptr.1_7;
  long unsigned int _8;
  long unsigned int _9;
  uint8_t[256] * _10;
  short unsigned int fci_ret.3_11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  fci_ret = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  reply_retval_ptr = 0B;
  # DEBUG BEGIN_STMT
  passed_vars.p_msg = msg_22(D);
  passed_vars.p_rep_msg = rep_msg_24(D);
  passed_vars.fci_floating_lock = 0;
  passed_vars.bCheckRet = 0;
  # DEBUG BEGIN_STMT
  _1 = &rep_msg_24(D)->msg_cmd.payload[4];
  reply_buf_ptr = _1;
  # DEBUG BEGIN_STMT
  _2 = &rep_msg_24(D)->msg_cmd.length;
  reply_buf_len_ptr = _2;
  # DEBUG BEGIN_STMT
  *_2 = 252;
  # DEBUG BEGIN_STMT
  _3 = msg_22(D)->type;
  if (_3 == 4099)
    goto <bb 3>; [20.24%]
  else
    goto <bb 4>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  ret_32 = fci_check_credentials (&passed_vars, &fci_ret, &reply_buf_len_ptr, &reply_retval_ptr);
  # DEBUG ret => ret_32

  <bb 4> [local count: 1073741824]:
  # ret_12 = PHI <0(2), ret_32(3)>
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  _4 = passed_vars.bCheckRet;
  if (_4 != 1)
    goto <bb 5>; [66.00%]
  else
    goto <bb 12>; [34.00%]

  <bb 5> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  _5 = msg_22(D)->type;
  if (_5 == 4099)
    goto <bb 6>; [32.03%]
  else
    goto <bb 12>; [67.97%]

  <bb 6> [local count: 226986874]:
<L3>:
  # DEBUG BEGIN_STMT
  ret_34 = execute_fci_cmd (msg_22(D), &fci_ret, &reply_buf_ptr, &reply_buf_len_ptr);
  # DEBUG ret => ret_34
  # DEBUG BEGIN_STMT
  _6 = passed_vars.fci_floating_lock;
  if (_6 == 1)
    goto <bb 7>; [20.24%]
  else
    goto <bb 11>; [79.76%]

  <bb 7> [local count: 45942143]:
  # DEBUG BEGIN_STMT
  ret_36 = fci_owner_clear_floating_lock ();
  # DEBUG ret => ret_36
  # DEBUG BEGIN_STMT
  if (ret_36 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 22971072]:
  # DEBUG BEGIN_STMT
  fci_ret = 65535;

  <bb 9> [local count: 45942143]:
  # DEBUG BEGIN_STMT
  ret_39 = fci_owner_mutex_unlock ();
  # DEBUG ret => ret_39
  # DEBUG BEGIN_STMT
  if (ret_39 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 22971072]:
  # DEBUG BEGIN_STMT
  fci_ret = 65535;

  <bb 11> [local count: 226986874]:
  # ret_13 = PHI <ret_34(6), ret_39(9), ret_39(10)>
  # DEBUG ret => ret_13
  # DEBUG BEGIN_STMT
  reply_buf_len_ptr.1_7 = reply_buf_len_ptr;
  _8 = *reply_buf_len_ptr.1_7;
  _9 = _8 + 4;
  rep_msg_24(D)->msg_cmd.length = _9;
  # DEBUG BEGIN_STMT
  _10 = &rep_msg_24(D)->msg_cmd.payload;
  # DEBUG BEGIN_STMT
  fci_ret.3_11 = fci_ret;
  MEM[(uint16_t *)_10] = fci_ret.3_11;
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 1073741824]:
  # ret_14 = PHI <ret_12(4), ret_13(11), 22(5)>
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  fci_ret ={v} {CLOBBER};
  reply_buf_ptr ={v} {CLOBBER};
  reply_buf_len_ptr ={v} {CLOBBER};
  reply_retval_ptr ={v} {CLOBBER};
  passed_vars ={v} {CLOBBER};
  return ret_14;

}



;; Function fci_fini (fci_fini, funcdef_no=31, decl_uid=12083, cgraph_uid=32, symbol_order=35)

Modification phase of node fci_fini/35
fci_fini ()
{
  uint32_t session_id;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;
  struct fci_core_t * _4;
  unsigned char _5;
  unsigned char _6;
  long unsigned int session_id.7_7;
  unsigned char _8;
  unsigned char _9;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG fci_context => &context
  # DEBUG BEGIN_STMT
  session_id = 0;
  # DEBUG BEGIN_STMT
  _1 = context.fci_initialized;
  if (_1 == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 18>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  _2 = context.rt_db_initialized;
  if (_2 == 1)
    goto <bb 4>; [20.24%]
  else
    goto <bb 5>; [79.76%]

  <bb 4> [local count: 73890617]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 98
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (98);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  fci_routes_drop_all ();
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 98
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (98);

  <bb 5> [local count: 365072220]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _3 = context.hm_cb_registered;
  if (_3 == 1)
    goto <bb 6>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 6> [local count: 73890617]:
  # DEBUG BEGIN_STMT
  fci_hm_cb_deregister ();
  # DEBUG BEGIN_STMT
  context.hm_cb_registered = 0;
  # DEBUG BEGIN_STMT
  context.is_some_client = 0;

  <bb 7> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  _4 = context.core;
  if (_4 != 0B)
    goto <bb 8>; [53.47%]
  else
    goto <bb 9>; [46.53%]

  <bb 8> [local count: 195204116]:
  # DEBUG BEGIN_STMT
  fci_core_fini ();
  # DEBUG BEGIN_STMT
  context.core = 0B;

  <bb 9> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  pfe_if_db_lock (&session_id);
  # DEBUG BEGIN_STMT
  _5 = context.log_if_db_initialized;
  if (_5 == 1)
    goto <bb 10>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 10> [local count: 124124555]:
  # DEBUG BEGIN_STMT
  context.log_if_db = 0B;
  # DEBUG BEGIN_STMT
  context.log_if_db_initialized = 0;

  <bb 11> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  _6 = context.phy_if_db_initialized;
  if (_6 == 1)
    goto <bb 12>; [34.00%]
  else
    goto <bb 13>; [66.00%]

  <bb 12> [local count: 124124555]:
  # DEBUG BEGIN_STMT
  context.phy_if_db = 0B;
  # DEBUG BEGIN_STMT
  context.phy_if_db_initialized = 0;

  <bb 13> [local count: 365072221]:
  # DEBUG BEGIN_STMT
  session_id.7_7 = session_id;
  pfe_if_db_unlock (session_id.7_7);
  # DEBUG BEGIN_STMT
  _8 = context.rt_db_initialized;
  if (_8 == 1)
    goto <bb 14>; [20.24%]
  else
    goto <bb 15>; [79.76%]

  <bb 14> [local count: 73890617]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 98
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (98);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  fci_routes_drop_all ();
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 98
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (98);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  context.rt_db_initialized = 0;

  <bb 15> [local count: 365072221]:
  # DEBUG BEGIN_STMT
  context.rtable = 0B;
  # DEBUG BEGIN_STMT
  context.rtable_initialized = 0;
  # DEBUG BEGIN_STMT
  _9 = context.fci_owner_initialized;
  if (_9 == 1)
    goto <bb 16>; [34.00%]
  else
    goto <bb 17>; [66.00%]

  <bb 16> [local count: 124124555]:
  # DEBUG BEGIN_STMT
  context.fci_owner_initialized = 0;

  <bb 17> [local count: 365072221]:
  # DEBUG BEGIN_STMT
  autolibc_memset (&context, 0, 6536);
  # DEBUG BEGIN_STMT
  context.fci_initialized = 0;

  <bb 18> [local count: 1073741824]:
  session_id ={v} {CLOBBER};
  return;

}



;; Function fci_init (fci_init, funcdef_no=30, decl_uid=12081, cgraph_uid=31, symbol_order=34)

Modification phase of node fci_init/34
fci_init (struct fci_init_info_t * info, const char_t * const identifier)
{
  errno_t err;
  int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG fci_context => &context
  # DEBUG BEGIN_STMT
  # DEBUG err => 0
  # DEBUG BEGIN_STMT
  # DEBUG D#2 => identifier_8(D)
  err_10 = fci_init_param_validate.isra.0 (&context);
  # DEBUG err => err_10
  # DEBUG BEGIN_STMT
  if (err_10 != 22)
    goto <bb 3>; [48.88%]
  else
    goto <bb 13>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  err_12 = fci_core_init (identifier_8(D));
  # DEBUG err => err_12
  # DEBUG BEGIN_STMT
  if (err_12 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 262422502]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not create FCI core\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/fci.c", 783, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  fci_fini ();
  goto <bb 13>; [100.00%]

  <bb 5> [local count: 262422502]:
  # DEBUG BEGIN_STMT
  err_15 = fci_owner_init (info_13(D));
  # DEBUG err => err_15
  # DEBUG BEGIN_STMT
  if (err_15 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 131211251]:
  # DEBUG BEGIN_STMT
  context.fci_owner_initialized = 1;

  <bb 7> [local count: 262422502]:
  # DEBUG BEGIN_STMT
  if (err_15 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 131211251]:
  # DEBUG BEGIN_STMT
  fci_fini ();
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 131211251]:
  # DEBUG BEGIN_STMT
  fci_init_context_info (&context, info_13(D));

  <bb 10> [local count: 262422502]:
  # DEBUG BEGIN_STMT
  _1 = fci_hm_cb_register ();
  if (_1 == 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 11> [local count: 131211251]:
  # DEBUG BEGIN_STMT
  context.hm_cb_registered = 1;

  <bb 12> [local count: 262422502]:
  # DEBUG BEGIN_STMT
  context.default_timeouts.timeout_tcp = 432000;
  # DEBUG BEGIN_STMT
  context.default_timeouts.timeout_udp = 300;
  # DEBUG BEGIN_STMT
  context.default_timeouts.timeout_other = 240;
  # DEBUG BEGIN_STMT
  context.fci_initialized = 1;

  <bb 13> [local count: 1073741824]:
  # err_2 = PHI <err_10(2), err_12(4), err_15(12)>
  # DEBUG err => err_2
  # DEBUG BEGIN_STMT
  return err_2;

}


