#if !defined(AFX_TRACKCODECHANGE_H__13FF15C4_CE28_4221_8D04_F7C467D55F13__INCLUDED_)
#define AFX_TRACKCODECHANGE_H__13FF15C4_CE28_4221_8D04_F7C467D55F13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TRACKCODECHANGE.h : header file
//
#include "ALLTRACKAUTOSet.h"
/////////////////////////////////////////////////////////////////////////////
// TRACKCODECHANGE dialog
#define TRACKUP	355
#define TRACKDOWN 340	

class TRACKCODECHANGE : public CDialog
{
// Construction
public:
	BOOL m_btracknameselected;
	BOOL m_bstationselected;
	CString GetTrackCode();
	CString GetCF();
	int m_npoint;
	BOOL m_bup;
	int m_ncounterwriter;
	CString m_strfilepath;
	TRACKCODECHANGE(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(TRACKCODECHANGE)
	enum { IDD = IDD_DIALOGTRACKCODECHANGE };
	CComboBox	m_cupdown;
	CComboBox	m_ctrackname;
	CComboBox	m_cstation;
	CComboBox	m_ccodefru;
	CComboBox	m_ccarrayfru;
	CString	m_strfilepos;
	CString	m_stroriginallycarray;
	CString	m_stroriginallycode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TRACKCODECHANGE)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TRACKCODECHANGE)
	afx_msg void OnButtonread();
	afx_msg void OnButtonchange();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboupdown();
	afx_msg void OnSelchangeCombostation();
	afx_msg void OnSelchangeCombotrackname();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRACKCODECHANGE_H__13FF15C4_CE28_4221_8D04_F7C467D55F13__INCLUDED_)
