// MushroomTestView.cpp : implementation of the CMushroomTestView class
//////////////////////////////////////////////////////////////////////////////
//名称：MushroomTest 
//功能：用Apriori算法实现对字符蘑菇 数据库的频繁集的发现
//		改进了子集测试的方法,可以快速的测试子集的存在性
//		用两种不同的显示形式来显示结果
//		提供数据库的主要参数信息
//
//
//
//当前版本: 1.1
//作	者：郭运凯(gyunkai@163.com)
//完成日期：2006.06.16-17
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MushroomTest.h"

#include "MushroomTestSet.h"
#include "MushroomTestDoc.h"
#include "MushroomTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMushroomTestView

IMPLEMENT_DYNCREATE(CMushroomTestView, CRecordView)

BEGIN_MESSAGE_MAP(CMushroomTestView, CRecordView)
	//{{AFX_MSG_MAP(CMushroomTestView)
	ON_BN_CLICKED(IDC_Bn_FreqItem, OnBnFreqItem)
	ON_BN_CLICKED(IDC_para_set, Onparaset)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMushroomTestView construction/destruction

CMushroomTestView::CMushroomTestView()
	: CRecordView(CMushroomTestView::IDD)
{
	//{{AFX_DATA_INIT(CMushroomTestView)
	m_pSet = NULL;
	m_min_supp = 0.2f;//初始化最小支持度为0.2
	m_total_num = 0;//记录的总条数
	m_min_supp_count = 0;//最小支持度数 
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CMushroomTestView::~CMushroomTestView()
{
	delete [] DB;
}

void CMushroomTestView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMushroomTestView)
	DDX_Control(pDX, IDC_List_FreqItem, m_List_FreqItem);
	DDX_Text(pDX, IDC_min_supp, m_min_supp);
	DDV_MinMaxFloat(pDX, m_min_supp, 0.1f, 1.f);
	DDX_Text(pDX, IDC_total_num, m_total_num);
	DDX_Text(pDX, IDC_min_supp_count, m_min_supp_count);
	//}}AFX_DATA_MAP
}

BOOL CMushroomTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CMushroomTestView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_mushroomTestSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CMushroomTestView printing

BOOL CMushroomTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMushroomTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMushroomTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMushroomTestView diagnostics

#ifdef _DEBUG
void CMushroomTestView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMushroomTestView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMushroomTestDoc* CMushroomTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMushroomTestDoc)));
	return (CMushroomTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMushroomTestView database support
CRecordset* CMushroomTestView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CMushroomTestView message handlers




void CMushroomTestView::HashDB()
{
	//////////////////////////////////////////////////////////////////////////////
	//名称：HashDB 
	//功能：对数据库进行扫描,得到数据库的各个记录的信息,为
	//		数字化测试子集做基础
	//日期：2006.06.16-17
	/////////////////////////////////////////////////////////////////////////////
	
	int m='z';
	int n;
	int k;
	long i;
	char D[24];
	CString strtemp;
	DB=new int[nDbItemCount+1];//用来保存对数据库扫描后得到的信息数值
	if(!DB)
		MessageBox("初始化失败！");
	
	m_pSet->MoveFirst();
	i=1;
	while (! m_pSet->IsEOF()) 
	{
		strtemp= m_pSet->m_item1 + m_pSet->m_item2+ m_pSet->m_item3 + m_pSet->m_item4 +
			m_pSet->m_item5 + m_pSet->m_item6 + m_pSet->m_item7 + m_pSet->m_item8 + 
			m_pSet->m_item9 + m_pSet->m_item10 + m_pSet->m_item11 + m_pSet->m_item12 + 
			m_pSet->m_item13 + m_pSet->m_item14 + m_pSet->m_item15 + m_pSet->m_item16 + 
			m_pSet->m_item17 + m_pSet->m_item18 + m_pSet->m_item19 + m_pSet->m_item20 + 
			m_pSet->m_item21 + m_pSet->m_item22 + m_pSet->m_item23;
	
	
	/*strtemp= m_pSet->m_item1 + m_ps + m_pset->m_item3 + m_pset->m_item4;
			m_pset->m_item5 + m_pset->m_item6 + m_pset->m_item7 + m_pset->m_item8 + 
			m_pset->m_item9 + m_pset->m_item10 + m_pset->m_item11 + m_pset->m_item12 + 
			m_pset->m_item13 + m_pset->m_item14 + m_pset->m_item15 + m_pset->m_item16 + 
			m_pset->m_item17 + m_pset->m_item18 + m_pset->m_item19 + m_pset->m_item20 + 
			m_pset->m_item21 + m_pset->m_item22 + m_pset->m_item23;*/

		//在对	m_pSet 进行整体修改(局部查找替换)时,不留意,把S小写了,造成23处错误,即m_pset 无法识别

		
		//essageBox(strtemp);
		
		n=strlen(strtemp);
		strcpy(D,strtemp);
		DB [i]=0;
		for (int j=0;j<n;j++)
		{
			k=1; 
			DB[i]+=k<<(int)(m-D[j]);	 
		}	 
		
		m_pSet->MoveNext();
		
	//	strtemp.Format("%s%d%s%d","DB[",i,"]=",DB[i]);
	//	MessageBox(strtemp,NULL,MB_OK);
	
		i++;//注意 在这里要对i加1，原来的程序中由于循环时自动对其加1，现在的循环
		//中没有对其修改的表到式，导致了i一直是1，使DB[i]无法在新的地址保存新的值
	}
	
	
}


void CMushroomTestView::check_supp(int num,int no)
{
	//////////////////////////////////////////////////////////////////////////////
	//名称：check_supp(int num,int no)
	//功能：数字化测试子集,num是要测试的记录的总条数
	//		no子集的长度
	//日期：2006.06.16-17
	/////////////////////////////////////////////////////////////////////////////
	CString  strtemp;
	int k,m;
	long i,j;
    int check;
	m='z';
	
	for(i=1;i<=num;i++)//for1
	{	
		check=0;
		C[i].min_supp_count=0;
		for (j=0;j<no;j++)//for2
		{
			k=1;
			check+=(int)(k<<(m-C[i].item[j]));
			
		}//end for2
		
		
		for (j=1;j<=nDbItemCount;j++)//for3
		{
			if (check==(check&DB[j]))
			{
				C[i].min_supp_count+=1;//子集存在，支持度数加1
			}
		}//end for3	
		
			//strtemp.Format("%s%d%s%s%s%d","C[",i,"]=",C[i].item,"   ",C[i].min_supp_count);
		//	MessageBox(strtemp,NULL,MB_OK);
		
	}//end for1
	
	
}//end check_supp(int num,int no)

void CMushroomTestView::C1()
{
	//////////////////////////////////////////////////////////////////////////////
	//名称：C1()
	//功能：初始化候选集数组,并测试1项候选集的支持度数
	//日期：2006.06.16-17
	/////////////////////////////////////////////////////////////////////////////
	strcpy(C[1].item,"a");
	strcpy(C[2].item,"b");
	strcpy(C[3].item,"c");
	strcpy(C[4].item,"d");
	strcpy(C[5].item,"e");
	strcpy(C[6].item,"f");
	strcpy(C[7].item,"g");
	strcpy(C[8].item,"h");
	strcpy(C[9].item,"i");
	strcpy(C[10].item,"j");
	strcpy(C[11].item,"k");
	strcpy(C[12].item,"l");
	strcpy(C[13].item,"m");
	strcpy(C[14].item,"n");
	strcpy(C[15].item,"o");
	strcpy(C[16].item,"p");
	strcpy(C[17].item,"q");
	strcpy(C[18].item,"r");
	strcpy(C[19].item,"s");
	strcpy(C[20].item,"t");
	strcpy(C[21].item,"u");
	strcpy(C[22].item,"v");
	strcpy(C[23].item,"w");
	strcpy(C[24].item,"x");
	strcpy(C[25].item,"y");
	strcpy(C[26].item,"z");
	
	C[0].min_supp_count=26;  //1 项候选集的个数，在本算法中，用C[0].min_supp_count来保存候选集Cn的个数   
	
	check_supp(26,1);
	
	
}  //end of  C1()

void CMushroomTestView::Cn(int n)
{  
	//////////////////////////////////////////////////////////////////////////////
	//名称：Cn(int n) 
	//功能：用频繁集Ln-1为基础，通过连接得到n项候选集Cn,并测试n项候选集的支持度数
	//日期：2006.06.16-17
	/////////////////////////////////////////////////////////////////////////////
	
	int i,j,k,num;
	int no=0,temp=0;
	
	C[0].min_supp_count=0;  //初始化
	
	
	num=L[0].min_supp_count;  //num是Ln-1项集的数据个数
	
	for(i=1;i<=num;i++)  
		
		for(j=i+1;j<=num;j++)   //for2
		{
			
			temp=1;  //测试是否满足联结条件
			if(n>2)//if 1
			{
				for(k=0;k<n-2;k++)    	//for3	  
				{
					if(L[i].item[k]!=L[j].item[k])
					{  temp=0;
					break; }//if 1
					
				}//end for3
				
			}//end if1
			
			if(temp==1)//满足联结条件
			{
				// printf("in if 2  no=%d\n",no);
				no++;
			strcpy(C[no].item,L[i].item);	//在这里，用字符串拷贝函数直接把L[i].item赋值给C[no].item			
			C[no].item[n-1]=L[j].item[n-2];	//L[j].item[n-2]赋值给C[no].item[n-1]，
			C[no].item[n]='\0';				//设置末尾标志位
				C[no].min_supp_count=0;
				C[0].min_supp_count+=1;
			}//end if2
		}//end for2

		num=C[0].min_supp_count;
		
		check_supp(num,n);//测试支持度 
		
}//end of Cn()  


void  CMushroomTestView::L1()
{	
	//////////////////////////////////////////////////////////////////////////////
	//名称：L1()
	//功能：以C1为基础,得到1项频繁集L-1
	//日期：2006.06.16-17
	/////////////////////////////////////////////////////////////////////////////
	CString strValue,strtemp;
	int n=1;
	int i,j,k;
	j=0;
	L[0].min_supp_count=0;//频繁集的个数，初始为0
	
	for(i=1;i<=C[0].min_supp_count;i++)
	{    
		if(C[i].min_supp_count>=min_supp_count)
		{
			j+=1;
			strcpy(L[j].item,C[i].item);		
			L[j].min_supp_count=C[i].min_supp_count;

		//	strtemp.Format("%s%d%s%d","L[",j,"]=",L[j].min_supp_count);
		//	MessageBox(strtemp,NULL,MB_OK);
		}
	}//end for1
	L[0].min_supp_count=j;///频繁集的个数,最后为j个
	
	
	k=L[0].min_supp_count;
	
   // nLargeCount++;	
	m_List_FreqItem.InsertItem(nLargeCount,strValue);
	m_List_FreqItem.SetItemText(nLargeCount,0,"_____________"); 
	m_List_FreqItem.SetItemText(nLargeCount,1,"______________"); 
	
	
	
	if(k!=0)
	{ 
		for(i=1;i<=k;i++)
		{
			nLargeCount++;		
			strtemp="";
			strtemp.Format("%s%d",strtemp,L[i].min_supp_count);
			///(float)nDbItemCount
			
			m_List_FreqItem.InsertItem(nLargeCount,strValue);
			
			m_List_FreqItem.SetItemText(nLargeCount,0,L[i].item);
			m_List_FreqItem.SetItemText(nLargeCount,1,strtemp);
			
			
			
			UpdateWindow(); 
			
			
		}//for
		
		
		
	}//if
	
}//end of L1()


void CMushroomTestView::Ln(int n)
{  
	//////////////////////////////////////////////////////////////////////////////
	//名称：Ln(int n)
	//功能：以Cn为基础,得到n项频繁集L-n
	//日期：2006.06.16-17
	/////////////////////////////////////////////////////////////////////////////
	CString strValue,strtemp;
	int i,j,k;
	Cn(n);
	j=0;
	L[0].min_supp_count=0;


	for(i=1;i<=C[0].min_supp_count;i++)  //for 1
	{
		if(C[i].min_supp_count >=min_supp_count)
		{
			j+=1;
			strcpy(L[j].item,C[i].item);		
			L[j].min_supp_count=C[i].min_supp_count;

			//strtemp.Format("%s%d%s%d","L[",j,"]=",L[j].min_supp_count);
		//	MessageBox(strtemp,NULL,MB_OK);
		
	}  //end if
	
	
}//end for1


		L[0].min_supp_count=j; //保存数据的个数
		k=L[0].min_supp_count;


		nLargeCount++;	
		m_List_FreqItem.InsertItem(nLargeCount,strValue);
		m_List_FreqItem.SetItemText(nLargeCount,0,"_______________"); 
		m_List_FreqItem.SetItemText(nLargeCount,1,"______________"); 


		if(k!=0)
		{ 
			for(i=1;i<=k;i++)
				{
		
				nLargeCount++;		
				
				strtemp="";
				strtemp.Format("%s%d",strtemp,L[i].min_supp_count);
				
				m_List_FreqItem.InsertItem(nLargeCount,strValue);
				
				m_List_FreqItem.SetItemText(nLargeCount,0,L[i].item);
				m_List_FreqItem.SetItemText(nLargeCount,1,strtemp);
				
				
				
				UpdateWindow(); 
				
				}//for
	
	
			}//if
	
}//end of Ln(int n)




void CMushroomTestView::Onparaset() 
{
	//////////////////////////////////////////////////////////////////////////////
	//名称：Onparaset()
	//功能：设置最小支持度数
	//日期：2006.06.16-17
	/////////////////////////////////////////////////////////////////////////////
		UpdateData(true);
	min_supp=m_min_supp;	
	
}

void CMushroomTestView::ClearItem()
{   
	//清除列表显示的内容
	m_List_FreqItem.DeleteAllItems ();
	while(m_List_FreqItem.DeleteColumn (0));
		UpdateWindow();	
	
}






void CMushroomTestView::OnBnFreqItem() 
{
	// TODO: Add your control notification handler code here
	//////////////////////////////////////////////////////////////////////////////
	//名称：OnBnFreqItem() 
	//功能：用Apriori算法实现对字符蘑菇数据库的频繁集的发现
	//作者：郭运凯(gyunkai@163.com)
	//日期：2006.06.16-17
	/////////////////////////////////////////////////////////////////////////////
	
	// TODO: Add your control notification handler code here
	int n=1;
	CString strtemp;
	clock_t start,stop,tick;
	double timeused;
	nLargeCount=0;      //第一次,没有对nLargeCount进行初始化,造成程序的结果都无法输出
	//问题看似很简单,但一不注意,就造成了错误
	
	
	
	
	while (!m_pSet->IsEOF()) 
	{
		m_pSet->MoveNext();
	}
	
	m_pSet->MovePrev();
	
	nDbItemCount=(m_pSet->GetRecordCount());//得到数据库记录的总条数
	m_total_num=nDbItemCount;
	UpdateData(false);

	min_supp_count=(int)(min_supp*nDbItemCount);//得到最小支持度数
	m_min_supp_count=min_supp_count;
	UpdateData(false);
	
	//min_supp_count=(int)min_supp*nDbItemCount;//得到最小支持度数
	//在这里，min_supp_count=0。原因是(int)是左结合的，在这里min_supp的值是0.3，变成整数后
	//(int)min_supp 就是0，再乘以nDbItemCount。结果仍然是0，造成min_supp_count=0，使得所有
	//的候选集都可以成为了频繁集
	//对运算符不能想当然的去理解。把握不清的就加括号，提高表达式的优先级，避免错误的发生
	
	
//	strtemp.Format("%s%d",strtemp,min_supp_count);
//	MessageBox(strtemp,NULL,MB_OK);
	
	
	HashDB();
	start=clock();
	ClearItem();		
	m_List_FreqItem.InsertColumn(0,"Item",LVCFMT_LEFT,100);
	m_List_FreqItem.InsertColumn(1,"Support",LVCFMT_LEFT,100);
	
	
	
	
	C1();//初始化,生成1项候选集C1
	L1();//得到1项频繁集L1
	/*Ln(2);
	Ln(3);
		Ln(4);
			Ln(5);
				Ln(6);
					Ln(7);
						Ln(8);
							Ln(9);
							Ln(10);
							Ln(11);
							Ln(12);
							Ln(13);*/
						
while(L[0].min_supp_count!=0)
	{
		n+=1;
		Ln(n);
	}
	stop=clock();
	
	tick=stop - start;
    timeused=(double)tick/CLOCKS_PER_SEC;
	// CLK_TCK
	
	strtemp.Format("%s%f",strtemp,timeused);
	MessageBox(strtemp,NULL,MB_OK);
	
}


