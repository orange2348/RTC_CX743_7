#if !defined( CCL_APP_CFG_H )
  #define CCL_APP_CFG_H

  /* ===========================================================================
  **
  **                     CONFIDENTIAL VISTEON CORPORATION
  **
  **  This is an unpublished work of authorship  which contains trade secrets 
  **  created in 2007.  Visteon Corporation owns all rights to this work and
  **  intends to maintain it in confidence to preserve its trade secret status.
  **  Visteon Corporation reserves the right  under the copyright laws of the
  **  United States or those of any other country that may have jurisdiction  to
  **  protect this work as an unpublished work  in the event of an inadvertent
  **  or deliberate unauthorized publication.  Visteon Corporation also reserves
  **  its rights under all copyright laws to protect this work as a published
  **  work  when appropriate.  Those having access to this work may not copy it 
  **  use it  modify it or disclose the information contained in it without the
  **  written authorization of Visteon Corporation.
  **
  ** =========================================================================*/

  /* ===========================================================================
  **
  **  Name:           CanCcl_Par_Cfg.h
  **
  **  Description:    CAN CCL configuration parameters for configured database
  **
  **  Organization:   Vehicle Communications
  **                  Visteon Corporation
  **
  ** =========================================================================*/

  /* ===========================================================================
  **  I N C L U D E   F I L E S
  ** =========================================================================*/

  #include "CanCcl_Cfg.h"
  #include "CanCcl_Defines.h"
  #include "Com_Handles.h"
   

/* ===========================================================================
  **  M A C R O   D E F I N I T I O N S
  ** =========================================================================*/

  /* DBC Tx & Rx CFG */

  #ifndef Can_ControllerId
  #define Can_ControllerId                        (0u)
  #endif

#define Can_Ccl_Rx_Num_Messages                 (46u)
#define Can_Ccl_Rx_Num_Periodic_Messages        (37u) /*no use*/
#define Can_Ccl_Rx_Num_Signals                  (294u)
#define Can_Ccl_Rx_Num_Periodic_Signals         (261u) /*no use*/
#define Can_Ccl_Rx_Num_RxAck_Ind                (294u)
#define Can_Ccl_Rx_Num_RxTOut_Ind               (294u)
#define Can_Ccl_Rx_Num_RxInv_Ind                (1u)

#define Can_Ccl_Tx_Num_Messages                 (7u)
#define Can_Ccl_Tx_Signal_Num_Signals           (72u)
#define Can_Ccl_Tx_Num_Periodic                 (7u)
#define Can_Ccl_Tx_Num_Burst_Periodic           (0u)

#define Can_Ccl_Num_Of_PduGroups                (2u)
  #define CCL_MAX_IPDUGROUPVECTOR_BYTES           (1u) 


/*Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
  /*      Symbolic Name                                  Value   Active in predefined variant(s) */
  #define CanCclConf_IPduGroup_TuringECU_CAN_Rx           1u
  #define CanCclConf_IPduGroup_TuringECU_CAN_Tx           0u



  /* Handle IDs of handle space CclRxSig [Rx Signals] */
	/*		Symbolic Name																	   Value   Active in predefined variant(s) */
