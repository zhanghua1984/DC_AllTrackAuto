// SETHD.cpp : implementation file
//

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "SETHD.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CSHOWMSG	m_showmsg;
extern BYTE	m_byteWriteCaputCauda[];
extern BOOL	m_bSendHD;
/////////////////////////////////////////////////////////////////////////////
// CSETHD dialog


CSETHD::CSETHD(CWnd* pParent /*=NULL*/)
	: CDialog(CSETHD::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSETHD)
	//}}AFX_DATA_INIT
}


void CSETHD::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSETHD)
	DDX_Control(pDX, IDC_CHECKDOPULFNONE, m_ccheckdopulnone);
	DDX_Control(pDX, IDC_CHECKDOPULFFAULT, m_ccheckdopulfault);
	DDX_Control(pDX, IDC_CHECKDOPULDATA, m_ccheckdopuldata);
	DDX_Control(pDX, IDC_CHECKREADERERR, m_ccheckreadererr);
	DDX_Control(pDX, IDC_CHECKTECHOP2, m_cchecktechop2);
	DDX_Control(pDX, IDC_CHECKTECHOP1, m_cchecktechop1);
	DDX_Control(pDX, IDC_CHECKTECH2, m_cchecktech2);
	DDX_Control(pDX, IDC_CHECKTECH1, m_cchecktech1);
	DDX_Control(pDX, IDC_CHECKRELAY9, m_ccheckr9);
	DDX_Control(pDX, IDC_CHECKRELAY8, m_ccheckr8);
	DDX_Control(pDX, IDC_CHECKRELAY7, m_ccheckr7);
	DDX_Control(pDX, IDC_CHECKRELAY6, m_ccheckr6);
	DDX_Control(pDX, IDC_CHECKRELAY5, m_ccheckr5);
	DDX_Control(pDX, IDC_CHECKRELAY4, m_ccheckr4);
	DDX_Control(pDX, IDC_CHECKRELAY3, m_ccheckr3);
	DDX_Control(pDX, IDC_CHECKRELAY2, m_ccheckr2);
	DDX_Control(pDX, IDC_CHECKRELAY16, m_ccheckr16);
	DDX_Control(pDX, IDC_CHECKRELAY15, m_ccheckr15);
	DDX_Control(pDX, IDC_CHECKRELAY14, m_ccheckr14);
	DDX_Control(pDX, IDC_CHECKRELAY13, m_ccheckr13);
	DDX_Control(pDX, IDC_CHECKRELAY12, m_ccheckr12);
	DDX_Control(pDX, IDC_CHECKRELAY11, m_ccheckr11);
	DDX_Control(pDX, IDC_CHECKRELAY10, m_ccheckr10);
	DDX_Control(pDX, IDC_CHECKRELAY1, m_ccheckr1);
	DDX_Control(pDX, IDC_CHECKFSKMOD, m_ccheckfskmod);
	DDX_Control(pDX, IDC_CHECKFSK2, m_ccheckfsk2);
	DDX_Control(pDX, IDC_CHECKFSK1, m_ccheckfsk1);
	DDX_Control(pDX, IDC_CHECKATP2, m_ccheckatp2);
	DDX_Control(pDX, IDC_CHECKATO, m_ccheckato);
	DDX_Control(pDX, IDC_CHECKATP1, m_ccheckatp1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSETHD, CDialog)
	//{{AFX_MSG_MAP(CSETHD)
	ON_BN_CLICKED(IDC_CHECKATO, OnCheckato)
	ON_BN_CLICKED(IDC_CHECKATP1, OnCheckatp1)
	ON_BN_CLICKED(IDC_CHECKATP2, OnCheckatp2)
	ON_BN_CLICKED(IDC_CHECKTECHOP1, OnChecktechop1)
	ON_BN_CLICKED(IDC_CHECKTECHOP2, OnChecktechop2)
	ON_BN_CLICKED(IDC_CHECKTECH1, OnChecktech1)
	ON_BN_CLICKED(IDC_CHECKTECH2, OnChecktech2)
	ON_BN_CLICKED(IDC_CHECKFSK1, OnCheckfsk1)
	ON_BN_CLICKED(IDC_CHECKFSK2, OnCheckfsk2)
	ON_BN_CLICKED(IDC_CHECKFSKMOD, OnCheckfskmod)
	ON_BN_CLICKED(IDC_CHECKRELAY1, OnCheckrelay1)
	ON_BN_CLICKED(IDC_CHECKRELAY2, OnCheckrelay2)
	ON_BN_CLICKED(IDC_CHECKRELAY3, OnCheckrelay3)
	ON_BN_CLICKED(IDC_CHECKRELAY4, OnCheckrelay4)
	ON_BN_CLICKED(IDC_CHECKRELAY5, OnCheckrelay5)
	ON_BN_CLICKED(IDC_CHECKRELAY6, OnCheckrelay6)
	ON_BN_CLICKED(IDC_CHECKRELAY7, OnCheckrelay7)
	ON_BN_CLICKED(IDC_CHECKRELAY8, OnCheckrelay8)
	ON_BN_CLICKED(IDC_CHECKRELAY9, OnCheckrelay9)
	ON_BN_CLICKED(IDC_CHECKRELAY10, OnCheckrelay10)
	ON_BN_CLICKED(IDC_CHECKRELAY11, OnCheckrelay11)
	ON_BN_CLICKED(IDC_CHECKRELAY12, OnCheckrelay12)
	ON_BN_CLICKED(IDC_CHECKRELAY13, OnCheckrelay13)
	ON_BN_CLICKED(IDC_CHECKRELAY14, OnCheckrelay14)
	ON_BN_CLICKED(IDC_CHECKRELAY15, OnCheckrelay15)
	ON_BN_CLICKED(IDC_CHECKRELAY16, OnCheckrelay16)
	ON_BN_CLICKED(IDC_CHECKREADERERR, OnCheckreadererr)
	ON_BN_CLICKED(IDC_CHECKDOPULDATA, OnCheckdopuldata)
	ON_BN_CLICKED(IDC_CHECKDOPULFNONE, OnCheckdopulfnone)
	ON_BN_CLICKED(IDC_CHECKDOPULFFAULT, OnCheckdopulffault)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSETHD message handlers

