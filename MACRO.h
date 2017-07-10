// MACRO.h: interface for the MACRO class.
// 该类不做实现，只定义各种宏
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MACRO_H__D7E31D4E_55D3_4E61_93DC_86371C32F21A__INCLUDED_)
#define AFX_MACRO_H__D7E31D4E_55D3_4E61_93DC_86371C32F21A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// 操作命令代码，用于发送和返回比对

//档位
#define	NONE	0x00
#define EB		0x08
#define B7		0x07
#define B6		0x06
#define B5		0x05
#define B4		0x04
#define B3		0x03
#define B2		0x02
#define B1		0x01
#define D0		0x10
#define D1		0x11
#define D2		0x12
#define D3		0x13
#define D4		0x14


//方向
#define FORWARD	0x09
#define NODIREACTOR	0x0A
#define BACK	0x0B

//头尾车

#define HEAD	0x0C
#define TRAIL	0x0D

//控车
#define PC		0x0E
#define DC		0x0F

//轮径
//轮经值（cm）	774	783	791	800	809	818	826	835	840
//发送编号(16进制)	1	2	3	4	5	6	7	8	9

#define WD840	0x29
#define WD835	0x28
#define WD826	0x27
#define WD818	0x26
#define WD809	0x25
#define WD800	0x24
#define WD791	0x23
#define WD783	0x22
#define WD774	0x21


//头尾车
#define ATO_E	0x2A
#define ATO_N	0x2B
#define ATP1_E	0x2C
#define ATP1_N	0x2D
#define ATP2_E	0x2E
#define ATP2_N	0x2F
#define FSKMOD_E	0x30
#define FSKMOD_N	0x31
#define FSK2_E	0x32
#define FSK2_N	0x33
#define FSK1_E	0x34
#define FSK1_N	0x35
#define TECH2_E	0x36
#define TECH2_N	0x37
#define TECH1_E	0x38
#define TECH1_N	0x39
#define TECHOP1_E	0x3A
#define TECHOP1_N	0x3B
#define TECHOP2_E	0x3C
#define TECHOP2_N	0x3D
#define R1_E	0x3E
#define R1_N	0x3F
#define R2_E	0x40
#define R2_N	0x41
#define R3_E	0x42
#define R3_N	0x43
#define R4_E	0x44
#define R4_N	0x45
#define R5_E	0x46
#define R5_N	0x47
#define R6_E	0x48
#define R6_N	0x49
#define R7_E	0x4A
#define R7_N	0x4B
#define R8_E	0x4C
#define R8_N	0x4D
#define R9_E	0x4E
#define R9_N	0x4F
#define R10_E	0x50
#define R10_N	0x51
#define R11_E	0x52
#define R11_N	0x53
#define R12_E	0x54
#define R12_N	0x55
#define R13_E	0x56
#define R13_N	0x57
#define R14_E	0x58
#define R14_N	0x59
#define R15_E	0x5A
#define R15_N	0x5B
#define R16_E	0x5C
#define R16_N	0x5D
#define NPAPR	0x5E
#define PAPR	0x5F
#define CODEGAP	0x60
#define ONTIME	0x61
#define NOONTIME	0x62
#define ONTIMECC	0x63
#define READERERR_E	0x64
#define READERERR_N 0x65
#define DOPULDATA_E 0x66
#define DOPULDATA_N 0x67
#define DOPULNONE_E 0x68
#define DOPULNONE_N 0x69
#define DOPULFAULT_E 0x6A
#define DOPULFAULT_N 0x6B

class MACRO  
{
public:
	MACRO();
	virtual ~MACRO();
	CString GetCode(BYTE m_byte,BOOL m_breturn);
};

#endif // !defined(AFX_MACRO_H__D7E31D4E_55D3_4E61_93DC_86371C32F21A__INCLUDED_)
