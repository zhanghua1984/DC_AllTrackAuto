// SHOWMSG.cpp: implementation of the CSHOWMSG class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "SHOWMSG.h"
#include "time.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSHOWMSG::CSHOWMSG()
{
	for (int i=0;i<SHOWNUMBER;i++)
	{
		m_msg[i].SetPos(0,i*18+SHOWPOSY);
	}
	m_counter=-1;
	m_bError=FALSE;
}

CSHOWMSG::~CSHOWMSG()
{

}
CSHOWMSG::Showmsg(CDC* pDC)
{
		if (m_counter>=0)
		{
			pDC->SetTextColor(RGB(20, 25, 80));	//文字颜色
			for (int i=0;i<SHOWNUMBER;i++)
			{
				pDC->TextOut(m_msg[i].m_pPos.x,m_msg[i].m_pPos.y,m_msg[i].m_strmsg);
			}
			pDC->SetTextColor(RGB(30, 150, 80));	//文字颜色
			pDC->TextOut(m_msg[m_counter].m_pPos.x,m_msg[m_counter].m_pPos.y,m_msg[m_counter].m_strmsg);
		}
}
CSHOWMSG::AddMsg(CString m_strmsg)
{
	//加入当前系统时间
	CString m_strsystime;
	SYSTEMTIME  m_systime;
	GetLocalTime(&m_systime);
	m_strsystime.Format("%02d:%02d:%02d %03d ",m_systime.wHour,m_systime.wMinute,m_systime.wSecond,m_systime.wMilliseconds);
	m_strmsg.Insert(0,m_strsystime);
	m_counter++;
	if (m_counter==SHOWNUMBER)
	{
		m_counter=0;
	}
	m_msg[m_counter].SetCString(m_strmsg);
}
CSHOWMSG::SetPos(LONG x,LONG y)
{
	for (int i=0;i<SHOWNUMBER;i++)
	{
		m_msg[i].SetPos(x,i*18+SHOWPOSY);
	}
}
CSHOWMSG::SetStyle(int m_nstyle)
{

}

CSHOWMSG::AddMsg(CString m_strmsg,int m_npos,BOOL m_bcorrect)
{
	CString m_strsystime;
	SYSTEMTIME  m_systime;
	GetLocalTime(&m_systime);
	m_strsystime.Format("%02d:%02d:%02d %03d ",m_systime.wHour,m_systime.wMinute,m_systime.wSecond,m_systime.wMilliseconds);
	m_strsystime.Insert(0,"时间:");
	m_msg[0].SetCString(m_strsystime);
	m_msg[m_npos].SetCString(m_strmsg);
	m_bError=m_bcorrect;
}
CSHOWMSG::Showmsg(CDC* pDC,BOOL m_bc)
{
	if (m_bError==TRUE)
	{
		pDC->SetTextColor(RGB(50, 150, 50));	//文字颜色
		for (int i=0;i<SHOWNUMBER;i++)
		{
			pDC->TextOut(m_msg[i].m_pPos.x,m_msg[i].m_pPos.y,m_msg[i].m_strmsg);
		}
	} 
	else
	{
		pDC->SetTextColor(RGB(150, 50, 50));	//文字颜色
		for (int i=0;i<SHOWNUMBER;i++)
		{
			pDC->TextOut(m_msg[i].m_pPos.x,m_msg[i].m_pPos.y,m_msg[i].m_strmsg);
		}
	}
}

