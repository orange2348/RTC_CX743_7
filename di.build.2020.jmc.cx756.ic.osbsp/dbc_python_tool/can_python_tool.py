'''========================================================================
使用方法
--------
can_python_tool
	修改can_python_tool实际路径;
--------
dbc_file
	修改dbc_file实际路径;

Rte_Type_h
	将di.gen.2019.jmc.n356.ic.bsw.osbsp\Appl\GenData目录下的Rte_Type.h复制到can_python_tool目录下.
========================================================================='''

'''========================================================================
History
--------
20180627
	初始版本;
	将dbc提取为json格式;
--------
20180628
	剔除与IC无关的message;
	message按ID从小到大排序;
	signal按sig_start_bit从小到大排序;(类似DFPV_D53_BDC_20180423.dbcZ中IC_TotalOdmeter的担忧是不必要的,CANdb++解析StartBit显示的是lsb(Setting中可设置msb),.dbc文件的StartBit实际是msb,)
--------
20180704
    msg增加msg_signals_counts键,统计一个message中signal的个数,以便自动生成代码.
    msg增加msg_type键,标记message layer,以便自动生成代码.

20181030
	.dbc中新添加的message的MsgSendType必须手动设置,否则对应的默认属性str为NULL,导致解析失败.
	
20181129
	从Rte_Type.h提取RTE随机数,填充到CanCcl_Par_Cfg.c的3个回调数组中.

20181130
	修改CanDisp_Par_Cfg.c的NM TP数组填充内容:CanDisp_RxPduMask(BasicCAN),CanDisp_RxPduMask(0x0780U), BasiId等
	不再需要手动修正.
	
20181204
	TP Function Request和Physical Request在MCAL中不按字母排序,Physical需排在Function前面.
	否则CanTp_Receive()判断首帧FF失败.
	
20190102
	Can_Ch0_Il_Tx_Precopy_Function_Table需要单独处理含rolling counter和checksum的msg.
    
2020
    0x384超时时间5000ms(其它报文2000ms)

20200729
    IC_0x510的前3字节为IC_OdometerMasterValue,需初始化为0xFFFFFF.
    若此信号在IC_0x510中位置或长度有变动,需重新适配.

========================================================================='''

'''========================================================================
待优化项
--------
	
--------


========================================================================='''

'''
注意事项
# --------------------------------------------------------------------------
# SG_ IPM_HMA_HighbeamReq : 55|1@0+ (1,0) [0|1] ""  BCM
# SG_ sig_name : sig_start_bit|sig_length@0+ (1,0) [0|1] ""  sig_receiver
# --------------------------------------------------------------------------
#-定义message的BO_前不能有空格等字符
#-定义SG_的行首只能有且只有1个空格,行尾不要有多余空格等字符
#-定义最后一个SG_的行的下一行必须是空行
#-JMC提供的dbc中,signal不是绝对按StartBit排序的
#-message的自定义属性只含GenMsgSendType, GenMsgCycleTime字段
#-GenMsgSendType取值范围必须为"cycle","event","undefined","undefined","undefined","cycleAndEvent"
#-仪表在dbc中必须定义为IC
#-DaVinci配置新的CAN signal时若未勾选配置RxTimeout,则Rte_Type.h不包含所有配置了RxTimeout的信号的RTE随机数,则自动填充CanCcl_Par_Cfg.c失败!
# -------------------------------------------------------------------------
'''


'''-------------------------------------
//库导入
-------------------------------------'''
import os
import copy
import re #正则
import json
import pdb #debug支持
import math
import time

'''-------------------------------------
//can_python_tool路径,dbc文件路径,生成的json文件存放路径
-------------------------------------'''
#can_python_tool       = 'D:\\works\\projects\\JMC_7.0\\N356_7.0\\11.Software\\N356_CAN\\can_python_tool'#can_python_tool路径
dbc_name                 = 'JMC_SUV_Body_CAN_Matrix_20210104.dbc'
can_python_tool          = os.getcwd()#获取当前can_python_tool.py文件所在目录
dbc_file                 = '..\..\di.gen.2020.jmc.cx756.ic.bsw.osbsp.cfg\project\Config\System' + '\\' + dbc_name #原始dbc文件路径
#dbc_file                 = can_python_tool + '\\' + dbc_name #原始dbc文件路径
dbc_file_filtered        = dbc_file[:-4] + '_filtered.json'#dbc整理为json,备份路径.注意,与IC无关的message已剔除.
dbc_file_filtered_sorted = dbc_file[:-4] + '_filtered_sorted.json'#dbc整理为json并按id排序,备份路径
auto_gen                 = can_python_tool + '\\CX756_Auto_Gen_Files'
Rte_Type_h               = "..\..\di.gen.2020.jmc.cx756.ic.bsw.osbsp\Appl\GenData\Rte_Type.h"#从\Appl\GenData复制到当前目录的
#Rte_Type_h               = can_python_tool + "\\Rte_Type.h"#从\Appl\GenData复制到当前目录的

'''-------------------------------------
//dbc关键字定义
-------------------------------------'''
BO_keyword              = 'BO_ '#'BO ',注意有空格,以区分'NS_ :'字段的BO
SG_keyword              = 'SG_ '#'SG ',注意有空格,以区分'NS_ :'字段的SG
BA_DEF_BO_keyword       = 'BA_DEF_ BO_'#message的自定义属性
GenMsgSendType_keyword  = 'BA_ \"GenMsgSendType\"'#message的自定义属性GenMsgSendType字段
GenMsgCycleTime_keyword = 'BA_ \"GenMsgCycleTime\"'#message的自定义属性GenMsgCycleTime字段
MessageType_keyword     = 'BA_ \"MessageType'#message的自定义属性MessageType字段
Channel_keyword         = 'BA_ \"Channel'#message的自定义属性Channel字段
#BA_DEF_ BO_  "GenMsgSendType" ENUM  "Cyclic","Event","IfActive","CE","CA";

'''-------------------------------------
//global变量定义
-------------------------------------'''
ClusterNodeName  = "IC"#dbc中仪表node name
NM_BASE_ID = "1024"#NM base ID 0X400
Cluster_NM_ID = "1072"#仪表NM ID x430
TESTER = "tester"#测试设备CAN node name

PhysicalAddress = '1840'#0x730
FunctionAddress = '2015'#0x7DF
PhysicalReq     = 'Tester_DiagReqToIC'
FunctionReq     = 'Tester_DiagFuncReq'

EVENT_0X511     = '1297'#0x511

current_status = 'idle'#当前处理状态

current_time = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()) 


#CanDisp_Par_Cfg.h
CanDisp_Type_Of_Messages        = 6
CanDisp_Number_Of_Rx_Messages   = 0
CanDisp_Number_Of_Rx_MBs        = 0
CanDisp_Number_Of_Tx_MBs        = 0
CanDisp_Number_Of_MBs           = 0
CanDisp_Number_Of_Tx_Messages   = 0
CanDisp_Number_Of_Tx_Messages_Ch0 = 0
CanDisp_Number_Of_Tx_Messages_Ch1 = 0
CanDisp_Number_Of_Wake_Channels = 1

#CanCcl_Par_Cfg.h
Can_Ccl_Rx_Num_Messages          = 0
Can_Ccl_Rx_Num_Periodic_Messages = 0
Can_Ccl_Rx_Num_Signals           = 0
Can_Ccl_Rx_Num_Periodic_Signals  = 0
Can_Ccl_Rx_Num_RxAck_Ind         = 0
Can_Ccl_Rx_Num_RxTOut_Ind        = 0
Can_Ccl_Rx_Num_RxInv_Ind         = 0

Can_Ccl_Tx_Num_Messages          = 0
Can_Ccl_Tx_Signal_Num_Signals    = 0
Can_Ccl_Tx_Num_Periodic          = 0
Can_Ccl_Tx_Num_Burst_Periodic    = 0


'''-------------------------------------
//dbc message及signal字典格式定义
-------------------------------------'''
#CAN signal定义
signal = {'sig_name':'', 
		  'sig_start_bit':'', 
		  'sig_length':'',
		  'sig_receiver':'',
		  'sig_is_ic_receiver':'0',
		 }

msg_signals = []#临时存放1个msg解析的signals


#CAN message定义	
msg = {'msg_name':'', 
	   'msg_id':'', 
	   'msg_send_type':'',
	   'msg_cycle_time':'',
	   'msg_dlc':'',
	   'msg_transmitter':'', 
	   'msg_is_ic_receiver':'0',#1:y 0:n
	   'msg_signals_counts':'',#message中signal数目
	   'msg_type':'0',#message type:IL, NM , TP, IVI
	   'msg_signals':'',
	   'msg_channel':'0',#'0':Ch0, '1':Ch1;
	   }

'''
 #CAN Base NM message定义	
BaseNMMessage = 
	   {'msg_name':'BaseNM', 
	   'msg_id':NM_BASE_ID, 
	   'msg_send_type':'1',#event
	   'msg_cycle_time':'0',
	   'msg_dlc':'8',
	   'msg_transmitter':TESTER, 
	   'msg_is_ic_receiver':'1',#1:y 0:n
	   'msg_signals_counts':'9',#message中signal数目
	   'msg_signals':'',
	   'msg_type':"1"#message type:IL, NM , TP, IVI
	   }
'''

dbc_msgs          = []#存放所有的msg
dbc_msgs_filtered = []#存放剔除IC无关的messages
dbc_msgs_sorted   = []#存放合并多个NM RRX后messages,并按Layer排序

dbc_tx_msgs       = []
dbc_rx_msgs       = []
dbc_tx_il_msgs    = []
dbc_rx_il_msgs    = []

rte_random        = []#提取signal随机数

