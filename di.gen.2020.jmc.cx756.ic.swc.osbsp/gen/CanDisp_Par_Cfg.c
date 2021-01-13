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
**   its rights under all copyright laws to protect this work as a published
**   work, when appropriate.  Those having access to this work may not copy it,
**   use it, modify it or disclose the information contained in it without the
**   written authorization of Visteon Corporation.
** 
**  =========================================================================*/

/* ===========================================================================
**
**  Name:           CanDisp_Par_Cfg.c
**
**  Description:    CAN Dispatcher parameter Configuration file for corresponding
**                    Network database
**
**  Organization:   Vehicle Communications
**                  Visteon Corporation
**
**  =========================================================================*/




/* ===========================================================================
** I N C L U D E   F I L E S
** =========================================================================*/

# include "CanDisp_Par_Cfg.h"
# include "CanIl_Par_Cfg.h"
# include "CanNm_Par_Cfg.h"
# include "CanIvi_Par_Cfg.h"
# include "CanIl.h"
# include "CanNm.h"
# include "CanXcp.h"
# include "CanTp.h"
# include "CanIvi.h"
# include "Os.h"
# include "Can_Cfg.h"


/* ===========================================================================
** M A C R O   D E F I N I T I O N S
** =========================================================================*/


/* ===========================================================================
** G L O B A L   C O N S T A N T   D E F I N I T I O N S
** =========================================================================*/



/**********************************************************************************************************************
  CanDisp_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanDisp_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
CONST(CanDisp_RxIndicationFctListType, CANDISP_CONST) CanDisp_RxIndicationFctList[CanDisp_Type_Of_Messages] = {
    /* Index    RxIndicationFct                                                RxIndicationLayout                   */
  { /*     0 */  { (CanDisp_SimpleRxIndicationFctType)CanIl_RxIndication    }, CanDisp_AdvancedRxIndicationLayout } ,
  { /*     1 */  { (CanDisp_SimpleRxIndicationFctType)CanNm_RxIndication    }, CanDisp_AdvancedRxIndicationLayout } ,
  { /*     2 */  { (CanDisp_SimpleRxIndicationFctType)CanTp_RxIndication    }, CanDisp_AdvancedRxIndicationLayout } ,
  { /*     3 */  { (CanDisp_SimpleRxIndicationFctType)CanIvi_RxIndication   }, CanDisp_AdvancedRxIndicationLayout } ,  
  { /*     4 */  { (CanDisp_SimpleRxIndicationFctType)NULL/*CanXcp_RxIndication*/   }, CanDisp_AdvancedRxIndicationLayout } ,
  { /*     5 */  { (CanDisp_SimpleRxIndicationFctType)NULL/*CanGw_RxIndication*/   }, CanDisp_AdvancedRxIndicationLayout } 
}; 




