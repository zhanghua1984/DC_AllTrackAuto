// Com.cpp: implementation of the CCom class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "ALLTRACKAUTO.h"
#include "Com.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
BYTE	m_bytecounter;
BYTE	m_byteCom[24];
BYTE	m_byteWriteStatus[24];
BYTE	m_byteWriteTrackCode[24];
BYTE	m_byteWriteCaputCauda[24];
BYTE	m_byteWritePAPR70[24];
BYTE	m_byteWritePAPR10[24];
BYTE	m_byteWriteNPAPR80[24];
BYTE	m_byteWriteNPAPR20[24];
BYTE	m_byteWriteDebug[24];
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CWinThread* pThreadWriter;
CWinThread* pThreadRead;
HANDLE hCom;
OVERLAPPED m_overlap;
COMSTAT comstat;
extern BOOL m_bEndThread;
BOOL	m_bSendStatus;
BOOL	m_bSendHD;
BOOL	m_bSendCode;
BOOL	m_bSendNPAPR;
BOOL	m_bSendNPAPRF;
BOOL	m_bSendPAPR;
BOOL	m_bSendPAPRF;
BOOL	m_bSendDebug;
/*
HANDLE	m_hThreadw;
HANDLE	m_hThreadr;
*/
CCom::CCom()
{
	

	InitValue();
	//串口数据
	if (OpenPort())
	{
		setupdcb(115200);
		setuptimeout(0,0,0,0,0);
		PurgeComm(hCom, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT |	PURGE_TXABORT);
		//启动接收，发送线程 此两个线程退出前不结束将出现内存错误
		pThreadWriter=AfxBeginThread(ThreadWrite,(LPVOID)1);
		pThreadRead=AfxBeginThread(ThreadRead,(LPVOID)1);
	} 
	else
	{
		AfxMessageBox("SATA未找到可用串口!");
	}

}

CCom::~CCom()
{
	
}

