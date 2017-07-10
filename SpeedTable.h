// SpeedTable.h: interface for the CSpeedTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPEEDTABLE_H__893D8B14_ED69_4D84_9623_E778A6CD1873__INCLUDED_)
#define AFX_SPEEDTABLE_H__893D8B14_ED69_4D84_9623_E778A6CD1873__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSpeedTable  
{
public:
	POINT	m_pHStart;
	POINT	m_pHEnd;
	POINT	m_pVStart;
	POINT	m_pVEnd;
public:
	CSpeedTable();
	virtual ~CSpeedTable();
	ShowSpeedTable(CDC* m_cdc);
};

#endif // !defined(AFX_SPEEDTABLE_H__893D8B14_ED69_4D84_9623_E778A6CD1873__INCLUDED_)