#define CanCclRxHndlCh0_SCU_faultwarning_200                            0u
#define CanCclRxHndlCh0_EMS_EngCoolanTemp_267                           1u
#define CanCclRxHndlCh0_EMS_EngOperationStatus_267                      2u
#define CanCclRxHndlCh0_EMS_BatteryVoltageError_267                     3u
#define CanCclRxHndlCh0_EMS_EngSpeed_267                                4u
#define CanCclRxHndlCh0_EMS_StartStopMessage_267                        5u
#define CanCclRxHndlCh0_TCU_DisplayGear_291                             6u
#define CanCclRxHndlCh0_TCU_GearSelectorReq_291                         7u
#define CanCclRxHndlCh0_TCU_StGearMode_291                              8u
#define CanCclRxHndlCh0_TCU_Status_AliveCounter0x123_291                9u
#define CanCclRxHndlCh0_TCU_Status_Checksum0x123_291                    10u
#define CanCclRxHndlCh0_EMS_TargCruiseSpeed_337                         11u
#define CanCclRxHndlCh0_EMS_CruiseControlStatus_337                     12u
#define CanCclRxHndlCh0_TBOX_ECALLFlt_418                               13u
#define CanCclRxHndlCh0_PEPS_Remotestartstatus_421                      14u
#define CanCclRxHndlCh0_ABS_WhlMilgFrntLe_545                           15u
#define CanCclRxHndlCh0_ABS_WhlMilgFrntRi_545                           16u
#define CanCclRxHndlCh0_ABS_VehSpdLgt_545                               17u
#define CanCclRxHndlCh0_ABS_EbdFlgFlt_545                               18u
#define CanCclRxHndlCh0_ABS_AbsFlgFlt_545                               19u
#define CanCclRxHndlCh0_ABS_RollingCounter_0x221_545                    20u
#define CanCclRxHndlCh0_ABS_WhlMilgFrntLeStatus_545                     21u
#define CanCclRxHndlCh0_ABS_WhlMilgFrntRiStatus_545                     22u
#define CanCclRxHndlCh0_ABS_Checksum_0x221_545                          23u
#define CanCclRxHndlCh0_ESP_HHCAvailable_579                            24u
#define CanCclRxHndlCh0_ABS_HAZActive_579                               25u
#define CanCclRxHndlCh0_ESP_EPBStatus_579                               26u
#define CanCclRxHndlCh0_ESP_EPBErrorStatus_579                          27u
#define CanCclRxHndlCh0_ESP_HDCAvailable_579                            28u
#define CanCclRxHndlCh0_ESP_HDCActive_579                               29u
#define CanCclRxHndlCh0_ESP_CdpAvailable_579                            30u
#define CanCclRxHndlCh0_ESP_EPBWarningMessage3_579                      31u
#define CanCclRxHndlCh0_ESP_EPBWarningMessage2_579                      32u
#define CanCclRxHndlCh0_ESP_EPBWarningMessage1_579                      33u
#define CanCclRxHndlCh0_ESP_AVHWarningMessage_579                       34u
#define CanCclRxHndlCh0_ESP_AvhActive_579                               35u
#define CanCclRxHndlCh0_ESP_AvhStandby_579                              36u
#define CanCclRxHndlCh0_ESP_AvhAvabliable_579                           37u
#define CanCclRxHndlCh0_ESP_VdcFlgFlt_579                               38u
#define CanCclRxHndlCh0_ESP_TcsFlgFlt_579                               39u
#define CanCclRxHndlCh0_ESP_ESPInfoLamp_579                             40u
#define CanCclRxHndlCh0_ESP_EspEnableSts_579                            41u
#define CanCclRxHndlCh0_ESP_RollingCounter_0x243_579                    42u
#define CanCclRxHndlCh0_ESP_Checksum_0x243_579                          43u
#define CanCclRxHndlCh0_IPM_LaneAssitType_581                           44u
#define CanCclRxHndlCh0_IPM_LaneAssit_WarningVibration_581              45u
#define CanCclRxHndlCh0_IPM_LaneAssit_WarningAudio_581                  46u
#define CanCclRxHndlCh0_IPM_LaneAssit_LeftVisualization_581              47u
#define CanCclRxHndlCh0_IPM_LaneAssit_RightVisualization_581              48u
#define CanCclRxHndlCh0_IPM_SLASpdlimitUnits_581                        49u
#define CanCclRxHndlCh0_IPM_SLAState_581                                50u
#define CanCclRxHndlCh0_IPM_LaneAssit_Status_581                        51u
#define CanCclRxHndlCh0_IPM_SLASpdlimit_581                             52u
#define CanCclRxHndlCh0_IPM_HMA_Status_581                              53u
#define CanCclRxHndlCh0_IPM_DDD_IndexStatus_581                         54u
#define CanCclRxHndlCh0_IPM_DDD_WarningLevel_581                        55u
#define CanCclRxHndlCh0_IPM_LaneAssit_HandsonReq_581                    56u
#define CanCclRxHndlCh0_vSetDis_582                                     57u
#define CanCclRxHndlCh0_ObjValid_582                                    58u
#define CanCclRxHndlCh0_TauGapSet_582                                   59u
#define CanCclRxHndlCh0_dxTarObj_582                                    60u
#define CanCclRxHndlCh0_ACCHMI_Mode_582                                 61u
#define CanCclRxHndlCh0_ACCFailInfo_582                                 62u
#define CanCclRxHndlCh0_TakeOverReq_582                                 63u
#define CanCclRxHndlCh0_AEB_STATE_582                                   64u
#define CanCclRxHndlCh0_ACC_Startstop_infor_582                         65u
#define CanCclRxHndlCh0_PCW_preWarning_582                              66u
#define CanCclRxHndlCh0_PCW_latentWarning_582                           67u
#define CanCclRxHndlCh0_PCW_STATE_582                                   68u
#define CanCclRxHndlCh0_Obj_Speed_582                                   69u
#define CanCclRxHndlCh0_Rolling_counter_0x246_582                       70u
#define CanCclRxHndlCh0_Textinfo_582                                    71u
#define CanCclRxHndlCh0_Checksum_0x246_582                              72u
#define CanCclRxHndlCh0_IPM_DCLC_manualfeedback_583                     73u
#define CanCclRxHndlCh0_IPM_ELKSts_583                                  74u
#define CanCclRxHndlCh0_IPM_DCLCSts_583                                 75u
#define CanCclRxHndlCh0_EPS_S_WarningLampYellow_608                     76u
#define CanCclRxHndlCh0_EPS_S_SafeLampRed_608                           77u
#define CanCclRxHndlCh0_Rolling_counter_0x260_608                       78u
#define CanCclRxHndlCh0_Checksum_0x260_608                              79u
#define CanCclRxHndlCh0_PAM_ChimeCmdSoundStatus_625                     80u
#define CanCclRxHndlCh0_PAM_RearSysTemWorkSts_625                       81u
#define CanCclRxHndlCh0_PAM_FrontSysTemWorkSts_625                      82u
#define CanCclRxHndlCh0_PAM_ChimeCmdSoundCadence_625                    83u
#define CanCclRxHndlCh0_LAEB_BrkgReqVal_628                             84u
#define CanCclRxHndlCh0_LAEB_BrkgReq_628                                85u
#define CanCclRxHndlCh0_LAEB_DistanceToCollision_628                    86u
#define CanCclRxHndlCh0_LAEB_SpeakReq_628                               87u
#define CanCclRxHndlCh0_LAEB_WorkSts_628                                88u
#define CanCclRxHndlCh0_Checksum_0x274_628                              89u
#define CanCclRxHndlCh0_Rolling_counter_0x274_628                       90u
#define CanCclRxHndlCh0_LAEB_LedReq_628                                 91u
#define CanCclRxHndlCh0_SOD_LCA_warningReqRight_629                     92u
#define CanCclRxHndlCh0_SOD_DOA_warningReqRightRear_629                 93u
#define CanCclRxHndlCh0_SOD_DOA_warningReqRightFront_629                94u
#define CanCclRxHndlCh0_SOD_CTA_warningReqRight_629                     95u
#define CanCclRxHndlCh0_SOD_BLIS_display_629                            96u
#define CanCclRxHndlCh0_SOD_LCA_warningReqLeft_629                      97u
#define CanCclRxHndlCh0_SOD_DOA_warningReqLeftRear_629                  98u
#define CanCclRxHndlCh0_SOD_DOA_warningReqLeftFront_629                 99u
#define CanCclRxHndlCh0_SOD_CTA_warningReqLeft_629                      100u
#define CanCclRxHndlCh0_DOA_OFFTelltale_629                             101u
#define CanCclRxHndlCh0_CTA_OFFTelltale_629                             102u
#define CanCclRxHndlCh0_SODLCA_OFFTelltale_629                          103u
#define CanCclRxHndlCh0_IPM_LedtLine_dx_start_632                       104u
#define CanCclRxHndlCh0_IPM_LeftLine_dy_632                             105u
#define CanCclRxHndlCh0_IPM_LeftLine_dx_lookhead_632                    106u
#define CanCclRxHndlCh0_IPM_LeftLine_hor_curve_632                      107u
#define CanCclRxHndlCh0_IPM_LeftLine_yawangle_632                       108u
#define CanCclRxHndlCh0_MRR_F_Object_dx_633                             109u
#define CanCclRxHndlCh0_MRR_F_Object_dy_633                             110u
#define CanCclRxHndlCh0_MRR_F_Obj_0x_class_633                          111u
#define CanCclRxHndlCh0_MRR_FF_Object_dx_633                            112u
#define CanCclRxHndlCh0_MRR_FF_Object_dy_633                            113u
#define CanCclRxHndlCh0_MRR_FF_Obj_0x_class_633                         114u
#define CanCclRxHndlCh0_MRR_FFTargrtDetection_633                       115u
#define CanCclRxHndlCh0_MRR_PedDetection_633                            116u
#define CanCclRxHndlCh0_IPM_LaneAssit_LeftVisualization_640              117u
#define CanCclRxHndlCh0_IPM_LeftLine_Type_640                           118u
#define CanCclRxHndlCh0_IPM_LeftLine_Color_640                          119u
#define CanCclRxHndlCh0_IPM_leftLeftLine_Type_640                       120u
#define CanCclRxHndlCh0_IPM_leftLeftLine_Color_640                      121u
#define CanCclRxHndlCh0_IPM_leftleftLine_dy_640                         122u
#define CanCclRxHndlCh0_IPM_leftleftLine_hor_curve_640                  123u
#define CanCclRxHndlCh0_IPM_leftleftLine_yawangle_640                   124u
#define CanCclRxHndlCh0_IPM_leftleftLine_cur_alteration_640              125u
#define CanCclRxHndlCh0_BCM_DoorStsRearRi_784                           126u
#define CanCclRxHndlCh0_BCM_DoorStsRearLe_784                           127u
#define CanCclRxHndlCh0_BCM_DoorStsFrntRi_784                           128u
#define CanCclRxHndlCh0_BCM_DoorStsFrntLe_784                           129u
#define CanCclRxHndlCh0_BCM_DoorLockStsRearRi_784                       130u
#define CanCclRxHndlCh0_BCM_DoorLockStsRearLe_784                       131u
#define CanCclRxHndlCh0_BCM_DoorLockStsFrntRi_784                       132u
#define CanCclRxHndlCh0_BCM_DoorLockStsFrntLe_784                       133u
#define CanCclRxHndlCh0_BCM_AntiTheftSts_784                            134u
#define CanCclRxHndlCh0_BCM_LockUnlockFeedback_784                      135u
#define CanCclRxHndlCh0_BCM_DoorLockStsTrunk_784                        136u
#define CanCclRxHndlCh0_BCM_DoorStsTrunk_784                            137u
#define CanCclRxHndlCh0_BCM_TrunkDoorPreUnlockSts_784                   138u
#define CanCclRxHndlCh0_BCM_EnginehoodSts_784                           139u
#define CanCclRxHndlCh0_BCM_Rolling_counter_0x310_784                   140u
#define CanCclRxHndlCh0_BCM_TurnIndicatorSts_784                        141u
#define CanCclRxHndlCh0_BCM_Checksum_0x310_784                          142u
#define CanCclRxHndlCh0_BCM_OutsideTempDig_787                          143u
#define CanCclRxHndlCh0_BCM_BrakeFluidSts_787                           144u
#define CanCclRxHndlCh0_BCM_OutsideTemp_787                             145u
#define CanCclRxHndlCh0_BCM_Reverse_gear_787                            146u
#define CanCclRxHndlCh0_BCM_SS_EnableSts_787                            147u
#define CanCclRxHndlCh0_BCM_Rollingcounter_0x313_787                    148u
#define CanCclRxHndlCh0_BCM_Checksum_0x313_787                          149u
#define CanCclRxHndlCh0_BCM_BGLLumLvlSettingStatus_789                  150u
#define CanCclRxHndlCh0_BCM_FrntFogLmpSts_792                           151u
#define CanCclRxHndlCh0_BCM_PosLmpSts_792                               152u
#define CanCclRxHndlCh0_BCM_LowBeamSts_792                              153u
#define CanCclRxHndlCh0_BCM_HighBeamSts_792                             154u
#define CanCclRxHndlCh0_BCM_reversinglightSts_792                       155u
#define CanCclRxHndlCh0_BCM_DayRunningLampSts_792                       156u
#define CanCclRxHndlCh0_BCM_RearFogLmpSts_792                           157u
#define CanCclRxHndlCh0_BCM_laserlightSts_792                           158u
#define CanCclRxHndlCh0_BCM_AmbientLightSts_792                         159u
#define CanCclRxHndlCh0_BCM_Highmountedstoplamp_792                     160u
#define CanCclRxHndlCh0_BCM_BrakelightSts_792                           161u
#define CanCclRxHndlCh0_BCM_BackHomeSts_792                             162u
#define CanCclRxHndlCh0_BCM_AutolampSts_792                             163u
#define CanCclRxHndlCh0_BCM_readinglampSts_792                          164u
#define CanCclRxHndlCh0_BCM_DayRunningLampDig_792                       165u
#define CanCclRxHndlCh0_BCM_BrakelightDig_792                           166u
#define CanCclRxHndlCh0_BCM_reversinglightDig_792                       167u
#define CanCclRxHndlCh0_BCM_TurnIndicatorDig_792                        168u
#define CanCclRxHndlCh0_BCM_RearFogLmpDig_792                           169u
#define CanCclRxHndlCh0_BCM_FrntFogLmpDig_792                           170u
#define CanCclRxHndlCh0_BCM_PosLmpDig_792                               171u
#define CanCclRxHndlCh0_BCM_LowBeamDig_792                              172u
#define CanCclRxHndlCh0_BCM_Rollingcounter_0x318_792                    173u
#define CanCclRxHndlCh0_BCM_Checksum_0x318_792                          174u
#define CanCclRxHndlCh0_SWM_Menu_Right_794                              175u
#define CanCclRxHndlCh0_SWM_Menu_Left_794                               176u
#define CanCclRxHndlCh0_SWM_Menu_Down_794                               177u
#define CanCclRxHndlCh0_SWM_Menu_Up_794                                 178u
#define CanCclRxHndlCh0_Rolling_counter_0x31A_794                       179u
#define CanCclRxHndlCh0_SWM_Menu_Return_794                             180u
#define CanCclRxHndlCh0_SWM_Menu_Confirm_794                            181u
#define CanCclRxHndlCh0_Checksum_0x31A_794                              182u
#define CanCclRxHndlCh0_SWM_ACCtauGapSetPlus_795                        183u
#define CanCclRxHndlCh0_SWM_ACCvSetMinus_795                            184u
#define CanCclRxHndlCh0_SWM_ACCvSetPlus_795                             185u
#define CanCclRxHndlCh0_SWM_ACCResume_795                               186u
#define CanCclRxHndlCh0_SWM_ACCSet_795                                  187u
#define CanCclRxHndlCh0_SWM_ACCEnableSwitch_795                         188u
#define CanCclRxHndlCh0_SWM_LaneAssistSwitch_795                        189u
#define CanCclRxHndlCh0_SWM_ACCtauGapSetMinus_795                       190u
#define CanCclRxHndlCh0_PEPS_PowerMode_805                              191u
#define CanCclRxHndlCh0_PEPS_IMMO_MatchStatus_805                       192u
#define CanCclRxHndlCh0_PEPS_SystemFailStatus_805                       193u
#define CanCclRxHndlCh0_PEPS_ESCL_FailStatus_805                        194u
#define CanCclRxHndlCh0_PEPS_SSB_FailStatus_805                         195u
#define CanCclRxHndlCh0_PEPS_BrakeIndicationWarning_805                 196u
#define CanCclRxHndlCh0_PEPS_NotPNWarning_805                           197u
#define CanCclRxHndlCh0_PEPS_DoorOpenNotOFFWarning_805                  198u
#define CanCclRxHndlCh0_PEPS_DoorOpenWarning_805                        199u
#define CanCclRxHndlCh0_PEPS_KeyBatteryWarning_805                      200u
#define CanCclRxHndlCh0_PEPS_KeyOutWarning1_805                         201u
#define CanCclRxHndlCh0_PEPS_NoKeyFoundWarning_805                      202u
#define CanCclRxHndlCh0_PEPS_KeyReminderWarning_805                     203u
#define CanCclRxHndlCh0_PEPS_RemainingNumSts_805                        204u
#define CanCclRxHndlCh0_SRS_SBR_PAMsenger_848                           205u
#define CanCclRxHndlCh0_SRS_SBR_Driver_848                              206u
#define CanCclRxHndlCh0_SRS_AirBagFailSts_848                           207u
#define CanCclRxHndlCh0_SRS_SBR_SecondRowRight_848                      208u
#define CanCclRxHndlCh0_SRS_SBR_SecondRowMid_848                        209u
#define CanCclRxHndlCh0_SRS_SBR_SecondRowLeft_848                       210u
#define CanCclRxHndlCh0_Rolling_counter_0x350_848                       211u
#define CanCclRxHndlCh0_Checksum_0x350_848                              212u
#define CanCclRxHndlCh0_TPMS_LF_Pressure_865                            213u
#define CanCclRxHndlCh0_TPMS_RF_Pressure_865                            214u
#define CanCclRxHndlCh0_TPMS_RR_Pressure_865                            215u
#define CanCclRxHndlCh0_TPMS_LR_Pressure_865                            216u
#define CanCclRxHndlCh0_TPMS_Tire_Temperature_865                       217u
#define CanCclRxHndlCh0_TPMS_LF_Pressure_Warning_865                    218u
#define CanCclRxHndlCh0_TPMS_RF_Pressure_Warning_865                    219u
#define CanCclRxHndlCh0_TPMS_System_Status_865                          220u
#define CanCclRxHndlCh0_TPMS_RR_Pressure_Warning_865                    221u
#define CanCclRxHndlCh0_TPMS_LR_Pressure_Warning_865                    222u
#define CanCclRxHndlCh0_TPMS_Temperature_Warning_865                    223u
#define CanCclRxHndlCh0_TPMS_resrved_865                                224u
#define CanCclRxHndlCh0_Tire_Position_865                               225u
#define CanCclRxHndlCh0_TPMS_Lamp_Status_865                            226u
#define CanCclRxHndlCh0_EMS_Fuelcounter_870                             227u
#define CanCclRxHndlCh0_EMS_FuelconsumptionInst_870                     228u
#define CanCclRxHndlCh0_EMS_MIL_870                                     229u
#define CanCclRxHndlCh0_EMS_SVS_870                                     230u
#define CanCclRxHndlCh0_EMS_StartStopStatus_870                         231u
#define CanCclRxHndlCh0_EMS_GasPrtcWarn_G_Rq_872                        232u
#define CanCclRxHndlCh0_MP5_AudioStatus_898                             233u
#define CanCclRxHndlCh0_MP5_EnergyFlow_898                              234u
#define CanCclRxHndlCh0_MP5_SetMultiButton_898                          235u
#define CanCclRxHndlCh0_MP5_BSDSoundSwitchSts_898                       236u
#define CanCclRxHndlCh0_MP5_NavStatus_898                               237u
#define CanCclRxHndlCh0_MP5_NavICON_900                                 238u
#define CanCclRxHndlCh0_MP5_ROUTE_REMAIN_DIS_900                        239u
#define CanCclRxHndlCh0_MP5_ALModeSetting_900                           240u
#define CanCclRxHndlCh0_MP5_ALStartAroundSetting_900                    241u
#define CanCclRxHndlCh0_TCU_EmergencyTowingSts_917                      242u
#define CanCclRxHndlCh0_TrnSrvcRqd_B_Rq_917                             243u
#define CanCclRxHndlCh0_TCU_GearPFault_917                              244u
#define CanCclRxHndlCh0_TCU_WarningMessage_917                          245u
#define CanCclRxHndlCh0_TCU_DrvShiftAllwCondRmd_917                     246u
#define CanCclRxHndlCh0_MRR_L_Object_dx_1152                            247u
#define CanCclRxHndlCh0_MRR_L_Object_dy_1152                            248u
#define CanCclRxHndlCh0_MRR_L_Obj_0x_class_1152                         249u
#define CanCclRxHndlCh0_MRR_R_Object_dx_1152                            250u
#define CanCclRxHndlCh0_MRR_R_Object_dy_1152                            251u
#define CanCclRxHndlCh0_MRR_R_Obj_0x_class_1152                         252u
#define CanCclRxHndlCh0_MRR_LeftTargrtDetection_1152                    253u
#define CanCclRxHndlCh0_MRR_RightTargrtDetection_1152                   254u
#define CanCclRxHndlCh0_IPM_RightLine_dx_start_1168                     255u
#define CanCclRxHndlCh0_IPM_RightLine_dy_1168                           256u
#define CanCclRxHndlCh0_IPM_RightLine_dx_lookhead_1168                  257u
#define CanCclRxHndlCh0_IPM_RightLine_hor_curve_1168                    258u
#define CanCclRxHndlCh0_IPM_RightLine_yawangle_1168                     259u
#define CanCclRxHndlCh0_IPM_LaneAssit_RightVisualization_1169              260u
#define CanCclRxHndlCh0_IPM_rightRighLine_Type_1169                     261u
#define CanCclRxHndlCh0_IPM_RighLine_Color_1169                         262u
#define CanCclRxHndlCh0_IPM_RighLine_Type_1169                          263u
#define CanCclRxHndlCh0_IPM_RighrightLine_Color_1169                    264u
#define CanCclRxHndlCh0_IPM_rightRightLine_dy_1169                      265u
#define CanCclRxHndlCh0_IPM_rightRightLine_hor_curve_1169               266u
#define CanCclRxHndlCh0_IPM_rightRightLine_yawangle_1169                267u
#define CanCclRxHndlCh0_IPM_RightLine_cur_alteration_1169               268u
#define CanCclRxHndlCh0_AVM_displaytype_1312                            269u
#define CanCclRxHndlCh0_AVM_Status_1312                                 270u
#define CanCclRxHndlCh0_AVM_Guide_line_info_1312                        271u
#define CanCclRxHndlCh0_AVM_Switch_1312                                 272u
#define CanCclRxHndlCh0_MP5_ICMenuShift_Button_1328                     273u
#define CanCclRxHndlCh0_MP5_ICMenuActive_Button_1328                    274u
#define CanCclRxHndlCh0_MP5_AlarmStatus_1328                            275u
#define CanCclRxHndlCh0_MP5_AlarmOrNot_1328                             276u
#define CanCclRxHndlCh0_MP5_ICMenu_Cmd_1330                             277u
#define CanCclRxHndlCh0_Nav_Sts_1331                                    278u
#define CanCclRxHndlCh0_MP5_BGLLumLvlSetting_1333                       279u
#define CanCclRxHndlCh0_WACM_WirelessChargerStatus_1335                 280u
#define CanCclRxHndlCh0_TBOX_Year_1410                                  281u
#define CanCclRxHndlCh0_TBOX_Month_1410                                 282u
#define CanCclRxHndlCh0_TBOX_Date_1410                                  283u
#define CanCclRxHndlCh0_TBOX_Hour_1410                                  284u
#define CanCclRxHndlCh0_TBOX_Minute_1410                                285u
#define CanCclRxHndlCh0_TBOX_Second_1410                                286u
#define CanCclRxHndlCh0_TBOX_ReTime_1410                                287u
#define CanCclRxHndlCh0_BCM_LoadManageLevel_1412                        288u
#define CanCclRxHndlCh0_BCM_CarModeIndicator_1412                       289u
#define CanCclRxHndlCh0_BCM_CarMode_1412                                290u
#define CanCclRxHndlCh0_AFS_WorkSts_1440                                291u
#define CanCclRxHndlCh0_SCMM_HMIDisplay_1443                            292u
#define CanCclRxHndlCh0_EMS_BackupOdometer_1590                         293u