'''====================================
//dbc message及signal解析为json并排序
====================================='''
def dbc_parse_to_json():
	#声明全局变量
	global current_status
	global signal
	global msg_signals
	global msg
	global dbc_msgs
	global dbc_msgs_filtered
	global dbc_msgs_sorted

	signal_count = 0#临时统计一个message中的signal数目

	#打开.dbc文件
	f_dbc = open(dbc_file,'r')#只读
	#f_dbc_file_filtered = open(dbc_file_filtered,'w+')
	#f_dbc_file_filtered_sorted = open(dbc_file_filtered_sorted,'w+')

	all_the_lines=f_dbc.readlines()

	f_dbc.seek(0)
	#f_dbc_file_filtered.seek(0)
	#f_dbc_file_filtered_sorted.seek(0)


	#遍历所有行
	for line in all_the_lines:
		if line.find(BO_keyword) == 0:#'BO_'在行内偏移为0,即行首为'BO_',表示一个msg的开始
			current_status         = 'message_handling'	

			line_split             = line.split(' ')#空格作为分隔符,将行中内容分割为list
			msg['msg_id']          = line_split[1]#id
			msg['msg_name']        = line_split[2][:-1]#name,去除最后的':'
			msg['msg_dlc']         = line_split[3]#dlc
			msg['msg_transmitter'] = line_split[4][:-1]#transmitter,去除最后的'\n'

		elif line.find(SG_keyword) == 1:#'SG_'在行内偏移为1,即行第二个字符为'SG_',表示一个signal的开始
			current_status          = 'signal_handling'
			line_split              = re.split(r'[\s|@]', line)#' ' 或 '|' 或 '@'作为分隔符,将行中内容分割为list. 注意最后receiver字段前究竟1个空格还是2个有点随机.
			signal['sig_name']      = line_split[2]#sig_name
			signal['sig_start_bit'] = line_split[4]#sig_start_bit
			signal['sig_length']    = line_split[5]#sig_length
			signal['sig_receiver']  = line_split[-2]#sig_receiver
			
			if (signal['sig_receiver']).find(ClusterNodeName) != -1:#IC接收该signal
				signal['sig_is_ic_receiver'] = '1'
				msg['msg_is_ic_receiver']    = '1'
				signal_count                 += 1
				msg_signals.append(copy.deepcopy(signal))#必须深拷贝 #只append IC接收的signal.
				signal['sig_is_ic_receiver'] = '0'
			elif msg['msg_transmitter'] == ClusterNodeName:
				signal['sig_is_ic_receiver'] = '0'
				msg['msg_is_ic_receiver']    = '0'
				signal_count                 += 1
				msg_signals.append(copy.deepcopy(signal))#必须深拷贝 #只append IC接收的signal.
		elif line.find(GenMsgSendType_keyword) != -1:
			line_split = re.split(r'[\s]', line)#
			for i in dbc_msgs:
				if i['msg_id'] == line_split[3]:#can id
					i['msg_send_type'] = line_split[4][:-1]#GenMsgSendType; 注意split后为'1;',要去掉';'
		elif line.find(GenMsgCycleTime_keyword) != -1:
			line_split = re.split(r'[\s]', line)#
			for i in dbc_msgs:
				if i['msg_id'] == line_split[3]:#can id
					i['msg_cycle_time'] = line_split[4][:-1]#GenMsgCycleTime; 注意split后为'1;',要去掉';'

		elif line.find(Channel_keyword) != -1:
			line_split = re.split(r'[\s]', line)#
			for i in dbc_msgs:
				if i['msg_id'] == line_split[3]:#can id
					i['msg_channel'] = line_split[4][:-1]#Channel; 注意split后为'1;',要去掉';'					

		elif line.find(MessageType_keyword) != -1:#默认IL的message无此字段,有此字段则表明不是IL,需要修正
			line_split = re.split(r'[\s]', line)#
			#pdb.set_trace() 
			for i in dbc_msgs:
				if i['msg_id'] == line_split[3]:#can id
					i['msg_type'] = line_split[4][:-1]#MessageType; 注意split后为'1;',要去掉';'
					#pdb.set_trace() 
			#print(line)
		
		#一个BO下面的所有SG_解析完毕,写入msg['msg_signals']
		#将BO_解析完毕后添加到dbc_msgs
		if line.strip() == '':#空行
			if (current_status == 'signal_handling'):
				msg["msg_signals_counts"] = signal_count
				signal_count              = 0
				msg["msg_type"]           = "0"#默认IL,若为NM或TP或IVI,则后面处理MessageType_keyword时会修正.
				msg_signals.sort(key      = lambda sig:int(sig['sig_start_bit']))#按sig_start_bit从小到大排序(JMC/DFPV.dbc中一个signal的msb是StartBit) 
				msg['msg_signals']        = msg_signals#msg_signals
				dbc_msgs.append(copy.deepcopy(msg))#deepcopy深拷贝.若浅拷贝,则dbc_msgs中所有元素都是同一个msg的复制.修改了msg,所有元素均受影响
				msg_signals               = [] #必须清空,否则下一个message的signal会在上一个的基础上append.
				msg['msg_is_ic_receiver'] = '0'#必须清空,否则下一个message的signal会在上一个的基础上直接使用旧值.
				current_status            = 'idle'


	#剔除既不是IC发送又不是IC接收的message
	'''
	方法一 失败
	#for + remove会出错,如[1,2,3,4],删除2后为[1,3,4],此时i指向第三个3元素4,预期的第三个元素3因为2被删除而往前挪了.
	#dbc_msgs_filtered = copy.deepcopy(dbc_msgs)
	for i in dbc_msgs_filtered:
		if ((i['msg_transmitter'] != ClusterNodeName) and (i['msg_is_ic_receiver'] != '1')):#既不是IC发送又不是IC接收的message
			#dbc_msgs_filtered.remove(i)#无法使用del dbc_msgs_filtered[i],因为i是dict而不是integer
			#print('---------found one----------')
			#print(i['msg_name'])
			#print('\n')
			pass
		#print('---------i----------')
		print(i['msg_name'])
		print('\n')
		#pdb.set_trace() 
	'''
	'''
	方法二 OK
	'''
	for i in dbc_msgs:
		if ((i['msg_transmitter'] == ClusterNodeName) or (i['msg_is_ic_receiver'] == '1')):#是IC发送或是IC接收的message
			dbc_msgs_filtered.append(i)
		#pdb.set_trace() 



	#将过滤好的dict格式的dbc转化为json格式保存到dbc_file_filtered
	#f_dbc_file_filtered.write(json.dumps(dbc_msgs_filtered))

	#将过滤好的dict格式的dbc按id排序, 然后转化为json格式保存到dbc_file_filtered_sorted
	dbc_msgs_filtered.sort(key = lambda msg:int(msg['msg_id']))#dbc_msgs_filtered为list,元素list[i]为dict, 元素按dict['msg_id']关键字排序.注意,dict['msg_id']为string,排序时'123' < '13',故转为int比较.



	#多个NM RX剔除,只保留1个, 并将其ID替换为NM_BASE_ID.
	NMMessageSelected = 0
	NMMessage = {}
	for i in dbc_msgs_filtered:
		#pdb.set_trace() 
		if i["msg_type"] == "1":#NM message
			if i["msg_is_ic_receiver"] == "1":#NM RX message
				if NMMessageSelected == 0:
					NMMessage         = i#保存1个NM message
					NMMessageSelected = 1
				continue#不再append任何NM RX message
		#pdb.set_trace() 
		dbc_msgs_sorted.append(i)

	if 	NMMessageSelected == 1:#存在NM Message
		NMMessage["msg_name"]    = "NM_BaseId"
		NMMessage["msg_id"]      = NM_BASE_ID
		dbc_msgs_sorted.append(NMMessage)

	dbc_msgs_sorted.sort(key = lambda msg:[int(msg["msg_type"]), int(msg['msg_id'])])#先按msg layer排序,同layer内按msg ID排序
	#f_dbc_file_filtered_sorted.write(json.dumps(dbc_msgs_sorted))


	f_dbc.close()
	#f_dbc_file_filtered.close()
	#f_dbc_file_filtered_sorted.close()
#end of dbc_parse_to_json()



'''====================================
write_const_string
--
写入不需修改的部分

===================================='''
def write_const_string(file_handle, const_string):
	file_handle.write(const_string)



'''====================================
CanDisp_Cfg.h
--
基本不需修改.
CAN_NUMBER_OF_CHANNELS,
CAN_RXQ_SIZE,
CAN_TXQ_SIZE,
===================================='''
def CanDisp_Cfg_h():
	pass




'''====================================
CanDisp_Par_Cfg.h
--
#define CanDisp_Type_Of_Messages             6u//Defines the number of different types of Messages supported
#define CanDisp_Number_Of_Rx_Messages        26u//Defines the number of Receive messages for the node in the CAN Network database file (*.dbc)
#define CanDisp_Number_Of_Rx_MBs             26u//Defines the number of Receive mailboxes configured in MCAL both Basic and Full CAN
#define CanDisp_Number_Of_Tx_MBs             5u//Defines the number of Transmit mailboxes configured in MCAL both Basic and Full CAN
#define CanDisp_Number_Of_MBs                31u//Defines the number of mailboxes configured in MCAL both Basic and Full CAN and both Transmit and receive
#define CanDisp_Number_Of_Tx_Messages        5u//Defines the number of transmit messages configured for the node
#define CanDisp_Number_Of_Wake_Channels      1u
===================================='''
def CanDisp_Par_Cfg_h():
    global dbc_msgs_sorted
    global ClusterNodeName
    global CanDisp_Number_Of_Rx_Messages
    global CanDisp_Number_Of_Rx_MBs
    global CanDisp_Number_Of_Tx_MBs
    global CanDisp_Number_Of_MBs
    global CanDisp_Number_Of_Tx_Messages
    global CanDisp_Number_Of_Tx_Messages_Ch0
    global CanDisp_Number_Of_Tx_Messages_Ch1

    for i in dbc_msgs_sorted:
        if (i['msg_transmitter'] == ClusterNodeName):
            CanDisp_Number_Of_Tx_MBs += 1
            if (i['msg_channel'] == '1'):
                CanDisp_Number_Of_Tx_Messages_Ch1 += 1
            else:
                CanDisp_Number_Of_Tx_Messages_Ch0 += 1

        elif (i['msg_is_ic_receiver'] == '1'):
            CanDisp_Number_Of_Rx_MBs += 1

    CanDisp_Number_Of_MBs             = CanDisp_Number_Of_Tx_MBs + CanDisp_Number_Of_Rx_MBs
    CanDisp_Number_Of_Rx_Messages     = CanDisp_Number_Of_Rx_MBs
    CanDisp_Number_Of_Tx_Messages     = CanDisp_Number_Of_Tx_MBs
	
    path_CanDisp_Par_Cfg_h = auto_gen + '\\CanDisp_Par_Cfg.h'#CanDisp_Par_Cfg.h路径
    f_CanDisp_Par_Cfg_h    = open(path_CanDisp_Par_Cfg_h, 'w+')

    write_const_string(f_CanDisp_Par_Cfg_h,
'''#if !defined( CAN_DISP_APP_CFG_H )
#define CAN_DISP_APP_CFG_H

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
**  Name:           CanDisp_Par_Cfg.h
**
**  Description:    CAN Dispatcher configuration parameters for configured 
**                    database
**
**  Organization:   Vehicle Communications
**                  Visteon Corporation
**
**  =========================================================================*/
/* ===========================================================================
** I N C L U D E   F I L E S
** =========================================================================*/

# include "Compiler.h"
# include "CanDisp_Cfg.h"
# include "CanDisp_Defines.h"

/*===========================================================================
** M A C R O   D E F I N I T I O N S
** =========================================================================*/

#ifndef ControllerId
#define ControllerId            (0u)
#endif

''')

    f_CanDisp_Par_Cfg_h.write('#define CanDisp_Type_Of_Messages             6u\n')
    f_CanDisp_Par_Cfg_h.write('#define CanDisp_Number_Of_Rx_Messages        %du /*ch0 and ch1 total*/\n'%CanDisp_Number_Of_Rx_Messages)
    f_CanDisp_Par_Cfg_h.write('#define CanDisp_Number_Of_Rx_MBs             %du /*finally not used*/\n'%CanDisp_Number_Of_Rx_MBs)
    f_CanDisp_Par_Cfg_h.write('#define CanDisp_Number_Of_Tx_MBs             %du /*finally not used*/\n'%CanDisp_Number_Of_Tx_MBs)
    f_CanDisp_Par_Cfg_h.write('#define CanDisp_Number_Of_MBs                %du /*ch0 and ch1 total*/\n'%CanDisp_Number_Of_MBs)
    f_CanDisp_Par_Cfg_h.write('#define CanDisp_Number_Of_Tx_Messages        %du /*ch0 and ch1 total*/\n'%CanDisp_Number_Of_Tx_Messages)
    f_CanDisp_Par_Cfg_h.write('#define CanDisp_Number_Of_Tx_Messages_Ch0    %du /*ch0 tx total*/\n'%CanDisp_Number_Of_Tx_Messages_Ch0)
    f_CanDisp_Par_Cfg_h.write('#define CanDisp_Number_Of_Tx_Messages_Ch1    %du /*ch1 tx total*/\n'%CanDisp_Number_Of_Tx_Messages_Ch1)
    f_CanDisp_Par_Cfg_h.write('#define CanDisp_Number_Of_Wake_Channels      1u /*finally not used*/\n')

    write_const_string(f_CanDisp_Par_Cfg_h,
'''/* ===========================================================================
** G L O B A L   C O N S T A N T   D E C L A R A T I O N S
** =========================================================================*/
/**********************************************************************************************************************
  CanDisp_RxIndicationFctList
**********************************************************************************************************************/
/** 
  var    CanDisp_RxIndicationFctList
  brief  Rx indication functions table.
  details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
extern CONST(CanDisp_RxIndicationFctListType, CANDISP_CONST) CanDisp_RxIndicationFctList[CanDisp_Type_Of_Messages]; 

/**********************************************************************************************************************
  CanDisp_RxPduConfig
**********************************************************************************************************************/
/** 
  var    CanDisp_RxPduConfig
  brief  Rx-PDU configuration table.
  details
  Element         Description
  UpperPduId      PDU ID defined by upper layer.
  Dlc             Data length code.
  RxIndication    Rx indication function.
*/
extern CONST(CanDisp_RxPduConfigType, CANDISP_CONST) CanDisp_RxPduConfig[CanDisp_Number_Of_Rx_Messages];

/**********************************************************************************************************************
  CanDisp_RxPduCanId
**********************************************************************************************************************/
/** 
  var    CanDisp_RxPduCanId
  brief  Rx-PDU: CAN identifier.
*/ 
extern CONST(CanDisp_RxPduCanIdentType, CANDISP_CONST) CanDisp_RxPduCanId[CanDisp_Number_Of_Rx_Messages];

/**********************************************************************************************************************
  CanDisp_ControllerConfig
**********************************************************************************************************************/
/** 
  var    CanDisp_ControllerConfig
  brief  CAN controller configuration - Tx-BasicCAN.
  details
  Element           Description
  TxBCStartIndex    Tx-BasicCAN start index
  TxBCStopIndex     Tx-BasicCAN stop index
*/ 
extern CONST(CanDisp_ControllerConfigType, CANDISP_CONST) CanDisp_ControllerConfig[CAN_NUMBER_OF_CHANNELS];

/**********************************************************************************************************************
  CanDisp_MailBoxConfig
**********************************************************************************************************************/
/** 
  var    CanDisp_MailBoxConfig
  brief  Mailbox table.
  details
  Element        Description
  PduIdFirst     "First" PDU mapped to mailbox.
  PduIdLast      "Last" PDU mapped to mailbox.
  Controller     Handle ID of controller.
  MailBoxType    Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
extern CONST(CanDisp_MailBoxConfigType, CANDISP_CONST) CanDisp_MailBoxConfig[CanDisp_Number_Of_MBs];

/**********************************************************************************************************************
  CanDisp_RxPduMask
**********************************************************************************************************************/
/** 
  var    CanDisp_RxPduMask
  brief  Rx-PDU: CAN identifier mask.
*/ 
extern CONST(CanDisp_RxPduMaskType, CANDISP_CONST) CanDisp_RxPduMask[CanDisp_Number_Of_Rx_Messages];

/**********************************************************************************************************************
  CanDisp_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  var    CanDisp_TxConfirmationFctList
  brief  Tx confirmation functions table.
*/ 
extern CONST(CanDisp_TxConfirmationFctType, CANDISP_CONST) CanDisp_TxConfirmationFctList[CanDisp_Type_Of_Messages];

/**********************************************************************************************************************
  CanDisp_TxPduConfig
**********************************************************************************************************************/
/** 
  var    CanDisp_TxPduConfig
  brief  Tx-PDUs - configuration.
  details
  Element              Description
  Hth                  Hardware transmit handle.
  CanId                CAN identifier (16bit / 32bit).
  UpperLayerTxPduId    Upper layer handle ID (8bit / 16bit).
  Controller           Controller.
  Dlc                  Data length code.
  TxConfirmation       Tx confirmation function.
*/ 
extern CONST(CanDisp_TxPduConfigType, CANDISP_CONST) CanDisp_TxPduConfig[CanDisp_Number_Of_Tx_Messages];


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

extern CONST(CanDisp_WakeUpConfigType, CANDISP_CONST) CanDisp_WakeUpConfig[CanDisp_Number_Of_Wake_Channels];


#endif /* CAN_DISP_APP_CFG_H */
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
Date          : %s
By              : ChengJia
Traceability    : %s
Change Description  : Tool Generated code
*****************************************************************************/
'''%(current_time, dbc_name))

    f_CanDisp_Par_Cfg_h.close()



