// STOPFLAG.cpp: implementation of the STOPFLAG class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "STOPFLAG.h"
#include "alldefine.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

STOPFLAG::STOPFLAG()
{
	m_pstart.x=0;
	m_pstart.y=0;
	m_fflag=0;
	m_bup=FALSE;
}

STOPFLAG::~STOPFLAG()
{

}
STOPFLAG::SetFlag(POINT m_pTstart,float m_fTflag,BOOL m_up)
{
	m_pstart=m_pTstart;
	m_fflag=m_fTflag;
	m_bup=m_up;
}
STOPFLAG::ShowAPR(CDC * m_pDC)
{
	POINT m_pFLAG[5];
	switch (m_bup)
	{
	case TRUE:
		{
			m_pFLAG[0].x=m_pstart.x-(int)m_fflag;
			m_pFLAG[0].y=m_pstart.y+PTOTRACK/2;
			m_pFLAG[1]=m_pFLAG[0];
			m_pFLAG[4]=m_pFLAG[0];
			m_pFLAG[1].x+=STOPFLAGLENTH;
			m_pFLAG[2]=m_pFLAG[1];
			m_pFLAG[2].y+=STOPFLAGLENTH;
			m_pFLAG[3]=m_pFLAG[0];
			m_pFLAG[3].y+=STOPFLAGLENTH;
			break;
		}
	case FALSE:
		{
			m_pFLAG[0].x=m_pstart.x+(int)m_fflag;
			m_pFLAG[0].y=m_pstart.y-PTOTRACK;
			m_pFLAG[1]=m_pFLAG[0];
			m_pFLAG[4]=m_pFLAG[0];
			m_pFLAG[1].x+=STOPFLAGLENTH;
			m_pFLAG[2]=m_pFLAG[1];
			m_pFLAG[2].y+=STOPFLAGLENTH;
			m_pFLAG[3]=m_pFLAG[0];
			m_pFLAG[3].y+=STOPFLAGLENTH;
			break;
		}
		
	}	
	
	CPen m_pen(PS_SOLID,1,RGB(180,180,80));
	CPen* m_oldpen;
	m_oldpen = m_pDC->SelectObject((CPen*)&m_pen);
	m_pDC->Polyline(m_pFLAG,5);
	m_pDC->TextOut(m_pFLAG[0].x+STOPFLAGLENTH/4,m_pFLAG[0].y+STOPFLAGLENTH/8,"P");
	m_pDC->SelectObject(m_oldpen);
}