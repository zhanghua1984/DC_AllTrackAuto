#if !defined(AFX_TRAINSET_H__AB5B2484_7A6F_4D9B_BC35_1D0931BF0A1E__INCLUDED_)
#define AFX_TRAINSET_H__AB5B2484_7A6F_4D9B_BC35_1D0931BF0A1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TRAINSET.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// TRAINSET dialog
#define WM_SETTRAINPOS	(WM_USER+113)
#define TRAINONTRACKHIGH	6
class TRAINSET : public CDialog
{
// Construction
public:
	TRAINSET(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(TRAINSET)
	enum { IDD = IDD_DIALOGTRAIN };
	CButton	m_cradio6che;
	CButton	m_cradio1che;
	CEdit	m_cconfigpath;
	CComboBox	m_cprioritygrowup;
	CComboBox	m_ccomboorigin;
	CComboBox	m_ccombohigh;
	CComboBox	m_ccombodefaulttrack;
	CString	m_strtrainoffsetpos;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TRAINSET)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TRAINSET)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnSettrainpos();
	afx_msg void OnHighconfirm();
	afx_msg void OnGrowupconfirm();
	afx_msg void OnReadconfig();
	afx_msg void OnRadio1();
	afx_msg void OnRadio6();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAINSET_H__AB5B2484_7A6F_4D9B_BC35_1D0931BF0A1E__INCLUDED_)
