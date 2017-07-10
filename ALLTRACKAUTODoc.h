// ALLTRACKAUTODoc.h : interface of the CALLTRACKAUTODoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ALLTRACKAUTODOC_H__7F61AD0F_CE40_404A_8F9F_27A0B84E0D99__INCLUDED_)
#define AFX_ALLTRACKAUTODOC_H__7F61AD0F_CE40_404A_8F9F_27A0B84E0D99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ALLTRACKAUTOSet.h"

class CALLTRACKAUTODoc : public COleDocument
{
protected: // create from serialization only
	CALLTRACKAUTODoc();
	DECLARE_DYNCREATE(CALLTRACKAUTODoc)

// Attributes
public:
	CALLTRACKAUTOSet m_aLLTRACKAUTOSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CALLTRACKAUTODoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CALLTRACKAUTODoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CALLTRACKAUTODoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CALLTRACKAUTODoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALLTRACKAUTODOC_H__7F61AD0F_CE40_404A_8F9F_27A0B84E0D99__INCLUDED_)
