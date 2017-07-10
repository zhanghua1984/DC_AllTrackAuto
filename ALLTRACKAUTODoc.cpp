// ALLTRACKAUTODoc.cpp : implementation of the CALLTRACKAUTODoc class
//

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "ALLTRACKAUTOSet.h"
#include "ALLTRACKAUTODoc.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CALLTRACKAUTODoc

IMPLEMENT_DYNCREATE(CALLTRACKAUTODoc, COleDocument)

BEGIN_MESSAGE_MAP(CALLTRACKAUTODoc, COleDocument)
	//{{AFX_MSG_MAP(CALLTRACKAUTODoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, COleDocument::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, COleDocument::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, COleDocument::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, COleDocument::OnEditConvert)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, COleDocument::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, COleDocument::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, COleDocument::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CALLTRACKAUTODoc, COleDocument)
	//{{AFX_DISPATCH_MAP(CALLTRACKAUTODoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IALLTRACKAUTO to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {56CAF5A2-007C-48D8-A769-1A9A7A0DAF13}
static const IID IID_IALLTRACKAUTO =
{ 0x56caf5a2, 0x7c, 0x48d8, { 0xa7, 0x69, 0x1a, 0x9a, 0x7a, 0xd, 0xaf, 0x13 } };

BEGIN_INTERFACE_MAP(CALLTRACKAUTODoc, COleDocument)
	INTERFACE_PART(CALLTRACKAUTODoc, IID_IALLTRACKAUTO, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CALLTRACKAUTODoc construction/destruction

CALLTRACKAUTODoc::CALLTRACKAUTODoc()
{
	// Use OLE compound files
	EnableCompoundFile();

	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();


}

CALLTRACKAUTODoc::~CALLTRACKAUTODoc()
{
	AfxOleUnlockApp();
}

BOOL CALLTRACKAUTODoc::OnNewDocument()
{
	if (!COleDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CALLTRACKAUTODoc serialization

void CALLTRACKAUTODoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}

	// Calling the base class COleDocument enables serialization
	//  of the container document's COleClientItem objects.
	COleDocument::Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CALLTRACKAUTODoc diagnostics

#ifdef _DEBUG
void CALLTRACKAUTODoc::AssertValid() const
{
	COleDocument::AssertValid();
}

void CALLTRACKAUTODoc::Dump(CDumpContext& dc) const
{
	COleDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CALLTRACKAUTODoc commands
