#if !defined(CAN_IL_PAR_H)
#define CAN_IL_PAR_H
/* ===========================================================================

                      CONFIDENTIAL VISTEON CORPORATION

   This is an unpublished work of authorship, which contains trade secrets,
   created in 2006.  Visteon Corporation owns all rights to this work and
   intends to maintain it in confidence to preserve its trade secret status.
   Visteon Corporation reserves the right, under the copyright laws of the
   United States or those of any other country that may have jurisdiction, to
   protect this work as an unpublished work, in the event of an inadvertent
   or deliberate unauthorized publication.  Visteon Corporation also reserves
   its rights under all copyright laws to protect this work as a published
   work, when appropriate.  Those having access to this work may not copy it,
   use it, modify it or disclose the information contained in it without the
   written authorization of Visteon Corporation.

  =========================================================================*/
/* ===========================================================================

    Name:           CanIl_Par_Cfg.h

    Description:    CAN Interaction Layer Tx, Rx Parameters Header File

    Organization:   Multiplex Core Technology

   =========================================================================*/ 

#include "CanIl_Defines.h" 

/* ===========================================================================
   P U B L I C   M A C R O S
  =========================================================================*/

/* ===========================================================================
   Interaction Layer Number of Transmit Messages, Signals
  =========================================================================*/


#define Can_Ch0_Il_Tx_Num_Burst_Periodic   (0u) /*no use*/


#define Can_Ch0_Il_Tx_Num_Periodic         (7u)


/* ===========================================================================
     Interaction Layer Number of Receive Messages, Signals
    =========================================================================*/


#define Can_Ch0_Il_Rx_Num_Periodic         (37u)	/*no use*/

#define Can_Ch0_Il_Rx_Num_Periodic_Signals (261u)	/*no use*/

#define Can_Ch0_Il_Rx_Num_Req_Frames       (0u)

/* ===========================================================================
      Interaction Layer support
     =========================================================================*/

  /* ===========================================================================
      Interaction Layer Transmit Message Enumerations
      NB: The below Tx message sequence should match one to one with the
          IL Tx Message Desription table.
          CAN_IL_CHANNEL0_TX_MESSAGE const
          Can_Ch0_Il_Tx_Messages[ Can_Ch0_Il_Tx_Num_Messages ]
     =========================================================================*/

/* ===========================================================================
    Interaction Layer Transmit Message (Frame) Handles
   =========================================================================*/

typedef enum
  {
Can_Ch0_Il_Tx_Msg_IC_0x386_TMH=0,
/*(0) */
Can_Ch0_Il_Tx_Msg_IC_0x387_TMH,
/*(1) */
Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,
/*(2) */
Can_Ch0_Il_Tx_Msg_IC_0x510_TMH,
/*(3) */
Can_Ch0_Il_Tx_Msg_IC_0x511_TMH,
/*(4) */
Can_Ch0_Il_Tx_Msg_IC_0x525_TMH,
/*(5) */
Can_Ch0_Il_Tx_Msg_IC_time_0x581_TMH,
/*(6) */
Can_Ch0_Il_Tx_Num_Messages
/*(7) */
}Can_Ch0_Il_Tx_Messages_Macro;


/* ===========================================================================
     Interaction Layer Transmit Signal Enumerations
     NB: The below tx signal sequence should match one to one with the
           IL Tx Signal description table.
         CAN_IL_SIGNAL const
         Can_Il_Tx_signals[ CAN_IL_TX_NUM_SIGNALS  ]

    =========================================================================*/

