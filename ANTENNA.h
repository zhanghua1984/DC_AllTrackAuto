// ANTENNA.h: interface for the ANTENNA class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANTENNA_H__99F22924_79CB_4200_B53C_6E2F0F5BADE5__INCLUDED_)
#define AFX_ANTENNA_H__99F22924_79CB_4200_B53C_6E2F0F5BADE5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define TIMES	1000
#define TRAINHALFLENTH	59.1
#define ANTENNATOCUSP	2.216
#define ADVANCELENTH	3
class ANTENNA  
{
private:
	float	m_fAntennaPos;
	int		m_nAntennaNumber;
public:
	ANTENNA();
	virtual ~ANTENNA();
	SetAntennaNumber(int m_nNumber);
	float GetAntennaPos();
};

#endif // !defined(AFX_ANTENNA_H__99F22924_79CB_4200_B53C_6E2F0F5BADE5__INCLUDED_)
