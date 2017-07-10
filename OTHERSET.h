#if !defined(AFX_OTHERSET_H__0361C6EF_76F8_4514_9976_0753B5CD3E91__INCLUDED_)
#define AFX_OTHERSET_H__0361C6EF_76F8_4514_9976_0753B5CD3E91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OTHERSET.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COTHERSET dialog
#include "Com.h"
#include "MACRO.h"

class COTHERSET : public CDialog
{
// Construction
public:
	void SendGapTime();
	COTHERSET(CWnd* pParent = NULL);   // standard constructor
	BOOL	m_bontime;
// Dialog Data
	//{{AFX_DATA(COTHERSET)
	enum { IDD = IDD_DIALOGOTHERSET };
	CComboBox	m_ccodefru;
	CComboBox	m_ccarryfru;
	CButton	m_ccheckontime;
	CButton	m_checkontime;
	CButton	m_checkkeepsend;
	CEdit	m_editgaptime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COTHERSET)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COTHERSET)
	virtual BOOL OnInitDialog();
	afx_msg void OnBsendtrackcode();
	afx_msg void OnCheckkeepsend();
	afx_msg void OnButtonstoppos();
	afx_msg void OnButtonsetspeed();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCheckontime();
	afx_msg void OnButtonsendontime();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OTHERSET_H__0361C6EF_76F8_4514_9976_0753B5CD3E91__INCLUDED_)
