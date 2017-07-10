// SpeedLine.cpp: implementation of the SpeedLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "SpeedLine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
extern m_nTrackView;
extern POINT m_pTrainpos;
extern m_bViewOn;
extern CRect m_rcClient;
SpeedLine::SpeedLine()
{
	for (int i=0;i<POINTNUMBER*AMPLIFICATORY_TIMES;i++)
	{
		m_pHeadSpeed[i].x=i;
		m_pHeadSpeed[i].y=0;
		m_pTailSpeed[i].x=i;
		m_pTailSpeed[i].y=0;
	}
}

SpeedLine::~SpeedLine()
{

}
SpeedLine::ShowLine(CDC * pCDC,int m_n)
{
	CPen m_headpen,m_tailpen;
	m_headpen.CreatePen(PS_SOLID,2,RGB(0,191,255));
	m_tailpen.CreatePen(PS_SOLID,2,RGB(238,130,238));
	
	
	for (int i=0;i<POINTNUMBER*AMPLIFICATORY_TIMES;i++)
	{
		if ((i-m_nTrackView>0)&&(i-m_nTrackView<m_rcClient.Width()))
		{
			if (m_bViewOn==TRUE)
			{
				if (i!=POINTNUMBER*AMPLIFICATORY_TIMES-1)
				{
					if ((m_pHeadSpeed[i].y!=0)&&(m_pHeadSpeed[i].x)&&(m_pHeadSpeed[i+1].x)&&(m_pHeadSpeed[i+1].y))
					{
						pCDC->SelectObject(&m_headpen);
						pCDC->MoveTo(m_pHeadSpeed[i].x-m_nTrackView,SPEEDLINEHIGH-m_pHeadSpeed[i].y);
						pCDC->LineTo(m_pHeadSpeed[i+1].x-m_nTrackView,SPEEDLINEHIGH-m_pHeadSpeed[i+1].y);	
					}
					if ((m_pTailSpeed[i].y!=0)&&(m_pTailSpeed[i].x!=0)&&(m_pTailSpeed[i+1].y)&&(m_pTailSpeed[i+1].x))
					{
						pCDC->SelectObject(&m_tailpen);
						pCDC->MoveTo(m_pTailSpeed[i].x-m_nTrackView,SPEEDLINEHIGH-m_pTailSpeed[i].y);
						pCDC->LineTo(m_pTailSpeed[i+1].x-m_nTrackView,SPEEDLINEHIGH-m_pTailSpeed[i+1].y);
					}
				} 
			} 
			else
			{
				if (i!=POINTNUMBER*AMPLIFICATORY_TIMES-1)
				{
					pCDC->SelectObject(&m_headpen);
					pCDC->MoveTo(m_pHeadSpeed[i].x-m_nTrackView,SPEEDLINEHIGH-m_pHeadSpeed[i].y);
					pCDC->LineTo(m_pHeadSpeed[i+1].x-m_nTrackView,SPEEDLINEHIGH-m_pHeadSpeed[i+1].y);
					
					pCDC->SelectObject(&m_tailpen);
					pCDC->MoveTo(m_pTailSpeed[i].x-m_nTrackView,SPEEDLINEHIGH-m_pTailSpeed[i].y);
					pCDC->LineTo(m_pTailSpeed[i+1].x-m_nTrackView,SPEEDLINEHIGH-m_pTailSpeed[i+1].y);
				} 
			}

		}
	}
	m_headpen.DeleteObject();
	m_tailpen.DeleteObject();
}


SpeedLine::SetSpeed(LONG x,LONG y)
{

	m_pHeadSpeed[x].x=x;
	m_pHeadSpeed[x].y=y;
	
	m_pTailSpeed[x].x=x-118*AMPLIFICATORY_TIMES;
	m_pTailSpeed[x].y=y;
}