'''====================================
CanDisp_Par_Cfg.c
--
===================================='''
def CanDisp_Par_Cfg_c():

	global CanDisp_Number_Of_Rx_Messages
	global CanDisp_Number_Of_Rx_MBs
	global CanDisp_Number_Of_Tx_MBs
	global CanDisp_Number_Of_MBs
	global CanDisp_Number_Of_Tx_Messages
	global CanDisp_Number_Of_Tx_Messages_Ch0
	global CanDisp_Number_Of_Tx_Messages_Ch1

	global dbc_msgs_sorted
	global dbc_tx_msgs
	global dbc_rx_msgs
	global dbc_tx_il_msgs
	global dbc_rx_il_msgs

	Index      = 0
	PduIdFirst = 0
	PduIdLast  = 0
	Controller = 0

	#分RX TX
	#(1 - msg_is_ic_receiver):将RX排在前面
	for i in dbc_msgs_sorted:
		if i['msg_is_ic_receiver'] == '1':#RX
			dbc_rx_msgs.append(i)
		else:
			dbc_tx_msgs.append(i)#TX

	#RX内按msg layer排序, 同layer内按msg name排序
	dbc_rx_msgs.sort(key = lambda msg:[int(msg['msg_type']), msg['msg_name']])
	dbc_tx_msgs.sort(key = lambda msg:[int(msg['msg_type']), msg['msg_name']])

	path_CanDisp_Par_Cfg_c = auto_gen + '\\CanDisp_Par_Cfg.c'#CanDisp_Par_Cfg.c路径
	f_CanDisp_Par_Cfg_c    = open(path_CanDisp_Par_Cfg_c, 'w+')
	

	write_const_string(f_CanDisp_Par_Cfg_c, 
'''/* ===========================================================================
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
  \\var    CanDisp_RxIndicationFctList
  \\brief  Rx indication functions table.
  \\details
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
	  \\var    CanDisp_MailBoxConfig
	  \\brief  Mailbox table.
	  \\details
	  Element        Description
	  PduIdFirst     "First" PDU mapped to mailbox.
	  PduIdLast      "Last" PDU mapped to mailbox.
	  Controller     Handle ID of controller.
	  MailBoxType    Type of mailbox: Rx BasicCAN/FullCAN/unused.
	  */


''')

	#CanDisp_MailBoxConfig#----------------------------------------------------------------------------------------------------------
	f_CanDisp_Par_Cfg_c.write('	  CONST(CanDisp_MailBoxConfigType, CANDISP_CONST) CanDisp_MailBoxConfig[CanDisp_Number_Of_MBs] = {\n')
	f_CanDisp_Par_Cfg_c.write('	  /* Index      PduIdFirst   PduIdLast   Controller   MailBoxType */ \n')
	for i in range(0, CanDisp_Number_Of_Rx_Messages):
		if (dbc_rx_msgs[i]['msg_id'] == NM_BASE_ID):#NM Message
			f_CanDisp_Par_Cfg_c.write('  { /*   %d */     %dU ,         %dU ,       0U,       CANDISP_RxBasicCANMailbox  },/*%XU*//*NM*/\n'%(Index, PduIdFirst, PduIdLast, int(dbc_rx_msgs[i]['msg_id'])))
		else:
			Controller = int(dbc_rx_msgs[i]['msg_channel'])
			f_CanDisp_Par_Cfg_c.write('  { /*   %d */     %dU ,         %dU ,       %dU,       CANDISP_RxFullCANMailbox  },/*%XU*/\n'%(Index, PduIdFirst, PduIdLast, Controller, int(dbc_rx_msgs[i]['msg_id'])))
		Index      += 1
		PduIdFirst += 1
		PduIdLast  += 1

	for i in range(0, CanDisp_Number_Of_Tx_Messages):
		Controller = int(dbc_tx_msgs[i]['msg_channel'])
		f_CanDisp_Par_Cfg_c.write('  { /*   %d */     %dU ,         %dU ,       %dU,       CANDISP_TxFullCANMailbox  },/*%XU*/\n'%(Index, PduIdFirst, PduIdLast, Controller, int(dbc_tx_msgs[i]['msg_id'])))
		Index      += 1
		PduIdFirst += 1
		PduIdLast  += 1
	f_CanDisp_Par_Cfg_c.write('};\n\n')



	#CanDisp_RxPduCanId#----------------------------------------------------------------------------------------------------------

	write_const_string(f_CanDisp_Par_Cfg_c,
'''
/**********************************************************************************************************************
  CanDisp_RxPduCanId
**********************************************************************************************************************/
/** 
  \\var    CanDisp_RxPduCanId
  \\brief  Rx-PDU: CAN identifier.
*/


''')


	f_CanDisp_Par_Cfg_c.write('CONST(CanDisp_RxPduCanIdentType, CANDISP_CONST) CanDisp_RxPduCanId[CanDisp_Number_Of_Rx_Messages] = {\n')
	f_CanDisp_Par_Cfg_c.write('    /* Index     RxPduCanId   RxOption          */\n')
	for i in range(0, CanDisp_Number_Of_Rx_Messages):
		if (dbc_rx_msgs[i]['msg_id'] == FunctionAddress):#0X7DF调整到0X738后面
			f_CanDisp_Par_Cfg_c.write('  { /*   %d */     0x%XU,    CANB_RX_STANDARD   },\n'%(i, int(PhysicalAddress)))
		elif (dbc_rx_msgs[i]['msg_id'] == PhysicalAddress):	
			f_CanDisp_Par_Cfg_c.write('  { /*   %d */     0x%XU,    CANB_RX_STANDARD   },\n'%(i, int(FunctionAddress)))
		else:
			f_CanDisp_Par_Cfg_c.write('  { /*   %d */     0x%XU,    CANB_RX_STANDARD   },\n'%(i, int(dbc_rx_msgs[i]['msg_id'])))
	f_CanDisp_Par_Cfg_c.write('};\n\n')

	#CanDisp_RxPduMask#----------------------------------------------------------------------------------------------------------
	write_const_string(f_CanDisp_Par_Cfg_c,
'''
/**********************************************************************************************************************
  CanDisp_RxPduMask
**********************************************************************************************************************/
/** 
  \\var    CanDisp_RxPduMask
  \\brief  Rx-PDU: CAN identifier mask.
*/


''')
	f_CanDisp_Par_Cfg_c.write('CONST(CanDisp_RxPduMaskType, CANDISP_CONST) CanDisp_RxPduMask[CanDisp_Number_Of_Rx_Messages] = {\n')
	f_CanDisp_Par_Cfg_c.write('  /* Index        RxPduMask  */\n')
	for i in range(0, CanDisp_Number_Of_Rx_Messages):
		if (dbc_rx_msgs[i]['msg_id'] == NM_BASE_ID):#NM Message
			f_CanDisp_Par_Cfg_c.write('  /*   %d */     0x0780U  ,/*NM*/\n'%(i))#需据客户提供的NM Message范围配置MCAL CAN 掩码
		else:
			f_CanDisp_Par_Cfg_c.write('  /*   %d */     0x07FFU  ,\n'%(i))
	f_CanDisp_Par_Cfg_c.write('};\n\n')


	#CanDisp_RxPduConfig#----------------------------------------------------------------------------------------------------------
	write_const_string(f_CanDisp_Par_Cfg_c,
'''
/**********************************************************************************************************************
  CanDisp_RxPduConfig
**********************************************************************************************************************/
/** 
  \\var    CanDisp_RxPduConfig
  \\brief  Rx-PDU configuration table.
  \\details
  Element         Description
  UpperPduId      PDU ID defined by upper layer.
  Dlc             Data length code.
  RxIndication    Rx indication function.
*/


''')
	f_CanDisp_Par_Cfg_c.write('CONST(CanDisp_RxPduConfigType, CANDISP_CONST) CanDisp_RxPduConfig[CanDisp_Number_Of_Rx_Messages] = {\n')
	f_CanDisp_Par_Cfg_c.write('    /* Index      UpperPduId                                                    Dlc           RxIndication */\n')
	for i in range(0, CanDisp_Number_Of_Rx_Messages):
		type = dbc_rx_msgs[i]['msg_type']
		layer  = 'Il'
		if type == '1':
			layer  = 'Nm'
		elif type == '2':
			layer = 'Tp'
		elif type == '3':
			layer = 'Ivi'
			
		#%-40s表示若%s不足40个字符则在右侧补齐空格
		if (dbc_rx_msgs[i]['msg_id'] == FunctionAddress):#0X7DF调整到0X738后面
			f_CanDisp_Par_Cfg_c.write('  { /*   %d */     Can_Ch0_%s_Rx_Msg_%-40s   ,  %dU,           %du            },\n'%(i, layer, PhysicalReq, int(dbc_rx_msgs[i]['msg_dlc']), int(type)))
		elif (dbc_rx_msgs[i]['msg_id'] == PhysicalAddress):	
			f_CanDisp_Par_Cfg_c.write('  { /*   %d */     Can_Ch0_%s_Rx_Msg_%-40s   ,  %dU,           %du            },\n'%(i, layer, FunctionReq, int(dbc_rx_msgs[i]['msg_dlc']), int(type)))
		else:
			if layer == 'Il':
				f_CanDisp_Par_Cfg_c.write('  { /*   %d */     Can_Ch0_%s_Rx_Msg_%-40s   ,  %dU,           %du            },\n'%(i, layer, dbc_rx_msgs[i]['msg_name'], int(dbc_rx_msgs[i]['msg_dlc']), int(type)))
			else:
				f_CanDisp_Par_Cfg_c.write('  { /*   %d */     Can_Ch%d_%s_Rx_Msg_%-40s   ,  %dU,           %du            },\n'%(i, int(dbc_rx_msgs[i]['msg_channel']) ,layer, dbc_rx_msgs[i]['msg_name'], int(dbc_rx_msgs[i]['msg_dlc']), int(type)))
	f_CanDisp_Par_Cfg_c.write('};\n\n')


	#CanDisp_TxPduConfig#----------------------------------------------------------------------------------------------------------
	write_const_string(f_CanDisp_Par_Cfg_c,
'''
/**********************************************************************************************************************
  CanDisp_TxPduConfig
**********************************************************************************************************************/
/** 
  \\var    CanDisp_TxPduConfig
  \\brief  Tx-PDUs - configuration.
  \\details
  Element              Description
  Hth                  Hardware transmit handle.
  CanId                CAN identifier (16bit / 32bit).
  UpperLayerTxPduId    Upper layer handle ID (8bit / 16bit).
  Controller           Controller.
  Dlc                  Data length code.
  TxConfirmation       Tx confirmation function.
*/


''')
	#TX内按msg layer排序, 同layer内按msg name排序
	dbc_tx_msgs.sort(key = lambda msg:[int(msg['msg_type']), msg['msg_name']])
	msg_temp = {}
	tx_msgs  = []
	for i in range(0, CanDisp_Number_Of_Tx_Messages):
		msg_temp = dbc_tx_msgs[i]
		msg_temp['Hth'] = CanDisp_Number_Of_Rx_Messages + i #新建key 'Hth'
		tx_msgs.append(msg_temp)

	#TX内按msg layer排序, 同layer内按msg ID排序
	tx_msgs.sort(key = lambda msg:[int(msg['msg_type']), int(msg['msg_id'])])
	f_CanDisp_Par_Cfg_c.write('CONST(CanDisp_TxPduConfigType, CANDISP_CONST) CanDisp_TxPduConfig[CanDisp_Number_Of_Tx_Messages] = {\n')
	f_CanDisp_Par_Cfg_c.write('    /* Index    Hth    CanId     TxOption           UpperLayerTxPduId                                   Controller     Dlc    TxConfirmation  Comment */\n')
	for i in range(0, CanDisp_Number_Of_Tx_Messages):
		type    = tx_msgs[i]['msg_type']
		layer   = 'Il'
		UpperLayerTxPduId = tx_msgs[i]['msg_name']
		if type == '1':
			layer  = 'Nm'
			UpperLayerTxPduId = 'IC_NM'
		elif type == '2':
			layer = 'Tp'
		elif type == '3':
			layer = 'Ivi'
		
		if layer   == 'Il':
			f_CanDisp_Par_Cfg_c.write('  { /*   %d */   %dU,   0x%xU,  CANB_TX_STANDARD,  %-50s    ,   %dU,         %dU,     %dU            }, /* Can%s_TxConfirmation    */\n'%(i, tx_msgs[i]['Hth'], int(tx_msgs[i]['msg_id']), ('Can_Ch0_' + layer + '_Tx_Msg_' + UpperLayerTxPduId + '_TMH'), int(tx_msgs[i]['msg_channel']), int(tx_msgs[i]['msg_dlc']), int(type), layer))#
			
		else:
			f_CanDisp_Par_Cfg_c.write('  { /*   %d */   %dU,   0x%xU,  CANB_TX_STANDARD,  %-50s    ,   %dU,         %dU,     %dU            }, /* Can%s_TxConfirmation    */\n'%(i, tx_msgs[i]['Hth'], int(tx_msgs[i]['msg_id']), ('Can_Ch' + tx_msgs[i]['msg_channel'] + '_' + layer + '_Tx_Msg_' + UpperLayerTxPduId + '_TMH'), int(tx_msgs[i]['msg_channel']), int(tx_msgs[i]['msg_dlc']), int(type), layer))#
	f_CanDisp_Par_Cfg_c.write('};')

	write_const_string(f_CanDisp_Par_Cfg_c,
'''


/**********************************************************************************************************************
  CanDisp_ControllerConfig
**********************************************************************************************************************/
/** 
  \\var    CanDisp_ControllerConfig
  \\brief  CAN controller configuration - Tx-BasicCAN.
  \\details
  Element           Description
  TxBCStartIndex    Tx-BasicCAN start index
  TxBCStopIndex     Tx-BasicCAN stop index
*/ 
CONST(CanDisp_ControllerConfigType, CANDISP_CONST) CanDisp_ControllerConfig[CAN_NUMBER_OF_CHANNELS] = {
    /* Index    TxBCStartIndex  TxBCStopIndex        Comment */
    { /* 0 */     0U,            %dU},   /* [BCAN HTH] */ /*CanDisp_Number_Of_Tx_Messages_Ch0 - 1*/
	{ /* 1 */	  0U,			 %dU}	/* [PCAN HTH] */ /*CanDisp_Number_Of_Tx_Messages_Ch1 - 1*/
}; /*ch0 tx message number and ch1 tx message number*/


/**********************************************************************************************************************
  CanDisp_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \\var    CanDisp_TxConfirmationFctList
  \\brief  Tx confirmation functions table.
*/


CONST(CanDisp_TxConfirmationFctType, CANDISP_CONST) CanDisp_TxConfirmationFctList[CanDisp_Type_Of_Messages] = {\\
  /* Index    TxConfirmationFctList              */\\
  /*     0 */ (CanDisp_TxConfirmationFctType)CanIl_TxConfirmation            ,\\
  /*     1 */ (CanDisp_TxConfirmationFctType)CanNm_TxConfirmation            ,\\
  /*     2 */ (CanDisp_TxConfirmationFctType)CanTp_TxConfirmation            ,\\
  /*     3 */ (CanDisp_TxConfirmationFctType)CanIvi_TxConfirmation   		 ,\\
  /*     4 */ (CanDisp_TxConfirmationFctType)NULL/*CanXcp_TxConfirmation*/   ,\\
  /*     5 */ (CanDisp_TxConfirmationFctType)NULL/*CanGw_TxConfirmation*/    \\
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
Date          : %s
By              : ChengJia
Traceability    : %s
Change Description  : Tool Generated code
*****************************************************************************/
'''%((CanDisp_Number_Of_Tx_Messages_Ch0 - 1), (CanDisp_Number_Of_Tx_Messages_Ch1 - 1), current_time, dbc_name))

	f_CanDisp_Par_Cfg_c.close()


