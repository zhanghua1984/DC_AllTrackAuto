// ALLTRACKAUTOSet.h : interface of the CALLTRACKAUTOSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ALLTRACKAUTOSET_H__8D3F5777_3708_4C11_8C19_33043146F7C8__INCLUDED_)
#define AFX_ALLTRACKAUTOSET_H__8D3F5777_3708_4C11_8C19_33043146F7C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "APR.h"
#include "STOPFLAG.h"
#define MAXSPEED	100

class CALLTRACKAUTOSet : public CRecordset
{
public:
	CALLTRACKAUTOSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CALLTRACKAUTOSet)
	APR	m_apr;
	STOPFLAG m_stopflag;
	BOOL m_btcodesend;
	BOOL m_btNPAPRsend;
	BOOL m_btNPAPR2send;
	BOOL m_btPAPRsend;
// Field/Param Data
	//{{AFX_FIELD(CALLTRACKAUTOSet, CRecordset)
	int	m_Snumber;
	CString	m_UpDown;
	CString	m_Sname;
	CString	m_TSname;
	CString	m_Tsnumber;
	CString	m_PR;
	CString	m_Tstype;
	CString	m_Tsskip;
	int	m_Tstartpos;
	int	m_Slenth;
	int	m_Sstarttospurlenth;
	int	m_stoppos;
	BOOL m_tgsign;
	int	m_Tgradient;
	CString	m_CF;
	int	m_PLS;
	CString	m_OPENDOOR;
	int	m_Signalorpos;
	CString	m_SignalorV;
	CString	m_NPAPRnumber;
	int	m_NPAPRpos;
	CString	m_PAPRcode;
	int	m_Psignalpos;
	CString	m_FDSNPAPRcode;
	CString	m_FRSNPAPRcode;
	CString	m_BDSNPAPRcode;
	CString	m_BRSNPAPRcode;
	CString m_TOEflag;
	CString	m_NPAPR2number;
	int	m_NPAPR2pos;
	CString	m_CODE7473;
	CString	m_CODE7458;
	CString	m_CODE5958;
	CString	m_CODE5937;
	CString	m_CODE3837;
	CString	m_CODE3827;
	CString	m_CODE3800;
	CString	m_CODE2827;
	CString	m_CODE2819;
	CString	m_CODE2800;
	CString	m_CODE2000;
	CString	m_CODE00;
	CString	m_NPAPR3number;
	int	m_NPAPR3pos;
	CString	m_R8;
	CString	m_LNPAPR1number;
	int	m_LNPAPR1pos;
	CString	m_LNPAPR2number;
	int	m_LNPAPR2pos;
	CString	m_LNPAPR3number;
	int	m_LNPAPR3pos;
	CString	m_LNPAPR4number;
	int	m_LNPAPR4pos;
	CString	m_LNPAPR5number;
	int	m_LNPAPR5pos;
	CString	m_ATOCnumber;
	int	m_ATOCpos;
	CString	m_R10;
	int m_POINT1ENDx;
	int m_POINT1ENDy;
	int m_POINT2ENDx;
	int m_POINT2ENDy;
	int m_POINT3ENDx;
	int m_POINT3ENDy;
	int m_LINENUMBER;
	BOOL m_ISFOLD;
	int m_SENDCODE;
	int m_TRACKSTARTHIGH;
	int m_TRACKENDHIGH;
	int	m_PRIORITY;
	int	m_Tendpos;
	int m_SENDCODE2;
	int m_SENDCODE2pos;
	byte m_PAPRDATA[6];
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CALLTRACKAUTOSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	public:
		//ShowTrack(CDC* pDC);
		ShowTrack(CDC* pDC,CDC MemDC);
		ShowTrack(CDC* MemDC);
		CopyTrack(CALLTRACKAUTOSet* m_tracksrc);
		CString SendCode(int m_code);
		CString SendFru(int m_fru);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALLTRACKAUTOSET_H__8D3F5777_3708_4C11_8C19_33043146F7C8__INCLUDED_)

