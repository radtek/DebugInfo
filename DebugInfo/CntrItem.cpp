
// CntrItem.cpp : CDebugInfoCntrItem ���ʵ��
//

#include "stdafx.h"
#include "DebugInfo.h"

#include "DebugInfoDoc.h"
#include "DebugInfoView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDebugInfoCntrItem ��ʵ��

IMPLEMENT_SERIAL(CDebugInfoCntrItem, CRichEditCntrItem, 0)

CDebugInfoCntrItem::CDebugInfoCntrItem(REOBJECT* preo, CDebugInfoDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: �ڴ����һ���Թ������
}

CDebugInfoCntrItem::~CDebugInfoCntrItem()
{
	// TODO: �ڴ˴�����������
}


// CDebugInfoCntrItem ���

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