UINT ThreadWrite(LPVOID lpParam)
{
	/*
	//列车状态数据帧
	CString m_cstypestatus="30";
	//无源信标握手帧
	CString	m_cstypenopowersignalhandle="70";
	//无源信标数据帧
	CString m_cstypenopowersigaldata="10";
	//有源信标握手帧
	CString m_cstypepowersignalhandle="80";
	//有源信标数据帧
	CString m_cstypepowersigaldata="20";
	//轨道码数据
	CString m_cstypetrackcode="40";
	//头尾车
	CString m_cstypeheadtrail="50";
	*/
	while(m_bEndThread==FALSE)
	{
		//30
		if ((m_bSendStatus==TRUE)&&(m_byteWriteStatus[0x14]!=0))
		{
			WORD	m_wcrc16=0;
			//填入序列号和校验
			m_byteWriteStatus[0x04]=m_bytecounter++;
			m_wcrc16=crc16(m_byteWriteStatus,22);
			m_byteWriteStatus[0x16]=m_wcrc16&0x00ff;
			m_wcrc16=m_wcrc16&0xff00;
			m_wcrc16=m_wcrc16>>8;
			m_byteWriteStatus[0x17]=(unsigned char)m_wcrc16;
			WriteChar(m_byteWriteStatus,24);
			CMainFrame* pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;	//先通过获取当前框架指针 
			CView * active = pMF->GetActiveView();					//才能获取当前视类指针 
			if(active != NULL)										//获取了当前视类指针才能发送消息 
			{
																	//第一个参数为帧类型,第二个为命令类型
				active->PostMessage(WM_UC_WRITE,m_byteWriteStatus[0x05],m_byteWriteStatus[0x14]);   //使用PostMessage发送消息
			}
			if (m_byteWriteStatus[0x11]>0)
			{
				m_byteWriteStatus[0x11]=0;
				m_bSendStatus=FALSE;
			}
			
			Delayms(10);
		}
		
		//40
		if ((m_bSendCode==TRUE)&&(m_byteWriteTrackCode[0x14]!=0))
		{
			WORD	m_ncrccode16;
			//填入序列号和校验
			
			m_byteWriteTrackCode[0x04]=m_bytecounter++;

			m_ncrccode16=crc16(m_byteWriteTrackCode,22);
			m_byteWriteTrackCode[0x16]=m_ncrccode16&0x00ff;
			m_ncrccode16=m_ncrccode16&0xff00;
			m_ncrccode16=m_ncrccode16>>8;
			m_byteWriteTrackCode[0x17]=(unsigned char)m_ncrccode16;
			WriteChar(m_byteWriteTrackCode,24);
			CMainFrame* pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;	//先通过获取当前框架指针 
			CView * active = pMF->GetActiveView();					//才能获取当前视类指针 
			if(active != NULL)										//获取了当前视类指针才能发送消息 
			{
				//第一个参数为帧类型,第二个为命令类型
				active->PostMessage(WM_UC_WRITE,m_byteWriteTrackCode[0x05],m_byteWriteTrackCode[0x14]);   //使用PostMessage发送消息
			}
			Delayms(10);
		}
	
		//50		
		if ((m_bSendHD==TRUE)&&(m_byteWriteCaputCauda[0x14]!=0))
		{
			WORD	m_ncrch16;
			//填入序列号和校验
			m_byteWriteCaputCauda[0x04]=m_bytecounter++;
			m_ncrch16=crc16(m_byteWriteCaputCauda,22);
			m_byteWriteCaputCauda[0x16]=m_ncrch16&0x00ff;
			m_ncrch16=m_ncrch16&0xff00;
			m_ncrch16=m_ncrch16>>8;
			m_byteWriteCaputCauda[0x17]=(unsigned char)m_ncrch16;
			WriteChar(m_byteWriteCaputCauda,24);
			CMainFrame* pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;	//先通过获取当前框架指针 
			CView * active = pMF->GetActiveView();					//才能获取当前视类指针 
			if(active != NULL)										//获取了当前视类指针才能发送消息 
			{
				//第一个参数为帧类型,第二个为命令类型
				active->PostMessage(WM_UC_WRITE,m_byteWriteCaputCauda[0x05],m_byteWriteCaputCauda[0x14]);   //使用PostMessage发送消息
			}
			Delayms(10);
		}
		//70 10
		if ((m_bSendNPAPR==TRUE)&&(m_byteWritePAPR70[0x14]!=0))
		{
			WORD	m_ncrca16;
			//填入序列号和校验
			m_byteWritePAPR70[0x04]=m_bytecounter++;
			m_ncrca16=crc16(m_byteWritePAPR70,22);
			m_byteWritePAPR70[0x16]=m_ncrca16&0x00ff;
			m_ncrca16=m_ncrca16&0xff00;
			m_ncrca16=m_ncrca16>>8;
			m_byteWritePAPR70[0x17]=(unsigned char)m_ncrca16;
			WriteChar(m_byteWritePAPR70,24);
			Delayms(2);
			m_byteWritePAPR10[0x04]=m_bytecounter++;
			m_ncrca16=crc16(m_byteWritePAPR10,22);
			m_byteWritePAPR10[0x16]=m_ncrca16&0x00ff;
			m_ncrca16=m_ncrca16&0xff00;
			m_ncrca16=m_ncrca16>>8;
			m_byteWritePAPR10[0x17]=(unsigned char)m_ncrca16;
			WriteChar(m_byteWritePAPR10,24);
			Delayms(5);
			CMainFrame* pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;	//先通过获取当前框架指针 
			CView * active = pMF->GetActiveView();					//才能获取当前视类指针 
			if(active != NULL)										//获取了当前视类指针才能发送消息 
			{
				//第一个参数为帧类型,第二个为命令类型
				active->PostMessage(WM_UC_WRITE,m_byteWritePAPR70[0x05],m_byteWritePAPR70[0x14]);   //使用PostMessage发送消息
			}
			m_bSendNPAPRF=TRUE;
		}
		//80 20
		if ((m_bSendPAPR==TRUE)&&(m_byteWritePAPR70[0x14]!=0))
		{
			WORD	m_ncrca16;
			//填入序列号和校验
			m_byteWritePAPR70[0x04]=m_bytecounter++;
			m_ncrca16=crc16(m_byteWritePAPR70,22);
			m_byteWritePAPR70[0x16]=m_ncrca16&0x00ff;
			m_ncrca16=m_ncrca16&0xff00;
			m_ncrca16=m_ncrca16>>8;
			m_byteWritePAPR70[0x17]=(unsigned char)m_ncrca16;
			WriteChar(m_byteWritePAPR70,24);
			Delayms(2);
			m_byteWritePAPR10[0x04]=m_bytecounter++;
			m_ncrca16=crc16(m_byteWritePAPR10,22);
			m_byteWritePAPR10[0x16]=m_ncrca16&0x00ff;
			m_ncrca16=m_ncrca16&0xff00;
			m_ncrca16=m_ncrca16>>8;
			m_byteWritePAPR10[0x17]=(unsigned char)m_ncrca16;
			WriteChar(m_byteWritePAPR10,24);
			Delayms(5);
			CMainFrame* pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;	//先通过获取当前框架指针 
			CView * active = pMF->GetActiveView();					//才能获取当前视类指针 
			if(active != NULL)										//获取了当前视类指针才能发送消息 
			{
				//第一个参数为帧类型,第二个为命令类型
				active->PostMessage(WM_UC_WRITE,m_byteWritePAPR70[0x05],m_byteWritePAPR70[0x14]);   //使用PostMessage发送消息
			}
			m_bSendPAPRF=TRUE;
		}

		//A0
		if (m_bSendDebug==TRUE)
		{
			WORD	m_ncrch16;
			//填入序列号和校验
			m_byteWriteDebug[0x04]=m_bytecounter++;
			m_ncrch16=crc16(m_byteWriteDebug,22);
			m_byteWriteDebug[0x16]=m_ncrch16&0x00ff;
			m_ncrch16=m_ncrch16&0xff00;
			m_ncrch16=m_ncrch16>>8;
			m_byteWriteDebug[0x17]=(unsigned char)m_ncrch16;
			WriteChar(m_byteWriteDebug,24);
			m_bSendDebug=FALSE;
			CMainFrame* pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;	//先通过获取当前框架指针 
			CView * active = pMF->GetActiveView();					//才能获取当前视类指针 
			if(active != NULL)										//获取了当前视类指针才能发送消息 
			{
				//第一个参数为帧类型,第二个为命令类型
				active->PostMessage(WM_UC_WRITE,m_byteWriteDebug[0x05],m_byteWriteDebug[0x14]);   //使用PostMessage发送消息
			}
			Delayms(10);
		}

		Sleep(1);
	}
	AfxEndThread(20,TRUE);
	return 0;
}
UINT ThreadRead(LPVOID lpParam)
{
	ReceiveChar(lpParam);
	return 0;
}
BOOL ProcessErrorMessage(char* ErrorText)
{
	char *Temp = new char[200];
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR) &lpMsgBuf,
		0,
		NULL
		);
	/*
	sprintf(Temp, "WARNING: %s Failed with the following error: \n%s\nPort:
		%d\n", (char*)ErrorText, lpMsgBuf, "com2");
		MessageBox(NULL, Temp, "Application Error", MB_ICONSTOP);
		*/
	LocalFree(lpMsgBuf);
	delete[] Temp;
	return true;
}
BOOL OpenPort()//打开一个串口
{
	//自动搜索串口算法
	CString m_strport="COM";
	CString m_strportnumber;
	for (int i=0;i<255;i++)
	{
		m_strport="COM";
		m_strportnumber.Format("%d",i);
		m_strport+=m_strportnumber;
		hCom = CreateFile(m_strport,GENERIC_READ | GENERIC_WRITE,0,0,OPEN_EXISTING,FILE_FLAG_OVERLAPPED,0);
		if (hCom == INVALID_HANDLE_VALUE)
		{
			continue;
		}
		else
		{
			return TRUE;
			break;
		}
	}
	return FALSE;
}