/**********************************************************************************************************************
	  CanDisp_MailBoxConfig
	  **********************************************************************************************************************/
	  /** 
	  \var    CanDisp_MailBoxConfig
	  \brief  Mailbox table.
	  \details
	  Element        Description
	  PduIdFirst     "First" PDU mapped to mailbox.
	  PduIdLast      "Last" PDU mapped to mailbox.
	  Controller     Handle ID of controller.
	  MailBoxType    Type of mailbox: Rx BasicCAN/FullCAN/unused.
	  */


	  CONST(CanDisp_MailBoxConfigType, CANDISP_CONST) CanDisp_MailBoxConfig[CanDisp_Number_Of_MBs] = {
	  /* Index      PduIdFirst   PduIdLast   Controller   MailBoxType */ 
  { /*   0 */     0U ,         0U ,       0U,       CANDISP_RxFullCANMailbox  },/*313U*/
  { /*   1 */     1U ,         1U ,       0U,       CANDISP_RxFullCANMailbox  },/*584U*/
  { /*   2 */     2U ,         2U ,       0U,       CANDISP_RxFullCANMailbox  },/*310U*/
  { /*   3 */     3U ,         3U ,       0U,       CANDISP_RxFullCANMailbox  },/*318U*/
  { /*   4 */     4U ,         4U ,       0U,       CANDISP_RxFullCANMailbox  },/*315U*/
  { /*   5 */     5U ,         5U ,       0U,       CANDISP_RxFullCANMailbox  },/*221U*/
  { /*   6 */     6U ,         6U ,       0U,       CANDISP_RxFullCANMailbox  },/*5A0U*/
  { /*   7 */     7U ,         7U ,       0U,       CANDISP_RxFullCANMailbox  },/*520U*/
  { /*   8 */     8U ,         8U ,       0U,       CANDISP_RxFullCANMailbox  },/*368U*/
  { /*   9 */     9U ,         9U ,       0U,       CANDISP_RxFullCANMailbox  },/*636U*/
  { /*   10 */     10U ,         10U ,       0U,       CANDISP_RxFullCANMailbox  },/*10BU*/
  { /*   11 */     11U ,         11U ,       0U,       CANDISP_RxFullCANMailbox  },/*366U*/
  { /*   12 */     12U ,         12U ,       0U,       CANDISP_RxFullCANMailbox  },/*151U*/
  { /*   13 */     13U ,         13U ,       0U,       CANDISP_RxFullCANMailbox  },/*260U*/
  { /*   14 */     14U ,         14U ,       0U,       CANDISP_RxFullCANMailbox  },/*243U*/
  { /*   15 */     15U ,         15U ,       0U,       CANDISP_RxFullCANMailbox  },/*245U*/
  { /*   16 */     16U ,         16U ,       0U,       CANDISP_RxFullCANMailbox  },/*247U*/
  { /*   17 */     17U ,         17U ,       0U,       CANDISP_RxFullCANMailbox  },/*278U*/
  { /*   18 */     18U ,         18U ,       0U,       CANDISP_RxFullCANMailbox  },/*280U*/
  { /*   19 */     19U ,         19U ,       0U,       CANDISP_RxFullCANMailbox  },/*490U*/
  { /*   20 */     20U ,         20U ,       0U,       CANDISP_RxFullCANMailbox  },/*246U*/
  { /*   21 */     21U ,         21U ,       0U,       CANDISP_RxFullCANMailbox  },/*480U*/
  { /*   22 */     22U ,         22U ,       0U,       CANDISP_RxFullCANMailbox  },/*279U*/
  { /*   23 */     23U ,         23U ,       0U,       CANDISP_RxFullCANMailbox  },/*271U*/
  { /*   24 */     24U ,         24U ,       0U,       CANDISP_RxFullCANMailbox  },/*274U*/
  { /*   25 */     25U ,         25U ,       0U,       CANDISP_RxFullCANMailbox  },/*275U*/
  { /*   26 */     26U ,         26U ,       0U,       CANDISP_RxFullCANMailbox  },/*350U*/
  { /*   27 */     27U ,         27U ,       0U,       CANDISP_RxFullCANMailbox  },/*31AU*/
  { /*   28 */     28U ,         28U ,       0U,       CANDISP_RxFullCANMailbox  },/*31BU*/
  { /*   29 */     29U ,         29U ,       0U,       CANDISP_RxFullCANMailbox  },/*1A2U*/
  { /*   30 */     30U ,         30U ,       0U,       CANDISP_RxFullCANMailbox  },/*582U*/
  { /*   31 */     31U ,         31U ,       0U,       CANDISP_RxFullCANMailbox  },/*123U*/
  { /*   32 */     32U ,         32U ,       0U,       CANDISP_RxFullCANMailbox  },/*395U*/
  { /*   33 */     33U ,         33U ,       0U,       CANDISP_RxFullCANMailbox  },/*491U*/
  { /*   34 */     34U ,         34U ,       1U,       CANDISP_RxFullCANMailbox  },/*382U*/
  { /*   35 */     35U ,         35U ,       0U,       CANDISP_RxFullCANMailbox  },/*384U*/
  { /*   36 */     36U ,         36U ,       0U,       CANDISP_RxFullCANMailbox  },/*530U*/
  { /*   37 */     37U ,         37U ,       0U,       CANDISP_RxFullCANMailbox  },/*533U*/
  { /*   38 */     38U ,         38U ,       0U,       CANDISP_RxFullCANMailbox  },/*535U*/
  { /*   39 */     39U ,         39U ,       0U,       CANDISP_RxFullCANMailbox  },/*532U*/
  { /*   40 */     40U ,         40U ,       0U,       CANDISP_RxFullCANMailbox  },/*325U*/
  { /*   41 */     41U ,         41U ,       0U,       CANDISP_RxFullCANMailbox  },/*1A5U*/
  { /*   42 */     42U ,         42U ,       0U,       CANDISP_RxFullCANMailbox  },/*5A3U*/
  { /*   43 */     43U ,         43U ,       0U,       CANDISP_RxFullCANMailbox  },/*C8U*/
  { /*   44 */     44U ,         44U ,       0U,       CANDISP_RxFullCANMailbox  },/*361U*/
  { /*   45 */     45U ,         45U ,       0U,       CANDISP_RxFullCANMailbox  },/*537U*/
  { /*   46 */     46U ,         46U ,       0U,       CANDISP_RxBasicCANMailbox  },/*400U*//*NM*/
  { /*   47 */     47U ,         47U ,       0U,       CANDISP_RxFullCANMailbox  },/*7DFU*/
  { /*   48 */     48U ,         48U ,       0U,       CANDISP_RxFullCANMailbox  },/*730U*/
  { /*   49 */     49U ,         49U ,       1U,       CANDISP_RxFullCANMailbox  },/*381U*/
  { /*   50 */     50U ,         50U ,       0U,       CANDISP_RxFullCANMailbox  },/*385U*/
  { /*   51 */     51U ,         51U ,       1U,       CANDISP_RxFullCANMailbox  },/*383U*/
  { /*   52 */     52U ,         52U ,       1U,       CANDISP_RxFullCANMailbox  },/*380U*/
  { /*   53 */     53U ,         53U ,       1U,       CANDISP_TxFullCANMailbox  },/*386U*/
  { /*   54 */     54U ,         54U ,       0U,       CANDISP_TxFullCANMailbox  },/*387U*/
  { /*   55 */     55U ,         55U ,       0U,       CANDISP_TxFullCANMailbox  },/*38AU*/
  { /*   56 */     56U ,         56U ,       0U,       CANDISP_TxFullCANMailbox  },/*510U*/
  { /*   57 */     57U ,         57U ,       0U,       CANDISP_TxFullCANMailbox  },/*511U*/
  { /*   58 */     58U ,         58U ,       0U,       CANDISP_TxFullCANMailbox  },/*525U*/
  { /*   59 */     59U ,         59U ,       0U,       CANDISP_TxFullCANMailbox  },/*581U*/
  { /*   60 */     60U ,         60U ,       0U,       CANDISP_TxFullCANMailbox  },/*430U*/
  { /*   61 */     61U ,         61U ,       0U,       CANDISP_TxFullCANMailbox  },/*738U*/
  { /*   62 */     62U ,         62U ,       1U,       CANDISP_TxFullCANMailbox  },/*377U*/
  { /*   63 */     63U ,         63U ,       1U,       CANDISP_TxFullCANMailbox  },/*389U*/
  { /*   64 */     64U ,         64U ,       0U,       CANDISP_TxFullCANMailbox  },/*38CU*/
  { /*   65 */     65U ,         65U ,       1U,       CANDISP_TxFullCANMailbox  },/*376U*/
  { /*   66 */     66U ,         66U ,       1U,       CANDISP_TxFullCANMailbox  },/*38BU*/
  { /*   67 */     67U ,         67U ,       1U,       CANDISP_TxFullCANMailbox  },/*388U*/
};