BOOL CSETHD::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//读取变量状态
	ReadShow();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSETHD::OnCheckato() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckato.GetCheck())
	{
		m_byteWriteCaputCauda[0x06]=m_byteWriteCaputCauda[0x06]&0xFB;
		m_byteWriteCaputCauda[0x06]=m_byteWriteCaputCauda[0x06]|0x04;
		CString m_str="ATO:故障";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=ATO_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x06]=m_byteWriteCaputCauda[0x06]&0xFB;
		CString m_str="ATO:正常";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=ATO_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
	
}

void CSETHD::OnCheckatp1() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckatp1.GetCheck())
	{
		m_byteWriteCaputCauda[0x06]=m_byteWriteCaputCauda[0x06]&0xFE;
		m_byteWriteCaputCauda[0x06]=m_byteWriteCaputCauda[0x06]|0x01;
		CString m_str="ATP1:故障";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=ATP1_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x06]=m_byteWriteCaputCauda[0x06]&0xFE;
		CString m_str="ATP1:正常";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=ATP1_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckatp2() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckatp2.GetCheck())
	{
		m_byteWriteCaputCauda[0x06]=m_byteWriteCaputCauda[0x06]&0xFD;
		m_byteWriteCaputCauda[0x06]=m_byteWriteCaputCauda[0x06]|0x02;
		CString m_str="ATP2:故障";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=ATP2_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x06]=m_byteWriteCaputCauda[0x06]&0xFD;
		CString m_str="ATP2:正常";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=ATP1_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnChecktechop1() 
{
	// TODO: Add your control notification handler code here
	if (m_cchecktechop1.GetCheck())
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xFE;
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]|0x01;
		CString m_str="测速电机1:故障";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=TECHOP1_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xFE;
		CString m_str="测速电机1:正常";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=TECHOP1_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnChecktechop2() 
{
	// TODO: Add your control notification handler code here
	if (m_cchecktechop2.GetCheck())
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xFD;
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]|0x02;
		CString m_str="测速电机2:故障";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=TECHOP2_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xFD;
		CString m_str="测速电机2:故障";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=TECHOP2_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnChecktech1() 
{
	// TODO: Add your control notification handler code here
	if (m_cchecktech1.GetCheck())
	{
		/*
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xFB;
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]|0x04;
		*/
		CString m_str="测速电机1:故障速度标志";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=TECH1_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xFB;
		CString m_str="测速电机1:正常速度标志";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=TECH1_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnChecktech2() 
{
	// TODO: Add your control notification handler code here
	if (m_cchecktech2.GetCheck())
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xF7;
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]|0x08;
		CString m_str="测速电机2:故障速度标志";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=TECH2_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xF7;
		CString m_str="测速电机2:正常速度标志";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=TECH2_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckfsk1() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckfsk1.GetCheck())
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xEF;
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]|0x10;
		CString m_str="FSK1:故障";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=FSK1_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xEF;
		CString m_str="FSK1:正常";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=FSK1_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckfsk2() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckfsk2.GetCheck())
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xDF;
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]|0x20;
		CString m_str="FSK2:故障";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=FSK2_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xDF;
		CString m_str="FSK2:正常";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=FSK2_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckfskmod() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckfskmod.GetCheck())
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xBF;
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]|0x40;
		CString m_str="即时模式:打开";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=FSKMOD_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xBF;
		CString m_str="即时模式:关闭";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=FSKMOD_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay1() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr1.GetCheck())
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0xFE;
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]|0x01;
		CString m_str="继电器1:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R1_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0xFE;
		CString m_str="继电器1:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R1_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay2() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr2.GetCheck())
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0xFD;
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]|0x02;
		CString m_str="继电器2:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R2_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0xFD;
		CString m_str="继电器2:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R2_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay3() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr3.GetCheck())
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0xFB;
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]|0x04;
		CString m_str="继电器3:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R3_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0xFB;
		CString m_str="继电器3:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R3_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay4() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr4.GetCheck())
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0xF7;
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]|0x08;
		CString m_str="继电器4:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R4_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0xF7;
		CString m_str="继电器4:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R4_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay5() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr5.GetCheck())
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0xEF;
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]|0x10;
		CString m_str="继电器5:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R5_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0xEF;
		CString m_str="继电器5:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R5_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay6() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr6.GetCheck())
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0xDF;
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]|0x20;
		CString m_str="继电器6:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R6_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0xDF;
		CString m_str="继电器6:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R6_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay7() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr7.GetCheck())
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0xBF;
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]|0x30;
		CString m_str="继电器7:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R7_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0xBF;
		CString m_str="继电器7:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R7_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay8() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr8.GetCheck())
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0x7F;
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]|0x80;
		CString m_str="继电器8:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R8_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x08]=m_byteWriteCaputCauda[0x08]&0x7F;
		CString m_str="继电器8:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R8_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay9() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr9.GetCheck())
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0xFE;
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]|0x01;
		CString m_str="继电器9:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R9_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0xFE;
		CString m_str="继电器9:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R9_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay10() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr10.GetCheck())
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0xFD;
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]|0x02;
		CString m_str="继电器10:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R10_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0xFD;
		CString m_str="继电器10:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R10_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay11() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr11.GetCheck())
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0xFB;
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]|0x04;
		CString m_str="继电器11:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R11_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0xFB;
		CString m_str="继电器11:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R11_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay12() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr12.GetCheck())
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0xF7;
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]|0x08;
		CString m_str="继电器12:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R12_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0xF7;
		CString m_str="继电器12:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R12_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay13() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr13.GetCheck())
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0xEF;
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]|0x10;
		CString m_str="继电器13:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R13_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0xEF;
		CString m_str="继电器13:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R13_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay14() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr14.GetCheck())
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0xDF;
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]|0x20;
		CString m_str="继电器14:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R14_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0xDF;
		CString m_str="继电器14:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R14_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay15() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr15.GetCheck())
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0xBF;
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]|0x40;
		CString m_str="继电器15:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R15_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0xBF;
		CString m_str="继电器15:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R15_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckrelay16() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckr16.GetCheck())
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0x7F;
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]|0x80;
		CString m_str="继电器16:励磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R16_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x09]=m_byteWriteCaputCauda[0x09]&0x7F;
		CString m_str="继电器16:失磁";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=R16_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::ReadShow()
{
	
	if (m_byteWriteCaputCauda[0x06]&0x04)
	{
		m_ccheckato.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckato.SetCheck(FALSE);
	}
	
	if (m_byteWriteCaputCauda[0x06]&0x02)
	{
		m_ccheckatp1.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckatp1.SetCheck(FALSE);
	}

	if (m_byteWriteCaputCauda[0x06]&0x01)
	{
		m_ccheckatp2.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckatp2.SetCheck(FALSE);
	}


	if (m_byteWriteCaputCauda[0x07]&0x40)
	{
		m_ccheckfskmod.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckfskmod.SetCheck(FALSE);
	}

	if (m_byteWriteCaputCauda[0x07]&0x20)
	{
		m_ccheckfsk2.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckfsk2.SetCheck(FALSE);
	}

	if (m_byteWriteCaputCauda[0x07]&0x10)
	{
		m_ccheckfsk1.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckfsk1.SetCheck(FALSE);
	}

	if (m_byteWriteCaputCauda[0x07]&0x08)
	{
		m_cchecktech2.SetCheck(TRUE);
	} 
	else
	{
		m_cchecktech2.SetCheck(FALSE);
	}
	if (m_byteWriteCaputCauda[0x07]&0x04)
	{
		m_cchecktech1.SetCheck(TRUE);
	} 
	else
	{
		m_cchecktech1.SetCheck(FALSE);
	}
	if (m_byteWriteCaputCauda[0x07]&0x02)
	{
		m_cchecktechop2.SetCheck(TRUE);
	} 
	else
	{
		m_cchecktechop2.SetCheck(FALSE);
	}
	if (m_byteWriteCaputCauda[0x07]&0x01)
	{
		m_cchecktechop1.SetCheck(TRUE);
	} 
	else
	{
		m_cchecktechop1.SetCheck(FALSE);
	}


	if (m_byteWriteCaputCauda[0x08]&0x01)
	{
		m_ccheckr1.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr1.SetCheck(FALSE);
	}
	

	if (m_byteWriteCaputCauda[0x08]&0x02)
	{
		m_ccheckr2.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr2.SetCheck(FALSE);
	}

	if (m_byteWriteCaputCauda[0x08]&0x04)
	{
		m_ccheckr3.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr3.SetCheck(FALSE);
	}
	if (m_byteWriteCaputCauda[0x08]&0x08)
	{
		m_ccheckr4.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr4.SetCheck(FALSE);
	}

	if (m_byteWriteCaputCauda[0x08]&0x10)
	{
		m_ccheckr5.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr5.SetCheck(FALSE);
	}
	if (m_byteWriteCaputCauda[0x08]&0x20)
	{
		m_ccheckr6.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr6.SetCheck(FALSE);
	}
	if (m_byteWriteCaputCauda[0x08]&0x40)
	{
		m_ccheckr7.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr7.SetCheck(FALSE);
	}
	if (m_byteWriteCaputCauda[0x08]&0x80)
	{
		m_ccheckr8.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr8.SetCheck(FALSE);
	}
	if (m_byteWriteCaputCauda[0x09]&0x01)
	{
		m_ccheckr9.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr9.SetCheck(FALSE);
	}
	if (m_byteWriteCaputCauda[0x09]&0x02)
	{
		m_ccheckr10.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr10.SetCheck(FALSE);
	}
	if (m_byteWriteCaputCauda[0x09]&0x04)
	{
		m_ccheckr11.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr11.SetCheck(FALSE);
	}
	if (m_byteWriteCaputCauda[0x09]&0x08)
	{
		m_ccheckr12.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr12.SetCheck(FALSE);
	}
	if (m_byteWriteCaputCauda[0x09]&0x10)
	{
		m_ccheckr13.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr13.SetCheck(FALSE);
	}
	if (m_byteWriteCaputCauda[0x09]&0x20)
	{
		m_ccheckr14.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr14.SetCheck(FALSE);
	}
	if (m_byteWriteCaputCauda[0x09]&0x40)
	{
		m_ccheckr15.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr15.SetCheck(FALSE);
	}
	if (m_byteWriteCaputCauda[0x09]&0x80)
	{
		m_ccheckr16.SetCheck(TRUE);
	} 
	else
	{
		m_ccheckr16.SetCheck(FALSE);
	}
}

