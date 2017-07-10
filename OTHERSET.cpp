// OTHERSET.cpp : implementation file
//

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "OTHERSET.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COTHERSET dialog
extern BYTE	m_byteWriteStatus[];
extern BYTE	m_byteWriteCaputCauda[];
extern BOOL m_bSendStatus;
extern BOOL m_bSendHD;
extern CSHOWMSG	m_showmsg;	
extern int	m_nGapOffSet;				//码间隙偏移量
COTHERSET::COTHERSET(CWnd* pParent /*=NULL*/)
	: CDialog(COTHERSET::IDD, pParent)
{
	//{{AFX_DATA_INIT(COTHERSET)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void COTHERSET::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COTHERSET)
	DDX_Control(pDX, IDC_CODEFRU, m_ccodefru);
	DDX_Control(pDX, IDC_CARRAYFRU, m_ccarryfru);
	DDX_Control(pDX, IDC_CHECKONTIME, m_ccheckontime);
	DDX_Control(pDX, IDC_BSENDTRACKCODE, m_checkontime);
	DDX_Control(pDX, IDC_CHECKKEEPSEND, m_checkkeepsend);
	DDX_Control(pDX, IDC_GAPTIME, m_editgaptime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COTHERSET, CDialog)
	//{{AFX_MSG_MAP(COTHERSET)
	ON_BN_CLICKED(IDC_BSENDTRACKCODE, OnBsendtrackcode)
	ON_BN_CLICKED(IDC_CHECKKEEPSEND, OnCheckkeepsend)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECKONTIME, OnCheckontime)
	ON_BN_CLICKED(IDC_BUTTONSENDONTIME, OnButtonsendontime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COTHERSET message handlers

BOOL COTHERSET::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_bontime=FALSE;
	m_ccarryfru.InsertString(0,"F1:4080");
	m_ccarryfru.InsertString(1,"F2:4320");
	m_ccarryfru.InsertString(2,"F3:4560");
	m_ccarryfru.InsertString(3,"F4:4800");
	m_ccarryfru.InsertString(4,"F5:5040");
	m_ccarryfru.InsertString(5,"F6:5280");
	m_ccarryfru.InsertString(6,"F7:5520");
	m_ccarryfru.InsertString(7,"F9:6000");
	m_ccarryfru.InsertString(8,"FX:8000");
	m_ccarryfru.InsertString(8,"F10:无码");
	m_ccarryfru.SetCurSel(0);
	m_ccodefru.InsertString(0,"M1:28:74/73");
	m_ccodefru.InsertString(1,"M2:32:74/58");
	m_ccodefru.InsertString(2,"M3:36:59/58");
	m_ccodefru.InsertString(3,"M4:40:59/37");
	m_ccodefru.InsertString(4,"M5:44:38/37");
	m_ccodefru.InsertString(5,"M6:48:38/27");
	m_ccodefru.InsertString(6,"M7:52:NONE");
	m_ccodefru.InsertString(7,"M8:56:38/0");
	m_ccodefru.InsertString(8,"M9:60:28/27");
	m_ccodefru.InsertString(9,"M10:64:28/19");
	m_ccodefru.InsertString(10,"M11:68:28/0");
	m_ccodefru.InsertString(11,"M12:72:NONE");
	m_ccodefru.InsertString(12,"M13:76:20/0");
	m_ccodefru.InsertString(13,"M14:80:0/0");
	m_ccodefru.InsertString(14,"M15:100");
	m_ccodefru.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COTHERSET::OnBsendtrackcode() 
{
	// TODO: Add your control notification handler code here
	//发送码间隙，自动取消即时模式
	CString m_strgaptime;
	BYTE	m_bytegaptime;
	CString m_strtoshow;
	if (m_ccheckontime.GetCheck())
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xbf;
		m_byteWriteCaputCauda[0x14]=NOONTIME;
		m_bontime=FALSE;
		m_strtoshow="取消即时模式";
		m_bSendHD=TRUE;
		m_strtoshow.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_strtoshow);
		m_ccheckontime.SetCheck(FALSE);
	} 

	m_editgaptime.GetWindowText(m_strgaptime);
	if (m_strgaptime!="")
	{
		m_bytegaptime=atoi(m_strgaptime);
		m_byteWriteStatus[0x11]=m_bytegaptime-m_nGapOffSet;
		m_byteWriteStatus[0x14]=CODEGAP;
		m_bSendStatus=TRUE;
		m_strtoshow="发送码间隙";
		m_strtoshow.Insert(0,"(人工)");
		m_showmsg.AddMsg(m_strtoshow);
	}
	else
	{
		m_showmsg.AddMsg("码间隙时间为空!");
	}
}

