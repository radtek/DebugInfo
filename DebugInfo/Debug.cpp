#include "StdAfx.h"
#include "Debug.h"

UINT CDebug::sm_nShowOP = 0;
CDebug CDebug::sm_cInst;
CDebug::CDebug(void)
{
	SetShowOP(SOP_ALL);
}


CDebug::~CDebug(void)
{
	SetShowOP(0);
}

void CDebug::ShowImpMessage( TCHAR* szMessage )
{
	if (sm_nShowOP & SOP_IMP)
	{
		_ShowDebugMessage(DBLV_IMP, szMessage);
	}
}

void CDebug::ShowFunMessage( TCHAR* szMessage )
{
	if (sm_nShowOP & SOP_FUN)
	{
		_ShowDebugMessage(DBLV_FUN, szMessage);
	}
}

void CDebug::ShowErrMessage( TCHAR* szFormat, ... )
{
	if (sm_nShowOP & SOP_ERR)
	{
		va_list args;
		va_start(args, szFormat);
		CString strMess;
		strMess.FormatV(szFormat, args);
		va_end(args);

		_ShowDebugMessage(DBLV_ERR, strMess);
	}
}

void CDebug::ShowLogMessage( TCHAR* szFormat, ... )
{
	if (sm_nShowOP & SOP_LOG)
	{
		va_list args;
		va_start(args, szFormat);
		CString strMess;
		strMess.FormatV(szFormat, args);
		va_end(args);

		_ShowDebugMessage(DBLV_LOG, strMess);
	}
}

void CDebug::ShowDataMessage( BYTE* pBuf, int nLen )
{
	if (sm_nShowOP & SOP_DATA)
	{
		CString strMessage = _T(""), strTmp(_T(""));
		for (int i=0 ; i<nLen ;i++)
		{
			strTmp.Format(_T("%02X "), pBuf[i]);
			strMessage += strTmp;
		}
		_ShowDebugMessage(DBLV_DATA, strMessage.GetBuffer(0));
	}
}

void CDebug::ShowSendMessage( BYTE* pBuf, int nLen )
{
	if (sm_nShowOP & SOP_DATA)
	{
		_ShowDebugMessage(DBLV_LOG, _T("Send: "));
		ShowDataMessage(pBuf, nLen);
	}
}

void CDebug::ShowRecvMessage( BYTE* pBuf, int nLen )
{
	if (sm_nShowOP & SOP_DATA)
	{
		_ShowDebugMessage(DBLV_LOG, _T("Recv: "));
		ShowDataMessage(pBuf, nLen);
	}
}

void CDebug::SetShowOP( UINT nOP )
{
	sm_nShowOP = nOP;
}

UINT CDebug::GetShowOP()
{
	return sm_nShowOP;
}

void CDebug::_ShowDebugMessage( int nLevel, CString strMess )
{
	static HWND s_hMainWnd = AfxGetMainWnd() ? AfxGetMainWnd()->GetSafeHwnd() : NULL;
	HWND hMessWnd = ::FindWindow( _T("DebugMess"), NULL);

	if( hMessWnd && !strMess.IsEmpty())
	{	
		COPYDATASTRUCT copyData = {0};
		copyData.dwData = nLevel;
		copyData.cbData = strMess.GetLength()+1;
		copyData.lpData = strMess.GetBuffer(0);

		::SendMessage(hMessWnd, WM_COPYDATA, WPARAM(s_hMainWnd), LPARAM(&copyData));
	}
}