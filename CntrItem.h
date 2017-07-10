// CntrItem.h : interface of the CALLTRACKAUTOCntrItem class
//

#if !defined(AFX_CNTRITEM_H__3832D077_A8B7_42E3_87EF_5EB9C012ABA6__INCLUDED_)
#define AFX_CNTRITEM_H__3832D077_A8B7_42E3_87EF_5EB9C012ABA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CALLTRACKAUTODoc;
class CALLTRACKAUTOView;

class CALLTRACKAUTOCntrItem : public COleClientItem
{
	DECLARE_SERIAL(CALLTRACKAUTOCntrItem)

// Constructors
public:
	CALLTRACKAUTOCntrItem(CALLTRACKAUTODoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CALLTRACKAUTODoc* GetDocument()
		{ return (CALLTRACKAUTODoc*)COleClientItem::GetDocument(); }
	CALLTRACKAUTOView* GetActiveView()
		{ return (CALLTRACKAUTOView*)COleClientItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CALLTRACKAUTOCntrItem)
	public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();
	protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	//}}AFX_VIRTUAL

// Implementation
public:
	~CALLTRACKAUTOCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRITEM_H__3832D077_A8B7_42E3_87EF_5EB9C012ABA6__INCLUDED_)