/* Handle IDs of handle space CclTxSig [Tx Signals] */
  /*      Symbolic Name                                                                      Value   Active in predefined variant(s) */
#define CanCclTxHndlCh0_IC_BSDSoundSts_902                              0u
#define CanCclTxHndlCh0_IC_Fuel_level_903                               1u
#define CanCclTxHndlCh0_IC_DriveTimehour_903                            2u
#define CanCclTxHndlCh0_IC_DriveTimeMinute_903                          3u
#define CanCclTxHndlCh0_IC_AverageSpeed_903                             4u
#define CanCclTxHndlCh0_IC_ChangOilDistance_903                         5u
#define CanCclTxHndlCh0_BackUpODO_903                                   6u
#define CanCclTxHndlCh0_IC_ABSLamp_906                                  7u
#define CanCclTxHndlCh0_IC_EBDFaultLamp_906                             8u
#define CanCclTxHndlCh0_IC_BrakefluidLowLamp_906                        9u
#define CanCclTxHndlCh0_IC_APBFaultLamp_906                             10u
#define CanCclTxHndlCh0_IC_APBLamp_906                                  11u
#define CanCclTxHndlCh0_IC_AVHLamp_906                                  12u
#define CanCclTxHndlCh0_IC_BatteryLamp_906                              13u
#define CanCclTxHndlCh0_IC_CoolantHighLamp_906                          14u
#define CanCclTxHndlCh0_IC_FuelLowLamp_906                              15u
#define CanCclTxHndlCh0_IC_OilpressureLowLamp_906                       16u
#define CanCclTxHndlCh0_IC_EngineMaintainLamp_906                       17u
#define CanCclTxHndlCh0_IC_EngineFaultLamp_906                          18u
#define CanCclTxHndlCh0_IC_ESPLamp_906                                  19u
#define CanCclTxHndlCh0_IC_AntitheftLamp_906                            20u
#define CanCclTxHndlCh0_IC_ACCFaultLamp_906                             21u
#define CanCclTxHndlCh0_IC_ACCLamp_906                                  22u
#define CanCclTxHndlCh0_IC_SRSLamp_906                                  23u
#define CanCclTxHndlCh0_IC_TPMSLamp_906                                 24u
#define CanCclTxHndlCh0_IC_TCUServiceLamp_906                           25u
#define CanCclTxHndlCh0_IC_EPSFaultLamp_906                             26u
#define CanCclTxHndlCh0_IC_EPSLamp_906                                  27u
#define CanCclTxHndlCh0_IC_SSSystemFaultLamp_906                        28u
#define CanCclTxHndlCh0_IC_ESCLLamp_906                                 29u
#define CanCclTxHndlCh0_IC_PEPSLamp_906                                 30u
#define CanCclTxHndlCh0_IC_InsulationLamp_906                           31u
#define CanCclTxHndlCh0_IC_VehFailGradeWarning_906                      32u
#define CanCclTxHndlCh0_IC_EVSystemLamp_906                             33u
#define CanCclTxHndlCh0_IC_ThermalRunaywaWarning_906                    34u
#define CanCclTxHndlCh0_IC_SOClowWarning_906                            35u
#define CanCclTxHndlCh0_IC_HandbrakeLamp_906                            36u
#define CanCclTxHndlCh0_IC_48VSystemFaultLamp_906                       37u
#define CanCclTxHndlCh0_IC_MotorTemHighLamp_906                         38u
#define CanCclTxHndlCh0_IC_MotorRestLamp_906                            39u
#define CanCclTxHndlCh0_IC_DCDCLamp_906                                 40u
#define CanCclTxHndlCh0_IC_MotorLamp_906                                41u
#define CanCclTxHndlCh0_IC_PackSystemLamp_906                           42u
#define CanCclTxHndlCh0_IC_OdometerMasterValue_1296                     43u
#define CanCclTxHndlCh0_IC_AirbagTelltaleBehavior_1296                  44u
#define CanCclTxHndlCh0_IC_VehBrkPump_ERR_IC_1296                       45u
#define CanCclTxHndlCh0_IC_DISFail_1296                                 46u
#define CanCclTxHndlCh0_IC_QDashACCFail_1296                            47u
#define CanCclTxHndlCh0_IC_VehSpd_HMI_1296                              48u
#define CanCclTxHndlCh0_BackupCountODO_1296                             49u
#define CanCclTxHndlCh0_IC_Rolling_counter_0x510_1296                   50u
#define CanCclTxHndlCh0_IC_Checksum_0x510_1296                          51u
#define CanCclTxHndlCh0_IC_TemperatureUnitsSetting_1297                 52u
#define CanCclTxHndlCh0_IC_MileageUnitsSetting_1297                     53u
#define CanCclTxHndlCh0_IC_LanguageSetting_1297                         54u
#define CanCclTxHndlCh0_IC_AFCUnitsSetting_1297                         55u
#define CanCclTxHndlCh0_IC_PressureUnitsSetting_1297                    56u
#define CanCclTxHndlCh0_IC_AFC_1317                                     57u
#define CanCclTxHndlCh0_IC_DTE_1317                                     58u
#define CanCclTxHndlCh0_IC_AlarmStatus_1317                             59u
#define CanCclTxHndlCh0_IC_AlarmOrNot_1317                              60u
#define CanCclTxHndlCh0_IC_AFC_Type_1317                                61u
#define CanCclTxHndlCh0_IC_Fuel_Level_Volumn_1317                       62u
#define CanCclTxHndlCh0_IC_Fuel_Level_VolumnQF_1317                     63u
#define CanCclTxHndlCh0_IC_Rolling_counter_0x525_1317                   64u
#define CanCclTxHndlCh0_IC_Checksum_0x525_1317                          65u
#define CanCclTxHndlCh0_IC_Year_1409                                    66u
#define CanCclTxHndlCh0_IC_Month_1409                                   67u
#define CanCclTxHndlCh0_IC_Date_1409                                    68u
#define CanCclTxHndlCh0_IC_Hour_1409                                    69u
#define CanCclTxHndlCh0_IC_Minute_1409                                  70u
#define CanCclTxHndlCh0_IC_Second_1409                                  71u



