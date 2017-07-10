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
	//�������ߺż�������λ�ã�1�ų���ǰ����������Ϊ1�����˷���Ϊ2��6�ų����˷���Ϊ3��6�ų�ǰ������Ϊ4
	//����118.2,�볤��Ϊ59.1 ��������ǰ��Ϊ126+59.1=185.1 ������λ�þ��복����ǰ��2.216��
	switch (m_nAntennaNumber)
	{
	case 1:
		{	
			//				�������ĵ�				��������һ��		���ߵ�����		��ǰ����			  
			m_fAntennaPos=(float)m_dgTrainRealPos+(float)TRAINHALFLENTH-(float)ANTENNATOCUSP+DISTANCE;		//1������λ��
			break;
		}
	case 2:
		{
			m_fAntennaPos=(float)m_dgTrainRealPos+(float)TRAINHALFLENTH-(float)ANTENNATOCUSP-DISTANCE;		//2������λ��
			break;
		}
	case 3:
		{
			m_fAntennaPos=(float)m_dgTrainRealPos-(float)TRAINHALFLENTH+(float)ANTENNATOCUSP+DISTANCE;		//3������λ��
			break;
		}
	case 4:
		{
			m_fAntennaPos=(float)m_dgTrainRealPos-(float)TRAINHALFLENTH+(float)ANTENNATOCUSP-DISTANCE;		//4������λ��
			break;
		}
	}
	return	m_fAntennaPos;
}