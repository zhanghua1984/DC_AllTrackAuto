// APR.cpp: implementation of the APR class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "APR.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
extern COLORREF	m_colorgapr;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

APR::APR()
{
	m_paprts.x=0;
	m_paprts.y=0;
	m_fdapr=0;
	m_bup=TRUE;
}

APR::~APR()
{

}
APR::SetAPR(POINT m_pTstart,float m_faprd,BOOL m_up)
{
	m_paprts=m_pTstart;
	m_fdapr=m_faprd;
	m_bup=m_up;
}
APR::ShowAPR(CDC * m_pDC)
{
	POINT m_pAPR[4];
	m_pAPR[0]=m_paprts;
	switch (m_bup)
	{
	case TRUE:
		{
			m_pAPR[0].x=m_pAPR[0].x-(int)m_fdapr;
			break;
		}
	case FALSE:
		{
			m_pAPR[0].x=m_pAPR[0].x+(int)m_fdapr;
			break;
		}

	}	
	
	m_pAPR[0].y=m_pAPR[0].y+3;
	m_pAPR[3]=m_pAPR[0];
	m_pAPR[1].x=m_pAPR[0].x-5;
	m_pAPR[2].x=m_pAPR[0].x+5;
	m_pAPR[1].y=m_pAPR[0].y+8;
	m_pAPR[2].y=m_pAPR[1].y;
	CPen m_pen(PS_SOLID,1,m_colorgapr);
	CPen* m_oldpen;
	m_oldpen = m_pDC->SelectObject((CPen*)&m_pen);
	m_pDC->Polyline(m_pAPR,4);
	m_pDC->SelectObject(m_oldpen);
}