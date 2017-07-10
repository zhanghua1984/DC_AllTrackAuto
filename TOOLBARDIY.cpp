// TOOLBARDIY.cpp : implementation file
//

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "TOOLBARDIY.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTOOLBARDIY

CTOOLBARDIY::CTOOLBARDIY()
{
}

CTOOLBARDIY::~CTOOLBARDIY()
{
}


BEGIN_MESSAGE_MAP(CTOOLBARDIY, CToolBar)
	//{{AFX_MSG_MAP(CTOOLBARDIY)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTOOLBARDIY message handlers
BOOL CTOOLBARDIY::CreateCombo(DWORD dwStyle,CComboBox *pComboBox,UINT nID,int nWidth,int nHeight)
{
	CRect pRect(-nWidth,-nHeight,0,0);
	pRect.right-=2;
	ASSERT(CommandToIndex(nID)>=0);
	SetButtonInfo(CommandToIndex(nID),nID,TBBS_SEPARATOR,nWidth);
	if (!pComboBox->Create(dwStyle,pRect,this,nID))
	{
		TRACE("Failed to create the combo-box %p .\n",nID);
		return FALSE;
	}
	GetItemRect(CommandToIndex(nID),&pRect);
	pRect.left+=2;
	pRect.right=pRect.left+nWidth;
	pComboBox->SetWindowPos(0,pRect.left,pRect.top,0,0,SWP_NOZORDER|SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOCOPYBITS);
	pComboBox->ShowWindow(SW_SHOW);

	return TRUE;
}
