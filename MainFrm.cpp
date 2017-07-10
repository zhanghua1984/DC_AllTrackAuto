// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern BYTE m_byteCom[];
extern BYTE	m_byteWriteStatus[];
extern BYTE	m_byteWriteTrackCode[];
extern BYTE	m_byteWriteCaputCauda[];
extern BYTE	m_byteWritePAPR70[];
extern BYTE	m_byteWritePAPR10[];
extern BYTE	m_byteWriteNPAPR80[];
extern BYTE	m_byteWriteNPAPR20[];
extern BOOL m_bViewOn;
extern CRUNNINGMSG * m_dlgmsg;
extern CWinThread* pThreadWriter;
extern CWinThread* pThreadRead;
extern CWinThread* pThreadRX;
extern CWinThread* pThreadTX;
extern BOOL	m_bThreadRXrunning;
extern BOOL	m_bThreadTXrunning;

extern	CSHOWMSG m_showmsg;
extern BOOL m_bSendStatus;
BOOL	m_bEndThread;
extern BOOL m_bSendDebug;
extern double m_dgspeed;
extern COLORREF	m_colorgline;
extern COLORREF	m_colorgfont;
extern COLORREF	m_colorgapr;
extern BOOL		m_bCarrayFruChangeTest;
extern BYTE		m_byteaCFCT[];
extern BYTE		m_bytepCFCT;
extern PROMPTINFO	m_promptinfoCFCT;
extern BOOL		m_bshowhandle;
extern BOOL		m_bshowauto;
extern BOOL		m_bshowreturn1;
extern BOOL		m_bshowreturn2;
extern BOOL		m_bshowreturn3;
extern BOOL		m_bshowdebug;
extern BOOL		m_bshowcalculate;
extern PROMPTINFO	m_promptinfoshow;
extern PROMPTINFO	m_promptinfoMailandV;
extern float	m_fgtrainclasp;
extern BOOL		m_bdisablefsb;
extern BOOL		m_bdisableeb;
extern BOOL		m_bEBvalid;
extern BOOL		m_bDirectorup;		//车辆是否下行
extern int		m_ngTrainhigh;		//全局车辆高度
extern int		m_ngTrainpos;		//全局车辆位置
extern CTrain		m_Train;
extern POINT m_pTrainpos;
extern BOOL		m_bDisableNone;		//屏蔽自动空挡
extern BOOL		m_bgoahead;					//行车方向
extern BOOL		m_bhead1;					//1号车是否为头车
extern BOOL		m_bSendAPR;
extern CALLTRACKAUTOSet m_uptrack[TRACKUP];	//上行轨道
extern CALLTRACKAUTOSet m_downtrack[TRACKDOWN];	//下行轨道
extern PROMPTINFO	m_promptinfoStatus;			//状态信息
int		m_nGT;	//全局车辆档位+
extern BOOL m_bForbidSendPAPR;
/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_MENUSETVIEW, OnMenusetview)
	ON_COMMAND(ID_MENUEB, OnMenueb)
	ON_COMMAND(ID_MENUB1, OnMenub1)
	ON_COMMAND(ID_MENUB2, OnMenub2)
	ON_COMMAND(ID_MENUB3, OnMenub3)
	ON_COMMAND(ID_MENUB4, OnMenub4)
	ON_COMMAND(ID_MENUB5, OnMenub5)
	ON_COMMAND(ID_MENUB6, OnMenub6)
	ON_COMMAND(ID_MENUB7, OnMenub7)
	ON_COMMAND(ID_MENUD1, OnMenud1)
	ON_COMMAND(ID_MENUD2, OnMenud2)
	ON_COMMAND(ID_MENUD3, OnMenud3)
	ON_COMMAND(ID_MENUD4, OnMenud4)
	ON_COMMAND(ID_MENUNONE, OnMenunone)
	ON_COMMAND(ID_MENUDIRFORWARD, OnMenudirforward)
	ON_COMMAND(ID_MENUDIR0, OnMenudir0)
	ON_COMMAND(ID_MENUDIRBACK, OnMenudirback)
	ON_COMMAND(ID_MENUHEAD, OnMenuhead)
	ON_COMMAND(ID_MENUTRAIL, OnMenutrail)
	ON_COMMAND(ID_MENUPC, OnMenupc)
	ON_COMMAND(ID_MENUDC, OnMenudc)
	ON_COMMAND(ID_MENUVIEWONTRAIN, OnMenuviewontrain)
	ON_COMMAND(ID_MENUVIEWONTRACK, OnMenuviewontrack)
	ON_COMMAND(ID_MENURUNNINGMSG, OnMenurunningmsg)
	ON_COMMAND(ID_MENUWHEEL840, OnMenuwheel840)
	ON_COMMAND(ID_MENUWHEEL835, OnMenuwheel835)
	ON_COMMAND(ID_MENUWHEEL826, OnMenuwheel826)
	ON_COMMAND(ID_MENUWHEEL818, OnMenuwheel818)
	ON_COMMAND(ID_MENUWHEEL809, OnMenuwheel809)
	ON_COMMAND(ID_MENUWHEEL800, OnMenuwheel800)
	ON_COMMAND(ID_MENUWHEEL791, OnMenuwheel791)
	ON_COMMAND(ID_MENUWHEEL783, OnMenuwheel783)
	ON_COMMAND(ID_MENUWHEEL774, OnMenuwheel774)
	ON_COMMAND(ID_MENUOTHERSET, OnMenuotherset)
	ON_WM_CLOSE()
	ON_COMMAND(ID_MENUHD, OnMenuhd)
	ON_COMMAND(ID_MENUUP, OnMenuup)
	ON_COMMAND(ID_MENUDOWN, OnMenudown)
	ON_COMMAND(ID_MENUITEMRETURN, OnMenuitemreturn)
	ON_COMMAND(ID_MENUITEMNORETURN, OnMenuitemnoreturn)
	ON_COMMAND(ID_BUTTONSETSPEED,OnSetSpeed)
	ON_WM_TIMER()
	ON_COMMAND(ID_MENUCOLORLINE, OnMenucolorline)
	ON_COMMAND(ID_MENUCOLORFONT, OnMenucolorfont)
	ON_COMMAND(ID_MENUCOLORAPR, OnMenucolorapr)
	ON_COMMAND(ID_BUTTONCARRAYCHANGE, OnMenuCarrayfruchange)
	ON_COMMAND(ID_BUTTONCALCULATE, OnShowCalculate)
	ON_COMMAND(ID_BUTTONDEBUG, OnShowDebug)
	ON_COMMAND(ID_BUTTONRETURN3, OnShowReturn3)
	ON_COMMAND(ID_BUTTONRETURN2, OnShowReturn2)
	ON_COMMAND(ID_BUTTONRETURN1, OnShowReturn1)
	ON_COMMAND(ID_BUTTONSHOWAUTO, OnShowAuto)
	ON_COMMAND(ID_BUTTONSHOWHANDLE, OnShowHandle)
	ON_COMMAND(ID_MENUCARRAYTEST, OnMenucarraytest)
	ON_COMMAND(ID_MENUTRACKCODE, OnMenutrackcode)
	ON_COMMAND(ID_BUTTONDISABLEFSB,OnMenuDisableFSB)
	ON_COMMAND(ID_BUTTONDISABLEEB,OnMenuDisableEB)
	ON_COMMAND(ID_MENUTRAIN, OnMenutrain)
	ON_COMMAND(ID_MENUHEAD1, OnMenuhead1)
	ON_COMMAND(ID_MENUTAIL1, OnMenutail1)
	ON_COMMAND(ID_MENUDATABASE1, OnMenudatabase1)
	ON_COMMAND(ID_MENUDATABASE6, OnMenudatabase6)
	ON_COMMAND(ID_AUTOSTOP, OnAutostop)
	ON_COMMAND(ID_BUTTONTESTLINEFUCTION, OnButtontestlinefuction)
	ON_COMMAND(ID_BUTTONFORBIDAPR, OnButtonforbidapr)
	ON_COMMAND(ID_MENUEBRECODER, OnMenuebrecoder)
	ON_WM_MOUSEWHEEL()
	ON_COMMAND(ID_RECODEREB, OnRecodereb)
	ON_COMMAND(ID_BUTTON840, OnButton840)
	ON_COMMAND(ID_BUTTON835, OnButton835)
	ON_COMMAND(ID_BUTTON826, OnButton826)
	ON_COMMAND(ID_BUTTON818, OnButton818)
	ON_COMMAND(ID_BUTTON809, OnButton809)
	ON_COMMAND(ID_BUTTON800, OnButton800)
	ON_COMMAND(ID_BUTTON791, OnButton791)
	ON_COMMAND(ID_BUTTON783, OnButton783)
	ON_COMMAND(ID_BUTTON774, OnButton774)
	ON_COMMAND(ID_MENUITEMPAPRFORBID, OnMenuitempaprforbid)
	ON_COMMAND(ID_BUTTONP1,OnMenud1)
	ON_COMMAND(ID_BUTTONP2,OnMenud2)
	ON_COMMAND(ID_BUTTONP3,OnMenud3)
	ON_COMMAND(ID_BUTTONP4,OnMenud4)
	ON_COMMAND(ID_BUTTONPB,OnMenunone)
	ON_COMMAND(ID_BUTTONB1,OnMenub1)
	ON_COMMAND(ID_BUTTONB2,OnMenub2)
	ON_COMMAND(ID_BUTTONB3,OnMenub3)
	ON_COMMAND(ID_BUTTONB4,OnMenub4)
	ON_COMMAND(ID_BUTTONB5,OnMenub5)
	ON_COMMAND(ID_BUTTONB6,OnMenub6)
	ON_COMMAND(ID_BUTTONB7,OnMenub7)
	ON_COMMAND(ID_BUTTONEB,OnMenueb)
	ON_WM_NCPAINT()
	ON_COMMAND(ID_MENUITEMSETPAPR, OnMenuitemsetpapr)
	//}}AFX_MSG_MAP
	// Global help commands
	ON_COMMAND(ID_HELP_FINDER, CFrameWnd::OnHelpFinder)
	ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, CFrameWnd::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, CFrameWnd::OnHelpFinder)
