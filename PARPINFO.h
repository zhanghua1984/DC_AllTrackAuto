// PARPINFO.h: interface for the PARPINFO class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARPINFO_H__534CA153_76CC_4112_86A0_3FBBC7F16D06__INCLUDED_)
#define AFX_PARPINFO_H__534CA153_76CC_4112_86A0_3FBBC7F16D06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PARPINFO  
{
public:
	int m_npaprid;
	byte m_bytedata[6];
	PARPINFO();
	virtual ~PARPINFO();
};

#endif // !defined(AFX_PARPINFO_H__534CA153_76CC_4112_86A0_3FBBC7F16D06__INCLUDED_)
