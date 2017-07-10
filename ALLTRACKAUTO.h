// ALLTRACKAUTO.h : main header file for the ALLTRACKAUTO application
//

#if !defined(AFX_ALLTRACKAUTO_H__2850F764_61FE_4052_81AF_7B70D81CBFD1__INCLUDED_)
#define AFX_ALLTRACKAUTO_H__2850F764_61FE_4052_81AF_7B70D81CBFD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CALLTRACKAUTOApp:
// See ALLTRACKAUTO.cpp for the implementation of this class
//

class CALLTRACKAUTOApp : public CWinApp
{
public:
	CALLTRACKAUTOApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CALLTRACKAUTOApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation
	//{{AFX_MSG(CALLTRACKAUTOApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALLTRACKAUTO_H__2850F764_61FE_4052_81AF_7B70D81CBFD1__INCLUDED_)