typedef CAN_UINT8 Ccl_IpduGroupVector[CCL_MAX_IPDUGROUPVECTOR_BYTES];


  # include "CanCcl_Com.h"


/* ===========================================================================
** G L O B A L   C O N S T A N T   D E C L A R A T I O N S
** =========================================================================*/

extern CONST(Ccl_TxSigInfoType, CCL_CONST) Can_Ccl_TxSigInfo[Can_Ccl_Tx_Signal_Num_Signals];

extern CONST(Ccl_RxAccessInfoType, CCL_CONST) Can_Ccl_RxAccessInfo[Can_Ccl_Rx_Num_Signals];


/**********************************************************************************************************************
  Ccl_CbkRxAckFuncPtr
**********************************************************************************************************************/
/**
  \var    Ccl_CbkRxAckFuncPtr
  \brief  Function pointer table containing configured Rx indication notifications for signals and signal groups.
*/

extern CONST(CclCbkRxAckType, CCL_CONST) Can_Ccl_CbkRxAckFuncPtr[Can_Ccl_Rx_Num_RxAck_Ind];

/**********************************************************************************************************************
  Ccl_CbkRxTOutFuncPtr
**********************************************************************************************************************/
/**
  \var    Ccl_CbkRxTOutFuncPtr
  \brief  Function pointer table containing configured Rx timeout notifications for signals and signal groups.}
*/

