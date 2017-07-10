// ALLTRACKAUTOView.h : interface of the CALLTRACKAUTOView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ALLTRACKAUTOVIEW_H__6C0F8C84_AE1C_4C07_804C_21C8FF627939__INCLUDED_)
#define AFX_ALLTRACKAUTOVIEW_H__6C0F8C84_AE1C_4C07_804C_21C8FF627939__INCLUDED_


#include "Station.h"
#include "Train.h"
#include "Com.h"
#include "SpeedLine.h"
#include "SpeedTable.h"
#include "SHOWMSG.h"
#include "MACRO.h"
#include "TRACKCODE.h"
#include "PROMPTINFO.h"
#include "TRACKCODECHANGE.h"
#include "ANTENNA.h"
#include "READER.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000 

#define WM_LOADALLTRACK WM_USER+1
#define WM_MY_DLGUPDATEVIEW (WM_USER+100)
#define WM_UC_MESSAGE (WM_USER+101)
#define WM_SEEKTRACKDATA (WM_USER+103)
#define WM_UC_WRITE	(WM_USER+102)
#define WM_NEXTTRACK	(WM_USER+104)
#define WM_SEEKISSENDAPR	(WM_USER+105)
#define WM_NEXTAPR	(WM_USER+106)
#define WM_CLEARFLAG	(WM_USER+107)
#define WM_SAVETURNPOS	(WM_USER+108)
#define WM_SENDCURRENTTRACKCODE	(WM_USER+109)
#define WM_AUTOSTOP	(WM_USER+110)
#define WM_TARGETSPEED	(WM_USER+111)
#define WM_SENDSECONDCODE	(WM_USER+112)
#define WM_SETTRAINPOS	(WM_USER+113)
#define TRAINLENTH	118
#define TRACKUP	355
#define TRACKDOWN 340	
#define TRAINTOTRACK	6
#define SENDAPRDISTANCE 10
#define SENDTRACKCODE	10
#define SHOWMSGPOS	200
#define SHOWMSGGAP	200
#define TRACKNUMBER 693
#define ALLTRACKLENTH	40914*2
#define VIEWMODIFY		1450
#define TRACKHIGHDIS	12		//轨道高度差容值
#define CONFIG_FILE_PATH ".\\CONFIG.INI"
#define RECTTRACKTOP	0
#define RECTTRACKBOTTEM	520
#define SHOWMSGBASEPOS	400

class CALLTRACKAUTOCntrItem;
class CALLTRACKAUTOSet;

//线程函数声明
UINT ThreadLoadingTrack(LPVOID lpParam);
UINT ThreadSeekTrackData(LPVOID lpParam);
UINT ThreadISSendAPR(LPVOID lpParam);
UINT ThreadISSendSecondCode(LPVOID lpParam);

class CALLTRACKAUTOView : public CRecordView
{
protected: // create from serialization only
	CALLTRACKAUTOView();
	DECLARE_DYNCREATE(CALLTRACKAUTOView)

public:
	//{{AFX_DATA(CALLTRACKAUTOView)
	enum{ IDD = IDD_ALLTRACKAUTO_FORM };
	CALLTRACKAUTOSet* m_pSet;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
	CWinThread* pThread;
	CWinThread* pThreadSeek;
	CWinThread* pThreadAPR;
	CWinThread* pThreadSCode;
	
public:
	CALLTRACKAUTODoc* GetDocument();
	// m_pSelection holds the selection to the current CALLTRACKAUTOCntrItem.
	// For many applications, such a member variable isn't adequate to
	//  represent a selection, such as a multiple selection or a selection
	//  of objects that are not CALLTRACKAUTOCntrItem objects.  This selection
	//  mechanism is provided just to help you get started.

	// TODO: replace this selection mechanism with one appropriate to your app.
	CALLTRACKAUTOCntrItem* m_pSelection;


	int		m_noldmail;
	BYTE	m_byteCom90[24];
	BOOL	m_bReverse;
	BOOL	m_bHardwareReset;
	CRect	m_recttrack;

// Operations
public:
	CString m_strmsgstatus;
	CString m_strmsghd;
	CString m_strmsgtrackcode;
	CString m_strmsgnpapr;
	CString m_strmsgpapr;
	//串口相关变量和函数开始
	
	CString m_strshowRX;
	void InitFrame();
	void Init();
	LRESULT OnThreadRXMessage(WPARAM wParam,LPARAM lParam);
	
	//串口相关变量和函数结束

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CALLTRACKAUTOView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Container support
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
public:
	void InitOtherAfter5Second();
	BYTE RightMove(byte m_bytedata,byte m_bytepos,byte m_bytemn);
	BOOL JudgeBit(byte m_bytedata,byte m_bit);
	void FrameParse();
	int STRCFtoINTCF(CString m_strcf);
	LRESULT SendOnTimeCode(int m_cf,int m_code);
	BOOL CheckIsBreak();
	void LoadConfig();
	void FindTrackofTrain(float m_fantennapos);
	void CalculateTrainPos();
	BOOL m_bAlreadyClear;
	void ClearFlagsForReset();
	void WriteRecoder(CString m_strtowr);
	void Reader();
	void SoftVersion();
	void Relay();
	void Healthy();
	byte CirclePickQN();
	byte BackGear();
	void BackStatus();
	double Speed();
	bool MilemeterDir();
	double Mail();
	void TrainStatus();
	void MandV();
	void GlobalInit();
	LRESULT OnThreadMessage(WPARAM wParam,LPARAM lParam);
	LRESULT OnThreadSendCode(WPARAM wParam,LPARAM lParam);
	LRESULT OnThreadSendAPR(WPARAM wParam,LPARAM lParam);
	virtual ~CALLTRACKAUTOView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CALLTRACKAUTOView)
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg LRESULT OnMyDLGMessage(WPARAM wParam, LPARAM lParam); 
	afx_msg LRESULT OnMyCOMMessage(WPARAM wParam, LPARAM lParam); 
	afx_msg LRESULT OnMyCOMWrite(WPARAM wParam, LPARAM lParam); 
	afx_msg LRESULT OnMyClearFlag(WPARAM wParam, LPARAM lParam); 
	afx_msg LRESULT OnMySaveTurnPos(WPARAM wParam, LPARAM lParam); 
	afx_msg LRESULT OnMyAutoStop(WPARAM wParam, LPARAM lParam); 
	afx_msg LRESULT OnMyOnTargetSpeed(WPARAM wParam, LPARAM lParam); 
	afx_msg LRESULT OnMySendCurrentTrackCode(WPARAM wParam, LPARAM lParam); 
	afx_msg LRESULT OnMySendSecondTrackCode(WPARAM wParam, LPARAM lParam); 
	afx_msg LRESULT OnResetTrainPos(WPARAM wParam, LPARAM lParam); 
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	afx_msg LRESULT OnReceiveAComPort(WPARAM wParam, LPARAM lParam); 
	afx_msg LRESULT OnWriteComPortMSG(WPARAM wParam, LPARAM lParam); 

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ALLTRACKAUTOView.cpp
inline CALLTRACKAUTODoc* CALLTRACKAUTOView::GetDocument()
   { return (CALLTRACKAUTODoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALLTRACKAUTOVIEW_H__6C0F8C84_AE1C_4C07_804C_21C8FF627939__INCLUDED_)