END_MESSAGE_MAP()

static UINT indicators0[] =
{
//	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_SIR,
	ID_INDICATOR_FSB,
	ID_INDICATOR_RDER,
	ID_INDICATOR_LDER,
	ID_INDICATOR_ZVR,
	ID_INDICATOR_TIR,
	ID_INDICATOR_TIRR,
	ID_INDICATOR_EUMR,
	ID_INDICATOR_MAIL, //8
	ID_INDICATOR_DRIVER,
	ID_INDICATOR_DIRECTOR,
	ID_INDICATOR_SPEED,
	ID_INDICATOR_HEATHY,
	ID_INDICATOR_VERSION,
	ID_INDICATOR_READERWORKSTATUS,
	ID_INDICATOR_READERDISTANCE,
	ID_INDICATOR_READERBEEP,
	ID_INDICATOR_VERSIONOMPM,
	ID_INDICATOR_VERSION_ATPM,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};
static UINT indicators1[] =
{
	//	ID_SEPARATOR,           // status line indicator
		ID_INDICATOR_EB2,
		ID_INDICATOR_FSB2,
		ID_INDICATOR_RDER2,
		ID_INDICATOR_LDER2,
		ID_INDICATOR_ZVR2,
		ID_INDICATOR_CHR2,

};
static UINT indicators2[] =
{
	//	ID_SEPARATOR,           // status line indicator
		ID_INDICATOR_EB1,
		ID_INDICATOR_FSB1,
		ID_INDICATOR_RDER1,
		ID_INDICATOR_LDER1,
		ID_INDICATOR_ZVR1,
		ID_INDICATOR_CHR1,
};
static UINT nButtenIDs[]=
{
		ID_BUTTONNULL,
		ID_SEPARATOR, 
		ID_BUTTONSETSPEED,
		ID_SEPARATOR, 
		ID_BUTTONP1,
		ID_BUTTONP2,
		ID_BUTTONP3,
		ID_BUTTONP4,
		ID_SEPARATOR, 
		ID_BUTTONPB,
		ID_SEPARATOR, 
		ID_BUTTONB1,
		ID_BUTTONB2,
		ID_BUTTONB3,
		ID_BUTTONB4,
		ID_BUTTONB5,
		ID_BUTTONB6,
		ID_BUTTONB7,
		ID_BUTTONEB,
		ID_SEPARATOR, 
		ID_BUTTONCARRAYCHANGE,
		ID_BUTTONSHOWHANDLE,
		ID_BUTTONSHOWAUTO,
		ID_BUTTONRETURN1,
		ID_BUTTONDEBUG,
		ID_BUTTONRETURN2,
		ID_BUTTONRETURN3,
		ID_BUTTONCALCULATE,
		ID_BUTTONDISABLEFSB,
		ID_BUTTONDISABLEEB,
		ID_SEPARATOR, 
		ID_AUTOSTOP,
		ID_BUTTONTESTLINE,
		ID_BUTTONTESTLINEFUCTION,
		ID_BUTTONFORBIDAPR,
		ID_RECODEREB,
		ID_BUTTON840,
		ID_BUTTON835,
		ID_BUTTON826,
		ID_BUTTON818,
		ID_BUTTON809,
		ID_BUTTON800,
		ID_BUTTON791,
		ID_BUTTON783,
		ID_BUTTON774,
};
/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_dacc=0;
	m_strDriverLevel="档位:空挡";
	m_promptinfoStatus.SetCString(0,m_strDriverLevel);
	m_bEndThread=FALSE;
	m_bhead1=TRUE;

	m_bEBrecoder=TRUE;
	m_nGT=0;	//空挡
	m_promptinfoStatus.SetCString(1,"方向:向前");
	m_promptinfoStatus.SetCString(2,"头车");
	m_promptinfoStatus.SetCString(3,"轮径:840");
	m_promptinfoStatus.SetCString(4,"FSB有效");
	m_promptinfoStatus.SetCString(5,"EB有效");
	m_promptinfoStatus.SetCString(6,"NPAPR有效");
	m_promptinfoStatus.SetCString(7,"PAPR有效");
}