void CSETHD::PostMessageToView()
{
	CMainFrame* pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;	//先通过获取当前框架指针 
	CView * active = pMF->GetActiveView();					//才能获取当前视类指针 
	if(active != NULL)										//获取了当前视类指针才能发送消息 
		active->PostMessage(WM_MY_DLGUPDATEVIEW,0,0);		//使用PostMessage发送消息 
}

void CSETHD::OnCheckreadererr() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckreadererr.GetCheck())
	{
		m_byteWriteCaputCauda[0x0A]=m_byteWriteCaputCauda[0x0A]&0xF7;
		m_byteWriteCaputCauda[0x0A]=m_byteWriteCaputCauda[0x0A]|0x08;
		CString m_str="阅读器故障";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=READERERR_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x0A]=m_byteWriteCaputCauda[0x09]&0xF7;
		CString m_str="阅读器正常";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=READERERR_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckdopuldata() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckdopuldata.GetCheck())
	{
		m_byteWriteCaputCauda[0x0A]=m_byteWriteCaputCauda[0x0A]&0xFB;
		m_byteWriteCaputCauda[0x0A]=m_byteWriteCaputCauda[0x0A]|0x04;
		CString m_str="多普勒数据禁发";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=DOPULDATA_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x0A]=m_byteWriteCaputCauda[0x09]&0xFB;
		CString m_str="多普勒数据发送";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=DOPULDATA_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckdopulfnone() 
{
	// TODO: Add your control notification handler code here
	if (m_ccheckdopulnone.GetCheck())
	{
		m_byteWriteCaputCauda[0x0A]=m_byteWriteCaputCauda[0x0A]&0xFD;
		m_byteWriteCaputCauda[0x0A]=m_byteWriteCaputCauda[0x0A]|0x02;
		CString m_str="多普勒禁止";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=DOPULNONE_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x0A]=m_byteWriteCaputCauda[0x09]&0xFD;
		CString m_str="多普勒开启";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=DOPULNONE_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}

void CSETHD::OnCheckdopulffault() 
{
	// TODO: Add your control notification handler code here
		if (m_ccheckdopulfault.GetCheck())
	{
		m_byteWriteCaputCauda[0x0A]=m_byteWriteCaputCauda[0x0A]&0xFE;
		m_byteWriteCaputCauda[0x0A]=m_byteWriteCaputCauda[0x0A]|0x01;
		CString m_str="多普勒故障";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=DOPULFAULT_E;
		m_bSendHD=TRUE;
		PostMessageToView();
	} 
	else
	{
		m_byteWriteCaputCauda[0x0A]=m_byteWriteCaputCauda[0x09]&0xFE;
		CString m_str="多普勒正常";
		m_str.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_str);
		m_byteWriteCaputCauda[0x14]=DOPULFAULT_N;
		m_bSendHD=TRUE;
		PostMessageToView();
	}
}
