// TRACKCODE.h: interface for the CTRACKCODE class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRACKCODE_H__C059A565_C8DA_41BC_B626_1CED0F98BE8D__INCLUDED_)
#define AFX_TRACKCODE_H__C059A565_C8DA_41BC_B626_1CED0F98BE8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTRACKCODE  
{

public:
	CTRACKCODE();
	virtual ~CTRACKCODE();
	CString GetTrackCode(byte m_bytesendcode,byte m_bytestyle);
};

#endif // !defined(AFX_TRACKCODE_H__C059A565_C8DA_41BC_B626_1CED0F98BE8D__INCLUDED_)
