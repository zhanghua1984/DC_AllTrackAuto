// wheel.h: interface for the Cwheel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WHEEL_H__3168A05E_B380_46E5_86F0_BAE00A1EFF2F__INCLUDED_)
#define AFX_WHEEL_H__3168A05E_B380_46E5_86F0_BAE00A1EFF2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define MATH_GEN2	1.414
class Cwheel  
{
private:
	FLOAT m_fwheeldia;
	POINT m_pwheelpos;

public:
	Cwheel();
	virtual ~Cwheel();
	Setwheelpos(POINT m_p);
	Setwheeldia(FLOAT m_fdia);
	Showwheel(CDC* pDC);
	Setwheelpos(FLOAT x,FLOAT y);
	Showwheel(CClientDC* pClientDC);
};

#endif // !defined(AFX_WHEEL_H__3168A05E_B380_46E5_86F0_BAE00A1EFF2F__INCLUDED_)
