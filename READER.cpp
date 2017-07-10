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
	//�����Ķ����ż����Ķ���λ�ã�1�ų���ǰ�������Ķ���Ϊ1�����˷���Ϊ2��6�ų����˷���Ϊ3��6�ų�ǰ������Ϊ4
	//����118.2,�볤��Ϊ59.1  ��//�Ķ������복����ǰ��18.574��

	switch (m_nReaderNumber)
	{
	case 1:
		{
			m_fReaderPos=(float)m_dgTrainRealPos+(float)TRAINHALFLENTH-(float)READERTOCUSP+DISTANCE;	//ʹ��1���Ķ���
			break;
		}
	case 2:
		{
			m_fReaderPos=(float)m_dgTrainRealPos+(float)TRAINHALFLENTH-(float)READERTOCUSP-DISTANCE;	//ʹ��2���Ķ���
			break;
		}
	case 3:
		{
			m_fReaderPos=(float)m_dgTrainRealPos-(float)TRAINHALFLENTH+(float)READERTOCUSP+DISTANCE;	//ʹ��3���Ķ���
			break;
		}
	case 4:
		{
			m_fReaderPos=(float)m_dgTrainRealPos-(float)TRAINHALFLENTH+(float)READERTOCUSP-DISTANCE;	//ʹ��4���Ķ���
			break;
		}
	}
	return m_fReaderPos;
}