// MushroomTestView.h : interface of the CMushroomTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MUSHROOMTESTVIEW_H__BE7DAEFB_931D_41F0_9ECE_7BDBA57F0878__INCLUDED_)
#define AFX_MUSHROOMTESTVIEW_H__BE7DAEFB_931D_41F0_9ECE_7BDBA57F0878__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class C_Node
{
public:
	char item[23];  //������
	int min_supp_count;//��С֧�ֶ���
}; //��ѡ��

class L_Node
{
public:
	char item[23];  //������
	int min_supp_count;//��С֧�ֶ���
	
};//Ƶ����


class CMushroomTestSet;

class CMushroomTestView : public CRecordView
{
protected: // create from serialization only
	CMushroomTestView();
	DECLARE_DYNCREATE(CMushroomTestView)

public:
	//{{AFX_DATA(CMushroomTestView)
	enum { IDD = IDD_MUSHROOMTEST_FORM };
	CListCtrl	m_List_FreqItem;
	CMushroomTestSet* m_pSet;
	float	m_min_supp;
	long	m_total_num;
	long	m_min_supp_count;
	//}}AFX_DATA

// Attributes
public:
	CMushroomTestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMushroomTestView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	int nDbItemCount;//ͳ�����ݿ����������
	int nLargeCount;//ͳ��Ƶ�������ܸ���
	int min_supp_count;//��С֧�ֶ��� min_supp_count=nDbItemCount*min_supp
	float min_supp;//��С֧�ֶ�min_supp
	int  * DB;//ָ��,�������ɱ������ݿ�ɢ�к������
	int row,col;
	void suppDB(long num);//
	void check_supp(int num,int no);//
	void  C1();//����1���ѡ��
	void Cn( int n);//����n���ѡ��
	void L1();//����1��Ƶ����
	void Ln(int n);//����1��Ƶ����
	void HashDB();//ͨ��ɨ�����ݿ�, �õ����ݿ��ɢ����ֵ
	void ClearItem();
	C_Node C[9000];
	L_Node L[9000];

	virtual ~CMushroomTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMushroomTestView)
	afx_msg void OnBnFreqItem();
	afx_msg void Onparaset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MushroomTestView.cpp
inline CMushroomTestDoc* CMushroomTestView::GetDocument()
   { return (CMushroomTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MUSHROOMTESTVIEW_H__BE7DAEFB_931D_41F0_9ECE_7BDBA57F0878__INCLUDED_)





















