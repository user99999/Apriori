// MushroomTestDoc.h : interface of the CMushroomTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MUSHROOMTESTDOC_H__25BD06FF_A8F2_4389_9575_DF381490B321__INCLUDED_)
#define AFX_MUSHROOMTESTDOC_H__25BD06FF_A8F2_4389_9575_DF381490B321__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MushroomTestSet.h"


class CMushroomTestDoc : public CDocument
{
protected: // create from serialization only
	CMushroomTestDoc();
	DECLARE_DYNCREATE(CMushroomTestDoc)

// Attributes
public:
	CMushroomTestSet m_mushroomTestSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMushroomTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMushroomTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMushroomTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MUSHROOMTESTDOC_H__25BD06FF_A8F2_4389_9575_DF381490B321__INCLUDED_)
