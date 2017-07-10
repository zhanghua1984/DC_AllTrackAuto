// Train.cpp: implementation of the CTrain class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "Train.h"
#include "ALLDEFINE.H"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTrain::CTrain()
{
	m_fTrainPos.x=720;
	m_fTrainPos.y=500;
	//运行方向，下行向右为正向1
	m_bDirection=1;
	m_bHead=1;
}

CTrain::~CTrain()
{

}
CTrain::SetTrainPos(POINT m_ppos)
{
	m_fTrainPos=m_ppos;
}
CTrain::SetTrainHead(BOOL m_bhead)
{
	m_bHead=m_bhead;
}
CTrain::SetTrainDirection(BOOL m_bDirect)
{
	m_bDirection=m_bDirect;
}

CTrain::ShowTrain(CDC* pClientDC)
{
	CPen m_trainpen;
	m_trainpen.CreatePen(PS_SOLID,LINEWIDTH,RGB(0,244,0));
	pClientDC->SelectObject(&m_trainpen);


	POINT m_pSetpos;
	m_pSetpos=m_fTrainPos;
	//根据放大倍数，设置各车厢参数
	switch (AMPLIFICATORY_TIMES)
	{
	case 2:
		{
			m_pSetpos.x=(int)(m_fTrainPos.x-(CARRIAGELENTH*2+HEADTAILLENTH/2)*AMPLIFICATORY_TIMES-4);
			m_CarriageTrain[0].SetCarriagePos(m_pSetpos);
			//根据上下行设置车辆头部
			m_CarriageTrain[0].SetCarriageStyle(2);
			//下行
			if (m_bDirection==1)
			{
				m_CarriageTrain[0].SetCarriageDir(FALSE);
			} 
			//上行
			else
			{
				m_CarriageTrain[0].SetCarriageDir(TRUE);
			}
			m_pSetpos.x=(int)(m_fTrainPos.x-(CARRIAGELENTH+CARRIAGELENTH/2)*AMPLIFICATORY_TIMES-4);
			m_CarriageTrain[1].SetCarriagePos(m_pSetpos);
			m_pSetpos.x=(int)(m_fTrainPos.x-(CARRIAGELENTH/2)*AMPLIFICATORY_TIMES-2);
			m_CarriageTrain[2].SetCarriagePos(m_pSetpos);
			m_pSetpos.x=(int)(m_fTrainPos.x+(CARRIAGELENTH/2)*AMPLIFICATORY_TIMES+2);
			m_CarriageTrain[3].SetCarriagePos(m_pSetpos);
			m_pSetpos.x=(int)(m_fTrainPos.x+(CARRIAGELENTH+CARRIAGELENTH/2)*AMPLIFICATORY_TIMES+4);
			m_CarriageTrain[4].SetCarriagePos(m_pSetpos);
			m_pSetpos.x=(int)(m_fTrainPos.x+(CARRIAGELENTH*2+HEADTAILLENTH/2)*AMPLIFICATORY_TIMES+7);
			m_CarriageTrain[5].SetCarriagePos(m_pSetpos);
			m_CarriageTrain[5].SetCarriageStyle(1);
			//下行
			if (m_bDirection==1)
			{
				m_CarriageTrain[5].SetCarriageDir(FALSE);
			} 
			//上行
			else
			{
				m_CarriageTrain[5].SetCarriageDir(TRUE);
			}
			break;
		}
		/*
	case 4:
		{
			m_pSetpos.x=(int)(m_fTrainPos.x-(CARRIAGELENTH*2+HEADTAILLENTH/2)*AMPLIFICATORY_TIMES-4);
			m_CarriageTrain[0].SetCarriagePos(m_pSetpos);
			m_CarriageTrain[0].SetCarriageStyle(2);
			
			m_pSetpos.x=(int)(m_fTrainPos.x-(CARRIAGELENTH+CARRIAGELENTH/2)*AMPLIFICATORY_TIMES-5);
			
			m_CarriageTrain[1].SetCarriagePos(m_pSetpos);
			
			m_pSetpos.x=(int)(m_fTrainPos.x-(CARRIAGELENTH/2)*AMPLIFICATORY_TIMES-3);
			m_CarriageTrain[2].SetCarriagePos(m_pSetpos);
			
			m_pSetpos.x=(int)(m_fTrainPos.x+(CARRIAGELENTH/2)*AMPLIFICATORY_TIMES+3);
			m_CarriageTrain[3].SetCarriagePos(m_pSetpos);
			
			m_pSetpos.x=(int)(m_fTrainPos.x+(CARRIAGELENTH+CARRIAGELENTH/2)*AMPLIFICATORY_TIMES+5);
			m_CarriageTrain[4].SetCarriagePos(m_pSetpos);
			
			
			m_pSetpos.x=(int)(m_fTrainPos.x+(CARRIAGELENTH*2+HEADTAILLENTH/2)*AMPLIFICATORY_TIMES+7);
			m_CarriageTrain[5].SetCarriagePos(m_pSetpos);
			m_CarriageTrain[5].SetCarriageStyle(1);
			break;
		}
		*/
	}
	
	for (int i=0;i<6;i++)
	{
		m_CarriageTrain[i].Showcarriage(pClientDC,i);
	}
	
}
