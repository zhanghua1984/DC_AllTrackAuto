// SpeedLine.h: interface for the SpeedLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPEEDLINE_H__B2355D6E_1C7D_447E_AD04_639ADE39B5CC__INCLUDED_)
#define AFX_SPEEDLINE_H__B2355D6E_1C7D_447E_AD04_639ADE39B5CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define SPEEDLINEHIGH	200
#define POINTNUMBER		42000
class SpeedLine  
{
public:
	POINT m_pHeadSpeed[POINTNUMBER*AMPLIFICATORY_TIMES];
	POINT m_pTailSpeed[POINTNUMBER*AMPLIFICATORY_TIMES];
public:
	SpeedLine();
	virtual ~SpeedLine();
	ShowLine(CDC * pCDC,int m_n);
	SetSpeed(LONG x,LONG y);
};

#endif // !defined(AFX_SPEEDLINE_H__B2355D6E_1C7D_447E_AD04_639ADE39B5CC__INCLUDED_)
