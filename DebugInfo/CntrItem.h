
// CntrItem.h : CDebugInfoCntrItem 类的接口
//

#pragma once

class CDebugInfoDoc;
class CDebugInfoView;

class CDebugInfoCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CDebugInfoCntrItem)

// 构造函数
public:
	CDebugInfoCntrItem(REOBJECT* preo = NULL, CDebugInfoDoc* pContainer = NULL);
		// 注意: 允许 pContainer 为 NULL 以启用 IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE 要求类具有带零
		//  参数的构造函数。OLE 项通常是用
		//  非 NULL 文档指针构造的

// 特性
public:
	CDebugInfoDoc* GetDocument()
		{ return reinterpret_cast<CDebugInfoDoc*>(CRichEditCntrItem::GetDocument()); }
	CDebugInfoView* GetActiveView()
		{ return reinterpret_cast<CDebugInfoView*>(CRichEditCntrItem::GetActiveView()); }

// 实现
public:
	~CDebugInfoCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

