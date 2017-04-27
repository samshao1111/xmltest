#include "stdafx.h"
#include "HardwareDef.h"

CHardwareDef::CHardwareDef()
{


	// TODO: add one-time construction code here

}
void CHardwareDef::Init()
{
	m_elm_comm_def	=	FALSE;  //如果座椅有ECU通讯,则需要有comms定义控制器通讯方式,否则无.
	m_elm_comm	=	CString("comm");     //comm定义一张CAN通讯卡
	m_elm_comm_attr_name[0]	=	CString("ControlCAN") ;//name,CAN接口类型,目前 “ControlCAN“,后续会增加.
	m_elm_comm_attr_module[0]	= CString("pci9820b.dll");  // module,CAN模块,目前“pci9820b.dll“,和name相关, 后续会增加.
	m_elm_comm_attr_device[0]   = CString("5/0"); //device,CAN设备,目前“5/0“,和name /module相关, 后续会增加.


	m_elm_dam	=	CString("dam"); //dam元素定义数据采集模块
	m_elm_dam_attr_type[0]	=	CString("NDAM-9000");  //type,数据采集模块类型,目前“NDAM-9000“,后续可能增加.
	m_elm_dam_attr_addr[0]	=	CString("192.168.0.178");  //addr,数据采集模块地址,对于“NDAM-9000“,目前网络地址默认”192.168.0.178”

}


CHardwareDef::~CHardwareDef()
{
	
}