CMainFrame::~CMainFrame()
{

}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	//屏蔽自带工具栏
	/*
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	*/
	//自定义工具栏
	
	if (!m_wndToolBardiy.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBardiy.LoadToolBar(IDR_TOOLBARDIY))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	m_wndToolBardiy.SetButtons(nButtenIDs,45);
	

	if (!m_wndToolBardiy.CreateCombo(WS_CHILD|CBS_DROPDOWN|CBS_AUTOHSCROLL|WS_VSCROLL|CBS_HASSTRINGS,&m_pCombo,ID_BUTTONNULL,75,300))
	{
		TRACE0("创建组合框失败!\n");
		return -1;
	}
	m_pCombo.AddString("2");
	m_pCombo.AddString("3.2");
	m_pCombo.AddString("20");
	m_pCombo.AddString("25");
	m_pCombo.AddString("30");
	m_pCombo.AddString("40");
	m_pCombo.AddString("50");
	m_pCombo.AddString("60");
	m_pCombo.AddString("70");
	m_pCombo.AddString("80");
	m_pCombo.SetCurSel(2);

	if (!m_wndToolBardiy.CreateCombo(WS_CHILD|CBS_DROPDOWN|CBS_AUTOHSCROLL|WS_VSCROLL|CBS_HASSTRINGS,&m_pCombotest,ID_BUTTONTESTLINE,75,300))
	{
		TRACE0("创建组合框失败!\n");
		return -1;
	}
	m_pCombotest.AddString("测试0");
	m_pCombotest.AddString("测试1");
	m_pCombotest.AddString("测试2");
	m_pCombotest.AddString("测试3");
	m_pCombotest.AddString("测试4");
	m_pCombotest.AddString("测试5");
	m_pCombotest.AddString("测试6");
	m_pCombotest.AddString("测试7");
	m_pCombotest.AddString("测试8");
	m_pCombotest.AddString("测试9");
	m_pCombotest.AddString("测试10");
	m_pCombotest.AddString("测试11");
	m_pCombotest.AddString("测试12");
	m_pCombotest.AddString("测试13");
	m_pCombotest.AddString("测试14");
	m_pCombotest.AddString("测试15");
	m_pCombotest.AddString("测试16");
	m_pCombotest.AddString("测试17");
	m_pCombotest.AddString("测试18");
	m_pCombotest.AddString("测试19");
	m_pCombotest.AddString("测试20");
	m_pCombotest.AddString("测试21");
	m_pCombotest.AddString("测试22");
	m_pCombotest.AddString("测试23");
	m_pCombotest.AddString("测试24");
	m_pCombotest.AddString("测试25");
	m_pCombotest.AddString("测试26");
	m_pCombotest.AddString("测试27");
	m_pCombotest.AddString("测试28");
	m_pCombotest.AddString("测试29");
	m_pCombotest.AddString("测试30");
	m_pCombotest.SetCurSel(0);


	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators0,
		  sizeof(indicators0)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}


	if (!m_wndStatusBar1.Create(this) ||
		!m_wndStatusBar1.SetIndicators(indicators1,
		sizeof(indicators1)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar2.Create(this) ||
		!m_wndStatusBar2.SetIndicators(indicators2,
		sizeof(indicators2)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}


	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
//	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBardiy.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
//	DockControlBar(&m_wndToolBar);
	DockControlBar(&m_wndToolBardiy);
	MainFrameInit();
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		| WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnMenusetview() 
{
	// TODO: Add your command handler code here
	//设置 视图对话框
	CSetview * m_dlgsetview;
	m_dlgsetview = new CSetview();
	m_dlgsetview->Create(IDD_DIALOGVIEW);
	m_dlgsetview->ShowWindow(SW_SHOW);
	int m_ntest=0;
	m_dlgsetview->GetScrollPos(m_ntest);
}

void CMainFrame::OnMenueb() 
{
	// TODO: Add your command handler code here
	m_dacc=-1.2;
	Acceleration(m_dacc);
	m_strDriverLevel="档位:EB";
	m_promptinfoStatus.SetCString(0,m_strDriverLevel);
	m_wndStatusBar.SetPaneText(9,m_strDriverLevel);
	m_strDriverLevel.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_strDriverLevel);
	m_byteWriteStatus[0x14]=EB;
	m_bSendStatus=TRUE;
	m_bEBvalid=TRUE;
	m_bDisableNone=TRUE;
	if (m_bEBrecoder==TRUE)
	{
		CString m_str;
		m_str.Format("%0.2f",m_fgtrainclasp);
		m_str.Insert(0,"启用EB车钩位置:");
		m_promptinfoMailandV.SetCString(5,m_str);
		//速度
		m_str.Format("%0.2f",m_dgspeed);
		m_str.Insert(0,"启用EB时速度:");
		m_promptinfoMailandV.SetCString(6,m_str);
		m_bEBrecoder=FALSE;
	}
	m_nGT=-8;
	Invalidate(TRUE);
}

void CMainFrame::OnMenub1() 
{
	// TODO: Add your command handler code here
	m_dacc=-0.1714285714285714285714285714;
	Acceleration(m_dacc);
	m_strDriverLevel="档位:B1";
	m_promptinfoStatus.SetCString(0,m_strDriverLevel);
	m_wndStatusBar.SetPaneText(9,m_strDriverLevel);
	m_strDriverLevel.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_strDriverLevel);
	m_byteWriteStatus[0x14]=B1;
	m_bSendStatus=TRUE;
	m_bDisableNone=TRUE;
		m_nGT=-1;
	Invalidate(TRUE);
}

void CMainFrame::OnMenub2() 
{
	// TODO: Add your command handler code here
	m_dacc=-0.3428571428571428571428571428;
	Acceleration(m_dacc);
	m_strDriverLevel="档位:B2";
	m_promptinfoStatus.SetCString(0,m_strDriverLevel);
	m_wndStatusBar.SetPaneText(9,m_strDriverLevel);
	m_strDriverLevel.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_strDriverLevel);
	m_byteWriteStatus[0x14]=B2;
	m_bSendStatus=TRUE;
	m_bDisableNone=TRUE;
		m_nGT=-2;
	Invalidate(TRUE);
}

void CMainFrame::OnMenub3() 
{
	// TODO: Add your command handler code here
	m_dacc=-0.5142857142857142857142857142;
	Acceleration(m_dacc);
	m_strDriverLevel="档位:B3";
	m_promptinfoStatus.SetCString(0,m_strDriverLevel);
	m_wndStatusBar.SetPaneText(9,m_strDriverLevel);
	m_strDriverLevel.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_strDriverLevel);
	m_byteWriteStatus[0x14]=B3;
	m_bSendStatus=TRUE;
	m_bDisableNone=TRUE;
		m_nGT=-3;
	Invalidate(TRUE);
}

void CMainFrame::OnMenub4() 
{
	// TODO: Add your command handler code here
	m_dacc=-0.6857142857142857142857142857;
	Acceleration(m_dacc);
	m_strDriverLevel="档位:B4";
	m_promptinfoStatus.SetCString(0,m_strDriverLevel);
	m_wndStatusBar.SetPaneText(9,m_strDriverLevel);
	m_strDriverLevel.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_strDriverLevel);
	m_byteWriteStatus[0x14]=B4;
	m_bSendStatus=TRUE;
	m_bDisableNone=TRUE;
		m_nGT=-4;
	Invalidate(TRUE);
}

void CMainFrame::OnMenub5() 
{
	// TODO: Add your command handler code here
	m_dacc=-0.8571428571428571428571428571;
	Acceleration(m_dacc);
	m_strDriverLevel="档位:B5";
	m_promptinfoStatus.SetCString(0,m_strDriverLevel);
	m_wndStatusBar.SetPaneText(9,m_strDriverLevel);
	m_strDriverLevel.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_strDriverLevel);
	m_byteWriteStatus[0x14]=B5;
	m_bSendStatus=TRUE;
	m_bDisableNone=TRUE;
		m_nGT=-5;
	Invalidate(TRUE);
}

void CMainFrame::OnMenub6() 
{
	// TODO: Add your command handler code here
	m_dacc=-1.0285714285714285714285714285;
	Acceleration(m_dacc);
	m_strDriverLevel="档位:B6";
	m_promptinfoStatus.SetCString(0,m_strDriverLevel);
	m_wndStatusBar.SetPaneText(9,m_strDriverLevel);
	m_strDriverLevel.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_strDriverLevel);
	m_byteWriteStatus[0x14]=B6;
	m_bSendStatus=TRUE;
	m_bDisableNone=TRUE;
		m_nGT=-6;
	Invalidate(TRUE);
}

void CMainFrame::OnMenub7() 
{
	// TODO: Add your command handler code here
	m_dacc=-1.0;
	Acceleration(m_dacc);
	m_strDriverLevel="档位:B7";
	m_promptinfoStatus.SetCString(0,m_strDriverLevel);
	m_wndStatusBar.SetPaneText(9,m_strDriverLevel);
	m_strDriverLevel.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_strDriverLevel);
	m_byteWriteStatus[0x14]=B7;
	m_bSendStatus=TRUE;
	m_bDisableNone=TRUE;
		m_nGT=-7;
	Invalidate(TRUE);
}

void CMainFrame::OnMenud1() 
{
	// TODO: Add your command handler code here
	m_dacc=0.3;
	Acceleration(m_dacc);
	m_strDriverLevel="档位:P1";
	m_promptinfoStatus.SetCString(0,m_strDriverLevel);
	m_wndStatusBar.SetPaneText(9,m_strDriverLevel);
	m_strDriverLevel.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_strDriverLevel);
	m_byteWriteStatus[0x14]=D1;
	m_bSendStatus=TRUE;
	m_bDisableNone=TRUE;
	OnMenuebrecoder();
		m_nGT=1;
	Invalidate(TRUE);
}

void CMainFrame::OnMenud2() 
{
	// TODO: Add your command handler code here
	m_dacc=0.5;
	Acceleration(m_dacc);
	m_strDriverLevel="档位:P2";
	m_promptinfoStatus.SetCString(0,m_strDriverLevel);
	m_wndStatusBar.SetPaneText(9,m_strDriverLevel);
	m_strDriverLevel.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_strDriverLevel);
	m_byteWriteStatus[0x14]=D2;
	m_bSendStatus=TRUE;
	m_bDisableNone=TRUE;
	OnMenuebrecoder();
		m_nGT=2;
	Invalidate(TRUE);
}

