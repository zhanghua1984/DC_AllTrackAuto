// Includes.h: interface for the Includes class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INCLUDES_H__0A319C65_3AFD_49AD_8C84_09E646AE9D35__INCLUDED_)
#define AFX_INCLUDES_H__0A319C65_3AFD_49AD_8C84_09E646AE9D35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define WM_FINDAVACOMPORT (WM_USER+1)		//找到一个有效串口号
#define WM_RX	WM_USER+2
#define BUFFERLENTH	10000
#define WM_UCOM_WRITE	(WM_USER+102) 
#define WM_UDISPLAY_MSG (WM_USER+103)

#define	Defcmd_UartAppOpen  		"cmd/Uart AppOp  "  /*     cmd 1         */
#define	Defcmd_UartPlanOpen 		"cmd/Uart PlanOp "	/*     cmd 2         */
#define	Defcmd_UartComOpen  		"cmd/Uart ComOp  "	/*     cmd 3         */
#define	Defcmd_DspBDebugOpen		"cmd/DspB DebugOp"	//解码

// 		ATP_MPM_A地址：0x93;
//		ATP_MPM_B地址：0xA3
// 		ATP_MPM_C地址：0xB3
// 		ATP_MPM_D地址：0xC3
// 		ATO_MPM地址：  0xD3
//		ATO
//		我是A4 下位机44
#define ATP_MPM_A	0x93
#define ATP_MPM_B	0xA3
#define ATP_MPM_C	0xB3
#define ATP_MPM_D	0xC3
#define ATP_MPM		0xD3
#define FRAME_HEAD1	0xFC
#define FRAME_HEAD2	0x0C

#define FRAME_SEQUENCE_70	0x70
#define FRAME_SEQUENCE_E0	0xE0
#define FRAME_SEQUENCE_E1	0xE1
#define FRAME_SEQUENCE_E2	0xE2

#define COMMANDLENTH	16
#define DATASTART	6
#define FRAMEPOS	5
#define LOCAL_ADDRESS	0x02
#define TARGET_ADDRESS	0x03

#define FRAME_SEQUENCE_POS	0x05

#define MC_P4	0xF245
#define MC_P3	0x7245
#define MC_P2	0x5245
#define MC_P1	0x4245
#define MC_N	0x0241
#define MC_B1	0x0451
#define MC_B2	0x04D1
#define MC_B3	0x04C1
#define MC_B4	0x05E1
#define MC_B5	0x0561
#define MC_B6	0x0571
#define MC_B7	0x05F1
#define MC_EB	0x0800
#define MC_EB1	0x0840

#define SHOWLINE0	0
#define SHOWLINE1	1
#define SHOWLINE2	2
#define SHOWLINE3	3
#define SHOWLINE4	4
#define SHOWLINE5	5

class Includes  
{
public:
	Includes();
	virtual ~Includes();

};

#endif // !defined(AFX_INCLUDES_H__0A319C65_3AFD_49AD_8C84_09E646AE9D35__INCLUDED_)