BOOL setupdcb(int rate_arg)
{
	DCB dcb;
	int rate= rate_arg;
	memset(&dcb,0,sizeof(dcb));
	if(!GetCommState(hCom,&dcb))//获取当前DCB 配置
	{
		ProcessErrorMessage("GetCommState()");
		return FALSE;
	}
	/* -------------------------------------------------------------------- */
// set DCB to configure the serial port
	dcb.DCBlength = sizeof(dcb);
	/* ---------- Serial Port Config ------- */
	dcb.BaudRate = rate;
	dcb.Parity = NOPARITY;
	dcb.fParity = 0;
	dcb.StopBits = ONESTOPBIT;
	dcb.ByteSize = 8;
	dcb.fOutxCtsFlow = 0;
	dcb.fOutxDsrFlow = 0;
	dcb.fDtrControl = DTR_CONTROL_DISABLE;
	dcb.fDsrSensitivity = 0;
	dcb.fRtsControl = RTS_CONTROL_DISABLE;
	dcb.fOutX = 0;
	dcb.fInX = 0;
	/* ----------------- misc parameters ----- */
	dcb.fErrorChar = 0;
	dcb.fBinary = 1;
	dcb.fNull = 0;
	dcb.fAbortOnError = 0;
	dcb.wReserved = 0;
	dcb.XonLim = 2;
	dcb.XoffLim = 4;
	dcb.XonChar = 0x13;
	dcb.XoffChar = 0x19;
	dcb.EvtChar = 0;
/* -------------------------------------------------------------------- */
// set DCB
	if(!SetCommState(hCom,&dcb))
	{
		ProcessErrorMessage("SetCommState()");
		return false;
	}
	else
	return true;
}

