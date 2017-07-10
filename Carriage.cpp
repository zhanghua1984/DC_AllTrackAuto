// Carriage.cpp: implementation of the CCarriage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "Carriage.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCarriage::CCarriage()
{
	m_fcarriagelenth=19*AMPLIFICATORY_TIMES;
	m_fcarriagehigh=(FLOAT)3.695*AMPLIFICATORY_TIMES;
	m_ncarriagestyle=0;
	m_ncarriageangle=0;
	m_pcarriagepos.x=720;
	m_pcarriagepos.y=200;
	m_carriagewheel[0].Setwheelpos((FLOAT)(m_pcarriagepos.x-7.856),(FLOAT)(m_pcarriagepos.y-0.844));
	m_carriagewheel[1].Setwheelpos((FLOAT)(m_pcarriagepos.x-6.421),(FLOAT)(m_pcarriagepos.y-0.844));
	m_carriagewheel[2].Setwheelpos((FLOAT)(m_pcarriagepos.x+7.856),(FLOAT)(m_pcarriagepos.y-0.844));
	m_carriagewheel[3].Setwheelpos((FLOAT)(m_pcarriagepos.x+6.421),(FLOAT)(m_pcarriagepos.y-0.844));
	m_strCarriageName="test";
	m_bDirector=FALSE;
}

