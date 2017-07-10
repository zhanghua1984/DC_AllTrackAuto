// Carriage.h: interface for the CCarriage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARRIAGE_H__264F869C_AE46_4D95_AC38_26E1218A17EA__INCLUDED_)
#define AFX_CARRIAGE_H__264F869C_AE46_4D95_AC38_26E1218A17EA__INCLUDED_
#include "wheel.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define XMODIFY	15
#define YMODIFY 12
class CCarriage  
{
private:
	FLOAT	m_fcarriagelenth;
	FLOAT	m_fcarriagehigh;
	int	m_ncarriagestyle;
	int m_ncarriageangle;
	POINT m_pcarriagepos;
	CString m_strCarriageName;
	BOOL m_bDirector;
public:
	Cwheel m_carriagewheel[4];
	static int m_n;
public:
	CCarriage();
	virtual ~CCarriage();
	Showcarriage(CDC* pDC,int m_number);
	Showcarriage(CClientDC* pClientDC,int m_number);
	SetCarriageLenth(FLOAT m_fcarrilenth);
	SetCarriageHigh(FLOAT m_fcarrihigh);
	SetCarriageStyle(int m_ncarristyle);
	SetCarriageAngle(int m_ncarriangle);
	SetCarriagePos(POINT m_ppos);
	SetCarriageDir(BOOL m_bdir);

};

#endif // !defined(AFX_CARRIAGE_H__264F869C_AE46_4D95_AC38_26E1218A17EA__INCLUDED_)