BOOL setuptimeout(DWORD ReadInterval,DWORD ReadTotalMultiplier,DWORD
ReadTotalconstant,DWORD WriteTotalMultiplier,DWORD WriteTotalconstant)
{
	COMMTIMEOUTS timeouts;
	timeouts.ReadIntervalTimeout=ReadInterval;
	timeouts.ReadTotalTimeoutConstant=ReadTotalconstant;
	timeouts.ReadTotalTimeoutMultiplier=ReadTotalMultiplier;
	timeouts.WriteTotalTimeoutConstant=WriteTotalconstant;
	timeouts.WriteTotalTimeoutMultiplier=WriteTotalMultiplier;
	if(!SetCommTimeouts(hCom, &timeouts))
	{
		ProcessErrorMessage("SetCommTimeouts()");
		return false;
	}
	else
	return true;
}

void ReceiveChar(LPVOID lpParam)
{
	BOOL bRead = TRUE;
	BOOL bResult = TRUE;
	DWORD dwError = 0;
	DWORD BytesRead = 0;
	while(m_bEndThread==FALSE)
	{
		Sleep(1);
		bResult = ClearCommError(hCom, &dwError, &comstat);
		if (comstat.cbInQue == 0)
		continue;
		if (bRead)
		{
			bResult = ReadFile(hCom,			// Handle to COMM port
								&m_byteCom,		// RX Buffer Pointer
								24,				// Read one byte
								&BytesRead,		// Stores number of bytes read
								&m_overlap);	// pointer to the m_ov structure
			
			//给主线程信息，显示

			if ((m_byteCom[0]==0xfc)&&(m_byteCom[1]==0x0c)&&(m_byteCom[2]==0x0a)&&(m_byteCom[3]==0x0b))
			{
				CMainFrame* pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;  //先通过获取当前框架指针 
				CView * active = pMF->GetActiveView();//才能获取当前视类指针 
				if(active != NULL)  //获取了当前视类指针才能发送消息 
				{
					//第一个参数为帧类型
					active->PostMessage(WM_UC_MESSAGE,m_byteCom[5],0);   //使用PostMessage发送消息
				}
			}
			else
			{
				//串口读取数据错误，终止读取，并清空缓冲区
				PurgeComm(hCom,PURGE_RXCLEAR|PURGE_TXCLEAR|PURGE_RXABORT|PURGE_TXABORT);
				Sleep(1);
				continue;
			}
			
			if (!bResult)
			{
				switch (dwError = GetLastError())
				{
				case ERROR_IO_PENDING:
					{
						bRead = FALSE;
						break;
					}
				default:
					{
						break;
					}
				}
			}
			else
			{
				bRead = TRUE;
			}
		} // close if (bRead)
		if (!bRead)
		{
			bRead = TRUE;
			bResult = GetOverlappedResult(hCom, // Handle to COMM port
			&m_overlap, // Overlapped structure
			&BytesRead, // Stores number of bytes read
			TRUE); // Wait flag
		}
	}
	AfxEndThread(21,TRUE);
}


