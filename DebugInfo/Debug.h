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
	static void ShowImpMessage(TCHAR* szMessage);		//�ӿ���Ϣ
	static void ShowFunMessage(TCHAR* szMessage);		//������Ϣ
	static void ShowErrMessage(TCHAR* szFormat, ...);	//������Ϣ
	static void ShowLogMessage(TCHAR* szFormat, ...);	//��־��Ϣ

	static void ShowDataMessage(BYTE* pBuf, int nLen);	//������Ϣ
	static void ShowSendMessage(BYTE* pBuf, int nLen);	//������Ϣ
	static void ShowRecvMessage(BYTE* pBuf, int nLen);	//������Ϣ

	static void SetShowOP(UINT nOP);	//������ʾѡ��
	static UINT GetShowOP();			//��ȡ��ʾѡ��

protected:
	static void _ShowDebugMessage(int nLevel, CString strMess); //������Ϣ

private:
	static UINT sm_nShowOP;
	static CDebug sm_cInst; //��֤���ٳ�ʼ��һ��
};

