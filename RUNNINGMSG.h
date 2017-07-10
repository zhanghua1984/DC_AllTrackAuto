#if !defined(AFX_RUNNINGMSG_H__147B4BF4_14B1_4508_9933_5BBE765AD6EC__INCLUDED_)
#define AFX_RUNNINGMSG_H__147B4BF4_14B1_4508_9933_5BBE765AD6EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RUNNINGMSG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRUNNINGMSG dialog

class CRUNNINGMSG : public CDialog
{
// Construction
public:
	CRUNNINGMSG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRUNNINGMSG)
	enum { IDD = IDD_DIALOGMSG };
	CListBox	m_clisttrackcode;
	CListBox	m_cliststatus;
	CListBox	m_clistpapr;
	CListBox	m_clistnpapr;
	CListBox	m_clisthd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRUNNINGMSG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRUNNINGMSG)
	virtual BOOL OnInitDialog();
	afx_msg void OnBstatusclear();
	afx_msg void OnBhdclear();
	afx_msg void OnBtcodeclear3();
	afx_msg void OnBnpaprclear();
	afx_msg void OnBpaprclear();
	afx_msg void OnBclearall();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RUNNINGMSG_H__147B4BF4_14B1_4508_9933_5BBE765AD6EC__INCLUDED_)
