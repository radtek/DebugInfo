
// CntrItem.cpp : CDebugInfoCntrItem 类的实现
//

#include "stdafx.h"
#include "DebugInfo.h"

#include "DebugInfoDoc.h"
#include "DebugInfoView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDebugInfoCntrItem 的实现

IMPLEMENT_SERIAL(CDebugInfoCntrItem, CRichEditCntrItem, 0)

CDebugInfoCntrItem::CDebugInfoCntrItem(REOBJECT* preo, CDebugInfoDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: 在此添加一次性构造代码
}

CDebugInfoCntrItem::~CDebugInfoCntrItem()
{
	// TODO: 在此处添加清理代码
}


// CDebugInfoCntrItem 诊断

#ifdef _DEBUG
void CDebugInfoCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CDebugInfoCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