'''====================================
CanCcl_Par_Cfg.h
--
===================================='''
def CanCcl_Par_Cfg_h():
	global	Can_Ccl_Rx_Num_Messages
	global	Can_Ccl_Rx_Num_Periodic_Messages
	global	Can_Ccl_Rx_Num_Signals
	global	Can_Ccl_Rx_Num_Periodic_Signals
	global	Can_Ccl_Rx_Num_RxAck_Ind
	global	Can_Ccl_Rx_Num_RxTOut_Ind
	global	Can_Ccl_Rx_Num_RxInv_Ind
		
	global	Can_Ccl_Tx_Num_Messages
	global	Can_Ccl_Tx_Signal_Num_Signals
	global	Can_Ccl_Tx_Num_Periodic
	global	Can_Ccl_Tx_Num_Burst_Periodic

	global dbc_msgs_sorted
	global dbc_tx_msgs
	global dbc_rx_msgs
	global dbc_tx_il_msgs
	global dbc_rx_il_msgs

	
	dbc_rx_il_msgs = []
	for i in dbc_rx_msgs:
		if i['msg_type'] == '0':
			Can_Ccl_Rx_Num_Messages += 1
			dbc_rx_il_msgs.append(i)#提取RX IL msgs

	for i in dbc_rx_il_msgs:
		if i['msg_send_type'] == '0' or i['msg_send_type'] == '3':#0:cycle 1:event 3:cycleAdnevent
			Can_Ccl_Rx_Num_Periodic_Messages += 1
			Can_Ccl_Rx_Num_Periodic_Signals += i['msg_signals_counts']

		Can_Ccl_Rx_Num_Signals += i['msg_signals_counts']


	dbc_tx_il_msgs = []
	for i in dbc_tx_msgs:
		if i['msg_type'] == '0':
			Can_Ccl_Tx_Num_Messages += 1
			dbc_tx_il_msgs.append(i)#提取TX IL msgs


	for i in dbc_tx_il_msgs:
		if i['msg_send_type'] == '0' or i['msg_send_type'] == '1' or i['msg_send_type'] == '3':#0:cycle 1:event 3:cycleAdnevent
			Can_Ccl_Tx_Num_Periodic += 1
		#print(i)
		Can_Ccl_Tx_Signal_Num_Signals += i['msg_signals_counts']


	path_CanCcl_Par_Cfg_h = auto_gen + '\\CanCcl_Par_Cfg.h'#CanCcl_Par_Cfg.h路径
	f_CanCcl_Par_Cfg_h = open(path_CanCcl_Par_Cfg_h, 'w+')




	write_const_string(f_CanCcl_Par_Cfg_h,
'''#if !defined( CCL_APP_CFG_H )
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
''')


	#----------------------------------------------------------------------------------------------------------
	f_CanCcl_Par_Cfg_h.write(
'''
#define Can_Ccl_Rx_Num_Messages                 (%du)
#define Can_Ccl_Rx_Num_Periodic_Messages        (%du) /*no use*/
#define Can_Ccl_Rx_Num_Signals                  (%du)
#define Can_Ccl_Rx_Num_Periodic_Signals         (%du) /*no use*/
#define Can_Ccl_Rx_Num_RxAck_Ind                (%du)
#define Can_Ccl_Rx_Num_RxTOut_Ind               (%du)
#define Can_Ccl_Rx_Num_RxInv_Ind                (%du)

#define Can_Ccl_Tx_Num_Messages                 (%du)
#define Can_Ccl_Tx_Signal_Num_Signals           (%du)
#define Can_Ccl_Tx_Num_Periodic                 (%du)
#define Can_Ccl_Tx_Num_Burst_Periodic           (0u)
'''%(Can_Ccl_Rx_Num_Messages, 
Can_Ccl_Rx_Num_Periodic_Messages, 
Can_Ccl_Rx_Num_Signals, 
Can_Ccl_Rx_Num_Periodic_Signals, 
Can_Ccl_Rx_Num_Signals, 
Can_Ccl_Rx_Num_Signals, 
1, 
Can_Ccl_Tx_Num_Messages, 
Can_Ccl_Tx_Signal_Num_Signals, 
Can_Ccl_Tx_Num_Periodic))

	#f_CanCcl_Par_Cfg_h.write('\n\n')
	write_const_string(f_CanCcl_Par_Cfg_h,
'''
#define Can_Ccl_Num_Of_PduGroups                (2u)
  #define CCL_MAX_IPDUGROUPVECTOR_BYTES           (1u) 


/*Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
  /*      Symbolic Name                                  Value   Active in predefined variant(s) */
  #define CanCclConf_IPduGroup_TuringECU_CAN_Rx           1u
  #define CanCclConf_IPduGroup_TuringECU_CAN_Tx           0u



  /* Handle IDs of handle space CclRxSig [Rx Signals] */
	/*		Symbolic Name																	   Value   Active in predefined variant(s) */
''')

	dbc_rx_il_msgs.sort(key = lambda msg:[int(msg['msg_id'])])#先按msg id排序, 再按signal startbit排序
	index = 0
	for i in dbc_rx_il_msgs:
		for s in i['msg_signals']:
			f_CanCcl_Par_Cfg_h.write('#define %-50s              %du\n'%(('CanCclRxHndlCh0_' + s['sig_name'] +'_' + i['msg_id']), index))
			index += 1
	f_CanCcl_Par_Cfg_h.write('\n\n')


	write_const_string(f_CanCcl_Par_Cfg_h,
'''

/* Handle IDs of handle space CclTxSig [Tx Signals] */
  /*      Symbolic Name                                                                      Value   Active in predefined variant(s) */
''')

	dbc_tx_il_msgs.sort(key = lambda msg:[int(msg['msg_id'])])#先按msg id排序, 再按signal startbit排序
	index = 0
	for i in dbc_tx_il_msgs:
		for s in i['msg_signals']:
			f_CanCcl_Par_Cfg_h.write('#define %-50s              %du\n'%(('CanCclTxHndlCh0_' + s['sig_name'] +'_' + i['msg_id']), index))
			index += 1
	#f_CanCcl_Par_Cfg_h.write('\n\n')

	write_const_string(f_CanCcl_Par_Cfg_h,
'''


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
  \\var    Ccl_CbkRxAckFuncPtr
  \\brief  Function pointer table containing configured Rx indication notifications for signals and signal groups.
*/

extern CONST(CclCbkRxAckType, CCL_CONST) Can_Ccl_CbkRxAckFuncPtr[Can_Ccl_Rx_Num_RxAck_Ind];

/**********************************************************************************************************************
  Ccl_CbkRxTOutFuncPtr
**********************************************************************************************************************/
/**
  \\var    Ccl_CbkRxTOutFuncPtr
  \\brief  Function pointer table containing configured Rx timeout notifications for signals and signal groups.}
*/

extern CONST(CclCbkRxTOutType, CCL_CONST) Can_Ccl_CbkRxTOutFuncPtr[Can_Ccl_Rx_Num_RxTOut_Ind];


/**********************************************************************************************************************
  Ccl_CbkRxInvFuncPtr
**********************************************************************************************************************/
/**
  \\var    Ccl_CbkRxInvFuncPtr
  \\brief  Function pointer table containing configured Rx invalid notifications for signals and signal groups.
*/

#if (CCL_RX_INVINDICATION_API == STD_ON)
extern CONST(CclCbkInvType, CCL_CONST) Can_Ccl_CbkRxInvFuncPtr[Can_Ccl_Rx_Num_RxInv_Ind];
#endif

/**********************************************************************************************************************
  Ccl_NumOfContainedRxSignals
**********************************************************************************************************************/
/**
  \\var    Ccl_NumOfContainedRxSignals
  \\brief  Structure describing the starting signal handle and the number of signals contaiend in Rx messages
*/

extern CONST(Ccl_MessageContentInfo, CCL_CONST) Can_Ccl_NumOfContainedRxSignals[Can_Ccl_Rx_Num_Messages];


/**********************************************************************************************************************
  Ccl_NumOfContainedTxSignals
**********************************************************************************************************************/
/**
  \\var    Ccl_NumOfContainedTxSignals
  \\brief  Structure describing the starting signal handle and the number of signals contaiend in Tx messages
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
  \\var    Ccl_PduGrpVector
  \\brief  Contains an I-PDU-Group vector for each I-PDU  mapping the I-PDU to the corresponding I-PDU-Groups.
  */
extern CONST(Ccl_PduGrpVectorType, CCL_CONST) Can_Ccl_PduGrpVector[Can_Ccl_Num_Of_PduGroups];


/**********************************************************************************************************************
  Ccl_TxPduGrpInfo
**********************************************************************************************************************/
/**
  \\var    Ccl_TxPduGrpInfo
  \\brief  Contains all I-PDU-Group relevant information for Tx I-PDUs.
  \\details
  Element                 Description
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Ccl_PduGrpVector
*/
extern CONST(Ccl_TxPduGrpInfoType, CCL_CONST) Can_Ccl_TxPduGrpInfo[Can_Ccl_Tx_Num_Messages];


/**********************************************************************************************************************
  Ccl_RxPduGrpInfo
**********************************************************************************************************************/
/**
  \\var    Ccl_RxPduGrpInfo
  \\brief  Contains all I-PDU-Group relevant information for Rx I-PDUs.
  \\details
  Element                 Description
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Ccl_PduGrpVector
*/
extern CONST(Ccl_RxPduGrpInfoType, CCL_CONST) Can_Ccl_RxPduGrpInfo[Can_Ccl_Rx_Num_Messages];


/**********************************************************************************************************************
  Ccl_DefRxPduInfo
**********************************************************************************************************************/
/**
  \\var    Ccl_DefRxPduInfo
  \\brief  Contains all relevant information for deferred Rx I-PDUs.
  \\details
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
Date          : %s
By              : ChengJia
Traceability    : %s
Change Description  : Tool Generated code
*****************************************************************************/
'''%(current_time, dbc_name))


	f_CanCcl_Par_Cfg_h.close()