extern CONST(CclCbkRxTOutType, CCL_CONST) Can_Ccl_CbkRxTOutFuncPtr[Can_Ccl_Rx_Num_RxTOut_Ind];


/**********************************************************************************************************************
  Ccl_CbkRxInvFuncPtr
**********************************************************************************************************************/
/**
  \var    Ccl_CbkRxInvFuncPtr
  \brief  Function pointer table containing configured Rx invalid notifications for signals and signal groups.
*/

#if (CCL_RX_INVINDICATION_API == STD_ON)
extern CONST(CclCbkInvType, CCL_CONST) Can_Ccl_CbkRxInvFuncPtr[Can_Ccl_Rx_Num_RxInv_Ind];
#endif

/**********************************************************************************************************************
  Ccl_NumOfContainedRxSignals
**********************************************************************************************************************/
/**
  \var    Ccl_NumOfContainedRxSignals
  \brief  Structure describing the starting signal handle and the number of signals contaiend in Rx messages
*/

extern CONST(Ccl_MessageContentInfo, CCL_CONST) Can_Ccl_NumOfContainedRxSignals[Can_Ccl_Rx_Num_Messages];


/**********************************************************************************************************************
  Ccl_NumOfContainedTxSignals
**********************************************************************************************************************/
/**
  \var    Ccl_NumOfContainedTxSignals
  \brief  Structure describing the starting signal handle and the number of signals contaiend in Tx messages
*/

