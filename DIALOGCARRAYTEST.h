#if !defined(AFX_DIALOGCARRAYTEST_H__54CC87A7_BFB7_49F5_99D3_D33E4A777F9F__INCLUDED_)
#define AFX_DIALOGCARRAYTEST_H__54CC87A7_BFB7_49F5_99D3_D33E4A777F9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// DIALOGCARRAYTEST.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DIALOGCARRAYTEST dialog

class DIALOGCARRAYTEST : public CDialog
{
// Construction
public:
	void UpDataShow();
	DIALOGCARRAYTEST(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DIALOGCARRAYTEST)
	enum { IDD = IDD_DIALOGCARRAYTEST };
	CString	m_strtest1;
	CString	m_strtest10;
	CString	m_strtest11;
	CString	m_strtest12;
	CString	m_strtest13;
	CString	m_strtest14;
	CString	m_strtest15;
	CString	m_strtest16;
	CString	m_strtest17;
	CString	m_strtest18;
	CString	m_strtest19;
	CString	m_strtest2;
	CString	m_strtest20;
	CString	m_strtest21;
	CString	m_strtest22;
	CString	m_strtest23;
	CString	m_strtest24;
	CString	m_strtest25;
	CString	m_strtest26;
	CString	m_strtest27;
	CString	m_strtest28;
	CString	m_strtest29;
	CString	m_strtest3;
	CString	m_strtest30;
	CString	m_strtest31;
	CString	m_strtest32;
	CString	m_strtest33;
	CString	m_strtest34;
	CString	m_strtest35;
	CString	m_strtest36;
	CString	m_strtest37;
	CString	m_strtest38;
	CString	m_strtest39;
	CString	m_strtest4;
	CString	m_strtest40;
	CString	m_strtest5;
	CString	m_strtest6;
	CString	m_strtest7;
	CString	m_strtest8;
	CString	m_strtest9;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DIALOGCARRAYTEST)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DIALOGCARRAYTEST)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGCARRAYTEST_H__54CC87A7_BFB7_49F5_99D3_D33E4A777F9F__INCLUDED_)