CCarriage::~CCarriage()
{

}
CCarriage::Showcarriage(CDC* pDC,int m_number)
{
	//车厢号
	m_number=6-m_number;
	CString m_str;
	m_str.Format("%d",m_number);
	switch (this->m_ncarriagestyle)
	{
	case 0:
		{
			POINT m_ptrain[5];
			m_ptrain[0].x=(int)(m_pcarriagepos.x-(CARRIAGELENTH/2)*AMPLIFICATORY_TIMES);
			m_ptrain[0].y=m_pcarriagepos.y;
			m_ptrain[1].x=(int)(m_ptrain[0].x+m_fcarriagelenth);
			m_ptrain[1].y=m_ptrain[0].y;
			m_ptrain[2].x=m_ptrain[1].x;
			m_ptrain[2].y=(int)(m_ptrain[1].y-m_fcarriagehigh);
			m_ptrain[3].x=(int)(m_ptrain[2].x-m_fcarriagelenth);
			m_ptrain[3].y=m_ptrain[2].y;
			m_ptrain[4]=m_ptrain[0];
			pDC->Polyline(m_ptrain,5);
			pDC->TextOut(m_ptrain[0].x+XMODIFY,m_ptrain[0].y-YMODIFY,m_str);

			break;
		}
		//根据车厢样式显示
	case 1:
		{
			POINT m_ptrain[5];
			m_ptrain[0].x=(int)(m_pcarriagepos.x-(HEADTAILLENTH/2)*AMPLIFICATORY_TIMES);
			m_ptrain[0].y=m_pcarriagepos.y;
			m_ptrain[1].x=(int)(m_ptrain[0].x+m_fcarriagelenth);
			m_ptrain[1].y=m_ptrain[0].y;
			m_ptrain[2].x=m_ptrain[1].x;
			m_ptrain[2].y=(int)(m_ptrain[1].y-m_fcarriagehigh);
			m_ptrain[3].x=(int)(m_ptrain[2].x-m_fcarriagelenth);
			m_ptrain[3].y=m_ptrain[2].y;
			m_ptrain[4]=m_ptrain[0];
			pDC->Polyline(m_ptrain,5);
			pDC->TextOut(m_ptrain[0].x+XMODIFY,m_ptrain[0].y-YMODIFY,m_str);
			switch (AMPLIFICATORY_TIMES)
			{
			case 2:
				{
					m_ptrain[0]=m_ptrain[2];
					m_ptrain[1].x=m_ptrain[0].x+3;
					m_ptrain[1].y=m_ptrain[0].y+3;
					m_ptrain[2].x=m_ptrain[0].x+5;
					m_ptrain[2].y=m_ptrain[0].y+8;
					m_ptrain[3].x=m_ptrain[0].x;
					m_ptrain[3].y=m_ptrain[4].y;
					pDC->PolyBezier(m_ptrain,4);
					if (!m_bDirector)
					{
						pDC->MoveTo(m_ptrain[1]);
						pDC->LineTo(m_ptrain[1].x+15,m_ptrain[1].y-2);
						pDC->MoveTo(m_ptrain[1]);
						pDC->LineTo(m_ptrain[1].x+15,m_ptrain[1].y+5);
					}
					break;
				}
			case 4:
				{
					m_ptrain[0]=m_ptrain[2];
					m_ptrain[1].x=m_ptrain[0].x+5;
					m_ptrain[1].y=m_ptrain[0].y+5;
					m_ptrain[2].x=m_ptrain[0].x+10;
					m_ptrain[2].y=m_ptrain[0].y+15;
					m_ptrain[3].x=m_ptrain[0].x;
					m_ptrain[3].y=m_ptrain[4].y;
					pDC->PolyBezier(m_ptrain,4);
					break;
				}
			}

			break;
		}
	case 2:
		{
			POINT m_ptrain[5];
			
			m_ptrain[0].x=(int)(m_pcarriagepos.x-(CARRIAGELENTH/2)*AMPLIFICATORY_TIMES);
			m_ptrain[0].y=m_pcarriagepos.y;
			m_ptrain[1].x=(int)(m_ptrain[0].x+m_fcarriagelenth);
			m_ptrain[1].y=m_ptrain[0].y;
			m_ptrain[2].x=m_ptrain[1].x;
			m_ptrain[2].y=(int)(m_ptrain[1].y-m_fcarriagehigh);
			m_ptrain[3].x=(int)(m_ptrain[2].x-m_fcarriagelenth);
			m_ptrain[3].y=m_ptrain[2].y;
			m_ptrain[4]=m_ptrain[0];
			pDC->Polyline(m_ptrain,5);
			pDC->TextOut(m_ptrain[0].x+XMODIFY,m_ptrain[0].y-YMODIFY,m_str);
			switch (AMPLIFICATORY_TIMES)
			{
			case 2:
				{
					m_ptrain[0]=m_ptrain[3];
					m_ptrain[1].x=m_ptrain[3].x-3;
					m_ptrain[1].y=m_ptrain[3].y+3;
					m_ptrain[2].x=m_ptrain[3].x-5;
					m_ptrain[2].y=m_ptrain[3].y+8;
					m_ptrain[3]=m_ptrain[4];
					pDC->PolyBezier(m_ptrain,4);
					if (m_bDirector)
					{
						pDC->MoveTo(m_ptrain[1]);
						pDC->LineTo(m_ptrain[1].x-10,m_ptrain[1].y-5);
						pDC->MoveTo(m_ptrain[1]);
						pDC->LineTo(m_ptrain[1].x-10,m_ptrain[1].y+5);
					}
					break;
				}
			case 4:
				{
					m_ptrain[0]=m_ptrain[3];
					m_ptrain[1].x=m_ptrain[3].x-5;
					m_ptrain[1].y=m_ptrain[3].y+5;
					m_ptrain[2].x=m_ptrain[3].x-10;
					m_ptrain[2].y=m_ptrain[3].y+15;
					m_ptrain[3]=m_ptrain[4];
					pDC->PolyBezier(m_ptrain,4);
					break;
				}
			}
			break;
		}
		
	default:
		{
			break;
		}
	}
	//显示轮子
	POINT	m_pwheelpos;
	m_pwheelpos=m_pcarriagepos;

	m_pwheelpos.y+=4;
	m_pwheelpos.x=(LONG)(m_pcarriagepos.x-7.2*AMPLIFICATORY_TIMES);
	m_carriagewheel[0].Setwheelpos(m_pwheelpos);
	m_carriagewheel[0].Showwheel(pDC);
	m_pwheelpos.x=(LONG)(m_pcarriagepos.x-5.2*AMPLIFICATORY_TIMES);
	m_carriagewheel[1].Setwheelpos(m_pwheelpos);
	m_carriagewheel[1].Showwheel(pDC);
	m_pwheelpos.x=(LONG)(m_pcarriagepos.x+5.2*AMPLIFICATORY_TIMES);
	m_carriagewheel[2].Setwheelpos(m_pwheelpos);
	m_carriagewheel[2].Showwheel(pDC);
	m_pwheelpos.x=(LONG)(m_pcarriagepos.x+7.2*AMPLIFICATORY_TIMES);
	m_carriagewheel[3].Setwheelpos(m_pwheelpos);
	m_carriagewheel[3].Showwheel(pDC);


}

