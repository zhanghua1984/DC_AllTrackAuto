// TRACKCODE.cpp: implementation of the CTRACKCODE class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "TRACKCODE.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTRACKCODE::CTRACKCODE()
{

}

CTRACKCODE::~CTRACKCODE()
{

}
CString CTRACKCODE::GetTrackCode(byte m_bytesendcode,byte m_bytestyle)
{
	CString m_str;
	CString m_strreturn;
	byte m_byte;
	m_byte=m_bytesendcode>>4;
	//ÂëÆµ
	switch (m_byte)
	{
	case 0x01:
		{
			m_str="M1:28:74/73";
			break;
		}
	case 0x02:
		{	
			m_str="M2:32:74/58";
			break;
		}
	case 0x03:
		{
			m_str="M3:36:59/58";
			break;
		}
	case 0x04:
		{
			m_str="M4:40:59/37";
			break;
		}
	case 0x05:
		{
			m_str="M5:44:38/37";
			break;
		}
	case 0x06:
		{
			m_str="M6:48:38/27";
			break;
		}
	case 0x07:
		{
			m_str="M7:52:NONE";
			break;
		}
	case 0x08:
		{
			m_str="M8:56:38/0";
			break;
		}
	case 0x09:
		{
			m_str="M9:60:28/27";
			break;
		}
	case 0x0A:
		{
			m_str="M10:64:28/19";
			break;
		}
	case 0x0B:
		{
			m_str="M11:68:28/0";
			break;
		}
	case 0x0C:
		{
			m_str="M12:72:NONE";
			break;
		}
	case 0x0D:
		{
			m_str="M13:76:20/0";
			break;
		}
	case 0x0E:
		{
			m_str="M14:80:0/0";
			break;
		}
	}
	m_strreturn=m_str;
	m_byte=m_bytesendcode&0x0f;
	//ÔØÆµ
	switch (m_byte)
	{
	case 0x01:
		{
			m_str=" F1:4080";
			break;
		}
	case 0x02:
		{
			m_str=" F2:4320";
			break;
		}
	case 0x03:
		{
			m_str=" F3:4560";
			break;
		}
	case 0x04:
		{
			m_str=" F4:4800";
			break;
		}
	case 0x05:
		{
			m_str=" F5:5040";
			break;
		}
	case 0x06:
		{
			m_str=" F6:5280";
			break;
		}
	case 0x07:
		{
			m_str=" F7:5520";
			break;
		}
	case 0x08:
		{
			m_str=" F9:6000";
			break;
		}
	case 0x0a:
		{
			m_str=" F10:ÎŞÂë";
			break;
		}
	}
	m_strreturn+=m_str;
	if (m_bytestyle)
	{
		m_strreturn+="·µ»Ø";
	}
	return m_strreturn;
}