void CMainFrame::OnMenud3() 
{
	// TODO: Add your command handler code here
	m_dacc=0.74;
	Acceleration(m_dacc);
	m_strDriverLevel="档位:P3";
	m_promptinfoStatus.SetCString(0,m_strDriverLevel);
	m_wndStatusBar.SetPaneText(9,m_strDriverLevel);
	m_strDriverLevel.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_strDriverLevel);
	m_byteWriteStatus[0x14]=D3;
	m_bSendStatus=TRUE;
	m_bDisableNone=TRUE;
	OnMenuebrecoder();
		m_nGT=3;
	Invalidate(TRUE);
}

void CMainFrame::OnMenud4() 
{
	// TODO: Add your command handler code here
	m_dacc=0.9;
	Acceleration(m_dacc);
	m_strDriverLevel="档位:P4";
	m_promptinfoStatus.SetCString(0,m_strDriverLevel);
	m_wndStatusBar.SetPaneText(9,m_strDriverLevel);
	m_strDriverLevel.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_strDriverLevel);
	m_byteWriteStatus[0x14]=D4;
	m_bSendStatus=TRUE;
	m_bDisableNone=TRUE;
	OnMenuebrecoder();
	m_nGT=4;
	Invalidate(TRUE);
}

void CMainFrame::OnMenunone() 
{
	// TODO: Add your command handler code here
	m_dacc=-0.025;
	Acceleration(m_dacc);
	m_strDriverLevel="档位:空挡";
	m_promptinfoStatus.SetCString(0,m_strDriverLevel);
	m_wndStatusBar.SetPaneText(9,m_strDriverLevel);
	m_strDriverLevel.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_strDriverLevel);
	m_byteWriteStatus[0x14]=D0;
	m_bSendStatus=TRUE;
	m_nGT=0;
	Invalidate(TRUE);
}

void CMainFrame::Acceleration(double m_acc)
{
	WORD m_wacc=0;
	if (m_acc>=0)
	{
		m_acc=m_acc*100;
		m_wacc=(WORD)m_acc;
		m_byteWriteStatus[0x09]=(unsigned char)m_wacc;
		m_wacc=m_wacc>>8;
		m_byteWriteStatus[0x0A]=(unsigned char)m_wacc;
	} 
	else
	{
		m_acc=m_acc*100;
		m_acc=-m_acc;
		m_wacc=(WORD)m_acc;
		m_wacc=m_wacc|0x8000;
		m_byteWriteStatus[0x09]=(unsigned char)m_wacc;
		m_wacc=m_wacc>>8;
		m_byteWriteStatus[0x0A]=(unsigned char)m_wacc;
	}

}

void CMainFrame::OnMenudirforward() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x08]=m_byteWriteStatus[0x08]&0XF8;
	m_byteWriteStatus[0x08]=m_byteWriteStatus[0x08]|0X01;
	CString m_str="方向:前";
	m_promptinfoStatus.SetCString(1,m_str);
	m_wndStatusBar.SetPaneText(10,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=FORWARD;
	m_bSendStatus=TRUE;
	
	ClearFlag();
	Invalidate(TRUE);
}

void CMainFrame::OnMenudir0() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x08]=m_byteWriteStatus[0x08]&0XF8;
	m_byteWriteStatus[0x08]=m_byteWriteStatus[0x08]|0X02;
	CString m_str="方向:无";
	m_promptinfoStatus.SetCString(1,m_str);
	m_wndStatusBar.SetPaneText(10,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=NODIREACTOR;
	m_bSendStatus=TRUE;
	ClearFlag();
	Invalidate(TRUE);
}

void CMainFrame::OnMenudirback() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x08]=m_byteWriteStatus[0x08]&0XF8;
	m_byteWriteStatus[0x08]=m_byteWriteStatus[0x08]|0X04;
	CString m_str="方向:后";
	m_promptinfoStatus.SetCString(1,m_str);
	m_wndStatusBar.SetPaneText(10,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=BACK;
	m_bSendStatus=TRUE;
	ClearFlag();
	Invalidate(TRUE);
}
void CMainFrame::OnMenuhead() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x08]=m_byteWriteStatus[0x08]&0X07;
	m_byteWriteStatus[0x08]=m_byteWriteStatus[0x08]|0X10;
	CString m_str="头车";
	m_promptinfoStatus.SetCString(2,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=HEAD;
	m_bSendStatus=TRUE;
	Invalidate(TRUE);
}

void CMainFrame::OnMenutrail() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x08]=m_byteWriteStatus[0x08]&0X07;
	m_byteWriteStatus[0x08]=m_byteWriteStatus[0x08]|0X08;
	CString m_str="尾车";
	m_promptinfoStatus.SetCString(2,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=TRAIL;
	m_bSendStatus=TRUE;
	Invalidate(TRUE);
}

void CMainFrame::OnMenupc() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x15]=0xAA;
	CString m_str="上位机控车";
	m_promptinfoStatus.SetCString(2,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=PC;
	m_bSendStatus=TRUE;
	Invalidate(TRUE);
}

void CMainFrame::OnMenudc() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x15]=0x55;
	CString m_str="司控台控车";
	m_promptinfoStatus.SetCString(2,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=DC;
	m_bSendStatus=TRUE;
	Invalidate(TRUE);
}

void CMainFrame::OnMenuviewontrain() 
{
	// TODO: Add your command handler code here
	m_bViewOn=TRUE;
}

void CMainFrame::OnMenuviewontrack() 
{
	// TODO: Add your command handler code here
	m_bViewOn=FALSE;
}

void CMainFrame::MainFrameInit()
{
	m_wndStatusBar.SetPaneText(9,m_strDriverLevel);
}

void CMainFrame::OnMenurunningmsg() 
{
	// TODO: Add your command handler code here

	m_dlgmsg->ShowWindow(SW_SHOW);
}

void CMainFrame::OnMenuwheel840() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x12]=0x09;
	CString m_str="轮径:840";
	m_promptinfoStatus.SetCString(3,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=WD840;
	m_bSendStatus=TRUE;
	Invalidate(TRUE);
}

void CMainFrame::OnMenuwheel835() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x12]=0x08;
	CString m_str="轮径:835";
	m_promptinfoStatus.SetCString(3,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=WD835;
	m_bSendStatus=TRUE;
	Invalidate(TRUE);
}

void CMainFrame::OnMenuwheel826() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x12]=0x07;
	CString m_str="轮径:826";
	m_promptinfoStatus.SetCString(3,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=WD826;
	m_bSendStatus=TRUE;
	Invalidate(TRUE);
}

void CMainFrame::OnMenuwheel818() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x12]=0x06;
	CString m_str="轮径:818";
	m_promptinfoStatus.SetCString(3,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=WD818;
	m_bSendStatus=TRUE;
	Invalidate(TRUE);
}

void CMainFrame::OnMenuwheel809() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x12]=0x05;
	CString m_str="轮径:809";
	m_promptinfoStatus.SetCString(3,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=WD809;
	m_bSendStatus=TRUE;
	Invalidate(TRUE);
}

void CMainFrame::OnMenuwheel800() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x12]=0x04;
	CString m_str="轮径:800";
	m_promptinfoStatus.SetCString(3,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=WD800;
	m_bSendStatus=TRUE;
	Invalidate(TRUE);
}

void CMainFrame::OnMenuwheel791() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x12]=0x03;
	CString m_str="轮径:791";
	m_promptinfoStatus.SetCString(3,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=WD791;
	m_bSendStatus=TRUE;
	Invalidate(TRUE);
}

void CMainFrame::OnMenuwheel783() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x12]=0x02;
	CString m_str="轮径:783";
	m_promptinfoStatus.SetCString(3,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=WD783;
	m_bSendStatus=TRUE;
	Invalidate(TRUE);
}

void CMainFrame::OnMenuwheel774() 
{
	// TODO: Add your command handler code here
	m_byteWriteStatus[0x12]=0x01;
	CString m_str="轮径:774";
	m_promptinfoStatus.SetCString(3,m_str);
	m_str.Insert(0,"(人工)");
	m_showmsg.AddMsg(m_str);
	m_byteWriteStatus[0x14]=WD774;
	m_bSendStatus=TRUE;
	Invalidate(TRUE);
}