/**********************************************************************************************************************
  CanDisp_RxPduCanId
**********************************************************************************************************************/
/** 
  \var    CanDisp_RxPduCanId
  \brief  Rx-PDU: CAN identifier.
*/


CONST(CanDisp_RxPduCanIdentType, CANDISP_CONST) CanDisp_RxPduCanId[CanDisp_Number_Of_Rx_Messages] = {
    /* Index     RxPduCanId   RxOption          */
  { /*   0 */     0x313U,    CANB_RX_STANDARD   },
  { /*   1 */     0x584U,    CANB_RX_STANDARD   },
  { /*   2 */     0x310U,    CANB_RX_STANDARD   },
  { /*   3 */     0x318U,    CANB_RX_STANDARD   },
  { /*   4 */     0x315U,    CANB_RX_STANDARD   },
  { /*   5 */     0x221U,    CANB_RX_STANDARD   },
  { /*   6 */     0x5A0U,    CANB_RX_STANDARD   },
  { /*   7 */     0x520U,    CANB_RX_STANDARD   },
  { /*   8 */     0x368U,    CANB_RX_STANDARD   },
  { /*   9 */     0x636U,    CANB_RX_STANDARD   },
  { /*   10 */     0x10BU,    CANB_RX_STANDARD   },
  { /*   11 */     0x366U,    CANB_RX_STANDARD   },
  { /*   12 */     0x151U,    CANB_RX_STANDARD   },
  { /*   13 */     0x260U,    CANB_RX_STANDARD   },
  { /*   14 */     0x243U,    CANB_RX_STANDARD   },
  { /*   15 */     0x245U,    CANB_RX_STANDARD   },
  { /*   16 */     0x247U,    CANB_RX_STANDARD   },
  { /*   17 */     0x278U,    CANB_RX_STANDARD   },
  { /*   18 */     0x280U,    CANB_RX_STANDARD   },
  { /*   19 */     0x490U,    CANB_RX_STANDARD   },
  { /*   20 */     0x246U,    CANB_RX_STANDARD   },
  { /*   21 */     0x480U,    CANB_RX_STANDARD   },
  { /*   22 */     0x279U,    CANB_RX_STANDARD   },
  { /*   23 */     0x271U,    CANB_RX_STANDARD   },
  { /*   24 */     0x274U,    CANB_RX_STANDARD   },
  { /*   25 */     0x275U,    CANB_RX_STANDARD   },
  { /*   26 */     0x350U,    CANB_RX_STANDARD   },
  { /*   27 */     0x31AU,    CANB_RX_STANDARD   },
  { /*   28 */     0x31BU,    CANB_RX_STANDARD   },
  { /*   29 */     0x1A2U,    CANB_RX_STANDARD   },
  { /*   30 */     0x582U,    CANB_RX_STANDARD   },
  { /*   31 */     0x123U,    CANB_RX_STANDARD   },
  { /*   32 */     0x395U,    CANB_RX_STANDARD   },
  { /*   33 */     0x491U,    CANB_RX_STANDARD   },
  { /*   34 */     0x382U,    CANB_RX_STANDARD   },
  { /*   35 */     0x384U,    CANB_RX_STANDARD   },
  { /*   36 */     0x530U,    CANB_RX_STANDARD   },
  { /*   37 */     0x533U,    CANB_RX_STANDARD   },
  { /*   38 */     0x535U,    CANB_RX_STANDARD   },
  { /*   39 */     0x532U,    CANB_RX_STANDARD   },
  { /*   40 */     0x325U,    CANB_RX_STANDARD   },
  { /*   41 */     0x1A5U,    CANB_RX_STANDARD   },
  { /*   42 */     0x5A3U,    CANB_RX_STANDARD   },
  { /*   43 */     0xC8U,    CANB_RX_STANDARD   },
  { /*   44 */     0x361U,    CANB_RX_STANDARD   },
  { /*   45 */     0x537U,    CANB_RX_STANDARD   },
  { /*   46 */     0x400U,    CANB_RX_STANDARD   },
  { /*   47 */     0x730U,    CANB_RX_STANDARD   },
  { /*   48 */     0x7DFU,    CANB_RX_STANDARD   },
  { /*   49 */     0x381U,    CANB_RX_STANDARD   },
  { /*   50 */     0x385U,    CANB_RX_STANDARD   },
  { /*   51 */     0x383U,    CANB_RX_STANDARD   },
  { /*   52 */     0x380U,    CANB_RX_STANDARD   },
};


