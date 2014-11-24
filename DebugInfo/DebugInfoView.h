
// DebugInfoView.h : CDebugInfoView ��Ľӿ�
//

#pragma once

#include "XRichEditView.h"
class CDebugInfoCntrItem;
class CDebugInfoDoc;
class CDebugInfoView : public CXRichEditView
{
protected: // �������л�����
	CDebugInfoView();
	DECLARE_DYNCREATE(CDebugInfoView)

// ����
public:
	CDebugInfoDoc* GetDocument() const;

// ����
public:
	BOOL RecvDebugMessage(CWnd* pWnd, const CString& strMess);

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDebugInfoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnDestroy();
	DECLARE_MESSAGE_MAP()
public:
	
};

#ifndef _DEBUG  // DebugInfoView.cpp �еĵ��԰汾
inline CDebugInfoDoc* CDebugInfoView::GetDocument() const
   { return reinterpret_cast<CDebugInfoDoc*>(m_pDocument); }
#endif

