#include "stdafx.h"
#include "HardwareDef.h"

CHardwareDef::CHardwareDef()
{


	// TODO: add one-time construction code here

}
void CHardwareDef::Init()
{
	m_elm_comm_def	=	FALSE;  //���������ECUͨѶ,����Ҫ��comms���������ͨѶ��ʽ,������.
	m_elm_comm	=	CString("comm");     //comm����һ��CANͨѶ��
	m_elm_comm_attr_name[0]	=	CString("ControlCAN") ;//name,CAN�ӿ�����,Ŀǰ ��ControlCAN��,����������.
	m_elm_comm_attr_module[0]	= CString("pci9820b.dll");  // module,CANģ��,Ŀǰ��pci9820b.dll��,��name���, ����������.
	m_elm_comm_attr_device[0]   = CString("5/0"); //device,CAN�豸,Ŀǰ��5/0��,��name /module���, ����������.


	m_elm_dam	=	CString("dam"); //damԪ�ض������ݲɼ�ģ��
	m_elm_dam_attr_type[0]	=	CString("NDAM-9000");  //type,���ݲɼ�ģ������,Ŀǰ��NDAM-9000��,������������.
	m_elm_dam_attr_addr[0]	=	CString("192.168.0.178");  //addr,���ݲɼ�ģ���ַ,���ڡ�NDAM-9000��,Ŀǰ�����ַĬ�ϡ�192.168.0.178��

}


CHardwareDef::~CHardwareDef()
{
	
}