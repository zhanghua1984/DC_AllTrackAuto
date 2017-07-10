// READER.cpp: implementation of the READER class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "READER.h"
#include "alldefine.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
extern double		m_dgTrainRealPos;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

READER::READER()
{
	m_fReaderPos=0;
	m_nReaderNumber=0;
}

READER::~READER()
{

}
READER::SetReaderNumber(int m_nNumber)
{
	m_nReaderNumber=m_nNumber;
}
float	READER::GetReaderPos()
{
	//根据阅读器号计算阅读器位置，1号车，前进方向阅读器为1，后退方向为2，6号车后退方向为3，6号车前进方向为4
	//车长118.2,半长车为59.1  ，//阅读器距离车辆最前端18.574米

	switch (m_nReaderNumber)
	{
	case 1:
		{
			m_fReaderPos=(float)m_dgTrainRealPos+(float)TRAINHALFLENTH-(float)READERTOCUSP+DISTANCE;	//使用1号阅读器
			break;
		}
	case 2:
		{
			m_fReaderPos=(float)m_dgTrainRealPos+(float)TRAINHALFLENTH-(float)READERTOCUSP-DISTANCE;	//使用2号阅读器
			break;
		}
	case 3:
		{
			m_fReaderPos=(float)m_dgTrainRealPos-(float)TRAINHALFLENTH+(float)READERTOCUSP+DISTANCE;	//使用3号阅读器
			break;
		}
	case 4:
		{
			m_fReaderPos=(float)m_dgTrainRealPos-(float)TRAINHALFLENTH+(float)READERTOCUSP-DISTANCE;	//使用4号阅读器
			break;
		}
	}
	return m_fReaderPos;
}