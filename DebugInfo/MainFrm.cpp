
// MainFrm.cpp : CMainFrame 类的实现
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
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

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
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	WNDCLASS wndClass;   
	::GetClassInfo(AfxGetInstanceHandle(), cs.lpszClass, &wndClass);   
	wndClass.lpszClassName = _T("DebugMess");   
	VERIFY(AfxRegisterClass(&wndClass));   
	cs.lpszClass = wndClass.lpszClassName;

	cs.lpszName = _T("调试信息显示窗口");
	return TRUE;
}

// CMainFrame 诊断

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


// CMainFrame 消息处理程序


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

	//时间
	if (m_bSTime)
	{
		COleDateTime tm = COleDateTime::GetTickCount();
		strText.Format(_T("[%s.%03.0d] "), 
						tm.Format(_T("%Y-%m-%d %H:%M:%S")), 
						::GetTickCount()%1000);
		pView->AddString(strText, 5);
	}

	//窗口
	pWnd->GetWindowText(strTmp);
	strText.Format(_T("%s "), strTmp);
	pView->AddString(strText, 0);

	//数据
	strTmp = strMess;
	strTmp += _T("\n");
	pView->AddString(strTmp, nLevel);
}