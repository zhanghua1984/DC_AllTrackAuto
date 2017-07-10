#if !defined(AFX_SETPAPR_H__32D226A4_C958_4EAD_A1B5_D227742B6663__INCLUDED_)
#define AFX_SETPAPR_H__32D226A4_C958_4EAD_A1B5_D227742B6663__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetPAPR.h : header file
//
#include "ALLTRACKAUTOSet.h"
/////////////////////////////////////////////////////////////////////////////
// CSetPAPR dialog
#include "TRACKCODECHANGE.h"
class CSetPAPR : public CDialog
{
// Construction
public:
	void Init();
	CSetPAPR(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetPAPR)
	enum { IDD = IDD_DIALOGSETPAPR };
	CEdit	m_cFilePath;
	CEdit	m_byte6;
	CEdit	m_byte5;
	CEdit	m_byte4;
	CEdit	m_byte3;
	CEdit	m_byte2;
	CEdit	m_byte1;
	CComboBox	m_cUpDown;
	CComboBox	m_cTrackName;
	CComboBox	m_cStationName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetPAPR)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetPAPR)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombostationname();
	afx_msg void OnButtonsave();
	afx_msg void OnSelchangeCombotrackname();
	afx_msg void OnButtonfileselect();
	afx_msg void OnButtonreadfile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETPAPR_H__32D226A4_C958_4EAD_A1B5_D227742B6663__INCLUDED_)
