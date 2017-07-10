// MSG.h: interface for the CMSG class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSG_H__3F55E63B_876B_43C5_BA68_9E99BD45592E__INCLUDED_)
#define AFX_MSG_H__3F55E63B_876B_43C5_BA68_9E99BD45592E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMSG  
{
public:
	POINT	m_pPos;
	CString	m_strmsg;
	int		m_ntype;
public:
	CMSG();
	virtual ~CMSG();
	SetPos(LONG m_x,LONG m_y);
	SetCString(CString m_str);
	SetType(int m_type);
};

#endif // !defined(AFX_MSG_H__3F55E63B_876B_43C5_BA68_9E99BD45592E__INCLUDED_)
