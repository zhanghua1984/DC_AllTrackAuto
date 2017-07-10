// STOPFLAG.h: interface for the STOPFLAG class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOPFLAG_H__35B70311_27C0_4EC8_B92B_DF829D65F697__INCLUDED_)
#define AFX_STOPFLAG_H__35B70311_27C0_4EC8_B92B_DF829D65F697__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class STOPFLAG  
{
private:
	POINT m_pstart;
	float m_fflag;
	BOOL	m_bup;
public:
	STOPFLAG();
	virtual ~STOPFLAG();
	SetFlag(POINT m_pTstart,float m_fTflag,BOOL m_up);
	ShowAPR(CDC * m_pDC);
};

#endif // !defined(AFX_STOPFLAG_H__35B70311_27C0_4EC8_B92B_DF829D65F697__INCLUDED_)
