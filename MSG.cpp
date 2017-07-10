// MSG.cpp: implementation of the CMSG class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "MSG.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMSG::CMSG()
{
	m_pPos.x=0;
	m_pPos.y=500;
	m_ntype=1;
}

CMSG::~CMSG()
{
	
}
CMSG::SetPos(LONG m_x,LONG m_y)
{
	m_pPos.x=m_x;
	m_pPos.y=m_y;
}
CMSG::SetCString(CString m_str)
{
	m_strmsg=m_str;
}
CMSG::SetType(int m_type)
{
	m_ntype=m_type;
}