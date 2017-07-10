// SpeedTable.cpp: implementation of the CSpeedTable class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "SpeedTable.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
extern CRect		m_rcClient;	;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSpeedTable::CSpeedTable()
{
	m_pHStart.x=0;
	m_pHStart.y=0;
	m_pHEnd.x=1440;
	m_pHEnd.y=0;
	m_pVStart.x=0;
	m_pVStart.y=0;
	m_pVEnd.x=0;
	m_pVEnd.y=200;
}

CSpeedTable::~CSpeedTable()
{

}

CSpeedTable::ShowSpeedTable(CDC* m_cdc)
{
	CPen m_trainpen;
	m_trainpen.CreatePen(PS_SOLID,1,RGB(160,32,240));
	m_cdc->SelectObject(&m_trainpen);

	CString m_strv;
	//ºáÊú¹Ì¶¨Öµ
	m_pHEnd.x=380;
	//H
	for (int i=0;i<200;i+=20)
	{
		m_pHStart.y=i;
		m_pHEnd.y=i;
		m_cdc->MoveTo(m_pHStart);
		m_cdc->LineTo(m_pHEnd);
		m_strv.Format("%d",(200-i)/AMPLIFICATORY_TIMES);
		m_cdc->TextOut(m_pHStart.x,m_pHStart.y,m_strv);
	}
	//V
	for (int j=0;j<400;j+=20)
	{
		m_pVStart.x=j;
		m_pVEnd.x=j;
		m_cdc->MoveTo(m_pVStart);
		m_cdc->LineTo(m_pVEnd);
	}
}