typedef enum
  {
Can_Ch0_Il_Tx_Sig_IC_BSDSoundSts_902 = 0,
/*(0) */
Can_Ch0_Il_Tx_Sig_IC_Fuel_level_903,
/*(1) */
Can_Ch0_Il_Tx_Sig_IC_DriveTimehour_903,
/*(2) */
Can_Ch0_Il_Tx_Sig_IC_DriveTimeMinute_903,
/*(3) */
Can_Ch0_Il_Tx_Sig_IC_AverageSpeed_903,
/*(4) */
Can_Ch0_Il_Tx_Sig_IC_ChangOilDistance_903,
/*(5) */
Can_Ch0_Il_Tx_Sig_BackUpODO_903,
/*(6) */
Can_Ch0_Il_Tx_Sig_IC_ABSLamp_906,
/*(7) */
Can_Ch0_Il_Tx_Sig_IC_EBDFaultLamp_906,
/*(8) */
Can_Ch0_Il_Tx_Sig_IC_BrakefluidLowLamp_906,
/*(9) */
Can_Ch0_Il_Tx_Sig_IC_APBFaultLamp_906,
/*(10) */
Can_Ch0_Il_Tx_Sig_IC_APBLamp_906,
/*(11) */
Can_Ch0_Il_Tx_Sig_IC_AVHLamp_906,
/*(12) */
Can_Ch0_Il_Tx_Sig_IC_BatteryLamp_906,
/*(13) */
Can_Ch0_Il_Tx_Sig_IC_CoolantHighLamp_906,
/*(14) */
Can_Ch0_Il_Tx_Sig_IC_FuelLowLamp_906,
/*(15) */
Can_Ch0_Il_Tx_Sig_IC_OilpressureLowLamp_906,
/*(16) */
Can_Ch0_Il_Tx_Sig_IC_EngineMaintainLamp_906,
/*(17) */
Can_Ch0_Il_Tx_Sig_IC_EngineFaultLamp_906,
/*(18) */
Can_Ch0_Il_Tx_Sig_IC_ESPLamp_906,
/*(19) */
Can_Ch0_Il_Tx_Sig_IC_AntitheftLamp_906,
/*(20) */
Can_Ch0_Il_Tx_Sig_IC_ACCFaultLamp_906,
/*(21) */
Can_Ch0_Il_Tx_Sig_IC_ACCLamp_906,
/*(22) */
Can_Ch0_Il_Tx_Sig_IC_SRSLamp_906,
/*(23) */
Can_Ch0_Il_Tx_Sig_IC_TPMSLamp_906,
/*(24) */
Can_Ch0_Il_Tx_Sig_IC_TCUServiceLamp_906,
/*(25) */
Can_Ch0_Il_Tx_Sig_IC_EPSFaultLamp_906,
/*(26) */
Can_Ch0_Il_Tx_Sig_IC_EPSLamp_906,
/*(27) */
Can_Ch0_Il_Tx_Sig_IC_SSSystemFaultLamp_906,
/*(28) */
Can_Ch0_Il_Tx_Sig_IC_ESCLLamp_906,
/*(29) */
Can_Ch0_Il_Tx_Sig_IC_PEPSLamp_906,
/*(30) */
Can_Ch0_Il_Tx_Sig_IC_InsulationLamp_906,
/*(31) */
Can_Ch0_Il_Tx_Sig_IC_VehFailGradeWarning_906,
/*(32) */
Can_Ch0_Il_Tx_Sig_IC_EVSystemLamp_906,
/*(33) */
Can_Ch0_Il_Tx_Sig_IC_ThermalRunaywaWarning_906,
/*(34) */
Can_Ch0_Il_Tx_Sig_IC_SOClowWarning_906,
/*(35) */
Can_Ch0_Il_Tx_Sig_IC_HandbrakeLamp_906,
/*(36) */
Can_Ch0_Il_Tx_Sig_IC_48VSystemFaultLamp_906,
/*(37) */
Can_Ch0_Il_Tx_Sig_IC_MotorTemHighLamp_906,
/*(38) */
Can_Ch0_Il_Tx_Sig_IC_MotorRestLamp_906,
/*(39) */
Can_Ch0_Il_Tx_Sig_IC_DCDCLamp_906,
/*(40) */
Can_Ch0_Il_Tx_Sig_IC_MotorLamp_906,
/*(41) */
Can_Ch0_Il_Tx_Sig_IC_PackSystemLamp_906,
/*(42) */
Can_Ch0_Il_Tx_Sig_IC_OdometerMasterValue_1296,
/*(43) */
Can_Ch0_Il_Tx_Sig_IC_AirbagTelltaleBehavior_1296,
/*(44) */
Can_Ch0_Il_Tx_Sig_IC_VehBrkPump_ERR_IC_1296,
/*(45) */
Can_Ch0_Il_Tx_Sig_IC_DISFail_1296,
/*(46) */
Can_Ch0_Il_Tx_Sig_IC_QDashACCFail_1296,
/*(47) */
Can_Ch0_Il_Tx_Sig_IC_VehSpd_HMI_1296,
/*(48) */
Can_Ch0_Il_Tx_Sig_BackupCountODO_1296,
/*(49) */
Can_Ch0_Il_Tx_Sig_IC_Rolling_counter_0x510_1296,
/*(50) */
Can_Ch0_Il_Tx_Sig_IC_Checksum_0x510_1296,
/*(51) */
Can_Ch0_Il_Tx_Sig_IC_TemperatureUnitsSetting_1297,
/*(52) */
Can_Ch0_Il_Tx_Sig_IC_MileageUnitsSetting_1297,
/*(53) */
Can_Ch0_Il_Tx_Sig_IC_LanguageSetting_1297,
/*(54) */
Can_Ch0_Il_Tx_Sig_IC_AFCUnitsSetting_1297,
/*(55) */
Can_Ch0_Il_Tx_Sig_IC_PressureUnitsSetting_1297,
/*(56) */
Can_Ch0_Il_Tx_Sig_IC_AFC_1317,
/*(57) */
Can_Ch0_Il_Tx_Sig_IC_DTE_1317,
/*(58) */
Can_Ch0_Il_Tx_Sig_IC_AlarmStatus_1317,
/*(59) */
Can_Ch0_Il_Tx_Sig_IC_AlarmOrNot_1317,
/*(60) */
Can_Ch0_Il_Tx_Sig_IC_AFC_Type_1317,
/*(61) */
Can_Ch0_Il_Tx_Sig_IC_Fuel_Level_Volumn_1317,
/*(62) */
Can_Ch0_Il_Tx_Sig_IC_Fuel_Level_VolumnQF_1317,
/*(63) */
Can_Ch0_Il_Tx_Sig_IC_Rolling_counter_0x525_1317,
/*(64) */
Can_Ch0_Il_Tx_Sig_IC_Checksum_0x525_1317,
/*(65) */
Can_Ch0_Il_Tx_Sig_IC_Year_1409,
/*(66) */
Can_Ch0_Il_Tx_Sig_IC_Month_1409,
/*(67) */
Can_Ch0_Il_Tx_Sig_IC_Date_1409,
/*(68) */
Can_Ch0_Il_Tx_Sig_IC_Hour_1409,
/*(69) */
Can_Ch0_Il_Tx_Sig_IC_Minute_1409,
/*(70) */
Can_Ch0_Il_Tx_Sig_IC_Second_1409,
/*(71) */
 Can_Ch0_Il_Tx_Num_Signals
/*(72) */
}Can_Ch0_Il_Tx_Signals_Macro;


/* ===========================================================================
      Interaction Layer Receive Message Enumerations
     =========================================================================*/
