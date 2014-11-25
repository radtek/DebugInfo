
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "DebugInfo.h"

#include "MainFrm.h"
#include "DebugInfoDoc.h"
#include "DebugInfoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_COPYDATA()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	m_bSTime = TRUE;
	m_bPauseDis = FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	WNDCLASS wndClass;   
	::GetClassInfo(AfxGetInstanceHandle(), cs.lpszClass, &wndClass);   
	wndClass.lpszClassName = _T("DebugMess");   
	VERIFY(AfxRegisterClass(&wndClass));   
	cs.lpszClass = wndClass.lpszClassName;

	cs.lpszName = _T("������Ϣ��ʾ����");
	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������


BOOL CMainFrame::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
{
	if (pCopyDataStruct != NULL && pCopyDataStruct->lpData != NULL)
	{
		int nLevel = pCopyDataStruct->dwData;
		CString strMess = (TCHAR*)pCopyDataStruct->lpData;

		//Process Recv Message
		TRACE(_T("RecvDebugMessage: %s\n"), strMess);
		
		return DisplayMessage(pWnd, nLevel, strMess);
	}
	return CFrameWnd::OnCopyData(pWnd, pCopyDataStruct);
}

BOOL CMainFrame::DisplayMessage(CWnd* pWnd, int nLevel, const CString& strMess)
{
	if (m_bPauseDis)
		return TRUE;

	CDebugInfoView* pView = GetView();
	if (pView == NULL)
		return FALSE;

	CString strTmp, strText;
	TCHAR szTmp[12] = {0};

	//ʱ��
	if (m_bSTime)
	{
		COleDateTime tm = COleDateTime::GetTickCount();
		strText.Format(_T("[%s.%03.0d] "), 
						tm.Format(_T("%Y-%m-%d %H:%M:%S")), 
						::GetTickCount()%1000);
		pView->AddString(strText, 5);
	}

	//����
	pWnd->GetWindowText(strTmp);
	strText.Format(_T("%s "), strTmp);
	pView->AddString(strText, 0);

	//����
	strTmp = strMess;
	strTmp += _T("\n");
	pView->AddString(strTmp, nLevel);
}