void CMainFrame::OnMenuotherset() 
{
	// TODO: Add your command handler code here
	COTHERSET * m_dlgotherset;
	m_dlgotherset = new COTHERSET();
	m_dlgotherset->Create(IDD_DIALOGOTHERSET);
	m_dlgotherset->ShowWindow(SW_SHOW);
}

void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	//等待子线程退出
	m_bEndThread=TRUE;
	m_bThreadRXrunning=FALSE;
	m_bThreadTXrunning=FALSE;
	DWORD m_dwr;
	m_dwr=WaitForSingleObject(pThreadWriter->m_hThread,INFINITE);
	m_dwr=WaitForSingleObject(pThreadRead->m_hThread,INFINITE);
	//	接收线程
	switch (m_dwr)
	{
	case WAIT_FAILED:
		{
			break;
		}
	case WAIT_TIMEOUT:
		{
			break;
		}
	case WAIT_ABANDONED:
		{
			break;
		}
	case WAIT_OBJECT_0:
		{
			break;
		}
	}
	m_dwr=GetLastError();

	CFrameWnd::OnClose();
}

void CMainFrame::OnMenuhd() 
{
	// TODO: Add your command handler code here
	CSETHD * m_dlgsethd;
	m_dlgsethd = new CSETHD();
	m_dlgsethd->Create(IDD_DIALOGHD);
	m_dlgsethd->ShowWindow(SW_SHOW);
}

void CMainFrame::OnMenuup() 
{
	// TODO: Add your command handler code here
	//上行只改变车辆方向和查找轨道
//	m_bDirectorup=TRUE;
	/*
	m_ngTrainhigh=294;	
	m_ngTrainpos=1080;
	m_pTrainpos.x=m_ngTrainpos;
	m_pTrainpos.y=m_ngTrainhigh;
	m_Train.SetTrainPos(m_pTrainpos);
	*/
	m_Train.SetTrainDirection(0);
	//上行默认方向向后
	OnMenudirback();
	//改变方向数据清除
	ClearFlag();
}

void CMainFrame::OnMenudown() 
{
	// TODO: Add your command handler code here
	//下行只改变车辆方向和查找轨道
//	m_bDirectorup=FALSE;
	/*
	m_ngTrainhigh=376;
	m_ngTrainpos=250;
	m_pTrainpos.x=m_ngTrainpos;
	m_pTrainpos.y=m_ngTrainhigh;
	m_Train.SetTrainPos(m_pTrainpos);
	*/
	m_Train.SetTrainDirection(1);
	//下行默认方向向前
	OnMenudirforward();
	//改变方向数据清除
	ClearFlag();
}

void CMainFrame::OnMenuitemreturn() 
{
	// TODO: Add your command handler code here
	m_bSendDebug=TRUE;
}

void CMainFrame::OnMenuitemnoreturn() 
{
	// TODO: Add your command handler code here
	m_bSendDebug=FALSE;
}
void CMainFrame::OnSetSpeed()
{
	int m_nsel=0;
	CString m_str;
	m_nsel=m_pCombo.GetCurSel();

	//选择
	if (m_nsel>=0)
	{
		m_pCombo.GetLBText(m_nsel,m_str);
	} 
	//编辑
	else
	{
		char m_char[20];
		m_pCombo.GetWindowText(m_char,20);
		m_str=m_char;
	}

	m_ftargetspeed=(float)atof(m_str);
	SetTimer(1,1,NULL);
}

void CMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent)
	{
	case 1:
		{
			ToGetTargetSpeed(m_ftargetspeed, (float)m_dgspeed);
			break;
		}
	case 2:
		{
			SetTargetSpeed(m_ftargetspeed,(float) m_dgspeed);
			break;
		}
	}
	CFrameWnd::OnTimer(nIDEvent);
}
void CMainFrame::SetTargetSpeed(float targets,float currs)
{
	//是否达到目标速度
	if ((targets>=(currs))&&(targets<(currs+(float)0.05)))
	{
		OnMenunone(); 
		KillTimer(2);
		CMainFrame* pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;	//先通过获取当前框架指针 
		CView * active = pMF->GetActiveView();					//才能获取当前视类指针 
		if(active != NULL)										//获取了当前视类指针才能发送消息 
		{
			active->PostMessage(WM_TARGETSPEED,0,0);   //使用PostMessage发送保存折弯点位置消息
		}
		return;
	}
	//加速
	if (currs<=targets)
	{
		OnMenud1(); 
		return ;
	}
	else
	{
		OnMenub3();
		return;
	}
}
void CMainFrame::ToGetTargetSpeed(float targets, float currs)
{
	float m_fnegative=0;
	//是否达到目标速度
	if ((targets>=(currs))&&(targets<(currs+(float)0.05)))
	{
		OnMenunone(); 
		KillTimer(1);
		return;
	}
	//加速
	if (currs<=targets)
	{
		m_fnegative=targets-currs;
		if (m_fnegative>=40)
		{
			OnMenud4(); 
			return ;
		}
		else if (m_fnegative>=30)
		{
			OnMenud3(); 
			return ;
		}
		else if (m_fnegative>=20)
		{
			OnMenud2(); 
			return ;
		}
		else
		{
			OnMenud1(); 
			return ;
		}
	} 
	//减速
	else
	{
		m_fnegative=currs-targets;
		
		if (m_fnegative>=70)
		{
			OnMenub7();
			return;
		}
		else if (m_fnegative>=60)
		{
			OnMenub6();
			return;
		}
		else if (m_fnegative>=50)
		{
			OnMenub5();
			return;
		}
		else if (m_fnegative>=40)
		{
			OnMenub4();
			return;
		}
		else if (m_fnegative>=30)
		{
			OnMenub3();
			return;
		}
		else if (m_fnegative>=20)
		{
			OnMenub2();
			return;
		}
		else if (m_fnegative>=10)
		{
			OnMenub1();
			return;
		}
	}
}

void CMainFrame::OnMenucolorline() 
{
	// TODO: Add your command handler code here
	CColorDialog m_dlgcolor;
	if (m_dlgcolor.DoModal()==IDOK)
	{
		m_colorgline=m_dlgcolor.GetColor();
	}
}

void CMainFrame::OnMenucolorfont() 
{
	// TODO: Add your command handler code here
	CColorDialog m_dlgcolor;
	if (m_dlgcolor.DoModal()==IDOK)
	{
		m_colorgfont=m_dlgcolor.GetColor();
	}
}

void CMainFrame::OnMenucolorapr() 
{
	// TODO: Add your command handler code here
	CColorDialog m_dlgcolor;
	if (m_dlgcolor.DoModal()==IDOK)
	{
		m_colorgapr=m_dlgcolor.GetColor();
	}
}
void CMainFrame::OnMenuCarrayfruchange()
{
	if(m_bCarrayFruChangeTest==FALSE)
	{
		m_bCarrayFruChangeTest=TRUE;
		m_bytepCFCT=0;
		CString m_str="已开启载频变换测试";
		m_showmsg.AddMsg(m_str);
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
		m_promptinfoCFCT.SetCString(0,"载频变换顺序");
	}
	else
	{
		m_bCarrayFruChangeTest=FALSE;
		CString m_str="已关闭载频变换测试";
		m_showmsg.AddMsg(m_str);
	}
	Invalidate(TRUE);
}

void CMainFrame::OnShowHandle()
{
	if (m_bshowhandle==FALSE)
	{
		m_bshowhandle=TRUE;
		m_promptinfoshow.SetCString(0,"显示人工操作");
	} 
	else
	{
		m_bshowhandle=FALSE;
		m_promptinfoshow.SetCString(0,"禁止显示人工操作");
	}
}

void CMainFrame::OnShowAuto()
{
	if (m_bshowauto==FALSE)
	{
		m_bshowauto=TRUE;
		m_promptinfoshow.SetCString(1,"显示自动操作");
	} 
	else
	{
		m_bshowauto=FALSE;
		m_promptinfoshow.SetCString(1,"禁止显示自动操作");
	}
}