typedef enum
  {
Can_Ch0_Il_Rx_Msg_SCU_0xC8 =0,
/*(0) */
Can_Ch0_Il_Rx_Msg_GW_EMS_Power_0x10B,
/*(1) */
Can_Ch0_Il_Rx_Msg_GW_TCU_GearInfo_Power_0x123,
/*(2) */
Can_Ch0_Il_Rx_Msg_GW_EMS_Sts_Power_0x151,
/*(3) */
Can_Ch0_Il_Rx_Msg_GW_TBOX_IVI_0x1A2,
/*(4) */
Can_Ch0_Il_Rx_Msg_PEPS_Start_0x1A5,
/*(5) */
Can_Ch0_Il_Rx_Msg_GW_ABS_Sts_0x221,
/*(6) */
Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,
/*(7) */
Can_Ch0_Il_Rx_Msg_GW_IPM_0x245,
/*(8) */
Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,
/*(9) */
Can_Ch0_Il_Rx_Msg_GW_IPM_0x247,
/*(10) */
Can_Ch0_Il_Rx_Msg_GW_EPS_Chassis_0x260,
/*(11) */
Can_Ch0_Il_Rx_Msg_GW_PAM_0x271,
/*(12) */
Can_Ch0_Il_Rx_Msg_GW_PAM_0x274,
/*(13) */
Can_Ch0_Il_Rx_Msg_GW_SOD_0x275,
/*(14) */
Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x278,
/*(15) */
Can_Ch0_Il_Rx_Msg_GW_MRR_FrObj_0x279,
/*(16) */
Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x280,
/*(17) */
Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,
/*(18) */
Can_Ch0_Il_Rx_Msg_BCM_0x313,
/*(19) */
Can_Ch0_Il_Rx_Msg_BCM_Sts_0x315,
/*(20) */
Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,
/*(21) */
Can_Ch0_Il_Rx_Msg_GW_SWM_Body_0x31A,
/*(22) */
Can_Ch0_Il_Rx_Msg_GW_SWM_MRR_0x31B,
/*(23) */
Can_Ch0_Il_Rx_Msg_PEPS_0x325,
/*(24) */
Can_Ch0_Il_Rx_Msg_GW_SRS_0x350,
/*(25) */
Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361,
/*(26) */
Can_Ch0_Il_Rx_Msg_GW_EMS_Power_0x366,
/*(27) */
Can_Ch0_Il_Rx_Msg_GW_EMS_0x368,
/*(28) */
Can_Ch0_Il_Rx_Msg_MP5_0x382,
/*(29) */
Can_Ch0_Il_Rx_Msg_MP5_0x384,
/*(30) */
Can_Ch0_Il_Rx_Msg_GW_TCU_Info_0x395,
/*(31) */
Can_Ch0_Il_Rx_Msg_GW_MRR_FRObj_0x480,
/*(32) */
Can_Ch0_Il_Rx_Msg_GW_IPM_RightLine_0x490,
/*(33) */
Can_Ch0_Il_Rx_Msg_IPM_RightLine_0x491,
/*(34) */
Can_Ch0_Il_Rx_Msg_GW_AVM_0x520,
/*(35) */
Can_Ch0_Il_Rx_Msg_MP5_0x530,
/*(36) */
Can_Ch0_Il_Rx_Msg_MP5_Windows_0x532,
/*(37) */
Can_Ch0_Il_Rx_Msg_MP5_NAV_0x533,
/*(38) */
Can_Ch0_Il_Rx_Msg_MP5_Setting_0x535,
/*(39) */
Can_Ch0_Il_Rx_Msg_WACM_WirelessChg_0x537,
/*(40) */
Can_Ch0_Il_Rx_Msg_GW_TBOX_time_0x582,
/*(41) */
Can_Ch0_Il_Rx_Msg_BCM_0x584,
/*(42) */
Can_Ch0_Il_Rx_Msg_GW_AFS_0x5A0,
/*(43) */
Can_Ch0_Il_Rx_Msg_SCMM_0x5A3,
/*(44) */
Can_Ch0_Il_Rx_Msg_GW_EMS_0x636,
/*(45) */
Can_Ch0_Il_Rx_Num_Messages
/*(46) */
}Can_Ch0_Il_Rx_Messages_Macro;


/* ===========================================================================
     Interaction Layer Receive Signal Enumerations
    =========================================================================*/
  

