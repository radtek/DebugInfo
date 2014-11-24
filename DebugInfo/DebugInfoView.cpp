
// DebugInfoView.cpp : CDebugInfoView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DebugInfo.h"
#endif

#include "DebugInfoDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "DebugInfoView.h"

#include "Debug.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDebugInfoView

IMPLEMENT_DYNCREATE(CDebugInfoView, CXRichEditView)

BEGIN_MESSAGE_MAP(CDebugInfoView, CXRichEditView)
	ON_WM_DESTROY()
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CXRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CXRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CXRichEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDebugInfoView 构造/析构

CDebugInfoView::CDebugInfoView()
{
	// TODO: 在此处添加构造代码

}

CDebugInfoView::~CDebugInfoView()
{
}

BOOL CDebugInfoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	
	return CXRichEditView::PreCreateWindow(cs);
}

void CDebugInfoView::OnInitialUpdate()
{
	CXRichEditView::OnInitialUpdate();


	// 设置打印边距(720 缇 = 1/2 英寸)
	SetMargins(CRect(720, 720, 720, 720));
}


// CDebugInfoView 打印

BOOL CDebugInfoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}


void CDebugInfoView::OnDestroy()
{
	// 析构时停用此项；这在
	// 使用拆分视图时非常重要 
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CXRichEditView::OnDestroy();
}



// CDebugInfoView 诊断

#ifdef _DEBUG
void CDebugInfoView::AssertValid() const
{
	CXRichEditView::AssertValid();
}

void CDebugInfoView::Dump(CDumpContext& dc) const
{
	CXRichEditView::Dump(dc);
}

CDebugInfoDoc* CDebugInfoView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDebugInfoDoc)));
	return (CDebugInfoDoc*)m_pDocument;
}
#endif //_DEBUG


// CDebugInfoView 消息处理程序


BOOL CDebugInfoView::RecvDebugMessage(CWnd* pWnd, const CString& strMess)
{
	COleDateTime tm = COleDateTime::GetTickCount();

	
	return FALSE;
}