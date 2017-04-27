// HardwareDef.h
#ifndef _HardwareDef_H
#define _HardwareDef_H

#include <vector>
using std::vector;

#define COMM_NUM   1
#define DAM_NUM		1

//����module NDAM-9000������ģ��io�ڵ�����
//<io type="ai" addr="0" var="motor_i"   name="���/����ģ�����" unit="mA" formula="(@@/65535*20-10)*1000/64/0.05" 
//value="0x8000" desc="��150mV @0.05��" />
/*
NDAM-9000��ģ��, ����������
NDAM-2808 8·�̵������(do)
NDAM-3402 8·ģ������(ai) 2·ģ�����(ao) 2·��������(di) 2·�������(do)
NDAM-3412 4·ģ������(ai) 1·ģ�����(ao) 2·��������(di) 4·�������(do)
NDAM-4017 8·ģ������(ai)
NDAM-4055 8·��������(di) 8·�������(do)
 
module�ڵ�io����ɼ���/���Ƶ�
type,�����������,Ŀǰ����,di/do/ai/ao,��Ӧ��������/�������/ģ������/ģ�����
addr,ʵ�ʵ�ģ����io���,��0��ʼ,֧�ֵ���������ģ�����;���.
var,�����̷��ʵı�����,��׼�ĳ��������������,�������ڵ���,��Ҫ��ģ���ļ��ı�дЭ��.
unit,��λ,����������ʾ,ֻ��ai/ao��Ч.
formula,���㹫ʽ, ֻ��ai/ao��Ч,��ȡ��ֵ��16λ����,�����ô˹�ʽת����ʵ�ʵ�������(@@��ʾai/ao,��ȡ�Ĳ���ֵ)
value,��ʼֵ
notgate,�Ƿ����߼�,Ĭ�����߼�,ֻ��di/do��Ч.
name,��ά�����˿�������,һ���������ƣ����ڽ���.
desc,��ά�����˿�������,һ���Ƚ����Ƶ�����, ����ά��.*/
typedef struct	Module_Ndam_Data
{
	CString	io_type;				
	CString io_addr;
	CString io_var;
	CString io_name;
	CString io_unit;
	CString io_formula;
	CString io_value;
	CString io_desc;
};


	/*
moduleԪ�ض���ɼ���ģ��
      type, ��ģ���ַ,���ڡ�NDAM-9000��,��ַ1-8�����8����ģ��.
      addr, ��ģ������, ���ڡ�NDAM-9000����Ŀǰ֧�ֵ����ͼ��� NDAM-9000��ģ�顱*/
typedef struct	Module_Data
{
	CString elm_module; //moduleԪ�ض���ɼ���ģ��
	CString elm_module_attr_type;  //type, ��ģ���ַ, �磺NDAM-2808
	CString elm_dam_attr_addr;   //addr, ��ģ������,�磺5
	vector<Module_Ndam_Data> elm_module_node_id; //module�ڵ�io����ɼ���/���Ƶ�
};

class CHardwareDef{
public:
    CHardwareDef();
	virtual ~CHardwareDef();
	void Init();  //Ԫ�س�ʼ����

	/*
	���������ECUͨѶ,����Ҫ��comms���������ͨѶ��ʽ,������.
comm����һ��CANͨѶ��
  name,CAN�ӿ�����,Ŀǰ ��ControlCAN��,����������.
  module,CANģ��,Ŀǰ��pci9820b.dll��,��name���, ����������.
  device,CAN�豸,Ŀǰ��5/0��,��name /module���, ����������.
*/
public:
	bool  m_elm_comm_def; //���������ECUͨѶ,����Ҫ��comms���������ͨѶ��ʽ,������.
	CString m_elm_comm;     //comm����һ��CANͨѶ��
	CString m_elm_comm_attr_name[COMM_NUM]; //name,CAN�ӿ�����,Ŀǰ ��ControlCAN��,����������.
	CString m_elm_comm_attr_module[COMM_NUM];  // module,CANģ��,Ŀǰ��pci9820b.dll��,��name���, ����������.
	CString m_elm_comm_attr_device[COMM_NUM];   //device,CAN�豸,Ŀǰ��5/0��,��name /module���, ����������.

/*
damԪ�ض������ݲɼ�ģ��
  type,���ݲɼ�ģ������,Ŀǰ��NDAM-9000��,������������.
  addr,���ݲɼ�ģ���ַ,���ڡ�NDAM-9000��,Ŀǰ�����ַĬ�ϡ�192.168.0.178��
*/
public:
	CString m_elm_dam; //damԪ�ض������ݲɼ�ģ��
	CString m_elm_dam_attr_type[DAM_NUM];  //type,���ݲɼ�ģ������,Ŀǰ��NDAM-9000��,������������.
	CString m_elm_dam_attr_addr[DAM_NUM];  //addr,���ݲɼ�ģ���ַ,���ڡ�NDAM-9000��,Ŀǰ�����ַĬ�ϡ�192.168.0.178��
	 
	/*
moduleԪ�ض���ɼ���ģ��
      type, ��ģ���ַ,���ڡ�NDAM-9000��,��ַ1-8�����8����ģ��.
      addr, ��ģ������, ���ڡ�NDAM-9000����Ŀǰ֧�ֵ����ͼ��� NDAM-9000��ģ�顱*/
	
	vector<Module_Data> m_elm_module; //��module���ڶ�Σ��ʲ���vectorǶ��	

};

#endif