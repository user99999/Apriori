// MushroomTestDoc.cpp : implementation of the CMushroomTestDoc class
//

#include "stdafx.h"
#include "MushroomTest.h"

#include "MushroomTestSet.h"
#include "MushroomTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMushroomTestDoc

IMPLEMENT_DYNCREATE(CMushroomTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CMushroomTestDoc, CDocument)
	//{{AFX_MSG_MAP(CMushroomTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMushroomTestDoc construction/destruction

CMushroomTestDoc::CMushroomTestDoc()
{
	// TODO: add one-time construction code here

}

CMushroomTestDoc::~CMushroomTestDoc()
{
}

BOOL CMushroomTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMushroomTestDoc serialization

void CMushroomTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMushroomTestDoc diagnostics

#ifdef _DEBUG
void CMushroomTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMushroomTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMushroomTestDoc commands
