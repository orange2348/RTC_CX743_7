/* ===========================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
**  This is an unpublished work of authorship, which contains trade secrets,
**  created in 2007.  Visteon Corporation owns all rights to this work and
**  intends to maintain it in confidence to preserve its trade secret status.
**  Visteon Corporation reserves the right, under the copyright laws of the
**  United States or those of any other country that may have jurisdiction, to
**  protect this work as an unpublished work, in the event of an inadvertent
**  or deliberate unauthorized publication.  Visteon Corporation also reserves
**  its rights under all copyright laws to protect this work as a published
**  work, when appropriate.  Those having access to this work may not copy it,
**  use it, modify it or disclose the information contained in it without the
**  written authorization of Visteon Corporation.
**
** =========================================================================*/

/* ===========================================================================
**
**  Name:           CanCcl_Par_Cfg.c
**
**  Description:    CAN CCL configuration parameter Configuration file for
**                  configured database file
**
**  Organization:   Vehicle Communications
**                  Visteon Corporation
**
** =========================================================================*/

/* ===========================================================================
**  I N C L U D E   F I L E S
** =========================================================================*/

# include "Rte_Cbk.h"
# include "CanCcl_Par_Cfg.h"

/* ===========================================================================
** G L O B A L   C O N S T A N T   D E F I N I T I O N S
** =========================================================================*/

/*******************************************************/
/* DBC Tx & Rx CFG */
/*******************************************************/

/**********************************************************************************************************************
        Can_Ccl_TxSigInfo 
	      **********************************************************************************************************************/
