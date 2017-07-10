#if !defined(AFX_SETHD_H__147A4E8D_4566_4C9E_AC9C_3FA0C049B4C6__INCLUDED_)
#define AFX_SETHD_H__147A4E8D_4566_4C9E_AC9C_3FA0C049B4C6__INCLUDED_
#include "MACRO.h"
#include "Com.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SETHD.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSETHD dialog

class CSETHD : public CDialog
{
// Construction
public:
	void PostMessageToView();
	void ReadShow();
	CSETHD(CWnd* pParent = NULL);   // standard constructor
	MACRO	m_macroinsethd;
// Dialog Data
	//{{AFX_DATA(CSETHD)
	enum { IDD = IDD_DIALOGHD };
	CButton	m_ccheckdopulnone;
	CButton	m_ccheckdopulfault;
	CButton	m_ccheckdopuldata;
	CButton	m_ccheckreadererr;
	CButton	m_cchecktechop2;
	CButton	m_cchecktechop1;
	CButton	m_cchecktech2;
	CButton	m_cchecktech1;
	CButton	m_ccheckr9;
	CButton	m_ccheckr8;
	CButton	m_ccheckr7;
	CButton	m_ccheckr6;
	CButton	m_ccheckr5;
	CButton	m_ccheckr4;
	CButton	m_ccheckr3;
	CButton	m_ccheckr2;
	CButton	m_ccheckr16;
	CButton	m_ccheckr15;
	CButton	m_ccheckr14;
	CButton	m_ccheckr13;
	CButton	m_ccheckr12;
	CButton	m_ccheckr11;
	CButton	m_ccheckr10;
	CButton	m_ccheckr1;
	CButton	m_ccheckfskmod;
	CButton	m_ccheckfsk2;
	CButton	m_ccheckfsk1;
	CButton	m_ccheckatp2;
	CButton	m_ccheckato;
	CButton	m_ccheckatp1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSETHD)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSETHD)
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckato();
	afx_msg void OnCheckatp1();
	afx_msg void OnCheckatp2();
	afx_msg void OnChecktechop1();
	afx_msg void OnChecktechop2();
	afx_msg void OnChecktech1();
	afx_msg void OnChecktech2();
	afx_msg void OnCheckfsk1();
	afx_msg void OnCheckfsk2();
	afx_msg void OnCheckfskmod();
	afx_msg void OnCheckrelay1();
	afx_msg void OnCheckrelay2();
	afx_msg void OnCheckrelay3();
	afx_msg void OnCheckrelay4();
	afx_msg void OnCheckrelay5();
	afx_msg void OnCheckrelay6();
	afx_msg void OnCheckrelay7();
	afx_msg void OnCheckrelay8();
	afx_msg void OnCheckrelay9();
	afx_msg void OnCheckrelay10();
	afx_msg void OnCheckrelay11();
	afx_msg void OnCheckrelay12();
	afx_msg void OnCheckrelay13();
	afx_msg void OnCheckrelay14();
	afx_msg void OnCheckrelay15();
	afx_msg void OnCheckrelay16();
	afx_msg void OnCheckreadererr();
	afx_msg void OnCheckdopuldata();
	afx_msg void OnCheckdopulfnone();
	afx_msg void OnCheckdopulffault();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETHD_H__147A4E8D_4566_4C9E_AC9C_3FA0C049B4C6__INCLUDED_)
