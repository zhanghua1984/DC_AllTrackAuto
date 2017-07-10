// PARP.h: interface for the PARP class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARP_H__558921FE_54D3_493D_B8E2_B0D729B4B138__INCLUDED_)
#define AFX_PARP_H__558921FE_54D3_493D_B8E2_B0D729B4B138__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MainFrm.h"
class PARP  
{
public:
	int m_nid;
	byte m_bytedata[6];
	PARP();
	virtual ~PARP();

};

#endif // !defined(AFX_PARP_H__558921FE_54D3_493D_B8E2_B0D729B4B138__INCLUDED_)