CONST(Ccl_TxSigInfoType, CCL_CONST) Can_Ccl_TxSigInfo[Can_Ccl_Tx_Signal_Num_Signals] = {
	/* Index		CntrId	  InitValue 	SendType   */
	 { /*	  0 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_BSDSoundSts		*/
	 { /*	  1 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_Fuel_level		*/
	 { /*	  2 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_DriveTimehour		*/
	 { /*	  3 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_DriveTimeMinute		*/
	 { /*	  4 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_AverageSpeed		*/
	 { /*	  5 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_ChangOilDistance		*/
	 { /*	  6 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* BackUpODO		*/
	 { /*	  7 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_ABSLamp		*/
	 { /*	  8 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_EBDFaultLamp		*/
	 { /*	  9 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_BrakefluidLowLamp		*/
	 { /*	  10 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_APBFaultLamp		*/
	 { /*	  11 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_APBLamp		*/
	 { /*	  12 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_AVHLamp		*/
	 { /*	  13 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_BatteryLamp		*/
	 { /*	  14 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_CoolantHighLamp		*/
	 { /*	  15 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_FuelLowLamp		*/
	 { /*	  16 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_OilpressureLowLamp		*/
	 { /*	  17 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_EngineMaintainLamp		*/
	 { /*	  18 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_EngineFaultLamp		*/
	 { /*	  19 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_ESPLamp		*/
	 { /*	  20 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_AntitheftLamp		*/
	 { /*	  21 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_ACCFaultLamp		*/
	 { /*	  22 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_ACCLamp		*/
	 { /*	  23 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_SRSLamp		*/
	 { /*	  24 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_TPMSLamp		*/
	 { /*	  25 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_TCUServiceLamp		*/
	 { /*	  26 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_EPSFaultLamp		*/
	 { /*	  27 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_EPSLamp		*/
	 { /*	  28 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_SSSystemFaultLamp		*/
	 { /*	  29 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_ESCLLamp		*/
	 { /*	  30 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_PEPSLamp		*/
	 { /*	  31 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_InsulationLamp		*/
	 { /*	  32 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_VehFailGradeWarning		*/
	 { /*	  33 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_EVSystemLamp		*/
	 { /*	  34 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_ThermalRunaywaWarning		*/
	 { /*	  35 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_SOClowWarning		*/
	 { /*	  36 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_HandbrakeLamp		*/
	 { /*	  37 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_48VSystemFaultLamp		*/
	 { /*	  38 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_MotorTemHighLamp		*/
	 { /*	  39 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_MotorRestLamp		*/
	 { /*	  40 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_DCDCLamp		*/
	 { /*	  41 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_MotorLamp		*/
	 { /*	  42 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_PackSystemLamp		*/
	 { /*	  43 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_OdometerMasterValue		*/
	 { /*	  44 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_AirbagTelltaleBehavior		*/
	 { /*	  45 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_VehBrkPump_ERR_IC		*/
	 { /*	  46 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_DISFail		*/
	 { /*	  47 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_QDashACCFail		*/
	 { /*	  48 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_VehSpd_HMI		*/
	 { /*	  49 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* BackupCountODO		*/
	 { /*	  50 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_Rolling_counter_0x510		*/
	 { /*	  51 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_Checksum_0x510		*/
	 { /*	  52 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_TemperatureUnitsSetting		*/
	 { /*	  53 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_MileageUnitsSetting		*/
	 { /*	  54 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_LanguageSetting		*/
	 { /*	  55 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_AFCUnitsSetting		*/
	 { /*	  56 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_PressureUnitsSetting		*/
	 { /*	  57 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_AFC		*/
	 { /*	  58 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_DTE		*/
	 { /*	  59 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_AlarmStatus		*/
	 { /*	  60 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_AlarmOrNot		*/
	 { /*	  61 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_AFC_Type		*/
	 { /*	  62 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_Fuel_Level_Volumn		*/
	 { /*	  63 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_Fuel_Level_VolumnQF		*/
	 { /*	  64 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_Rolling_counter_0x525		*/
	 { /*	  65 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_Checksum_0x525		*/
	 { /*	  66 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_Year		*/
	 { /*	  67 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_Month		*/
	 { /*	  68 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_Date		*/
	 { /*	  69 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_Hour		*/
	 { /*	  70 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_Minute		*/
	 { /*	  71 */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* IC_Second		*/
};



/**********************************************************************************************************************
        Can_Ccl_NumOfContainedTxSignals
        **********************************************************************************************************************/
CONST(Ccl_MessageContentInfo, CCL_CONST) Can_Ccl_NumOfContainedTxSignals[Can_Ccl_Tx_Num_Messages] =
{
/* Index      SigStartIndex   SigCount   */
{ /*  0  */          0 ,          1   },/*IC_0x386*/
{ /*  1  */          0 ,          6   },/*IC_0x387*/
{ /*  2  */          0 ,          36   },/*IC_0x38A*/
{ /*  3  */          0 ,          9   },/*IC_0x510*/
{ /*  4  */          0 ,          5   },/*IC_0x511*/
{ /*  5  */          0 ,          9   },/*IC_0x525*/
{ /*  6  */          0 ,          6   },/*IC_time_0x581*/
};

/**********************************************************************************************************************
    Can_Ccl_RxAccessInfo
  **********************************************************************************************************************/
CONST(Ccl_RxAccessInfoType, CCL_CONST) Can_Ccl_RxAccessInfo[Can_Ccl_Rx_Num_Signals] = {
	   /* Index 	 ControllerId */
{ /* 	0  */		   0	   },		/*SCU_faultwarning                        	*/
{ /* 	1  */		   0	   },		/*EMS_EngCoolanTemp                       	*/
{ /* 	2  */		   0	   },		/*EMS_EngOperationStatus                  	*/
{ /* 	3  */		   0	   },		/*EMS_BatteryVoltageError                 	*/
{ /* 	4  */		   0	   },		/*EMS_EngSpeed                            	*/
{ /* 	5  */		   0	   },		/*EMS_StartStopMessage                    	*/
{ /* 	6  */		   0	   },		/*TCU_DisplayGear                         	*/
{ /* 	7  */		   0	   },		/*TCU_GearSelectorReq                     	*/
{ /* 	8  */		   0	   },		/*TCU_StGearMode                          	*/
{ /* 	9  */		   0	   },		/*TCU_Status_AliveCounter0x123            	*/
{ /* 	10  */		   0	   },		/*TCU_Status_Checksum0x123                	*/
{ /* 	11  */		   0	   },		/*EMS_TargCruiseSpeed                     	*/
{ /* 	12  */		   0	   },		/*EMS_CruiseControlStatus                 	*/
{ /* 	13  */		   0	   },		/*TBOX_ECALLFlt                           	*/
{ /* 	14  */		   0	   },		/*PEPS_Remotestartstatus                  	*/
{ /* 	15  */		   0	   },		/*ABS_WhlMilgFrntLe                       	*/
{ /* 	16  */		   0	   },		/*ABS_WhlMilgFrntRi                       	*/
{ /* 	17  */		   0	   },		/*ABS_VehSpdLgt                           	*/
{ /* 	18  */		   0	   },		/*ABS_EbdFlgFlt                           	*/
{ /* 	19  */		   0	   },		/*ABS_AbsFlgFlt                           	*/
{ /* 	20  */		   0	   },		/*ABS_RollingCounter_0x221                	*/
{ /* 	21  */		   0	   },		/*ABS_WhlMilgFrntLeStatus                 	*/
{ /* 	22  */		   0	   },		/*ABS_WhlMilgFrntRiStatus                 	*/
{ /* 	23  */		   0	   },		/*ABS_Checksum_0x221                      	*/
{ /* 	24  */		   0	   },		/*ESP_HHCAvailable                        	*/
{ /* 	25  */		   0	   },		/*ABS_HAZActive                           	*/
{ /* 	26  */		   0	   },		/*ESP_EPBStatus                           	*/
{ /* 	27  */		   0	   },		/*ESP_EPBErrorStatus                      	*/
{ /* 	28  */		   0	   },		/*ESP_HDCAvailable                        	*/
{ /* 	29  */		   0	   },		/*ESP_HDCActive                           	*/
{ /* 	30  */		   0	   },		/*ESP_CdpAvailable                        	*/
{ /* 	31  */		   0	   },		/*ESP_EPBWarningMessage3                  	*/
{ /* 	32  */		   0	   },		/*ESP_EPBWarningMessage2                  	*/
{ /* 	33  */		   0	   },		/*ESP_EPBWarningMessage1                  	*/
{ /* 	34  */		   0	   },		/*ESP_AVHWarningMessage                   	*/
{ /* 	35  */		   0	   },		/*ESP_AvhActive                           	*/
{ /* 	36  */		   0	   },		/*ESP_AvhStandby                          	*/
{ /* 	37  */		   0	   },		/*ESP_AvhAvabliable                       	*/
{ /* 	38  */		   0	   },		/*ESP_VdcFlgFlt                           	*/
{ /* 	39  */		   0	   },		/*ESP_TcsFlgFlt                           	*/
{ /* 	40  */		   0	   },		/*ESP_ESPInfoLamp                         	*/
{ /* 	41  */		   0	   },		/*ESP_EspEnableSts                        	*/
{ /* 	42  */		   0	   },		/*ESP_RollingCounter_0x243                	*/
{ /* 	43  */		   0	   },		/*ESP_Checksum_0x243                      	*/
{ /* 	44  */		   0	   },		/*IPM_LaneAssitType                       	*/
{ /* 	45  */		   0	   },		/*IPM_LaneAssit_WarningVibration          	*/
{ /* 	46  */		   0	   },		/*IPM_LaneAssit_WarningAudio              	*/
{ /* 	47  */		   0	   },		/*IPM_LaneAssit_LeftVisualization         	*/
{ /* 	48  */		   0	   },		/*IPM_LaneAssit_RightVisualization        	*/
{ /* 	49  */		   0	   },		/*IPM_SLASpdlimitUnits                    	*/
{ /* 	50  */		   0	   },		/*IPM_SLAState                            	*/
{ /* 	51  */		   0	   },		/*IPM_LaneAssit_Status                    	*/
{ /* 	52  */		   0	   },		/*IPM_SLASpdlimit                         	*/
{ /* 	53  */		   0	   },		/*IPM_HMA_Status                          	*/
{ /* 	54  */		   0	   },		/*IPM_DDD_IndexStatus                     	*/
{ /* 	55  */		   0	   },		/*IPM_DDD_WarningLevel                    	*/
{ /* 	56  */		   0	   },		/*IPM_LaneAssit_HandsonReq                	*/
{ /* 	57  */		   0	   },		/*vSetDis                                 	*/
{ /* 	58  */		   0	   },		/*ObjValid                                	*/
{ /* 	59  */		   0	   },		/*TauGapSet                               	*/
{ /* 	60  */		   0	   },		/*dxTarObj                                	*/
{ /* 	61  */		   0	   },		/*ACCHMI_Mode                             	*/
{ /* 	62  */		   0	   },		/*ACCFailInfo                             	*/
{ /* 	63  */		   0	   },		/*TakeOverReq                             	*/
{ /* 	64  */		   0	   },		/*AEB_STATE                               	*/
{ /* 	65  */		   0	   },		/*ACC_Startstop_infor                     	*/
{ /* 	66  */		   0	   },		/*PCW_preWarning                          	*/
{ /* 	67  */		   0	   },		/*PCW_latentWarning                       	*/
{ /* 	68  */		   0	   },		/*PCW_STATE                               	*/
{ /* 	69  */		   0	   },		/*Obj_Speed                               	*/
{ /* 	70  */		   0	   },		/*Rolling_counter_0x246                   	*/
{ /* 	71  */		   0	   },		/*Textinfo                                	*/
{ /* 	72  */		   0	   },		/*Checksum_0x246                          	*/
{ /* 	73  */		   0	   },		/*IPM_DCLC_manualfeedback                 	*/
{ /* 	74  */		   0	   },		/*IPM_ELKSts                              	*/
{ /* 	75  */		   0	   },		/*IPM_DCLCSts                             	*/
{ /* 	76  */		   0	   },		/*EPS_S_WarningLampYellow                 	*/
{ /* 	77  */		   0	   },		/*EPS_S_SafeLampRed                       	*/
{ /* 	78  */		   0	   },		/*Rolling_counter_0x260                   	*/
{ /* 	79  */		   0	   },		/*Checksum_0x260                          	*/
{ /* 	80  */		   0	   },		/*PAM_ChimeCmdSoundStatus                 	*/
{ /* 	81  */		   0	   },		/*PAM_RearSysTemWorkSts                   	*/
{ /* 	82  */		   0	   },		/*PAM_FrontSysTemWorkSts                  	*/
{ /* 	83  */		   0	   },		/*PAM_ChimeCmdSoundCadence                	*/
{ /* 	84  */		   0	   },		/*LAEB_BrkgReqVal                         	*/
{ /* 	85  */		   0	   },		/*LAEB_BrkgReq                            	*/
{ /* 	86  */		   0	   },		/*LAEB_DistanceToCollision                	*/
{ /* 	87  */		   0	   },		/*LAEB_SpeakReq                           	*/
{ /* 	88  */		   0	   },		/*LAEB_WorkSts                            	*/
{ /* 	89  */		   0	   },		/*Checksum_0x274                          	*/
{ /* 	90  */		   0	   },		/*Rolling_counter_0x274                   	*/
{ /* 	91  */		   0	   },		/*LAEB_LedReq                             	*/
{ /* 	92  */		   0	   },		/*SOD_LCA_warningReqRight                 	*/
{ /* 	93  */		   0	   },		/*SOD_DOA_warningReqRightRear             	*/
{ /* 	94  */		   0	   },		/*SOD_DOA_warningReqRightFront            	*/
{ /* 	95  */		   0	   },		/*SOD_CTA_warningReqRight                 	*/
{ /* 	96  */		   0	   },		/*SOD_BLIS_display                        	*/
{ /* 	97  */		   0	   },		/*SOD_LCA_warningReqLeft                  	*/
{ /* 	98  */		   0	   },		/*SOD_DOA_warningReqLeftRear              	*/
{ /* 	99  */		   0	   },		/*SOD_DOA_warningReqLeftFront             	*/
{ /* 	100  */		   0	   },		/*SOD_CTA_warningReqLeft                  	*/
{ /* 	101  */		   0	   },		/*DOA_OFFTelltale                         	*/
{ /* 	102  */		   0	   },		/*CTA_OFFTelltale                         	*/
{ /* 	103  */		   0	   },		/*SODLCA_OFFTelltale                      	*/
{ /* 	104  */		   0	   },		/*IPM_LedtLine_dx_start                   	*/
{ /* 	105  */		   0	   },		/*IPM_LeftLine_dy                         	*/
{ /* 	106  */		   0	   },		/*IPM_LeftLine_dx_lookhead                	*/
{ /* 	107  */		   0	   },		/*IPM_LeftLine_hor_curve                  	*/
{ /* 	108  */		   0	   },		/*IPM_LeftLine_yawangle                   	*/
{ /* 	109  */		   0	   },		/*MRR_F_Object_dx                         	*/
{ /* 	110  */		   0	   },		/*MRR_F_Object_dy                         	*/
{ /* 	111  */		   0	   },		/*MRR_F_Obj_0x_class                      	*/
{ /* 	112  */		   0	   },		/*MRR_FF_Object_dx                        	*/
{ /* 	113  */		   0	   },		/*MRR_FF_Object_dy                        	*/
{ /* 	114  */		   0	   },		/*MRR_FF_Obj_0x_class                     	*/
{ /* 	115  */		   0	   },		/*MRR_FFTargrtDetection                   	*/
{ /* 	116  */		   0	   },		/*MRR_PedDetection                        	*/
{ /* 	117  */		   0	   },		/*IPM_LaneAssit_LeftVisualization         	*/
{ /* 	118  */		   0	   },		/*IPM_LeftLine_Type                       	*/
{ /* 	119  */		   0	   },		/*IPM_LeftLine_Color                      	*/
{ /* 	120  */		   0	   },		/*IPM_leftLeftLine_Type                   	*/
{ /* 	121  */		   0	   },		/*IPM_leftLeftLine_Color                  	*/
{ /* 	122  */		   0	   },		/*IPM_leftleftLine_dy                     	*/
{ /* 	123  */		   0	   },		/*IPM_leftleftLine_hor_curve              	*/
{ /* 	124  */		   0	   },		/*IPM_leftleftLine_yawangle               	*/
{ /* 	125  */		   0	   },		/*IPM_leftleftLine_cur_alteration         	*/
{ /* 	126  */		   0	   },		/*BCM_DoorStsRearRi                       	*/
{ /* 	127  */		   0	   },		/*BCM_DoorStsRearLe                       	*/
{ /* 	128  */		   0	   },		/*BCM_DoorStsFrntRi                       	*/
{ /* 	129  */		   0	   },		/*BCM_DoorStsFrntLe                       	*/
{ /* 	130  */		   0	   },		/*BCM_DoorLockStsRearRi                   	*/
{ /* 	131  */		   0	   },		/*BCM_DoorLockStsRearLe                   	*/
{ /* 	132  */		   0	   },		/*BCM_DoorLockStsFrntRi                   	*/
{ /* 	133  */		   0	   },		/*BCM_DoorLockStsFrntLe                   	*/
{ /* 	134  */		   0	   },		/*BCM_AntiTheftSts                        	*/
{ /* 	135  */		   0	   },		/*BCM_LockUnlockFeedback                  	*/
{ /* 	136  */		   0	   },		/*BCM_DoorLockStsTrunk                    	*/
{ /* 	137  */		   0	   },		/*BCM_DoorStsTrunk                        	*/
{ /* 	138  */		   0	   },		/*BCM_TrunkDoorPreUnlockSts               	*/
{ /* 	139  */		   0	   },		/*BCM_EnginehoodSts                       	*/
{ /* 	140  */		   0	   },		/*BCM_Rolling_counter_0x310               	*/
{ /* 	141  */		   0	   },		/*BCM_TurnIndicatorSts                    	*/
{ /* 	142  */		   0	   },		/*BCM_Checksum_0x310                      	*/
{ /* 	143  */		   0	   },		/*BCM_OutsideTempDig                      	*/
{ /* 	144  */		   0	   },		/*BCM_BrakeFluidSts                       	*/
{ /* 	145  */		   0	   },		/*BCM_OutsideTemp                         	*/
{ /* 	146  */		   0	   },		/*BCM_Reverse_gear                        	*/
{ /* 	147  */		   0	   },		/*BCM_SS_EnableSts                        	*/
{ /* 	148  */		   0	   },		/*BCM_Rollingcounter_0x313                	*/
{ /* 	149  */		   0	   },		/*BCM_Checksum_0x313                      	*/
{ /* 	150  */		   0	   },		/*BCM_BGLLumLvlSettingStatus              	*/
{ /* 	151  */		   0	   },		/*BCM_FrntFogLmpSts                       	*/
{ /* 	152  */		   0	   },		/*BCM_PosLmpSts                           	*/
{ /* 	153  */		   0	   },		/*BCM_LowBeamSts                          	*/
{ /* 	154  */		   0	   },		/*BCM_HighBeamSts                         	*/
{ /* 	155  */		   0	   },		/*BCM_reversinglightSts                   	*/
{ /* 	156  */		   0	   },		/*BCM_DayRunningLampSts                   	*/
{ /* 	157  */		   0	   },		/*BCM_RearFogLmpSts                       	*/
{ /* 	158  */		   0	   },		/*BCM_laserlightSts                       	*/
{ /* 	159  */		   0	   },		/*BCM_AmbientLightSts                     	*/
{ /* 	160  */		   0	   },		/*BCM_Highmountedstoplamp                 	*/
{ /* 	161  */		   0	   },		/*BCM_BrakelightSts                       	*/
{ /* 	162  */		   0	   },		/*BCM_BackHomeSts                         	*/
{ /* 	163  */		   0	   },		/*BCM_AutolampSts                         	*/
{ /* 	164  */		   0	   },		/*BCM_readinglampSts                      	*/
{ /* 	165  */		   0	   },		/*BCM_DayRunningLampDig                   	*/
{ /* 	166  */		   0	   },		/*BCM_BrakelightDig                       	*/
{ /* 	167  */		   0	   },		/*BCM_reversinglightDig                   	*/
{ /* 	168  */		   0	   },		/*BCM_TurnIndicatorDig                    	*/
{ /* 	169  */		   0	   },		/*BCM_RearFogLmpDig                       	*/
{ /* 	170  */		   0	   },		/*BCM_FrntFogLmpDig                       	*/
{ /* 	171  */		   0	   },		/*BCM_PosLmpDig                           	*/
{ /* 	172  */		   0	   },		/*BCM_LowBeamDig                          	*/
{ /* 	173  */		   0	   },		/*BCM_Rollingcounter_0x318                	*/
{ /* 	174  */		   0	   },		/*BCM_Checksum_0x318                      	*/
{ /* 	175  */		   0	   },		/*SWM_Menu_Right                          	*/
{ /* 	176  */		   0	   },		/*SWM_Menu_Left                           	*/
{ /* 	177  */		   0	   },		/*SWM_Menu_Down                           	*/
{ /* 	178  */		   0	   },		/*SWM_Menu_Up                             	*/
{ /* 	179  */		   0	   },		/*Rolling_counter_0x31A                   	*/
{ /* 	180  */		   0	   },		/*SWM_Menu_Return                         	*/
{ /* 	181  */		   0	   },		/*SWM_Menu_Confirm                        	*/
{ /* 	182  */		   0	   },		/*Checksum_0x31A                          	*/
{ /* 	183  */		   0	   },		/*SWM_ACCtauGapSetPlus                    	*/
{ /* 	184  */		   0	   },		/*SWM_ACCvSetMinus                        	*/
{ /* 	185  */		   0	   },		/*SWM_ACCvSetPlus                         	*/
{ /* 	186  */		   0	   },		/*SWM_ACCResume                           	*/
{ /* 	187  */		   0	   },		/*SWM_ACCSet                              	*/
{ /* 	188  */		   0	   },		/*SWM_ACCEnableSwitch                     	*/
{ /* 	189  */		   0	   },		/*SWM_LaneAssistSwitch                    	*/
{ /* 	190  */		   0	   },		/*SWM_ACCtauGapSetMinus                   	*/
{ /* 	191  */		   0	   },		/*PEPS_PowerMode                          	*/
{ /* 	192  */		   0	   },		/*PEPS_IMMO_MatchStatus                   	*/
{ /* 	193  */		   0	   },		/*PEPS_SystemFailStatus                   	*/
{ /* 	194  */		   0	   },		/*PEPS_ESCL_FailStatus                    	*/
{ /* 	195  */		   0	   },		/*PEPS_SSB_FailStatus                     	*/
{ /* 	196  */		   0	   },		/*PEPS_BrakeIndicationWarning             	*/
{ /* 	197  */		   0	   },		/*PEPS_NotPNWarning                       	*/
{ /* 	198  */		   0	   },		/*PEPS_DoorOpenNotOFFWarning              	*/
{ /* 	199  */		   0	   },		/*PEPS_DoorOpenWarning                    	*/
{ /* 	200  */		   0	   },		/*PEPS_KeyBatteryWarning                  	*/
{ /* 	201  */		   0	   },		/*PEPS_KeyOutWarning1                     	*/
{ /* 	202  */		   0	   },		/*PEPS_NoKeyFoundWarning                  	*/
{ /* 	203  */		   0	   },		/*PEPS_KeyReminderWarning                 	*/
{ /* 	204  */		   0	   },		/*PEPS_RemainingNumSts                    	*/
{ /* 	205  */		   0	   },		/*SRS_SBR_PAMsenger                       	*/
{ /* 	206  */		   0	   },		/*SRS_SBR_Driver                          	*/
{ /* 	207  */		   0	   },		/*SRS_AirBagFailSts                       	*/
{ /* 	208  */		   0	   },		/*SRS_SBR_SecondRowRight                  	*/
{ /* 	209  */		   0	   },		/*SRS_SBR_SecondRowMid                    	*/
{ /* 	210  */		   0	   },		/*SRS_SBR_SecondRowLeft                   	*/
{ /* 	211  */		   0	   },		/*Rolling_counter_0x350                   	*/
{ /* 	212  */		   0	   },		/*Checksum_0x350                          	*/
{ /* 	213  */		   0	   },		/*TPMS_LF_Pressure                        	*/
{ /* 	214  */		   0	   },		/*TPMS_RF_Pressure                        	*/
{ /* 	215  */		   0	   },		/*TPMS_RR_Pressure                        	*/
{ /* 	216  */		   0	   },		/*TPMS_LR_Pressure                        	*/
{ /* 	217  */		   0	   },		/*TPMS_Tire_Temperature                   	*/
{ /* 	218  */		   0	   },		/*TPMS_LF_Pressure_Warning                	*/
{ /* 	219  */		   0	   },		/*TPMS_RF_Pressure_Warning                	*/
{ /* 	220  */		   0	   },		/*TPMS_System_Status                      	*/
{ /* 	221  */		   0	   },		/*TPMS_RR_Pressure_Warning                	*/
{ /* 	222  */		   0	   },		/*TPMS_LR_Pressure_Warning                	*/
{ /* 	223  */		   0	   },		/*TPMS_Temperature_Warning                	*/
{ /* 	224  */		   0	   },		/*TPMS_resrved                            	*/
{ /* 	225  */		   0	   },		/*Tire_Position                           	*/
{ /* 	226  */		   0	   },		/*TPMS_Lamp_Status                        	*/
{ /* 	227  */		   0	   },		/*EMS_Fuelcounter                         	*/
{ /* 	228  */		   0	   },		/*EMS_FuelconsumptionInst                 	*/
{ /* 	229  */		   0	   },		/*EMS_MIL                                 	*/
{ /* 	230  */		   0	   },		/*EMS_SVS                                 	*/
{ /* 	231  */		   0	   },		/*EMS_StartStopStatus                     	*/
{ /* 	232  */		   0	   },		/*EMS_GasPrtcWarn_G_Rq                    	*/
{ /* 	233  */		   0	   },		/*MP5_AudioStatus                         	*/
{ /* 	234  */		   0	   },		/*MP5_EnergyFlow                          	*/
{ /* 	235  */		   0	   },		/*MP5_SetMultiButton                      	*/
{ /* 	236  */		   0	   },		/*MP5_BSDSoundSwitchSts                   	*/
{ /* 	237  */		   0	   },		/*MP5_NavStatus                           	*/
{ /* 	238  */		   0	   },		/*MP5_NavICON                             	*/
{ /* 	239  */		   0	   },		/*MP5_ROUTE_REMAIN_DIS                    	*/
{ /* 	240  */		   0	   },		/*MP5_ALModeSetting                       	*/
{ /* 	241  */		   0	   },		/*MP5_ALStartAroundSetting                	*/
{ /* 	242  */		   0	   },		/*TCU_EmergencyTowingSts                  	*/
{ /* 	243  */		   0	   },		/*TrnSrvcRqd_B_Rq                         	*/
{ /* 	244  */		   0	   },		/*TCU_GearPFault                          	*/
{ /* 	245  */		   0	   },		/*TCU_WarningMessage                      	*/
{ /* 	246  */		   0	   },		/*TCU_DrvShiftAllwCondRmd                 	*/
{ /* 	247  */		   0	   },		/*MRR_L_Object_dx                         	*/
{ /* 	248  */		   0	   },		/*MRR_L_Object_dy                         	*/
{ /* 	249  */		   0	   },		/*MRR_L_Obj_0x_class                      	*/
{ /* 	250  */		   0	   },		/*MRR_R_Object_dx                         	*/
{ /* 	251  */		   0	   },		/*MRR_R_Object_dy                         	*/
{ /* 	252  */		   0	   },		/*MRR_R_Obj_0x_class                      	*/
{ /* 	253  */		   0	   },		/*MRR_LeftTargrtDetection                 	*/
{ /* 	254  */		   0	   },		/*MRR_RightTargrtDetection                	*/
{ /* 	255  */		   0	   },		/*IPM_RightLine_dx_start                  	*/
{ /* 	256  */		   0	   },		/*IPM_RightLine_dy                        	*/
{ /* 	257  */		   0	   },		/*IPM_RightLine_dx_lookhead               	*/
{ /* 	258  */		   0	   },		/*IPM_RightLine_hor_curve                 	*/
{ /* 	259  */		   0	   },		/*IPM_RightLine_yawangle                  	*/
{ /* 	260  */		   0	   },		/*IPM_LaneAssit_RightVisualization        	*/
{ /* 	261  */		   0	   },		/*IPM_rightRighLine_Type                  	*/
{ /* 	262  */		   0	   },		/*IPM_RighLine_Color                      	*/
{ /* 	263  */		   0	   },		/*IPM_RighLine_Type                       	*/
{ /* 	264  */		   0	   },		/*IPM_RighrightLine_Color                 	*/
{ /* 	265  */		   0	   },		/*IPM_rightRightLine_dy                   	*/
{ /* 	266  */		   0	   },		/*IPM_rightRightLine_hor_curve            	*/
{ /* 	267  */		   0	   },		/*IPM_rightRightLine_yawangle             	*/
{ /* 	268  */		   0	   },		/*IPM_RightLine_cur_alteration            	*/
{ /* 	269  */		   0	   },		/*AVM_displaytype                         	*/
{ /* 	270  */		   0	   },		/*AVM_Status                              	*/
{ /* 	271  */		   0	   },		/*AVM_Guide_line_info                     	*/
{ /* 	272  */		   0	   },		/*AVM_Switch                              	*/
{ /* 	273  */		   0	   },		/*MP5_ICMenuShift_Button                  	*/
{ /* 	274  */		   0	   },		/*MP5_ICMenuActive_Button                 	*/
{ /* 	275  */		   0	   },		/*MP5_AlarmStatus                         	*/
{ /* 	276  */		   0	   },		/*MP5_AlarmOrNot                          	*/
{ /* 	277  */		   0	   },		/*MP5_ICMenu_Cmd                          	*/
{ /* 	278  */		   0	   },		/*Nav_Sts                                 	*/
{ /* 	279  */		   0	   },		/*MP5_BGLLumLvlSetting                    	*/
{ /* 	280  */		   0	   },		/*WACM_WirelessChargerStatus              	*/
{ /* 	281  */		   0	   },		/*TBOX_Year                               	*/
{ /* 	282  */		   0	   },		/*TBOX_Month                              	*/
{ /* 	283  */		   0	   },		/*TBOX_Date                               	*/
{ /* 	284  */		   0	   },		/*TBOX_Hour                               	*/
{ /* 	285  */		   0	   },		/*TBOX_Minute                             	*/
{ /* 	286  */		   0	   },		/*TBOX_Second                             	*/
{ /* 	287  */		   0	   },		/*TBOX_ReTime                             	*/
{ /* 	288  */		   0	   },		/*BCM_LoadManageLevel                     	*/
{ /* 	289  */		   0	   },		/*BCM_CarModeIndicator                    	*/
{ /* 	290  */		   0	   },		/*BCM_CarMode                             	*/
{ /* 	291  */		   0	   },		/*AFS_WorkSts                             	*/
{ /* 	292  */		   0	   },		/*SCMM_HMIDisplay                         	*/
{ /* 	293  */		   0	   },		/*EMS_BackupOdometer                      	*/
};



/**********************************************************************************************************************
    Can_Ccl_NumOfContainedRxSignals
  **********************************************************************************************************************/
  CONST(Ccl_MessageContentInfo, CCL_CONST) Can_Ccl_NumOfContainedRxSignals[Can_Ccl_Rx_Num_Messages] =
  {
     /* Index      SigStartIndex   SigCount   */
     { /*  0  */            0,       1        },
     { /*  1  */            1,       5        },
     { /*  2  */            6,       5        },
     { /*  3  */            11,       2        },
     { /*  4  */            13,       1        },
     { /*  5  */            14,       1        },
     { /*  6  */            15,       9        },
     { /*  7  */            24,       20        },
     { /*  8  */            44,       13        },
     { /*  9  */            57,       16        },
     { /*  10  */            73,       3        },
     { /*  11  */            76,       4        },
     { /*  12  */            80,       4        },
     { /*  13  */            84,       8        },
     { /*  14  */            92,       12        },
     { /*  15  */            104,       5        },
     { /*  16  */            109,       8        },
     { /*  17  */            117,       9        },
     { /*  18  */            126,       17        },
     { /*  19  */            143,       7        },
     { /*  20  */            150,       1        },
     { /*  21  */            151,       24        },
     { /*  22  */            175,       8        },
     { /*  23  */            183,       8        },
     { /*  24  */            191,       14        },
     { /*  25  */            205,       8        },
     { /*  26  */            213,       14        },
     { /*  27  */            227,       5        },
     { /*  28  */            232,       1        },
     { /*  29  */            233,       5        },
     { /*  30  */            238,       4        },
     { /*  31  */            242,       5        },
     { /*  32  */            247,       8        },
     { /*  33  */            255,       5        },
     { /*  34  */            260,       9        },
     { /*  35  */            269,       4        },
     { /*  36  */            273,       4        },
     { /*  37  */            277,       1        },
     { /*  38  */            278,       1        },
     { /*  39  */            279,       1        },
     { /*  40  */            280,       1        },
     { /*  41  */            281,       7        },
     { /*  42  */            288,       3        },
     { /*  43  */            291,       1        },
     { /*  44  */            292,       1        },
     { /*  45  */            293,       1        },
};



  #if (CCL_RX_INDICATION_API == STD_ON)
  /**********************************************************************************************************************
    Ccl_CbkRxAckFuncPtr
  **********************************************************************************************************************/
  /**
    \var    Ccl_CbkRxAckFuncPtr
    \brief  Function pointer table containing configured Rx Indication notifications for signals and signal groups.*/

  CONST(CclCbkRxAckType, CCL_CONST) Can_Ccl_CbkRxAckFuncPtr[Can_Ccl_Rx_Num_RxAck_Ind] = {
    /* Index    CbkRxAckFuncPtr                              */
	/*	0	*/	NULL	,/*SCU_faultwarning*/
	/*	1	*/	Rte_COMCbk_EMS_EngCoolanTemp_85187d93	,/*EMS_EngCoolanTemp*/
	/*	2	*/	Rte_COMCbk_EMS_EngOperationStatus_85187d93	,/*EMS_EngOperationStatus*/
	/*	3	*/	Rte_COMCbk_EMS_BatteryVoltageError_85187d93	,/*EMS_BatteryVoltageError*/
	/*	4	*/	Rte_COMCbk_EMS_EngSpeed_85187d93	,/*EMS_EngSpeed*/
	/*	5	*/	Rte_COMCbk_EMS_StartStopMessage_85187d93	,/*EMS_StartStopMessage*/
	/*	6	*/	Rte_COMCbk_TCU_DisplayGear_cb5c6a72	,/*TCU_DisplayGear*/
	/*	7	*/	NULL	,/*TCU_GearSelectorReq*/
	/*	8	*/	Rte_COMCbk_TCU_StGearMode_cb5c6a72	,/*TCU_StGearMode*/
	/*	9	*/	NULL	,/*TCU_Status_AliveCounter0x123*/
	/*	10	*/	NULL	,/*TCU_Status_Checksum0x123*/
	/*	11	*/	Rte_COMCbk_EMS_TargCruiseSpeed_341d7c91	,/*EMS_TargCruiseSpeed*/
	/*	12	*/	Rte_COMCbk_EMS_CruiseControlStatus_341d7c91	,/*EMS_CruiseControlStatus*/
	/*	13	*/	Rte_COMCbk_TBOX_ECALLFlt_983dfd23	,/*TBOX_ECALLFlt*/
	/*	14	*/	Rte_COMCbk_PEPS_Remotestartstatus_9dbbb616	,/*PEPS_Remotestartstatus*/
	/*	15	*/	Rte_COMCbk_ABS_WhlMilgFrntLe_2356a03c	,/*ABS_WhlMilgFrntLe*/
	/*	16	*/	Rte_COMCbk_ABS_WhlMilgFrntRi_2356a03c	,/*ABS_WhlMilgFrntRi*/
	/*	17	*/	Rte_COMCbk_ABS_VehSpdLgt_2356a03c	,/*ABS_VehSpdLgt*/
	/*	18	*/	Rte_COMCbk_ABS_EbdFlgFlt_2356a03c	,/*ABS_EbdFlgFlt*/
	/*	19	*/	Rte_COMCbk_ABS_AbsFlgFlt_2356a03c	,/*ABS_AbsFlgFlt*/
	/*	20	*/	NULL	,/*ABS_RollingCounter_0x221*/
	/*	21	*/	Rte_COMCbk_ABS_WhlMilgFrntLeStatus_2356a03c	,/*ABS_WhlMilgFrntLeStatus*/
	/*	22	*/	Rte_COMCbk_ABS_WhlMilgFrntRiStatus_2356a03c	,/*ABS_WhlMilgFrntRiStatus*/
	/*	23	*/	NULL	,/*ABS_Checksum_0x221*/
	/*	24	*/	NULL	,/*ESP_HHCAvailable*/
	/*	25	*/	NULL	,/*ABS_HAZActive*/
	/*	26	*/	Rte_COMCbk_ESP_EPBStatus_af66671b	,/*ESP_EPBStatus*/
	/*	27	*/	Rte_COMCbk_ESP_EPBErrorStatus_af66671b	,/*ESP_EPBErrorStatus*/
	/*	28	*/	Rte_COMCbk_ESP_HDCAvailable_af66671b	,/*ESP_HDCAvailable*/
	/*	29	*/	Rte_COMCbk_ESP_HDCActive_af66671b	,/*ESP_HDCActive*/
	/*	30	*/	Rte_COMCbk_ESP_CdpAvailable_af66671b	,/*ESP_CdpAvailable*/
	/*	31	*/	Rte_COMCbk_ESP_EPBWarningMessage3_af66671b	,/*ESP_EPBWarningMessage3*/
	/*	32	*/	Rte_COMCbk_ESP_EPBWarningMessage2_af66671b	,/*ESP_EPBWarningMessage2*/
	/*	33	*/	Rte_COMCbk_ESP_EPBWarningMessage1_af66671b	,/*ESP_EPBWarningMessage1*/
	/*	34	*/	Rte_COMCbk_ESP_AVHWarningMessage_af66671b	,/*ESP_AVHWarningMessage*/
	/*	35	*/	Rte_COMCbk_ESP_AvhActive_af66671b	,/*ESP_AvhActive*/
	/*	36	*/	Rte_COMCbk_ESP_AvhStandby_af66671b	,/*ESP_AvhStandby*/
	/*	37	*/	Rte_COMCbk_ESP_AvhAvabliable_af66671b	,/*ESP_AvhAvabliable*/
	/*	38	*/	Rte_COMCbk_ESP_VdcFlgFlt_af66671b	,/*ESP_VdcFlgFlt*/
	/*	39	*/	Rte_COMCbk_ESP_TcsFlgFlt_af66671b	,/*ESP_TcsFlgFlt*/
	/*	40	*/	Rte_COMCbk_ESP_ESPInfoLamp_af66671b	,/*ESP_ESPInfoLamp*/
	/*	41	*/	Rte_COMCbk_ESP_EspEnableSts_af66671b	,/*ESP_EspEnableSts*/
	/*	42	*/	NULL	,/*ESP_RollingCounter_0x243*/
	/*	43	*/	NULL	,/*ESP_Checksum_0x243*/
	/*	44	*/	Rte_COMCbk_IPM_LaneAssitType_32f79b14	,/*IPM_LaneAssitType*/
	/*	45	*/	NULL	,/*IPM_LaneAssit_WarningVibration*/
	/*	46	*/	Rte_COMCbk_IPM_LaneAssit_WarningAudio_32f79b14	,/*IPM_LaneAssit_WarningAudio*/
	/*	47	*/	Rte_COMCbk_IPM_LaneAssit_LeftVisualization_32f79b14	,/*IPM_LaneAssit_LeftVisualization*/
	/*	48	*/	Rte_COMCbk_IPM_LaneAssit_RightVisualization_32f79b14	,/*IPM_LaneAssit_RightVisualization*/
	/*	49	*/	Rte_COMCbk_IPM_SLASpdlimitUnits_32f79b14	,/*IPM_SLASpdlimitUnits*/
	/*	50	*/	Rte_COMCbk_IPM_SLAState_32f79b14	,/*IPM_SLAState*/
	/*	51	*/	Rte_COMCbk_IPM_LaneAssit_Status_32f79b14	,/*IPM_LaneAssit_Status*/
	/*	52	*/	Rte_COMCbk_IPM_SLASpdlimit_32f79b14	,/*IPM_SLASpdlimit*/
	/*	53	*/	Rte_COMCbk_IPM_HMA_Status_32f79b14	,/*IPM_HMA_Status*/
	/*	54	*/	NULL	,/*IPM_DDD_IndexStatus*/
	/*	55	*/	NULL	,/*IPM_DDD_WarningLevel*/
	/*	56	*/	Rte_COMCbk_IPM_LaneAssit_HandsonReq_32f79b14	,/*IPM_LaneAssit_HandsonReq*/
	/*	57	*/	Rte_COMCbk_vSetDis_255e8a04	,/*vSetDis*/
	/*	58	*/	Rte_COMCbk_ObjValid_255e8a04	,/*ObjValid*/
	/*	59	*/	Rte_COMCbk_TauGapSet_255e8a04	,/*TauGapSet*/
	/*	60	*/	Rte_COMCbk_dxTarObj_255e8a04	,/*dxTarObj*/
	/*	61	*/	Rte_COMCbk_ACCHMI_Mode_255e8a04	,/*ACCHMI_Mode*/
	/*	62	*/	NULL	,/*ACCFailInfo*/
	/*	63	*/	Rte_COMCbk_TakeOverReq_255e8a04	,/*TakeOverReq*/
	/*	64	*/	Rte_COMCbk_AEB_STATE_255e8a04	,/*AEB_STATE*/
	/*	65	*/	NULL	,/*ACC_Startstop_infor*/
	/*	66	*/	Rte_COMCbk_PCW_preWarning_255e8a04	,/*PCW_preWarning*/
	/*	67	*/	Rte_COMCbk_PCW_latentWarning_255e8a04	,/*PCW_latentWarning*/
	/*	68	*/	Rte_COMCbk_PCW_STATE_255e8a04	,/*PCW_STATE*/
	/*	69	*/	NULL	,/*Obj_Speed*/
	/*	70	*/	NULL	,/*Rolling_counter_0x246*/
	/*	71	*/	Rte_COMCbk_Textinfo_255e8a04	,/*Textinfo*/
	/*	72	*/	NULL	,/*Checksum_0x246*/
	/*	73	*/	NULL	,/*IPM_DCLC_manualfeedback*/
	/*	74	*/	NULL	,/*IPM_ELKSts*/
	/*	75	*/	NULL	,/*IPM_DCLCSts*/
	/*	76	*/	Rte_COMCbk_EPS_S_WarningLampYellow_e5742092	,/*EPS_S_WarningLampYellow*/
	/*	77	*/	Rte_COMCbk_EPS_S_SafeLampRed_e5742092	,/*EPS_S_SafeLampRed*/
	/*	78	*/	NULL	,/*Rolling_counter_0x260*/
	/*	79	*/	NULL	,/*Checksum_0x260*/
	/*	80	*/	Rte_COMCbk_PAM_ChimeCmdSoundStatus_49f5ddcc	,/*PAM_ChimeCmdSoundStatus*/
	/*	81	*/	Rte_COMCbk_PAM_RearSysTemWorkSts_49f5ddcc	,/*PAM_RearSysTemWorkSts*/
	/*	82	*/	Rte_COMCbk_PAM_FrontSysTemWorkSts_49f5ddcc	,/*PAM_FrontSysTemWorkSts*/
	/*	83	*/	Rte_COMCbk_PAM_ChimeCmdSoundCadence_49f5ddcc	,/*PAM_ChimeCmdSoundCadence*/
	/*	84	*/	NULL	,/*LAEB_BrkgReqVal*/
	/*	85	*/	NULL	,/*LAEB_BrkgReq*/
	/*	86	*/	NULL	,/*LAEB_DistanceToCollision*/
	/*	87	*/	NULL	,/*LAEB_SpeakReq*/
	/*	88	*/	NULL	,/*LAEB_WorkSts*/
	/*	89	*/	NULL	,/*Checksum_0x274*/
	/*	90	*/	NULL	,/*Rolling_counter_0x274*/
	/*	91	*/	NULL	,/*LAEB_LedReq*/
	/*	92	*/	Rte_COMCbk_SOD_LCA_warningReqRight_a75280f1	,/*SOD_LCA_warningReqRight*/
	/*	93	*/	Rte_COMCbk_SOD_DOA_warningReqRightRear_a75280f1	,/*SOD_DOA_warningReqRightRear*/
	/*	94	*/	Rte_COMCbk_SOD_DOA_warningReqRightFront_a75280f1	,/*SOD_DOA_warningReqRightFront*/
	/*	95	*/	Rte_COMCbk_SOD_CTA_warningReqRight_a75280f1	,/*SOD_CTA_warningReqRight*/
	/*	96	*/	Rte_COMCbk_SOD_BLIS_display_a75280f1	,/*SOD_BLIS_display*/
	/*	97	*/	Rte_COMCbk_SOD_LCA_warningReqLeft_a75280f1	,/*SOD_LCA_warningReqLeft*/
	/*	98	*/	Rte_COMCbk_SOD_DOA_warningReqLeftRear_a75280f1	,/*SOD_DOA_warningReqLeftRear*/
	/*	99	*/	Rte_COMCbk_SOD_DOA_warningReqLeftFront_a75280f1	,/*SOD_DOA_warningReqLeftFront*/
	/*	100	*/	Rte_COMCbk_SOD_CTA_warningReqLeft_a75280f1	,/*SOD_CTA_warningReqLeft*/
	/*	101	*/	Rte_COMCbk_DOA_OFFTelltale_a75280f1	,/*DOA_OFFTelltale*/
	/*	102	*/	Rte_COMCbk_CTA_OFFTelltale_a75280f1	,/*CTA_OFFTelltale*/
	/*	103	*/	Rte_COMCbk_SODLCA_OFFTelltale_a75280f1	,/*SODLCA_OFFTelltale*/
	/*	104	*/	NULL	,/*IPM_LedtLine_dx_start*/
	/*	105	*/	NULL	,/*IPM_LeftLine_dy*/
	/*	106	*/	NULL	,/*IPM_LeftLine_dx_lookhead*/
	/*	107	*/	NULL	,/*IPM_LeftLine_hor_curve*/
	/*	108	*/	NULL	,/*IPM_LeftLine_yawangle*/
	/*	109	*/	Rte_COMCbk_MRR_F_Object_dx_49708b05	,/*MRR_F_Object_dx*/
	/*	110	*/	Rte_COMCbk_MRR_F_Object_dy_49708b05	,/*MRR_F_Object_dy*/
	/*	111	*/	Rte_COMCbk_MRR_F_Obj_0x_class_49708b05	,/*MRR_F_Obj_0x_class*/
	/*	112	*/	NULL	,/*MRR_FF_Object_dx*/
	/*	113	*/	NULL	,/*MRR_FF_Object_dy*/
	/*	114	*/	NULL	,/*MRR_FF_Obj_0x_class*/
	/*	115	*/	NULL	,/*MRR_FFTargrtDetection*/
	/*	116	*/	NULL	,/*MRR_PedDetection*/
	/*	117	*/	Rte_COMCbk_IPM_LaneAssit_LeftVisualization_32f79b14	,/*IPM_LaneAssit_LeftVisualization*/
	/*	118	*/	NULL	,/*IPM_LeftLine_Type*/
	/*	119	*/	NULL	,/*IPM_LeftLine_Color*/
	/*	120	*/	NULL	,/*IPM_leftLeftLine_Type*/
	/*	121	*/	NULL	,/*IPM_leftLeftLine_Color*/
	/*	122	*/	NULL	,/*IPM_leftleftLine_dy*/
	/*	123	*/	NULL	,/*IPM_leftleftLine_hor_curve*/
	/*	124	*/	NULL	,/*IPM_leftleftLine_yawangle*/
	/*	125	*/	NULL	,/*IPM_leftleftLine_cur_alteration*/
	/*	126	*/	Rte_COMCbk_BCM_DoorStsRearRi_0edb943f	,/*BCM_DoorStsRearRi*/
	/*	127	*/	Rte_COMCbk_BCM_DoorStsRearLe_0edb943f	,/*BCM_DoorStsRearLe*/
	/*	128	*/	Rte_COMCbk_BCM_DoorStsFrntRi_0edb943f	,/*BCM_DoorStsFrntRi*/
	/*	129	*/	Rte_COMCbk_BCM_DoorStsFrntLe_0edb943f	,/*BCM_DoorStsFrntLe*/
	/*	130	*/	NULL	,/*BCM_DoorLockStsRearRi*/
	/*	131	*/	NULL	,/*BCM_DoorLockStsRearLe*/
	/*	132	*/	NULL	,/*BCM_DoorLockStsFrntRi*/
	/*	133	*/	NULL	,/*BCM_DoorLockStsFrntLe*/
	/*	134	*/	NULL	,/*BCM_AntiTheftSts*/
	/*	135	*/	NULL	,/*BCM_LockUnlockFeedback*/
	/*	136	*/	NULL	,/*BCM_DoorLockStsTrunk*/
	/*	137	*/	Rte_COMCbk_BCM_DoorStsTrunk_0edb943f	,/*BCM_DoorStsTrunk*/
	/*	138	*/	NULL	,/*BCM_TrunkDoorPreUnlockSts*/
	/*	139	*/	Rte_COMCbk_BCM_EnginehoodSts_0edb943f	,/*BCM_EnginehoodSts*/
	/*	140	*/	NULL	,/*BCM_Rolling_counter_0x310*/
	/*	141	*/	Rte_COMCbk_BCM_TurnIndicatorSts_0edb943f	,/*BCM_TurnIndicatorSts*/
	/*	142	*/	NULL	,/*BCM_Checksum_0x310*/
	/*	143	*/	NULL	,/*BCM_OutsideTempDig*/
	/*	144	*/	Rte_COMCbk_BCM_BrakeFluidSts_abc8cd44	,/*BCM_BrakeFluidSts*/
	/*	145	*/	Rte_COMCbk_BCM_OutsideTemp_abc8cd44	,/*BCM_OutsideTemp*/
	/*	146	*/	NULL	,/*BCM_Reverse_gear*/
	/*	147	*/	NULL	,/*BCM_SS_EnableSts*/
	/*	148	*/	NULL	,/*BCM_Rollingcounter_0x313*/
	/*	149	*/	NULL	,/*BCM_Checksum_0x313*/
	/*	150	*/	Rte_COMCbk_BCM_BGLLumLvlSettingStatus_a1dcf71c	,/*BCM_BGLLumLvlSettingStatus*/
	/*	151	*/	Rte_COMCbk_BCM_FrntFogLmpSts_52444383	,/*BCM_FrntFogLmpSts*/
	/*	152	*/	Rte_COMCbk_BCM_PosLmpSts_52444383	,/*BCM_PosLmpSts*/
	/*	153	*/	Rte_COMCbk_BCM_LowBeamSts_52444383	,/*BCM_LowBeamSts*/
	/*	154	*/	Rte_COMCbk_BCM_HighBeamSts_52444383	,/*BCM_HighBeamSts*/
	/*	155	*/	NULL	,/*BCM_reversinglightSts*/
	/*	156	*/	NULL	,/*BCM_DayRunningLampSts*/
	/*	157	*/	Rte_COMCbk_BCM_RearFogLmpSts_52444383	,/*BCM_RearFogLmpSts*/
	/*	158	*/	NULL	,/*BCM_laserlightSts*/
	/*	159	*/	NULL	,/*BCM_AmbientLightSts*/
	/*	160	*/	NULL	,/*BCM_Highmountedstoplamp*/
	/*	161	*/	NULL	,/*BCM_BrakelightSts*/
	/*	162	*/	Rte_COMCbk_BCM_BackHomeSts_52444383	,/*BCM_BackHomeSts*/
	/*	163	*/	NULL	,/*BCM_AutolampSts*/
	/*	164	*/	NULL	,/*BCM_readinglampSts*/
	/*	165	*/	Rte_COMCbk_BCM_DayRunningLampDig_52444383	,/*BCM_DayRunningLampDig*/
	/*	166	*/	Rte_COMCbk_BCM_BrakelightDig_52444383	,/*BCM_BrakelightDig*/
	/*	167	*/	Rte_COMCbk_BCM_reversinglightDig_52444383	,/*BCM_reversinglightDig*/
	/*	168	*/	Rte_COMCbk_BCM_TurnIndicatorDig_52444383	,/*BCM_TurnIndicatorDig*/
	/*	169	*/	Rte_COMCbk_BCM_RearFogLmpDig_52444383	,/*BCM_RearFogLmpDig*/
	/*	170	*/	Rte_COMCbk_BCM_FrntFogLmpDig_52444383	,/*BCM_FrntFogLmpDig*/
	/*	171	*/	Rte_COMCbk_BCM_PosLmpDig_52444383	,/*BCM_PosLmpDig*/
	/*	172	*/	Rte_COMCbk_BCM_LowBeamDig_52444383	,/*BCM_LowBeamDig*/
	/*	173	*/	NULL	,/*BCM_Rollingcounter_0x318*/
	/*	174	*/	NULL	,/*BCM_Checksum_0x318*/
	/*	175	*/	Rte_COMCbk_SWM_Menu_Right_f733f54d	,/*SWM_Menu_Right*/
	/*	176	*/	Rte_COMCbk_SWM_Menu_Left_f733f54d	,/*SWM_Menu_Left*/
	/*	177	*/	Rte_COMCbk_SWM_Menu_Down_f733f54d	,/*SWM_Menu_Down*/
	/*	178	*/	Rte_COMCbk_SWM_Menu_Up_f733f54d	,/*SWM_Menu_Up*/
	/*	179	*/	NULL	,/*Rolling_counter_0x31A*/
	/*	180	*/	Rte_COMCbk_SWM_Menu_Return_f733f54d	,/*SWM_Menu_Return*/
	/*	181	*/	Rte_COMCbk_SWM_Menu_Confirm_f733f54d	,/*SWM_Menu_Confirm*/
	/*	182	*/	NULL	,/*Checksum_0x31A*/
	/*	183	*/	Rte_COMCbk_SWM_ACCtauGapSetPlus_db79ffcb	,/*SWM_ACCtauGapSetPlus*/
	/*	184	*/	Rte_COMCbk_SWM_ACCvSetMinus_db79ffcb	,/*SWM_ACCvSetMinus*/
	/*	185	*/	Rte_COMCbk_SWM_ACCvSetPlus_db79ffcb	,/*SWM_ACCvSetPlus*/
	/*	186	*/	Rte_COMCbk_SWM_ACCResume_db79ffcb	,/*SWM_ACCResume*/
	/*	187	*/	Rte_COMCbk_SWM_ACCSet_db79ffcb	,/*SWM_ACCSet*/
	/*	188	*/	Rte_COMCbk_SWM_ACCEnableSwitch_db79ffcb	,/*SWM_ACCEnableSwitch*/
	/*	189	*/	Rte_COMCbk_SWM_LaneAssistSwitch_db79ffcb	,/*SWM_LaneAssistSwitch*/
	/*	190	*/	Rte_COMCbk_SWM_ACCtauGapSetMinus_db79ffcb	,/*SWM_ACCtauGapSetMinus*/
	/*	191	*/	Rte_COMCbk_PEPS_PowerMode_9b45c0e5	,/*PEPS_PowerMode*/
	/*	192	*/	Rte_COMCbk_PEPS_IMMO_MatchStatus_9b45c0e5	,/*PEPS_IMMO_MatchStatus*/
	/*	193	*/	Rte_COMCbk_PEPS_SystemFailStatus_9b45c0e5	,/*PEPS_SystemFailStatus*/
	/*	194	*/	Rte_COMCbk_PEPS_ESCL_FailStatus_9b45c0e5	,/*PEPS_ESCL_FailStatus*/
	/*	195	*/	Rte_COMCbk_PEPS_SSB_FailStatus_9b45c0e5	,/*PEPS_SSB_FailStatus*/
	/*	196	*/	Rte_COMCbk_PEPS_BrakeIndicationWarning_9b45c0e5	,/*PEPS_BrakeIndicationWarning*/
	/*	197	*/	Rte_COMCbk_PEPS_NotPNWarning_9b45c0e5	,/*PEPS_NotPNWarning*/
	/*	198	*/	Rte_COMCbk_PEPS_DoorOpenNotOFFWarning_9b45c0e5	,/*PEPS_DoorOpenNotOFFWarning*/
	/*	199	*/	Rte_COMCbk_PEPS_DoorOpenWarning_9b45c0e5	,/*PEPS_DoorOpenWarning*/
	/*	200	*/	Rte_COMCbk_PEPS_KeyBatteryWarning_9b45c0e5	,/*PEPS_KeyBatteryWarning*/
	/*	201	*/	Rte_COMCbk_PEPS_KeyOutWarning1_9b45c0e5	,/*PEPS_KeyOutWarning1*/
	/*	202	*/	Rte_COMCbk_PEPS_NoKeyFoundWarning_9b45c0e5	,/*PEPS_NoKeyFoundWarning*/
	/*	203	*/	Rte_COMCbk_PEPS_KeyReminderWarning_9b45c0e5	,/*PEPS_KeyReminderWarning*/
	/*	204	*/	Rte_COMCbk_PEPS_RemainingNumSts_9b45c0e5	,/*PEPS_RemainingNumSts*/
	/*	205	*/	Rte_COMCbk_SRS_SBR_PAMsenger_9595b6c2	,/*SRS_SBR_PAMsenger*/
	/*	206	*/	Rte_COMCbk_SRS_SBR_Driver_9595b6c2	,/*SRS_SBR_Driver*/
	/*	207	*/	Rte_COMCbk_SRS_AirBagFailSts_9595b6c2	,/*SRS_AirBagFailSts*/
	/*	208	*/	Rte_COMCbk_SRS_SBR_SecondRowRight_9595b6c2	,/*SRS_SBR_SecondRowRight*/
	/*	209	*/	Rte_COMCbk_SRS_SBR_SecondRowMid_9595b6c2	,/*SRS_SBR_SecondRowMid*/
	/*	210	*/	Rte_COMCbk_SRS_SBR_SecondRowLeft_9595b6c2	,/*SRS_SBR_SecondRowLeft*/
	/*	211	*/	NULL	,/*Rolling_counter_0x350*/
	/*	212	*/	NULL	,/*Checksum_0x350*/
	/*	213	*/	Rte_COMCbk_TPMS_LF_Pressure_c030f382	,/*TPMS_LF_Pressure*/
	/*	214	*/	Rte_COMCbk_TPMS_RF_Pressure_c030f382	,/*TPMS_RF_Pressure*/
	/*	215	*/	Rte_COMCbk_TPMS_RR_Pressure_c030f382	,/*TPMS_RR_Pressure*/
	/*	216	*/	Rte_COMCbk_TPMS_LR_Pressure_c030f382	,/*TPMS_LR_Pressure*/
	/*	217	*/	Rte_COMCbk_TPMS_Tire_Temperature_c030f382	,/*TPMS_Tire_Temperature*/
	/*	218	*/	Rte_COMCbk_TPMS_LF_Pressure_Warning_c030f382	,/*TPMS_LF_Pressure_Warning*/
	/*	219	*/	Rte_COMCbk_TPMS_RF_Pressure_Warning_c030f382	,/*TPMS_RF_Pressure_Warning*/
	/*	220	*/	Rte_COMCbk_TPMS_System_Status_c030f382	,/*TPMS_System_Status*/
	/*	221	*/	Rte_COMCbk_TPMS_RR_Pressure_Warning_c030f382	,/*TPMS_RR_Pressure_Warning*/
	/*	222	*/	Rte_COMCbk_TPMS_LR_Pressure_Warning_c030f382	,/*TPMS_LR_Pressure_Warning*/
	/*	223	*/	Rte_COMCbk_TPMS_Temperature_Warning_c030f382	,/*TPMS_Temperature_Warning*/
	/*	224	*/	NULL	,/*TPMS_resrved*/
	/*	225	*/	Rte_COMCbk_Tire_Position_c030f382	,/*Tire_Position*/
	/*	226	*/	Rte_COMCbk_TPMS_Lamp_Status_c030f382	,/*TPMS_Lamp_Status*/
	/*	227	*/	Rte_COMCbk_EMS_Fuelcounter_daed4b4e	,/*EMS_Fuelcounter*/
	/*	228	*/	Rte_COMCbk_EMS_FuelconsumptionInst_daed4b4e	,/*EMS_FuelconsumptionInst*/
	/*	229	*/	Rte_COMCbk_EMS_MIL_daed4b4e	,/*EMS_MIL*/
	/*	230	*/	Rte_COMCbk_EMS_SVS_daed4b4e	,/*EMS_SVS*/
	/*	231	*/	Rte_COMCbk_EMS_StartStopStatus_daed4b4e	,/*EMS_StartStopStatus*/
	/*	232	*/	Rte_COMCbk_EMS_GasPrtcWarn_G_Rq_daa19a1a	,/*EMS_GasPrtcWarn_G_Rq*/
	/*	233	*/	NULL	,/*MP5_AudioStatus*/
	/*	234	*/	NULL	,/*MP5_EnergyFlow*/
	/*	235	*/	NULL	,/*MP5_SetMultiButton*/
	/*	236	*/	Rte_COMCbk_MP5_BSDSoundSwitchSts_c90244fe	,/*MP5_BSDSoundSwitchSts*/
	/*	237	*/	Rte_COMCbk_MP5_NavStatus_c90244fe	,/*MP5_NavStatus*/
	/*	238	*/	Rte_COMCbk_MP5_NavICON_0f6d4d79	,/*MP5_NavICON*/
	/*	239	*/	Rte_COMCbk_MP5_ROUTE_REMAIN_DIS_0f6d4d79	,/*MP5_ROUTE_REMAIN_DIS*/
	/*	240	*/	NULL	,/*MP5_ALModeSetting*/
	/*	241	*/	NULL	,/*MP5_ALStartAroundSetting*/
	/*	242	*/	Rte_COMCbk_TCU_EmergencyTowingSts_94ca6b54	,/*TCU_EmergencyTowingSts*/
	/*	243	*/	Rte_COMCbk_TrnSrvcRqd_B_Rq_94ca6b54	,/*TrnSrvcRqd_B_Rq*/
	/*	244	*/	Rte_COMCbk_TCU_GearPFault_94ca6b54	,/*TCU_GearPFault*/
	/*	245	*/	Rte_COMCbk_TCU_WarningMessage_94ca6b54	,/*TCU_WarningMessage*/
	/*	246	*/	Rte_COMCbk_TCU_DrvShiftAllwCondRmd_94ca6b54	,/*TCU_DrvShiftAllwCondRmd*/
	/*	247	*/	NULL	,/*MRR_L_Object_dx*/
	/*	248	*/	NULL	,/*MRR_L_Object_dy*/
	/*	249	*/	NULL	,/*MRR_L_Obj_0x_class*/
	/*	250	*/	NULL	,/*MRR_R_Object_dx*/
	/*	251	*/	NULL	,/*MRR_R_Object_dy*/
	/*	252	*/	NULL	,/*MRR_R_Obj_0x_class*/
	/*	253	*/	NULL	,/*MRR_LeftTargrtDetection*/
	/*	254	*/	NULL	,/*MRR_RightTargrtDetection*/
	/*	255	*/	NULL	,/*IPM_RightLine_dx_start*/
	/*	256	*/	NULL	,/*IPM_RightLine_dy*/
	/*	257	*/	NULL	,/*IPM_RightLine_dx_lookhead*/
	/*	258	*/	NULL	,/*IPM_RightLine_hor_curve*/
	/*	259	*/	NULL	,/*IPM_RightLine_yawangle*/
	/*	260	*/	Rte_COMCbk_IPM_LaneAssit_RightVisualization_32f79b14	,/*IPM_LaneAssit_RightVisualization*/
	/*	261	*/	NULL	,/*IPM_rightRighLine_Type*/
	/*	262	*/	NULL	,/*IPM_RighLine_Color*/
	/*	263	*/	NULL	,/*IPM_RighLine_Type*/
	/*	264	*/	NULL	,/*IPM_RighrightLine_Color*/
	/*	265	*/	NULL	,/*IPM_rightRightLine_dy*/
	/*	266	*/	NULL	,/*IPM_rightRightLine_hor_curve*/
	/*	267	*/	NULL	,/*IPM_rightRightLine_yawangle*/
	/*	268	*/	NULL	,/*IPM_RightLine_cur_alteration*/
	/*	269	*/	NULL	,/*AVM_displaytype*/
	/*	270	*/	NULL	,/*AVM_Status*/
	/*	271	*/	NULL	,/*AVM_Guide_line_info*/
	/*	272	*/	NULL	,/*AVM_Switch*/
	/*	273	*/	Rte_COMCbk_MP5_ICMenuShift_Button_046cad19	,/*MP5_ICMenuShift_Button*/
	/*	274	*/	Rte_COMCbk_MP5_ICMenuActive_Button_046cad19	,/*MP5_ICMenuActive_Button*/
	/*	275	*/	Rte_COMCbk_MP5_AlarmStatus_046cad19	,/*MP5_AlarmStatus*/
	/*	276	*/	Rte_COMCbk_MP5_AlarmOrNot_046cad19	,/*MP5_AlarmOrNot*/
	/*	277	*/	Rte_COMCbk_MP5_ICMenu_Cmd_34a683c9	,/*MP5_ICMenu_Cmd*/
	/*	278	*/	Rte_COMCbk_Nav_Sts_0f6324b4	,/*Nav_Sts*/
	/*	279	*/	NULL	,/*MP5_BGLLumLvlSetting*/
	/*	280	*/	NULL	,/*WACM_WirelessChargerStatus*/
	/*	281	*/	Rte_COMCbk_TBOX_Year_4e88e95a	,/*TBOX_Year*/
	/*	282	*/	Rte_COMCbk_TBOX_Month_4e88e95a	,/*TBOX_Month*/
	/*	283	*/	Rte_COMCbk_TBOX_Date_4e88e95a	,/*TBOX_Date*/
	/*	284	*/	Rte_COMCbk_TBOX_Hour_4e88e95a	,/*TBOX_Hour*/
	/*	285	*/	Rte_COMCbk_TBOX_Minute_4e88e95a	,/*TBOX_Minute*/
	/*	286	*/	Rte_COMCbk_TBOX_Second_4e88e95a	,/*TBOX_Second*/
	/*	287	*/	Rte_COMCbk_TBOX_ReTime_4e88e95a	,/*TBOX_ReTime*/
	/*	288	*/	Rte_COMCbk_BCM_LoadManageLevel_00b00241	,/*BCM_LoadManageLevel*/
	/*	289	*/	Rte_COMCbk_BCM_CarModeIndicator_00b00241	,/*BCM_CarModeIndicator*/
	/*	290	*/	Rte_COMCbk_BCM_CarMode_00b00241	,/*BCM_CarMode*/
	/*	291	*/	NULL	,/*AFS_WorkSts*/
	/*	292	*/	Rte_COMCbk_SCMM_HMIDisplay_8c54f0fa	,/*SCMM_HMIDisplay*/
	/*	293	*/	Rte_COMCbk_EMS_BackupOdometer_63950623	,/*EMS_BackupOdometer*/
  };
  #endif


  #if (CCL_RX_TOUTINDICATION_API == STD_ON)
  /**********************************************************************************************************************
    Ccl_CbkRxTOutFuncPtr
  **********************************************************************************************************************/
  /**
    \var    Ccl_CbkRxTOutFuncPtr
    \brief  Function pointer table containing configured Rx timeout notifications for signals and signal groups. ea:{71D75BEB-245A-468b-96DB-A4F1362E927C}
  */
CONST(CclCbkRxTOutType, CCL_CONST) Can_Ccl_CbkRxTOutFuncPtr[Can_Ccl_Rx_Num_RxTOut_Ind] = {
/* Index	  CbkRxTOutFuncPtr	   */
	/*	0	*/	NULL	,/*SCU_faultwarning*/
	/*	1	*/	Rte_COMCbkRxTOut_EMS_EngCoolanTemp_85187d93	,/*EMS_EngCoolanTemp*/
	/*	2	*/	Rte_COMCbkRxTOut_EMS_EngOperationStatus_85187d93	,/*EMS_EngOperationStatus*/
	/*	3	*/	Rte_COMCbkRxTOut_EMS_BatteryVoltageError_85187d93	,/*EMS_BatteryVoltageError*/
	/*	4	*/	Rte_COMCbkRxTOut_EMS_EngSpeed_85187d93	,/*EMS_EngSpeed*/
	/*	5	*/	Rte_COMCbkRxTOut_EMS_StartStopMessage_85187d93	,/*EMS_StartStopMessage*/
	/*	6	*/	Rte_COMCbkRxTOut_TCU_DisplayGear_cb5c6a72	,/*TCU_DisplayGear*/
	/*	7	*/	NULL	,/*TCU_GearSelectorReq*/
	/*	8	*/	Rte_COMCbkRxTOut_TCU_StGearMode_cb5c6a72	,/*TCU_StGearMode*/
	/*	9	*/	NULL	,/*TCU_Status_AliveCounter0x123*/
	/*	10	*/	NULL	,/*TCU_Status_Checksum0x123*/
	/*	11	*/	Rte_COMCbkRxTOut_EMS_TargCruiseSpeed_341d7c91	,/*EMS_TargCruiseSpeed*/
	/*	12	*/	Rte_COMCbkRxTOut_EMS_CruiseControlStatus_341d7c91	,/*EMS_CruiseControlStatus*/
	/*	13	*/	Rte_COMCbkRxTOut_TBOX_ECALLFlt_983dfd23	,/*TBOX_ECALLFlt*/
	/*	14	*/	Rte_COMCbkRxTOut_PEPS_Remotestartstatus_9dbbb616	,/*PEPS_Remotestartstatus*/
	/*	15	*/	Rte_COMCbkRxTOut_ABS_WhlMilgFrntLe_2356a03c	,/*ABS_WhlMilgFrntLe*/
	/*	16	*/	Rte_COMCbkRxTOut_ABS_WhlMilgFrntRi_2356a03c	,/*ABS_WhlMilgFrntRi*/
	/*	17	*/	Rte_COMCbkRxTOut_ABS_VehSpdLgt_2356a03c	,/*ABS_VehSpdLgt*/
	/*	18	*/	Rte_COMCbkRxTOut_ABS_EbdFlgFlt_2356a03c	,/*ABS_EbdFlgFlt*/
	/*	19	*/	Rte_COMCbkRxTOut_ABS_AbsFlgFlt_2356a03c	,/*ABS_AbsFlgFlt*/
	/*	20	*/	NULL	,/*ABS_RollingCounter_0x221*/
	/*	21	*/	Rte_COMCbkRxTOut_ABS_WhlMilgFrntLeStatus_2356a03c	,/*ABS_WhlMilgFrntLeStatus*/
	/*	22	*/	Rte_COMCbkRxTOut_ABS_WhlMilgFrntRiStatus_2356a03c	,/*ABS_WhlMilgFrntRiStatus*/
	/*	23	*/	NULL	,/*ABS_Checksum_0x221*/
	/*	24	*/	NULL	,/*ESP_HHCAvailable*/
	/*	25	*/	NULL	,/*ABS_HAZActive*/
	/*	26	*/	Rte_COMCbkRxTOut_ESP_EPBStatus_af66671b	,/*ESP_EPBStatus*/
	/*	27	*/	Rte_COMCbkRxTOut_ESP_EPBErrorStatus_af66671b	,/*ESP_EPBErrorStatus*/
	/*	28	*/	Rte_COMCbkRxTOut_ESP_HDCAvailable_af66671b	,/*ESP_HDCAvailable*/
	/*	29	*/	Rte_COMCbkRxTOut_ESP_HDCActive_af66671b	,/*ESP_HDCActive*/
	/*	30	*/	Rte_COMCbkRxTOut_ESP_CdpAvailable_af66671b	,/*ESP_CdpAvailable*/
	/*	31	*/	Rte_COMCbkRxTOut_ESP_EPBWarningMessage3_af66671b	,/*ESP_EPBWarningMessage3*/
	/*	32	*/	Rte_COMCbkRxTOut_ESP_EPBWarningMessage2_af66671b	,/*ESP_EPBWarningMessage2*/
	/*	33	*/	Rte_COMCbkRxTOut_ESP_EPBWarningMessage1_af66671b	,/*ESP_EPBWarningMessage1*/
	/*	34	*/	Rte_COMCbkRxTOut_ESP_AVHWarningMessage_af66671b	,/*ESP_AVHWarningMessage*/
	/*	35	*/	Rte_COMCbkRxTOut_ESP_AvhActive_af66671b	,/*ESP_AvhActive*/
	/*	36	*/	Rte_COMCbkRxTOut_ESP_AvhStandby_af66671b	,/*ESP_AvhStandby*/
	/*	37	*/	Rte_COMCbkRxTOut_ESP_AvhAvabliable_af66671b	,/*ESP_AvhAvabliable*/
	/*	38	*/	Rte_COMCbkRxTOut_ESP_VdcFlgFlt_af66671b	,/*ESP_VdcFlgFlt*/
	/*	39	*/	Rte_COMCbkRxTOut_ESP_TcsFlgFlt_af66671b	,/*ESP_TcsFlgFlt*/
	/*	40	*/	Rte_COMCbkRxTOut_ESP_ESPInfoLamp_af66671b	,/*ESP_ESPInfoLamp*/
	/*	41	*/	Rte_COMCbkRxTOut_ESP_EspEnableSts_af66671b	,/*ESP_EspEnableSts*/
	/*	42	*/	NULL	,/*ESP_RollingCounter_0x243*/
	/*	43	*/	NULL	,/*ESP_Checksum_0x243*/
	/*	44	*/	Rte_COMCbkRxTOut_IPM_LaneAssitType_32f79b14	,/*IPM_LaneAssitType*/
	/*	45	*/	NULL	,/*IPM_LaneAssit_WarningVibration*/
	/*	46	*/	Rte_COMCbkRxTOut_IPM_LaneAssit_WarningAudio_32f79b14	,/*IPM_LaneAssit_WarningAudio*/
	/*	47	*/	Rte_COMCbkRxTOut_IPM_LaneAssit_LeftVisualization_32f79b14	,/*IPM_LaneAssit_LeftVisualization*/
	/*	48	*/	Rte_COMCbkRxTOut_IPM_LaneAssit_RightVisualization_32f79b14	,/*IPM_LaneAssit_RightVisualization*/
	/*	49	*/	Rte_COMCbkRxTOut_IPM_SLASpdlimitUnits_32f79b14	,/*IPM_SLASpdlimitUnits*/
	/*	50	*/	Rte_COMCbkRxTOut_IPM_SLAState_32f79b14	,/*IPM_SLAState*/
	/*	51	*/	Rte_COMCbkRxTOut_IPM_LaneAssit_Status_32f79b14	,/*IPM_LaneAssit_Status*/
	/*	52	*/	Rte_COMCbkRxTOut_IPM_SLASpdlimit_32f79b14	,/*IPM_SLASpdlimit*/
	/*	53	*/	Rte_COMCbkRxTOut_IPM_HMA_Status_32f79b14	,/*IPM_HMA_Status*/
	/*	54	*/	NULL	,/*IPM_DDD_IndexStatus*/
	/*	55	*/	NULL	,/*IPM_DDD_WarningLevel*/
	/*	56	*/	Rte_COMCbkRxTOut_IPM_LaneAssit_HandsonReq_32f79b14	,/*IPM_LaneAssit_HandsonReq*/
	/*	57	*/	Rte_COMCbkRxTOut_vSetDis_255e8a04	,/*vSetDis*/
	/*	58	*/	Rte_COMCbkRxTOut_ObjValid_255e8a04	,/*ObjValid*/
	/*	59	*/	Rte_COMCbkRxTOut_TauGapSet_255e8a04	,/*TauGapSet*/
	/*	60	*/	Rte_COMCbkRxTOut_dxTarObj_255e8a04	,/*dxTarObj*/
	/*	61	*/	Rte_COMCbkRxTOut_ACCHMI_Mode_255e8a04	,/*ACCHMI_Mode*/
	/*	62	*/	NULL	,/*ACCFailInfo*/
	/*	63	*/	Rte_COMCbkRxTOut_TakeOverReq_255e8a04	,/*TakeOverReq*/
	/*	64	*/	Rte_COMCbkRxTOut_AEB_STATE_255e8a04	,/*AEB_STATE*/
	/*	65	*/	NULL	,/*ACC_Startstop_infor*/
	/*	66	*/	Rte_COMCbkRxTOut_PCW_preWarning_255e8a04	,/*PCW_preWarning*/
	/*	67	*/	Rte_COMCbkRxTOut_PCW_latentWarning_255e8a04	,/*PCW_latentWarning*/
	/*	68	*/	Rte_COMCbkRxTOut_PCW_STATE_255e8a04	,/*PCW_STATE*/
	/*	69	*/	NULL	,/*Obj_Speed*/
	/*	70	*/	NULL	,/*Rolling_counter_0x246*/
	/*	71	*/	Rte_COMCbkRxTOut_Textinfo_255e8a04	,/*Textinfo*/
	/*	72	*/	NULL	,/*Checksum_0x246*/
	/*	73	*/	NULL	,/*IPM_DCLC_manualfeedback*/
	/*	74	*/	NULL	,/*IPM_ELKSts*/
	/*	75	*/	NULL	,/*IPM_DCLCSts*/
	/*	76	*/	Rte_COMCbkRxTOut_EPS_S_WarningLampYellow_e5742092	,/*EPS_S_WarningLampYellow*/
	/*	77	*/	Rte_COMCbkRxTOut_EPS_S_SafeLampRed_e5742092	,/*EPS_S_SafeLampRed*/
	/*	78	*/	NULL	,/*Rolling_counter_0x260*/
	/*	79	*/	NULL	,/*Checksum_0x260*/
	/*	80	*/	Rte_COMCbkRxTOut_PAM_ChimeCmdSoundStatus_49f5ddcc	,/*PAM_ChimeCmdSoundStatus*/
	/*	81	*/	Rte_COMCbkRxTOut_PAM_RearSysTemWorkSts_49f5ddcc	,/*PAM_RearSysTemWorkSts*/
	/*	82	*/	Rte_COMCbkRxTOut_PAM_FrontSysTemWorkSts_49f5ddcc	,/*PAM_FrontSysTemWorkSts*/
	/*	83	*/	Rte_COMCbkRxTOut_PAM_ChimeCmdSoundCadence_49f5ddcc	,/*PAM_ChimeCmdSoundCadence*/
	/*	84	*/	NULL	,/*LAEB_BrkgReqVal*/
	/*	85	*/	NULL	,/*LAEB_BrkgReq*/
	/*	86	*/	NULL	,/*LAEB_DistanceToCollision*/
	/*	87	*/	NULL	,/*LAEB_SpeakReq*/
	/*	88	*/	NULL	,/*LAEB_WorkSts*/
	/*	89	*/	NULL	,/*Checksum_0x274*/
	/*	90	*/	NULL	,/*Rolling_counter_0x274*/
	/*	91	*/	NULL	,/*LAEB_LedReq*/
	/*	92	*/	Rte_COMCbkRxTOut_SOD_LCA_warningReqRight_a75280f1	,/*SOD_LCA_warningReqRight*/
	/*	93	*/	Rte_COMCbkRxTOut_SOD_DOA_warningReqRightRear_a75280f1	,/*SOD_DOA_warningReqRightRear*/
	/*	94	*/	Rte_COMCbkRxTOut_SOD_DOA_warningReqRightFront_a75280f1	,/*SOD_DOA_warningReqRightFront*/
	/*	95	*/	Rte_COMCbkRxTOut_SOD_CTA_warningReqRight_a75280f1	,/*SOD_CTA_warningReqRight*/
	/*	96	*/	Rte_COMCbkRxTOut_SOD_BLIS_display_a75280f1	,/*SOD_BLIS_display*/
	/*	97	*/	Rte_COMCbkRxTOut_SOD_LCA_warningReqLeft_a75280f1	,/*SOD_LCA_warningReqLeft*/
	/*	98	*/	Rte_COMCbkRxTOut_SOD_DOA_warningReqLeftRear_a75280f1	,/*SOD_DOA_warningReqLeftRear*/
	/*	99	*/	Rte_COMCbkRxTOut_SOD_DOA_warningReqLeftFront_a75280f1	,/*SOD_DOA_warningReqLeftFront*/
	/*	100	*/	Rte_COMCbkRxTOut_SOD_CTA_warningReqLeft_a75280f1	,/*SOD_CTA_warningReqLeft*/
	/*	101	*/	Rte_COMCbkRxTOut_DOA_OFFTelltale_a75280f1	,/*DOA_OFFTelltale*/
	/*	102	*/	Rte_COMCbkRxTOut_CTA_OFFTelltale_a75280f1	,/*CTA_OFFTelltale*/
	/*	103	*/	Rte_COMCbkRxTOut_SODLCA_OFFTelltale_a75280f1	,/*SODLCA_OFFTelltale*/
	/*	104	*/	NULL	,/*IPM_LedtLine_dx_start*/
	/*	105	*/	NULL	,/*IPM_LeftLine_dy*/
	/*	106	*/	NULL	,/*IPM_LeftLine_dx_lookhead*/
	/*	107	*/	NULL	,/*IPM_LeftLine_hor_curve*/
	/*	108	*/	NULL	,/*IPM_LeftLine_yawangle*/
	/*	109	*/	Rte_COMCbkRxTOut_MRR_F_Object_dx_49708b05	,/*MRR_F_Object_dx*/
	/*	110	*/	Rte_COMCbkRxTOut_MRR_F_Object_dy_49708b05	,/*MRR_F_Object_dy*/
	/*	111	*/	Rte_COMCbkRxTOut_MRR_F_Obj_0x_class_49708b05	,/*MRR_F_Obj_0x_class*/
	/*	112	*/	NULL	,/*MRR_FF_Object_dx*/
	/*	113	*/	NULL	,/*MRR_FF_Object_dy*/
	/*	114	*/	NULL	,/*MRR_FF_Obj_0x_class*/
	/*	115	*/	NULL	,/*MRR_FFTargrtDetection*/
	/*	116	*/	NULL	,/*MRR_PedDetection*/
	/*	117	*/	Rte_COMCbkRxTOut_IPM_LaneAssit_LeftVisualization_32f79b14	,/*IPM_LaneAssit_LeftVisualization*/
	/*	118	*/	NULL	,/*IPM_LeftLine_Type*/
	/*	119	*/	NULL	,/*IPM_LeftLine_Color*/
	/*	120	*/	NULL	,/*IPM_leftLeftLine_Type*/
	/*	121	*/	NULL	,/*IPM_leftLeftLine_Color*/
	/*	122	*/	NULL	,/*IPM_leftleftLine_dy*/
	/*	123	*/	NULL	,/*IPM_leftleftLine_hor_curve*/
	/*	124	*/	NULL	,/*IPM_leftleftLine_yawangle*/
	/*	125	*/	NULL	,/*IPM_leftleftLine_cur_alteration*/
	/*	126	*/	Rte_COMCbkRxTOut_BCM_DoorStsRearRi_0edb943f	,/*BCM_DoorStsRearRi*/
	/*	127	*/	Rte_COMCbkRxTOut_BCM_DoorStsRearLe_0edb943f	,/*BCM_DoorStsRearLe*/
	/*	128	*/	Rte_COMCbkRxTOut_BCM_DoorStsFrntRi_0edb943f	,/*BCM_DoorStsFrntRi*/
	/*	129	*/	Rte_COMCbkRxTOut_BCM_DoorStsFrntLe_0edb943f	,/*BCM_DoorStsFrntLe*/
	/*	130	*/	NULL	,/*BCM_DoorLockStsRearRi*/
	/*	131	*/	NULL	,/*BCM_DoorLockStsRearLe*/
	/*	132	*/	NULL	,/*BCM_DoorLockStsFrntRi*/
	/*	133	*/	NULL	,/*BCM_DoorLockStsFrntLe*/
	/*	134	*/	NULL	,/*BCM_AntiTheftSts*/
	/*	135	*/	NULL	,/*BCM_LockUnlockFeedback*/
	/*	136	*/	NULL	,/*BCM_DoorLockStsTrunk*/
	/*	137	*/	Rte_COMCbkRxTOut_BCM_DoorStsTrunk_0edb943f	,/*BCM_DoorStsTrunk*/
	/*	138	*/	NULL	,/*BCM_TrunkDoorPreUnlockSts*/
	/*	139	*/	Rte_COMCbkRxTOut_BCM_EnginehoodSts_0edb943f	,/*BCM_EnginehoodSts*/
	/*	140	*/	NULL	,/*BCM_Rolling_counter_0x310*/
	/*	141	*/	Rte_COMCbkRxTOut_BCM_TurnIndicatorSts_0edb943f	,/*BCM_TurnIndicatorSts*/
	/*	142	*/	NULL	,/*BCM_Checksum_0x310*/
	/*	143	*/	NULL	,/*BCM_OutsideTempDig*/
	/*	144	*/	Rte_COMCbkRxTOut_BCM_BrakeFluidSts_abc8cd44	,/*BCM_BrakeFluidSts*/
	/*	145	*/	Rte_COMCbkRxTOut_BCM_OutsideTemp_abc8cd44	,/*BCM_OutsideTemp*/
	/*	146	*/	NULL	,/*BCM_Reverse_gear*/
	/*	147	*/	NULL	,/*BCM_SS_EnableSts*/
	/*	148	*/	NULL	,/*BCM_Rollingcounter_0x313*/
	/*	149	*/	NULL	,/*BCM_Checksum_0x313*/
	/*	150	*/	Rte_COMCbkRxTOut_BCM_BGLLumLvlSettingStatus_a1dcf71c	,/*BCM_BGLLumLvlSettingStatus*/
	/*	151	*/	Rte_COMCbkRxTOut_BCM_FrntFogLmpSts_52444383	,/*BCM_FrntFogLmpSts*/
	/*	152	*/	Rte_COMCbkRxTOut_BCM_PosLmpSts_52444383	,/*BCM_PosLmpSts*/
	/*	153	*/	Rte_COMCbkRxTOut_BCM_LowBeamSts_52444383	,/*BCM_LowBeamSts*/
	/*	154	*/	Rte_COMCbkRxTOut_BCM_HighBeamSts_52444383	,/*BCM_HighBeamSts*/
	/*	155	*/	NULL	,/*BCM_reversinglightSts*/
	/*	156	*/	NULL	,/*BCM_DayRunningLampSts*/
	/*	157	*/	Rte_COMCbkRxTOut_BCM_RearFogLmpSts_52444383	,/*BCM_RearFogLmpSts*/
	/*	158	*/	NULL	,/*BCM_laserlightSts*/
	/*	159	*/	NULL	,/*BCM_AmbientLightSts*/
	/*	160	*/	NULL	,/*BCM_Highmountedstoplamp*/
	/*	161	*/	NULL	,/*BCM_BrakelightSts*/
	/*	162	*/	Rte_COMCbkRxTOut_BCM_BackHomeSts_52444383	,/*BCM_BackHomeSts*/
	/*	163	*/	NULL	,/*BCM_AutolampSts*/
	/*	164	*/	NULL	,/*BCM_readinglampSts*/
	/*	165	*/	Rte_COMCbkRxTOut_BCM_DayRunningLampDig_52444383	,/*BCM_DayRunningLampDig*/
	/*	166	*/	Rte_COMCbkRxTOut_BCM_BrakelightDig_52444383	,/*BCM_BrakelightDig*/
	/*	167	*/	Rte_COMCbkRxTOut_BCM_reversinglightDig_52444383	,/*BCM_reversinglightDig*/
	/*	168	*/	Rte_COMCbkRxTOut_BCM_TurnIndicatorDig_52444383	,/*BCM_TurnIndicatorDig*/
	/*	169	*/	Rte_COMCbkRxTOut_BCM_RearFogLmpDig_52444383	,/*BCM_RearFogLmpDig*/
	/*	170	*/	Rte_COMCbkRxTOut_BCM_FrntFogLmpDig_52444383	,/*BCM_FrntFogLmpDig*/
	/*	171	*/	Rte_COMCbkRxTOut_BCM_PosLmpDig_52444383	,/*BCM_PosLmpDig*/
	/*	172	*/	Rte_COMCbkRxTOut_BCM_LowBeamDig_52444383	,/*BCM_LowBeamDig*/
	/*	173	*/	NULL	,/*BCM_Rollingcounter_0x318*/
	/*	174	*/	NULL	,/*BCM_Checksum_0x318*/
	/*	175	*/	Rte_COMCbkRxTOut_SWM_Menu_Right_f733f54d	,/*SWM_Menu_Right*/
	/*	176	*/	Rte_COMCbkRxTOut_SWM_Menu_Left_f733f54d	,/*SWM_Menu_Left*/
	/*	177	*/	Rte_COMCbkRxTOut_SWM_Menu_Down_f733f54d	,/*SWM_Menu_Down*/
	/*	178	*/	Rte_COMCbkRxTOut_SWM_Menu_Up_f733f54d	,/*SWM_Menu_Up*/
	/*	179	*/	NULL	,/*Rolling_counter_0x31A*/
	/*	180	*/	Rte_COMCbkRxTOut_SWM_Menu_Return_f733f54d	,/*SWM_Menu_Return*/
	/*	181	*/	Rte_COMCbkRxTOut_SWM_Menu_Confirm_f733f54d	,/*SWM_Menu_Confirm*/
	/*	182	*/	NULL	,/*Checksum_0x31A*/
	/*	183	*/	Rte_COMCbkRxTOut_SWM_ACCtauGapSetPlus_db79ffcb	,/*SWM_ACCtauGapSetPlus*/
	/*	184	*/	Rte_COMCbkRxTOut_SWM_ACCvSetMinus_db79ffcb	,/*SWM_ACCvSetMinus*/
	/*	185	*/	Rte_COMCbkRxTOut_SWM_ACCvSetPlus_db79ffcb	,/*SWM_ACCvSetPlus*/
	/*	186	*/	Rte_COMCbkRxTOut_SWM_ACCResume_db79ffcb	,/*SWM_ACCResume*/
	/*	187	*/	Rte_COMCbkRxTOut_SWM_ACCSet_db79ffcb	,/*SWM_ACCSet*/
	/*	188	*/	Rte_COMCbkRxTOut_SWM_ACCEnableSwitch_db79ffcb	,/*SWM_ACCEnableSwitch*/
	/*	189	*/	Rte_COMCbkRxTOut_SWM_LaneAssistSwitch_db79ffcb	,/*SWM_LaneAssistSwitch*/
	/*	190	*/	Rte_COMCbkRxTOut_SWM_ACCtauGapSetMinus_db79ffcb	,/*SWM_ACCtauGapSetMinus*/
	/*	191	*/	Rte_COMCbkRxTOut_PEPS_PowerMode_9b45c0e5	,/*PEPS_PowerMode*/
	/*	192	*/	Rte_COMCbkRxTOut_PEPS_IMMO_MatchStatus_9b45c0e5	,/*PEPS_IMMO_MatchStatus*/
	/*	193	*/	Rte_COMCbkRxTOut_PEPS_SystemFailStatus_9b45c0e5	,/*PEPS_SystemFailStatus*/
	/*	194	*/	Rte_COMCbkRxTOut_PEPS_ESCL_FailStatus_9b45c0e5	,/*PEPS_ESCL_FailStatus*/
	/*	195	*/	Rte_COMCbkRxTOut_PEPS_SSB_FailStatus_9b45c0e5	,/*PEPS_SSB_FailStatus*/
	/*	196	*/	Rte_COMCbkRxTOut_PEPS_BrakeIndicationWarning_9b45c0e5	,/*PEPS_BrakeIndicationWarning*/
	/*	197	*/	Rte_COMCbkRxTOut_PEPS_NotPNWarning_9b45c0e5	,/*PEPS_NotPNWarning*/
	/*	198	*/	Rte_COMCbkRxTOut_PEPS_DoorOpenNotOFFWarning_9b45c0e5	,/*PEPS_DoorOpenNotOFFWarning*/
	/*	199	*/	Rte_COMCbkRxTOut_PEPS_DoorOpenWarning_9b45c0e5	,/*PEPS_DoorOpenWarning*/
	/*	200	*/	Rte_COMCbkRxTOut_PEPS_KeyBatteryWarning_9b45c0e5	,/*PEPS_KeyBatteryWarning*/
	/*	201	*/	Rte_COMCbkRxTOut_PEPS_KeyOutWarning1_9b45c0e5	,/*PEPS_KeyOutWarning1*/
	/*	202	*/	Rte_COMCbkRxTOut_PEPS_NoKeyFoundWarning_9b45c0e5	,/*PEPS_NoKeyFoundWarning*/
	/*	203	*/	Rte_COMCbkRxTOut_PEPS_KeyReminderWarning_9b45c0e5	,/*PEPS_KeyReminderWarning*/
	/*	204	*/	Rte_COMCbkRxTOut_PEPS_RemainingNumSts_9b45c0e5	,/*PEPS_RemainingNumSts*/
	/*	205	*/	Rte_COMCbkRxTOut_SRS_SBR_PAMsenger_9595b6c2	,/*SRS_SBR_PAMsenger*/
	/*	206	*/	Rte_COMCbkRxTOut_SRS_SBR_Driver_9595b6c2	,/*SRS_SBR_Driver*/
	/*	207	*/	Rte_COMCbkRxTOut_SRS_AirBagFailSts_9595b6c2	,/*SRS_AirBagFailSts*/
	/*	208	*/	Rte_COMCbkRxTOut_SRS_SBR_SecondRowRight_9595b6c2	,/*SRS_SBR_SecondRowRight*/
	/*	209	*/	Rte_COMCbkRxTOut_SRS_SBR_SecondRowMid_9595b6c2	,/*SRS_SBR_SecondRowMid*/
	/*	210	*/	Rte_COMCbkRxTOut_SRS_SBR_SecondRowLeft_9595b6c2	,/*SRS_SBR_SecondRowLeft*/
	/*	211	*/	NULL	,/*Rolling_counter_0x350*/
	/*	212	*/	NULL	,/*Checksum_0x350*/
	/*	213	*/	Rte_COMCbkRxTOut_TPMS_LF_Pressure_c030f382	,/*TPMS_LF_Pressure*/
	/*	214	*/	Rte_COMCbkRxTOut_TPMS_RF_Pressure_c030f382	,/*TPMS_RF_Pressure*/
	/*	215	*/	Rte_COMCbkRxTOut_TPMS_RR_Pressure_c030f382	,/*TPMS_RR_Pressure*/
	/*	216	*/	Rte_COMCbkRxTOut_TPMS_LR_Pressure_c030f382	,/*TPMS_LR_Pressure*/
	/*	217	*/	Rte_COMCbkRxTOut_TPMS_Tire_Temperature_c030f382	,/*TPMS_Tire_Temperature*/
	/*	218	*/	Rte_COMCbkRxTOut_TPMS_LF_Pressure_Warning_c030f382	,/*TPMS_LF_Pressure_Warning*/
	/*	219	*/	Rte_COMCbkRxTOut_TPMS_RF_Pressure_Warning_c030f382	,/*TPMS_RF_Pressure_Warning*/
	/*	220	*/	Rte_COMCbkRxTOut_TPMS_System_Status_c030f382	,/*TPMS_System_Status*/
	/*	221	*/	Rte_COMCbkRxTOut_TPMS_RR_Pressure_Warning_c030f382	,/*TPMS_RR_Pressure_Warning*/
	/*	222	*/	Rte_COMCbkRxTOut_TPMS_LR_Pressure_Warning_c030f382	,/*TPMS_LR_Pressure_Warning*/
	/*	223	*/	Rte_COMCbkRxTOut_TPMS_Temperature_Warning_c030f382	,/*TPMS_Temperature_Warning*/
	/*	224	*/	NULL	,/*TPMS_resrved*/
	/*	225	*/	Rte_COMCbkRxTOut_Tire_Position_c030f382	,/*Tire_Position*/
	/*	226	*/	Rte_COMCbkRxTOut_TPMS_Lamp_Status_c030f382	,/*TPMS_Lamp_Status*/
	/*	227	*/	Rte_COMCbkRxTOut_EMS_Fuelcounter_daed4b4e	,/*EMS_Fuelcounter*/
	/*	228	*/	Rte_COMCbkRxTOut_EMS_FuelconsumptionInst_daed4b4e	,/*EMS_FuelconsumptionInst*/
	/*	229	*/	Rte_COMCbkRxTOut_EMS_MIL_daed4b4e	,/*EMS_MIL*/
	/*	230	*/	Rte_COMCbkRxTOut_EMS_SVS_daed4b4e	,/*EMS_SVS*/
	/*	231	*/	Rte_COMCbkRxTOut_EMS_StartStopStatus_daed4b4e	,/*EMS_StartStopStatus*/
	/*	232	*/	Rte_COMCbkRxTOut_EMS_GasPrtcWarn_G_Rq_daa19a1a	,/*EMS_GasPrtcWarn_G_Rq*/
	/*	233	*/	NULL	,/*MP5_AudioStatus*/
	/*	234	*/	NULL	,/*MP5_EnergyFlow*/
	/*	235	*/	NULL	,/*MP5_SetMultiButton*/
	/*	236	*/	Rte_COMCbkRxTOut_MP5_BSDSoundSwitchSts_c90244fe	,/*MP5_BSDSoundSwitchSts*/
	/*	237	*/	Rte_COMCbkRxTOut_MP5_NavStatus_c90244fe	,/*MP5_NavStatus*/
	/*	238	*/	Rte_COMCbkRxTOut_MP5_NavICON_0f6d4d79	,/*MP5_NavICON*/
	/*	239	*/	Rte_COMCbkRxTOut_MP5_ROUTE_REMAIN_DIS_0f6d4d79	,/*MP5_ROUTE_REMAIN_DIS*/
	/*	240	*/	NULL	,/*MP5_ALModeSetting*/
	/*	241	*/	NULL	,/*MP5_ALStartAroundSetting*/
	/*	242	*/	Rte_COMCbkRxTOut_TCU_EmergencyTowingSts_94ca6b54	,/*TCU_EmergencyTowingSts*/
	/*	243	*/	Rte_COMCbkRxTOut_TrnSrvcRqd_B_Rq_94ca6b54	,/*TrnSrvcRqd_B_Rq*/
	/*	244	*/	Rte_COMCbkRxTOut_TCU_GearPFault_94ca6b54	,/*TCU_GearPFault*/
	/*	245	*/	Rte_COMCbkRxTOut_TCU_WarningMessage_94ca6b54	,/*TCU_WarningMessage*/
	/*	246	*/	Rte_COMCbkRxTOut_TCU_DrvShiftAllwCondRmd_94ca6b54	,/*TCU_DrvShiftAllwCondRmd*/
	/*	247	*/	NULL	,/*MRR_L_Object_dx*/
	/*	248	*/	NULL	,/*MRR_L_Object_dy*/
	/*	249	*/	NULL	,/*MRR_L_Obj_0x_class*/
	/*	250	*/	NULL	,/*MRR_R_Object_dx*/
	/*	251	*/	NULL	,/*MRR_R_Object_dy*/
	/*	252	*/	NULL	,/*MRR_R_Obj_0x_class*/
	/*	253	*/	NULL	,/*MRR_LeftTargrtDetection*/
	/*	254	*/	NULL	,/*MRR_RightTargrtDetection*/
	/*	255	*/	NULL	,/*IPM_RightLine_dx_start*/
	/*	256	*/	NULL	,/*IPM_RightLine_dy*/
	/*	257	*/	NULL	,/*IPM_RightLine_dx_lookhead*/
	/*	258	*/	NULL	,/*IPM_RightLine_hor_curve*/
	/*	259	*/	NULL	,/*IPM_RightLine_yawangle*/
	/*	260	*/	Rte_COMCbkRxTOut_IPM_LaneAssit_RightVisualization_32f79b14	,/*IPM_LaneAssit_RightVisualization*/
	/*	261	*/	NULL	,/*IPM_rightRighLine_Type*/
	/*	262	*/	NULL	,/*IPM_RighLine_Color*/
	/*	263	*/	NULL	,/*IPM_RighLine_Type*/
	/*	264	*/	NULL	,/*IPM_RighrightLine_Color*/
	/*	265	*/	NULL	,/*IPM_rightRightLine_dy*/
	/*	266	*/	NULL	,/*IPM_rightRightLine_hor_curve*/
	/*	267	*/	NULL	,/*IPM_rightRightLine_yawangle*/
	/*	268	*/	NULL	,/*IPM_RightLine_cur_alteration*/
	/*	269	*/	NULL	,/*AVM_displaytype*/
	/*	270	*/	NULL	,/*AVM_Status*/
	/*	271	*/	NULL	,/*AVM_Guide_line_info*/
	/*	272	*/	NULL	,/*AVM_Switch*/
	/*	273	*/	Rte_COMCbkRxTOut_MP5_ICMenuShift_Button_046cad19	,/*MP5_ICMenuShift_Button*/
	/*	274	*/	Rte_COMCbkRxTOut_MP5_ICMenuActive_Button_046cad19	,/*MP5_ICMenuActive_Button*/
	/*	275	*/	Rte_COMCbkRxTOut_MP5_AlarmStatus_046cad19	,/*MP5_AlarmStatus*/
	/*	276	*/	Rte_COMCbkRxTOut_MP5_AlarmOrNot_046cad19	,/*MP5_AlarmOrNot*/
	/*	277	*/	Rte_COMCbkRxTOut_MP5_ICMenu_Cmd_34a683c9	,/*MP5_ICMenu_Cmd*/
	/*	278	*/	Rte_COMCbkRxTOut_Nav_Sts_0f6324b4	,/*Nav_Sts*/
	/*	279	*/	NULL	,/*MP5_BGLLumLvlSetting*/
	/*	280	*/	NULL	,/*WACM_WirelessChargerStatus*/
	/*	281	*/	Rte_COMCbkRxTOut_TBOX_Year_4e88e95a	,/*TBOX_Year*/
	/*	282	*/	Rte_COMCbkRxTOut_TBOX_Month_4e88e95a	,/*TBOX_Month*/
	/*	283	*/	Rte_COMCbkRxTOut_TBOX_Date_4e88e95a	,/*TBOX_Date*/
	/*	284	*/	Rte_COMCbkRxTOut_TBOX_Hour_4e88e95a	,/*TBOX_Hour*/
	/*	285	*/	Rte_COMCbkRxTOut_TBOX_Minute_4e88e95a	,/*TBOX_Minute*/
	/*	286	*/	Rte_COMCbkRxTOut_TBOX_Second_4e88e95a	,/*TBOX_Second*/
	/*	287	*/	Rte_COMCbkRxTOut_TBOX_ReTime_4e88e95a	,/*TBOX_ReTime*/
	/*	288	*/	Rte_COMCbkRxTOut_BCM_LoadManageLevel_00b00241	,/*BCM_LoadManageLevel*/
	/*	289	*/	Rte_COMCbkRxTOut_BCM_CarModeIndicator_00b00241	,/*BCM_CarModeIndicator*/
	/*	290	*/	Rte_COMCbkRxTOut_BCM_CarMode_00b00241	,/*BCM_CarMode*/
	/*	291	*/	NULL	,/*AFS_WorkSts*/
	/*	292	*/	Rte_COMCbkRxTOut_SCMM_HMIDisplay_8c54f0fa	,/*SCMM_HMIDisplay*/
	/*	293	*/	Rte_COMCbkRxTOut_EMS_BackupOdometer_63950623	,/*EMS_BackupOdometer*/
  };
  #endif


  #if (CCL_RX_INVINDICATION_API == STD_ON)
  /**********************************************************************************************************************
    Ccl_CbkRxInvFuncPtr
  **********************************************************************************************************************/
  /**
    \var    Ccl_CbkRxInvFuncPtr
    \brief  Function pointer table containing configured Rx Indication notifications for signals and signal groups.*/

  CONST(CclCbkInvType, CCL_CONST) Can_Ccl_CbkRxInvFuncPtr[Can_Ccl_Rx_Num_RxInv_Ind] = {
    /* Index    CbkRxAckFuncPtr                        */
    /*     0 */ NULL
  };
  #endif


  /**********************************************************************************************************************
    Can_Ccl_Channel0_RxNotifFuncPtr
  **********************************************************************************************************************/
  CONST(Ccl_RxNotifFuncInfo, CCL_CONST) Can_Ccl_RxNotifFuncPtr[Can_Ccl_Rx_Num_Signals] = {
        /* Index      RxAckIndex          RxToutIndex         RxInvIndex       */
  { /*  0  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*SCU_faultwarning*/
  { /*  1  */    CanCclRxHndlCh0_EMS_EngCoolanTemp_267,  CanCclRxHndlCh0_EMS_EngCoolanTemp_267, CanCclRxHndlCh0_EMS_EngCoolanTemp_267   },/*EMS_EngCoolanTemp*/
  { /*  2  */    CanCclRxHndlCh0_EMS_EngOperationStatus_267,  CanCclRxHndlCh0_EMS_EngOperationStatus_267, CanCclRxHndlCh0_EMS_EngOperationStatus_267   },/*EMS_EngOperationStatus*/
  { /*  3  */    CanCclRxHndlCh0_EMS_BatteryVoltageError_267,  CanCclRxHndlCh0_EMS_BatteryVoltageError_267, CanCclRxHndlCh0_EMS_BatteryVoltageError_267   },/*EMS_BatteryVoltageError*/
  { /*  4  */    CanCclRxHndlCh0_EMS_EngSpeed_267,  CanCclRxHndlCh0_EMS_EngSpeed_267, CanCclRxHndlCh0_EMS_EngSpeed_267   },/*EMS_EngSpeed*/
  { /*  5  */    CanCclRxHndlCh0_EMS_StartStopMessage_267,  CanCclRxHndlCh0_EMS_StartStopMessage_267, CanCclRxHndlCh0_EMS_StartStopMessage_267   },/*EMS_StartStopMessage*/
  { /*  6  */    CanCclRxHndlCh0_TCU_DisplayGear_291,  CanCclRxHndlCh0_TCU_DisplayGear_291, CanCclRxHndlCh0_TCU_DisplayGear_291   },/*TCU_DisplayGear*/
  { /*  7  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*TCU_GearSelectorReq*/
  { /*  8  */    CanCclRxHndlCh0_TCU_StGearMode_291,  CanCclRxHndlCh0_TCU_StGearMode_291, CanCclRxHndlCh0_TCU_StGearMode_291   },/*TCU_StGearMode*/
  { /*  9  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*TCU_Status_AliveCounter0x123*/
  { /*  10  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*TCU_Status_Checksum0x123*/
  { /*  11  */    CanCclRxHndlCh0_EMS_TargCruiseSpeed_337,  CanCclRxHndlCh0_EMS_TargCruiseSpeed_337, CanCclRxHndlCh0_EMS_TargCruiseSpeed_337   },/*EMS_TargCruiseSpeed*/
  { /*  12  */    CanCclRxHndlCh0_EMS_CruiseControlStatus_337,  CanCclRxHndlCh0_EMS_CruiseControlStatus_337, CanCclRxHndlCh0_EMS_CruiseControlStatus_337   },/*EMS_CruiseControlStatus*/
  { /*  13  */    CanCclRxHndlCh0_TBOX_ECALLFlt_418,  CanCclRxHndlCh0_TBOX_ECALLFlt_418, CanCclRxHndlCh0_TBOX_ECALLFlt_418   },/*TBOX_ECALLFlt*/
  { /*  14  */    CanCclRxHndlCh0_PEPS_Remotestartstatus_421,  CanCclRxHndlCh0_PEPS_Remotestartstatus_421, CanCclRxHndlCh0_PEPS_Remotestartstatus_421   },/*PEPS_Remotestartstatus*/
  { /*  15  */    CanCclRxHndlCh0_ABS_WhlMilgFrntLe_545,  CanCclRxHndlCh0_ABS_WhlMilgFrntLe_545, CanCclRxHndlCh0_ABS_WhlMilgFrntLe_545   },/*ABS_WhlMilgFrntLe*/
  { /*  16  */    CanCclRxHndlCh0_ABS_WhlMilgFrntRi_545,  CanCclRxHndlCh0_ABS_WhlMilgFrntRi_545, CanCclRxHndlCh0_ABS_WhlMilgFrntRi_545   },/*ABS_WhlMilgFrntRi*/
  { /*  17  */    CanCclRxHndlCh0_ABS_VehSpdLgt_545,  CanCclRxHndlCh0_ABS_VehSpdLgt_545, CanCclRxHndlCh0_ABS_VehSpdLgt_545   },/*ABS_VehSpdLgt*/
  { /*  18  */    CanCclRxHndlCh0_ABS_EbdFlgFlt_545,  CanCclRxHndlCh0_ABS_EbdFlgFlt_545, CanCclRxHndlCh0_ABS_EbdFlgFlt_545   },/*ABS_EbdFlgFlt*/
  { /*  19  */    CanCclRxHndlCh0_ABS_AbsFlgFlt_545,  CanCclRxHndlCh0_ABS_AbsFlgFlt_545, CanCclRxHndlCh0_ABS_AbsFlgFlt_545   },/*ABS_AbsFlgFlt*/
  { /*  20  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*ABS_RollingCounter_0x221*/
  { /*  21  */    CanCclRxHndlCh0_ABS_WhlMilgFrntLeStatus_545,  CanCclRxHndlCh0_ABS_WhlMilgFrntLeStatus_545, CanCclRxHndlCh0_ABS_WhlMilgFrntLeStatus_545   },/*ABS_WhlMilgFrntLeStatus*/
  { /*  22  */    CanCclRxHndlCh0_ABS_WhlMilgFrntRiStatus_545,  CanCclRxHndlCh0_ABS_WhlMilgFrntRiStatus_545, CanCclRxHndlCh0_ABS_WhlMilgFrntRiStatus_545   },/*ABS_WhlMilgFrntRiStatus*/
  { /*  23  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*ABS_Checksum_0x221*/
  { /*  24  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*ESP_HHCAvailable*/
  { /*  25  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*ABS_HAZActive*/
  { /*  26  */    CanCclRxHndlCh0_ESP_EPBStatus_579,  CanCclRxHndlCh0_ESP_EPBStatus_579, CanCclRxHndlCh0_ESP_EPBStatus_579   },/*ESP_EPBStatus*/
  { /*  27  */    CanCclRxHndlCh0_ESP_EPBErrorStatus_579,  CanCclRxHndlCh0_ESP_EPBErrorStatus_579, CanCclRxHndlCh0_ESP_EPBErrorStatus_579   },/*ESP_EPBErrorStatus*/
  { /*  28  */    CanCclRxHndlCh0_ESP_HDCAvailable_579,  CanCclRxHndlCh0_ESP_HDCAvailable_579, CanCclRxHndlCh0_ESP_HDCAvailable_579   },/*ESP_HDCAvailable*/
  { /*  29  */    CanCclRxHndlCh0_ESP_HDCActive_579,  CanCclRxHndlCh0_ESP_HDCActive_579, CanCclRxHndlCh0_ESP_HDCActive_579   },/*ESP_HDCActive*/
  { /*  30  */    CanCclRxHndlCh0_ESP_CdpAvailable_579,  CanCclRxHndlCh0_ESP_CdpAvailable_579, CanCclRxHndlCh0_ESP_CdpAvailable_579   },/*ESP_CdpAvailable*/
  { /*  31  */    CanCclRxHndlCh0_ESP_EPBWarningMessage3_579,  CanCclRxHndlCh0_ESP_EPBWarningMessage3_579, CanCclRxHndlCh0_ESP_EPBWarningMessage3_579   },/*ESP_EPBWarningMessage3*/
  { /*  32  */    CanCclRxHndlCh0_ESP_EPBWarningMessage2_579,  CanCclRxHndlCh0_ESP_EPBWarningMessage2_579, CanCclRxHndlCh0_ESP_EPBWarningMessage2_579   },/*ESP_EPBWarningMessage2*/
  { /*  33  */    CanCclRxHndlCh0_ESP_EPBWarningMessage1_579,  CanCclRxHndlCh0_ESP_EPBWarningMessage1_579, CanCclRxHndlCh0_ESP_EPBWarningMessage1_579   },/*ESP_EPBWarningMessage1*/
  { /*  34  */    CanCclRxHndlCh0_ESP_AVHWarningMessage_579,  CanCclRxHndlCh0_ESP_AVHWarningMessage_579, CanCclRxHndlCh0_ESP_AVHWarningMessage_579   },/*ESP_AVHWarningMessage*/
  { /*  35  */    CanCclRxHndlCh0_ESP_AvhActive_579,  CanCclRxHndlCh0_ESP_AvhActive_579, CanCclRxHndlCh0_ESP_AvhActive_579   },/*ESP_AvhActive*/
  { /*  36  */    CanCclRxHndlCh0_ESP_AvhStandby_579,  CanCclRxHndlCh0_ESP_AvhStandby_579, CanCclRxHndlCh0_ESP_AvhStandby_579   },/*ESP_AvhStandby*/
  { /*  37  */    CanCclRxHndlCh0_ESP_AvhAvabliable_579,  CanCclRxHndlCh0_ESP_AvhAvabliable_579, CanCclRxHndlCh0_ESP_AvhAvabliable_579   },/*ESP_AvhAvabliable*/
  { /*  38  */    CanCclRxHndlCh0_ESP_VdcFlgFlt_579,  CanCclRxHndlCh0_ESP_VdcFlgFlt_579, CanCclRxHndlCh0_ESP_VdcFlgFlt_579   },/*ESP_VdcFlgFlt*/
  { /*  39  */    CanCclRxHndlCh0_ESP_TcsFlgFlt_579,  CanCclRxHndlCh0_ESP_TcsFlgFlt_579, CanCclRxHndlCh0_ESP_TcsFlgFlt_579   },/*ESP_TcsFlgFlt*/
  { /*  40  */    CanCclRxHndlCh0_ESP_ESPInfoLamp_579,  CanCclRxHndlCh0_ESP_ESPInfoLamp_579, CanCclRxHndlCh0_ESP_ESPInfoLamp_579   },/*ESP_ESPInfoLamp*/
  { /*  41  */    CanCclRxHndlCh0_ESP_EspEnableSts_579,  CanCclRxHndlCh0_ESP_EspEnableSts_579, CanCclRxHndlCh0_ESP_EspEnableSts_579   },/*ESP_EspEnableSts*/
  { /*  42  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*ESP_RollingCounter_0x243*/
  { /*  43  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*ESP_Checksum_0x243*/
  { /*  44  */    CanCclRxHndlCh0_IPM_LaneAssitType_581,  CanCclRxHndlCh0_IPM_LaneAssitType_581, CanCclRxHndlCh0_IPM_LaneAssitType_581   },/*IPM_LaneAssitType*/
  { /*  45  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_LaneAssit_WarningVibration*/
  { /*  46  */    CanCclRxHndlCh0_IPM_LaneAssit_WarningAudio_581,  CanCclRxHndlCh0_IPM_LaneAssit_WarningAudio_581, CanCclRxHndlCh0_IPM_LaneAssit_WarningAudio_581   },/*IPM_LaneAssit_WarningAudio*/
  { /*  47  */    CanCclRxHndlCh0_IPM_LaneAssit_LeftVisualization_581,  CanCclRxHndlCh0_IPM_LaneAssit_LeftVisualization_581, CanCclRxHndlCh0_IPM_LaneAssit_LeftVisualization_581   },/*IPM_LaneAssit_LeftVisualization*/
  { /*  48  */    CanCclRxHndlCh0_IPM_LaneAssit_RightVisualization_581,  CanCclRxHndlCh0_IPM_LaneAssit_RightVisualization_581, CanCclRxHndlCh0_IPM_LaneAssit_RightVisualization_581   },/*IPM_LaneAssit_RightVisualization*/
  { /*  49  */    CanCclRxHndlCh0_IPM_SLASpdlimitUnits_581,  CanCclRxHndlCh0_IPM_SLASpdlimitUnits_581, CanCclRxHndlCh0_IPM_SLASpdlimitUnits_581   },/*IPM_SLASpdlimitUnits*/
  { /*  50  */    CanCclRxHndlCh0_IPM_SLAState_581,  CanCclRxHndlCh0_IPM_SLAState_581, CanCclRxHndlCh0_IPM_SLAState_581   },/*IPM_SLAState*/
  { /*  51  */    CanCclRxHndlCh0_IPM_LaneAssit_Status_581,  CanCclRxHndlCh0_IPM_LaneAssit_Status_581, CanCclRxHndlCh0_IPM_LaneAssit_Status_581   },/*IPM_LaneAssit_Status*/
  { /*  52  */    CanCclRxHndlCh0_IPM_SLASpdlimit_581,  CanCclRxHndlCh0_IPM_SLASpdlimit_581, CanCclRxHndlCh0_IPM_SLASpdlimit_581   },/*IPM_SLASpdlimit*/
  { /*  53  */    CanCclRxHndlCh0_IPM_HMA_Status_581,  CanCclRxHndlCh0_IPM_HMA_Status_581, CanCclRxHndlCh0_IPM_HMA_Status_581   },/*IPM_HMA_Status*/
  { /*  54  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_DDD_IndexStatus*/
  { /*  55  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_DDD_WarningLevel*/
  { /*  56  */    CanCclRxHndlCh0_IPM_LaneAssit_HandsonReq_581,  CanCclRxHndlCh0_IPM_LaneAssit_HandsonReq_581, CanCclRxHndlCh0_IPM_LaneAssit_HandsonReq_581   },/*IPM_LaneAssit_HandsonReq*/
  { /*  57  */    CanCclRxHndlCh0_vSetDis_582,  CanCclRxHndlCh0_vSetDis_582, CanCclRxHndlCh0_vSetDis_582   },/*vSetDis*/
  { /*  58  */    CanCclRxHndlCh0_ObjValid_582,  CanCclRxHndlCh0_ObjValid_582, CanCclRxHndlCh0_ObjValid_582   },/*ObjValid*/
  { /*  59  */    CanCclRxHndlCh0_TauGapSet_582,  CanCclRxHndlCh0_TauGapSet_582, CanCclRxHndlCh0_TauGapSet_582   },/*TauGapSet*/
  { /*  60  */    CanCclRxHndlCh0_dxTarObj_582,  CanCclRxHndlCh0_dxTarObj_582, CanCclRxHndlCh0_dxTarObj_582   },/*dxTarObj*/
  { /*  61  */    CanCclRxHndlCh0_ACCHMI_Mode_582,  CanCclRxHndlCh0_ACCHMI_Mode_582, CanCclRxHndlCh0_ACCHMI_Mode_582   },/*ACCHMI_Mode*/
  { /*  62  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*ACCFailInfo*/
  { /*  63  */    CanCclRxHndlCh0_TakeOverReq_582,  CanCclRxHndlCh0_TakeOverReq_582, CanCclRxHndlCh0_TakeOverReq_582   },/*TakeOverReq*/
  { /*  64  */    CanCclRxHndlCh0_AEB_STATE_582,  CanCclRxHndlCh0_AEB_STATE_582, CanCclRxHndlCh0_AEB_STATE_582   },/*AEB_STATE*/
  { /*  65  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*ACC_Startstop_infor*/
  { /*  66  */    CanCclRxHndlCh0_PCW_preWarning_582,  CanCclRxHndlCh0_PCW_preWarning_582, CanCclRxHndlCh0_PCW_preWarning_582   },/*PCW_preWarning*/
  { /*  67  */    CanCclRxHndlCh0_PCW_latentWarning_582,  CanCclRxHndlCh0_PCW_latentWarning_582, CanCclRxHndlCh0_PCW_latentWarning_582   },/*PCW_latentWarning*/
  { /*  68  */    CanCclRxHndlCh0_PCW_STATE_582,  CanCclRxHndlCh0_PCW_STATE_582, CanCclRxHndlCh0_PCW_STATE_582   },/*PCW_STATE*/
  { /*  69  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*Obj_Speed*/
  { /*  70  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*Rolling_counter_0x246*/
  { /*  71  */    CanCclRxHndlCh0_Textinfo_582,  CanCclRxHndlCh0_Textinfo_582, CanCclRxHndlCh0_Textinfo_582   },/*Textinfo*/
  { /*  72  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*Checksum_0x246*/
  { /*  73  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_DCLC_manualfeedback*/
  { /*  74  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_ELKSts*/
  { /*  75  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_DCLCSts*/
  { /*  76  */    CanCclRxHndlCh0_EPS_S_WarningLampYellow_608,  CanCclRxHndlCh0_EPS_S_WarningLampYellow_608, CanCclRxHndlCh0_EPS_S_WarningLampYellow_608   },/*EPS_S_WarningLampYellow*/
  { /*  77  */    CanCclRxHndlCh0_EPS_S_SafeLampRed_608,  CanCclRxHndlCh0_EPS_S_SafeLampRed_608, CanCclRxHndlCh0_EPS_S_SafeLampRed_608   },/*EPS_S_SafeLampRed*/
  { /*  78  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*Rolling_counter_0x260*/
  { /*  79  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*Checksum_0x260*/
  { /*  80  */    CanCclRxHndlCh0_PAM_ChimeCmdSoundStatus_625,  CanCclRxHndlCh0_PAM_ChimeCmdSoundStatus_625, CanCclRxHndlCh0_PAM_ChimeCmdSoundStatus_625   },/*PAM_ChimeCmdSoundStatus*/
  { /*  81  */    CanCclRxHndlCh0_PAM_RearSysTemWorkSts_625,  CanCclRxHndlCh0_PAM_RearSysTemWorkSts_625, CanCclRxHndlCh0_PAM_RearSysTemWorkSts_625   },/*PAM_RearSysTemWorkSts*/
  { /*  82  */    CanCclRxHndlCh0_PAM_FrontSysTemWorkSts_625,  CanCclRxHndlCh0_PAM_FrontSysTemWorkSts_625, CanCclRxHndlCh0_PAM_FrontSysTemWorkSts_625   },/*PAM_FrontSysTemWorkSts*/
  { /*  83  */    CanCclRxHndlCh0_PAM_ChimeCmdSoundCadence_625,  CanCclRxHndlCh0_PAM_ChimeCmdSoundCadence_625, CanCclRxHndlCh0_PAM_ChimeCmdSoundCadence_625   },/*PAM_ChimeCmdSoundCadence*/
  { /*  84  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*LAEB_BrkgReqVal*/
  { /*  85  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*LAEB_BrkgReq*/
  { /*  86  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*LAEB_DistanceToCollision*/
  { /*  87  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*LAEB_SpeakReq*/
  { /*  88  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*LAEB_WorkSts*/
  { /*  89  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*Checksum_0x274*/
  { /*  90  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*Rolling_counter_0x274*/
  { /*  91  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*LAEB_LedReq*/
  { /*  92  */    CanCclRxHndlCh0_SOD_LCA_warningReqRight_629,  CanCclRxHndlCh0_SOD_LCA_warningReqRight_629, CanCclRxHndlCh0_SOD_LCA_warningReqRight_629   },/*SOD_LCA_warningReqRight*/
  { /*  93  */    CanCclRxHndlCh0_SOD_DOA_warningReqRightRear_629,  CanCclRxHndlCh0_SOD_DOA_warningReqRightRear_629, CanCclRxHndlCh0_SOD_DOA_warningReqRightRear_629   },/*SOD_DOA_warningReqRightRear*/
  { /*  94  */    CanCclRxHndlCh0_SOD_DOA_warningReqRightFront_629,  CanCclRxHndlCh0_SOD_DOA_warningReqRightFront_629, CanCclRxHndlCh0_SOD_DOA_warningReqRightFront_629   },/*SOD_DOA_warningReqRightFront*/
  { /*  95  */    CanCclRxHndlCh0_SOD_CTA_warningReqRight_629,  CanCclRxHndlCh0_SOD_CTA_warningReqRight_629, CanCclRxHndlCh0_SOD_CTA_warningReqRight_629   },/*SOD_CTA_warningReqRight*/
  { /*  96  */    CanCclRxHndlCh0_SOD_BLIS_display_629,  CanCclRxHndlCh0_SOD_BLIS_display_629, CanCclRxHndlCh0_SOD_BLIS_display_629   },/*SOD_BLIS_display*/
  { /*  97  */    CanCclRxHndlCh0_SOD_LCA_warningReqLeft_629,  CanCclRxHndlCh0_SOD_LCA_warningReqLeft_629, CanCclRxHndlCh0_SOD_LCA_warningReqLeft_629   },/*SOD_LCA_warningReqLeft*/
  { /*  98  */    CanCclRxHndlCh0_SOD_DOA_warningReqLeftRear_629,  CanCclRxHndlCh0_SOD_DOA_warningReqLeftRear_629, CanCclRxHndlCh0_SOD_DOA_warningReqLeftRear_629   },/*SOD_DOA_warningReqLeftRear*/
  { /*  99  */    CanCclRxHndlCh0_SOD_DOA_warningReqLeftFront_629,  CanCclRxHndlCh0_SOD_DOA_warningReqLeftFront_629, CanCclRxHndlCh0_SOD_DOA_warningReqLeftFront_629   },/*SOD_DOA_warningReqLeftFront*/
  { /*  100  */    CanCclRxHndlCh0_SOD_CTA_warningReqLeft_629,  CanCclRxHndlCh0_SOD_CTA_warningReqLeft_629, CanCclRxHndlCh0_SOD_CTA_warningReqLeft_629   },/*SOD_CTA_warningReqLeft*/
  { /*  101  */    CanCclRxHndlCh0_DOA_OFFTelltale_629,  CanCclRxHndlCh0_DOA_OFFTelltale_629, CanCclRxHndlCh0_DOA_OFFTelltale_629   },/*DOA_OFFTelltale*/
  { /*  102  */    CanCclRxHndlCh0_CTA_OFFTelltale_629,  CanCclRxHndlCh0_CTA_OFFTelltale_629, CanCclRxHndlCh0_CTA_OFFTelltale_629   },/*CTA_OFFTelltale*/
  { /*  103  */    CanCclRxHndlCh0_SODLCA_OFFTelltale_629,  CanCclRxHndlCh0_SODLCA_OFFTelltale_629, CanCclRxHndlCh0_SODLCA_OFFTelltale_629   },/*SODLCA_OFFTelltale*/
  { /*  104  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_LedtLine_dx_start*/
  { /*  105  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_LeftLine_dy*/
  { /*  106  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_LeftLine_dx_lookhead*/
  { /*  107  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_LeftLine_hor_curve*/
  { /*  108  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_LeftLine_yawangle*/
  { /*  109  */    CanCclRxHndlCh0_MRR_F_Object_dx_633,  CanCclRxHndlCh0_MRR_F_Object_dx_633, CanCclRxHndlCh0_MRR_F_Object_dx_633   },/*MRR_F_Object_dx*/
  { /*  110  */    CanCclRxHndlCh0_MRR_F_Object_dy_633,  CanCclRxHndlCh0_MRR_F_Object_dy_633, CanCclRxHndlCh0_MRR_F_Object_dy_633   },/*MRR_F_Object_dy*/
  { /*  111  */    CanCclRxHndlCh0_MRR_F_Obj_0x_class_633,  CanCclRxHndlCh0_MRR_F_Obj_0x_class_633, CanCclRxHndlCh0_MRR_F_Obj_0x_class_633   },/*MRR_F_Obj_0x_class*/
  { /*  112  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MRR_FF_Object_dx*/
  { /*  113  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MRR_FF_Object_dy*/
  { /*  114  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MRR_FF_Obj_0x_class*/
  { /*  115  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MRR_FFTargrtDetection*/
  { /*  116  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MRR_PedDetection*/
  { /*  117  */    CanCclRxHndlCh0_IPM_LaneAssit_LeftVisualization_640,  CanCclRxHndlCh0_IPM_LaneAssit_LeftVisualization_640, CanCclRxHndlCh0_IPM_LaneAssit_LeftVisualization_640   },/*IPM_LaneAssit_LeftVisualization*/
  { /*  118  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_LeftLine_Type*/
  { /*  119  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_LeftLine_Color*/
  { /*  120  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_leftLeftLine_Type*/
  { /*  121  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_leftLeftLine_Color*/
  { /*  122  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_leftleftLine_dy*/
  { /*  123  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_leftleftLine_hor_curve*/
  { /*  124  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_leftleftLine_yawangle*/
  { /*  125  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_leftleftLine_cur_alteration*/
  { /*  126  */    CanCclRxHndlCh0_BCM_DoorStsRearRi_784,  CanCclRxHndlCh0_BCM_DoorStsRearRi_784, CanCclRxHndlCh0_BCM_DoorStsRearRi_784   },/*BCM_DoorStsRearRi*/
  { /*  127  */    CanCclRxHndlCh0_BCM_DoorStsRearLe_784,  CanCclRxHndlCh0_BCM_DoorStsRearLe_784, CanCclRxHndlCh0_BCM_DoorStsRearLe_784   },/*BCM_DoorStsRearLe*/
  { /*  128  */    CanCclRxHndlCh0_BCM_DoorStsFrntRi_784,  CanCclRxHndlCh0_BCM_DoorStsFrntRi_784, CanCclRxHndlCh0_BCM_DoorStsFrntRi_784   },/*BCM_DoorStsFrntRi*/
  { /*  129  */    CanCclRxHndlCh0_BCM_DoorStsFrntLe_784,  CanCclRxHndlCh0_BCM_DoorStsFrntLe_784, CanCclRxHndlCh0_BCM_DoorStsFrntLe_784   },/*BCM_DoorStsFrntLe*/
  { /*  130  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_DoorLockStsRearRi*/
  { /*  131  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_DoorLockStsRearLe*/
  { /*  132  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_DoorLockStsFrntRi*/
  { /*  133  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_DoorLockStsFrntLe*/
  { /*  134  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_AntiTheftSts*/
  { /*  135  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_LockUnlockFeedback*/
  { /*  136  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_DoorLockStsTrunk*/
  { /*  137  */    CanCclRxHndlCh0_BCM_DoorStsTrunk_784,  CanCclRxHndlCh0_BCM_DoorStsTrunk_784, CanCclRxHndlCh0_BCM_DoorStsTrunk_784   },/*BCM_DoorStsTrunk*/
  { /*  138  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_TrunkDoorPreUnlockSts*/
  { /*  139  */    CanCclRxHndlCh0_BCM_EnginehoodSts_784,  CanCclRxHndlCh0_BCM_EnginehoodSts_784, CanCclRxHndlCh0_BCM_EnginehoodSts_784   },/*BCM_EnginehoodSts*/
  { /*  140  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_Rolling_counter_0x310*/
  { /*  141  */    CanCclRxHndlCh0_BCM_TurnIndicatorSts_784,  CanCclRxHndlCh0_BCM_TurnIndicatorSts_784, CanCclRxHndlCh0_BCM_TurnIndicatorSts_784   },/*BCM_TurnIndicatorSts*/
  { /*  142  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_Checksum_0x310*/
  { /*  143  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_OutsideTempDig*/
  { /*  144  */    CanCclRxHndlCh0_BCM_BrakeFluidSts_787,  CanCclRxHndlCh0_BCM_BrakeFluidSts_787, CanCclRxHndlCh0_BCM_BrakeFluidSts_787   },/*BCM_BrakeFluidSts*/
  { /*  145  */    CanCclRxHndlCh0_BCM_OutsideTemp_787,  CanCclRxHndlCh0_BCM_OutsideTemp_787, CanCclRxHndlCh0_BCM_OutsideTemp_787   },/*BCM_OutsideTemp*/
  { /*  146  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_Reverse_gear*/
  { /*  147  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_SS_EnableSts*/
  { /*  148  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_Rollingcounter_0x313*/
  { /*  149  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_Checksum_0x313*/
  { /*  150  */    CanCclRxHndlCh0_BCM_BGLLumLvlSettingStatus_789,  CanCclRxHndlCh0_BCM_BGLLumLvlSettingStatus_789, CanCclRxHndlCh0_BCM_BGLLumLvlSettingStatus_789   },/*BCM_BGLLumLvlSettingStatus*/
  { /*  151  */    CanCclRxHndlCh0_BCM_FrntFogLmpSts_792,  CanCclRxHndlCh0_BCM_FrntFogLmpSts_792, CanCclRxHndlCh0_BCM_FrntFogLmpSts_792   },/*BCM_FrntFogLmpSts*/
  { /*  152  */    CanCclRxHndlCh0_BCM_PosLmpSts_792,  CanCclRxHndlCh0_BCM_PosLmpSts_792, CanCclRxHndlCh0_BCM_PosLmpSts_792   },/*BCM_PosLmpSts*/
  { /*  153  */    CanCclRxHndlCh0_BCM_LowBeamSts_792,  CanCclRxHndlCh0_BCM_LowBeamSts_792, CanCclRxHndlCh0_BCM_LowBeamSts_792   },/*BCM_LowBeamSts*/
  { /*  154  */    CanCclRxHndlCh0_BCM_HighBeamSts_792,  CanCclRxHndlCh0_BCM_HighBeamSts_792, CanCclRxHndlCh0_BCM_HighBeamSts_792   },/*BCM_HighBeamSts*/
  { /*  155  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_reversinglightSts*/
  { /*  156  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_DayRunningLampSts*/
  { /*  157  */    CanCclRxHndlCh0_BCM_RearFogLmpSts_792,  CanCclRxHndlCh0_BCM_RearFogLmpSts_792, CanCclRxHndlCh0_BCM_RearFogLmpSts_792   },/*BCM_RearFogLmpSts*/
  { /*  158  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_laserlightSts*/
  { /*  159  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_AmbientLightSts*/
  { /*  160  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_Highmountedstoplamp*/
  { /*  161  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_BrakelightSts*/
  { /*  162  */    CanCclRxHndlCh0_BCM_BackHomeSts_792,  CanCclRxHndlCh0_BCM_BackHomeSts_792, CanCclRxHndlCh0_BCM_BackHomeSts_792   },/*BCM_BackHomeSts*/
  { /*  163  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_AutolampSts*/
  { /*  164  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_readinglampSts*/
  { /*  165  */    CanCclRxHndlCh0_BCM_DayRunningLampDig_792,  CanCclRxHndlCh0_BCM_DayRunningLampDig_792, CanCclRxHndlCh0_BCM_DayRunningLampDig_792   },/*BCM_DayRunningLampDig*/
  { /*  166  */    CanCclRxHndlCh0_BCM_BrakelightDig_792,  CanCclRxHndlCh0_BCM_BrakelightDig_792, CanCclRxHndlCh0_BCM_BrakelightDig_792   },/*BCM_BrakelightDig*/
  { /*  167  */    CanCclRxHndlCh0_BCM_reversinglightDig_792,  CanCclRxHndlCh0_BCM_reversinglightDig_792, CanCclRxHndlCh0_BCM_reversinglightDig_792   },/*BCM_reversinglightDig*/
  { /*  168  */    CanCclRxHndlCh0_BCM_TurnIndicatorDig_792,  CanCclRxHndlCh0_BCM_TurnIndicatorDig_792, CanCclRxHndlCh0_BCM_TurnIndicatorDig_792   },/*BCM_TurnIndicatorDig*/
  { /*  169  */    CanCclRxHndlCh0_BCM_RearFogLmpDig_792,  CanCclRxHndlCh0_BCM_RearFogLmpDig_792, CanCclRxHndlCh0_BCM_RearFogLmpDig_792   },/*BCM_RearFogLmpDig*/
  { /*  170  */    CanCclRxHndlCh0_BCM_FrntFogLmpDig_792,  CanCclRxHndlCh0_BCM_FrntFogLmpDig_792, CanCclRxHndlCh0_BCM_FrntFogLmpDig_792   },/*BCM_FrntFogLmpDig*/
  { /*  171  */    CanCclRxHndlCh0_BCM_PosLmpDig_792,  CanCclRxHndlCh0_BCM_PosLmpDig_792, CanCclRxHndlCh0_BCM_PosLmpDig_792   },/*BCM_PosLmpDig*/
  { /*  172  */    CanCclRxHndlCh0_BCM_LowBeamDig_792,  CanCclRxHndlCh0_BCM_LowBeamDig_792, CanCclRxHndlCh0_BCM_LowBeamDig_792   },/*BCM_LowBeamDig*/
  { /*  173  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_Rollingcounter_0x318*/
  { /*  174  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*BCM_Checksum_0x318*/
  { /*  175  */    CanCclRxHndlCh0_SWM_Menu_Right_794,  CanCclRxHndlCh0_SWM_Menu_Right_794, CanCclRxHndlCh0_SWM_Menu_Right_794   },/*SWM_Menu_Right*/
  { /*  176  */    CanCclRxHndlCh0_SWM_Menu_Left_794,  CanCclRxHndlCh0_SWM_Menu_Left_794, CanCclRxHndlCh0_SWM_Menu_Left_794   },/*SWM_Menu_Left*/
  { /*  177  */    CanCclRxHndlCh0_SWM_Menu_Down_794,  CanCclRxHndlCh0_SWM_Menu_Down_794, CanCclRxHndlCh0_SWM_Menu_Down_794   },/*SWM_Menu_Down*/
  { /*  178  */    CanCclRxHndlCh0_SWM_Menu_Up_794,  CanCclRxHndlCh0_SWM_Menu_Up_794, CanCclRxHndlCh0_SWM_Menu_Up_794   },/*SWM_Menu_Up*/
  { /*  179  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*Rolling_counter_0x31A*/
  { /*  180  */    CanCclRxHndlCh0_SWM_Menu_Return_794,  CanCclRxHndlCh0_SWM_Menu_Return_794, CanCclRxHndlCh0_SWM_Menu_Return_794   },/*SWM_Menu_Return*/
  { /*  181  */    CanCclRxHndlCh0_SWM_Menu_Confirm_794,  CanCclRxHndlCh0_SWM_Menu_Confirm_794, CanCclRxHndlCh0_SWM_Menu_Confirm_794   },/*SWM_Menu_Confirm*/
  { /*  182  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*Checksum_0x31A*/
  { /*  183  */    CanCclRxHndlCh0_SWM_ACCtauGapSetPlus_795,  CanCclRxHndlCh0_SWM_ACCtauGapSetPlus_795, CanCclRxHndlCh0_SWM_ACCtauGapSetPlus_795   },/*SWM_ACCtauGapSetPlus*/
  { /*  184  */    CanCclRxHndlCh0_SWM_ACCvSetMinus_795,  CanCclRxHndlCh0_SWM_ACCvSetMinus_795, CanCclRxHndlCh0_SWM_ACCvSetMinus_795   },/*SWM_ACCvSetMinus*/
  { /*  185  */    CanCclRxHndlCh0_SWM_ACCvSetPlus_795,  CanCclRxHndlCh0_SWM_ACCvSetPlus_795, CanCclRxHndlCh0_SWM_ACCvSetPlus_795   },/*SWM_ACCvSetPlus*/
  { /*  186  */    CanCclRxHndlCh0_SWM_ACCResume_795,  CanCclRxHndlCh0_SWM_ACCResume_795, CanCclRxHndlCh0_SWM_ACCResume_795   },/*SWM_ACCResume*/
  { /*  187  */    CanCclRxHndlCh0_SWM_ACCSet_795,  CanCclRxHndlCh0_SWM_ACCSet_795, CanCclRxHndlCh0_SWM_ACCSet_795   },/*SWM_ACCSet*/
  { /*  188  */    CanCclRxHndlCh0_SWM_ACCEnableSwitch_795,  CanCclRxHndlCh0_SWM_ACCEnableSwitch_795, CanCclRxHndlCh0_SWM_ACCEnableSwitch_795   },/*SWM_ACCEnableSwitch*/
  { /*  189  */    CanCclRxHndlCh0_SWM_LaneAssistSwitch_795,  CanCclRxHndlCh0_SWM_LaneAssistSwitch_795, CanCclRxHndlCh0_SWM_LaneAssistSwitch_795   },/*SWM_LaneAssistSwitch*/
  { /*  190  */    CanCclRxHndlCh0_SWM_ACCtauGapSetMinus_795,  CanCclRxHndlCh0_SWM_ACCtauGapSetMinus_795, CanCclRxHndlCh0_SWM_ACCtauGapSetMinus_795   },/*SWM_ACCtauGapSetMinus*/
  { /*  191  */    CanCclRxHndlCh0_PEPS_PowerMode_805,  CanCclRxHndlCh0_PEPS_PowerMode_805, CanCclRxHndlCh0_PEPS_PowerMode_805   },/*PEPS_PowerMode*/
  { /*  192  */    CanCclRxHndlCh0_PEPS_IMMO_MatchStatus_805,  CanCclRxHndlCh0_PEPS_IMMO_MatchStatus_805, CanCclRxHndlCh0_PEPS_IMMO_MatchStatus_805   },/*PEPS_IMMO_MatchStatus*/
  { /*  193  */    CanCclRxHndlCh0_PEPS_SystemFailStatus_805,  CanCclRxHndlCh0_PEPS_SystemFailStatus_805, CanCclRxHndlCh0_PEPS_SystemFailStatus_805   },/*PEPS_SystemFailStatus*/
  { /*  194  */    CanCclRxHndlCh0_PEPS_ESCL_FailStatus_805,  CanCclRxHndlCh0_PEPS_ESCL_FailStatus_805, CanCclRxHndlCh0_PEPS_ESCL_FailStatus_805   },/*PEPS_ESCL_FailStatus*/
  { /*  195  */    CanCclRxHndlCh0_PEPS_SSB_FailStatus_805,  CanCclRxHndlCh0_PEPS_SSB_FailStatus_805, CanCclRxHndlCh0_PEPS_SSB_FailStatus_805   },/*PEPS_SSB_FailStatus*/
  { /*  196  */    CanCclRxHndlCh0_PEPS_BrakeIndicationWarning_805,  CanCclRxHndlCh0_PEPS_BrakeIndicationWarning_805, CanCclRxHndlCh0_PEPS_BrakeIndicationWarning_805   },/*PEPS_BrakeIndicationWarning*/
  { /*  197  */    CanCclRxHndlCh0_PEPS_NotPNWarning_805,  CanCclRxHndlCh0_PEPS_NotPNWarning_805, CanCclRxHndlCh0_PEPS_NotPNWarning_805   },/*PEPS_NotPNWarning*/
  { /*  198  */    CanCclRxHndlCh0_PEPS_DoorOpenNotOFFWarning_805,  CanCclRxHndlCh0_PEPS_DoorOpenNotOFFWarning_805, CanCclRxHndlCh0_PEPS_DoorOpenNotOFFWarning_805   },/*PEPS_DoorOpenNotOFFWarning*/
  { /*  199  */    CanCclRxHndlCh0_PEPS_DoorOpenWarning_805,  CanCclRxHndlCh0_PEPS_DoorOpenWarning_805, CanCclRxHndlCh0_PEPS_DoorOpenWarning_805   },/*PEPS_DoorOpenWarning*/
  { /*  200  */    CanCclRxHndlCh0_PEPS_KeyBatteryWarning_805,  CanCclRxHndlCh0_PEPS_KeyBatteryWarning_805, CanCclRxHndlCh0_PEPS_KeyBatteryWarning_805   },/*PEPS_KeyBatteryWarning*/
  { /*  201  */    CanCclRxHndlCh0_PEPS_KeyOutWarning1_805,  CanCclRxHndlCh0_PEPS_KeyOutWarning1_805, CanCclRxHndlCh0_PEPS_KeyOutWarning1_805   },/*PEPS_KeyOutWarning1*/
  { /*  202  */    CanCclRxHndlCh0_PEPS_NoKeyFoundWarning_805,  CanCclRxHndlCh0_PEPS_NoKeyFoundWarning_805, CanCclRxHndlCh0_PEPS_NoKeyFoundWarning_805   },/*PEPS_NoKeyFoundWarning*/
  { /*  203  */    CanCclRxHndlCh0_PEPS_KeyReminderWarning_805,  CanCclRxHndlCh0_PEPS_KeyReminderWarning_805, CanCclRxHndlCh0_PEPS_KeyReminderWarning_805   },/*PEPS_KeyReminderWarning*/
  { /*  204  */    CanCclRxHndlCh0_PEPS_RemainingNumSts_805,  CanCclRxHndlCh0_PEPS_RemainingNumSts_805, CanCclRxHndlCh0_PEPS_RemainingNumSts_805   },/*PEPS_RemainingNumSts*/
  { /*  205  */    CanCclRxHndlCh0_SRS_SBR_PAMsenger_848,  CanCclRxHndlCh0_SRS_SBR_PAMsenger_848, CanCclRxHndlCh0_SRS_SBR_PAMsenger_848   },/*SRS_SBR_PAMsenger*/
  { /*  206  */    CanCclRxHndlCh0_SRS_SBR_Driver_848,  CanCclRxHndlCh0_SRS_SBR_Driver_848, CanCclRxHndlCh0_SRS_SBR_Driver_848   },/*SRS_SBR_Driver*/
  { /*  207  */    CanCclRxHndlCh0_SRS_AirBagFailSts_848,  CanCclRxHndlCh0_SRS_AirBagFailSts_848, CanCclRxHndlCh0_SRS_AirBagFailSts_848   },/*SRS_AirBagFailSts*/
  { /*  208  */    CanCclRxHndlCh0_SRS_SBR_SecondRowRight_848,  CanCclRxHndlCh0_SRS_SBR_SecondRowRight_848, CanCclRxHndlCh0_SRS_SBR_SecondRowRight_848   },/*SRS_SBR_SecondRowRight*/
  { /*  209  */    CanCclRxHndlCh0_SRS_SBR_SecondRowMid_848,  CanCclRxHndlCh0_SRS_SBR_SecondRowMid_848, CanCclRxHndlCh0_SRS_SBR_SecondRowMid_848   },/*SRS_SBR_SecondRowMid*/
  { /*  210  */    CanCclRxHndlCh0_SRS_SBR_SecondRowLeft_848,  CanCclRxHndlCh0_SRS_SBR_SecondRowLeft_848, CanCclRxHndlCh0_SRS_SBR_SecondRowLeft_848   },/*SRS_SBR_SecondRowLeft*/
  { /*  211  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*Rolling_counter_0x350*/
  { /*  212  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*Checksum_0x350*/
  { /*  213  */    CanCclRxHndlCh0_TPMS_LF_Pressure_865,  CanCclRxHndlCh0_TPMS_LF_Pressure_865, CanCclRxHndlCh0_TPMS_LF_Pressure_865   },/*TPMS_LF_Pressure*/
  { /*  214  */    CanCclRxHndlCh0_TPMS_RF_Pressure_865,  CanCclRxHndlCh0_TPMS_RF_Pressure_865, CanCclRxHndlCh0_TPMS_RF_Pressure_865   },/*TPMS_RF_Pressure*/
  { /*  215  */    CanCclRxHndlCh0_TPMS_RR_Pressure_865,  CanCclRxHndlCh0_TPMS_RR_Pressure_865, CanCclRxHndlCh0_TPMS_RR_Pressure_865   },/*TPMS_RR_Pressure*/
  { /*  216  */    CanCclRxHndlCh0_TPMS_LR_Pressure_865,  CanCclRxHndlCh0_TPMS_LR_Pressure_865, CanCclRxHndlCh0_TPMS_LR_Pressure_865   },/*TPMS_LR_Pressure*/
  { /*  217  */    CanCclRxHndlCh0_TPMS_Tire_Temperature_865,  CanCclRxHndlCh0_TPMS_Tire_Temperature_865, CanCclRxHndlCh0_TPMS_Tire_Temperature_865   },/*TPMS_Tire_Temperature*/
  { /*  218  */    CanCclRxHndlCh0_TPMS_LF_Pressure_Warning_865,  CanCclRxHndlCh0_TPMS_LF_Pressure_Warning_865, CanCclRxHndlCh0_TPMS_LF_Pressure_Warning_865   },/*TPMS_LF_Pressure_Warning*/
  { /*  219  */    CanCclRxHndlCh0_TPMS_RF_Pressure_Warning_865,  CanCclRxHndlCh0_TPMS_RF_Pressure_Warning_865, CanCclRxHndlCh0_TPMS_RF_Pressure_Warning_865   },/*TPMS_RF_Pressure_Warning*/
  { /*  220  */    CanCclRxHndlCh0_TPMS_System_Status_865,  CanCclRxHndlCh0_TPMS_System_Status_865, CanCclRxHndlCh0_TPMS_System_Status_865   },/*TPMS_System_Status*/
  { /*  221  */    CanCclRxHndlCh0_TPMS_RR_Pressure_Warning_865,  CanCclRxHndlCh0_TPMS_RR_Pressure_Warning_865, CanCclRxHndlCh0_TPMS_RR_Pressure_Warning_865   },/*TPMS_RR_Pressure_Warning*/
  { /*  222  */    CanCclRxHndlCh0_TPMS_LR_Pressure_Warning_865,  CanCclRxHndlCh0_TPMS_LR_Pressure_Warning_865, CanCclRxHndlCh0_TPMS_LR_Pressure_Warning_865   },/*TPMS_LR_Pressure_Warning*/
  { /*  223  */    CanCclRxHndlCh0_TPMS_Temperature_Warning_865,  CanCclRxHndlCh0_TPMS_Temperature_Warning_865, CanCclRxHndlCh0_TPMS_Temperature_Warning_865   },/*TPMS_Temperature_Warning*/
  { /*  224  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*TPMS_resrved*/
  { /*  225  */    CanCclRxHndlCh0_Tire_Position_865,  CanCclRxHndlCh0_Tire_Position_865, CanCclRxHndlCh0_Tire_Position_865   },/*Tire_Position*/
  { /*  226  */    CanCclRxHndlCh0_TPMS_Lamp_Status_865,  CanCclRxHndlCh0_TPMS_Lamp_Status_865, CanCclRxHndlCh0_TPMS_Lamp_Status_865   },/*TPMS_Lamp_Status*/
  { /*  227  */    CanCclRxHndlCh0_EMS_Fuelcounter_870,  CanCclRxHndlCh0_EMS_Fuelcounter_870, CanCclRxHndlCh0_EMS_Fuelcounter_870   },/*EMS_Fuelcounter*/
  { /*  228  */    CanCclRxHndlCh0_EMS_FuelconsumptionInst_870,  CanCclRxHndlCh0_EMS_FuelconsumptionInst_870, CanCclRxHndlCh0_EMS_FuelconsumptionInst_870   },/*EMS_FuelconsumptionInst*/
  { /*  229  */    CanCclRxHndlCh0_EMS_MIL_870,  CanCclRxHndlCh0_EMS_MIL_870, CanCclRxHndlCh0_EMS_MIL_870   },/*EMS_MIL*/
  { /*  230  */    CanCclRxHndlCh0_EMS_SVS_870,  CanCclRxHndlCh0_EMS_SVS_870, CanCclRxHndlCh0_EMS_SVS_870   },/*EMS_SVS*/
  { /*  231  */    CanCclRxHndlCh0_EMS_StartStopStatus_870,  CanCclRxHndlCh0_EMS_StartStopStatus_870, CanCclRxHndlCh0_EMS_StartStopStatus_870   },/*EMS_StartStopStatus*/
  { /*  232  */    CanCclRxHndlCh0_EMS_GasPrtcWarn_G_Rq_872,  CanCclRxHndlCh0_EMS_GasPrtcWarn_G_Rq_872, CanCclRxHndlCh0_EMS_GasPrtcWarn_G_Rq_872   },/*EMS_GasPrtcWarn_G_Rq*/
  { /*  233  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MP5_AudioStatus*/
  { /*  234  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MP5_EnergyFlow*/
  { /*  235  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MP5_SetMultiButton*/
  { /*  236  */    CanCclRxHndlCh0_MP5_BSDSoundSwitchSts_898,  CanCclRxHndlCh0_MP5_BSDSoundSwitchSts_898, CanCclRxHndlCh0_MP5_BSDSoundSwitchSts_898   },/*MP5_BSDSoundSwitchSts*/
  { /*  237  */    CanCclRxHndlCh0_MP5_NavStatus_898,  CanCclRxHndlCh0_MP5_NavStatus_898, CanCclRxHndlCh0_MP5_NavStatus_898   },/*MP5_NavStatus*/
  { /*  238  */    CanCclRxHndlCh0_MP5_NavICON_900,  CanCclRxHndlCh0_MP5_NavICON_900, CanCclRxHndlCh0_MP5_NavICON_900   },/*MP5_NavICON*/
  { /*  239  */    CanCclRxHndlCh0_MP5_ROUTE_REMAIN_DIS_900,  CanCclRxHndlCh0_MP5_ROUTE_REMAIN_DIS_900, CanCclRxHndlCh0_MP5_ROUTE_REMAIN_DIS_900   },/*MP5_ROUTE_REMAIN_DIS*/
  { /*  240  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MP5_ALModeSetting*/
  { /*  241  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MP5_ALStartAroundSetting*/
  { /*  242  */    CanCclRxHndlCh0_TCU_EmergencyTowingSts_917,  CanCclRxHndlCh0_TCU_EmergencyTowingSts_917, CanCclRxHndlCh0_TCU_EmergencyTowingSts_917   },/*TCU_EmergencyTowingSts*/
  { /*  243  */    CanCclRxHndlCh0_TrnSrvcRqd_B_Rq_917,  CanCclRxHndlCh0_TrnSrvcRqd_B_Rq_917, CanCclRxHndlCh0_TrnSrvcRqd_B_Rq_917   },/*TrnSrvcRqd_B_Rq*/
  { /*  244  */    CanCclRxHndlCh0_TCU_GearPFault_917,  CanCclRxHndlCh0_TCU_GearPFault_917, CanCclRxHndlCh0_TCU_GearPFault_917   },/*TCU_GearPFault*/
  { /*  245  */    CanCclRxHndlCh0_TCU_WarningMessage_917,  CanCclRxHndlCh0_TCU_WarningMessage_917, CanCclRxHndlCh0_TCU_WarningMessage_917   },/*TCU_WarningMessage*/
  { /*  246  */    CanCclRxHndlCh0_TCU_DrvShiftAllwCondRmd_917,  CanCclRxHndlCh0_TCU_DrvShiftAllwCondRmd_917, CanCclRxHndlCh0_TCU_DrvShiftAllwCondRmd_917   },/*TCU_DrvShiftAllwCondRmd*/
  { /*  247  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MRR_L_Object_dx*/
  { /*  248  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MRR_L_Object_dy*/
  { /*  249  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MRR_L_Obj_0x_class*/
  { /*  250  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MRR_R_Object_dx*/
  { /*  251  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MRR_R_Object_dy*/
  { /*  252  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MRR_R_Obj_0x_class*/
  { /*  253  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MRR_LeftTargrtDetection*/
  { /*  254  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MRR_RightTargrtDetection*/
  { /*  255  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_RightLine_dx_start*/
  { /*  256  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_RightLine_dy*/
  { /*  257  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_RightLine_dx_lookhead*/
  { /*  258  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_RightLine_hor_curve*/
  { /*  259  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_RightLine_yawangle*/
  { /*  260  */    CanCclRxHndlCh0_IPM_LaneAssit_RightVisualization_1169,  CanCclRxHndlCh0_IPM_LaneAssit_RightVisualization_1169, CanCclRxHndlCh0_IPM_LaneAssit_RightVisualization_1169   },/*IPM_LaneAssit_RightVisualization*/
  { /*  261  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_rightRighLine_Type*/
  { /*  262  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_RighLine_Color*/
  { /*  263  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_RighLine_Type*/
  { /*  264  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_RighrightLine_Color*/
  { /*  265  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_rightRightLine_dy*/
  { /*  266  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_rightRightLine_hor_curve*/
  { /*  267  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_rightRightLine_yawangle*/
  { /*  268  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*IPM_RightLine_cur_alteration*/
  { /*  269  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*AVM_displaytype*/
  { /*  270  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*AVM_Status*/
  { /*  271  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*AVM_Guide_line_info*/
  { /*  272  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*AVM_Switch*/
  { /*  273  */    CanCclRxHndlCh0_MP5_ICMenuShift_Button_1328,  CanCclRxHndlCh0_MP5_ICMenuShift_Button_1328, CanCclRxHndlCh0_MP5_ICMenuShift_Button_1328   },/*MP5_ICMenuShift_Button*/
  { /*  274  */    CanCclRxHndlCh0_MP5_ICMenuActive_Button_1328,  CanCclRxHndlCh0_MP5_ICMenuActive_Button_1328, CanCclRxHndlCh0_MP5_ICMenuActive_Button_1328   },/*MP5_ICMenuActive_Button*/
  { /*  275  */    CanCclRxHndlCh0_MP5_AlarmStatus_1328,  CanCclRxHndlCh0_MP5_AlarmStatus_1328, CanCclRxHndlCh0_MP5_AlarmStatus_1328   },/*MP5_AlarmStatus*/
  { /*  276  */    CanCclRxHndlCh0_MP5_AlarmOrNot_1328,  CanCclRxHndlCh0_MP5_AlarmOrNot_1328, CanCclRxHndlCh0_MP5_AlarmOrNot_1328   },/*MP5_AlarmOrNot*/
  { /*  277  */    CanCclRxHndlCh0_MP5_ICMenu_Cmd_1330,  CanCclRxHndlCh0_MP5_ICMenu_Cmd_1330, CanCclRxHndlCh0_MP5_ICMenu_Cmd_1330   },/*MP5_ICMenu_Cmd*/
  { /*  278  */    CanCclRxHndlCh0_Nav_Sts_1331,  CanCclRxHndlCh0_Nav_Sts_1331, CanCclRxHndlCh0_Nav_Sts_1331   },/*Nav_Sts*/
  { /*  279  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*MP5_BGLLumLvlSetting*/
  { /*  280  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*WACM_WirelessChargerStatus*/
  { /*  281  */    CanCclRxHndlCh0_TBOX_Year_1410,  CanCclRxHndlCh0_TBOX_Year_1410, CanCclRxHndlCh0_TBOX_Year_1410   },/*TBOX_Year*/
  { /*  282  */    CanCclRxHndlCh0_TBOX_Month_1410,  CanCclRxHndlCh0_TBOX_Month_1410, CanCclRxHndlCh0_TBOX_Month_1410   },/*TBOX_Month*/
  { /*  283  */    CanCclRxHndlCh0_TBOX_Date_1410,  CanCclRxHndlCh0_TBOX_Date_1410, CanCclRxHndlCh0_TBOX_Date_1410   },/*TBOX_Date*/
  { /*  284  */    CanCclRxHndlCh0_TBOX_Hour_1410,  CanCclRxHndlCh0_TBOX_Hour_1410, CanCclRxHndlCh0_TBOX_Hour_1410   },/*TBOX_Hour*/
  { /*  285  */    CanCclRxHndlCh0_TBOX_Minute_1410,  CanCclRxHndlCh0_TBOX_Minute_1410, CanCclRxHndlCh0_TBOX_Minute_1410   },/*TBOX_Minute*/
  { /*  286  */    CanCclRxHndlCh0_TBOX_Second_1410,  CanCclRxHndlCh0_TBOX_Second_1410, CanCclRxHndlCh0_TBOX_Second_1410   },/*TBOX_Second*/
  { /*  287  */    CanCclRxHndlCh0_TBOX_ReTime_1410,  CanCclRxHndlCh0_TBOX_ReTime_1410, CanCclRxHndlCh0_TBOX_ReTime_1410   },/*TBOX_ReTime*/
  { /*  288  */    CanCclRxHndlCh0_BCM_LoadManageLevel_1412,  CanCclRxHndlCh0_BCM_LoadManageLevel_1412, CanCclRxHndlCh0_BCM_LoadManageLevel_1412   },/*BCM_LoadManageLevel*/
  { /*  289  */    CanCclRxHndlCh0_BCM_CarModeIndicator_1412,  CanCclRxHndlCh0_BCM_CarModeIndicator_1412, CanCclRxHndlCh0_BCM_CarModeIndicator_1412   },/*BCM_CarModeIndicator*/
  { /*  290  */    CanCclRxHndlCh0_BCM_CarMode_1412,  CanCclRxHndlCh0_BCM_CarMode_1412, CanCclRxHndlCh0_BCM_CarMode_1412   },/*BCM_CarMode*/
  { /*  291  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*AFS_WorkSts*/
  { /*  292  */    CanCclRxHndlCh0_SCMM_HMIDisplay_1443,  CanCclRxHndlCh0_SCMM_HMIDisplay_1443, CanCclRxHndlCh0_SCMM_HMIDisplay_1443   },/*SCMM_HMIDisplay*/
  { /*  293  */    CanCclRxHndlCh0_EMS_BackupOdometer_1590,  CanCclRxHndlCh0_EMS_BackupOdometer_1590, CanCclRxHndlCh0_EMS_BackupOdometer_1590   },/*EMS_BackupOdometer*/
};


  /**********************************************************************************************************************
    Ccl_PduGrpVector
  **********************************************************************************************************************/
  /**
    \var    Ccl_PduGrpVector
    \brief  Contains an I-PDU-Group vector for each I-PDU, mapping the I-PDU to the corresponding I-PDU-Groups.
    */
  CONST(Ccl_PduGrpVectorType, CCL_CONST) Can_Ccl_PduGrpVector[Can_Ccl_Num_Of_PduGroups] = {
    /* Index    PduGrpVector   */
    /*     0 */        0x02,
    /*     1 */        0x01
  };

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
  CONST(Ccl_TxPduGrpInfoType, CCL_CONST) Can_Ccl_TxPduGrpInfo[Can_Ccl_Tx_Num_Messages] = {
    /* Index     PduGrpVectorStartIdx */ 
  { /*  0  */           0U  },
  { /*  1  */           0U  },
  { /*  2  */           0U  },
  { /*  3  */           0U  },
  { /*  4  */           0U  },
  { /*  5  */           0U  },
  { /*  6  */           0U  },
};

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
  CONST(Ccl_RxPduGrpInfoType, CCL_CONST) Can_Ccl_RxPduGrpInfo[Can_Ccl_Rx_Num_Messages] = {
    /* Index     PduGrpVectorStartIdx */ 
  { /*     0 */           1U  },
  { /*     1 */           1U  },
  { /*     2 */           1U  },
  { /*     3 */           1U  },
  { /*     4 */           1U  },
  { /*     5 */           1U  },
  { /*     6 */           1U  },
  { /*     7 */           1U  },
  { /*     8 */           1U  },
  { /*     9 */           1U  },
  { /*     10 */           1U  },
  { /*     11 */           1U  },
  { /*     12 */           1U  },
  { /*     13 */           1U  },
  { /*     14 */           1U  },
  { /*     15 */           1U  },
  { /*     16 */           1U  },
  { /*     17 */           1U  },
  { /*     18 */           1U  },
  { /*     19 */           1U  },
  { /*     20 */           1U  },
  { /*     21 */           1U  },
  { /*     22 */           1U  },
  { /*     23 */           1U  },
  { /*     24 */           1U  },
  { /*     25 */           1U  },
  { /*     26 */           1U  },
  { /*     27 */           1U  },
  { /*     28 */           1U  },
  { /*     29 */           1U  },
  { /*     30 */           1U  },
  { /*     31 */           1U  },
  { /*     32 */           1U  },
  { /*     33 */           1U  },
  { /*     34 */           1U  },
  { /*     35 */           1U  },
  { /*     36 */           1U  },
  { /*     37 */           1U  },
  { /*     38 */           1U  },
  { /*     39 */           1U  },
  { /*     40 */           1U  },
  { /*     41 */           1U  },
  { /*     42 */           1U  },
  { /*     43 */           1U  },
  { /*     44 */           1U  },
  { /*     45 */           1U  },
};

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
Date          : 2021-01-06 14:51:25
By              : ChengJia
Traceability    : JMC_SUV_Body_CAN_Matrix_20210104.dbc
Change Description  : Tool Generated code
*****************************************************************************/
