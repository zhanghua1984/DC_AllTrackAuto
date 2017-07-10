#if !defined(AFX_SETVIEW_H__B74628BE_6E2F_480B_AE6A_C1E29DC47F07__INCLUDED_)
#define AFX_SETVIEW_H__B74628BE_6E2F_480B_AE6A_C1E29DC47F07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Setview.h : header file
//
#define WM_MY_DLGUPDATEVIEW (WM_USER+100)
/////////////////////////////////////////////////////////////////////////////
// CSetview dialog

class CSetview : public CDialog
{
// Construction
public:
	void PostMessageToView();
	CSetview(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetview)
	enum { IDD = IDD_DIALOGVIEW };
	CScrollBar	m_cscrollbar;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetview)
	public:
	virtual CScrollBar* GetScrollBarCtrl(int nBar) const;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetview)
	afx_msg void OnDestroy();
	afx_msg void OnSet();
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnOutofmemorySpinselectstation(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETVIEW_H__B74628BE_6E2F_480B_AE6A_C1E29DC47F07__INCLUDED_)
