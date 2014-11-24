
// DebugInfoDoc.cpp : CDebugInfoDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DebugInfo.h"
#endif

#include "DebugInfoDoc.h"
#include "CntrItem.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDebugInfoDoc

IMPLEMENT_DYNCREATE(CDebugInfoDoc, CXRichEditDoc)

BEGIN_MESSAGE_MAP(CDebugInfoDoc, CXRichEditDoc)
	// ����Ĭ�ϵ� OLE ����ʵ��
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &CXRichEditDoc::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &CXRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &CXRichEditDoc::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()


// CDebugInfoDoc ����/����

CDebugInfoDoc::CDebugInfoDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CDebugInfoDoc::~CDebugInfoDoc()
{
}

BOOL CDebugInfoDoc::OnNewDocument()
{
	if (!CXRichEditDoc::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}

CRichEditCntrItem* CDebugInfoDoc::CreateClientItem(REOBJECT* preo) const
{
	return new CDebugInfoCntrItem(preo, const_cast<CDebugInfoDoc*>(this));
}




// CDebugInfoDoc ���л�

void CDebugInfoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}

	// ���û��� CRichEditDoc ������
	//  �����ĵ��� COleClientItem ��������л���
	// TODO: �����Ϊ�ı��������л��������� CRichEditDoc::m_bRTF = FALSE
	CXRichEditDoc::Serialize(ar);
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CDebugInfoDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CDebugInfoDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CDebugInfoDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDebugInfoDoc ���

#ifdef _DEBUG
void CDebugInfoDoc::AssertValid() const
{
	CXRichEditDoc::AssertValid();
}

void CDebugInfoDoc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG


// CDebugInfoDoc ����
