// DIALOGCARRAYTEST.cpp : implementation file
//

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "DIALOGCARRAYTEST.h"
#include "PROMPTINFO.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern BYTE		m_byteaCFCT[];
extern BYTE 	m_bytepCFCT;
extern PROMPTINFO	m_promptinfoCFCT;
/////////////////////////////////////////////////////////////////////////////
// DIALOGCARRAYTEST dialog


DIALOGCARRAYTEST::DIALOGCARRAYTEST(CWnd* pParent /*=NULL*/)
	: CDialog(DIALOGCARRAYTEST::IDD, pParent)
{
	//{{AFX_DATA_INIT(DIALOGCARRAYTEST)
	m_strtest1 = _T("");
	m_strtest10 = _T("");
	m_strtest11 = _T("");
	m_strtest12 = _T("");
	m_strtest13 = _T("");
	m_strtest14 = _T("");
	m_strtest15 = _T("");
	m_strtest16 = _T("");
	m_strtest17 = _T("");
	m_strtest18 = _T("");
	m_strtest19 = _T("");
	m_strtest2 = _T("");
	m_strtest20 = _T("");
	m_strtest21 = _T("");
	m_strtest22 = _T("");
	m_strtest23 = _T("");
	m_strtest24 = _T("");
	m_strtest25 = _T("");
	m_strtest26 = _T("");
	m_strtest27 = _T("");
	m_strtest28 = _T("");
	m_strtest29 = _T("");
	m_strtest3 = _T("");
	m_strtest30 = _T("");
	m_strtest31 = _T("");
	m_strtest32 = _T("");
	m_strtest33 = _T("");
	m_strtest34 = _T("");
	m_strtest35 = _T("");
	m_strtest36 = _T("");
	m_strtest37 = _T("");
	m_strtest38 = _T("");
	m_strtest39 = _T("");
	m_strtest4 = _T("");
	m_strtest40 = _T("");
	m_strtest5 = _T("");
	m_strtest6 = _T("");
	m_strtest7 = _T("");
	m_strtest8 = _T("");
	m_strtest9 = _T("");
	//}}AFX_DATA_INIT
}


void DIALOGCARRAYTEST::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DIALOGCARRAYTEST)
	DDX_Text(pDX, IDC_TEST1, m_strtest1);
	DDX_Text(pDX, IDC_TEST10, m_strtest10);
	DDX_Text(pDX, IDC_TEST11, m_strtest11);
	DDX_Text(pDX, IDC_TEST12, m_strtest12);
	DDX_Text(pDX, IDC_TEST13, m_strtest13);
	DDX_Text(pDX, IDC_TEST14, m_strtest14);
	DDX_Text(pDX, IDC_TEST15, m_strtest15);
	DDX_Text(pDX, IDC_TEST16, m_strtest16);
	DDX_Text(pDX, IDC_TEST17, m_strtest17);
	DDX_Text(pDX, IDC_TEST18, m_strtest18);
	DDX_Text(pDX, IDC_TEST19, m_strtest19);
	DDX_Text(pDX, IDC_TEST2, m_strtest2);
	DDX_Text(pDX, IDC_TEST20, m_strtest20);
	DDX_Text(pDX, IDC_TEST21, m_strtest21);
	DDX_Text(pDX, IDC_TEST22, m_strtest22);
	DDX_Text(pDX, IDC_TEST23, m_strtest23);
	DDX_Text(pDX, IDC_TEST24, m_strtest24);
	DDX_Text(pDX, IDC_TEST25, m_strtest25);
	DDX_Text(pDX, IDC_TEST26, m_strtest26);
	DDX_Text(pDX, IDC_TEST27, m_strtest27);
	DDX_Text(pDX, IDC_TEST28, m_strtest28);
	DDX_Text(pDX, IDC_TEST29, m_strtest29);
	DDX_Text(pDX, IDC_TEST3, m_strtest3);
	DDX_Text(pDX, IDC_TEST30, m_strtest30);
	DDX_Text(pDX, IDC_TEST31, m_strtest31);
	DDX_Text(pDX, IDC_TEST32, m_strtest32);
	DDX_Text(pDX, IDC_TEST33, m_strtest33);
	DDX_Text(pDX, IDC_TEST34, m_strtest34);
	DDX_Text(pDX, IDC_TEST35, m_strtest35);
	DDX_Text(pDX, IDC_TEST36, m_strtest36);
	DDX_Text(pDX, IDC_TEST37, m_strtest37);
	DDX_Text(pDX, IDC_TEST38, m_strtest38);
	DDX_Text(pDX, IDC_TEST39, m_strtest39);
	DDX_Text(pDX, IDC_TEST4, m_strtest4);
	DDX_Text(pDX, IDC_TEST40, m_strtest40);
	DDX_Text(pDX, IDC_TEST5, m_strtest5);
	DDX_Text(pDX, IDC_TEST6, m_strtest6);
	DDX_Text(pDX, IDC_TEST7, m_strtest7);
	DDX_Text(pDX, IDC_TEST8, m_strtest8);
	DDX_Text(pDX, IDC_TEST9, m_strtest9);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DIALOGCARRAYTEST, CDialog)
	//{{AFX_MSG_MAP(DIALOGCARRAYTEST)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DIALOGCARRAYTEST message handlers

void DIALOGCARRAYTEST::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if ((m_strtest1.Left(1)=="F")||(m_strtest1.Left(1)=="f"))
	{
		m_strtest1.Delete(0,1);
	}
	m_byteaCFCT[0]=atoi(m_strtest1);

	if ((m_strtest2.Left(1)=="F")||(m_strtest2.Left(1)=="f"))
	{
		m_strtest2.Delete(0,1);
	}
	m_byteaCFCT[1]=atoi(m_strtest2);

	if ((m_strtest3.Left(1)=="F")||(m_strtest3.Left(1)=="f"))
	{
		m_strtest3.Delete(0,1);
	}
	m_byteaCFCT[2]=atoi(m_strtest3);

	if ((m_strtest4.Left(1)=="F")||(m_strtest4.Left(1)=="f"))
	{
		m_strtest4.Delete(0,1);
	}
	m_byteaCFCT[3]=atoi(m_strtest4);

	if ((m_strtest5.Left(1)=="F")||(m_strtest5.Left(1)=="f"))
	{
		m_strtest5.Delete(0,1);
	}
	m_byteaCFCT[4]=atoi(m_strtest5);

	if ((m_strtest6.Left(1)=="F")||(m_strtest6.Left(1)=="f"))
	{
		m_strtest6.Delete(0,1);
	}
	m_byteaCFCT[5]=atoi(m_strtest6);

	if ((m_strtest7.Left(1)=="F")||(m_strtest7.Left(1)=="f"))
	{
		m_strtest7.Delete(0,1);
	}
	m_byteaCFCT[6]=atoi(m_strtest7);

	if ((m_strtest8.Left(1)=="F")||(m_strtest8.Left(1)=="f"))
	{
		m_strtest8.Delete(0,1);
	}
	m_byteaCFCT[7]=atoi(m_strtest8);

	if ((m_strtest9.Left(1)=="F")||(m_strtest9.Left(1)=="f"))
	{
		m_strtest9.Delete(0,1);
	}
	m_byteaCFCT[8]=atoi(m_strtest9);

	if ((m_strtest10.Left(1)=="F")||(m_strtest10.Left(1)=="f"))
	{
		m_strtest10.Delete(0,1);
	}
	m_byteaCFCT[9]=atoi(m_strtest10);

	if ((m_strtest11.Left(1)=="F")||(m_strtest11.Left(1)=="f"))
	{
		m_strtest11.Delete(0,1);
	}
	m_byteaCFCT[10]=atoi(m_strtest11);

	if ((m_strtest12.Left(1)=="F")||(m_strtest12.Left(1)=="f"))
	{
		m_strtest12.Delete(0,1);
	}
	m_byteaCFCT[11]=atoi(m_strtest12);

	if ((m_strtest13.Left(1)=="F")||(m_strtest13.Left(1)=="f"))
	{
		m_strtest13.Delete(0,1);
	}
	m_byteaCFCT[12]=atoi(m_strtest13);

	if ((m_strtest14.Left(1)=="F")||(m_strtest14.Left(1)=="f"))
	{
		m_strtest14.Delete(0,1);
	}
	m_byteaCFCT[13]=atoi(m_strtest14);

	if ((m_strtest15.Left(1)=="F")||(m_strtest15.Left(1)=="f"))
	{
		m_strtest15.Delete(0,1);
	}
	m_byteaCFCT[14]=atoi(m_strtest15);

	if ((m_strtest16.Left(1)=="F")||(m_strtest16.Left(1)=="f"))
	{
		m_strtest16.Delete(0,1);
	}
	m_byteaCFCT[15]=atoi(m_strtest16);

	if ((m_strtest17.Left(1)=="F")||(m_strtest17.Left(1)=="f"))
	{
		m_strtest17.Delete(0,1);
	}
	m_byteaCFCT[16]=atoi(m_strtest17);

	if ((m_strtest18.Left(1)=="F")||(m_strtest18.Left(1)=="f"))
	{
		m_strtest18.Delete(0,1);
	}
	m_byteaCFCT[17]=atoi(m_strtest18);

	if ((m_strtest19.Left(1)=="F")||(m_strtest19.Left(1)=="f"))
	{
		m_strtest19.Delete(0,1);
	}
	m_byteaCFCT[18]=atoi(m_strtest19);

	if ((m_strtest20.Left(1)=="F")||(m_strtest20.Left(1)=="f"))
	{
		m_strtest20.Delete(0,1);
	}
	m_byteaCFCT[19]=atoi(m_strtest20);

	if ((m_strtest21.Left(1)=="F")||(m_strtest21.Left(1)=="f"))
	{
		m_strtest21.Delete(0,1);
	}
	m_byteaCFCT[20]=atoi(m_strtest21);

	if ((m_strtest22.Left(1)=="F")||(m_strtest22.Left(1)=="f"))
	{
		m_strtest22.Delete(0,1);
	}
	m_byteaCFCT[21]=atoi(m_strtest22);

	if ((m_strtest23.Left(1)=="F")||(m_strtest23.Left(1)=="f"))
	{
		m_strtest23.Delete(0,1);
	}
	m_byteaCFCT[22]=atoi(m_strtest23);

	if ((m_strtest24.Left(1)=="F")||(m_strtest24.Left(1)=="f"))
	{
		m_strtest24.Delete(0,1);
	}
	m_byteaCFCT[23]=atoi(m_strtest24);

	if ((m_strtest25.Left(1)=="F")||(m_strtest25.Left(1)=="f"))
	{
		m_strtest25.Delete(0,1);
	}
	m_byteaCFCT[24]=atoi(m_strtest25);

	if ((m_strtest26.Left(1)=="F")||(m_strtest26.Left(1)=="f"))
	{
		m_strtest26.Delete(0,1);
	}
	m_byteaCFCT[25]=atoi(m_strtest26);

	if ((m_strtest27.Left(1)=="F")||(m_strtest27.Left(1)=="f"))
	{
		m_strtest27.Delete(0,1);
	}
	m_byteaCFCT[26]=atoi(m_strtest27);

	if ((m_strtest28.Left(1)=="F")||(m_strtest28.Left(1)=="f"))
	{
		m_strtest28.Delete(0,1);
	}
	m_byteaCFCT[27]=atoi(m_strtest28);

	if ((m_strtest29.Left(1)=="F")||(m_strtest29.Left(1)=="f"))
	{
		m_strtest29.Delete(0,1);
	}
	m_byteaCFCT[28]=atoi(m_strtest29);

	if ((m_strtest30.Left(1)=="F")||(m_strtest30.Left(1)=="f"))
	{
		m_strtest30.Delete(0,1);
	}
	m_byteaCFCT[29]=atoi(m_strtest30);

	if ((m_strtest31.Left(1)=="F")||(m_strtest13.Left(1)=="f"))
	{
		m_strtest31.Delete(0,1);
	}
	m_byteaCFCT[30]=atoi(m_strtest31);

	if ((m_strtest32.Left(1)=="F")||(m_strtest32.Left(1)=="f"))
	{
		m_strtest32.Delete(0,1);
	}
	m_byteaCFCT[31]=atoi(m_strtest32);

	if ((m_strtest33.Left(1)=="F")||(m_strtest33.Left(1)=="f"))
	{
		m_strtest33.Delete(0,1);
	}
	m_byteaCFCT[32]=atoi(m_strtest33);

	if ((m_strtest34.Left(1)=="F")||(m_strtest34.Left(1)=="f"))
	{
		m_strtest34.Delete(0,1);
	}
	m_byteaCFCT[33]=atoi(m_strtest34);
	if ((m_strtest35.Left(1)=="F")||(m_strtest35.Left(1)=="f"))
	{
		m_strtest35.Delete(0,1);
	}
	m_byteaCFCT[34]=atoi(m_strtest35);
	if ((m_strtest36.Left(1)=="F")||(m_strtest36.Left(1)=="f"))
	{
		m_strtest36.Delete(0,1);
	}
	m_byteaCFCT[35]=atoi(m_strtest36);
	if ((m_strtest37.Left(1)=="F")||(m_strtest37.Left(1)=="f"))
	{
		m_strtest37.Delete(0,1);
	}
	m_byteaCFCT[36]=atoi(m_strtest37);
	if ((m_strtest38.Left(1)=="F")||(m_strtest38.Left(1)=="f"))
	{
		m_strtest38.Delete(0,1);
	}
	m_byteaCFCT[37]=atoi(m_strtest38);
	if ((m_strtest39.Left(1)=="F")||(m_strtest39.Left(1)=="f"))
	{
		m_strtest39.Delete(0,1);
	}
	m_byteaCFCT[38]=atoi(m_strtest39);
	if ((m_strtest40.Left(1)=="F")||(m_strtest40.Left(1)=="f"))
	{
		m_strtest40.Delete(0,1);
	}
	m_byteaCFCT[39]=atoi(m_strtest40);

	UpDataShow();


	CDialog::OnOK();
}

BOOL DIALOGCARRAYTEST::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//初始化对话框时，将数据赋值后显示
	
	m_strtest1.Format("F%d",m_byteaCFCT[0]);
	m_strtest2.Format("F%d",m_byteaCFCT[1]);
	m_strtest3.Format("F%d",m_byteaCFCT[2]);
	m_strtest4.Format("F%d",m_byteaCFCT[3]);
	m_strtest5.Format("F%d",m_byteaCFCT[4]);
	m_strtest6.Format("F%d",m_byteaCFCT[5]);
	m_strtest7.Format("F%d",m_byteaCFCT[6]);
	m_strtest8.Format("F%d",m_byteaCFCT[7]);
	m_strtest9.Format("F%d",m_byteaCFCT[8]);
	m_strtest10.Format("F%d",m_byteaCFCT[9]);
	m_strtest11.Format("F%d",m_byteaCFCT[10]);
	m_strtest12.Format("F%d",m_byteaCFCT[11]);
	m_strtest13.Format("F%d",m_byteaCFCT[12]);
	m_strtest14.Format("F%d",m_byteaCFCT[13]);
	m_strtest15.Format("F%d",m_byteaCFCT[14]);
	m_strtest16.Format("F%d",m_byteaCFCT[15]);
	m_strtest17.Format("F%d",m_byteaCFCT[16]);
	m_strtest18.Format("F%d",m_byteaCFCT[17]);
	m_strtest19.Format("F%d",m_byteaCFCT[18]);
	m_strtest20.Format("F%d",m_byteaCFCT[19]);
	m_strtest21.Format("F%d",m_byteaCFCT[20]);
	m_strtest22.Format("F%d",m_byteaCFCT[21]);
	m_strtest23.Format("F%d",m_byteaCFCT[22]);
	m_strtest24.Format("F%d",m_byteaCFCT[23]);
	m_strtest25.Format("F%d",m_byteaCFCT[24]);
	m_strtest26.Format("F%d",m_byteaCFCT[25]);
	m_strtest27.Format("F%d",m_byteaCFCT[26]);
	m_strtest28.Format("F%d",m_byteaCFCT[27]);
	m_strtest29.Format("F%d",m_byteaCFCT[28]);
	m_strtest30.Format("F%d",m_byteaCFCT[29]);
	m_strtest31.Format("F%d",m_byteaCFCT[30]);
	m_strtest32.Format("F%d",m_byteaCFCT[31]);
	m_strtest33.Format("F%d",m_byteaCFCT[32]);
	m_strtest34.Format("F%d",m_byteaCFCT[33]);
	m_strtest35.Format("F%d",m_byteaCFCT[34]);
	m_strtest36.Format("F%d",m_byteaCFCT[35]);
	m_strtest37.Format("F%d",m_byteaCFCT[36]);
	m_strtest38.Format("F%d",m_byteaCFCT[37]);
	m_strtest39.Format("F%d",m_byteaCFCT[38]);
	m_strtest40.Format("F%d",m_byteaCFCT[39]);
	
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DIALOGCARRAYTEST::UpDataShow()
{
	CString m_str;
	CString m_strtoshow;
	for (int i=0;i<40;i++)
	{
		m_str.Format("%d",m_byteaCFCT[i]);
		m_str.Insert(0,"F");
		m_str+=" ";
		m_strtoshow+=m_str;
		if ((i+1)%5==0)
		{
			m_promptinfoCFCT.SetCString((i+1)/5,m_strtoshow);
			m_strtoshow="";
		}
	}
}