typedef enum
{
Can_Ch0_Il_Rx_Sig_SCU_faultwarning_200 = 0,                         /*(0) */
Can_Ch0_Il_Rx_Sig_EMS_EngCoolanTemp_267,                            /*(1) */
Can_Ch0_Il_Rx_Sig_EMS_EngOperationStatus_267,                       /*(2) */
Can_Ch0_Il_Rx_Sig_EMS_BatteryVoltageError_267,                      /*(3) */
Can_Ch0_Il_Rx_Sig_EMS_EngSpeed_267,                                 /*(4) */
Can_Ch0_Il_Rx_Sig_EMS_StartStopMessage_267,                         /*(5) */
Can_Ch0_Il_Rx_Sig_TCU_DisplayGear_291,                              /*(6) */
Can_Ch0_Il_Rx_Sig_TCU_GearSelectorReq_291,                          /*(7) */
Can_Ch0_Il_Rx_Sig_TCU_StGearMode_291,                               /*(8) */
Can_Ch0_Il_Rx_Sig_TCU_Status_AliveCounter0x123_291,                 /*(9) */
Can_Ch0_Il_Rx_Sig_TCU_Status_Checksum0x123_291,                     /*(10) */
Can_Ch0_Il_Rx_Sig_EMS_TargCruiseSpeed_337,                          /*(11) */
Can_Ch0_Il_Rx_Sig_EMS_CruiseControlStatus_337,                      /*(12) */
Can_Ch0_Il_Rx_Sig_TBOX_ECALLFlt_418,                                /*(13) */
Can_Ch0_Il_Rx_Sig_PEPS_Remotestartstatus_421,                       /*(14) */
Can_Ch0_Il_Rx_Sig_ABS_WhlMilgFrntLe_545,                            /*(15) */
Can_Ch0_Il_Rx_Sig_ABS_WhlMilgFrntRi_545,                            /*(16) */
Can_Ch0_Il_Rx_Sig_ABS_VehSpdLgt_545,                                /*(17) */
Can_Ch0_Il_Rx_Sig_ABS_EbdFlgFlt_545,                                /*(18) */
Can_Ch0_Il_Rx_Sig_ABS_AbsFlgFlt_545,                                /*(19) */
Can_Ch0_Il_Rx_Sig_ABS_RollingCounter_0x221_545,                     /*(20) */
Can_Ch0_Il_Rx_Sig_ABS_WhlMilgFrntLeStatus_545,                      /*(21) */
Can_Ch0_Il_Rx_Sig_ABS_WhlMilgFrntRiStatus_545,                      /*(22) */
Can_Ch0_Il_Rx_Sig_ABS_Checksum_0x221_545,                           /*(23) */
Can_Ch0_Il_Rx_Sig_ESP_HHCAvailable_579,                             /*(24) */
Can_Ch0_Il_Rx_Sig_ABS_HAZActive_579,                                /*(25) */
Can_Ch0_Il_Rx_Sig_ESP_EPBStatus_579,                                /*(26) */
Can_Ch0_Il_Rx_Sig_ESP_EPBErrorStatus_579,                           /*(27) */
Can_Ch0_Il_Rx_Sig_ESP_HDCAvailable_579,                             /*(28) */
Can_Ch0_Il_Rx_Sig_ESP_HDCActive_579,                                /*(29) */
Can_Ch0_Il_Rx_Sig_ESP_CdpAvailable_579,                             /*(30) */
Can_Ch0_Il_Rx_Sig_ESP_EPBWarningMessage3_579,                       /*(31) */
Can_Ch0_Il_Rx_Sig_ESP_EPBWarningMessage2_579,                       /*(32) */
Can_Ch0_Il_Rx_Sig_ESP_EPBWarningMessage1_579,                       /*(33) */
Can_Ch0_Il_Rx_Sig_ESP_AVHWarningMessage_579,                        /*(34) */
Can_Ch0_Il_Rx_Sig_ESP_AvhActive_579,                                /*(35) */
Can_Ch0_Il_Rx_Sig_ESP_AvhStandby_579,                               /*(36) */
Can_Ch0_Il_Rx_Sig_ESP_AvhAvabliable_579,                            /*(37) */
Can_Ch0_Il_Rx_Sig_ESP_VdcFlgFlt_579,                                /*(38) */
Can_Ch0_Il_Rx_Sig_ESP_TcsFlgFlt_579,                                /*(39) */
Can_Ch0_Il_Rx_Sig_ESP_ESPInfoLamp_579,                              /*(40) */
Can_Ch0_Il_Rx_Sig_ESP_EspEnableSts_579,                             /*(41) */
Can_Ch0_Il_Rx_Sig_ESP_RollingCounter_0x243_579,                     /*(42) */
Can_Ch0_Il_Rx_Sig_ESP_Checksum_0x243_579,                           /*(43) */
Can_Ch0_Il_Rx_Sig_IPM_LaneAssitType_581,                            /*(44) */
Can_Ch0_Il_Rx_Sig_IPM_LaneAssit_WarningVibration_581,               /*(45) */
Can_Ch0_Il_Rx_Sig_IPM_LaneAssit_WarningAudio_581,                   /*(46) */
Can_Ch0_Il_Rx_Sig_IPM_LaneAssit_LeftVisualization_581,              /*(47) */
Can_Ch0_Il_Rx_Sig_IPM_LaneAssit_RightVisualization_581,             /*(48) */
Can_Ch0_Il_Rx_Sig_IPM_SLASpdlimitUnits_581,                         /*(49) */
Can_Ch0_Il_Rx_Sig_IPM_SLAState_581,                                 /*(50) */
Can_Ch0_Il_Rx_Sig_IPM_LaneAssit_Status_581,                         /*(51) */
Can_Ch0_Il_Rx_Sig_IPM_SLASpdlimit_581,                              /*(52) */
Can_Ch0_Il_Rx_Sig_IPM_HMA_Status_581,                               /*(53) */
Can_Ch0_Il_Rx_Sig_IPM_DDD_IndexStatus_581,                          /*(54) */
Can_Ch0_Il_Rx_Sig_IPM_DDD_WarningLevel_581,                         /*(55) */
Can_Ch0_Il_Rx_Sig_IPM_LaneAssit_HandsonReq_581,                     /*(56) */
Can_Ch0_Il_Rx_Sig_vSetDis_582,                                      /*(57) */
Can_Ch0_Il_Rx_Sig_ObjValid_582,                                     /*(58) */
Can_Ch0_Il_Rx_Sig_TauGapSet_582,                                    /*(59) */
Can_Ch0_Il_Rx_Sig_dxTarObj_582,                                     /*(60) */
Can_Ch0_Il_Rx_Sig_ACCHMI_Mode_582,                                  /*(61) */
Can_Ch0_Il_Rx_Sig_ACCFailInfo_582,                                  /*(62) */
Can_Ch0_Il_Rx_Sig_TakeOverReq_582,                                  /*(63) */
Can_Ch0_Il_Rx_Sig_AEB_STATE_582,                                    /*(64) */
Can_Ch0_Il_Rx_Sig_ACC_Startstop_infor_582,                          /*(65) */
Can_Ch0_Il_Rx_Sig_PCW_preWarning_582,                               /*(66) */
Can_Ch0_Il_Rx_Sig_PCW_latentWarning_582,                            /*(67) */
Can_Ch0_Il_Rx_Sig_PCW_STATE_582,                                    /*(68) */
Can_Ch0_Il_Rx_Sig_Obj_Speed_582,                                    /*(69) */
Can_Ch0_Il_Rx_Sig_Rolling_counter_0x246_582,                        /*(70) */
Can_Ch0_Il_Rx_Sig_Textinfo_582,                                     /*(71) */
Can_Ch0_Il_Rx_Sig_Checksum_0x246_582,                               /*(72) */
Can_Ch0_Il_Rx_Sig_IPM_DCLC_manualfeedback_583,                      /*(73) */
Can_Ch0_Il_Rx_Sig_IPM_ELKSts_583,                                   /*(74) */
Can_Ch0_Il_Rx_Sig_IPM_DCLCSts_583,                                  /*(75) */
Can_Ch0_Il_Rx_Sig_EPS_S_WarningLampYellow_608,                      /*(76) */
Can_Ch0_Il_Rx_Sig_EPS_S_SafeLampRed_608,                            /*(77) */
Can_Ch0_Il_Rx_Sig_Rolling_counter_0x260_608,                        /*(78) */
Can_Ch0_Il_Rx_Sig_Checksum_0x260_608,                               /*(79) */
Can_Ch0_Il_Rx_Sig_PAM_ChimeCmdSoundStatus_625,                      /*(80) */
Can_Ch0_Il_Rx_Sig_PAM_RearSysTemWorkSts_625,                        /*(81) */
Can_Ch0_Il_Rx_Sig_PAM_FrontSysTemWorkSts_625,                       /*(82) */
Can_Ch0_Il_Rx_Sig_PAM_ChimeCmdSoundCadence_625,                     /*(83) */
Can_Ch0_Il_Rx_Sig_LAEB_BrkgReqVal_628,                              /*(84) */
Can_Ch0_Il_Rx_Sig_LAEB_BrkgReq_628,                                 /*(85) */
Can_Ch0_Il_Rx_Sig_LAEB_DistanceToCollision_628,                     /*(86) */
Can_Ch0_Il_Rx_Sig_LAEB_SpeakReq_628,                                /*(87) */
Can_Ch0_Il_Rx_Sig_LAEB_WorkSts_628,                                 /*(88) */
Can_Ch0_Il_Rx_Sig_Checksum_0x274_628,                               /*(89) */
Can_Ch0_Il_Rx_Sig_Rolling_counter_0x274_628,                        /*(90) */
Can_Ch0_Il_Rx_Sig_LAEB_LedReq_628,                                  /*(91) */
Can_Ch0_Il_Rx_Sig_SOD_LCA_warningReqRight_629,                      /*(92) */
Can_Ch0_Il_Rx_Sig_SOD_DOA_warningReqRightRear_629,                  /*(93) */
Can_Ch0_Il_Rx_Sig_SOD_DOA_warningReqRightFront_629,                 /*(94) */
Can_Ch0_Il_Rx_Sig_SOD_CTA_warningReqRight_629,                      /*(95) */
Can_Ch0_Il_Rx_Sig_SOD_BLIS_display_629,                             /*(96) */
Can_Ch0_Il_Rx_Sig_SOD_LCA_warningReqLeft_629,                       /*(97) */
Can_Ch0_Il_Rx_Sig_SOD_DOA_warningReqLeftRear_629,                   /*(98) */
Can_Ch0_Il_Rx_Sig_SOD_DOA_warningReqLeftFront_629,                  /*(99) */
Can_Ch0_Il_Rx_Sig_SOD_CTA_warningReqLeft_629,                       /*(100) */
Can_Ch0_Il_Rx_Sig_DOA_OFFTelltale_629,                              /*(101) */
Can_Ch0_Il_Rx_Sig_CTA_OFFTelltale_629,                              /*(102) */
Can_Ch0_Il_Rx_Sig_SODLCA_OFFTelltale_629,                           /*(103) */
Can_Ch0_Il_Rx_Sig_IPM_LedtLine_dx_start_632,                        /*(104) */
Can_Ch0_Il_Rx_Sig_IPM_LeftLine_dy_632,                              /*(105) */
Can_Ch0_Il_Rx_Sig_IPM_LeftLine_dx_lookhead_632,                     /*(106) */
Can_Ch0_Il_Rx_Sig_IPM_LeftLine_hor_curve_632,                       /*(107) */
Can_Ch0_Il_Rx_Sig_IPM_LeftLine_yawangle_632,                        /*(108) */
Can_Ch0_Il_Rx_Sig_MRR_F_Object_dx_633,                              /*(109) */
Can_Ch0_Il_Rx_Sig_MRR_F_Object_dy_633,                              /*(110) */
Can_Ch0_Il_Rx_Sig_MRR_F_Obj_0x_class_633,                           /*(111) */
Can_Ch0_Il_Rx_Sig_MRR_FF_Object_dx_633,                             /*(112) */
Can_Ch0_Il_Rx_Sig_MRR_FF_Object_dy_633,                             /*(113) */
Can_Ch0_Il_Rx_Sig_MRR_FF_Obj_0x_class_633,                          /*(114) */
Can_Ch0_Il_Rx_Sig_MRR_FFTargrtDetection_633,                        /*(115) */
Can_Ch0_Il_Rx_Sig_MRR_PedDetection_633,                             /*(116) */
Can_Ch0_Il_Rx_Sig_IPM_LaneAssit_LeftVisualization_640,              /*(117) */
Can_Ch0_Il_Rx_Sig_IPM_LeftLine_Type_640,                            /*(118) */
Can_Ch0_Il_Rx_Sig_IPM_LeftLine_Color_640,                           /*(119) */
Can_Ch0_Il_Rx_Sig_IPM_leftLeftLine_Type_640,                        /*(120) */
Can_Ch0_Il_Rx_Sig_IPM_leftLeftLine_Color_640,                       /*(121) */
Can_Ch0_Il_Rx_Sig_IPM_leftleftLine_dy_640,                          /*(122) */
Can_Ch0_Il_Rx_Sig_IPM_leftleftLine_hor_curve_640,                   /*(123) */
Can_Ch0_Il_Rx_Sig_IPM_leftleftLine_yawangle_640,                    /*(124) */
Can_Ch0_Il_Rx_Sig_IPM_leftleftLine_cur_alteration_640,              /*(125) */
Can_Ch0_Il_Rx_Sig_BCM_DoorStsRearRi_784,                            /*(126) */
Can_Ch0_Il_Rx_Sig_BCM_DoorStsRearLe_784,                            /*(127) */
Can_Ch0_Il_Rx_Sig_BCM_DoorStsFrntRi_784,                            /*(128) */
Can_Ch0_Il_Rx_Sig_BCM_DoorStsFrntLe_784,                            /*(129) */
Can_Ch0_Il_Rx_Sig_BCM_DoorLockStsRearRi_784,                        /*(130) */
Can_Ch0_Il_Rx_Sig_BCM_DoorLockStsRearLe_784,                        /*(131) */
Can_Ch0_Il_Rx_Sig_BCM_DoorLockStsFrntRi_784,                        /*(132) */
Can_Ch0_Il_Rx_Sig_BCM_DoorLockStsFrntLe_784,                        /*(133) */
Can_Ch0_Il_Rx_Sig_BCM_AntiTheftSts_784,                             /*(134) */
Can_Ch0_Il_Rx_Sig_BCM_LockUnlockFeedback_784,                       /*(135) */
Can_Ch0_Il_Rx_Sig_BCM_DoorLockStsTrunk_784,                         /*(136) */
Can_Ch0_Il_Rx_Sig_BCM_DoorStsTrunk_784,                             /*(137) */
Can_Ch0_Il_Rx_Sig_BCM_TrunkDoorPreUnlockSts_784,                    /*(138) */
Can_Ch0_Il_Rx_Sig_BCM_EnginehoodSts_784,                            /*(139) */
Can_Ch0_Il_Rx_Sig_BCM_Rolling_counter_0x310_784,                    /*(140) */
Can_Ch0_Il_Rx_Sig_BCM_TurnIndicatorSts_784,                         /*(141) */
Can_Ch0_Il_Rx_Sig_BCM_Checksum_0x310_784,                           /*(142) */
Can_Ch0_Il_Rx_Sig_BCM_OutsideTempDig_787,                           /*(143) */
Can_Ch0_Il_Rx_Sig_BCM_BrakeFluidSts_787,                            /*(144) */
Can_Ch0_Il_Rx_Sig_BCM_OutsideTemp_787,                              /*(145) */
Can_Ch0_Il_Rx_Sig_BCM_Reverse_gear_787,                             /*(146) */
Can_Ch0_Il_Rx_Sig_BCM_SS_EnableSts_787,                             /*(147) */
Can_Ch0_Il_Rx_Sig_BCM_Rollingcounter_0x313_787,                     /*(148) */
Can_Ch0_Il_Rx_Sig_BCM_Checksum_0x313_787,                           /*(149) */
Can_Ch0_Il_Rx_Sig_BCM_BGLLumLvlSettingStatus_789,                   /*(150) */
Can_Ch0_Il_Rx_Sig_BCM_FrntFogLmpSts_792,                            /*(151) */
Can_Ch0_Il_Rx_Sig_BCM_PosLmpSts_792,                                /*(152) */
Can_Ch0_Il_Rx_Sig_BCM_LowBeamSts_792,                               /*(153) */
Can_Ch0_Il_Rx_Sig_BCM_HighBeamSts_792,                              /*(154) */
Can_Ch0_Il_Rx_Sig_BCM_reversinglightSts_792,                        /*(155) */
Can_Ch0_Il_Rx_Sig_BCM_DayRunningLampSts_792,                        /*(156) */
Can_Ch0_Il_Rx_Sig_BCM_RearFogLmpSts_792,                            /*(157) */
Can_Ch0_Il_Rx_Sig_BCM_laserlightSts_792,                            /*(158) */
Can_Ch0_Il_Rx_Sig_BCM_AmbientLightSts_792,                          /*(159) */
Can_Ch0_Il_Rx_Sig_BCM_Highmountedstoplamp_792,                      /*(160) */
Can_Ch0_Il_Rx_Sig_BCM_BrakelightSts_792,                            /*(161) */
Can_Ch0_Il_Rx_Sig_BCM_BackHomeSts_792,                              /*(162) */
Can_Ch0_Il_Rx_Sig_BCM_AutolampSts_792,                              /*(163) */
Can_Ch0_Il_Rx_Sig_BCM_readinglampSts_792,                           /*(164) */
Can_Ch0_Il_Rx_Sig_BCM_DayRunningLampDig_792,                        /*(165) */
Can_Ch0_Il_Rx_Sig_BCM_BrakelightDig_792,                            /*(166) */
Can_Ch0_Il_Rx_Sig_BCM_reversinglightDig_792,                        /*(167) */
Can_Ch0_Il_Rx_Sig_BCM_TurnIndicatorDig_792,                         /*(168) */
Can_Ch0_Il_Rx_Sig_BCM_RearFogLmpDig_792,                            /*(169) */
Can_Ch0_Il_Rx_Sig_BCM_FrntFogLmpDig_792,                            /*(170) */
Can_Ch0_Il_Rx_Sig_BCM_PosLmpDig_792,                                /*(171) */
Can_Ch0_Il_Rx_Sig_BCM_LowBeamDig_792,                               /*(172) */
Can_Ch0_Il_Rx_Sig_BCM_Rollingcounter_0x318_792,                     /*(173) */
Can_Ch0_Il_Rx_Sig_BCM_Checksum_0x318_792,                           /*(174) */
Can_Ch0_Il_Rx_Sig_SWM_Menu_Right_794,                               /*(175) */
Can_Ch0_Il_Rx_Sig_SWM_Menu_Left_794,                                /*(176) */
Can_Ch0_Il_Rx_Sig_SWM_Menu_Down_794,                                /*(177) */
Can_Ch0_Il_Rx_Sig_SWM_Menu_Up_794,                                  /*(178) */
Can_Ch0_Il_Rx_Sig_Rolling_counter_0x31A_794,                        /*(179) */
Can_Ch0_Il_Rx_Sig_SWM_Menu_Return_794,                              /*(180) */
Can_Ch0_Il_Rx_Sig_SWM_Menu_Confirm_794,                             /*(181) */
Can_Ch0_Il_Rx_Sig_Checksum_0x31A_794,                               /*(182) */
Can_Ch0_Il_Rx_Sig_SWM_ACCtauGapSetPlus_795,                         /*(183) */
Can_Ch0_Il_Rx_Sig_SWM_ACCvSetMinus_795,                             /*(184) */
Can_Ch0_Il_Rx_Sig_SWM_ACCvSetPlus_795,                              /*(185) */
Can_Ch0_Il_Rx_Sig_SWM_ACCResume_795,                                /*(186) */
Can_Ch0_Il_Rx_Sig_SWM_ACCSet_795,                                   /*(187) */
Can_Ch0_Il_Rx_Sig_SWM_ACCEnableSwitch_795,                          /*(188) */
Can_Ch0_Il_Rx_Sig_SWM_LaneAssistSwitch_795,                         /*(189) */
Can_Ch0_Il_Rx_Sig_SWM_ACCtauGapSetMinus_795,                        /*(190) */
Can_Ch0_Il_Rx_Sig_PEPS_PowerMode_805,                               /*(191) */
Can_Ch0_Il_Rx_Sig_PEPS_IMMO_MatchStatus_805,                        /*(192) */
Can_Ch0_Il_Rx_Sig_PEPS_SystemFailStatus_805,                        /*(193) */
Can_Ch0_Il_Rx_Sig_PEPS_ESCL_FailStatus_805,                         /*(194) */
Can_Ch0_Il_Rx_Sig_PEPS_SSB_FailStatus_805,                          /*(195) */
Can_Ch0_Il_Rx_Sig_PEPS_BrakeIndicationWarning_805,                  /*(196) */
Can_Ch0_Il_Rx_Sig_PEPS_NotPNWarning_805,                            /*(197) */
Can_Ch0_Il_Rx_Sig_PEPS_DoorOpenNotOFFWarning_805,                   /*(198) */
Can_Ch0_Il_Rx_Sig_PEPS_DoorOpenWarning_805,                         /*(199) */
Can_Ch0_Il_Rx_Sig_PEPS_KeyBatteryWarning_805,                       /*(200) */
Can_Ch0_Il_Rx_Sig_PEPS_KeyOutWarning1_805,                          /*(201) */
Can_Ch0_Il_Rx_Sig_PEPS_NoKeyFoundWarning_805,                       /*(202) */
Can_Ch0_Il_Rx_Sig_PEPS_KeyReminderWarning_805,                      /*(203) */
Can_Ch0_Il_Rx_Sig_PEPS_RemainingNumSts_805,                         /*(204) */
Can_Ch0_Il_Rx_Sig_SRS_SBR_PAMsenger_848,                            /*(205) */
Can_Ch0_Il_Rx_Sig_SRS_SBR_Driver_848,                               /*(206) */
Can_Ch0_Il_Rx_Sig_SRS_AirBagFailSts_848,                            /*(207) */
Can_Ch0_Il_Rx_Sig_SRS_SBR_SecondRowRight_848,                       /*(208) */
Can_Ch0_Il_Rx_Sig_SRS_SBR_SecondRowMid_848,                         /*(209) */
Can_Ch0_Il_Rx_Sig_SRS_SBR_SecondRowLeft_848,                        /*(210) */
Can_Ch0_Il_Rx_Sig_Rolling_counter_0x350_848,                        /*(211) */
Can_Ch0_Il_Rx_Sig_Checksum_0x350_848,                               /*(212) */
Can_Ch0_Il_Rx_Sig_TPMS_LF_Pressure_865,                             /*(213) */
Can_Ch0_Il_Rx_Sig_TPMS_RF_Pressure_865,                             /*(214) */
Can_Ch0_Il_Rx_Sig_TPMS_RR_Pressure_865,                             /*(215) */
Can_Ch0_Il_Rx_Sig_TPMS_LR_Pressure_865,                             /*(216) */
Can_Ch0_Il_Rx_Sig_TPMS_Tire_Temperature_865,                        /*(217) */
Can_Ch0_Il_Rx_Sig_TPMS_LF_Pressure_Warning_865,                     /*(218) */
Can_Ch0_Il_Rx_Sig_TPMS_RF_Pressure_Warning_865,                     /*(219) */
Can_Ch0_Il_Rx_Sig_TPMS_System_Status_865,                           /*(220) */
Can_Ch0_Il_Rx_Sig_TPMS_RR_Pressure_Warning_865,                     /*(221) */
Can_Ch0_Il_Rx_Sig_TPMS_LR_Pressure_Warning_865,                     /*(222) */
Can_Ch0_Il_Rx_Sig_TPMS_Temperature_Warning_865,                     /*(223) */
Can_Ch0_Il_Rx_Sig_TPMS_resrved_865,                                 /*(224) */
Can_Ch0_Il_Rx_Sig_Tire_Position_865,                                /*(225) */
Can_Ch0_Il_Rx_Sig_TPMS_Lamp_Status_865,                             /*(226) */
Can_Ch0_Il_Rx_Sig_EMS_Fuelcounter_870,                              /*(227) */
Can_Ch0_Il_Rx_Sig_EMS_FuelconsumptionInst_870,                      /*(228) */
Can_Ch0_Il_Rx_Sig_EMS_MIL_870,                                      /*(229) */
Can_Ch0_Il_Rx_Sig_EMS_SVS_870,                                      /*(230) */
Can_Ch0_Il_Rx_Sig_EMS_StartStopStatus_870,                          /*(231) */
Can_Ch0_Il_Rx_Sig_EMS_GasPrtcWarn_G_Rq_872,                         /*(232) */
Can_Ch0_Il_Rx_Sig_MP5_AudioStatus_898,                              /*(233) */
Can_Ch0_Il_Rx_Sig_MP5_EnergyFlow_898,                               /*(234) */
Can_Ch0_Il_Rx_Sig_MP5_SetMultiButton_898,                           /*(235) */
Can_Ch0_Il_Rx_Sig_MP5_BSDSoundSwitchSts_898,                        /*(236) */
Can_Ch0_Il_Rx_Sig_MP5_NavStatus_898,                                /*(237) */
Can_Ch0_Il_Rx_Sig_MP5_NavICON_900,                                  /*(238) */
Can_Ch0_Il_Rx_Sig_MP5_ROUTE_REMAIN_DIS_900,                         /*(239) */
Can_Ch0_Il_Rx_Sig_MP5_ALModeSetting_900,                            /*(240) */
Can_Ch0_Il_Rx_Sig_MP5_ALStartAroundSetting_900,                     /*(241) */
Can_Ch0_Il_Rx_Sig_TCU_EmergencyTowingSts_917,                       /*(242) */
Can_Ch0_Il_Rx_Sig_TrnSrvcRqd_B_Rq_917,                              /*(243) */
Can_Ch0_Il_Rx_Sig_TCU_GearPFault_917,                               /*(244) */
Can_Ch0_Il_Rx_Sig_TCU_WarningMessage_917,                           /*(245) */
Can_Ch0_Il_Rx_Sig_TCU_DrvShiftAllwCondRmd_917,                      /*(246) */
Can_Ch0_Il_Rx_Sig_MRR_L_Object_dx_1152,                             /*(247) */
Can_Ch0_Il_Rx_Sig_MRR_L_Object_dy_1152,                             /*(248) */
Can_Ch0_Il_Rx_Sig_MRR_L_Obj_0x_class_1152,                          /*(249) */
Can_Ch0_Il_Rx_Sig_MRR_R_Object_dx_1152,                             /*(250) */
Can_Ch0_Il_Rx_Sig_MRR_R_Object_dy_1152,                             /*(251) */
Can_Ch0_Il_Rx_Sig_MRR_R_Obj_0x_class_1152,                          /*(252) */
Can_Ch0_Il_Rx_Sig_MRR_LeftTargrtDetection_1152,                     /*(253) */
Can_Ch0_Il_Rx_Sig_MRR_RightTargrtDetection_1152,                    /*(254) */
Can_Ch0_Il_Rx_Sig_IPM_RightLine_dx_start_1168,                      /*(255) */
Can_Ch0_Il_Rx_Sig_IPM_RightLine_dy_1168,                            /*(256) */
Can_Ch0_Il_Rx_Sig_IPM_RightLine_dx_lookhead_1168,                   /*(257) */
Can_Ch0_Il_Rx_Sig_IPM_RightLine_hor_curve_1168,                     /*(258) */
Can_Ch0_Il_Rx_Sig_IPM_RightLine_yawangle_1168,                      /*(259) */
Can_Ch0_Il_Rx_Sig_IPM_LaneAssit_RightVisualization_1169,            /*(260) */
Can_Ch0_Il_Rx_Sig_IPM_rightRighLine_Type_1169,                      /*(261) */
Can_Ch0_Il_Rx_Sig_IPM_RighLine_Color_1169,                          /*(262) */
Can_Ch0_Il_Rx_Sig_IPM_RighLine_Type_1169,                           /*(263) */
Can_Ch0_Il_Rx_Sig_IPM_RighrightLine_Color_1169,                     /*(264) */
Can_Ch0_Il_Rx_Sig_IPM_rightRightLine_dy_1169,                       /*(265) */
Can_Ch0_Il_Rx_Sig_IPM_rightRightLine_hor_curve_1169,                /*(266) */
Can_Ch0_Il_Rx_Sig_IPM_rightRightLine_yawangle_1169,                 /*(267) */
Can_Ch0_Il_Rx_Sig_IPM_RightLine_cur_alteration_1169,                /*(268) */
Can_Ch0_Il_Rx_Sig_AVM_displaytype_1312,                             /*(269) */
Can_Ch0_Il_Rx_Sig_AVM_Status_1312,                                  /*(270) */
Can_Ch0_Il_Rx_Sig_AVM_Guide_line_info_1312,                         /*(271) */
Can_Ch0_Il_Rx_Sig_AVM_Switch_1312,                                  /*(272) */
Can_Ch0_Il_Rx_Sig_MP5_ICMenuShift_Button_1328,                      /*(273) */
Can_Ch0_Il_Rx_Sig_MP5_ICMenuActive_Button_1328,                     /*(274) */
Can_Ch0_Il_Rx_Sig_MP5_AlarmStatus_1328,                             /*(275) */
Can_Ch0_Il_Rx_Sig_MP5_AlarmOrNot_1328,                              /*(276) */
Can_Ch0_Il_Rx_Sig_MP5_ICMenu_Cmd_1330,                              /*(277) */
Can_Ch0_Il_Rx_Sig_Nav_Sts_1331,                                     /*(278) */
Can_Ch0_Il_Rx_Sig_MP5_BGLLumLvlSetting_1333,                        /*(279) */
Can_Ch0_Il_Rx_Sig_WACM_WirelessChargerStatus_1335,                  /*(280) */
Can_Ch0_Il_Rx_Sig_TBOX_Year_1410,                                   /*(281) */
Can_Ch0_Il_Rx_Sig_TBOX_Month_1410,                                  /*(282) */
Can_Ch0_Il_Rx_Sig_TBOX_Date_1410,                                   /*(283) */
Can_Ch0_Il_Rx_Sig_TBOX_Hour_1410,                                   /*(284) */
Can_Ch0_Il_Rx_Sig_TBOX_Minute_1410,                                 /*(285) */
Can_Ch0_Il_Rx_Sig_TBOX_Second_1410,                                 /*(286) */
Can_Ch0_Il_Rx_Sig_TBOX_ReTime_1410,                                 /*(287) */
Can_Ch0_Il_Rx_Sig_BCM_LoadManageLevel_1412,                         /*(288) */
Can_Ch0_Il_Rx_Sig_BCM_CarModeIndicator_1412,                        /*(289) */
Can_Ch0_Il_Rx_Sig_BCM_CarMode_1412,                                 /*(290) */
Can_Ch0_Il_Rx_Sig_AFS_WorkSts_1440,                                 /*(291) */
Can_Ch0_Il_Rx_Sig_SCMM_HMIDisplay_1443,                             /*(292) */
Can_Ch0_Il_Rx_Sig_EMS_BackupOdometer_1590,                          /*(293) */
Can_Ch0_Il_Rx_Num_Signals              /*(294) */
}Can_Ch0_Il_Rx_Signals_Macro;