void CMainFrame::OnShowReturn1()
{
	if (m_bshowreturn1==FALSE)
	{
		m_bshowreturn1=TRUE;
		m_promptinfoshow.SetCString(2,"显示返回信息1");
	} 
	else
	{
		m_bshowreturn1=FALSE;
		m_promptinfoshow.SetCString(2,"禁止显示返回信息1");
	}
}

void CMainFrame::OnShowReturn2()
{
	if (m_bshowreturn2==FALSE)
	{
		m_bshowreturn2=TRUE;
		m_promptinfoshow.SetCString(3,"显示返回信息2");
	} 
	else
	{
		m_bshowreturn2=FALSE;
		m_promptinfoshow.SetCString(3,"禁止显示返回信息2");
	}
}

void CMainFrame::OnShowReturn3()
{
	if (m_bshowreturn3==FALSE)
	{
		m_bshowreturn3=TRUE;
		m_promptinfoshow.SetCString(4,"显示返回信息3");
	} 
	else
	{
		m_bshowreturn3=FALSE;
		m_promptinfoshow.SetCString(4,"禁止显示返回信息3");
	}
}

void CMainFrame::OnShowDebug()
{
	if (m_bshowdebug==FALSE)
	{
		m_bshowdebug=TRUE;
		m_promptinfoshow.SetCString(5,"显示调试信息");
	} 
	else
	{
		m_bshowdebug=FALSE;
		m_promptinfoshow.SetCString(5,"禁止显示调试信息");
	}
}

void CMainFrame::OnShowCalculate()
{
	if (m_bshowcalculate==FALSE)
	{
		m_bshowcalculate=TRUE;
		m_promptinfoshow.SetCString(6,"显示运行信息");
	} 
	else
	{
		m_bshowcalculate=FALSE;
		m_promptinfoshow.SetCString(6,"禁止显示运行信息");
	}
}

void CMainFrame::OnMenucarraytest() 
{
	// TODO: Add your command handler code here
	DIALOGCARRAYTEST * m_dlgcarraytest;
	m_dlgcarraytest = new DIALOGCARRAYTEST();
	m_dlgcarraytest->Create(IDD_DIALOGCARRAYTEST);
	m_dlgcarraytest->ShowWindow(SW_SHOW);
}

void CMainFrame::OnMenutrackcode() 
{
	// TODO: Add your command handler code here
	TRACKCODECHANGE * m_dlgtrackcodechange;
	m_dlgtrackcodechange = new TRACKCODECHANGE();
	m_dlgtrackcodechange->Create(IDD_DIALOGTRACKCODECHANGE);
	m_dlgtrackcodechange->ShowWindow(SW_SHOW);
}
void CMainFrame::OnMenuDisableFSB()
{
	if (m_bdisablefsb==TRUE)
	{
		m_bdisablefsb=FALSE;
		m_showmsg.AddMsg("(人工)FSB失效禁用");
		m_promptinfoStatus.SetCString(4,"FSB有效");
	} 
	else
	{
		m_bdisablefsb=TRUE;
		m_showmsg.AddMsg("(人工)FSB失效启用");
		m_promptinfoStatus.SetCString(4,"FSB无效");
	}
}
void CMainFrame::OnMenuDisableEB()
{
	if (m_bdisableeb==TRUE)
	{
		m_bdisableeb=FALSE;
		m_showmsg.AddMsg("(人工)EB失效禁用");
		m_promptinfoStatus.SetCString(5,"EB有效");
	} 
	else
	{
		m_bdisableeb=TRUE;
		m_showmsg.AddMsg("(人工)EB失效启用");
		m_promptinfoStatus.SetCString(5,"EB无效");
	}
}

void CMainFrame::OnMenutrain() 
{
	// TODO: Add your command handler code here
	TRAINSET * m_dlgtrainset;
	m_dlgtrainset = new TRAINSET();
	m_dlgtrainset->Create(IDD_DIALOGTRAIN);
	m_dlgtrainset->ShowWindow(SW_SHOW);
}

void CMainFrame::ClearFlag()
{
	CMainFrame* pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;	//先通过获取当前框架指针 
	CView * active = pMF->GetActiveView();					//才能获取当前视类指针 
	if(active != NULL)										//获取了当前视类指针才能发送消息 
	{
		active->PostMessage(WM_CLEARFLAG,0,0);   //使用PostMessage发送清除标志消息
	}
}

void CMainFrame::OnMenuhead1() 
{
	// TODO: Add your command handler code here
	IsSaveTurnPos(1);
	m_bhead1=TRUE;					//1号车是否为头车
	if (m_bgoahead==TRUE)
	{
		OnMenudirforward();
	} 
	else
	{
		OnMenudirback();
	}
	m_Train.SetTrainDirection(1);
}

void CMainFrame::OnMenutail1() 
{
	// TODO: Add your command handler code here
	IsSaveTurnPos(2);
	m_bhead1=FALSE;
	if (m_bgoahead==TRUE)
	{
		OnMenudirforward();
	} 
	else
	{
		OnMenudirback();
	}
	m_Train.SetTrainDirection(0);
}

void CMainFrame::OnMenudatabase1() 
{
	// TODO: Add your command handler code here
	//方向 向前
	IsSaveTurnPos(3);
	m_bgoahead=TRUE;
	OnMenudirforward();
}

void CMainFrame::OnMenudatabase6() 
{
	// TODO: Add your command handler code here
	//方向 向后
	IsSaveTurnPos(4);
	m_bgoahead=FALSE;
	OnMenudirback();
}

void CMainFrame::SendSaveTurnPosMsg()
{
	CMainFrame* pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;	//先通过获取当前框架指针 
	CView * active = pMF->GetActiveView();					//才能获取当前视类指针 
	if(active != NULL)										//获取了当前视类指针才能发送消息 
	{
		active->PostMessage(WM_SAVETURNPOS,0,0);   //使用PostMessage发送保存折弯点位置消息
	}
}

BOOL CMainFrame::IsSaveTurnPos(int m_nchangestype)
{
	//是否保存折弯点
	BOOL m_bsave=FALSE;
	//1号车是否为头
	if (m_bhead1==TRUE)
	{
		//1号车为头
		if (m_bgoahead==TRUE)
		{
			//前进 ，默认状态下行
			switch (m_nchangestype)
			{
			case 1:
				{	//无动作，1号车已经是车头
					break;
				}
			case 2:
				{
					//默认情况切成尾，改变上下行，应保存折弯点
					SendSaveTurnPosMsg();
					break;
				}
			case 3:
				{
					//无动作，1号车已经向前
					break;
				}
			case 4:
				{
					//默认情况切前后,改变上下行，应保存折弯点
					SendSaveTurnPosMsg();
					break;
				}
			}
		} 
		else
		{
			//后退 
			switch (m_nchangestype)
			{
			case 1:
				{
					//无动作，1号车已经是车头
					break;
				}
			case 2:
				{
					//尾车向后，改变上下行，保存折弯点
					SendSaveTurnPosMsg();
					break;
				}
			case 3:
				{
					//向前，头车，改变上下行，保存折弯点
					SendSaveTurnPosMsg();
					break;
				}
			case 4:
				{
					//无动作，已经是想后
					break;
				}
			}
		}
	} 
	else
	{
		if (m_bgoahead==TRUE)
		{
			//尾车向前
			switch (m_nchangestype)
			{
			case 1:
				{
					//切头车，改变上下行，保存折弯点
					SendSaveTurnPosMsg();
					break;
				}
			case 2:
				{
					//已经为尾车
					break;
				}
			case 3:
				{
					//向前，已经向前
					break;
				}
			case 4:
				{
					SendSaveTurnPosMsg();
					break;
				}
			}
		} 
		else
		{
			//尾车向后
			switch (m_nchangestype)
			{
			case 1:
				{
					//改变上下行
					SendSaveTurnPosMsg();
					break;
				}
			case 2:
				{
					//已经是尾车
					break;
				}
			case 3:
				{
					//向前，改变上下行
					SendSaveTurnPosMsg();
					break;
				}
			case 4:
				{
					break;
				}
			}
		}
	}
	return m_bsave;
}