BOOL WriteChar(BYTE* m_szWriteBuffer,DWORD m_nToSend)
{
	BOOL bWrite = TRUE;
	BOOL bResult = TRUE;
	DWORD BytesSent = 0;
	HANDLE m_hWriteEvent=NULL;
	ResetEvent(m_hWriteEvent);
	if (bWrite)
	{
		m_overlap.Offset = 0;
		m_overlap.OffsetHigh = 0;
		// Clear buffer
		bResult = WriteFile(hCom, // Handle to COMM Port
			m_szWriteBuffer, // Pointer to message buffer in calling finction
			m_nToSend, // Length of message to send
			&BytesSent, // Where to store the number of bytes sent
			&m_overlap ); // Overlapped structure
		if (!bResult)
		{
			DWORD dwError = GetLastError();
			switch (dwError)
			{
			case ERROR_IO_PENDING:
				{
					// continue to GetOverlappedResults()
					BytesSent = 0;
					bWrite = FALSE;
					break;
				}
			default:
				{
					// all other error codes
					ProcessErrorMessage("WriteFile()");
				}
			}
		}
	} // end if(bWrite)
	if (!bWrite)
	{
		bWrite = TRUE;
		bResult = GetOverlappedResult(hCom, // Handle to COMM port
			&m_overlap, // Overlapped structure
			&BytesSent, // Stores number of bytes sent
			TRUE); // Wait flag
		// deal with the error code
		if (!bResult)
		{
			ProcessErrorMessage("GetOverlappedResults() in WriteFile()");
		}
	} // end if (!bWrite)
	// Verify that the data size send equals what we tried to send
	if (BytesSent != m_nToSend)
	{
		printf("WARNING: WriteFile() error.. Bytes Sent: %d; Message Length: %d\n",
			BytesSent, strlen((char*)m_szWriteBuffer));
	}
	return true;
}

void	Delayms(int m_ns)
{
	LARGE_INTEGER litmp;
	LONGLONG QPart1,QPart2;
	double dfMinus, dfFreq, dfTim;
	QueryPerformanceFrequency(&litmp);
	dfFreq = (double)litmp.QuadPart;// 获得计数器的时钟频率
	QueryPerformanceCounter(&litmp);
	QPart1 = litmp.QuadPart;// 获得初始值
	do
	{
		QueryPerformanceCounter(&litmp);
		QPart2 = litmp.QuadPart;//获得中止值
		dfMinus = (double)(QPart2-QPart1);
		dfTim = dfMinus / dfFreq;// 获得对应的时间值，单位为秒
	}while(dfTim <0.00173575*m_ns);
}

