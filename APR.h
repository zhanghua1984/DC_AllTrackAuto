// APR.h: interface for the APR class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_APR_H__F84B7C8A_2D4C_4505_A4A2_4AE6CBB12BA1__INCLUDED_)
#define AFX_APR_H__F84B7C8A_2D4C_4505_A4A2_4AE6CBB12BA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class APR  
{
private:
	POINT m_paprts;
	float m_fdapr;
	BOOL	m_bup;
public:
	APR();
	virtual ~APR();
	SetAPR(POINT m_pTstart,float m_faprd,BOOL m_up);
	ShowAPR(CDC * m_pDC);
};

#endif // !defined(AFX_APR_H__F84B7C8A_2D4C_4505_A4A2_4AE6CBB12BA1__INCLUDED_)