BOOL CMainFrame::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	switch   (pMsg->message)  
	{                                              
	case   WM_KEYDOWN:  
		{  
			switch(pMsg->wParam)  
			{  
			case	VK_0://0键
				{
					OnMenunone();
					return TRUE;
				}
			case	VK_0+1:
				{
					OnMenud1();
					return TRUE;
				}
			case	VK_0+2:
				{
					OnMenud2();
					return TRUE;
				}
			case	VK_0+3:
				{
					OnMenud3();
					return TRUE;
				}
			case	VK_0+4:
				{
					OnMenud4();
					return TRUE;
				}
			case VK_NUMPAD0:
				{
					OnMenunone();
					return TRUE;
				}
			case VK_NUMPAD1:
				{
					OnMenub1();
					return TRUE;
				}
			case VK_NUMPAD2:
				{
					OnMenub2();
					return TRUE;
				}
			case VK_NUMPAD3:
				{
					OnMenub3();
					return TRUE;
				}
			case VK_NUMPAD4:
				{
					OnMenub4();
					return TRUE;
				}
			case VK_NUMPAD5:
				{
					OnMenub5();
					return TRUE;
				}
			case VK_NUMPAD6:
				{
					OnMenub6();
					return TRUE;
				}
			case VK_NUMPAD7:
				{
					OnMenub7();
					return TRUE;
				}
			case 'E':
				{
					OnMenueb();
					return TRUE;
				}
			case 'X':
				{
					OnSetSpeed();
					return TRUE;
				}
			case 'C':
				{
					OnMenuCarrayfruchange();
					return TRUE;
				}
			case 'Q':
				{
					OnMenudatabase1();
					return TRUE;
				}
			case 'H':
				{
					OnMenudatabase6();
					return TRUE;
				}
			case 'L':
				{
					OnMenutail1();
					return TRUE;
				}
			case 'Y':
				{
					OnMenuhead1();
					return TRUE;
				}
			case 'P':
				{
					OnMenuDisableEB();
					OnMenuDisableFSB();
					return TRUE;
				}
			case 'M':
				{
					OnMenuotherset();
					return TRUE;
				}
			case 'Z':
				{
					OnMenucarraytest();
					return TRUE;
				}
			case 'G':
				{
					OnMenutrackcode();
					return TRUE;
				}
			case 'T':
				{
					OnMenutrain();
					return TRUE;
				}
			case 'B':
				{
					OnAutostop();
					return TRUE;
				}
			case 'R':
				{
					OnMenuebrecoder(); 
					return TRUE;
				}
			case 'J':
				{
					OnMenuebrecoder(); 
					return TRUE;
				}
			}
		}                   
      } 
	return CFrameWnd::PreTranslateMessage(pMsg);
}

void CMainFrame::OnAutostop() 
{
	// TODO: Add your command handler code here

	CMainFrame* pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;	//先通过获取当前框架指针 
	CView * active = pMF->GetActiveView();					//才能获取当前视类指针 
	if(active != NULL)										//获取了当前视类指针才能发送消息 
	{
		active->PostMessage(WM_AUTOSTOP,0,0);   //使用PostMessage发送保存折弯点位置消息
	}
}

void CMainFrame::Ebtotargetspeed(float m_targetspeed)
{
	m_ftargetspeed=m_targetspeed;
	SetTimer(2,1,NULL);
}

void CMainFrame::OnButtontestlinefuction() 
{
	// TODO: Add your command handler code here
	int	m_nselect=m_pCombotest.GetCurSel();
	switch (m_nselect)
	{
	case 0:
		{
			LoadTestLineConfig("TESTTRACK0.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK0.INI");
			break;
		}
	case 1:
		{
			LoadTestLineConfig("TESTTRACK1.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK1.INI");
			break;
		}
	case 2:
		{
			LoadTestLineConfig("TESTTRACK2.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK2.INI");
			break;
		}
	case 3:
		{
			LoadTestLineConfig("TESTTRACK3.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK3.INI");
			break;
		}
	case 4:
		{
			LoadTestLineConfig("TESTTRACK4.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK4.INI");
			break;
		}
	case 5:
		{
			LoadTestLineConfig("TESTTRACK5.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK5.INI");
			break;
		}
	case 6:
		{
			LoadTestLineConfig("TESTTRACK6.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK6.INI");
			break;
		}
	case 7:
		{
			LoadTestLineConfig("TESTTRACK7.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK7.INI");
			break;
		}
	case 8:
		{
			LoadTestLineConfig("TESTTRACK8.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK8.INI");
			break;
		}
	case 9:
		{
			LoadTestLineConfig("TESTTRACK9.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK9.INI");
			break;
		}
	case 10:
		{
			LoadTestLineConfig("TESTTRACK10.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK10.INI");
			break;
		}
	case 11:
		{
			LoadTestLineConfig("TESTTRACK11.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK11.INI");
			break;
		}
	case 12:
		{
			LoadTestLineConfig("TESTTRACK12.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK12.INI");
			break;
		}
	case 13:
		{
			LoadTestLineConfig("TESTTRACK13.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK13.INI");
			break;
		}
	case 14:
		{
			LoadTestLineConfig("TESTTRACK14.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK14.INI");
			break;
		}
	case 15:
		{
			LoadTestLineConfig("TESTTRACK15.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK15.INI");
			break;
		}
	case 16:
		{
			LoadTestLineConfig("TESTTRACK16.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK16.INI");
			break;
		}
	case 17:
		{
			LoadTestLineConfig("TESTTRACK17.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK17.INI");
			break;
		}
	case 18:
		{
			LoadTestLineConfig("TESTTRACK18.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK18.INI");
			break;
		}
	case 19:
		{
			LoadTestLineConfig("TESTTRACK19.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK19.INI");
			break;
		}
	case 20:
		{
			LoadTestLineConfig("TESTTRACK20.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK20.INI");
			break;
		}
	case 21:
		{
			LoadTestLineConfig("TESTTRACK21.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK21.INI");
			break;
		}
	case 22:
		{
			LoadTestLineConfig("TESTTRACK22.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK22.INI");
			break;
		}
	case 23:
		{
			LoadTestLineConfig("TESTTRACK23.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK23.INI");
			break;
		}
	case 24:
		{
			LoadTestLineConfig("TESTTRACK24.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK24.INI");
			break;
		}
	case 25:
		{
			LoadTestLineConfig("TESTTRACK25.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK25.INI");
			break;
		}
	case 26:
		{
			LoadTestLineConfig("TESTTRACK26.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK26.INI");
			break;
		}
	case 27:
		{
			LoadTestLineConfig("TESTTRACK27.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK27.INI");
			break;
		}
	case 28:
		{
			LoadTestLineConfig("TESTTRACK28.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK28.INI");
			break;
		}
	case 29:
		{
			LoadTestLineConfig("TESTTRACK29.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK29.INI");
			break;
		}
	case 30:
		{
			LoadTestLineConfig("TESTTRACK30.INI");
			m_promptinfoshow.SetCString(8,"加载TESTTRACK30.INI");
			break;
		}
	}
}

void CMainFrame::OnButtonforbidapr() 
{
	// TODO: Add your command handler code here
	if (m_bSendAPR==TRUE)
	{
		m_bSendAPR=FALSE;
		m_promptinfoshow.SetCString(7,"禁止APR发送已启用!");
		m_promptinfoStatus.SetCString(6,"APR无效");
	} 
	else
	{
		m_bSendAPR=TRUE;
		m_promptinfoshow.SetCString(7,"禁止APR发送已撤销!");
		m_promptinfoStatus.SetCString(6,"APR有效");
	}
}