/**********************************************************************************************************************
  CanDisp_RxPduMask
**********************************************************************************************************************/
/** 
  \var    CanDisp_RxPduMask
  \brief  Rx-PDU: CAN identifier mask.
*/


CONST(CanDisp_RxPduMaskType, CANDISP_CONST) CanDisp_RxPduMask[CanDisp_Number_Of_Rx_Messages] = {
  /* Index        RxPduMask  */
  /*   0 */     0x07FFU  ,
  /*   1 */     0x07FFU  ,
  /*   2 */     0x07FFU  ,
  /*   3 */     0x07FFU  ,
  /*   4 */     0x07FFU  ,
  /*   5 */     0x07FFU  ,
  /*   6 */     0x07FFU  ,
  /*   7 */     0x07FFU  ,
  /*   8 */     0x07FFU  ,
  /*   9 */     0x07FFU  ,
  /*   10 */     0x07FFU  ,
  /*   11 */     0x07FFU  ,
  /*   12 */     0x07FFU  ,
  /*   13 */     0x07FFU  ,
  /*   14 */     0x07FFU  ,
  /*   15 */     0x07FFU  ,
  /*   16 */     0x07FFU  ,
  /*   17 */     0x07FFU  ,
  /*   18 */     0x07FFU  ,
  /*   19 */     0x07FFU  ,
  /*   20 */     0x07FFU  ,
  /*   21 */     0x07FFU  ,
  /*   22 */     0x07FFU  ,
  /*   23 */     0x07FFU  ,
  /*   24 */     0x07FFU  ,
  /*   25 */     0x07FFU  ,
  /*   26 */     0x07FFU  ,
  /*   27 */     0x07FFU  ,
  /*   28 */     0x07FFU  ,
  /*   29 */     0x07FFU  ,
  /*   30 */     0x07FFU  ,
  /*   31 */     0x07FFU  ,
  /*   32 */     0x07FFU  ,
  /*   33 */     0x07FFU  ,
  /*   34 */     0x07FFU  ,
  /*   35 */     0x07FFU  ,
  /*   36 */     0x07FFU  ,
  /*   37 */     0x07FFU  ,
  /*   38 */     0x07FFU  ,
  /*   39 */     0x07FFU  ,
  /*   40 */     0x07FFU  ,
  /*   41 */     0x07FFU  ,
  /*   42 */     0x07FFU  ,
  /*   43 */     0x07FFU  ,
  /*   44 */     0x07FFU  ,
  /*   45 */     0x07FFU  ,
  /*   46 */     0x0780U  ,/*NM*/
  /*   47 */     0x07FFU  ,
  /*   48 */     0x07FFU  ,
  /*   49 */     0x07FFU  ,
  /*   50 */     0x07FFU  ,
  /*   51 */     0x07FFU  ,
  /*   52 */     0x07FFU  ,
};


