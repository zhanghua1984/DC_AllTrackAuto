// RUNNINGMSG.cpp : implementation file
//

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "RUNNINGMSG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRUNNINGMSG dialog


CRUNNINGMSG::CRUNNINGMSG(CWnd* pParent /*=NULL*/)
	: CDialog(CRUNNINGMSG::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRUNNINGMSG)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRUNNINGMSG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRUNNINGMSG)
	DDX_Control(pDX, IDC_LISTSHOWMSGTRACKCODE, m_clisttrackcode);
	DDX_Control(pDX, IDC_LISTSHOWMSGSTATUS, m_cliststatus);
	DDX_Control(pDX, IDC_LISTSHOWMSGPAPR, m_clistpapr);
	DDX_Control(pDX, IDC_LISTSHOWMSGNPAPR, m_clistnpapr);
	DDX_Control(pDX, IDC_LISTSHOWMSGHD, m_clisthd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRUNNINGMSG, CDialog)
	//{{AFX_MSG_MAP(CRUNNINGMSG)
	ON_BN_CLICKED(IDC_BSTATUSCLEAR, OnBstatusclear)
	ON_BN_CLICKED(IDC_BHDCLEAR, OnBhdclear)
	ON_BN_CLICKED(IDC_BTCODECLEAR3, OnBtcodeclear3)
	ON_BN_CLICKED(IDC_BNPAPRCLEAR, OnBnpaprclear)
	ON_BN_CLICKED(IDC_BPAPRCLEAR, OnBpaprclear)
	ON_BN_CLICKED(IDC_BCLEARALL, OnBclearall)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRUNNINGMSG message handlers

BOOL CRUNNINGMSG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRUNNINGMSG::OnBstatusclear() 
{
	// TODO: Add your control notification handler code here
	int m_ncounter=0;
	m_ncounter=m_cliststatus.GetCount();
	for (int i=0;i<m_ncounter;i++)
	{
		m_cliststatus.DeleteString(i);
	}
}

void CRUNNINGMSG::OnBhdclear() 
{
	// TODO: Add your control notification handler code here
	int m_ncounter=0;
	m_ncounter=m_clisthd.GetCount();
	for (int i=0;i<m_ncounter;i++)
	{
		m_clisthd.DeleteString(i);
	}
}

void CRUNNINGMSG::OnBtcodeclear3() 
{
	// TODO: Add your control notification handler code here
	int m_ncounter=0;
	m_ncounter=m_clisttrackcode.GetCount();
	for (int i=0;i<m_ncounter;i++)
	{
		m_clisttrackcode.DeleteString(i);
	}
}

void CRUNNINGMSG::OnBnpaprclear() 
{
	// TODO: Add your control notification handler code here
	int m_ncounter=0;
	m_ncounter=m_clistnpapr.GetCount();
	for (int i=0;i<m_ncounter;i++)
	{
		m_clistnpapr.DeleteString(i);
	}
}

void CRUNNINGMSG::OnBpaprclear() 
{
	// TODO: Add your control notification handler code here
	
	int m_ncounter=0;
	m_ncounter=m_clistpapr.GetCount();
	for (int i=0;i<m_ncounter;i++)
	{
		m_clistpapr.DeleteString(i);
	}
}

void CRUNNINGMSG::OnBclearall() 
{
	// TODO: Add your control notification handler code here
	int m_ncounter=0;
	int i=0;
	m_ncounter=m_cliststatus.GetCount();
	for (i=0;i<m_ncounter;i++)
	{
		m_cliststatus.DeleteString(i);
	}

	m_ncounter=m_clisttrackcode.GetCount();
	for (i=0;i<m_ncounter;i++)
	{
		m_clisttrackcode.DeleteString(i);
	}

	m_ncounter=m_clistpapr.GetCount();
	for (i=0;i<m_ncounter;i++)
	{
		m_clistpapr.DeleteString(i);
	}
	
	m_ncounter=m_clistnpapr.GetCount();
	for (i=0;i<m_ncounter;i++)
	{
		m_clistnpapr.DeleteString(i);
	}

	m_ncounter=m_clisthd.GetCount();
	for (i=0;i<m_ncounter;i++)
	{
		m_clisthd.DeleteString(i);
	}
}