/* ===========================================================================
    Interaction Layer Receive Signal (Multiple Bytes) Rx Get Macros
   =========================================================================*/
/* ===========================================================================
   P U B L I C   M E M O R Y
  =========================================================================*/

extern CAN_IL_SIGNAL          const      Can_Ch0_Il_Tx_Signals[ Can_Ch0_Il_Tx_Num_Signals ];

extern CAN_IL_TX_MESSAGE      const      Can_Ch0_Il_Tx_Messages[ Can_Ch0_Il_Tx_Num_Messages ];

extern CAN_IL_TX_FRAME        const      Can_Ch0_Il_Tx_Frame_Table[ Can_Ch0_Il_Tx_Num_Messages ];

extern CAN_IL_SIGNAL          const      Can_Ch0_Il_Rx_Signals[Can_Ch0_Il_Rx_Num_Signals  ];

/*extern CAN_IL_RX_MESSAGE      const      Can_Ch0_Il_Rx_Messages[ ];*/

extern CAN_IL_RX_FRAME        const      Can_Ch0_Il_Rx_Frame_Table[ Can_Ch0_Il_Rx_Num_Messages ];

/*extern Can_Il_Rx_Data_Pointer const      Can_Ch0_Il_Receive_Data_Table[ ];*/

extern pTxPrecopyfn           const      Can_Ch0_Il_Tx_Precopy_Function_Table[ Can_Ch0_Il_Tx_Num_Messages ];

