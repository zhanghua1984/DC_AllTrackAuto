// Com.h: interface for the CCom class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COM_H__202D2888_A6EB_4D76_9545_0549D4FBFE0B__INCLUDED_)
#define AFX_COM_H__202D2888_A6EB_4D76_9545_0549D4FBFE0B__INCLUDED_
#include "MainFrm.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define WM_UC_MESSAGE (WM_USER+101) 
#define WM_UC_WRITE	(WM_USER+102)
UINT	ThreadWrite(LPVOID lpParam);
UINT	ThreadRead(LPVOID lpParam);
BOOL	ProcessErrorMessage(char* ErrorText);
BOOL	OpenPort();
BOOL	setupdcb(int rate_arg);
BOOL	setuptimeout(DWORD ReadInterval,DWORD ReadTotalMultiplier,DWORD ReadTotalconstant,DWORD WriteTotalMultiplier,DWORD WriteTotalconstant);
void	ReceiveChar(LPVOID lpParam);
BOOL	WriteChar(BYTE* m_szWriteBuffer,DWORD m_nToSend);
void	Delayms(int m_ns);
int		crc16(unsigned char *pchMsg,unsigned int wDataLen);
class CCom  
{
private:

public:
	CCom();
	virtual ~CCom();
	InitValue();
};

#endif // !defined(AFX_COM_H__202D2888_A6EB_4D76_9545_0549D4FBFE0B__INCLUDED_)