CCarriage::SetCarriageLenth(FLOAT m_fcarrilenth)
{
	m_fcarriagelenth=m_fcarrilenth*AMPLIFICATORY_TIMES;
}
CCarriage::SetCarriageHigh(FLOAT m_fcarrihigh)
{
	m_fcarriagehigh=m_fcarrihigh*AMPLIFICATORY_TIMES;
}
CCarriage::SetCarriageStyle(int m_ncarristyle)
{
	m_ncarriagestyle=m_ncarristyle;
}
CCarriage::SetCarriageAngle(int m_ncarriangle)
{
	m_ncarriageangle=m_ncarriangle;
}
CCarriage::SetCarriagePos(POINT m_ppos)
{
	m_pcarriagepos=m_ppos;
}
CCarriage::SetCarriageDir(BOOL m_bdir)
{
	m_bDirector=m_bdir;
}

CCarriage::Showcarriage(CClientDC* pClientDC ,int m_number)
{
	switch (this->m_ncarriagestyle)
	{
	case 0:
		{
			POINT m_ptrain[5];
			m_ptrain[0].x=(int)(m_pcarriagepos.x-(CARRIAGELENTH/2)*AMPLIFICATORY_TIMES);
			m_ptrain[0].y=m_pcarriagepos.y;
			m_ptrain[1].x=(int)(m_ptrain[0].x+m_fcarriagelenth);
			m_ptrain[1].y=m_ptrain[0].y;
			m_ptrain[2].x=m_ptrain[1].x;
			m_ptrain[2].y=(int)(m_ptrain[1].y-m_fcarriagehigh);
			m_ptrain[3].x=(int)(m_ptrain[2].x-m_fcarriagelenth);
			m_ptrain[3].y=m_ptrain[2].y;
			m_ptrain[4]=m_ptrain[0];
			pClientDC->Polyline(m_ptrain,5);
			break;
		}
		
	case 1:
		{
			POINT m_ptrain[5];
			m_ptrain[0].x=(int)(m_pcarriagepos.x-(HEADTAILLENTH/2)*AMPLIFICATORY_TIMES);
			m_ptrain[0].y=m_pcarriagepos.y;
			m_ptrain[1].x=(int)(m_ptrain[0].x+m_fcarriagelenth);
			m_ptrain[1].y=m_ptrain[0].y;
			m_ptrain[2].x=m_ptrain[1].x;
			m_ptrain[2].y=(int)(m_ptrain[1].y-m_fcarriagehigh);
			m_ptrain[3].x=(int)(m_ptrain[2].x-m_fcarriagelenth);
			m_ptrain[3].y=m_ptrain[2].y;
			m_ptrain[4]=m_ptrain[0];
			pClientDC->Polyline(m_ptrain,5);
			switch (AMPLIFICATORY_TIMES)
			{
			case 2:
				{
					m_ptrain[0]=m_ptrain[2];
					m_ptrain[1].x=m_ptrain[0].x+3;
					m_ptrain[1].y=m_ptrain[0].y+3;
					m_ptrain[2].x=m_ptrain[0].x+5;
					m_ptrain[2].y=m_ptrain[0].y+8;
					m_ptrain[3].x=m_ptrain[0].x;
					m_ptrain[3].y=m_ptrain[4].y;
					pClientDC->PolyBezier(m_ptrain,4);
					break;
				}
			case 4:
				{
					m_ptrain[0]=m_ptrain[2];
					m_ptrain[1].x=m_ptrain[0].x+5;
					m_ptrain[1].y=m_ptrain[0].y+5;
					m_ptrain[2].x=m_ptrain[0].x+10;
					m_ptrain[2].y=m_ptrain[0].y+15;
					m_ptrain[3].x=m_ptrain[0].x;
					m_ptrain[3].y=m_ptrain[4].y;
					pClientDC->PolyBezier(m_ptrain,4);
					break;
				}
			}

			break;
		}
	case 2:
		{
			POINT m_ptrain[5];
			
			m_ptrain[0].x=(int)(m_pcarriagepos.x-(CARRIAGELENTH/2)*AMPLIFICATORY_TIMES);
			m_ptrain[0].y=m_pcarriagepos.y;
			m_ptrain[1].x=(int)(m_ptrain[0].x+m_fcarriagelenth);
			m_ptrain[1].y=m_ptrain[0].y;
			m_ptrain[2].x=m_ptrain[1].x;
			m_ptrain[2].y=(int)(m_ptrain[1].y-m_fcarriagehigh);
			m_ptrain[3].x=(int)(m_ptrain[2].x-m_fcarriagelenth);
			m_ptrain[3].y=m_ptrain[2].y;
			m_ptrain[4]=m_ptrain[0];
			pClientDC->Polyline(m_ptrain,5);

			switch (AMPLIFICATORY_TIMES)
			{
			case 2:
				{
					m_ptrain[0]=m_ptrain[3];
					m_ptrain[1].x=m_ptrain[3].x-3;
					m_ptrain[1].y=m_ptrain[3].y+3;
					m_ptrain[2].x=m_ptrain[3].x-5;
					m_ptrain[2].y=m_ptrain[3].y+8;
					m_ptrain[3]=m_ptrain[4];
					pClientDC->PolyBezier(m_ptrain,4);
					break;
				}
			case 4:
				{
					m_ptrain[0]=m_ptrain[3];
					m_ptrain[1].x=m_ptrain[3].x-5;
					m_ptrain[1].y=m_ptrain[3].y+5;
					m_ptrain[2].x=m_ptrain[3].x-10;
					m_ptrain[2].y=m_ptrain[3].y+15;
					m_ptrain[3]=m_ptrain[4];
					pClientDC->PolyBezier(m_ptrain,4);
					break;
				}
			}
			break;
		}
		
	default:
		{
			break;
		}
	}
	//显示轮子
	POINT	m_pwheelpos;
	m_pwheelpos=m_pcarriagepos;

	m_pwheelpos.y+=4;
	m_pwheelpos.x=(LONG)(m_pcarriagepos.x-7.2*AMPLIFICATORY_TIMES);
	m_carriagewheel[0].Setwheelpos(m_pwheelpos);
	m_carriagewheel[0].Showwheel(pClientDC);
	m_pwheelpos.x=(LONG)(m_pcarriagepos.x-5.2*AMPLIFICATORY_TIMES);
	m_carriagewheel[1].Setwheelpos(m_pwheelpos);
	m_carriagewheel[1].Showwheel(pClientDC);
	m_pwheelpos.x=(LONG)(m_pcarriagepos.x+5.2*AMPLIFICATORY_TIMES);
	m_carriagewheel[2].Setwheelpos(m_pwheelpos);
	m_carriagewheel[2].Showwheel(pClientDC);
	m_pwheelpos.x=(LONG)(m_pcarriagepos.x+7.2*AMPLIFICATORY_TIMES);
	m_carriagewheel[3].Setwheelpos(m_pwheelpos);
	m_carriagewheel[3].Showwheel(pClientDC);


}