/**********************************************************************************************************************
  CanDisp_RxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanDisp_RxPduConfig
  \brief  Rx-PDU configuration table.
  \details
  Element         Description
  UpperPduId      PDU ID defined by upper layer.
  Dlc             Data length code.
  RxIndication    Rx indication function.
*/


CONST(CanDisp_RxPduConfigType, CANDISP_CONST) CanDisp_RxPduConfig[CanDisp_Number_Of_Rx_Messages] = {
    /* Index      UpperPduId                                                    Dlc           RxIndication */
  { /*   0 */     Can_Ch0_Il_Rx_Msg_BCM_0x313                                  ,  8U,           0u            },
  { /*   1 */     Can_Ch0_Il_Rx_Msg_BCM_0x584                                  ,  8U,           0u            },
  { /*   2 */     Can_Ch0_Il_Rx_Msg_BCM_Door_0x310                             ,  8U,           0u            },
  { /*   3 */     Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318                             ,  8U,           0u            },
  { /*   4 */     Can_Ch0_Il_Rx_Msg_BCM_Sts_0x315                              ,  8U,           0u            },
  { /*   5 */     Can_Ch0_Il_Rx_Msg_GW_ABS_Sts_0x221                           ,  8U,           0u            },
  { /*   6 */     Can_Ch0_Il_Rx_Msg_GW_AFS_0x5A0                               ,  8U,           0u            },
  { /*   7 */     Can_Ch0_Il_Rx_Msg_GW_AVM_0x520                               ,  8U,           0u            },
  { /*   8 */     Can_Ch0_Il_Rx_Msg_GW_EMS_0x368                               ,  8U,           0u            },
  { /*   9 */     Can_Ch0_Il_Rx_Msg_GW_EMS_0x636                               ,  8U,           0u            },
  { /*   10 */     Can_Ch0_Il_Rx_Msg_GW_EMS_Power_0x10B                         ,  8U,           0u            },
  { /*   11 */     Can_Ch0_Il_Rx_Msg_GW_EMS_Power_0x366                         ,  8U,           0u            },
  { /*   12 */     Can_Ch0_Il_Rx_Msg_GW_EMS_Sts_Power_0x151                     ,  8U,           0u            },
  { /*   13 */     Can_Ch0_Il_Rx_Msg_GW_EPS_Chassis_0x260                       ,  8U,           0u            },
  { /*   14 */     Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243                ,  8U,           0u            },
  { /*   15 */     Can_Ch0_Il_Rx_Msg_GW_IPM_0x245                               ,  8U,           0u            },
  { /*   16 */     Can_Ch0_Il_Rx_Msg_GW_IPM_0x247                               ,  8U,           0u            },
  { /*   17 */     Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x278                      ,  8U,           0u            },
  { /*   18 */     Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x280                      ,  8U,           0u            },
  { /*   19 */     Can_Ch0_Il_Rx_Msg_GW_IPM_RightLine_0x490                     ,  8U,           0u            },
  { /*   20 */     Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246                       ,  8U,           0u            },
  { /*   21 */     Can_Ch0_Il_Rx_Msg_GW_MRR_FRObj_0x480                         ,  8U,           0u            },
  { /*   22 */     Can_Ch0_Il_Rx_Msg_GW_MRR_FrObj_0x279                         ,  8U,           0u            },
  { /*   23 */     Can_Ch0_Il_Rx_Msg_GW_PAM_0x271                               ,  8U,           0u            },
  { /*   24 */     Can_Ch0_Il_Rx_Msg_GW_PAM_0x274                               ,  8U,           0u            },
  { /*   25 */     Can_Ch0_Il_Rx_Msg_GW_SOD_0x275                               ,  8U,           0u            },
  { /*   26 */     Can_Ch0_Il_Rx_Msg_GW_SRS_0x350                               ,  8U,           0u            },
  { /*   27 */     Can_Ch0_Il_Rx_Msg_GW_SWM_Body_0x31A                          ,  8U,           0u            },
  { /*   28 */     Can_Ch0_Il_Rx_Msg_GW_SWM_MRR_0x31B                           ,  8U,           0u            },
  { /*   29 */     Can_Ch0_Il_Rx_Msg_GW_TBOX_IVI_0x1A2                          ,  8U,           0u            },
  { /*   30 */     Can_Ch0_Il_Rx_Msg_GW_TBOX_time_0x582                         ,  8U,           0u            },
  { /*   31 */     Can_Ch0_Il_Rx_Msg_GW_TCU_GearInfo_Power_0x123                ,  8U,           0u            },
  { /*   32 */     Can_Ch0_Il_Rx_Msg_GW_TCU_Info_0x395                          ,  8U,           0u            },
  { /*   33 */     Can_Ch0_Il_Rx_Msg_IPM_RightLine_0x491                        ,  8U,           0u            },
  { /*   34 */     Can_Ch0_Il_Rx_Msg_MP5_0x382                                  ,  8U,           0u            },
  { /*   35 */     Can_Ch0_Il_Rx_Msg_MP5_0x384                                  ,  8U,           0u            },
  { /*   36 */     Can_Ch0_Il_Rx_Msg_MP5_0x530                                  ,  8U,           0u            },
  { /*   37 */     Can_Ch0_Il_Rx_Msg_MP5_NAV_0x533                              ,  8U,           0u            },
  { /*   38 */     Can_Ch0_Il_Rx_Msg_MP5_Setting_0x535                          ,  8U,           0u            },
  { /*   39 */     Can_Ch0_Il_Rx_Msg_MP5_Windows_0x532                          ,  8U,           0u            },
  { /*   40 */     Can_Ch0_Il_Rx_Msg_PEPS_0x325                                 ,  8U,           0u            },
  { /*   41 */     Can_Ch0_Il_Rx_Msg_PEPS_Start_0x1A5                           ,  8U,           0u            },
  { /*   42 */     Can_Ch0_Il_Rx_Msg_SCMM_0x5A3                                 ,  8U,           0u            },
  { /*   43 */     Can_Ch0_Il_Rx_Msg_SCU_0xC8                                   ,  8U,           0u            },
  { /*   44 */     Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361                            ,  8U,           0u            },
  { /*   45 */     Can_Ch0_Il_Rx_Msg_WACM_WirelessChg_0x537                     ,  8U,           0u            },
  { /*   46 */     Can_Ch0_Nm_Rx_Msg_NM_BaseId                                  ,  8U,           1u            },
  { /*   47 */     Can_Ch0_Tp_Rx_Msg_Tester_DiagReqToIC                         ,  8U,           2u            },
  { /*   48 */     Can_Ch0_Tp_Rx_Msg_Tester_DiagFuncReq                         ,  8U,           2u            },
  { /*   49 */     Can_Ch1_Ivi_Rx_Msg_MP5_Audio_TX_0x381                         ,  8U,           3u            },
  { /*   50 */     Can_Ch0_Ivi_Rx_Msg_MP5_Nav_TX_0x385                           ,  8U,           3u            },
  { /*   51 */     Can_Ch1_Ivi_Rx_Msg_MP5_PhoneNum_TX_0x383                      ,  8U,           3u            },
  { /*   52 */     Can_Ch1_Ivi_Rx_Msg_MP5_Phone_TX_0x380                         ,  8U,           3u            },
};


