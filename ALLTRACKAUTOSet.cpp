// ALLTRACKAUTOSet.cpp : implementation of the CALLTRACKAUTOSet class
//

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "ALLTRACKAUTOSet.h"
#include "symbol.h"
#include "math.h"
#include <cmath>
#include "alldefine.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern m_nTrackView;
extern CRect m_rcClient;
extern BOOL m_bDirectorup;
extern int	m_ngTrainhigh;		//全局车辆高度
extern BOOL		m_bDirectorup;		//车辆是否下行
/////////////////////////////////////////////////////////////////////////////
// CALLTRACKAUTOSet implementation

IMPLEMENT_DYNAMIC(CALLTRACKAUTOSet, CRecordset)

CALLTRACKAUTOSet::CALLTRACKAUTOSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_btcodesend=FALSE;
	m_btNPAPRsend=FALSE;
	m_btNPAPR2send=FALSE;
	m_btPAPRsend=FALSE;
	//{{AFX_FIELD_INIT(CALLTRACKAUTOSet)
	m_Snumber = 0;
	m_UpDown = _T("");
	m_Sname = _T("");
	m_TSname = _T("");
	m_Tsnumber = _T("");
	m_PR = _T("");
	m_Tstype = _T("");
	m_Tsskip = _T("");
	m_Tstartpos = 0;
	m_Slenth = 0;
	m_Sstarttospurlenth = 0;
	m_stoppos = 0;
	m_tgsign = 0;
	m_Tgradient = 0;
	m_CF = _T("");
	m_PLS = 0;
	m_OPENDOOR = _T("");
	m_Signalorpos = 0;
	m_SignalorV = _T("");
	m_NPAPRnumber = _T("");
	m_NPAPRpos = 0;
	m_PAPRcode = _T("");
	m_Psignalpos = 0;
	m_FDSNPAPRcode = _T("");
	m_FRSNPAPRcode = _T("");
	m_BDSNPAPRcode = _T("");
	m_BRSNPAPRcode = _T("");
	m_TOEflag= _T("");
	m_NPAPR2number = _T("");
	m_NPAPR2pos = 0;
	m_CODE7473 = _T("");
	m_CODE7458 = _T("");
	m_CODE5958 = _T("");
	m_CODE5937 = _T("");
	m_CODE3837 = _T("");
	m_CODE3827 = _T("");
	m_CODE3800 = _T("");
	m_CODE2827 = _T("");
	m_CODE2819 = _T("");
	m_CODE2800 = _T("");
	m_CODE2000 = _T("");
	m_CODE00 = _T("");
	m_NPAPR3number = _T("");
	m_NPAPR3pos = 0;
	m_R8 = _T("");
	m_LNPAPR1number = _T("");
	m_LNPAPR1pos = 0;
	m_LNPAPR2number = _T("");
	m_LNPAPR2pos = 0;
	m_LNPAPR3number = _T("");
	m_LNPAPR3pos = 0;
	m_LNPAPR4number = _T("");
	m_LNPAPR4pos = 0;
	m_LNPAPR5number = _T("");
	m_LNPAPR5pos = 0;
	m_ATOCnumber = _T("");
	m_ATOCpos = 0;
	m_R10 = _T("");
	m_POINT1ENDx = 0;
	m_POINT1ENDy = 0;
	m_POINT2ENDx = 0;
	m_POINT2ENDy = 0;
	m_POINT3ENDx = 0;
	m_POINT3ENDy = 0;
	m_LINENUMBER = 0;
	m_ISFOLD = 0;
	m_SENDCODE= 0;
	m_TRACKSTARTHIGH=0;
	m_TRACKENDHIGH=0;
	m_PRIORITY=0;
	m_Tendpos=0;
	m_SENDCODE2=0;
	m_SENDCODE2pos=0;
	m_nFields = 73;
	//}}AFX_FIELD_INIT
	m_nDefaultType = AFX_DB_USE_DEFAULT_TYPE;
}

CString CALLTRACKAUTOSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=ALLTRACK");
}

CString CALLTRACKAUTOSet::GetDefaultSQL()
{
	return _T("[dbo].[toexcel]");
}

void CALLTRACKAUTOSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CALLTRACKAUTOSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Int(pFX, _T("[Snumber]"), m_Snumber);
	RFX_Text(pFX, _T("[UpDown]"), m_UpDown);
	RFX_Text(pFX, _T("[Sname]"), m_Sname);
	RFX_Text(pFX, _T("[TSname]"), m_TSname);
	RFX_Text(pFX, _T("[Tsnumber]"), m_Tsnumber);
	RFX_Text(pFX, _T("[PR]"), m_PR);
	RFX_Text(pFX, _T("[Tstype]"), m_Tstype);
	RFX_Text(pFX, _T("[Tsskip]"), m_Tsskip);
	RFX_Int(pFX, _T("[Tstartpos]"), m_Tstartpos);
	RFX_Int(pFX, _T("[Slenth]"), m_Slenth);
	RFX_Int(pFX, _T("[Sstarttospurlenth]"), m_Sstarttospurlenth);
	RFX_Int(pFX, _T("[stoppos]"), m_stoppos);
	RFX_Int(pFX, _T("[tgsign]"), m_tgsign);
	RFX_Int(pFX, _T("[Tgradient]"), m_Tgradient);
	RFX_Text(pFX, _T("[CF]"), m_CF);
	RFX_Int(pFX, _T("[PLS]"), m_PLS);
	RFX_Text(pFX, _T("[OPENDOOR]"), m_OPENDOOR);
	RFX_Int(pFX, _T("[Signalorpos]"), m_Signalorpos);
	RFX_Text(pFX, _T("[SignalorV]"), m_SignalorV);
	RFX_Text(pFX, _T("[NPAPRnumber]"), m_NPAPRnumber);
	RFX_Int(pFX, _T("[NPAPRpos]"), m_NPAPRpos);
	RFX_Text(pFX, _T("[PAPRcode]"), m_PAPRcode);
	RFX_Int(pFX, _T("[Psignalpos]"), m_Psignalpos);
	RFX_Text(pFX, _T("[FDSNPAPRcode]"), m_FDSNPAPRcode);
	RFX_Text(pFX, _T("[FRSNPAPRcode]"), m_FRSNPAPRcode);
	RFX_Text(pFX, _T("[BDSNPAPRcode]"), m_BDSNPAPRcode);
	RFX_Text(pFX, _T("[BRSNPAPRcode]"), m_BRSNPAPRcode);
	RFX_Text(pFX, _T("[TOEflag]"), m_TOEflag);
	RFX_Text(pFX, _T("[NPAPR2number]"), m_NPAPR2number);
	RFX_Int(pFX, _T("[NPAPR2pos]"), m_NPAPR2pos);
	RFX_Text(pFX, _T("[CODE7473]"), m_CODE7473);
	RFX_Text(pFX, _T("[CODE7458]"), m_CODE7458);
	RFX_Text(pFX, _T("[CODE5958]"), m_CODE5958);
	RFX_Text(pFX, _T("[CODE5937]"), m_CODE5937);
	RFX_Text(pFX, _T("[CODE3837]"), m_CODE3837);
	RFX_Text(pFX, _T("[CODE3827]"), m_CODE3827);
	RFX_Text(pFX, _T("[CODE3800]"), m_CODE3800);
	RFX_Text(pFX, _T("[CODE2827]"), m_CODE2827);
	RFX_Text(pFX, _T("[CODE2819]"), m_CODE2819);
	RFX_Text(pFX, _T("[CODE2800]"), m_CODE2800);
	RFX_Text(pFX, _T("[CODE2000]"), m_CODE2000);
	RFX_Text(pFX, _T("[CODE00]"), m_CODE00);
	RFX_Text(pFX, _T("[NPAPR3number]"), m_NPAPR3number);
	RFX_Int(pFX, _T("[NPAPR3pos]"), m_NPAPR3pos);
	RFX_Text(pFX, _T("[R8]"), m_R8);
	RFX_Text(pFX, _T("[LNPAPR1number]"), m_LNPAPR1number);
	RFX_Int(pFX, _T("[LNPAPR1pos]"), m_LNPAPR1pos);
	RFX_Text(pFX, _T("[LNPAPR2number]"), m_LNPAPR2number);
	RFX_Int(pFX, _T("[LNPAPR2pos]"), m_LNPAPR2pos);
	RFX_Text(pFX, _T("[LNPAPR3number]"), m_LNPAPR3number);
	RFX_Int(pFX, _T("[LNPAPR3pos]"), m_LNPAPR3pos);
	RFX_Text(pFX, _T("[LNPAPR4number]"), m_LNPAPR4number);
	RFX_Int(pFX, _T("[LNPAPR4pos]"), m_LNPAPR4pos);
	RFX_Text(pFX, _T("[LNPAPR5number]"), m_LNPAPR5number);
	RFX_Int(pFX, _T("[LNPAPR5pos]"), m_LNPAPR5pos);
	RFX_Text(pFX, _T("[ATOCnumber]"), m_ATOCnumber);
	RFX_Int(pFX, _T("[ATOCpos]"), m_ATOCpos);
	RFX_Text(pFX, _T("[R10]"), m_R10);
	RFX_Int(pFX, _T("[POINT1ENDx]"), m_POINT1ENDx);
	RFX_Int(pFX, _T("[POINT1ENDy]"), m_POINT1ENDy);
	RFX_Int(pFX, _T("[POINT2ENDx]"), m_POINT2ENDx);
	RFX_Int(pFX, _T("[POINT2ENDy]"), m_POINT2ENDy);
	RFX_Int(pFX, _T("[POINT3ENDx]"), m_POINT3ENDx);
	RFX_Int(pFX, _T("[POINT3ENDy]"), m_POINT3ENDy);
	RFX_Int(pFX, _T("[LINENUMBER]"), m_LINENUMBER);
	RFX_Int(pFX, _T("[ISFOLD]"), m_ISFOLD);
	RFX_Int(pFX, _T("[SENDCODE]"),m_SENDCODE);
	RFX_Int(pFX, _T("[TRACKSTARTHIGH]"), m_TRACKSTARTHIGH);
	RFX_Int(pFX, _T("[TRACKENDHIGH]"),m_TRACKENDHIGH);
	RFX_Int(pFX, _T("[PRIORITY]"),m_PRIORITY);
	RFX_Int(pFX, _T("[Tendpos]"),m_Tendpos);
	RFX_Int(pFX, _T("[SENDCODE2]"),m_SENDCODE2);
	RFX_Int(pFX, _T("[SENDCODE2pos]"),m_SENDCODE2pos);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CALLTRACKAUTOSet diagnostics

