// symbol.cpp: implementation of the Csymbol class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "symbol.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Csymbol::Csymbol()
{
	m_pSymbolpos.x=100;
	m_pSymbolpos.y=100;

	m_pSymbol[0].x=m_pSymbolpos.x+5;
	m_pSymbol[0].y=m_pSymbolpos.y+5;

	m_pSymbol[1].x=m_pSymbolpos.x;
	m_pSymbol[1].y=m_pSymbolpos.y+5;

	m_pSymbol[2].x=m_pSymbolpos.x;
	m_pSymbol[2].y=m_pSymbolpos.y-5;

	m_pSymbol[3].x=m_pSymbolpos.x+5;
	m_pSymbol[3].y=m_pSymbolpos.y-5;

	m_pSymbol[4].x=m_pSymbolpos.x+3;
	m_pSymbol[4].y=m_pSymbolpos.y+3;
	
	m_nSymbolStyle=1;
}

Csymbol::~Csymbol()
{

}
Csymbol::ShowSymbol(CDC *pDC)
{
	switch (m_nSymbolStyle)
	{
	case 0:
		{
			break;
		}
	case 1:
		{
			m_pSymbol[0].x=m_pSymbolpos.x+5;
			m_pSymbol[0].y=m_pSymbolpos.y+5;
			
			m_pSymbol[1].x=m_pSymbolpos.x;
			m_pSymbol[1].y=m_pSymbolpos.y+5;
			
			m_pSymbol[2].x=m_pSymbolpos.x;
			m_pSymbol[2].y=m_pSymbolpos.y-5;
			
			m_pSymbol[3].x=m_pSymbolpos.x+5;
			m_pSymbol[3].y=m_pSymbolpos.y-5;
			
			m_pSymbol[4].x=m_pSymbolpos.x+3;
			m_pSymbol[4].y=m_pSymbolpos.y+3;

			pDC->Polyline(m_pSymbol,4);
			break;
		}
	case 2:
		{
			m_pSymbol[0].x=m_pSymbolpos.x-5;
			m_pSymbol[0].y=m_pSymbolpos.y+5;
			
			m_pSymbol[1].x=m_pSymbolpos.x;
			m_pSymbol[1].y=m_pSymbolpos.y+5;
			
			m_pSymbol[2].x=m_pSymbolpos.x;
			m_pSymbol[2].y=m_pSymbolpos.y-5;
			
			m_pSymbol[3].x=m_pSymbolpos.x-5;
			m_pSymbol[3].y=m_pSymbolpos.y-5;
			
			m_pSymbol[4].x=m_pSymbolpos.x+3;
			m_pSymbol[4].y=m_pSymbolpos.y+3;
			
			pDC->Polyline(m_pSymbol,4);
			break;
		}
	}
	
}
Csymbol::SetSymbolpos(POINT m_pSympos)
{
	m_pSymbolpos=m_pSympos;
}
Csymbol::SetSymbolstyle(int m_nsymstyle)
{
	m_nSymbolStyle=m_nsymstyle;
}