/**********************************************************************************************************************
  CanDisp_TxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanDisp_TxPduConfig
  \brief  Tx-PDUs - configuration.
  \details
  Element              Description
  Hth                  Hardware transmit handle.
  CanId                CAN identifier (16bit / 32bit).
  UpperLayerTxPduId    Upper layer handle ID (8bit / 16bit).
  Controller           Controller.
  Dlc                  Data length code.
  TxConfirmation       Tx confirmation function.
*/


CONST(CanDisp_TxPduConfigType, CANDISP_CONST) CanDisp_TxPduConfig[CanDisp_Number_Of_Tx_Messages] = {
    /* Index    Hth    CanId     TxOption           UpperLayerTxPduId                                   Controller     Dlc    TxConfirmation  Comment */
  { /*   0 */   53U,   0x386U,  CANB_TX_STANDARD,  Can_Ch0_Il_Tx_Msg_IC_0x386_TMH                        ,   1U,         8U,     0U            }, /* CanIl_TxConfirmation    */
  { /*   1 */   54U,   0x387U,  CANB_TX_STANDARD,  Can_Ch0_Il_Tx_Msg_IC_0x387_TMH                        ,   0U,         8U,     0U            }, /* CanIl_TxConfirmation    */
  { /*   2 */   55U,   0x38aU,  CANB_TX_STANDARD,  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH                        ,   0U,         8U,     0U            }, /* CanIl_TxConfirmation    */
  { /*   3 */   56U,   0x510U,  CANB_TX_STANDARD,  Can_Ch0_Il_Tx_Msg_IC_0x510_TMH                        ,   0U,         8U,     0U            }, /* CanIl_TxConfirmation    */
  { /*   4 */   57U,   0x511U,  CANB_TX_STANDARD,  Can_Ch0_Il_Tx_Msg_IC_0x511_TMH                        ,   0U,         8U,     0U            }, /* CanIl_TxConfirmation    */
  { /*   5 */   58U,   0x525U,  CANB_TX_STANDARD,  Can_Ch0_Il_Tx_Msg_IC_0x525_TMH                        ,   0U,         8U,     0U            }, /* CanIl_TxConfirmation    */
  { /*   6 */   59U,   0x581U,  CANB_TX_STANDARD,  Can_Ch0_Il_Tx_Msg_IC_time_0x581_TMH                   ,   0U,         8U,     0U            }, /* CanIl_TxConfirmation    */
  { /*   7 */   60U,   0x430U,  CANB_TX_STANDARD,  Can_Ch0_Nm_Tx_Msg_IC_NM_TMH                           ,   0U,         8U,     1U            }, /* CanNm_TxConfirmation    */
  { /*   8 */   61U,   0x738U,  CANB_TX_STANDARD,  Can_Ch0_Tp_Tx_Msg_IC_DiagResp_TMH                     ,   0U,         8U,     2U            }, /* CanTp_TxConfirmation    */
  { /*   9 */   65U,   0x376U,  CANB_TX_STANDARD,  Can_Ch1_Ivi_Tx_Msg_IC_PhoneNum_0x376_TMH              ,   1U,         8U,     3U            }, /* CanIvi_TxConfirmation    */
  { /*   10 */   62U,   0x377U,  CANB_TX_STANDARD,  Can_Ch1_Ivi_Tx_Msg_IC_0x377_TMH                       ,   1U,         8U,     3U            }, /* CanIvi_TxConfirmation    */
  { /*   11 */   67U,   0x388U,  CANB_TX_STANDARD,  Can_Ch1_Ivi_Tx_Msg_IC_Phone_RX_0x388_TMH              ,   1U,         8U,     3U            }, /* CanIvi_TxConfirmation    */
  { /*   12 */   63U,   0x389U,  CANB_TX_STANDARD,  Can_Ch1_Ivi_Tx_Msg_IC_Audio_RX_0x389_TMH              ,   1U,         8U,     3U            }, /* CanIvi_TxConfirmation    */
  { /*   13 */   66U,   0x38bU,  CANB_TX_STANDARD,  Can_Ch1_Ivi_Tx_Msg_IC_PhoneNum_RX_0x38B_TMH           ,   1U,         8U,     3U            }, /* CanIvi_TxConfirmation    */
  { /*   14 */   64U,   0x38cU,  CANB_TX_STANDARD,  Can_Ch0_Ivi_Tx_Msg_IC_Nav_RX_0x38C_TMH                ,   0U,         8U,     3U            }, /* CanIvi_TxConfirmation    */
};