#ifdef _DEBUG
void CALLTRACKAUTOSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CALLTRACKAUTOSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

CALLTRACKAUTOSet::ShowTrack(CDC* MemDC)
{
	FLOAT m_fCal;
	POINT m_pStartpos,m_pEndpos;
	float  m_fLenth;
	CString m_str;
	Csymbol m_symTrack;	
	CPen* m_oldpen;
	POINT	m_pSpeedLimitStartpos,m_pSpeedLimitEndpos;
	POINT	m_pCodeStartpos,m_pCodeEndpos;

	//轨道起点
 	m_pStartpos.x=m_Tstartpos;
	m_fCal=(FLOAT)m_pStartpos.x;
	m_fCal=m_fCal/100*AMPLIFICATORY_TIMES; // /100*2
	m_pStartpos.x=(LONG)m_fCal;
	m_pStartpos.y=m_TRACKSTARTHIGH;	//轨道高度
	m_pEndpos=m_pStartpos;			//结束点初始化

	m_fLenth=(float)m_Slenth;
	m_fLenth=m_fLenth/100*AMPLIFICATORY_TIMES;		//轨道长度
	//上下行轨道
	if (m_UpDown=="上行")
	{
		//CPen m_initpen(PS_SOLID,LINEWIDTH,RGB(30,144,255));
		//m_oldpen = MemDC->SelectObject((CPen*)&m_initpen);
		//显示部分计算
		m_pStartpos.x=m_pStartpos.x-m_nTrackView;
		m_pEndpos.x=(long)(m_pEndpos.x-m_nTrackView-m_fLenth);
		//判断起点终点是否在客户区内
		if (PtInRect(m_rcClient,m_pStartpos)||PtInRect(m_rcClient,m_pEndpos))
		{
			//根据上下行改变轨道颜色，并显示列车限速
			if (m_bDirectorup==TRUE)
			{
				CPen m_pen(PS_SOLID,LINEWIDTH,RGB(30,144,255));
				m_oldpen=MemDC->SelectObject((CPen*)&m_pen);
			}
			CPen m_initpen(PS_SOLID,LINEWIDTH,RGB(30,144,255));
			m_oldpen = MemDC->SelectObject((CPen*)&m_initpen);
			MemDC->MoveTo(m_pStartpos);
			//初始化
			m_pCodeStartpos=m_pStartpos;
			m_pCodeEndpos=m_pStartpos;
			m_pSpeedLimitStartpos=m_pStartpos;
			m_pSpeedLimitEndpos=m_pStartpos;
			//直轨
			if (m_ISFOLD==0)
			{
				MemDC->LineTo(m_pEndpos);
				m_fLenth=(float)((m_Slenth)/100);
				m_str.Format("%.1f",m_fLenth);
				m_str+="m";
				//轨道长度大于100显示说明，否则显示简要说明
				if (m_fLenth>=100)
				{
					MemDC->TextOut(m_pEndpos.x+(int)(m_fLenth/2),m_pEndpos.y+3,m_Sname+" "+m_TSname+" "+m_CF+" "+m_str);
				} 
				else
				{
					MemDC->TextOut(m_pEndpos.x+(int)(m_fLenth/2),m_pEndpos.y+3,m_TSname);
				}
				m_symTrack.SetSymbolpos(m_pEndpos);
				m_symTrack.SetSymbolstyle(1);
				m_symTrack.ShowSymbol(MemDC);
				//APR
				if (m_NPAPRpos!=0)
				{
					float m_fdapr=(float)(m_NPAPRpos);
					m_fdapr=m_fdapr/100;
					m_apr.SetAPR(m_pStartpos,m_fdapr*AMPLIFICATORY_TIMES,TRUE);
					m_apr.ShowAPR(MemDC);
				}
				//停车标
				if (m_stoppos!=0)
				{
					float m_fstop=(float)m_stoppos;
					m_fstop=m_fstop/100;
					m_stopflag.SetFlag(m_pStartpos,m_fstop*AMPLIFICATORY_TIMES,TRUE);
					m_stopflag.ShowAPR(MemDC);
				}
				if ((m_ngTrainhigh+6==m_TRACKENDHIGH)&&(m_bDirectorup==TRUE))
				{
					//初始化
					m_pCodeStartpos=m_pStartpos;
					m_pCodeEndpos=m_pEndpos;
					m_pSpeedLimitStartpos=m_pStartpos;
					m_pSpeedLimitEndpos=m_pEndpos;

					//绘制轨道最高允许限速
					m_pSpeedLimitStartpos.y=(MAXSPEED-m_PLS)*2;
					m_pSpeedLimitEndpos.y=m_pSpeedLimitStartpos.y;
					
					CPen m_maxspeedpen(PS_SOLID,1,RGB(240,20,65));
					CPen *m_oldmaxspeedpen;
					m_oldmaxspeedpen = MemDC->SelectObject((CPen*)&m_maxspeedpen);
					
					MemDC->MoveTo(m_pSpeedLimitStartpos);
					MemDC->LineTo(m_pSpeedLimitEndpos);
					MemDC->SelectObject(m_oldmaxspeedpen);
					//绘制轨道运行码频
					if(m_CODE7473!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-74)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(20,250,40));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE7458!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-73)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(20,230,40));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE5958!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-59)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(40,210,60));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE5937!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-58)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(40,180,60));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE3837!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-38)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(50,160,70));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE3827!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-37)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(50,140,70));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE3800!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-36)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(70,120,90));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2827!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-28)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(80,100,100));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2819!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-27)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(80,80,100));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2800!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-26)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(80,60,100));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2000!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-20)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(100,40,120));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE00!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-00)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(120,20,140));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}

				}

			} 
			//折轨
			else
			{
				//根据线段数分别绘制
				switch (m_LINENUMBER)
				{
				case 1:
					{
						//计算结束点
						float m_fpx;
						float m_fpy;
						m_fpx=(float)m_POINT1ENDx;
						m_fpx=m_fpx/100*AMPLIFICATORY_TIMES;
						m_fpy=(float)m_POINT1ENDy;
						m_fpy=m_fpy/100*AMPLIFICATORY_TIMES;
						//y值四舍五入
						m_fpy+=0.5;
						m_pEndpos.x=m_pStartpos.x+(int)m_fpx;
						m_pEndpos.y=m_pStartpos.y+(int)m_fpy;
						MemDC->LineTo(m_pEndpos);
						break;
					}
				case 2:
					{
						//计算第一段线段结束点
						float m_fpx;
						float m_fpy;
						m_fpx=(float)m_POINT1ENDx;
						m_fpx=m_fpx/100*AMPLIFICATORY_TIMES;
						m_fpy=(float)m_POINT1ENDy;
						m_fpy=m_fpy/100*AMPLIFICATORY_TIMES;
						//y值四舍五入
						m_fpy+=0.5;
						m_pEndpos.x=m_pStartpos.x-(int)m_fpx;
						m_pEndpos.y=m_pStartpos.y+(int)m_fpy;
						MemDC->LineTo(m_pEndpos);
						m_pStartpos=m_pEndpos;
						//计算第二个结束点
						m_fpx=(float)m_POINT2ENDx;
						m_fpx=m_fpx/100*AMPLIFICATORY_TIMES;
						m_fpy=(float)m_POINT2ENDy;
						m_fpy=m_fpy/100*AMPLIFICATORY_TIMES;
						//y值四舍五入
						m_fpy+=0.5;
						m_pEndpos.x=m_pEndpos.x-(int)m_fpx;
						m_pEndpos.y=m_pEndpos.y+(int)m_fpy;
						MemDC->MoveTo(m_pStartpos);
						MemDC->LineTo(m_pEndpos);
						break;
					}
				case 3:
					{
						//计算第一段线段结束点
						float m_fpx;
						float m_fpy;
						m_fpx=(float)m_POINT1ENDx;
						m_fpx=m_fpx/100*AMPLIFICATORY_TIMES;
						m_fpy=(float)m_POINT1ENDy;
						m_fpy=m_fpy/100*AMPLIFICATORY_TIMES;
						//y值四舍五入
						m_fpy+=0.5;
						m_pEndpos.x=m_pStartpos.x-(int)m_fpx;
						m_pEndpos.y=m_pStartpos.y+(int)m_fpy;
						MemDC->LineTo(m_pEndpos);
						m_pStartpos=m_pEndpos;
						//计算第二个结束点
						m_fpx=(float)m_POINT2ENDx;
						m_fpx=m_fpx/100*AMPLIFICATORY_TIMES;
						m_fpy=(float)m_POINT2ENDy;
						m_fpy=m_fpy/100*AMPLIFICATORY_TIMES;
						//y值四舍五入
						m_fpy+=0.5;
						m_pEndpos.x=m_pEndpos.x-(int)m_fpx;
						m_pEndpos.y=m_pEndpos.y+(int)m_fpy;
						MemDC->MoveTo(m_pStartpos);
						MemDC->LineTo(m_pEndpos);
						m_pStartpos=m_pEndpos;
						//计算第三个结束点
						m_fpx=(float)m_POINT3ENDx;
						m_fpx=m_fpx/100*AMPLIFICATORY_TIMES;
						m_fpy=(float)m_POINT3ENDy;
						m_fpy=m_fpy/100*AMPLIFICATORY_TIMES;
						//y值四舍五入
						m_fpy+=0.5;
						m_pEndpos.x=m_pEndpos.x-(int)m_fpx;
						m_pEndpos.y=m_pEndpos.y+(int)m_fpy;
						MemDC->MoveTo(m_pStartpos);
						MemDC->LineTo(m_pEndpos);
						break;
					}
				}
				if ((m_ngTrainhigh+6==m_TRACKENDHIGH)&&(m_bDirectorup==TRUE))
				{
					//初始化
					m_pCodeStartpos=m_pStartpos;
					m_pCodeEndpos=m_pEndpos;
					m_pSpeedLimitStartpos=m_pStartpos;
					m_pSpeedLimitEndpos=m_pEndpos;

					//绘制轨道最高允许限速
					m_pSpeedLimitStartpos.y=(MAXSPEED-m_PLS)*2;
					m_pSpeedLimitEndpos.y=m_pSpeedLimitStartpos.y;
					
					CPen m_maxspeedpen(PS_SOLID,1,RGB(240,20,65));
					CPen *m_oldmaxspeedpen;
					m_oldmaxspeedpen = MemDC->SelectObject((CPen*)&m_maxspeedpen);
					
					MemDC->MoveTo(m_pSpeedLimitStartpos);
					MemDC->LineTo(m_pSpeedLimitEndpos);
					MemDC->SelectObject(m_oldmaxspeedpen);
					//绘制轨道运行码频
					/*
					m_CODE7473 = _T("");
					m_CODE7458 = _T("");
					m_CODE5958 = _T("");
					m_CODE5937 = _T("");
					m_CODE3837 = _T("");
					m_CODE3827 = _T("");
					m_CODE3800 = _T("");
					m_CODE2827 = _T("");
					m_CODE2819 = _T("");
					m_CODE2800 = _T("");
					m_CODE2000 = _T("");
					m_CODE00 = _T("");
					*/
					if(m_CODE7473!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-74)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(20,250,40));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE7458!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-73)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(20,230,40));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE5958!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-59)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(40,210,60));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE5937!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-58)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(40,180,60));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE3837!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-38)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(50,160,70));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE3827!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-37)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(50,140,70));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE3800!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-36)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(70,120,90));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2827!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-28)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(80,100,100));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2819!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-27)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(80,80,100));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2800!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-26)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(80,60,100));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2000!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-20)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(100,40,120));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE00!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-00)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(120,20,140));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}

				}

			}
			if (m_bDirectorup==TRUE)
			{
				MemDC->SelectObject(m_oldpen);
			}

		}

	} 
	//下行
	else
	{
		//CPen m_initpen(PS_SOLID,LINEWIDTH,RGB(160,32,240));
		//m_oldpen = MemDC->SelectObject((CPen*)&m_initpen);
		//显示部分计算
		//移动操作
		m_pStartpos.x=m_pStartpos.x-m_nTrackView;
		m_pEndpos.x=(long)(m_pEndpos.x-m_nTrackView+m_fLenth);
		//判断起点终点是否在客户区内
		if (PtInRect(m_rcClient,m_pStartpos)||PtInRect(m_rcClient,m_pEndpos))
		{
			if (m_bDirectorup==FALSE)
			{
				CPen m_pen(PS_SOLID,LINEWIDTH,RGB(160,32,240));
				m_oldpen=MemDC->SelectObject((CPen*)&m_pen);
			} 
			CPen m_initpen(PS_SOLID,LINEWIDTH,RGB(160,32,240));
			m_oldpen = MemDC->SelectObject((CPen*)&m_initpen);
			MemDC->MoveTo(m_pStartpos);
			//直轨
			if (m_ISFOLD==0)
			{
				MemDC->LineTo(m_pEndpos);
				m_fLenth=(float)m_Slenth;
				m_fLenth=m_fLenth/100;
				m_str.Format("%.1f",m_fLenth);
				m_str+="m";
				//轨道长度大于100，显示完整信息，否则显示简要信息
				if (m_fLenth>=100)
				{
					MemDC->TextOut((int)(m_pStartpos.x+m_fLenth/2),m_pStartpos.y+3,m_Sname+" "+m_TSname+" "+m_CF+" "+m_str);
				} 
				else
				{
					MemDC->TextOut((int)(m_pStartpos.x+m_fLenth/2),m_pStartpos.y+3,m_TSname);
				}
				m_symTrack.SetSymbolpos(m_pEndpos);
				m_symTrack.SetSymbolstyle(2);
				m_symTrack.ShowSymbol(MemDC);
				//APR
				if (m_NPAPRpos!=0)
				{
					float m_fdapr=(float)(m_NPAPRpos);
					m_fdapr=m_fdapr/100;
					m_apr.SetAPR(m_pStartpos,m_fdapr*AMPLIFICATORY_TIMES,FALSE);
					m_apr.ShowAPR(MemDC);
				}
				//停车标
				if (m_stoppos!=0)
				{
					float m_fstop=(float)m_stoppos;
					m_fstop=m_fstop/100;
					m_stopflag.SetFlag(m_pStartpos,m_fstop*AMPLIFICATORY_TIMES,FALSE);
					m_stopflag.ShowAPR(MemDC);
				}
				//轨道载频码频
				if (m_bDirectorup==FALSE)
				{
					CString m_showcode;
					CString m_temp;
					if (m_SENDCODE!=0)
					{
						m_temp=SendCode(m_SENDCODE);
						m_showcode=m_temp;
					}
					
					if (m_SENDCODE2!=0)
					{
						m_temp=SendCode(m_SENDCODE2);
						m_showcode+="  ";
						m_showcode+=m_temp;
					}
					if (m_CF=="0xF10")
					{
						m_showcode="不发码";
					}
					//m_showcode+="  ";
					//m_showcode+=m_CF;

					MemDC->TextOut((int)(m_pStartpos.x+m_fLenth/2),m_pStartpos.y-16,m_showcode);
				}
				
				if ((m_ngTrainhigh+6==m_TRACKENDHIGH)&&(m_bDirectorup==FALSE))
				{
					//初始化
					m_pCodeStartpos=m_pStartpos;
					m_pCodeEndpos=m_pEndpos;
					m_pSpeedLimitStartpos=m_pStartpos;
					m_pSpeedLimitEndpos=m_pEndpos;

					//绘制轨道最高允许限速
					m_pSpeedLimitStartpos.y=(MAXSPEED-m_PLS)*2;
					m_pSpeedLimitEndpos.y=m_pSpeedLimitStartpos.y;
					
					CPen m_maxspeedpen(PS_SOLID,1,RGB(240,20,65));
					CPen *m_oldmaxspeedpen;
					m_oldmaxspeedpen = MemDC->SelectObject((CPen*)&m_maxspeedpen);
					
					MemDC->MoveTo(m_pSpeedLimitStartpos);
					MemDC->LineTo(m_pSpeedLimitEndpos);
					MemDC->SelectObject(m_oldmaxspeedpen);
					//绘制轨道运行码频
					/*
					m_CODE7473 = _T("");
					m_CODE7458 = _T("");
					m_CODE5958 = _T("");
					m_CODE5937 = _T("");
					m_CODE3837 = _T("");
					m_CODE3827 = _T("");
					m_CODE3800 = _T("");
					m_CODE2827 = _T("");
					m_CODE2819 = _T("");
					m_CODE2800 = _T("");
					m_CODE2000 = _T("");
					m_CODE00 = _T("");
					*/
					if(m_CODE7473!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-74)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(20,250,40));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE7458!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-73)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(20,230,40));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE5958!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-59)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(40,210,60));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE5937!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-58)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(40,180,60));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE3837!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-38)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(50,160,70));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE3827!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-37)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(50,140,70));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE3800!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-36)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(70,120,90));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2827!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-28)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(80,100,100));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2819!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-27)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(80,80,100));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2800!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-26)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(80,60,100));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2000!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-20)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(100,40,120));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE00!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-00)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(120,20,140));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}

				}

				
			} 
			//折轨	折轨按线段数绘制，13号线轨中最多折线段为3
			else
			{	
				//根据线段数分别绘制
				switch (m_LINENUMBER)
				{
				case 1:
					{
						//计算结束点
						float m_fpx;
						float m_fpy;
						m_fpx=(float)m_POINT1ENDx;
						m_fpx=m_fpx/100*AMPLIFICATORY_TIMES;
						m_fpy=(float)m_POINT1ENDy;
						m_fpy=m_fpy/100*AMPLIFICATORY_TIMES;
						//y值四舍五入
						m_fpy+=0.5;
						m_pEndpos.x=m_pStartpos.x+(int)m_fpx;
						m_pEndpos.y=m_pStartpos.y+(int)m_fpy;
						MemDC->LineTo(m_pEndpos);
						
						break;
					}
				case 2:
					{
						//计算第一段线段结束点
						float m_fpx;
						float m_fpy;
						m_fpx=(float)m_POINT1ENDx;
						m_fpx=m_fpx/100*AMPLIFICATORY_TIMES;
						m_fpy=(float)m_POINT1ENDy;
						m_fpy=m_fpy/100*AMPLIFICATORY_TIMES;
						//y值四舍五入
						m_fpy+=0.5;
						m_pEndpos.x=m_pStartpos.x+(int)m_fpx;
						m_pEndpos.y=m_pStartpos.y+(int)m_fpy;
						MemDC->LineTo(m_pEndpos);
						
						m_pStartpos=m_pEndpos;
						//计算第二个结束点
						m_fpx=(float)m_POINT2ENDx;
						m_fpx=m_fpx/100*AMPLIFICATORY_TIMES;
						m_fpy=(float)m_POINT2ENDy;
						m_fpy=m_fpy/100*AMPLIFICATORY_TIMES;
						//y值四舍五入
						m_fpy+=0.5;
						m_pEndpos.x=m_pEndpos.x+(int)m_fpx;
						m_pEndpos.y=m_pEndpos.y+(int)m_fpy;
						MemDC->MoveTo(m_pStartpos);
						MemDC->LineTo(m_pEndpos);
						break;
					}
				case 3:
					{
						
						//计算第一段线段结束点
						float m_fpx;
						float m_fpy;
						m_fpx=(float)m_POINT1ENDx;
						m_fpx=m_fpx/100*AMPLIFICATORY_TIMES;
						m_fpy=(float)m_POINT1ENDy;
						m_fpy=m_fpy/100*AMPLIFICATORY_TIMES;
						//y值四舍五入
						m_fpy+=0.5;
						m_pEndpos.x=m_pStartpos.x+(int)m_fpx;
						m_pEndpos.y=m_pStartpos.y+(int)m_fpy;
						MemDC->LineTo(m_pEndpos);
						
						m_pStartpos=m_pEndpos;
						//计算第二个结束点
						m_fpx=(float)m_POINT2ENDx;
						m_fpx=m_fpx/100*AMPLIFICATORY_TIMES;
						m_fpy=(float)m_POINT2ENDy;
						m_fpy=m_fpy/100*AMPLIFICATORY_TIMES;
						//y值四舍五入
						m_fpy+=0.5;
						m_pEndpos.x=m_pEndpos.x+(int)m_fpx;
						m_pEndpos.y=m_pEndpos.y+(int)m_fpy;
						MemDC->MoveTo(m_pStartpos);
						MemDC->LineTo(m_pEndpos);

						m_pStartpos=m_pEndpos;
						//计算第三个结束点
						m_fpx=(float)m_POINT3ENDx;
						m_fpx=m_fpx/100*AMPLIFICATORY_TIMES;
						m_fpy=(float)m_POINT3ENDy;
						m_fpy=m_fpy/100*AMPLIFICATORY_TIMES;
						//y值四舍五入
						m_fpy+=0.5;
						m_pEndpos.x=m_pEndpos.x+(int)m_fpx;
						m_pEndpos.y=m_pEndpos.y+(int)m_fpy;
						MemDC->MoveTo(m_pStartpos);
						MemDC->LineTo(m_pEndpos);
						break;
					}
				}
				if ((m_ngTrainhigh+6==m_TRACKENDHIGH)&&(m_bDirectorup==FALSE))
				{
					//初始化
					m_pCodeStartpos=m_pStartpos;
					m_pCodeEndpos=m_pEndpos;
					m_pSpeedLimitStartpos=m_pStartpos;
					m_pSpeedLimitEndpos=m_pEndpos;

					//绘制轨道最高允许限速
					m_pSpeedLimitStartpos.y=(MAXSPEED-m_PLS)*2;
					m_pSpeedLimitEndpos.y=m_pSpeedLimitStartpos.y;
					
					CPen m_maxspeedpen(PS_SOLID,1,RGB(240,20,65));
					CPen *m_oldmaxspeedpen;
					m_oldmaxspeedpen = MemDC->SelectObject((CPen*)&m_maxspeedpen);
					
					MemDC->MoveTo(m_pSpeedLimitStartpos);
					MemDC->LineTo(m_pSpeedLimitEndpos);
					MemDC->SelectObject(m_oldmaxspeedpen);
					//绘制轨道运行码频
					/*
					m_CODE7473 = _T("");
					m_CODE7458 = _T("");
					m_CODE5958 = _T("");
					m_CODE5937 = _T("");
					m_CODE3837 = _T("");
					m_CODE3827 = _T("");
					m_CODE3800 = _T("");
					m_CODE2827 = _T("");
					m_CODE2819 = _T("");
					m_CODE2800 = _T("");
					m_CODE2000 = _T("");
					m_CODE00 = _T("");
					*/
					if(m_CODE7473!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-74)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(20,250,40));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE7458!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-73)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(20,230,40));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE5958!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-59)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(40,210,60));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE5937!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-58)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(40,180,60));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE3837!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-38)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(50,160,70));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE3827!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-37)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(50,140,70));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE3800!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-36)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(70,120,90));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2827!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-28)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(80,100,100));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2819!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-27)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(80,80,100));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2800!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-26)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(80,60,100));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE2000!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-20)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(100,40,120));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}
					if(m_CODE00!="")
					{
						m_pCodeStartpos.y=(MAXSPEED-00)*2;
						m_pCodeEndpos.y=m_pCodeStartpos.y;
						CPen m_codepen(PS_SOLID,1,RGB(120,20,140));
						CPen *m_oldcodepen;
						m_oldcodepen = MemDC->SelectObject((CPen*)&m_codepen);
						
						MemDC->MoveTo(m_pCodeStartpos);
						MemDC->LineTo(m_pCodeEndpos);
						MemDC->SelectObject(m_oldcodepen);
					}

				}

			}
			if (m_bDirectorup==FALSE)
			{
				MemDC->SelectObject(m_oldpen);
			} 
		}
	}
}
CALLTRACKAUTOSet::CopyTrack(CALLTRACKAUTOSet* m_tracksrc)
{
	this->m_Snumber=m_tracksrc->m_Snumber;
	this->m_UpDown = m_tracksrc->m_UpDown;
	this->m_Sname = m_tracksrc->m_Sname;
	this->m_TSname = m_tracksrc->m_TSname;
	this->m_Tsnumber = m_tracksrc->m_Tsnumber;
	this->m_PR = m_tracksrc->m_PR;
	this->m_Tstype = m_tracksrc->m_Tstype;
	this->m_Tsskip = m_tracksrc->m_Tsskip;
	this->m_Tstartpos = m_tracksrc->m_Tstartpos;
	this->m_Slenth = m_tracksrc->m_Slenth;
	this->m_Sstarttospurlenth = m_tracksrc->m_Sstarttospurlenth;
	this->m_stoppos = m_tracksrc->m_stoppos;
	this->m_Tgradient = m_tracksrc->m_Tgradient;
	this->m_CF = m_tracksrc->m_CF;
	this->m_PLS = m_tracksrc->m_PLS;
	this->m_OPENDOOR = m_tracksrc->m_OPENDOOR;
	this->m_Signalorpos = m_tracksrc->m_Signalorpos;
	this->m_SignalorV = m_tracksrc->m_SignalorV;
	this->m_NPAPRnumber = m_tracksrc->m_NPAPRnumber;
	this->m_NPAPRpos = m_tracksrc->m_NPAPRpos;
	this->m_PAPRcode = m_tracksrc->m_PAPRcode;
	this->m_Psignalpos = m_tracksrc->m_Psignalpos;
	this->m_FDSNPAPRcode = m_tracksrc->m_FDSNPAPRcode;
	this->m_FRSNPAPRcode = m_tracksrc->m_FRSNPAPRcode;
	this->m_BDSNPAPRcode = m_tracksrc->m_BDSNPAPRcode;
	this->m_BRSNPAPRcode = m_tracksrc->m_BRSNPAPRcode;
	this->m_TOEflag=m_tracksrc->m_TOEflag;
	this->m_NPAPR2number=m_tracksrc->m_NPAPR2number;
	this->m_NPAPR2pos=m_tracksrc->m_NPAPR2pos;
	this->m_CODE7473 = m_tracksrc->m_CODE7473;
	this->m_CODE7458 = m_tracksrc->m_CODE7458;
	this->m_CODE5958 = m_tracksrc->m_CODE5958;
	this->m_CODE5937 = m_tracksrc->m_CODE5937;
	this->m_CODE3837 = m_tracksrc->m_CODE3837;
	this->m_CODE3827 = m_tracksrc->m_CODE3827;
	this->m_CODE3800 = m_tracksrc->m_CODE3800;
	this->m_CODE2827 = m_tracksrc->m_CODE2827;
	this->m_CODE2819 = m_tracksrc->m_CODE2819;
	this->m_CODE2800 = m_tracksrc->m_CODE2800;
	this->m_CODE2000 = m_tracksrc->m_CODE2000;
	this->m_CODE00 = m_tracksrc->m_CODE00;
	this->m_NPAPR3number=m_tracksrc->m_NPAPR3number;
	this->m_NPAPR3pos=m_tracksrc->m_NPAPR3pos;
	this->m_R8 = m_tracksrc->m_R8;
	this->m_LNPAPR1number=m_tracksrc->m_LNPAPR1number;
	this->m_LNPAPR1pos=m_tracksrc->m_LNPAPR1pos;
	this->m_LNPAPR2number=m_tracksrc->m_LNPAPR2number;
	this->m_LNPAPR2pos=m_tracksrc->m_LNPAPR2pos;
	this->m_LNPAPR3number=m_tracksrc->m_LNPAPR3number;
	this->m_LNPAPR3pos=m_tracksrc->m_LNPAPR3pos;
	this->m_LNPAPR4number=m_tracksrc->m_LNPAPR4number;
	this->m_LNPAPR4pos=m_tracksrc->m_LNPAPR4pos;
	this->m_LNPAPR5number=m_tracksrc->m_LNPAPR5number;
	this->m_LNPAPR5pos=m_tracksrc->m_LNPAPR5pos;
	this->m_ATOCnumber=m_tracksrc->m_ATOCnumber;
	this->m_ATOCpos=m_tracksrc->m_ATOCpos;
	this->m_POINT1ENDx = m_tracksrc->m_POINT1ENDx;
	this->m_POINT1ENDy = m_tracksrc->m_POINT1ENDy;
	this->m_POINT2ENDx = m_tracksrc->m_POINT2ENDx;
	this->m_POINT2ENDy = m_tracksrc->m_POINT2ENDy;
	this->m_POINT3ENDx = m_tracksrc->m_POINT3ENDx;
	this->m_POINT3ENDy = m_tracksrc->m_POINT3ENDy;
	this->m_LINENUMBER = m_tracksrc->m_LINENUMBER;
	this->m_ISFOLD = m_tracksrc->m_ISFOLD;
	this->m_SENDCODE= m_tracksrc->m_SENDCODE;
	this->m_TRACKSTARTHIGH = m_tracksrc->m_TRACKSTARTHIGH;
	this->m_TRACKENDHIGH= m_tracksrc->m_TRACKENDHIGH;
	this->m_apr=m_tracksrc->m_apr;
	this->m_PRIORITY=m_tracksrc->m_PRIORITY;
	this->m_Tendpos=m_tracksrc->m_Tendpos;
	this->m_SENDCODE2=m_tracksrc->m_SENDCODE2;
	this->m_SENDCODE2pos=m_tracksrc->m_SENDCODE2pos;
}

