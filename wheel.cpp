// wheel.cpp: implementation of the Cwheel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "wheel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Cwheel::Cwheel()
{
	m_fwheeldia=(FLOAT)0.884*AMPLIFICATORY_TIMES;
	m_pwheelpos.x=100;
	m_pwheelpos.y=100;
}

Cwheel::~Cwheel()
{

}

Cwheel::Setwheelpos(POINT m_p)
{
	m_pwheelpos=m_p;
}

Cwheel::Setwheeldia(FLOAT m_fdia)
{
	m_fwheeldia=m_fdia*AMPLIFICATORY_TIMES;
}
Cwheel::Showwheel(CDC* pDC)
{
	CRect m_rctoellipse;
	FLOAT	m_flenth;
	m_flenth=(FLOAT)(m_fwheeldia/2*MATH_GEN2);
	pDC->Ellipse((int)(m_pwheelpos.x-m_flenth),(int)(m_pwheelpos.y-m_flenth),(int)(m_pwheelpos.x+m_flenth),(int)(m_pwheelpos.y+m_flenth));
}


Cwheel::Setwheelpos(FLOAT x,FLOAT y)
{
	m_pwheelpos.x=(int)x;
	m_pwheelpos.y=(int)y;
}

Cwheel::Showwheel(CClientDC* pClientDC)
{
	CRect m_rctoellipse;
	FLOAT	m_flenth;
	m_flenth=(FLOAT)(m_fwheeldia/2*MATH_GEN2);
	pClientDC->Ellipse((int)(m_pwheelpos.x-m_flenth),(int)(m_pwheelpos.y-m_flenth),(int)(m_pwheelpos.x+m_flenth),(int)(m_pwheelpos.y+m_flenth));
}
