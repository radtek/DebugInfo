
// DebugInfoView.h : CDebugInfoView 类的接口
//

#pragma once

#include "XRichEditView.h"
class CDebugInfoCntrItem;
class CDebugInfoDoc;
class CDebugInfoView : public CXRichEditView
{
protected: // 仅从序列化创建
	CDebugInfoView();
	DECLARE_DYNCREATE(CDebugInfoView)

// 特性
public:
	CDebugInfoDoc* GetDocument() const;

// 操作
public:
	BOOL RecvDebugMessage(CWnd* pWnd, const CString& strMess);

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDebugInfoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnDestroy();
	DECLARE_MESSAGE_MAP()
public:
	
};

#ifndef _DEBUG  // DebugInfoView.cpp 中的调试版本
inline CDebugInfoDoc* CDebugInfoView::GetDocument() const
   { return reinterpret_cast<CDebugInfoDoc*>(m_pDocument); }
#endif

