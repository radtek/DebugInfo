
// DebugInfoView.cpp : CDebugInfoView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CXRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CXRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CXRichEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDebugInfoView ����/����

CDebugInfoView::CDebugInfoView()
{
	// TODO: �ڴ˴���ӹ������

}

CDebugInfoView::~CDebugInfoView()
{
}

BOOL CDebugInfoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	
	return CXRichEditView::PreCreateWindow(cs);
}

void CDebugInfoView::OnInitialUpdate()
{
	CXRichEditView::OnInitialUpdate();


	// ���ô�ӡ�߾�(720 � = 1/2 Ӣ��)
	SetMargins(CRect(720, 720, 720, 720));
}


// CDebugInfoView ��ӡ

BOOL CDebugInfoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}


void CDebugInfoView::OnDestroy()
{
	// ����ʱͣ�ô������
	// ʹ�ò����ͼʱ�ǳ���Ҫ 
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CXRichEditView::OnDestroy();
}



// CDebugInfoView ���

#ifdef _DEBUG
void CDebugInfoView::AssertValid() const
{
	CXRichEditView::AssertValid();
}

void CDebugInfoView::Dump(CDumpContext& dc) const
{
	CXRichEditView::Dump(dc);
}

CDebugInfoDoc* CDebugInfoView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDebugInfoDoc)));
	return (CDebugInfoDoc*)m_pDocument;
}
#endif //_DEBUG


// CDebugInfoView ��Ϣ�������


BOOL CDebugInfoView::RecvDebugMessage(CWnd* pWnd, const CString& strMess)
{
	COleDateTime tm = COleDateTime::GetTickCount();

	
	return FALSE;
}