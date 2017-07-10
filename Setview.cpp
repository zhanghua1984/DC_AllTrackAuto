// Setview.cpp : implementation file
//

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "Setview.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern m_nTrackView;
/////////////////////////////////////////////////////////////////////////////
// CSetview dialog


CSetview::CSetview(CWnd* pParent /*=NULL*/)
	: CDialog(CSetview::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetview)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSetview::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetview)
	DDX_Control(pDX, IDC_SCROLLBAR1, m_cscrollbar);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetview, CDialog)
	//{{AFX_MSG_MAP(CSetview)
	ON_WM_DESTROY()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetview message handlers

void CSetview::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	delete this;
}

void CSetview::OnSet() 
{
	// TODO: Add your control notification handler code here

}

void CSetview::OnOK() 
{
	// TODO: Add extra validation here
	PostMessageToView();
	CDialog::OnOK();
}

void CSetview::OnCancel() 
{
	// TODO: Add extra cleanup here
	PostMessageToView();
	CDialog::OnCancel();
}

BOOL CSetview::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::PreCreateWindow(cs);
}

BOOL CSetview::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_cscrollbar.SetScrollRange(0,20097,TRUE);
	m_cscrollbar.SetScrollPos(m_nTrackView/4,TRUE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

CScrollBar* CSetview::GetScrollBarCtrl(int nBar) const
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::GetScrollBarCtrl(nBar);
}

void CSetview::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default

	switch(nSBCode)                 //处理滚动信息
	{
		/*
#define SB_LINEUP           0
#define SB_LINELEFT         0
#define SB_LINEDOWN         1
#define SB_LINERIGHT        1
#define SB_PAGEUP           2
#define SB_PAGELEFT         2
#define SB_PAGEDOWN         3
#define SB_PAGERIGHT        3
#define SB_THUMBPOSITION    4
#define SB_THUMBTRACK       5
#define SB_TOP              6
#define SB_LEFT             6
#define SB_BOTTOM           7
#define SB_RIGHT            7
#define SB_ENDSCROLL        8
		*/

	case SB_LINELEFT:					 //向左的箭头被按下
		m_nTrackView-=60;
		break;   
	case SB_LINERIGHT:
		m_nTrackView+=60;
		break;							//向右的箭头被按下
	case SB_PAGEUP:
		m_nTrackView-=200;

		break;							//向右的箭头被按下
	case SB_PAGEDOWN:
		m_nTrackView+=200;
		break;							//向右的箭头被按下

	case SB_THUMBPOSITION:					//鼠标拖动
		m_nTrackView=(int)nPos*4;
		break;

	case SB_THUMBTRACK:					//鼠标拖动
		m_nTrackView=(int)nPos*4;
		break;
	}

	m_cscrollbar.SetScrollPos(m_nTrackView/4,TRUE);

	PostMessageToView();
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CSetview::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CSetview::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	delete this;
	CDialog::PostNcDestroy();
}

void CSetview::OnOutofmemorySpinselectstation(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CSetview::PostMessageToView()
{
	CMainFrame* pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;	//先通过获取当前框架指针 
	CView * active = pMF->GetActiveView();					//才能获取当前视类指针 
	if(active != NULL)										//获取了当前视类指针才能发送消息 
		active->PostMessage(WM_MY_DLGUPDATEVIEW,0,0);		//使用PostMessage发送消息 
}
