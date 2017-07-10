// PROMPTINFO.h: interface for the PROMPTINFO class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROMPTINFO_H__CDC5A93C_3224_479B_80AF_109E1F2D1299__INCLUDED_)
#define AFX_PROMPTINFO_H__CDC5A93C_3224_479B_80AF_109E1F2D1299__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PROMPTINFO  
{
public:
	POINT m_pos;
	CString m_strnexttrack;
	CString m_strtrackinfo[10];
	PROMPTINFO();
	virtual ~PROMPTINFO();
	ShowPromp(CDC* pDC);
	SetPos(POINT m_pos);
	SetPos(int m_posx,int m_posy);
	SetUpDown(CString m_updown);

	SetSname(CString m_sname);
	SetTSname(CString m_tsname);
	SetTSnumber(CString m_tsnumber);
	SetTSlenth(CString m_tslenth);
	SetCF(CString m_cf);
	SetNPAPRnumber(CString m_npaprnumber);
	SetNPAPRpos(CString m_npaprpos);
	SetCodeFru(CString m_codefru);
	SetCString(int m_num,CString m_strcontent);
};

#endif // !defined(AFX_PROMPTINFO_H__CDC5A93C_3224_479B_80AF_109E1F2D1299__INCLUDED_)
