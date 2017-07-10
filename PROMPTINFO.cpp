// PROMPTINFO.cpp: implementation of the PROMPTINFO class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "PROMPTINFO.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
extern COLORREF	m_colorgfont;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PROMPTINFO::PROMPTINFO()
{
	m_pos.x=800;
	m_pos.y=0;
}

PROMPTINFO::~PROMPTINFO()
{

}

PROMPTINFO::ShowPromp(CDC* pDC)
{
	pDC->SetTextColor(m_colorgfont);	//文字颜色
	for (int i=0;i<=9;i++)
	{
		pDC->TextOut(m_pos.x,m_pos.y+i*20,m_strtrackinfo[i]);
	}
}

PROMPTINFO::SetPos(POINT m_pos)
{
	
}

PROMPTINFO::SetPos(int m_posx,int m_posy)
{
	m_pos.x=m_posx;
	m_pos.y=m_posy;
}
PROMPTINFO::SetUpDown(CString m_updown)
{
	m_strtrackinfo[0]=m_updown;
	m_strtrackinfo[0].Insert(0,"上下行:");
}
PROMPTINFO::SetSname(CString m_sname)
{
	m_strtrackinfo[1]=m_sname;
	m_strtrackinfo[1].Insert(0,"站名:");
}
PROMPTINFO::SetTSname(CString m_tsname)
{
	m_strtrackinfo[2]=m_tsname;
	m_strtrackinfo[2].Insert(0,"轨道名:");
}
PROMPTINFO::SetTSnumber(CString m_tsnumber)
{
	m_strtrackinfo[3]=m_tsnumber;
	m_strtrackinfo[3].Insert(0,"轨道码:");
}
PROMPTINFO::SetTSlenth(CString m_tslenth)
{
	m_strtrackinfo[4]=m_tslenth;
	m_strtrackinfo[4].Insert(0,"轨长:");
	m_strtrackinfo[4]+="cm";
}
PROMPTINFO::SetCF(CString m_cf)
{
	m_strtrackinfo[5]=m_cf;
	m_strtrackinfo[5].Insert(0,"载频:");
}
PROMPTINFO::SetNPAPRnumber(CString m_npaprnumber)
{
	m_strtrackinfo[6]=m_npaprnumber;
	m_strtrackinfo[6].Insert(0,"NPAPR:");
}
PROMPTINFO::SetNPAPRpos(CString m_npaprpos)
{
	m_strtrackinfo[7]=m_npaprpos;
	m_strtrackinfo[7].Insert(0,"APR位置:");
	m_strtrackinfo[7]+="cm";
}
PROMPTINFO::SetCodeFru(CString m_codefru)
{
	m_strtrackinfo[8]=m_codefru;
	m_strtrackinfo[8].Insert(0,"码频:M");
}
PROMPTINFO::SetCString(int m_num,CString m_strcontent)
{
	m_strtrackinfo[m_num]=m_strcontent;
}
