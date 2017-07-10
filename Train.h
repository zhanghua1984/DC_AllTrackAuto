// Train.h: interface for the CTrain class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRAIN_H__F7C8086A_AE19_4F30_9687_8CFF4F879868__INCLUDED_)
#define AFX_TRAIN_H__F7C8086A_AE19_4F30_9687_8CFF4F879868__INCLUDED_
#include "Carriage.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Carriage.h"
class CTrain  
{
private:
	POINT m_fTrainPos;
	//运行方向，下行向右为正向
	BOOL	m_bDirection;
	BOOL	m_bHead;

public:
	CCarriage m_CarriageTrain[6];
public:
	CTrain();
	virtual ~CTrain();
	SetTrainPos(POINT m_ppos);
	SetTrainHead(BOOL m_bhead);
	SetTrainDirection(BOOL m_bDirect);
//	ShowTrain(CDC* pDC);
	ShowTrain(CDC* pClientDC);
};

#endif // !defined(AFX_TRAIN_H__F7C8086A_AE19_4F30_9687_8CFF4F879868__INCLUDED_)
