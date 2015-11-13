// MushroomTestSet.h : interface of the CMushroomTestSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MUSHROOMTESTSET_H__D09F8A4D_10EF_497D_9861_B9211328D62C__INCLUDED_)
#define AFX_MUSHROOMTESTSET_H__D09F8A4D_10EF_497D_9861_B9211328D62C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMushroomTestSet : public CRecordset
{
public:
	CMushroomTestSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMushroomTestSet)

// Field/Param Data
	//{{AFX_FIELD(CMushroomTestSet, CRecordset)
	long	m_ID;
	CString	m_item1;
	CString	m_item2;
	CString	m_item3;
	CString	m_item4;
	CString	m_item5;
	CString	m_item6;
	CString	m_item7;
	CString	m_item8;
	CString	m_item9;
	CString	m_item10;
	CString	m_item11;
	CString	m_item12;
	CString	m_item13;
	CString	m_item14;
	CString	m_item15;
	CString	m_item16;
	CString	m_item17;
	CString	m_item18;
	CString	m_item19;
	CString	m_item20;
	CString	m_item21;
	CString	m_item22;
	CString	m_item23;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMushroomTestSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MUSHROOMTESTSET_H__D09F8A4D_10EF_497D_9861_B9211328D62C__INCLUDED_)