'''====================================
CanCcl_Par_Cfg.c
--
===================================='''
def CanCcl_Par_Cfg_c():
	global dbc_msgs_sorted
	global dbc_tx_msgs
	global dbc_rx_msgs
	global dbc_tx_il_msgs
	global dbc_rx_il_msgs

	path_CanCcl_Par_Cfg_c = auto_gen + '\\CanCcl_Par_Cfg.c'#CanCcl_Par_Cfg.c路径
	f_CanCcl_Par_Cfg_c = open(path_CanCcl_Par_Cfg_c, 'w+')
	

	write_const_string(f_CanCcl_Par_Cfg_c,
'''/* ===========================================================================
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
''')

	#Can_Ccl_TxSigInfo#----------------------------------------------------------------------------------------------------------
	f_CanCcl_Par_Cfg_c.write('CONST(Ccl_TxSigInfoType, CCL_CONST) Can_Ccl_TxSigInfo[Can_Ccl_Tx_Signal_Num_Signals] = {\n')
	f_CanCcl_Par_Cfg_c.write('	/* Index		CntrId	  InitValue 	SendType   */\n')

	index = 0
	for i in dbc_tx_il_msgs:
		for s in i['msg_signals']:
			if (i['msg_id'] == EVENT_0X511):#0x511
				f_CanCcl_Par_Cfg_c.write('	 { /*	  %d */		0 , 	 0x0,	  SIG_ONCHANGE	      },		  /* %s		*/\n'%(index, s['sig_name']))
			else:
				f_CanCcl_Par_Cfg_c.write('	 { /*	  %d */		0 , 	 0x0,	  SIG_NOSENDTYPE	  },		  /* %s		*/\n'%(index, s['sig_name']))
			index += 1
	
	f_CanCcl_Par_Cfg_c.write('};\n')


	#Can_Ccl_NumOfContainedTxSignals#----------------------------------------------------------------------------------------------------------
	f_CanCcl_Par_Cfg_c.write(
'''


/**********************************************************************************************************************
        Can_Ccl_NumOfContainedTxSignals
        **********************************************************************************************************************/
CONST(Ccl_MessageContentInfo, CCL_CONST) Can_Ccl_NumOfContainedTxSignals[Can_Ccl_Tx_Num_Messages] =
{
/* Index      SigStartIndex   SigCount   */
''')

	index = 0
	for i in dbc_tx_il_msgs:
		f_CanCcl_Par_Cfg_c.write('{ /*  %d  */          0 ,          %d   },/*%s*/\n'%(index, i['msg_signals_counts'], i['msg_name']))
		index += 1
	
	f_CanCcl_Par_Cfg_c.write('};\n')



	#Can_Ccl_RxAccessInfo#----------------------------------------------------------------------------------------------------------
	f_CanCcl_Par_Cfg_c.write(
'''
/**********************************************************************************************************************
    Can_Ccl_RxAccessInfo
  **********************************************************************************************************************/
CONST(Ccl_RxAccessInfoType, CCL_CONST) Can_Ccl_RxAccessInfo[Can_Ccl_Rx_Num_Signals] = {
	   /* Index 	 ControllerId */
''')
	index = 0
	for i in dbc_rx_il_msgs:
		for s in i['msg_signals']:
			f_CanCcl_Par_Cfg_c.write('{ /* 	%d  */		   0	   },		/*%-40s	*/\n'%(index, s['sig_name']))
			index += 1
	f_CanCcl_Par_Cfg_c.write('};\n')



	#Can_Ccl_NumOfContainedRxSignals#----------------------------------------------------------------------------------------------------------
	write_const_string(f_CanCcl_Par_Cfg_c,
'''


/**********************************************************************************************************************
    Can_Ccl_NumOfContainedRxSignals
  **********************************************************************************************************************/
''')

	f_CanCcl_Par_Cfg_c.write(
'''  CONST(Ccl_MessageContentInfo, CCL_CONST) Can_Ccl_NumOfContainedRxSignals[Can_Ccl_Rx_Num_Messages] =
  {
     /* Index      SigStartIndex   SigCount   */
''')
	index = 0
	start_index = 0
	signal_count = 0
	for i in dbc_rx_il_msgs:
		signal_count = i['msg_signals_counts']
		f_CanCcl_Par_Cfg_c.write('     { /*  %d  */            %d,       %d        },\n'%(index, start_index, signal_count))
		index += 1
		start_index += signal_count
	f_CanCcl_Par_Cfg_c.write('};\n')

	
	#提取RTE随机数
	search_rte()


	#Can_Ccl_CbkRxAckFuncPtr#----------------------------------------------------------------------------------------------------------
	write_const_string(f_CanCcl_Par_Cfg_c, 
'''


  #if (CCL_RX_INDICATION_API == STD_ON)
  /**********************************************************************************************************************
    Ccl_CbkRxAckFuncPtr
  **********************************************************************************************************************/
  /**
    \\var    Ccl_CbkRxAckFuncPtr
    \\brief  Function pointer table containing configured Rx Indication notifications for signals and signal groups.*/

  CONST(CclCbkRxAckType, CCL_CONST) Can_Ccl_CbkRxAckFuncPtr[Can_Ccl_Rx_Num_RxAck_Ind] = {
    /* Index    CbkRxAckFuncPtr                              */
''')
	index   = 0
	matched = 0
	for i in dbc_rx_il_msgs:
		for s in i['msg_signals']:
			for r in rte_random:
				result = re.match(s['sig_name'], r)
				if (result != None):
					span  = result.span()[1]#最后一个匹配的字符的位置
					tail   = r[span:]
					if re.match(r'_[a-h0-9]{8}', tail):#_XXXXXXXX
						f_CanCcl_Par_Cfg_c.write('	/*	%d	*/	Rte_COMCbk_%s	,/*%s*/\n'%(index, r, s['sig_name']))
						matched = 1
						#print(s['sig_name'])
						break
					else:
						pass
				else:
					pass
			if matched == 1:
				matched = 0
			else:
				f_CanCcl_Par_Cfg_c.write('	/*	%d	*/	NULL	,/*%s*/\n'%(index, s['sig_name']))

			index += 1
	f_CanCcl_Par_Cfg_c.write('  };\n')



	#Can_Ccl_CbkRxTOutFuncPtr#----------------------------------------------------------------------------------------------------------
	write_const_string(f_CanCcl_Par_Cfg_c,
'''  #endif


  #if (CCL_RX_TOUTINDICATION_API == STD_ON)
  /**********************************************************************************************************************
    Ccl_CbkRxTOutFuncPtr
  **********************************************************************************************************************/
  /**
    \\var    Ccl_CbkRxTOutFuncPtr
    \\brief  Function pointer table containing configured Rx timeout notifications for signals and signal groups. ea:{71D75BEB-245A-468b-96DB-A4F1362E927C}
  */
CONST(CclCbkRxTOutType, CCL_CONST) Can_Ccl_CbkRxTOutFuncPtr[Can_Ccl_Rx_Num_RxTOut_Ind] = {
/* Index	  CbkRxTOutFuncPtr	   */
''')


	index   = 0
	matched = 0
	for i in dbc_rx_il_msgs:
		for s in i['msg_signals']:
			for r in rte_random:
				result = re.match(s['sig_name'], r)
				if (result != None):
					span  = result.span()[1]#最后一个匹配的字符的位置
					tail   = r[span:]
					if re.match(r'_[a-h0-9]{8}', tail):
						f_CanCcl_Par_Cfg_c.write('	/*	%d	*/	Rte_COMCbkRxTOut_%s	,/*%s*/\n'%(index, r, s['sig_name']))
						matched = 1
						#print(s['sig_name'])
						break
					else:
						pass
				else:
					pass
			if matched == 1:
				matched = 0
			else:
				f_CanCcl_Par_Cfg_c.write('	/*	%d	*/	NULL	,/*%s*/\n'%(index, s['sig_name']))

			index += 1
	f_CanCcl_Par_Cfg_c.write('  };\n')

	write_const_string(f_CanCcl_Par_Cfg_c,
'''  #endif


  #if (CCL_RX_INVINDICATION_API == STD_ON)
  /**********************************************************************************************************************
    Ccl_CbkRxInvFuncPtr
  **********************************************************************************************************************/
  /**
    \\var    Ccl_CbkRxInvFuncPtr
    \\brief  Function pointer table containing configured Rx Indication notifications for signals and signal groups.*/

  CONST(CclCbkInvType, CCL_CONST) Can_Ccl_CbkRxInvFuncPtr[Can_Ccl_Rx_Num_RxInv_Ind] = {
    /* Index    CbkRxAckFuncPtr                        */
    /*     0 */ NULL
  };
''')


	#Can_Ccl_RxNotifFuncPtr#----------------------------------------------------------------------------------------------------------
	f_CanCcl_Par_Cfg_c.write(
'''  #endif


  /**********************************************************************************************************************
    Can_Ccl_Channel0_RxNotifFuncPtr
  **********************************************************************************************************************/
  CONST(Ccl_RxNotifFuncInfo, CCL_CONST) Can_Ccl_RxNotifFuncPtr[Can_Ccl_Rx_Num_Signals] = {
        /* Index      RxAckIndex          RxToutIndex         RxInvIndex       */
''')
	
	index   = 0
	matched = 0
	for i in dbc_rx_il_msgs:
		for s in i['msg_signals']:
			for r in rte_random:
				result = re.match(s['sig_name'], r)
				if (result != None):
					span  = result.span()[1]#最后一个匹配的字符的位置
					tail   = r[span:]
					if re.match(r'_[a-h0-9]{8}', tail):
						rear = 'CanCclRxHndlCh0_' + s['sig_name'] + '_' + i['msg_id']
						f_CanCcl_Par_Cfg_c.write('  { /*  %d  */    %s,  %s, %s   },/*%s*/\n'%(index, rear, rear, rear, s['sig_name']))
						matched = 1
						#print(s['sig_name'])
						break
					else:
						pass
				else:
					pass
			if matched == 1:
				matched = 0
			else:
				f_CanCcl_Par_Cfg_c.write('  { /*  %d  */    CCL_NO_CBKRXACK,  CCL_NO_CBKRXTOUT, CCL_NO_CBKRXINV   },/*%s*/\n'%(index, s['sig_name']))
			index += 1

	f_CanCcl_Par_Cfg_c.write('};\n')


	f_CanCcl_Par_Cfg_c.write(
'''

  /**********************************************************************************************************************
    Ccl_PduGrpVector
  **********************************************************************************************************************/
  /**
    \\var    Ccl_PduGrpVector
    \\brief  Contains an I-PDU-Group vector for each I-PDU, mapping the I-PDU to the corresponding I-PDU-Groups.
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
    \\var    Ccl_TxPduGrpInfo
    \\brief  Contains all I-PDU-Group relevant information for Tx I-PDUs.
    \\details
    Element                 Description
    PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Ccl_PduGrpVector
  */
  CONST(Ccl_TxPduGrpInfoType, CCL_CONST) Can_Ccl_TxPduGrpInfo[Can_Ccl_Tx_Num_Messages] = {
    /* Index     PduGrpVectorStartIdx */ 
''')
	#Can_Ccl_TxPduGrpInfo#----------------------------------------------------------------------------------------------------------
	index = 0
	for i in dbc_tx_il_msgs:
		f_CanCcl_Par_Cfg_c.write('  { /*  %d  */           0U  },\n'%(index))
		index += 1
	f_CanCcl_Par_Cfg_c.write('};\n')



	write_const_string(f_CanCcl_Par_Cfg_c,
'''
/**********************************************************************************************************************
    Ccl_RxPduGrpInfo
  **********************************************************************************************************************/
  /**
    \\var    Ccl_RxPduGrpInfo
    \\brief  Contains all I-PDU-Group relevant information for Rx I-PDUs.
    \\details
    Element                 Description
    PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Ccl_PduGrpVector
  */
  CONST(Ccl_RxPduGrpInfoType, CCL_CONST) Can_Ccl_RxPduGrpInfo[Can_Ccl_Rx_Num_Messages] = {
    /* Index     PduGrpVectorStartIdx */ 
''')
	index = 0
	for i in dbc_rx_il_msgs:
		f_CanCcl_Par_Cfg_c.write('  { /*     %d */           1U  },\n'%(index))
		index += 1
	f_CanCcl_Par_Cfg_c.write('};\n')


	write_const_string(f_CanCcl_Par_Cfg_c,
'''
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
Date          : %s
By              : ChengJia
Traceability    : %s
Change Description  : Tool Generated code
*****************************************************************************/
'''%(current_time, dbc_name))


	#f_CanCcl_Par_Cfg_c.write('\n\n')

	f_CanCcl_Par_Cfg_c.close()


