#if !defined(AFX_TOOLBARDIY_H__172FF4B1_100D_4E64_9466_2AD777752498__INCLUDED_)
#define AFX_TOOLBARDIY_H__172FF4B1_100D_4E64_9466_2AD777752498__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// TOOLBARDIY.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTOOLBARDIY window

class CTOOLBARDIY : public CToolBar
{
// Construction
public:
	CTOOLBARDIY();

// Attributes
public:

// Operations
public:
	BOOL CreateCombo(DWORD dwStyle,CComboBox *pComboBox,UINT nID,int nWidth,int nHeight);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTOOLBARDIY)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTOOLBARDIY();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTOOLBARDIY)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLBARDIY_H__172FF4B1_100D_4E64_9466_2AD777752498__INCLUDED_)