/**********************************************************************************************************************
  CanDisp_ControllerConfig
**********************************************************************************************************************/
/** 
  \var    CanDisp_ControllerConfig
  \brief  CAN controller configuration - Tx-BasicCAN.
  \details
  Element           Description
  TxBCStartIndex    Tx-BasicCAN start index
  TxBCStopIndex     Tx-BasicCAN stop index
*/ 
CONST(CanDisp_ControllerConfigType, CANDISP_CONST) CanDisp_ControllerConfig[CAN_NUMBER_OF_CHANNELS] = {
    /* Index    TxBCStartIndex  TxBCStopIndex        Comment */
    { /* 0 */     0U,            8U},   /* [BCAN HTH] */ /*CanDisp_Number_Of_Tx_Messages_Ch0 - 1*/
	{ /* 1 */	  0U,			 5U}	/* [PCAN HTH] */ /*CanDisp_Number_Of_Tx_Messages_Ch1 - 1*/
}; /*ch0 tx message number and ch1 tx message number*/


/**********************************************************************************************************************
  CanDisp_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanDisp_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/


CONST(CanDisp_TxConfirmationFctType, CANDISP_CONST) CanDisp_TxConfirmationFctList[CanDisp_Type_Of_Messages] = {\
  /* Index    TxConfirmationFctList              */\
  /*     0 */ (CanDisp_TxConfirmationFctType)CanIl_TxConfirmation            ,\
  /*     1 */ (CanDisp_TxConfirmationFctType)CanNm_TxConfirmation            ,\
  /*     2 */ (CanDisp_TxConfirmationFctType)CanTp_TxConfirmation            ,\
  /*     3 */ (CanDisp_TxConfirmationFctType)CanIvi_TxConfirmation   		 ,\
  /*     4 */ (CanDisp_TxConfirmationFctType)NULL/*CanXcp_TxConfirmation*/   ,\
  /*     5 */ (CanDisp_TxConfirmationFctType)NULL/*CanGw_TxConfirmation*/    \
};


/**********************************************************************************************************************
  CanDisp_WakeUpConfig
**********************************************************************************************************************/
/** 
  var    CanDisp_WakeUpConfig
  brief                 Wake-up source configuration
  details
  Element                Description
  WakeUpSource           Wake-up source identifier
  Controller             CAN controller handle ID
  WakeUpTargetAddress    Logical handle ID of target (CAN controller / transceiver)
  WakeUpTargetModule     Target for wake-up source: CAN controller / transceiver
*/ 

CONST(CanDisp_WakeUpConfigType, CANDISP_CONST) CanDisp_WakeUpConfig[CanDisp_Number_Of_Wake_Channels] = {
    /* Index    WakeUpSource  Controller  WakeUpTargetAddress  WakeUpTargetModule     */
  { /*     0 */         32UL,         0U,                  0U, CANDISP_WAKEUPREQUEST_CAN } 
}; /*finally not used*/

/**********************************************************************************************************************
  CAN ISR Configuration
**********************************************************************************************************************/
/* 
    Mapping of OS ISR func to Can ISR func 
*/
void CanIsr_6func (void)
{
    Can_Interrupt_CAN6_Cat2func();
}

void CanIsr_1func (void)
{
	Can_Interrupt_CAN1_Cat2func();
}


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