void CMainFrame::LoadTestLineConfig(CString m_strname)
{
	//读取摘要信息
	/*
	UINT GetPrivateProfileInt(
	LPCTSTR lpAppName,  // address of section name
		LPCTSTR lpKeyName,  // address of key name
		INT nDefault,       // return value if key name is not found
		LPCTSTR lpFileName  // address of initialization filename
		);
		DWORD GetPrivateProfileString(
		LPCTSTR lpAppName,        // points to section name
		LPCTSTR lpKeyName,        // points to key name
		LPCTSTR lpDefault,        // points to default string
		LPTSTR lpReturnedString,  // points to destination buffer
		DWORD nSize,              // size of destination buffer
		LPCTSTR lpFileName        // points to initialization filename
		);
		BOOL GetPrivateProfileStruct(
		LPCTSTR lpszSection,  // address of section name
		LPCTSTR lpszKey,      // address of key name
		LPVOID lpStruct,      // address of return buffer
		UINT uSizeStruct,     // size of return buffer
		LPCTSTR szFile        // address of initialization filename
		);
		BOOL WritePrivateProfileStruct(
		LPCTSTR lpszSection,// pointer to section name
		LPCTSTR lpszKey,  // pointer to key name
		LPVOID lpStruct,  // pointer to buffer that contains data to add
		UINT uSizeStruct, // size, in bytes, of the buffer
		LPCTSTR szFile    // pointer to initialization filename
		);

	*/
	CString m_strFilePath=TESTCONFIG_FILE_PATH;
	m_strFilePath+=m_strname;
	int m_ntracknumber=GetPrivateProfileInt("SUMMARY", "TOTAL",0, LPCSTR(m_strFilePath));


	//将读取数据写入当前内存中
	for (int i=1;i<=m_ntracknumber;i++)
	{
		CString m_strsectionname;
		m_strsectionname.Format("%d",i);
		m_strsectionname.Insert(0,"TRACK");
		CString m_strupdown,m_strtrackname,m_strapr,m_strcf;
		char m_charupdown[5],m_chartrackname[30],m_charapr[11],m_charcf[8];

		GetPrivateProfileString(m_strsectionname, "UPDOWN","", m_charupdown, 5,m_strFilePath);
		GetPrivateProfileString(m_strsectionname, "TRACKNAME","", m_chartrackname, 30,m_strFilePath);
		GetPrivateProfileString(m_strsectionname, "APR","", m_charapr, 11,m_strFilePath);
		GetPrivateProfileString(m_strsectionname, "CF","", m_charcf, 8,m_strFilePath);
		int	m_nsendcode=GetPrivateProfileInt(m_strsectionname, "TRACKCODE",0, LPCSTR(m_strFilePath));
		int m_naprpos=GetPrivateProfileInt(m_strsectionname, "APRPOS",0, LPCSTR(m_strFilePath));
		int m_nsecondcode=GetPrivateProfileInt(m_strsectionname, "SECONDCODE",0, LPCSTR(m_strFilePath));
		int m_nsecondcodepos=GetPrivateProfileInt(m_strsectionname, "SECONDCODEPOS",0, LPCSTR(m_strFilePath));
		m_strupdown=m_charupdown;
		m_strtrackname=m_chartrackname;
		m_strapr=m_charapr;
		m_strcf=m_charcf;
		if (m_strupdown=="上行")
		{
			for (int up=0;up<TRACKUP;up++)
			{
				if ((m_uptrack[up].m_Sname=="试车线")&&(m_uptrack[up].m_TSname==m_strtrackname))
				{
					if (m_strapr!="")
					{
						m_uptrack[up].m_NPAPRnumber=m_strapr;
					}
					if (m_strcf!="")
					{
						m_uptrack[up].m_CF=m_strcf;
					}
					if (m_nsendcode)
					{
						m_uptrack[up].m_SENDCODE=m_nsendcode;
					}
					if (m_naprpos)
					{
						m_uptrack[up].m_NPAPRpos=m_naprpos;
					}
					if (m_nsecondcode)
					{
						m_uptrack[up].m_SENDCODE2=m_nsecondcode;
					}
					if (m_nsecondcodepos)
					{
						m_uptrack[up].m_SENDCODE2pos=m_nsecondcodepos;
					}
					break;
				}
			}
		}
		else if (m_strupdown=="下行")
		{
			for (int down=0;down<TRACKDOWN;down++)
			{
				if ((m_downtrack[down].m_Sname=="试车线")&&(m_downtrack[down].m_TSname==m_strtrackname))
				{
					if (m_strapr!="")
					{
						m_downtrack[down].m_NPAPRnumber=m_strapr;
					}
					if (m_strcf!="")
					{
						m_downtrack[down].m_CF=m_strcf;
					}
					if (m_nsendcode)
					{
						m_downtrack[down].m_SENDCODE=m_nsendcode;
					}
					if (m_naprpos)
					{
						m_downtrack[down].m_NPAPRpos=m_naprpos;
					}
					if (m_nsecondcode)
					{
						m_downtrack[down].m_SENDCODE2=m_nsecondcode;
					}
					if (m_nsecondcodepos)
					{
						m_downtrack[down].m_SENDCODE2pos=m_nsecondcodepos;
					}
					break;
				}
			}
		}
		else
		{
			AfxMessageBox("读取配置文件错误!");
			break;
		}
	}
}

void CMainFrame::OnMenuebrecoder() 
{
	// TODO: Add your command handler code here
	if (m_bEBrecoder==FALSE)
	{
		CString m_str;
		m_str="准备记录首次EB位置!";
		m_promptinfoMailandV.SetCString(7,m_str);
		m_bEBrecoder=TRUE;
	}
}

BOOL CMainFrame::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	int m_nT=0;

	m_nT=zDelta/120;
	m_nGT+=m_nT;

	if (m_nGT>4)
	{
		m_nGT=4;
	}

	if (m_nGT<-8)
	{
		m_nGT=-8;
	}

	switch (m_nGT)
	{
	case 4:
		{
			OnMenud4();
			break;
		}
	case 3:
		{
			OnMenud3();
			break;
		}
	case 2:
		{
			OnMenud2();
			break;
		}
	case 1:
		{
			OnMenud1();
			break;
		}
	case 0:
		{
			OnMenunone();
			break;
		}
	case -1:
		{
			OnMenub1();
			break;
		}
	case -2:
		{
			OnMenub2();
			break;
		}
	case -3:
		{	
			OnMenub3();
			break;
		}
	case -4:
		{
			OnMenub4();
			break;
		}
	case -5:
		{
			OnMenub5();
			break;
		}
	case -6:
		{
			OnMenub6();
			break;
		}
	case -7:
		{
			OnMenub7();
			break;
		}
	case -8:
		{
			OnMenueb();
			break;
		}
	}

	return CFrameWnd::OnMouseWheel(nFlags, zDelta, pt);
}

void CMainFrame::OnRecodereb() 
{
	// TODO: Add your command handler code here
	OnMenuebrecoder();
}

void CMainFrame::OnButton840() 
{
	// TODO: Add your command handler code here
	OnMenuwheel840();
}

void CMainFrame::OnButton835() 
{
	// TODO: Add your command handler code here
	OnMenuwheel835();	
}

void CMainFrame::OnButton826() 
{
	// TODO: Add your command handler code here
	OnMenuwheel826();
}

void CMainFrame::OnButton818() 
{
	// TODO: Add your command handler code here
	OnMenuwheel818();
}

void CMainFrame::OnButton809() 
{
	// TODO: Add your command handler code here
	OnMenuwheel809();
}

void CMainFrame::OnButton800() 
{
	// TODO: Add your command handler code here
	OnMenuwheel800();
}

void CMainFrame::OnButton791() 
{
	// TODO: Add your command handler code here
	OnMenuwheel791();
}

void CMainFrame::OnButton783() 
{
	// TODO: Add your command handler code here
	OnMenuwheel783();
}

void CMainFrame::OnButton774() 
{
	// TODO: Add your command handler code here
	OnMenuwheel774();
}

void CMainFrame::OnMenuitempaprforbid() 
{
	// TODO: Add your command handler code here
	if (m_bForbidSendPAPR==FALSE)
	{
		m_bForbidSendPAPR=TRUE;
		m_promptinfoStatus.SetCString(7,"PAPR无效");
	}
	else
	{
		m_bForbidSendPAPR=FALSE;
		m_promptinfoStatus.SetCString(7,"PAPR有效");
	}
	
}

void CMainFrame::OnMenuitemsetpapr() 
{
	// TODO: Add your command handler code here
	CSetPAPR * m_dlgtrainset;
	m_dlgtrainset = new CSetPAPR();
	m_dlgtrainset->Create(IDD_DIALOGSETPAPR);
	m_dlgtrainset->ShowWindow(SW_SHOW);
}
