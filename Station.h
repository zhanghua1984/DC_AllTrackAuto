#if !defined(AFX_STATION_H__B8F98C53_3CFF_4C14_B065_B63FFF8613EB__INCLUDED_)
#define AFX_STATION_H__B8F98C53_3CFF_4C14_B065_B63FFF8613EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Station.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Station recordset

class Station : public CRecordset
{
public:
	
	Station(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Station)
	POINT m_pStation[6];
// Field/Param Data
	//{{AFX_FIELD(Station, CRecordset)
	CString	m_name;
	CString	m_pos;
	CString	m_platformnum;
	CString	m_plenth;
	CString	m_p1high;
	CString	m_p1width;
	CString	m_p2high;
	CString	m_p2width;
	CString	m_p3high;
	CString	m_p3width;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Station)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL
	public:
		ShowStation(CDC* pDC);
	private:
		BuildPlat(int m_n);
// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATION_H__B8F98C53_3CFF_4C14_B065_B63FFF8613EB__INCLUDED_)