void COTHERSET::OnCheckkeepsend() 
{
	// TODO: Add your control notification handler code here
	if (m_checkkeepsend.GetCheck())
	{
		SetTimer(1,100,NULL);
	} 
	else
	{
		KillTimer(1);
	}

}

void COTHERSET::OnButtonstoppos() 
{
	// TODO: Add your control notification handler code here
	
}

void COTHERSET::OnButtonsetspeed() 
{
	// TODO: Add your control notification handler code here
	
}

void COTHERSET::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent)
	{
	case 1:
		{
			SendGapTime();
			break;
		}
	}
	CDialog::OnTimer(nIDEvent);
}

void COTHERSET::SendGapTime()
{
	CString m_strtoshow;
	m_byteWriteStatus[0x11]=0xc8;
	m_byteWriteStatus[0x14]=CODEGAP;
	m_bSendStatus=TRUE;
	m_strtoshow="发送码间隙";
	m_strtoshow.Insert(0,"(定时)");
	m_showmsg.AddMsg(m_strtoshow);
}

void COTHERSET::OnCheckontime() 
{
	// TODO: Add your control notification handler code here
	CString m_strtoshow;
	if (m_ccheckontime.GetCheck())
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]^0x40;
		m_byteWriteCaputCauda[0x14]=ONTIME;
		m_bontime=TRUE;
		m_strtoshow="设置即时模式";
	} 
	else
	{
		m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xbf;
		m_byteWriteCaputCauda[0x14]=NOONTIME;
		m_bontime=FALSE;
		m_strtoshow="取消即时模式";
	}
	m_bSendHD=TRUE;
	m_strtoshow.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_strtoshow);
}

void COTHERSET::OnButtonsendontime() 
{
	// TODO: Add your control notification handler code here
	/*
	载波频率编码表：
	载频（Hz）	4080	4320	4560	4800	5040	5280	5520	6000  无码
	发送编号(16进制)	1	2	3	4	5	6	7	8	0x0a
	调制频率编码表：
	码频（Hz）	28	32	36	40	44	48	52	56	60	64	68	72	76	80
	发送编号(16进制)	1	2	3	4	5	6	7	8	9	A	B	C	D	E
	*/
	int m_ncarryfru=0;
	int m_ncodefru=0;
	CString m_strtoshow;
	m_ncarryfru=m_ccarryfru.GetCurSel();
	m_ncodefru=m_ccodefru.GetCurSel();
	m_byteWriteStatus[0x0b]=0;
	
	switch (m_ncarryfru)
	{
	case 0:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x10;
		break;
	case 1:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x20;
		break;
	case 2:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x30;
		break;
	case 3:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x40;
		break;
	case 4:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x50;
		break;
	case 5:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x60;
		break;
	case 6:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x70;
		break;
	case 7:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x80;
		break;
	case 8:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0xA0;
		break;
	}
	
	switch (m_ncodefru)
	{
				case 0:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x01;
					break;
				case 1:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x02;
					break;
				case 2:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x03;
					break;
				case 3:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x04;
					break;
				case 4:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x05;
					break;
				case 5:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x06;
					break;
				case 6:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x07;
					break;
				case 7:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x08;
					break;
				case 8:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x09;
					break;
				case 9:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x0a;
					break;
				case 10:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x0b;
					break;
				case 11:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x0c;
					break;
				case 12:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x0d;
					break;
				case 13:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x0e;
					break;
	}
	m_byteWriteStatus[0x14]=ONTIMECC;
	m_bSendStatus=TRUE;
	m_strtoshow="即时码";
	m_strtoshow.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_strtoshow);
}
