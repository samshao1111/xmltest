// HardwareDef.h
#ifndef _HardwareDef_H
#define _HardwareDef_H

#include <vector>
using std::vector;

#define COMM_NUM   1
#define DAM_NUM		1

//定义module NDAM-9000各个子模块io节点数据
//<io type="ai" addr="0" var="motor_i"   name="电机/加热模块电流" unit="mA" formula="(@@/65535*20-10)*1000/64/0.05" 
//value="0x8000" desc="±150mV @0.05Ω" />
/*
NDAM-9000子模块, 后续会增加
NDAM-2808 8路继电器输出(do)
NDAM-3402 8路模拟输入(ai) 2路模拟输出(ao) 2路数字输入(di) 2路数字输出(do)
NDAM-3412 4路模拟输入(ai) 1路模拟输出(ao) 2路数字输入(di) 4路数字输出(do)
NDAM-4017 8路模拟输入(ai)
NDAM-4055 8路数字输入(di) 8路数字输出(do)
 
module内的io定义采集点/控制点
type,输入输出类型,目前四类,di/do/ai/ao,对应数字输入/数字输出/模拟输入/模拟输出
addr,实际的模块内io序号,从0开始,支持的上限由子模块类型决定.
var,给流程访问的变量名,标准的程序变量命名规则,供流程内调用,需要和模型文件的编写协调.
unit,单位,仅仅用于显示,只对ai/ao有效.
formula,换算公式, 只对ai/ao有效,读取的值是16位整数,可以用此公式转换成实际的物理量(@@表示ai/ao,读取的测量值)
value,初始值
notgate,是否正逻辑,默认正逻辑,只对di/do有效.
name,给维护的人看的名称,一个简洁的名称，便于交流.
desc,给维护的人看的描述,一个比较完善的描述, 便于维护.*/
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
module元素定义采集子模块
      type, 子模块地址,对于“NDAM-9000“,地址1-8，最多8个子模块.
      addr, 子模块类型, 对于“NDAM-9000“，目前支持的类型见” NDAM-9000子模块”*/
typedef struct	Module_Data
{
	CString elm_module; //module元素定义采集子模块
	CString elm_module_attr_type;  //type, 子模块地址, 如：NDAM-2808
	CString elm_dam_attr_addr;   //addr, 子模块类型,如：5
	vector<Module_Ndam_Data> elm_module_node_id; //module内的io定义采集点/控制点
};

class CHardwareDef{
public:
    CHardwareDef();
	virtual ~CHardwareDef();
	void Init();  //元素初始化；

	/*
	如果座椅有ECU通讯,则需要有comms定义控制器通讯方式,否则无.
comm定义一张CAN通讯卡
  name,CAN接口类型,目前 “ControlCAN“,后续会增加.
  module,CAN模块,目前“pci9820b.dll“,和name相关, 后续会增加.
  device,CAN设备,目前“5/0“,和name /module相关, 后续会增加.
*/
public:
	bool  m_elm_comm_def; //如果座椅有ECU通讯,则需要有comms定义控制器通讯方式,否则无.
	CString m_elm_comm;     //comm定义一张CAN通讯卡
	CString m_elm_comm_attr_name[COMM_NUM]; //name,CAN接口类型,目前 “ControlCAN“,后续会增加.
	CString m_elm_comm_attr_module[COMM_NUM];  // module,CAN模块,目前“pci9820b.dll“,和name相关, 后续会增加.
	CString m_elm_comm_attr_device[COMM_NUM];   //device,CAN设备,目前“5/0“,和name /module相关, 后续会增加.

/*
dam元素定义数据采集模块
  type,数据采集模块类型,目前“NDAM-9000“,后续可能增加.
  addr,数据采集模块地址,对于“NDAM-9000“,目前网络地址默认”192.168.0.178”
*/
public:
	CString m_elm_dam; //dam元素定义数据采集模块
	CString m_elm_dam_attr_type[DAM_NUM];  //type,数据采集模块类型,目前“NDAM-9000“,后续可能增加.
	CString m_elm_dam_attr_addr[DAM_NUM];  //addr,数据采集模块地址,对于“NDAM-9000“,目前网络地址默认”192.168.0.178”
	 
	/*
module元素定义采集子模块
      type, 子模块地址,对于“NDAM-9000“,地址1-8，最多8个子模块.
      addr, 子模块类型, 对于“NDAM-9000“，目前支持的类型见” NDAM-9000子模块”*/
	
	vector<Module_Data> m_elm_module; //因module存在多次，故采用vector嵌套	

};

#endif