CString CALLTRACKAUTOSet::SendCode(int m_code)
{

	
	
	CString m_str;
	switch (m_code)
	{
	case 1:
		{
			m_str="M1:28:74/73";
			break;
		}
	case 2:
		{
			m_str="M2:32:74/58";
			break;
		}
	case 3:
		{
			m_str="M3:36:59/58";
			break;
		}
	case 4:
		{
			m_str="M4:40:59/37";
			break;
		}
	case 5:
		{
			m_str="M5:44:38/37";
			break;
		}
	case 6:
		{
			m_str="M6:48:38/27";
			break;
		}
	case 7:
		{
			m_str="M7:52:NONE";
			break;
		}
	case 8:
		{
			m_str="M8:56:38/0";
			break;
		}
	case 9:
		{
			m_str="M9:60:28/27";
			break;
		}
	case 10:
		{
			m_str="M10:64:28/19";
			break;
		}
	case 11:
		{
			m_str="M11:68:28/0";
			break;
		}
	case 12:
		{
			m_str="M12:72:NONE";
			break;
		}
	case 13:
		{
			m_str="M14:80:0/0";
			break;
		}
	case 14:
		{
			m_str="M14:80:0/0";
			break;
		}
	case 15:
		{
			m_str="M15:100";
			break;
		}
	default:
		{
			m_str="码频解析错误";
			break;
		}
	}
	return m_str;
}
CString CALLTRACKAUTOSet::SendFru(int m_fru)
{
	CString m_str;
	switch (m_fru)
	{
	case 1:
		{
			m_str="F1:4080";
			break;
		}
	case 2:
		{
			m_str="F2:4320";
			break;
		}
	case 3:
		{
			m_str="F3:4560";
			break;
		}
	case 4:
		{
			m_str="F4:4800";
			break;
		}
	case 5:
		{
			m_str="F5:5040";
			break;
		}
	case 6:
		{
			m_str="F6:5280";
			break;
		}
	case 7:
		{
			m_str="F7:5520";
			break;
		}
	case 9:
		{
			m_str="F9:6000";
			break;
		}
	case 10:
		{
			m_str="F10:无码";
			break;
		}
	default:
		{
			m_str="载频解析错误";
			break;
		}
	}

	return m_str;
}