'''====================================
CanIl_Par_Cfg.h
--
===================================='''
def CanIl_Par_Cfg_h():
	global dbc_msgs_sorted
	global dbc_tx_msgs
	global dbc_rx_msgs
	global dbc_tx_il_msgs
	global dbc_rx_il_msgs
	global Can_Ccl_Tx_Num_Periodic
	global Can_Ccl_Rx_Num_Periodic_Messages
	global Can_Ccl_Rx_Num_Periodic_Signals


	path_CanIl_Par_Cfg_h = auto_gen + '\\CanIl_Par_Cfg.h'#CanCcl_Par_Cfg.h路径
	f_CanIl_Par_Cfg_h = open(path_CanIl_Par_Cfg_h, 'w+')


	write_const_string(f_CanIl_Par_Cfg_h,
'''#if !defined(CAN_IL_PAR_H)
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

''')

	#----------------------------------------------------------------------------------------------------------
	f_CanIl_Par_Cfg_h.write(
'''
#define Can_Ch0_Il_Tx_Num_Burst_Periodic   (0u) /*no use*/


#define Can_Ch0_Il_Tx_Num_Periodic         (%du)


/* ===========================================================================
     Interaction Layer Number of Receive Messages, Signals
    =========================================================================*/


#define Can_Ch0_Il_Rx_Num_Periodic         (%du)	/*no use*/

#define Can_Ch0_Il_Rx_Num_Periodic_Signals (%du)	/*no use*/

#define Can_Ch0_Il_Rx_Num_Req_Frames       (0u)
'''
%(Can_Ccl_Tx_Num_Periodic, Can_Ccl_Rx_Num_Periodic_Messages, Can_Ccl_Rx_Num_Periodic_Signals))


	write_const_string(f_CanIl_Par_Cfg_h,
'''
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
''')

	#----------------------------------------------------------------------------------------------------------
	f_CanIl_Par_Cfg_h.write(
'''
typedef enum
  {
''')

	index = 0
	for i in dbc_tx_il_msgs:
		if index == 0:
			f_CanIl_Par_Cfg_h.write('Can_Ch0_Il_Tx_Msg_%s_TMH=0,\n'%(i['msg_name']))
			f_CanIl_Par_Cfg_h.write('/*(0) */\n')
		else:
			f_CanIl_Par_Cfg_h.write('Can_Ch0_Il_Tx_Msg_%s_TMH,\n'%(i['msg_name']))
			f_CanIl_Par_Cfg_h.write('/*(%d) */\n'%(index))
		index += 1

	f_CanIl_Par_Cfg_h.write('Can_Ch0_Il_Tx_Num_Messages\n')
	f_CanIl_Par_Cfg_h.write('/*(%d) */'%(index))

	f_CanIl_Par_Cfg_h.write(
'''
}Can_Ch0_Il_Tx_Messages_Macro;


/* ===========================================================================
     Interaction Layer Transmit Signal Enumerations
     NB: The below tx signal sequence should match one to one with the
           IL Tx Signal description table.
         CAN_IL_SIGNAL const
         Can_Il_Tx_signals[ CAN_IL_TX_NUM_SIGNALS  ]

    =========================================================================*/
''')



	#----------------------------------------------------------------------------------------------------------
	f_CanIl_Par_Cfg_h.write(
'''
typedef enum
  {
''')
	index = 0
	for i in dbc_tx_il_msgs:
		for s in i['msg_signals']:
			if index == 0:
				f_CanIl_Par_Cfg_h.write('Can_Ch0_Il_Tx_Sig_%s_%s = 0,\n'%(s['sig_name'], i['msg_id']))
				f_CanIl_Par_Cfg_h.write('/*(0) */\n')
			else:
				f_CanIl_Par_Cfg_h.write('Can_Ch0_Il_Tx_Sig_%s_%s,\n'%(s['sig_name'], i['msg_id']))
				f_CanIl_Par_Cfg_h.write('/*(%d) */\n'%(index))
			index += 1

	f_CanIl_Par_Cfg_h.write(' Can_Ch0_Il_Tx_Num_Signals\n')
	f_CanIl_Par_Cfg_h.write('/*(%d) */'%(index))

	f_CanIl_Par_Cfg_h.write(
'''
}Can_Ch0_Il_Tx_Signals_Macro;
''')



	#----------------------------------------------------------------------------------------------------------
	f_CanIl_Par_Cfg_h.write(
'''

/* ===========================================================================
      Interaction Layer Receive Message Enumerations
     =========================================================================*/
typedef enum
  {
''')
	index = 0
	for i in dbc_rx_il_msgs:
		if index == 0:
			f_CanIl_Par_Cfg_h.write('Can_Ch0_Il_Rx_Msg_%s =0,\n'%(i['msg_name']))
			f_CanIl_Par_Cfg_h.write('/*(0) */\n')
		else:
			f_CanIl_Par_Cfg_h.write('Can_Ch0_Il_Rx_Msg_%s,\n'%(i['msg_name']))
			f_CanIl_Par_Cfg_h.write('/*(%d) */\n'%(index))
		index += 1

	f_CanIl_Par_Cfg_h.write('Can_Ch0_Il_Rx_Num_Messages\n')
	f_CanIl_Par_Cfg_h.write('/*(%d) */'%(index))

	f_CanIl_Par_Cfg_h.write(
'''
}Can_Ch0_Il_Rx_Messages_Macro;
''')



	#----------------------------------------------------------------------------------------------------------
	f_CanIl_Par_Cfg_h.write(
'''

/* ===========================================================================
     Interaction Layer Receive Signal Enumerations
    =========================================================================*/
  

typedef enum
{
''')
	index = 0
	for i in dbc_rx_il_msgs:
		for s in i['msg_signals']:
			if index == 0:
				f_CanIl_Par_Cfg_h.write('%-60s        /*(%d) */\n'%(('Can_Ch0_Il_Rx_Sig_' +s['sig_name'] +'_' + i['msg_id'] + ' = 0,'), index))
			else:
				f_CanIl_Par_Cfg_h.write('%-60s        /*(%d) */\n'%(('Can_Ch0_Il_Rx_Sig_' +s['sig_name'] +'_' + i['msg_id'] + ','), index))
			index += 1

	f_CanIl_Par_Cfg_h.write('Can_Ch0_Il_Rx_Num_Signals              /*(%d) */'%(index))

	f_CanIl_Par_Cfg_h.write(
'''
}Can_Ch0_Il_Rx_Signals_Macro;
''')

	write_const_string(f_CanIl_Par_Cfg_h,
'''

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
Date          : %s
By              : ChengJia
Traceability    : %s
Change Description  : Tool Generated code
*****************************************************************************/
'''%(current_time, dbc_name))

	#f_CanIl_Par_Cfg_h.write('\n\n')
	f_CanIl_Par_Cfg_h.close()


