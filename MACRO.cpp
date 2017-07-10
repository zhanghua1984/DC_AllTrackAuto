// MACRO.cpp: implementation of the MACRO class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "MACRO.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MACRO::MACRO()
{

}

MACRO::~MACRO()
{

}
CString MACRO::GetCode(BYTE m_byte,BOOL m_breturn)
{
	CString m_strcode;
	switch (m_byte)
	{
	case NONE:
		{
			m_strcode="空";
			break;
		}
	case B1:
		{
			m_strcode="B1";
			break;
		}
	case B2:
		{
			m_strcode="B2";
			break;
		}
	case B3:
		{
			m_strcode="B3";
			break;
		}
	case B4:
		{
			m_strcode="B4";
			break;
		}
	case B5:
		{
			m_strcode="B5";
			break;
		}
	case B6:
		{
			m_strcode="B6";
			break;
		}
	case B7:
		{
			m_strcode="B7";
			break;
		}
	case EB:
		{
			m_strcode="EB";
			break;
		}
	case FORWARD:
		{
			m_strcode="向前";
			break;
		}
	case NODIREACTOR:
		{
			m_strcode="无";
			break;
		}
	case BACK:
		{
			m_strcode="向后";
			break;
		}
	case HEAD:
		{
			m_strcode="头车";
			break;
		}
	case TRAIL:
		{
			m_strcode="尾车";
			break;
		}
	case PC:
		{
			m_strcode="PC";
			break;
		}
	case DC:
		{
			m_strcode="DC";
			break;
		}
	case D0:
		{
			m_strcode="D0";
			break;
		}
	case D1:
		{
			m_strcode="D1";
			break;
		}
	case D2:
		{
			m_strcode="D2";
			break;
		}
	case D3:
		{
			m_strcode="D3";
			break;
		}
	case D4:
		{
			m_strcode="D4";
			break;
		}
	case WD840:
		{
			m_strcode="WD840";
			break;
		}
	case WD835:
		{
			m_strcode="WD835";
			break;
		}
	case WD826:
		{
			m_strcode="WD826";
			break;
		}
	case WD818:
		{
			m_strcode="WD818";
			break;
		}
	case WD809:
		{
			m_strcode="WD809";
			break;
		}
	case WD800:
		{
			m_strcode="WD800";
			break;
		}
	case WD791:
		{
			m_strcode="WD791";
			break;
		}
	case WD783:
		{
			m_strcode="WD783";
			break;
		}
	case WD774:
		{
			m_strcode="WD774";
			break;
		}
	case ATO_E:
		{
			m_strcode="ATO_E";
			break;
		}
	case ATO_N:
		{
			m_strcode="ATO_N";
			break;
		}

	case ATP1_E:
		{
			m_strcode="ATP1_E";
			break;
		}
	case ATP1_N:
		{
			m_strcode="ATP1_N";
			break;
		}
	case ATP2_E:
		{
			m_strcode="ATP2_E";
			break;
		}
	case ATP2_N:
		{
			m_strcode="ATP2_N";
			break;
		}
	case FSKMOD_E:
		{
			m_strcode="FSKMOD_E";
			break;
		}
	case FSKMOD_N:
		{
			m_strcode="FSKMOD_N";
			break;
		}

	case FSK1_E:
		{
			m_strcode="FSK1_E";
			break;
		}
	case FSK1_N:
		{
			m_strcode="FSK1_N";
		}
	case FSK2_E:
		{
			m_strcode="FSK2_E";
			break;
		}
	case FSK2_N:
		{
			m_strcode="FSK2_N";
			break;
		}
	case TECH1_E:
		{
			m_strcode="TECH1_E";
			break;
		}
	case TECH1_N:
		{
			m_strcode="TECH1_N";
			break;
		}
	case TECH2_E:
		{
			m_strcode="TECH2_E";
			break;
		}
	case TECH2_N:
		{
			m_strcode="TECH2_N";
			break;
		}
	case TECHOP1_E:
		{
			m_strcode="TECHOP1_E";
			break;
		}
	case TECHOP1_N:
		{
			m_strcode="TECHOP1_N";
			break;
		}
	case TECHOP2_E:
		{
			m_strcode="TECHOP2_E";
			break;
		}
	case TECHOP2_N:
		{
			m_strcode="TECHOP2_N";
			break;
		}
	case R1_E:
		{
			m_strcode="R1_E";
			break;
		}
	case R1_N:
		{
			m_strcode="R1_N";
			break;
		}
	case R2_E:
		{
			m_strcode="R2_E";
			break;
		}
	case R2_N:
		{
			m_strcode="R2_N";
			break;
		}
	case R3_E:
		{
			m_strcode="R3_E";
			break;
		}
	case R3_N:
		{
			m_strcode="R3_N";
			break;
		}
	case R4_E:
		{
			m_strcode="R4_E";
			break;
		}
	case R4_N:
		{
			m_strcode="R4_N";
			break;
		}
	case R5_E:
		{
			m_strcode="R5_E";
			break;
		}
	case R5_N:
		{
			m_strcode="R5_N";
			break;
		}
	case R6_E:
		{
			m_strcode="R6_E";
			break;
		}
	case R6_N:
		{
			m_strcode="R6_N";
			break;
		}
	case R7_E:
		{
			m_strcode="R7_E";
			break;
		}
	case R7_N:
		{
			m_strcode="R7_N";
			break;
		}
	case R8_E:
		{
			m_strcode="R8_E";
			break;
		}
	case R8_N:
		{
			m_strcode="R8_N";
			break;
		}
	case R9_E:
		{
			m_strcode="R9_E";
			break;
		}
	case R9_N:
		{
			m_strcode="R9_N";
			break;
		}
	case R10_E:
		{
			m_strcode="R10_E";
			break;
		}
	case R10_N:
		{
			m_strcode="R10_N";
			break;
		}
	case R11_E:
		{
			m_strcode="R11_E";
			break;
		}
	case R11_N:
		{
			m_strcode="R11_N";
			break;
		}
	case R12_E:
		{
			m_strcode="R12_E";
			break;
		}
	case R12_N:
		{
			m_strcode="R12_N";
			break;
		}
	case R13_E:
		{
			m_strcode="R13_E";
			break;
		}
	case R13_N:
		{
			m_strcode="R13_N";
			break;
		}
	case R14_E:
		{
			m_strcode="R14_E";
			break;
		}
	case R14_N:
		{
			m_strcode="R14_N";
			break;
		}
	case R15_E:
		{
			m_strcode="R15_E";
			break;
		}
	case R15_N:
		{
			m_strcode="R15_N";
			break;
		}
	case R16_E:
		{
			m_strcode="R16_E";
			break;
		}
	case R16_N:
		{
			m_strcode="R16_N";
			break;
		}
	case NPAPR:
		{
			m_strcode="NPAPR";
			break;
		}
	case PAPR:
		{
			m_strcode="PAPR";
			break;
		}
	case CODEGAP:
		{
			m_strcode="CODEGAP";
			break;
		}
	case ONTIME:
		{
			m_strcode="ONTIME";
			break;
		}
	case NOONTIME:
		{
			m_strcode="NOONTIME";
			break;
		}
	case ONTIMECC:
		{
			m_strcode="ONTIMECC";
			break;
		}
	case READERERR_E:
		{
			m_strcode="READERERR_E";
			break;
		}
	case READERERR_N:
		{
			m_strcode="READERERR_N";
			break;
		}
	case DOPULDATA_E:
		{
			m_strcode="DOPULDATA_E";
			break;
		}
	case DOPULDATA_N:
		{
			m_strcode="DOPULDATA_N";
			break;
		}
	case DOPULNONE_E:
		{
			m_strcode="DOPULNONE_E";
			break;
		}
	case DOPULNONE_N:
		{
			m_strcode="DOPULNONE_N";
			break;
		}
	case DOPULFAULT_E:
		{
			m_strcode="DOPULFAULT_E";
			break;
		}
	case DOPULFAULT_N:
		{
			m_strcode="DOPULFAULT_N";
			break;
		}
	}
	if (m_breturn==TRUE)
	{
		m_strcode+="返回";
	}
	return m_strcode;
}