CCom::InitValue()
{
	m_byteWriteStatus[0]=0xFC;
	m_byteWriteTrackCode[0]=0xFC;
	m_byteWriteCaputCauda[0]=0xFC;
	m_byteWritePAPR70[0]=0xFC;
	m_byteWritePAPR10[0]=0xFC;
	m_byteWriteNPAPR80[0]=0xFC;
	m_byteWriteNPAPR20[0]=0xFC;
	m_byteWriteDebug[0]=0xFC;

	m_byteWriteStatus[1]=0x0C;
	m_byteWriteTrackCode[1]=0x0C;
	m_byteWriteCaputCauda[1]=0x0C;
	m_byteWritePAPR70[1]=0x0C;
	m_byteWritePAPR10[1]=0x0C;
	m_byteWriteNPAPR80[1]=0x0C;
	m_byteWriteNPAPR20[1]=0x0C;
	m_byteWriteDebug[1]=0x0C;

	m_byteWriteStatus[2]=0x0B;
	m_byteWriteTrackCode[2]=0x0B;
	m_byteWriteCaputCauda[2]=0x0B;
	m_byteWritePAPR70[2]=0x0B;
	m_byteWritePAPR10[2]=0x0B;
	m_byteWriteNPAPR80[2]=0x0B;
	m_byteWriteNPAPR20[2]=0x0B;

	m_byteWriteDebug[2]=0x0B;
	m_byteWriteStatus[3]=0x0A;
	m_byteWriteTrackCode[3]=0x0A;
	m_byteWriteCaputCauda[3]=0x0A;
	m_byteWritePAPR70[3]=0x0A;
	m_byteWritePAPR10[3]=0x0A;
	m_byteWriteNPAPR80[3]=0x0A;
	m_byteWriteNPAPR20[3]=0x0A;
	m_byteWriteDebug[3]=0x0A;
	m_bytecounter=0;
	m_byteWriteStatus[0x05]=0x30;
	m_byteWriteStatus[0x08]=0x11;
	m_byteWriteStatus[0x12]=0x09;
	m_byteWriteStatus[0x13]=0x14;
	m_byteWriteStatus[0x15]=0xAA;

	m_byteWriteTrackCode[0x05]=0x40;
	m_byteWriteCaputCauda[0x05]=0x50;
	m_byteWritePAPR70[0x05]=0x70;
	m_byteWritePAPR10[0x05]=0x10;
	m_byteWriteNPAPR80[0x05]=0x80;
	m_byteWriteNPAPR20[0x05]=0x20;
	m_byteWriteDebug[0x05]=0xA0;

	m_byteWriteDebug[0x14]=0xAA;

	m_bSendStatus=FALSE;
	m_bSendHD=FALSE;
	m_bSendCode=FALSE;
	m_bSendNPAPR=FALSE;
	m_bSendNPAPRF=FALSE;
	m_bSendPAPR=FALSE;
	m_bSendDebug=FALSE;
}

int crc16(unsigned char *pchMsg,unsigned int wDataLen)
{
	unsigned  int wCRCTalbeAbs[] =
	{
		0x0000, 0xCC01, 0xD801, 0x1400, 0xF001, 
			0x3C00, 0x2800, 0xE401, 0xA001, 0x6C00, 
			0x7800, 0xB401, 0x5000, 0x9C01, 0x8801, 
			0x4400
	};
	unsigned  int wCRC = 0xFFFF;
	unsigned  int i = 0;
	unsigned char chChar = 0;
	
	for (i = 0; i < wDataLen; i++)
	{
		chChar = *pchMsg++;
		wCRC = wCRCTalbeAbs[(chChar ^ wCRC) & 15] ^ (wCRC >> 4);
		wCRC = wCRCTalbeAbs[((chChar >> 4) ^ wCRC) & 15] ^ (wCRC >> 4);
	}
	
	return wCRC;
}
