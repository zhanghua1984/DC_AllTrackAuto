// Station.cpp : implementation file
//

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "Station.h"
#include "alldefine.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern m_nTrackView;
/////////////////////////////////////////////////////////////////////////////
// Station

IMPLEMENT_DYNAMIC(Station, CRecordset)

Station::Station(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(Station)
	m_name = _T("");
	m_pos = _T("");
	m_platformnum = _T("");
	m_plenth = _T("");
	m_p1high = _T("");
	m_p1width = _T("");
	m_p2high = _T("");
	m_p2width = _T("");
	m_p3high = _T("");
	m_p3width = _T("");
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	m_nDefaultType = AFX_DB_USE_DEFAULT_TYPE;
}


CString Station::GetDefaultConnect()
{
	return _T("ODBC;DSN=ALLTRACK");
}

CString Station::GetDefaultSQL()
{
	return _T("[dbo].[station]");
}

void Station::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(Station)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[pos]"), m_pos);
	RFX_Text(pFX, _T("[platformnum]"), m_platformnum);
	RFX_Text(pFX, _T("[plenth]"), m_plenth);
	RFX_Text(pFX, _T("[p1high]"), m_p1high);
	RFX_Text(pFX, _T("[p1width]"), m_p1width);
	RFX_Text(pFX, _T("[p2high]"), m_p2high);
	RFX_Text(pFX, _T("[p2width]"), m_p2width);
	RFX_Text(pFX, _T("[p3high]"), m_p3high);
	RFX_Text(pFX, _T("[p3width]"), m_p3width);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// Station diagnostics

#ifdef _DEBUG
void Station::AssertValid() const
{
	CRecordset::AssertValid();
}

void Station::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
Station::ShowStation(CDC* pDC)
{
	CPen m_initpen(PS_SOLID,LINEWIDTH,RGB(238,48,167));
	pDC->SelectObject((CPen*)&m_initpen);
	int m_platnum=atoi(m_platformnum);
	switch (m_platnum)
	{
	case 1:
		{
			BuildPlat(1);
			pDC->Polyline(m_pStation,6);
			pDC->TextOut(m_pStation[0].x-20,m_pStation[0].y-18,m_name);
			break;
		}
	case 2:
		{
			BuildPlat(1);
			pDC->Polyline(m_pStation,6);
			pDC->TextOut(m_pStation[0].x-20,m_pStation[0].y-18,m_name);
			BuildPlat(2);
			pDC->Polyline(m_pStation,6);
			pDC->TextOut(m_pStation[0].x-20,m_pStation[0].y-18,m_name);
			break;
		}
	case 3:
		{
			BuildPlat(1);
			pDC->Polyline(m_pStation,6);
			pDC->TextOut(m_pStation[0].x-20,m_pStation[0].y-18,m_name);
			BuildPlat(2);
			pDC->Polyline(m_pStation,6);
			pDC->TextOut(m_pStation[0].x-20,m_pStation[0].y-18,m_name);
			BuildPlat(3);
			pDC->Polyline(m_pStation,6);
			pDC->TextOut(m_pStation[0].x-20,m_pStation[0].y-18,m_name);
			break;
		}
	}
}

Station::BuildPlat(int m_n)
{
	switch (m_n)
	{
	case 1:
		{
			m_pStation[0].x=atoi(m_pos)*AMPLIFICATORY_TIMES-m_nTrackView;
			m_pStation[0].y=atoi(m_p1high);
			m_pStation[1].x=m_pStation[0].x+atoi(m_plenth)/2*AMPLIFICATORY_TIMES;
			m_pStation[1].y=m_pStation[0].y;
			m_pStation[2].x=m_pStation[1].x;
			m_pStation[2].y=m_pStation[1].y-atoi(m_p1width);
			m_pStation[3].x=m_pStation[2].x-atoi(m_plenth)*AMPLIFICATORY_TIMES;
			m_pStation[3].y=m_pStation[2].y;
			m_pStation[4].x=m_pStation[3].x;
			m_pStation[4].y=m_pStation[3].y+atoi(m_p1width);
			m_pStation[5]=m_pStation[0];
			break;
		}
	case 2:
		{
			m_pStation[0].x=atoi(m_pos)*AMPLIFICATORY_TIMES-m_nTrackView;
			m_pStation[0].y=atoi(m_p2high);
			m_pStation[1].x=m_pStation[0].x+atoi(m_plenth)/2*AMPLIFICATORY_TIMES;
			m_pStation[1].y=m_pStation[0].y;
			m_pStation[2].x=m_pStation[1].x;
			m_pStation[2].y=m_pStation[1].y-atoi(m_p2width);
			m_pStation[3].x=m_pStation[2].x-atoi(m_plenth)*AMPLIFICATORY_TIMES;
			m_pStation[3].y=m_pStation[2].y;
			m_pStation[4].x=m_pStation[3].x;
			m_pStation[4].y=m_pStation[3].y+atoi(m_p2width);
			m_pStation[5]=m_pStation[0];
			break;
		}
	case 3:
		{
			m_pStation[0].x=atoi(m_pos)*AMPLIFICATORY_TIMES-m_nTrackView;
			m_pStation[0].y=atoi(m_p3high);
			m_pStation[1].x=m_pStation[0].x+atoi(m_plenth)/2*AMPLIFICATORY_TIMES;
			m_pStation[1].y=m_pStation[0].y;
			m_pStation[2].x=m_pStation[1].x;
			m_pStation[2].y=m_pStation[1].y-atoi(m_p3width);
			m_pStation[3].x=m_pStation[2].x-atoi(m_plenth)*AMPLIFICATORY_TIMES;
			m_pStation[3].y=m_pStation[2].y;
			m_pStation[4].x=m_pStation[3].x;
			m_pStation[4].y=m_pStation[3].y+atoi(m_p3width);
			m_pStation[5]=m_pStation[0];
			break;
		}
	}
}