extern CONST(Ccl_MessageContentInfo, CCL_CONST) Can_Ccl_NumOfContainedTxSignals[Can_Ccl_Tx_Num_Messages];


/**********************************************************************************************************************
  Ccl_NumOfContainedTxSignals
**********************************************************************************************************************/
extern CONST(Ccl_RxNotifFuncInfo, CCL_CONST) Can_Ccl_RxNotifFuncPtr[Can_Ccl_Rx_Num_Signals];


/**********************************************************************************************************************
  Ccl_PduGrpVector
**********************************************************************************************************************/
/**
  \var    Ccl_PduGrpVector
  \brief  Contains an I-PDU-Group vector for each I-PDU  mapping the I-PDU to the corresponding I-PDU-Groups.
  */
extern CONST(Ccl_PduGrpVectorType, CCL_CONST) Can_Ccl_PduGrpVector[Can_Ccl_Num_Of_PduGroups];


/**********************************************************************************************************************
  Ccl_TxPduGrpInfo
**********************************************************************************************************************/
/**
  \var    Ccl_TxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Tx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Ccl_PduGrpVector
*/
extern CONST(Ccl_TxPduGrpInfoType, CCL_CONST) Can_Ccl_TxPduGrpInfo[Can_Ccl_Tx_Num_Messages];


