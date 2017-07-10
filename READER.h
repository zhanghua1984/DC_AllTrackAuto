// READER.h: interface for the READER class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_READER_H__A0C13408_6DE1_433E_AF90_E03BAEADF72F__INCLUDED_)
#define AFX_READER_H__A0C13408_6DE1_433E_AF90_E03BAEADF72F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define TRAINHALFLENTH	59.1
#define READERTOCUSP	18.574
#define ADVANCELENTH	3
class READER  
{
private:
	float m_fReaderPos;
	int		m_nReaderNumber;
public:
	READER();
	virtual ~READER();
	SetReaderNumber(int m_nNumber);
float	GetReaderPos();
};

#endif // !defined(AFX_READER_H__A0C13408_6DE1_433E_AF90_E03BAEADF72F__INCLUDED_)
