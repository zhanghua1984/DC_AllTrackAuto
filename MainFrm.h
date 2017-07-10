// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__67177316_9591_4C2D_9CA1_AEC88C8DDAC4__INCLUDED_)
#define AFX_MAINFRM_H__67177316_9591_4C2D_9CA1_AEC88C8DDAC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Setview.h"
#include "RUNNINGMSG.h"
#include "OTHERSET.h"
#include "SHOWMSG.h"
#include "MACRO.h"
#include "SETHD.h"
#include "TOOLBARDIY.h"
#include "PROMPTINFO.h"
#include "DIALOGCARRAYTEST.h"
#include "TRACKCODECHANGE.h"
#include "Train.h"
#include "TRAINSET.h"
#include "alldefine.h"
#include "SetPAPR.h"
#define WM_CLEARFLAG	(WM_USER+107)
#define WM_SAVETURNPOS	(WM_USER+108)
#define WM_AUTOSTOP		(WM_USER+110)
#define WM_TARGETSPEED	(WM_USER+111)
#define VK_0	0x30

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	double m_dacc;
	float m_ftargetspeed;

// Operations
public:
	CStatusBar  m_wndStatusBar;
	CStatusBar  m_wndStatusBar1;
	CStatusBar  m_wndStatusBar2;
	CToolBar    m_wndToolBar;
	CTOOLBARDIY	m_wndToolBardiy;
	CString		m_strDriverLevel;
	CComboBox	m_pCombo;
	CComboBox	m_pCombotest;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetTargetSpeed(float targets,float currs);
	void ToGetTargetSpeed(float targets,float currs);
	void MainFrameInit();
	void Acceleration(double m_acc);
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	BOOL m_bEBrecoder;

// Generated message map functions
public:
	void LoadTestLineConfig(CString m_strname);
	void Ebtotargetspeed(float m_targetspeed);
	BOOL IsSaveTurnPos(int m_nchangestype);
	void SendSaveTurnPosMsg();
	void ClearFlag();
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMenusetview();
	afx_msg void OnMenueb();
	afx_msg void OnMenub1();
	afx_msg void OnMenub2();
	afx_msg void OnMenub3();
	afx_msg void OnMenub4();
	afx_msg void OnMenub5();
	afx_msg void OnMenub6();
	afx_msg void OnMenub7();
	afx_msg void OnMenud1();
	afx_msg void OnMenud2();
	afx_msg void OnMenud3();
	afx_msg void OnMenud4();
	afx_msg void OnMenunone();
	afx_msg void OnMenudirforward();
	afx_msg void OnMenudir0();
	afx_msg void OnMenudirback();
	afx_msg void OnMenuhead();
	afx_msg void OnMenutrail();
	afx_msg void OnMenupc();
	afx_msg void OnMenudc();
	afx_msg void OnMenuviewontrain();
	afx_msg void OnMenuviewontrack();
	afx_msg void OnMenurunningmsg();
	afx_msg void OnMenuwheel840();
	afx_msg void OnMenuwheel835();
	afx_msg void OnMenuwheel826();
	afx_msg void OnMenuwheel818();
	afx_msg void OnMenuwheel809();
	afx_msg void OnMenuwheel800();
	afx_msg void OnMenuwheel791();
	afx_msg void OnMenuwheel783();
	afx_msg void OnMenuwheel774();
	afx_msg void OnMenuotherset();
	afx_msg void OnClose();
	afx_msg void OnMenuhd();
	afx_msg void OnMenuup();
	afx_msg void OnMenudown();
	afx_msg void OnMenuitemreturn();
	afx_msg void OnMenuitemnoreturn();
	afx_msg void OnSetSpeed();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMenucolorline();
	afx_msg void OnMenucolorfont();
	afx_msg void OnMenucolorapr();
	afx_msg void OnMenuCarrayfruchange();
	afx_msg void OnShowCalculate();
	afx_msg	void OnShowDebug();
	afx_msg	void OnShowReturn3();
	afx_msg	void OnShowReturn2();
	afx_msg	void OnShowReturn1();
	afx_msg	void OnShowAuto();
	afx_msg	void OnShowHandle();
	afx_msg void OnMenucarraytest();
	afx_msg void OnMenutrackcode();
	afx_msg void OnMenuDisableFSB();
	afx_msg void OnMenuDisableEB();
	afx_msg void OnMenutrain();
	afx_msg void OnMenuhead1();
	afx_msg void OnMenutail1();
	afx_msg void OnMenudatabase1();
	afx_msg void OnMenudatabase6();
	afx_msg void OnAutostop();
	afx_msg void OnButtontestlinefuction();
	afx_msg void OnButtonforbidapr();
	afx_msg void OnMenuebrecoder();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnRecodereb();
	afx_msg void OnButton840();
	afx_msg void OnButton835();
	afx_msg void OnButton826();
	afx_msg void OnButton818();
	afx_msg void OnButton809();
	afx_msg void OnButton800();
	afx_msg void OnButton791();
	afx_msg void OnButton783();
	afx_msg void OnButton774();
	afx_msg void OnMenuitempaprforbid();
	afx_msg void OnMenuitemsetpapr();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__67177316_9591_4C2D_9CA1_AEC88C8DDAC4__INCLUDED_)
