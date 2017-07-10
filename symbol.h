// symbol.h: interface for the Csymbol class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYMBOL_H__0FE97562_59A1_4D47_BCDE_C74A7DF526DA__INCLUDED_)
#define AFX_SYMBOL_H__0FE97562_59A1_4D47_BCDE_C74A7DF526DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Csymbol  
{
private:
	POINT m_pSymbolpos;
	POINT m_pSymbol[5];
	int		m_nSymbolStyle;
public:
	Csymbol();
	virtual ~Csymbol();
	ShowSymbol(CDC *pDC);
	SetSymbolpos(POINT m_pSympos);
	SetSymbolstyle(int m_nsymstyle);
};

#endif // !defined(AFX_SYMBOL_H__0FE97562_59A1_4D47_BCDE_C74A7DF526DA__INCLUDED_)