/**********************************************************************************************************************
  Ccl_RxPduGrpInfo
**********************************************************************************************************************/
/**
  \var    Ccl_RxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Rx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Ccl_PduGrpVector
*/
extern CONST(Ccl_RxPduGrpInfoType, CCL_CONST) Can_Ccl_RxPduGrpInfo[Can_Ccl_Rx_Num_Messages];


/**********************************************************************************************************************
  Ccl_DefRxPduInfo
**********************************************************************************************************************/
/**
  \var    Ccl_DefRxPduInfo
  \brief  Contains all relevant information for deferred Rx I-PDUs.
  \details
  Element                   Description
  RxDefPduBufferUsed        TRUE  if the 0:n relation has 1 relation pointing to ilRxBuffer
*/
extern CONST(Ccl_DefRxPduInfoType, CCL_CONST) Can_Ccl_DefRxPduInfo[Can_Ccl_Rx_Num_Messages];


#endif /* CCL_APP_CFG_H */


/*****************************************************************************
    R E V I S I O N     N O T E S
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  -
For each change to this file  be sure to record:
1.   Who made the change and when the change was made.
2.   Why the change was made and the intended result.

Date       By         Reason For Change
------------------------------------------------------------------------------

******************************************************************************/
/*****************************************************************************
Date          : 2021-01-06 14:51:25
By              : ChengJia
Traceability    : JMC_SUV_Body_CAN_Matrix_20210104.dbc
Change Description  : Tool Generated code
*****************************************************************************/