'''====================================
CanIl_Par_Cfg.c
--
===================================='''
def CanIl_Par_Cfg_c():
	global dbc_msgs_sorted
	global dbc_tx_msgs
	global dbc_rx_msgs
	global dbc_tx_il_msgs
	global dbc_rx_il_msgs
	pass


	path_CanIl_Par_Cfg_c = auto_gen + '\\CanIl_Par_Cfg.c'#CanCcl_Par_Cfg.c路径
	f_CanIl_Par_Cfg_c = open(path_CanIl_Par_Cfg_c, 'w+')


	write_const_string(f_CanIl_Par_Cfg_c,
'''/* ===========================================================================

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

  Name:           Can_Il_Par_Cfg.c

  Description:    CAN Interaction Layer Tx and Rx Parameters Configurations

                  Application Specific Tx and Rx Message and Signal
                  Data Structure Definitions

  Organization:   Multiplex Subsystems

 =========================================================================*/

/* ===========================================================================
  I N C L U D E   F I L E S
 =========================================================================*/ 

//#ifdef CANIL_IFSUPPORT

#include "Can_GeneralTypes.h"
#include <CclStack_Types.h>

//#endif

#include "CanIl_Util.h"
#include "CanIl.h"
#include "CanIl_Par_Cfg.h" 

CAN_UINT16 Can_Ch0_Il_Tx_Periodic_Count[ Can_Ch0_Il_Tx_Num_Periodic ];

#ifdef CAN_IL_TX_BURST_MODE

 #if ( Can_Ch0_Il_Tx_Num_Burst_Periodic > 0 )

CAN_UINT8 Can_Ch0_Il_Tx_Burst_Count[ Can_Ch0_Il_Tx_Num_Burst_Periodic ];

 #endif

#endif

/* ===========================================================================
  M E M O R Y   A L L O C A T I O N
 =========================================================================*/
/* ===========================================================================
  Interaction Layer Transmit Frame Status and Data Storage
 =========================================================================*/
CAN_UINT8 Can_Ch0_Il_Tx_Frame_Data[ Can_Ch0_Il_Tx_Num_Messages ][ CAN_MAX_DATA_LENGTH ];


CAN_UINT8 Can_Ch0_Il_Tx_Frame_Status[ Can_Ch0_Il_Tx_Num_Messages ];


CAN_UINT16 Can_Ch0_Il_Tx_Delay_Count[ Can_Ch0_Il_Tx_Num_Messages ]; 

/* ===========================================================================
  TRANSMIT DATA STRUCTURES
 =========================================================================*/

/* ===========================================================================
  Interaction Layer Transmit Signal Descriptors

 The Following Table Definition Assumes a Motorola (Big Endian) Byte
 Ordering of Bytes within the CAN Frame. As an example, if a 16bit signal
 is defined in Bytes 0 and 1 of the CAN frame, the MSByte is Byte 0 and the
 LSByte is Byte 1.

 =========================================================================*/
''')

	#Can_Ch0_Il_Tx_Signals#----------------------------------------------------------------------------------------------------------
	f_CanIl_Par_Cfg_c.write('CAN_IL_SIGNAL const\n')
	f_CanIl_Par_Cfg_c.write('Can_Ch0_Il_Tx_Signals[ Can_Ch0_Il_Tx_Num_Signals ] ={\\\n')
	f_CanIl_Par_Cfg_c.write('/*  CAN Frame,                                Num Bytes,       MS Byte,     MS Bit,          LS Byte,       LS Bit   */\n')

	index = 0
	for i in dbc_tx_il_msgs:
		InitNumBytes = 0
		for s in i['msg_signals']:
			start    = int(s['sig_start_bit'])
			len      = int(s['sig_length'])
			NumBytes = math.ceil(len/8.0)
			#MSB msb处理
			MSB = start/8
			msb = start%8
			#LSB lsb处理
			if ((start%8 + 1) -len >= 0):#MSB LSB在同一个字节
				LSB = start/8
				lsb = (start%8 + 1) - len
			else:#跨字节
				LSB = start/8 + math.ceil((len- (start%8 + 1))/8.0)#如start=11,len=11, 则MSB=1, LSB=MSB + 向上取整((扣除MSB行的bit数)/8.0)
				if (len- (start%8 + 1))%8  == 0:
					lsb = 0
				else:
					lsb = 8 - ((len- (start%8 + 1))%8) 
			f_CanIl_Par_Cfg_c.write('{  %-40s       %d,             %d,             %d,             %d,             %d  },  /*%s*/   /*%s*/\\\n'%(('Can_Ch0_Il_Tx_Msg_'+i['msg_name']+'_TMH,'), NumBytes, MSB, msb, LSB, lsb, s['sig_name'], i['msg_name'])) 
			index += 1
			InitNumBytes += NumBytes#统计1个signal所占字节数(不足1Byte的取整1Byte)
		i['msg_init_byte_num'] = InitNumBytes#为msg添加key'msg_init_byte_num'
	f_CanIl_Par_Cfg_c.write('};\n')




	write_const_string(f_CanIl_Par_Cfg_c,
'''/* ===========================================================================
  Interaction Layer Transmit Message Initialization Arrays

  The following transmit message initialization arrays define the initial
  values for all of the transmitted messages.

 =========================================================================*/

/*
 Sample Message Has 7 Signals, Each 1 Byte, for Initialization
 The order of the bytes in this array is as follows:
 Byte 0 - Signal 0, bit 1.7 Value = 0     C_SAMPLE*/
''')
	#----------------------------------------------------------------------------------------------------------
	for i in dbc_tx_il_msgs:
		msg_init_byte_num = i['msg_init_byte_num']

		f_CanIl_Par_Cfg_c.write('/*     %s   */\n'%(i['msg_name']))
		f_CanIl_Par_Cfg_c.write('static CAN_UINT8 const Can_Ch0_Il_%s_Message_Init[%d ] = {'%(i['msg_name'], i['msg_init_byte_num']))
		for j in range(0, msg_init_byte_num):
			if (j == (msg_init_byte_num-1)):#最后一个00不要','
				f_CanIl_Par_Cfg_c.write('0x00')
			else:
				if ('IC_0x510' == i['msg_name']):#special handling for Odo output
					if (j < 3):#IC_OdometerMasterValue:FF FF FF
						f_CanIl_Par_Cfg_c.write('0xFF,')
					else:
						f_CanIl_Par_Cfg_c.write('0x00,')
				else:
					f_CanIl_Par_Cfg_c.write('0x00,')
		f_CanIl_Par_Cfg_c.write('};\n')



	write_const_string(f_CanIl_Par_Cfg_c,
'''/* ===========================================================================
  Interaction Layer Transmit Message Definition Table

  This table (array of transmit message data structures) defines each
  transmitted message. The data structure defines the number of signals in
  the message, the total number of bytes in the message, a pointer to the
  list of signal handles, and a pointer to the message initialization data
  bytes.

 =========================================================================*/
''')


	#Can_Ch0_Il_Tx_Messages----------------------------------------------------------------------------------------------------------
	f_CanIl_Par_Cfg_c.write(
'''
CAN_IL_TX_MESSAGE const
Can_Ch0_Il_Tx_Messages[ Can_Ch0_Il_Tx_Num_Messages ] =
 {
''')

	for i in dbc_tx_il_msgs:
		f_CanIl_Par_Cfg_c.write(
'''	/*%s_TMH*/
	{
        %d,                              /* Number of Signals in the Message             */
        0,                               /* Total Number of Signal Bytes in the Message  */
        Can_Ch0_Il_%s_Message_Init       /* Pointer to the Initialization Data Bytes     */
	},
'''%(i['msg_name'], i['msg_signals_counts'], i['msg_name']))


	f_CanIl_Par_Cfg_c.write('};')
	f_CanIl_Par_Cfg_c.write('\n\n')




	write_const_string(f_CanIl_Par_Cfg_c,
'''/* ===========================================================================
  Interaction Layer Transmit Message Data (TMD) Structures (Frame Definition)

  !!! IMPORTANT NOTE !!! The transmit message handles must be specified
  sequentially, starting with 0 (zero). These message handles serve as an
  index to the transmit complete function pointers, so each index must map
  to the correct transmit complete callback function pointer in the lookup
  table (array of function pointers) for servicing transmit complete events.

 =========================================================================*/
''')


	#----------------------------------------------------------------------------------------------------------
	index = 0
	for i in dbc_tx_il_msgs:
		f_CanIl_Par_Cfg_c.write(
'''
/*       %s     */
 static CAN_IL_TMD const Can_Ch0_Il_Tx_Message_%s_Tmd =
{
     CAN_GPNUM_%d,                            /* CAN message data length  */
     Can_Ch0_Il_Tx_Frame_Data[ %d ],           /* Pointer to Data          */
     Can_Ch0_Il_Tx_Msg_%s_TMH           /* Transmit Message Handle  */
};
'''%(i['msg_name'], i['msg_name'], int(i['msg_dlc']), index, i['msg_name']))
		index += 1
	#f_CanIl_Par_Cfg_c.write('\n\n')


	write_const_string(f_CanIl_Par_Cfg_c,
'''/* ===========================================================================
  Interaction Layer Periodic Transmit Table

  This table is an array of data structures that define the periodic
  transmit characteristics for messages that are transmitted periodically.
  Care must be taken so that the each periodic message defined in the
  Interaction Layer Transmit Frame table map correctly to this table so
  that the correct periodic message attributes, and the pointer to the
  periodic timer, is correctly retrieved.

 =========================================================================*/
''')


	#Can_Ch0_Il_Tx_Periodic----------------------------------------------------------------------------------------------------------
	f_CanIl_Par_Cfg_c.write(
'''static CAN_IL_TX_PERIODIC const
Can_Ch0_Il_Tx_Periodic[ Can_Ch0_Il_Tx_Num_Periodic ] =
{
''')

	index = 0
	for i in dbc_tx_il_msgs:
		f_CanIl_Par_Cfg_c.write(
''' /* %s  Message */
 {
     IL_TIME_IN_TASK_TICS( %s) ,                                   /* Primary Period in Task Tics  */
     IL_TIME_IN_TASK_TICS( %d),                                     /* Offset Delay in Task Tics    */
     &Can_Ch0_Il_Tx_Periodic_Count[ %d ]                         /* Pointer to Periodic Count    */
 },
'''%(i['msg_name'], i['msg_cycle_time'], (index+1)*10, index))
		index += 1
	f_CanIl_Par_Cfg_c.write('};')
	#f_CanIl_Par_Cfg_c.write('\n\n')


	write_const_string(f_CanIl_Par_Cfg_c,
'''
/* ===========================================================================
  Interaction Layer Burst Periodic Transmit Table
 =========================================================================*/

/* ===========================================================================
  Interaction Layer Transmit Frame Table

  Each entry in this table defines the attributes for a specific transmit
  frame transmitted by the Interaction Layer.

 =========================================================================*/

''')


	#Can_Ch0_Il_Tx_Frame_Table----------------------------------------------------------------------------------------------------------
	f_CanIl_Par_Cfg_c.write(
'''CAN_IL_TX_FRAME const Can_Ch0_Il_Tx_Frame_Table[ Can_Ch0_Il_Tx_Num_Messages ] = 
{
''')
	index = 0
	ticks = 0
	FrameTransAttr = ''
	for i in dbc_tx_il_msgs:
		if i['msg_send_type'] == '0':#Cyclic
			FrameTransAttr = r'(IL_TX_ATTR_PERIODIC | IL_TX_ATTR_TXC_NOTIFY)'
		elif i['msg_send_type'] == '1':#Event
			FrameTransAttr = r'(IL_TX_ATTR_EVENT | IL_TX_ATTR_TXC_NOTIFY)'
			ticks = 20#CE类型的msg发送间隔20ms
		elif i['msg_send_type'] == '3':#CE
			FrameTransAttr = r'(IL_TX_ATTR_EVENT | IL_TX_ATTR_PERIODIC | IL_TX_ATTR_TXC_NOTIFY)'
			ticks = 20#CE类型的msg发送间隔20ms
		f_CanIl_Par_Cfg_c.write(
''' {
 /* %s Message (CAN periodic, data change or a request ) */
     %s,   /* Frame Transmission Attributes                */
     &Can_Ch0_Il_Tx_Frame_Status[ %d ],       /* Pointer to the Frame Status Variable         */
     Can_Ch0_Il_Tx_Frame_Data[ %d ],          /* Pointer to the Transmitted Frame Data        */
     &Can_Ch0_Il_Tx_Delay_Count[ %d ],        /* Pointer to the Transmit Delay Count          */ 
     IL_TIME_IN_TASK_TICS( %d ),                   /* Minimum Transmit Delay in Timer Tics         */
     &Can_Ch0_Il_Tx_Periodic[ %d ],           /* Pointer to the Periodic Attributes (or NULL ) */ 
     NULL,                                        /* Ptr to Burst Periodic Attributes (or NULL)   */
     &Can_Ch0_Il_Tx_Message_%s_Tmd,  /* Pointer to CAN Driver TMD Data Structure     */
 },
'''%(i['msg_name'], FrameTransAttr, index, index, index, ticks, index, i['msg_name']))
		index += 1
		ticks = 0
	f_CanIl_Par_Cfg_c.write('};')
	f_CanIl_Par_Cfg_c.write('\n')


	write_const_string(f_CanIl_Par_Cfg_c,
'''/* ===========================================================================
  R E C E I V E   D A T A   S T R U C T U R E S
 =========================================================================*/
/* ===========================================================================
  Interaction Layer Receive Signal Descriptors

  This data structure defines each received signal, include the specific
  received CAN frame (sequentially enumerated) in which the signal resides,
  and the specific location of the signal within the CAN frame. The
  signal is assumed to span the bits in the frame from the MSByte.MSBit to
  the LSByte.LSBit. As an example, a 16 bit (2 Byte) wide signal that
  occupies the first two bytes (Byte0, Byte 1) of a CAN frame is specified
  as having endpoints at (Byte 0, Bit 7) and (Byte 1, Bit 0). This table
  definition assumes a Motorola (Big Endian) ordering of bytes within the
  CAN Frame.

 =========================================================================*/
/* Receive messages */
''')



	#Can_Ch0_Il_Rx_Signals#----------------------------------------------------------------------------------------------------------
	f_CanIl_Par_Cfg_c.write(
'''CAN_IL_SIGNAL const
Can_Ch0_Il_Rx_Signals[ Can_Ch0_Il_Rx_Num_Signals ] =
{ 
/*  CAN Frame,                                               Num Bytes,      MS Byte,    MS Bit,     LS Byte,    LS Bit */
''')

	index = 0
	for i in dbc_rx_il_msgs:
		InitNumBytes = 0
		for s in i['msg_signals']:
			start    = int(s['sig_start_bit'])
			len      = int(s['sig_length'])
			NumBytes = math.ceil(len/8.0)
			#MSB msb处理
			MSB = start/8
			msb = start%8
			#LSB lsb处理
			if ((start%8 + 1) -len >= 0):#MSB LSB在同一个字节
				LSB = start/8
				lsb = (start%8 + 1) - len
			else:#跨字节
				LSB = start/8 + math.ceil((len- (start%8 + 1))/8.0)#如start=11,len=11, 则MSB=1, LSB=MSB + 向上取整((扣除MSB行的bit数)/8.0)
				if (len- (start%8 + 1))%8  == 0:
					lsb = 0
				else:
					lsb = 8 - ((len- (start%8 + 1))%8) 
			f_CanIl_Par_Cfg_c.write('{  %-50s       %d,             %d,             %d,             %d,             %d  },/*%d*/  /*%s*/   /*%s*/\n'%(('Can_Ch0_Il_Rx_Msg_'+i['msg_name'] + ','), NumBytes, MSB, msb, LSB, lsb, index, s['sig_name'], i['msg_name'])) 
			index += 1
			InitNumBytes += NumBytes#统计1个signal所占字节数(不足1Byte的取整1Byte)
		i['msg_init_byte_num'] = InitNumBytes#为msg添加key'msg_init_byte_num'
	f_CanIl_Par_Cfg_c.write('};\n')





	write_const_string(f_CanIl_Par_Cfg_c,
'''/* ===========================================================================
  Interaction Layer Receive Frame Data Storage and Status
 =========================================================================*/
CAN_UINT8 Can_Ch0_Il_Rx_Frame_Data[ Can_Ch0_Il_Rx_Num_Messages ][ CAN_MAX_DATA_LENGTH ];

CAN_UINT8 Can_Ch0_Il_Rx_Frame_Status[ Can_Ch0_Il_Rx_Num_Messages ];

CAN_UINT16 Can_Ch0_Il_Rx_Timeout_Count[ Can_Ch0_Il_Rx_Num_Messages ];

Can_Il_Rx_Data_Pointer Can_Ch0_Il_Receive_Ptr[ Can_Ch0_Il_Rx_Num_Messages ][ CAN_MAX_DATA_LENGTH ];

#if (Can_Ch0_Il_Rx_Num_Req_Frames > 0)

#define CAN_CHANNEL0_IL_DATA_REQ_TX_HANDLE
#define CAN_CHANNEL0_IL_REQ_TX_CANID

static CAN_UINT8  reqCounter[ Can_Ch0_Il_Rx_Num_Req_Frames ];
static CAN_UINT16 reqTimer[ Can_Ch0_Il_Rx_Num_Req_Frames ];
static CAN_UINT8  reqStatus[ Can_Ch0_Il_Rx_Num_Req_Frames ];

static const CAN_UINT8 Can_Ch0_Il_Data_Request[2] = {0x00,0x00};

static const CAN_IL_TMD Can_Ch0_Il_Data_Request_Frame_Tmd[ Can_Ch0_Il_Rx_Num_Req_Frames ] =
{
};

static const Can_Ch0_Il_Rx_Frame_Request Can_Ch0_Il_Rx_Request_Frame_Data[ Can_Ch0_Il_Rx_Num_Req_Frames ] =
{
};

#endif


/* ===========================================================================
  Received Frame Attributes Lookup Table

  This table includes the attributes for all of the received frames.
  If a received frame is periodic, this table also includes pointers to the
  received frame status and to the receive timeout counter for message
  gain and loss indication. If a transmitted frame request can be issued
  for a received frame, this table includes the pointer to the receive
  frame request attributes.

 =========================================================================*/
''')



	#Can_Ch0_Il_Tx_Frame_Table----------------------------------------------------------------------------------------------------------
	f_CanIl_Par_Cfg_c.write(
'''CAN_IL_RX_FRAME const
Can_Ch0_Il_Rx_Frame_Table[ Can_Ch0_Il_Rx_Num_Messages ] =
{
''')
	index           = 0
	timeout_index   = 0
	sig_start_index = 0
	sig_counts      = 0
	FrameReceivAttr = ''
	timeout_counter = ''

	for i in dbc_rx_il_msgs:
		timeout_counter = '&Can_Ch0_Il_Rx_Timeout_Count[' + str(timeout_index) + ']'#Event msg的为NULL
		sig_counts = int(i['msg_signals_counts'])
		TimeoutCountValue = 1900
		if i['msg_id'] == '1410':#0x582, timeout value is 5000. 
			TimeoutCountValue = 4900

		if i['msg_send_type'] == '0':#Cyclic
			FrameReceivAttr = r'(IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR)'
		elif i['msg_send_type'] == '1':#Event
			FrameReceivAttr = r'(IL_RX_ATTR_DEFAULT)'
			timeout_counter = 'NULL'
		elif i['msg_send_type'] == '3':#CE
			FrameReceivAttr = r'(IL_RX_ATTR_EVENT | IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR)'

		f_CanIl_Par_Cfg_c.write(
'''/* %s */ /*%d*/
 {
     %s,
     %d,      /* Signal Start Index                   */
     %d,      /* Number of Signals in Message         */
     CAN_GPNUM_%d,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ %d],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ %d],         /* Pointer to Received Frame Data       */
     %s,         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(%03d),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
'''%(i['msg_name'], index, FrameReceivAttr, sig_start_index, sig_counts, int(i['msg_dlc']), index, index, timeout_counter, TimeoutCountValue))
		index += 1
		if i['msg_send_type'] != '1':#Event
			timeout_index           += 1
		sig_start_index += sig_counts
	f_CanIl_Par_Cfg_c.write('};')
	#f_CanIl_Par_Cfg_c.write('\n\n')





	#Can_Ch0_Il_Tx_Precopy_Function_Table----------------------------------------------------------------------------------------------------------
	f_CanIl_Par_Cfg_c.write(
'''
pTxPrecopyfn const Can_Ch0_Il_Tx_Precopy_Function_Table[ Can_Ch0_Il_Tx_Num_Messages ] =
  {
''')

	for i in dbc_tx_il_msgs:
		if i['msg_name'] == 'IC_0x510':
			f_CanIl_Par_Cfg_c.write('     IC_0x510_RollingCounter_Checksum  ,\n')
		elif i['msg_name'] == 'IC_0x525':
			f_CanIl_Par_Cfg_c.write('     IC_0x525_RollingCounter_Checksum  ,\n')
		else:
			f_CanIl_Par_Cfg_c.write('     NULL  ,\n')

	f_CanIl_Par_Cfg_c.write('};')
	f_CanIl_Par_Cfg_c.write('\n')


	write_const_string(f_CanIl_Par_Cfg_c,
'''/*****************************************************************************
    R E V I S I O N     N O T E S
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  -
For each change to this file, be sure to record:
1.   Who made the change and when the change was made.
2.   Why the change was made and the intended result.

Date       By         Reason For Change
------------------------------------------------------------------------------

******************************************************************************/
/*****************************************************************************
Date          : %s
By              : ChengJia
Traceability    : %s
Change Description  : Tool Generated code
*****************************************************************************/
'''%(current_time, dbc_name))

	#f_CanIl_Par_Cfg_c.write('\n\n')
	f_CanIl_Par_Cfg_c.close()