extern CAN_UINT8 Can_Ch0_Il_Rx_Frame_Data[ Can_Ch0_Il_Rx_Num_Messages ][ CAN_MAX_DATA_LENGTH ];

extern CAN_UINT8 Can_Ch0_Il_Rx_Frame_Status[ Can_Ch0_Il_Rx_Num_Messages ];

extern CAN_UINT16 Can_Ch0_Il_Rx_Timeout_Count[ Can_Ch0_Il_Rx_Num_Messages ];

extern Can_Il_Rx_Data_Pointer Can_Ch0_Il_Receive_Ptr[ Can_Ch0_Il_Rx_Num_Messages ][ CAN_MAX_DATA_LENGTH ];

#ifdef CAN_IL_TX_BURST_MODE

 #if ( Can_Ch0_Il_Tx_Num_Burst_Periodic > 0 )

  extern CAN_UINT8 Can_Ch0_Il_Tx_Burst_Count[ Can_Ch0_Il_Tx_Num_Burst_Periodic ];

 #endif

#endif

extern void Can_Ch0_Il_Precopy_Function(void);


#endif  /* CAN_IL_PAR_H */ 
/*****************************************************************************
    R E V I S I O N     N O T E S
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  -
For each change to this file, be sure to record:
1.   Who made the change and when the change was made.
2.   Why the change was made and the intended result.

Date       By         Reason For Change
------------------------------------------------------------------------------

******************************************************************************/
/*****************************************************************************
Date          : 2021-01-14 17:49:28
By              : ChengJia
Traceability    : JMC_SUV_Body_CAN_Matrix_20210104.dbc
Change Description  : Tool Generated code
*****************************************************************************/
