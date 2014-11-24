#pragma once

//Show option
#define	SOP_IMP		0x0001
#define	SOP_FUN		0x0002
#define	SOP_ERR		0x0004
#define	SOP_LOG		0x0008
#define SOP_DATA	0x0010
#define SOP_ALL		0x00FF

//Debug Message Level
#define DBLV_IMP		1   // Interface flow 
#define	DBLV_FUN		2	// Function flow 
#define	DBLV_ERR 		3	// Error handle information 
#define	DBLV_LOG		4	// Log Information by definited
#define DBLV_DATA		5   // Send and Receive data message

#define DBF_DATA   0x1234	//Debug Flag Data
#define MAX_MESSAGE_LEN	1024
class CDebug
{
public:
	CDebug(void);
	virtual ~CDebug(void);

public:
	static void ShowImpMessage(TCHAR* szMessage);		//接口信息
	static void ShowFunMessage(TCHAR* szMessage);		//方法信息
	static void ShowErrMessage(TCHAR* szFormat, ...);	//错误信息
	static void ShowLogMessage(TCHAR* szFormat, ...);	//日志信息

	static void ShowDataMessage(BYTE* pBuf, int nLen);	//数据信息
	static void ShowSendMessage(BYTE* pBuf, int nLen);	//发送信息
	static void ShowRecvMessage(BYTE* pBuf, int nLen);	//接收信息

	static void SetShowOP(UINT nOP);	//设置显示选项
	static UINT GetShowOP();			//获取显示选项

protected:
	static void _ShowDebugMessage(int nLevel, CString strMess); //调试信息

private:
	static UINT sm_nShowOP;
	static CDebug sm_cInst; //保证至少初始化一次
};