'''====================================
CanIvi_Par_Cfg.h
--
===================================='''
def CanIvi_Par_Cfg_h():
	global dbc_tx_msgs
	global dbc_rx_msgs
	global CanDisp_Number_Of_Rx_Messages

	Can_Ivi_Tx_Num_Messages = 0
	Can_Ivi_Rx_Num_Messages = 0
	dbc_tx_ivi_msgs = []
	dbc_rx_ivi_msgs = []

	tx_cnt = 0
	tx_ivi_first_index = 0
	rx_cnt = 0
	rx_ivi_first_index = 0
	
	for i in dbc_tx_msgs:
		if i['msg_type'] == '3':#Ivi
			if tx_ivi_first_index == 0:#首个TX IVI HTH, 从0计数.
				tx_ivi_first_index = tx_cnt

			Can_Ivi_Tx_Num_Messages += 1
			dbc_tx_ivi_msgs.append(i)#提取TX IVI msgs
		tx_cnt += 1
	dbc_tx_ivi_msgs.sort(key = lambda msg:[msg['msg_id']])#不同于RX按Name排序, TX按ID排序.

	for i in dbc_rx_msgs:
		if i['msg_type'] == '3':#Ivi
			if rx_ivi_first_index == 0:
				rx_ivi_first_index = rx_cnt
			Can_Ivi_Rx_Num_Messages += 1
			dbc_rx_ivi_msgs.append(i)#提取RX IVI msgs
		rx_cnt += 1
	dbc_rx_ivi_msgs.sort(key = lambda msg:[msg['msg_name']])

	path_CanIvi_Par_Cfg_h = auto_gen + '\\CanIvi_Par_Cfg.h'#CanIvi_Par_Cfg.h路径
	f_CanIvi_Par_Cfg_h = open(path_CanIvi_Par_Cfg_h, 'w+')


	write_const_string(f_CanIvi_Par_Cfg_h,
'''/* ===========================================================================

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
**
**  Name:           CanIvi_Par_Cfg.h
**
**  Description:    CAN Ivi parameter configuration file for global constants
**
**  Organization:   Vehicle Communications
**                  Visteon Corporation
**
**  =========================================================================*/
''')
	index = 0
	for i in dbc_tx_ivi_msgs:
		f_CanIvi_Par_Cfg_h.write(
'''
#define %-40s				(%du)'''%(('Can_Ch'+i['msg_channel']+'_Ivi_Tx_Msg_'+i['msg_name']+'_TMH'), (tx_ivi_first_index +index)))
		index += 1

	f_CanIvi_Par_Cfg_h.write('\n\n')

	index = 0
	for i in dbc_rx_ivi_msgs:
		f_CanIvi_Par_Cfg_h.write(
'''
#define %-40s				(%du)'''%(('Can_Ch'+i['msg_channel']+'_Ivi_Rx_Msg_'+i['msg_name']), (rx_ivi_first_index + index)))
		index += 1

	f_CanIvi_Par_Cfg_h.close()




'''====================================
从Rte_Type.h中搜索提取所有signal是的RTE随机数.
注意, DaVinci中必须为signal配置RxTimeout,
否则提取将失败.
--
===================================='''
def search_rte():
	pattern = r'Rte_RxTimeout_.+[a-f0-9]{8} '#注意8个数字串后有一个空格
	#print('please copy Rte_ype.h to current directory...')
	f_Rte_Type_h = open(Rte_Type_h,"r",errors="ignore")
	infos = f_Rte_Type_h.readlines()
	for line in infos:
		result = re.search(pattern, line)
		if (result ==  None):
			#print('search failed, next line')
			pass
		else:
			r = result.group()[14:-1]
			#print(r)#engspeed_0f0e0g71
			rte_random.append(r)
	#print(rte_random)
	f_Rte_Type_h.close()


def notice():
	print(
'''
Notice for N356 CAN stack auto-gen:
1.Place .dbc file into can_python_tool directory, and modify the 'dbc_name' in can_python_tool.py.
2.Place Rte_Type.h into can_python_tool directory.
''')


def exit_gen():
	print("CAN stack code auto-generation succeeded!\n%s"%current_time)
	time.sleep(5)	
'''====================================
main function
--
===================================='''
if __name__ == "__main__":
	notice()
	dbc_parse_to_json()
	CanDisp_Par_Cfg_h()
	CanDisp_Par_Cfg_c()
	CanCcl_Par_Cfg_h()
	CanCcl_Par_Cfg_c()
	CanIl_Par_Cfg_h()
	CanIl_Par_Cfg_c()
	CanIvi_Par_Cfg_h()
	exit_gen()




