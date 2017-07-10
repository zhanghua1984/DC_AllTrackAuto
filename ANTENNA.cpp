// ANTENNA.cpp: implementation of the ANTENNA class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "ANTENNA.h"
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

ANTENNA::ANTENNA()
{
	m_fAntennaPos=0;
	m_nAntennaNumber=0;
}

ANTENNA::~ANTENNA()
{

}

ANTENNA::SetAntennaNumber(int m_nNumber)
{
	m_nAntennaNumber=m_nNumber;
}
float ANTENNA::GetAntennaPos()
{
	//根据天线号计算天线位置，1号车，前进方向天线为1，后退方向为2，6号车后退方向为3，6号车前进方向为4
	//车长118.2,半长车为59.1 ，车辆最前端为126+59.1=185.1 ，天线位置距离车辆最前端2.216米
	switch (m_nAntennaNumber)
	{
	case 1:
		{	
			//				车辆中心点				车辆长度一半		天线到车钩		提前距离			  
			m_fAntennaPos=(float)m_dgTrainRealPos+(float)TRAINHALFLENTH-(float)ANTENNATOCUSP+DISTANCE;		//1号天线位置
			break;
		}
	case 2:
		{
			m_fAntennaPos=(float)m_dgTrainRealPos+(float)TRAINHALFLENTH-(float)ANTENNATOCUSP-DISTANCE;		//2号天线位置
			break;
		}
	case 3:
		{
			m_fAntennaPos=(float)m_dgTrainRealPos-(float)TRAINHALFLENTH+(float)ANTENNATOCUSP+DISTANCE;		//3号天线位置
			break;
		}
	case 4:
		{
			m_fAntennaPos=(float)m_dgTrainRealPos-(float)TRAINHALFLENTH+(float)ANTENNATOCUSP-DISTANCE;		//4号天线位置
			break;
		}
	}
	return	m_fAntennaPos;
}