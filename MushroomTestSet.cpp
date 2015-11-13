// MushroomTestSet.cpp : implementation of the CMushroomTestSet class
//

#include "stdafx.h"
#include "MushroomTest.h"
#include "MushroomTestSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMushroomTestSet implementation

IMPLEMENT_DYNAMIC(CMushroomTestSet, CRecordset)

CMushroomTestSet::CMushroomTestSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CMushroomTestSet)
	m_ID = 0;
	m_item1 = _T("");
	m_item2 = _T("");
	m_item3 = _T("");
	m_item4 = _T("");
	m_item5 = _T("");
	m_item6 = _T("");
	m_item7 = _T("");
	m_item8 = _T("");
	m_item9 = _T("");
	m_item10 = _T("");
	m_item11 = _T("");
	m_item12 = _T("");
	m_item13 = _T("");
	m_item14 = _T("");
	m_item15 = _T("");
	m_item16 = _T("");
	m_item17 = _T("");
	m_item18 = _T("");
	m_item19 = _T("");
	m_item20 = _T("");
	m_item21 = _T("");
	m_item22 = _T("");
	m_item23 = _T("");
	m_nFields = 24;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CMushroomTestSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=testDB");
}

CString CMushroomTestSet::GetDefaultSQL()
{
	return _T("[mushroom]");
}

void CMushroomTestSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CMushroomTestSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[item1]"), m_item1);
	RFX_Text(pFX, _T("[item2]"), m_item2);
	RFX_Text(pFX, _T("[item3]"), m_item3);
	RFX_Text(pFX, _T("[item4]"), m_item4);
	RFX_Text(pFX, _T("[item5]"), m_item5);
	RFX_Text(pFX, _T("[item6]"), m_item6);
	RFX_Text(pFX, _T("[item7]"), m_item7);
	RFX_Text(pFX, _T("[item8]"), m_item8);
	RFX_Text(pFX, _T("[item9]"), m_item9);
	RFX_Text(pFX, _T("[item10]"), m_item10);
	RFX_Text(pFX, _T("[item11]"), m_item11);
	RFX_Text(pFX, _T("[item12]"), m_item12);
	RFX_Text(pFX, _T("[item13]"), m_item13);
	RFX_Text(pFX, _T("[item14]"), m_item14);
	RFX_Text(pFX, _T("[item15]"), m_item15);
	RFX_Text(pFX, _T("[item16]"), m_item16);
	RFX_Text(pFX, _T("[item17]"), m_item17);
	RFX_Text(pFX, _T("[item18]"), m_item18);
	RFX_Text(pFX, _T("[item19]"), m_item19);
	RFX_Text(pFX, _T("[item20]"), m_item20);
	RFX_Text(pFX, _T("[item21]"), m_item21);
	RFX_Text(pFX, _T("[item22]"), m_item22);
	RFX_Text(pFX, _T("[item23]"), m_item23);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CMushroomTestSet diagnostics

#ifdef _DEBUG
void CMushroomTestSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMushroomTestSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
