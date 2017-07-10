// SHOWMSG.h: interface for the CSHOWMSG class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWMSG_H__6C27F519_F027_4559_B691_333F5AD5582B__INCLUDED_)
#define AFX_SHOWMSG_H__6C27F519_F027_4559_B691_333F5AD5582B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define SHOWPOSY	560	
#define SHOWNUMBER	5

#include "MSG.h"
class CSHOWMSG  
{
private:
	int m_counter;
	BOOL m_bError;
public:
	CMSG	m_msg[SHOWNUMBER];
public:
	CSHOWMSG();
	virtual ~CSHOWMSG();
	Showmsg(CDC* pDC);
	AddMsg(CString m_strmsg);
	AddMsg(CString m_strmsg,int m_npos,BOOL m_bcorrect);
	SetPos(LONG x,LONG y);
	SetStyle(int m_nstyle);
	Showmsg(CDC* pDC,BOOL m_bc);
};

#endif // !defined(AFX_SHOWMSG_H__6C27F519_F027_4559_B691_333F5AD5582B__INCLUDED_)
