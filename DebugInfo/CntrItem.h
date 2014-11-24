
// CntrItem.h : CDebugInfoCntrItem ��Ľӿ�
//

#pragma once

class CDebugInfoDoc;
class CDebugInfoView;

class CDebugInfoCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CDebugInfoCntrItem)

// ���캯��
public:
	CDebugInfoCntrItem(REOBJECT* preo = NULL, CDebugInfoDoc* pContainer = NULL);
		// ע��: ���� pContainer Ϊ NULL ������ IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE Ҫ������д���
		//  �����Ĺ��캯����OLE ��ͨ������
		//  �� NULL �ĵ�ָ�빹���

// ����
public:
	CDebugInfoDoc* GetDocument()
		{ return reinterpret_cast<CDebugInfoDoc*>(CRichEditCntrItem::GetDocument()); }
	CDebugInfoView* GetActiveView()
		{ return reinterpret_cast<CDebugInfoView*>(CRichEditCntrItem::GetActiveView()); }

// ʵ��
public:
	~CDebugInfoCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

