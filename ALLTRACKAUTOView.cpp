// ALLTRACKAUTOView.cpp : implementation of the CALLTRACKAUTOView class
//

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "ALLTRACKAUTOSet.h"
#include "ALLTRACKAUTODoc.h"
#include "CntrItem.h"
#include "ALLTRACKAUTOView.h"
#include "alldefine.h"
#include "PARPINFO.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CALLTRACKAUTOSet m_alltrack[TRACKNUMBER];	//全线轨道
CALLTRACKAUTOSet m_uptrack[TRACKUP];	//上行轨道
CALLTRACKAUTOSet m_downtrack[TRACKDOWN];	//下行轨道
Station m_station[20];
SpeedLine	m_speedheadline;
SpeedLine	m_speedtailline;
BOOL	m_bLoadAllTrackFinish;
CSpeedTable m_speedtable;
int		m_nTrackView;	//轨道视图
int		m_nTrainView;	//列车视图
BOOL	m_bViewOn;
extern BYTE m_byteCom[];
extern BYTE	m_byteWriteStatus[];
extern BYTE	m_byteWriteTrackCode[];
extern BYTE	m_byteWriteCaputCauda[];
extern BYTE	m_byteWritePAPR70[];
extern BYTE	m_byteWritePAPR10[];
extern BYTE	m_byteWriteNPAPR80[];
extern BYTE	m_byteWriteNPAPR20[];
extern BYTE m_byteWriteDebug[];
extern BOOL m_bSendStatus;
extern BOOL m_bSendHD;
extern BOOL	m_bSendCode;
extern BOOL	m_bSendNPAPR;
extern BOOL m_bSendNPAPRF;
extern BOOL	m_bSendPAPR;
extern BOOL	m_bSendPAPRF;
POINT m_pTrainpos;				//车辆在轨道位置
POINT m_pTrainShowpos;			//车辆显示位置
CRUNNINGMSG * m_dlgmsg;
CSHOWMSG	m_showmsg;			//操作命令显示
CSHOWMSG	m_showautomsg;		//自动命令
CSHOWMSG	m_showstatusmsg;	//状态
CSHOWMSG	m_showhdmsg;		//头尾车
CSHOWMSG	m_showtcode;		//轨道码
CSHOWMSG	m_shownpapr;		//无源信标
CSHOWMSG	m_showpapr;			//有源信标
CSHOWMSG	m_showrunning;		//运行信息
MACRO	m_macro;
CTRACKCODE	m_trackcode;
CRect		m_rcClient;					//客户区
double		m_dgmail;			//全局行驶里程
double		m_dgaddmail;		//全局行驶里程增量
BOOL		m_bDirectorup;
int			m_ngTrainpos;		//全局车辆显示位置
int			m_ngTrainhigh;		//全局车辆高度
float		m_fgantennapos;
int			m_ngtrackpointer;
int			m_gnAPRpointer;
float		m_fgaproldadd;
float		m_fgtrackcode;
double		m_dgspeed;
COLORREF	m_colorgline;
COLORREF	m_colorgfont;
COLORREF	m_colorgapr;
PROMPTINFO	m_promptinfonexttrack;
PROMPTINFO	m_promptinfoCFCT;
PROMPTINFO	m_promptinfoshow;
PROMPTINFO	m_promptinfoMailandV;
PROMPTINFO	m_promptinfoAPRreturn;
PROMPTINFO	m_promptinfoStatus;
PROMPTINFO	m_promptinfoParser;
BOOL		m_bCarrayFruChangeTest;
BYTE		m_byteaCFCT[40];
BYTE 		m_bytepCFCT;
BOOL		m_bshowhandle;
BOOL		m_bshowauto;
BOOL		m_bshowreturn1;
BOOL		m_bshowreturn2;
BOOL		m_bshowreturn3;
BOOL		m_bshowdebug;
BOOL		m_bshowcalculate;
BOOL		m_bdisablefsb;
BOOL		m_bdisableeb;
BOOL		m_bEBvalid;
BOOL		m_bDisableNone;
BOOL		m_bprioritygrow;			//折轨优先级
CTrain		m_Train;
BOOL		m_bAutoBreak;
BOOL		m_bShowTrain;
int			m_nTrackPriority[2][3];		//轨道进路优先级
int			m_nNormalTrackPriority;		//直轨优先级
int			m_nFoldTrackPriority;		//折轨优先级
BOOL		m_bgoahead;					//行车方向
BOOL		m_bhead1;					//1号车是否为头车
BOOL		m_bDefaultLowEndHigh;		//默认走高度低轨道
int			m_nTrackEndPos;				//轨道结束点
int			m_nGapOffSet;				//码间隙偏移量
BOOL		m_bAutoStop;
ANTENNA		m_antenna;
READER		m_reader;
BOOL		m_bSendAPR;
//以下变量用于计算车辆位置
double		m_dgTrainTrunPos;			//车辆切头尾位置
double		m_dgTrainRealPos;			//全局车辆实际位置
double		m_dgTrainAddPos;			//新增加里程
double		m_dgTrainReverseDis;
float		m_fgTrainOffSet;
BOOL		m_bgFirstReverse;
BOOL		m_bgTrackEndPosCalculate;	//轨道结束点是否已经进行过计算
BOOL		m_bgSendCurrentTrackCode;
float		m_fgantennaforshow;
float		m_fgreaderforshow;
BOOL		m_bAutoStopPoint;
double		m_dAutoStopPoint;
float		m_fgtrainclasp;
//二次发送
int			m_gnAntennaNumber;
int			m_gnSecondCodepos;
int			m_gnSecondcode;

//轨道查找方法
int			m_gnuplastpointer;
int			m_gndownlastpointer;

PARPINFO	m_papr[3];
BOOL		m_bForbidSendPAPR;
BOOL		m_boolmsb4;
BOOL		m_boolisfold;
unsigned int  Wheel_Diametear[10]=
{
		0,
		774,
		783,
		791,
		800,
		809,
		818,
		826,
		835,
		840
};

//串口相关变量
#include "Includes.h"
#include "COMPORT.h"

BOOL	m_bWorking;
BOOL	m_bHighSpeed;
extern BOOL	m_bThreadRXrunning;
extern BOOL	m_bThreadTXrunning;
extern HANDLE hCom2; //串口
extern  BYTE	m_byteRXbuffer[BUFFERLENTH];
BYTE	m_byteFrame[24];
extern BYTE	m_byteWriteFrame1[24];
extern BYTE	m_byteWriteFrame2[24];
extern BYTE	m_byteWriteFrame3[24];
extern BYTE	m_byteWriteFrame4[24];
BOOL	m_bConnectCom;	//串口是否连接
extern BOOL	m_bSendPackage;
#define MAXQSIZE BUFFERLENTH

/*利用循环队列实现循环缓冲*/

typedef BYTE QElemType ; //定义新类型名 

typedef struct
{
	QElemType *base;  //循环队列的存储空间 （ 用数组指针指示存储实际长度10字节的字符串) 
	int front;  //队头元素下标（取元素） 
	int rear;  //队尾元素下标（插入元素） 
}SqQueue;            

//建立循环队列（循环缓冲区）
int InitQueue(SqQueue &Q)
{
    Q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
    if(!Q.base) 
		return -1;  //创建失败，返回-1 
    Q.front=0;
    Q.rear=0;
    return 0;    //创建成功，返回0 
}    

//插入元素（入队列）
int EnQueue(SqQueue &Q,QElemType e)
{
    if((Q.rear+1)%MAXQSIZE==Q.front)	//下一个是否和读取指针重回
		return -1;  //队满
    //memcpy(Q.base[Q.rear],e);  //赋值
	Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;  //下标加一 
    return 0;  //入队成功
}

//取元素(数组指针，指向取到的值） 
int DeQueue(SqQueue &Q,QElemType &e)
{
    if(Q.rear==Q.front)
        return -1;   //队空
    //memcpy(e,Q.base[Q.front]);
	e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE; //下标加一 
    return 0;  //成功
}  

int QueueLenth(SqQueue Q)
{
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

SqQueue q;  //数据结构 环形缓冲区队列
int flag; 
QElemType strIn,strOut;


//串口变量结束





/////////////////////////////////////////////////////////////////////////////
// CALLTRACKAUTOView

IMPLEMENT_DYNCREATE(CALLTRACKAUTOView, CRecordView)

BEGIN_MESSAGE_MAP(CALLTRACKAUTOView, CRecordView)
	//{{AFX_MSG_MAP(CALLTRACKAUTOView)
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, OnCancelEditCntr)
	ON_WM_TIMER()
	ON_MESSAGE(WM_MY_DLGUPDATEVIEW, OnMyDLGMessage)
	ON_MESSAGE(WM_UC_MESSAGE, OnMyCOMMessage)
	ON_MESSAGE(WM_UC_WRITE, OnMyCOMWrite)
	ON_MESSAGE(WM_CLEARFLAG, OnMyClearFlag)
	ON_MESSAGE(WM_SAVETURNPOS, OnMySaveTurnPos)
	ON_MESSAGE(WM_AUTOSTOP, OnMyAutoStop)
	ON_MESSAGE(WM_TARGETSPEED, OnMyOnTargetSpeed)
	ON_MESSAGE(WM_SENDCURRENTTRACKCODE,OnMySendCurrentTrackCode)
	ON_MESSAGE(WM_SENDSECONDCODE,OnMySendSecondTrackCode)
	ON_MESSAGE(WM_SETTRAINPOS,OnResetTrainPos)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
	ON_MESSAGE(WM_LOADALLTRACK,OnThreadMessage)
	ON_MESSAGE(WM_NEXTTRACK,OnThreadSendCode)
	ON_MESSAGE(WM_NEXTAPR,OnThreadSendAPR)
	ON_MESSAGE(WM_RX,OnThreadRXMessage)
	ON_MESSAGE(WM_FINDAVACOMPORT,OnReceiveAComPort)
	ON_MESSAGE(WM_UCOM_WRITE,OnWriteComPortMSG)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CALLTRACKAUTOView construction/destruction

CALLTRACKAUTOView::CALLTRACKAUTOView()
	: CRecordView(CALLTRACKAUTOView::IDD)
{
	//{{AFX_DATA_INIT(CALLTRACKAUTOView)
		// NOTE: the ClassWizard will add member initialization here
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	m_pSelection = NULL;
	// TODO: add construction code here
	m_noldmail=0;
	m_bViewOn=TRUE;	//视角跟随列车
	//设置显示位置
	m_showautomsg.SetPos(SHOWMSGPOS,0);		//自动命令
	m_showstatusmsg.SetPos(SHOWMSGPOS+SHOWMSGGAP,0);	//状态
	m_showhdmsg.SetPos(SHOWMSGPOS+SHOWMSGGAP*2,0);		//头尾车
	m_showhdmsg.SetStyle(4);
	m_showtcode.SetPos(SHOWMSGPOS+SHOWMSGGAP*3,0);		//轨道码
	m_shownpapr.SetPos(SHOWMSGPOS+SHOWMSGGAP*4,0);		//无源信标
	m_showrunning.SetPos(SHOWMSGPOS+SHOWMSGGAP*5,0);		//运行信息
	m_showpapr.SetPos(SHOWMSGPOS+SHOWMSGGAP*7,0);			//有源信标
}

CALLTRACKAUTOView::~CALLTRACKAUTOView()
{
	//m_station->Delete();

}

void CALLTRACKAUTOView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CALLTRACKAUTOView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CALLTRACKAUTOView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CALLTRACKAUTOView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_aLLTRACKAUTOSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();


	// TODO: remove this code when final selection model code is written
	m_pSelection = NULL;    // initialize selection
	//初始化
	GlobalInit();
}

/////////////////////////////////////////////////////////////////////////////
// CALLTRACKAUTOView printing

BOOL CALLTRACKAUTOView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CALLTRACKAUTOView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CALLTRACKAUTOView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CALLTRACKAUTOView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used.
   CRecordView::OnDestroy();
   
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   
}


/////////////////////////////////////////////////////////////////////////////
// OLE Client support and commands

BOOL CALLTRACKAUTOView::IsSelected(const CObject* pDocItem) const
{
	// The implementation below is adequate if your selection consists of
	//  only CALLTRACKAUTOCntrItem objects.  To handle different selection
	//  mechanisms, the implementation here should be replaced.

	// TODO: implement this function that tests for a selected OLE client item

	return pDocItem == m_pSelection;
}

void CALLTRACKAUTOView::OnInsertObject()
{
	// Invoke the standard Insert Object dialog box to obtain information
	//  for new CALLTRACKAUTOCntrItem object.
	COleInsertDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();

	CALLTRACKAUTOCntrItem* pItem = NULL;
	TRY
	{
		// Create new item connected to this document.
		CALLTRACKAUTODoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CALLTRACKAUTOCntrItem(pDoc);
		ASSERT_VALID(pItem);

		// Initialize the item from the dialog data.
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // any exception will do
		ASSERT_VALID(pItem);
		
        if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
			pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);

		// As an arbitrary user interface design, this sets the selection
		//  to the last item inserted.

		// TODO: reimplement selection as appropriate for your application

		m_pSelection = pItem;   // set selection to last inserted item
		pDoc->UpdateAllViews(NULL);
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the container (not the server) causes the deactivation.
void CALLTRACKAUTOView::OnCancelEditCntr()
{
	// Close any in-place active item on this view.
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// Special handling of OnSetFocus and OnSize are required for a container
//  when an object is being edited in-place.
void CALLTRACKAUTOView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// need to set focus to this item if it is in the same view
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // don't call the base class
			return;
		}
	}

	CRecordView::OnSetFocus(pOldWnd);
}

void CALLTRACKAUTOView::OnSize(UINT nType, int cx, int cy)
{
	CRecordView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

/////////////////////////////////////////////////////////////////////////////
// CALLTRACKAUTOView diagnostics

#ifdef _DEBUG
void CALLTRACKAUTOView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CALLTRACKAUTOView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CALLTRACKAUTODoc* CALLTRACKAUTOView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CALLTRACKAUTODoc)));
	return (CALLTRACKAUTODoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CALLTRACKAUTOView database support
CRecordset* CALLTRACKAUTOView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CALLTRACKAUTOView message handlers

void CALLTRACKAUTOView::GlobalInit()
{
	m_bLoadAllTrackFinish=FALSE;
	//轨道信息加载线程
	pThread=AfxBeginThread(ThreadLoadingTrack,(LPVOID)GetSafeHwnd());
	//查找轨道码线程
	pThreadSeek=AfxBeginThread(ThreadSeekTrackData,(LPVOID)GetSafeHwnd());
	//查找是否发送APR线程
	pThreadAPR=AfxBeginThread(ThreadISSendAPR,(LPVOID)GetSafeHwnd());
	//初始车辆位置
	m_ngTrainpos=0;		//全局车辆显示位置
	m_pTrainpos.x=m_ngTrainpos;
	m_ngTrainhigh=494;		//全局车辆高度
	m_pTrainpos.y=m_ngTrainhigh;
	m_nTrackView=0;
	m_nTrainView=0;
//	SetTimer(1,1,NULL);
	CCom	m_com;
	m_dlgmsg = new CRUNNINGMSG();
	m_dlgmsg->Create(IDD_DIALOGMSG);
	m_dgmail=0;
	m_bDirectorup=FALSE;	//默认下行
	m_fgantennapos=(float)3.2;
	m_ngtrackpointer=0;
	m_fgaproldadd=0;
	m_fgtrackcode=0;
	m_dgspeed=0;
	m_bAlreadyClear=FALSE;

	m_colorgline=RGB(50,80,180);
	m_colorgfont=RGB(16, 78, 139);
	m_colorgapr=RGB(20,180,80);
	//默认不开启载频变换测试
	m_bCarrayFruChangeTest=FALSE;
	//载频测试赋值
	m_byteaCFCT[0]=2;
	m_byteaCFCT[1]=1;
	m_byteaCFCT[2]=4;
	m_byteaCFCT[3]=1;
	m_byteaCFCT[4]=6;
	m_byteaCFCT[5]=1;
	m_byteaCFCT[6]=8;
	m_byteaCFCT[7]=2;
	m_byteaCFCT[8]=4;
	m_byteaCFCT[9]=2;
	m_byteaCFCT[10]=5;
	m_byteaCFCT[11]=2;
	m_byteaCFCT[12]=7;
	m_byteaCFCT[13]=2;
	m_byteaCFCT[14]=8;
	m_byteaCFCT[15]=3;
	m_byteaCFCT[16]=4;
	m_byteaCFCT[17]=3;
	m_byteaCFCT[18]=6;
	m_byteaCFCT[19]=3;
	m_byteaCFCT[20]=8;
	m_byteaCFCT[21]=4;
	m_byteaCFCT[22]=5;
	m_byteaCFCT[23]=4;
	m_byteaCFCT[24]=6;
	m_byteaCFCT[25]=4;
	m_byteaCFCT[26]=7;
	m_byteaCFCT[27]=4;
	m_byteaCFCT[28]=8;
	m_byteaCFCT[29]=5;
	m_byteaCFCT[30]=7;
	m_byteaCFCT[31]=5;
	m_byteaCFCT[32]=8;
	m_byteaCFCT[33]=6;
	m_byteaCFCT[34]=8;
	m_byteaCFCT[35]=7;
	m_byteaCFCT[36]=8;
	m_byteaCFCT[37]=1;
	m_byteaCFCT[38]=3;
	m_byteaCFCT[39]=1;

	m_bytepCFCT	= 0;

	m_bshowhandle=TRUE;
	m_bshowauto=TRUE;
	m_bshowreturn1=TRUE;
	m_bshowreturn2=TRUE;
	m_bshowreturn3=TRUE;
	m_bshowdebug=TRUE;
	m_bshowcalculate=TRUE;
	m_bdisablefsb=FALSE;
	m_bdisableeb=FALSE;
	m_bEBvalid=FALSE;
	m_bDisableNone=TRUE;
	m_bAutoBreak=FALSE;
	m_bShowTrain=TRUE;
	//数字越小优先级越高
	m_nNormalTrackPriority=1;		//直轨优先级
	m_nFoldTrackPriority=10;		//折轨优先级
	m_bgoahead=TRUE;					//默认前进
	m_bhead1=TRUE;					//默认1号车为头车
	m_bDefaultLowEndHigh=TRUE;		//默认走轨道高度低的岔子
	m_nTrackEndPos=0;
	m_dgTrainTrunPos=0;			//车辆切头尾位置
	m_dgTrainRealPos=0;			//全局车辆实际位置
	m_dgTrainAddPos=0;			//新增加里程
	m_fgTrainOffSet=126;
	m_dgTrainReverseDis=0;
	m_bReverse=FALSE;
	m_bgFirstReverse=TRUE;		//首次反向
	m_bgTrackEndPosCalculate=FALSE;
	m_bgSendCurrentTrackCode=FALSE;	//是否发送当前轨道码
	m_bprioritygrow=TRUE;			//轨道优先级默认采用降级的增长方式
	m_bAutoStop=FALSE;
	m_bAutoStopPoint=FALSE;
	m_bSendAPR=TRUE;
	m_bHardwareReset=TRUE;
	m_gnuplastpointer=TRACKUP;		//从后向前找
	m_gndownlastpointer=0;			//从前向后找

	m_bForbidSendPAPR=FALSE;
	LoadConfig();					//加载全局配置文件
	Init();
	SetTimer(2,2000,NULL);			//5秒后初始化其它设置

	m_boolisfold=FALSE;
}

UINT ThreadISSendAPR(LPVOID lpParam)
{
	MSG m_msgapr;
	while(TRUE)
	{
		GetMessage(&m_msgapr,NULL,0,0);
		switch (m_msgapr.message)
		{
		case WM_SEEKISSENDAPR:
			{
				if (m_bLoadAllTrackFinish==TRUE)
				{					
					float m_fantenna=0;
					float m_fnpapr=0;
					float	m_ftrackstartpos;
					//阅读器距离车辆最前端18.574米
					//1号车为头车
					if (m_bhead1==TRUE)
					{
						//向前
						if (m_bgoahead==TRUE)
						{
							//阅读器位置计算
							m_reader.SetReaderNumber(1);
							m_fantenna=m_reader.GetReaderPos();
							m_fgreaderforshow=m_fantenna;
							CString m_str;
							m_str.Format("%f",m_fantenna-DISTANCE);
							m_str.Insert(0,"1号阅读器位置:");
							m_promptinfoMailandV.SetCString(9,m_str);
						} 
						//向后
						else
						{
							m_reader.SetReaderNumber(2);
							m_fantenna=m_reader.GetReaderPos();
							m_fgreaderforshow=m_fantenna;
							CString m_str;
							m_str.Format("%f",m_fantenna+DISTANCE);
							m_str.Insert(0,"2号阅读器位置:");
							m_promptinfoMailandV.SetCString(9,m_str);
						}
					} 
					else
					{
						//向前
						if (m_bgoahead==TRUE)
						{
							//阅读器位置计算
							m_reader.SetReaderNumber(4);
							m_fantenna=m_reader.GetReaderPos();
							m_fgreaderforshow=m_fantenna;
							CString m_str;
							m_str.Format("%f",m_fantenna+DISTANCE);
							m_str.Insert(0,"4号阅读器位置:");
							m_promptinfoMailandV.SetCString(9,m_str);
						} 
						//向后
						else
						{
							//阅读器位置计算
							m_reader.SetReaderNumber(3);
							m_fantenna=m_reader.GetReaderPos();
							m_fgreaderforshow=m_fantenna;
							CString m_str;
							m_str.Format("%f",m_fantenna-DISTANCE);
							m_str.Insert(0,"3号阅读器位置:");
							m_promptinfoMailandV.SetCString(9,m_str);
						}
					}
					//上下行
					if (m_bDirectorup)
					{

						//改变发送APR方式
						int	m_ndowntrackendhigh;
						for (int up= m_gnuplastpointer;up>0;up--)
						{
							//APR搜索条件，APR所在轨道和车辆在同一高度上，APR未发送过，阅读器在APR检测范围内
							m_ndowntrackendhigh=m_uptrack[up].m_TRACKENDHIGH;
							//阅读器在该轨道上，则轨道结束高度和车辆高度相等
							//寻找无源APR
							if ((m_ndowntrackendhigh==(m_ngTrainhigh+TRAINTOTRACK))&&(m_uptrack[up].m_btNPAPRsend==FALSE)&&(m_uptrack[up].m_ISFOLD==m_boolisfold))	//与当前轨高相等认为该车在当前轨上
							{

								m_ftrackstartpos=(float)(m_uptrack[up].m_Tstartpos);
								m_fnpapr=(float)(m_uptrack[up].m_NPAPRpos);
								m_fnpapr=m_ftrackstartpos-m_fnpapr;
								m_fnpapr=m_fnpapr/100;
								if ((m_fantenna>=m_fnpapr)&&(m_fantenna<=m_fnpapr+1))
								{				
									//无源	轨道指针
									int	m_naprid=0;
									float m_fchangepos=0;
									m_naprid=strtoul(m_uptrack[up].m_NPAPRnumber,NULL,16);
									m_fchangepos=(float)(m_dgmail+DISTANCE);
									m_fchangepos=m_fchangepos*1000;
									if (m_bSendAPR==TRUE)
									{
										m_gnAPRpointer=up;
										m_boolmsb4=m_naprid&0x40000000;
										if (!m_boolmsb4)
										{
											m_naprid=m_naprid|0x40000000;	
										} 
										::PostMessage((HWND)lpParam, WM_NEXTAPR, m_naprid, (LPARAM)m_fchangepos);
									}
								}
							}
							//查找第二个无源APR
							if ((m_ndowntrackendhigh==(m_ngTrainhigh+TRAINTOTRACK))&&(m_uptrack[up].m_btNPAPR2send==FALSE))	//与当前轨高相等认为该车在当前轨上
							{
								m_ftrackstartpos=(float)(m_uptrack[up].m_Tstartpos);
								m_fnpapr=(float)(m_uptrack[up].m_NPAPR2pos);
								if (m_fnpapr!=0)
								{
									m_fnpapr=m_ftrackstartpos-m_fnpapr;
									m_fnpapr=m_fnpapr/100;
									if ((m_fantenna>=m_fnpapr)&&(m_fantenna<=m_fnpapr+1))
									{				
										//无源	轨道指针
										int	m_naprid=0;
										float m_fchangepos=0;
										m_naprid=strtoul(m_uptrack[up].m_NPAPR2number,NULL,16);
										m_fchangepos=(float)(m_dgmail+DISTANCE);
										m_fchangepos=m_fchangepos*1000;
										if (m_bSendAPR==TRUE)
										{
											m_gnAPRpointer=up;
											m_uptrack[up].m_btNPAPR2send=TRUE;
											m_boolmsb4=m_naprid&0x40000000;
											if (!m_boolmsb4)
											{
												m_naprid=m_naprid|0x40000000;	
											} 
											::PostMessage((HWND)lpParam, WM_NEXTAPR, m_naprid, (LPARAM)m_fchangepos);
										}
									}
								}
							}

							//寻找有源ARP
							if (m_bForbidSendPAPR==FALSE)
							{
								if ((m_ndowntrackendhigh==(m_ngTrainhigh+TRAINTOTRACK))&&(m_uptrack[up].m_btNPAPRsend==FALSE)&&(m_uptrack[up].m_Psignalpos!=0))	//与当前轨高相等认为该车在当前轨上
								{
									m_ftrackstartpos=(float)(m_uptrack[up].m_Tstartpos);
									m_fnpapr=(float)(m_uptrack[up].m_Psignalpos);
									m_fnpapr=m_ftrackstartpos-m_fnpapr;
									m_fnpapr=m_fnpapr/100;
									if ((m_fantenna>=m_fnpapr)&&(m_fantenna<=m_fnpapr+1))
									{				
										//无源	轨道指针
										int	m_naprid=0;
										float m_fchangepos=0;
										m_naprid=strtoul(m_uptrack[up].m_PAPRcode,NULL,16);
										m_fchangepos=(float)(m_dgmail+DISTANCE);
										m_fchangepos=m_fchangepos*1000;
										if (m_bSendAPR==TRUE)
										{
											m_gnAPRpointer=up;
											//m_naprid=m_naprid|0x30000000;
											::PostMessage((HWND)lpParam, WM_NEXTAPR, m_naprid, (LPARAM)m_fchangepos);
											
										}
									}
								}
							}
						}
					} 
					else
					{

						//改变发送APR方式
						int	m_ndowntrackendhigh;
						for (int down=0;down<TRACKDOWN;down++)
						{
							//APR搜索条件，APR所在轨道和车辆在同一高度上，APR未发送过，阅读器在APR检测范围内

							m_ndowntrackendhigh=m_downtrack[down].m_TRACKENDHIGH;
							//阅读器在该轨道上，则轨道结束高度和车辆高度相等
							//寻找无源APR
							if ((m_ndowntrackendhigh==(m_ngTrainhigh+TRAINTOTRACK))&&(m_downtrack[down].m_btNPAPRsend==FALSE))	//与当前轨高相等认为该车在当前轨上
							{
								m_ftrackstartpos=(float)(m_downtrack[down].m_Tstartpos);
								m_fnpapr=(float)(m_downtrack[down].m_NPAPRpos);
								m_fnpapr+=m_ftrackstartpos;
								m_fnpapr=m_fnpapr/100;
								if ((m_fantenna>=m_fnpapr)&&(m_fantenna<=m_fnpapr+1))
								{				
									//无源	轨道指针
									int	m_naprid=0;
									float m_fchangepos=0;
									m_naprid=strtoul(m_downtrack[down].m_NPAPRnumber,NULL,16);
									m_fchangepos=(float)(m_dgmail+DISTANCE);
									m_fchangepos=m_fchangepos*1000;
									if (m_bSendAPR==TRUE)
									{
										m_gnAPRpointer=down;
										m_boolmsb4=m_naprid&0x40000000;
										if (!m_boolmsb4)
										{
											m_naprid=m_naprid|0x40000000;	
										} 
										::PostMessage((HWND)lpParam, WM_NEXTAPR, m_naprid, (LPARAM)m_fchangepos);
										
									}
								}
							}
							//查找第二个无源APR
							if ((m_ndowntrackendhigh==(m_ngTrainhigh+TRAINTOTRACK))&&(m_downtrack[down].m_btNPAPR2send==FALSE))	//与当前轨高相等认为该车在当前轨上
							{
								m_ftrackstartpos=(float)(m_downtrack[down].m_Tstartpos);
								m_fnpapr=(float)(m_downtrack[down].m_NPAPR2pos);
								if (m_fnpapr!=0)
								{
									m_fnpapr+=m_ftrackstartpos;
									m_fnpapr=m_fnpapr/100;
									if ((m_fantenna>=m_fnpapr)&&(m_fantenna<=m_fnpapr+1))
									{				
										//无源	轨道指针
										int	m_naprid=0;
										float m_fchangepos=0;
										m_naprid=strtoul(m_downtrack[down].m_NPAPR2number,NULL,16);
										m_fchangepos=(float)(m_dgmail+DISTANCE);
										m_fchangepos=m_fchangepos*1000;
										if (m_bSendAPR==TRUE)
										{
											m_gnAPRpointer=down;
											m_boolmsb4=m_naprid&0x40000000;
											if (!m_boolmsb4)
											{
												m_naprid=m_naprid|0x40000000;	
											} 
											::PostMessage((HWND)lpParam, WM_NEXTAPR, m_naprid, (LPARAM)m_fchangepos);
										}
									}
								}
							}

							//寻找有源APR
							if (m_bForbidSendPAPR==FALSE)
							{
								if ((m_ndowntrackendhigh==(m_ngTrainhigh+TRAINTOTRACK))&&(m_downtrack[down].m_btPAPRsend==FALSE)&&(m_downtrack[down].m_Psignalpos!=0))	//与当前轨高相等认为该车在当前轨上
								{
									m_ftrackstartpos=(float)(m_downtrack[down].m_Tstartpos);
									m_fnpapr=(float)(m_downtrack[down].m_Psignalpos);
									m_fnpapr+=m_ftrackstartpos;
									m_fnpapr=m_fnpapr/100;
									if ((m_fantenna>=m_fnpapr)&&(m_fantenna<=m_fnpapr+1))
									{				
										//无源	轨道指针
										int	m_naprid=0;
										float m_fchangepos=0;
										m_naprid=strtoul(m_downtrack[down].m_PAPRcode,NULL,16);
										m_fchangepos=(float)(m_dgmail+DISTANCE);
										m_fchangepos=m_fchangepos*1000;
										if (m_bSendAPR==TRUE)
										{
											m_gnAPRpointer=down;
											m_naprid=m_naprid|0x20000000;
											::PostMessage((HWND)lpParam, WM_NEXTAPR, m_naprid, (LPARAM)m_fchangepos);
										}
									}
								}
							}
							//无源低速APR
							
							if ((m_ndowntrackendhigh==(m_ngTrainhigh+TRAINTOTRACK)))	//与当前轨高相等认为该车在当前轨上
							{
								if ((m_downtrack[down].m_LNPAPR1pos)&&(m_downtrack[down].m_LNPAPR1number))
								{
									m_ftrackstartpos=(float)(m_downtrack[down].m_Tstartpos);
									m_fnpapr=(float)(m_downtrack[down].m_LNPAPR1pos);
									m_fnpapr+=m_ftrackstartpos;
									m_fnpapr=m_fnpapr/100;
									if ((m_fantenna>=m_fnpapr)&&(m_fantenna<=m_fnpapr+2))
									{				
										//无源	轨道指针
										int	m_naprid=0;
										float m_fchangepos=0;
										m_naprid=strtoul(m_downtrack[down].m_LNPAPR1number,NULL,16);
										m_fchangepos=(float)(m_dgmail+DISTANCE);
										m_fchangepos=m_fchangepos*1000;
										if (m_bSendAPR==TRUE)
										{
											m_gnAPRpointer=down;
											//m_naprid=m_naprid|0x40000000;
											::PostMessage((HWND)lpParam, WM_NEXTAPR, m_naprid, (LPARAM)m_fchangepos);
											
										}
									}
								}
							}
						}
					}
				}
				break;
			}
		}
		Sleep(1);
	}
	return 0;
}
UINT ThreadSeekTrackData(LPVOID lpParam)
{
	MSG m_msg;
	while(TRUE)
	{
		GetMessage(&m_msg,NULL,0,0);
		switch (m_msg.message)
		{
		case WM_SEEKTRACKDATA:
			{	
				//每次计算天线位置，保持数据最新
				//天线位置=车位置+车身长度/2 - 天线安装位置 +行车距离
				//判断天线位置是否到达轨道起始点+-2米位置
				if (m_bLoadAllTrackFinish==TRUE)
				{
					float	m_fantenna=0;
					float	m_ftrackstartpos=0;
					int		m_ntrainhigh=0;
					int		m_ntrackhigh=0;
					//计算车辆高度
					m_ntrainhigh=m_ngTrainhigh+TRAINTOTRACK;	//与当前轨高相等认为该车在当前轨上
					if (m_bhead1==TRUE)
					{
						//1号车为头车
						if (m_bgoahead==TRUE)
						{
							//行车方向，前进
							m_bDirectorup=FALSE;
							m_antenna.SetAntennaNumber(1);
							m_gnAntennaNumber=1;
							m_fantenna=m_antenna.GetAntennaPos();
							m_fgantennaforshow=m_fantenna;
							//未发送当前轨道码
							if (m_bgSendCurrentTrackCode==FALSE)
							{
								::PostMessage((HWND)lpParam, WM_SENDCURRENTTRACKCODE, 1, (int)m_fantenna*100);
								m_bgSendCurrentTrackCode=TRUE;
							}
							CString m_str;
							m_str.Format("%f",m_fantenna-DISTANCE);
							m_str.Insert(0,"1号天线位置:");
							m_promptinfoMailandV.SetCString(8,m_str);

							//必为下行
							m_ftrackstartpos=(float)m_downtrack[m_ngtrackpointer].m_Tstartpos;
							m_ftrackstartpos=m_ftrackstartpos/100;
							
							m_fgtrainclasp=m_fantenna-DISTANCE+(float)ANTENNATOCUSP;
							m_str.Format("%f",m_fgtrainclasp);
							m_str.Insert(0,"1号车钩位置:");
							m_promptinfoMailandV.SetCString(3,m_str);
							//位置速度
							m_str.Format("%f",m_fgtrainclasp);
							m_str.Insert(0,"车辆位置:");
							m_promptinfoMailandV.SetCString(1,m_str);
							
							m_str.Format("%f",m_dgspeed);
							m_str.Insert(0,"车辆速度:");
							m_promptinfoMailandV.SetCString(0,m_str);
						} 
						else
						{
							//行车方向，后退
							m_bDirectorup=TRUE;
							m_antenna.SetAntennaNumber(2);
							m_gnAntennaNumber=2;
							m_fantenna=m_antenna.GetAntennaPos();
							m_fgantennaforshow=m_fantenna;
							//未发送当前轨道码
							if (m_bgSendCurrentTrackCode==FALSE)
							{
								::PostMessage((HWND)lpParam, WM_SENDCURRENTTRACKCODE, 2, (int)m_fantenna*100);
								m_bgSendCurrentTrackCode=TRUE;
							}
							CString m_str;
							m_str.Format("%f",m_fantenna+DISTANCE);
							m_str.Insert(0,"2号天线位置:");
							m_promptinfoMailandV.SetCString(8,m_str);

							//位置速度
							m_fgtrainclasp=m_fantenna+DISTANCE+(float)ANTENNATOCUSP;
							m_str.Format("%f",m_fgtrainclasp);
							m_str.Insert(0,"1号车钩位置:");
							m_promptinfoMailandV.SetCString(3,m_str);

							m_str.Format("%f",m_fgtrainclasp);
							m_str.Insert(0,"车辆位置:");
							m_promptinfoMailandV.SetCString(1,m_str);
							
							m_str.Format("%f",m_dgspeed);
							m_str.Insert(0,"车辆速度:");
							m_promptinfoMailandV.SetCString(0,m_str);

						}
					} 
					else
					{
						//1号车为尾车
						if (m_bgoahead==TRUE)
						{
							//行车方向，前进
							m_bDirectorup=TRUE;
							m_antenna.SetAntennaNumber(4);
							m_gnAntennaNumber=4;
							m_fantenna=m_antenna.GetAntennaPos();
							m_fgantennaforshow=m_fantenna;
							//未发送当前轨道码
							if (m_bgSendCurrentTrackCode==FALSE)
							{
								::PostMessage((HWND)lpParam, WM_SENDCURRENTTRACKCODE, 4, (int)m_fantenna*100);
								m_bgSendCurrentTrackCode=TRUE;
							}
							CString m_str;
							m_str.Format("%f",m_fantenna+DISTANCE);
							m_str.Insert(0,"4号天线位置:");
							m_promptinfoMailandV.SetCString(8,m_str);
							//必为上行
							m_fgtrainclasp=m_fantenna+DISTANCE-(float)ANTENNATOCUSP;
							m_str.Format("%f",m_fgtrainclasp);
							m_str.Insert(0,"6号车钩位置:");
							m_promptinfoMailandV.SetCString(3,m_str);

							//位置速度
							m_str.Format("%f",m_fgtrainclasp);
							m_str.Insert(0,"车辆位置:");
							m_promptinfoMailandV.SetCString(1,m_str);
							
						} 
						else
						{
							//行车方向，后退
							m_bDirectorup=FALSE;
							m_antenna.SetAntennaNumber(3);
							m_gnAntennaNumber=3;
							m_fantenna=m_antenna.GetAntennaPos();
							m_fgantennaforshow=m_fantenna;
							//未发送当前轨道码
							if (m_bgSendCurrentTrackCode==FALSE)
							{
								::PostMessage((HWND)lpParam, WM_SENDCURRENTTRACKCODE, 3, (int)m_fantenna*100);
								m_bgSendCurrentTrackCode=TRUE;
							}
							CString m_str;
							m_str.Format("%f",m_fantenna-DISTANCE);
							m_str.Insert(0,"3号天线位置:");
							m_promptinfoMailandV.SetCString(8,m_str);


						}
					}
					//上行数据
					if (m_bDirectorup)
					{
						//轨道搜索初始化
						int	m_nEnterNumber=0;
						for (int i=0;i<3;i++)
						{
							for (int j=0;j<2;j++)
							{
								m_nTrackPriority[j][i]=0;
							}
						}
						for (int up=0;up<TRACKUP;up++)
						{
							//该轨道码已发送，则不再发送
							if (!m_uptrack[up].m_btcodesend)
							{
								m_ntrackhigh=(m_uptrack[up].m_TRACKSTARTHIGH);
								//车在此轨, 条件为轨道与车辆高度相同或者轨道高度差在允许范围内，并且下一轨道起始点必须大于等于当前轨道结束点
								int	m_nHighDis=0;	//轨道高度容差
								m_nHighDis=abs(m_ntrackhigh-m_ntrainhigh);
								if (m_nHighDis<=TRACKHIGHDIS)		
								{
									//轨道起始点计算
									m_ftrackstartpos=(float)m_uptrack[up].m_Tstartpos;
									m_ftrackstartpos=m_ftrackstartpos/100;
									//轨道结束点未进行过计算
									if (m_bgTrackEndPosCalculate==FALSE)
									{
										if ((m_fantenna>=m_ftrackstartpos-1)&&(m_fantenna<=m_ftrackstartpos+1))
										{
											//判断是否是折轨，并填入轨道优先级
											//数字越小优先级越高
											if (m_uptrack[up].m_ISFOLD==FALSE)
											{
												m_nTrackPriority[0][m_nEnterNumber]=m_nNormalTrackPriority;
											} 
											else
											{
												m_nTrackPriority[0][m_nEnterNumber]=m_nFoldTrackPriority;
											 	if (m_bprioritygrow==FALSE)
												{
													m_nFoldTrackPriority--;
												} 
												else
												{
													m_nFoldTrackPriority++;
												}
											}
											m_nTrackPriority[1][m_nEnterNumber]=up;		//轨道进路优先级
											m_nEnterNumber++;
										}
									}
									else
									{																				//上一轨道结束点必须和下一轨道开始点相等
										if ((m_fantenna>=m_ftrackstartpos-1)&&(m_fantenna<=m_ftrackstartpos+1)&&(m_nTrackEndPos==m_uptrack[up].m_Tstartpos))
										{
											//判断是否是折轨，并填入轨道优先级
											//数字越小优先级越高
											if (m_uptrack[up].m_ISFOLD==FALSE)
											{
												m_nTrackPriority[0][m_nEnterNumber]=m_nNormalTrackPriority;
											} 
											else
											{
												m_nTrackPriority[0][m_nEnterNumber]=m_nFoldTrackPriority;
												if (m_bprioritygrow==FALSE)
												{
													m_nFoldTrackPriority--;
												} 
												else
												{
													m_nFoldTrackPriority++;
												}
											}
											m_nTrackPriority[1][m_nEnterNumber]=up;		//轨道进路优先级
											m_nEnterNumber++;
										}
									}
								}
							}
						}

						//搜索完毕
						switch (m_nEnterNumber)
						{
						case 0:
							{
								//未找到轨道
								break;
							}
						case 1:
							{
								//只找到一条进路
								::PostMessage((HWND)lpParam, WM_NEXTTRACK, 1, m_nTrackPriority[1][0]);
								m_boolisfold=m_uptrack[m_nTrackPriority[1][0]].m_ISFOLD;
								break;
							}
						case 2:
							{
								//找到两条进路，将选择的轨道数据发送后，将两外一条轨道发送信息也同时置位，否则在下一次检测中将本次没发送的轨道数据发送
								//先判断两条轨道是否都是折轨，如果都是折轨,根据轨道结束点高度判断走那条轨道，可人工控制反向
								if (m_nTrackPriority[0][0]==m_nTrackPriority[0][1])
								{
									//默认走轨道结束高度低的轨道
									if (m_bDefaultLowEndHigh==TRUE)
									{
										if (m_uptrack[m_nTrackPriority[1][0]].m_TRACKENDHIGH<m_uptrack[m_nTrackPriority[1][1]].m_TRACKENDHIGH)
										{
											::PostMessage((HWND)lpParam, WM_NEXTTRACK, 1, m_nTrackPriority[1][0]);
											m_boolisfold=m_uptrack[m_nTrackPriority[1][0]].m_ISFOLD;
											m_uptrack[m_nTrackPriority[1][1]].m_btcodesend=TRUE;
										} 
										else
										{
											::PostMessage((HWND)lpParam, WM_NEXTTRACK, 1, m_nTrackPriority[1][1]);
											m_uptrack[m_nTrackPriority[1][0]].m_btcodesend=TRUE;
											m_boolisfold=m_uptrack[m_nTrackPriority[1][1]].m_ISFOLD;
										}
									} 
									else
									{
										if (m_uptrack[m_nTrackPriority[1][0]].m_TRACKENDHIGH<m_uptrack[m_nTrackPriority[1][1]].m_TRACKENDHIGH)
										{
											::PostMessage((HWND)lpParam, WM_NEXTTRACK, 1, m_nTrackPriority[1][1]);
											m_uptrack[m_nTrackPriority[1][0]].m_btcodesend=TRUE;
											m_boolisfold=m_uptrack[m_nTrackPriority[1][1]].m_ISFOLD;
										} 
										else
										{
											::PostMessage((HWND)lpParam, WM_NEXTTRACK, 1, m_nTrackPriority[1][0]);
											m_uptrack[m_nTrackPriority[1][1]].m_btcodesend=TRUE;
											m_boolisfold=m_uptrack[m_nTrackPriority[1][0]].m_ISFOLD;
										}
									}
									//轨道优先级自动回复，否则轨道全部走侧向
									m_nNormalTrackPriority=1;
									m_nFoldTrackPriority=10;

								}
								else if (m_nTrackPriority[0][0]<m_nTrackPriority[0][1])
								{
									::PostMessage((HWND)lpParam, WM_NEXTTRACK, 1, m_nTrackPriority[1][0]);
									m_uptrack[m_nTrackPriority[1][1]].m_btcodesend=TRUE;
									//侧向轨道清除侧向优先
									if (m_uptrack[m_nTrackPriority[1][0]].m_ISFOLD==TRUE)
									{
										//轨道优先级自动回复，否则轨道全部走侧向
										m_nNormalTrackPriority=1;
										m_nFoldTrackPriority=10;
										//m_uptrack[m_nTrackPriority[1][0]].m_ISFOLD=FALSE;
										m_boolisfold=m_uptrack[m_nTrackPriority[1][0]].m_ISFOLD;
									}

								} 
								else
								{
									::PostMessage((HWND)lpParam, WM_NEXTTRACK, 1, m_nTrackPriority[1][1]);
									m_uptrack[m_nTrackPriority[1][0]].m_btcodesend=TRUE;
									if (m_uptrack[m_nTrackPriority[1][1]].m_ISFOLD==TRUE)
									{
										//轨道优先级自动回复，否则轨道全部走侧向
										m_nNormalTrackPriority=1;
										m_nFoldTrackPriority=10;
										//m_uptrack[m_nTrackPriority[1][1]].m_ISFOLD=FALSE;
										m_boolisfold=m_uptrack[m_nTrackPriority[1][1]].m_ISFOLD;
									}
								}
								break;
							}
						case 3:
							{
								//找到三条进路
								//先比较第一个和第二个
								if (m_nTrackPriority[0][0]<m_nTrackPriority[0][1])
								{
									
								} 
								else
								{
								}
								break;
							}
						}

					} 
					//下行数据
					else
					{
						//轨道搜索初始化
						int	m_nEnterNumber=0;
						for (int i=0;i<3;i++)
						{
							for (int j=0;j<2;j++)
							{
								m_nTrackPriority[j][i]=0;
							}
						}
						for (int down=0;down<TRACKDOWN;down++)
						{
							//该轨道码已发送，则不再发送
							if (!m_downtrack[down].m_btcodesend)
							{
								m_ntrackhigh=(m_downtrack[down].m_TRACKSTARTHIGH);
								//车在此轨, 条件为轨道与车辆高度相同或者轨道高度差在允许范围内，并且下一轨道起始点必须大于等于当前轨道结束点
								int	m_nHighDis=0;	//轨道高度差
								m_nHighDis=abs(m_ntrackhigh-m_ntrainhigh);
								if (m_nHighDis<=TRACKHIGHDIS)		
								{
									//轨道起始点计算
									m_ftrackstartpos=(float)m_downtrack[down].m_Tstartpos;
									m_ftrackstartpos=m_ftrackstartpos/100;
									//轨道结束点未进行过计算
									if (m_bgTrackEndPosCalculate==FALSE)
									{
										if ((m_fantenna>=m_ftrackstartpos-1)&&(m_fantenna<=m_ftrackstartpos+1))
										{
											//找到一个轨道后继续寻找，直到搜索完全部数据，因为在同一个点有多条进路，根据优先级判断驶入那条轨道
											
											//判断是否是折轨，并填入轨道优先级
											//数字越小优先级越高
											if (m_downtrack[down].m_ISFOLD==FALSE)
											{
												m_nTrackPriority[0][m_nEnterNumber]=m_nNormalTrackPriority;
											} 
											else
											{
												m_nTrackPriority[0][m_nEnterNumber]=m_nFoldTrackPriority;
												if (m_bprioritygrow==FALSE)
												{
													m_nFoldTrackPriority--;
												} 
												else
												{
													m_nFoldTrackPriority++;
												}
											}

											m_nTrackPriority[1][m_nEnterNumber]=down;		//轨道进路优先级
											m_nEnterNumber++;
										}
									} 
									else
									{
										if ((m_fantenna>=m_ftrackstartpos-1)&&(m_fantenna<=m_ftrackstartpos+1)&&(m_nTrackEndPos==m_downtrack[down].m_Tstartpos))
										{
											//找到一个轨道后继续寻找，直到搜索完全部数据，因为在同一个点有多条进路，根据优先级判断驶入那条轨道
											
											//判断是否是折轨，并填入轨道优先级
											//数字越小优先级越高
											if (m_downtrack[down].m_ISFOLD==FALSE)
											{
												m_nTrackPriority[0][m_nEnterNumber]=m_nNormalTrackPriority;
											} 
											else
											{
												m_nTrackPriority[0][m_nEnterNumber]=m_nFoldTrackPriority;
												if (m_bprioritygrow==FALSE)
												{
													m_nFoldTrackPriority--;
												} 
												else
												{
													m_nFoldTrackPriority++;
												}
											}
											m_nTrackPriority[1][m_nEnterNumber]=down;		//轨道进路优先级
											m_nEnterNumber++;
										}
									}

								}
							}
						}

						//搜索完毕,根据优先级判断驶入那条进路
						switch (m_nEnterNumber)
						{
						case 0:
							{
								//未找到轨道
								break;
							}
						case 1:
							{
								//只找到一条进路
								::PostMessage((HWND)lpParam, WM_NEXTTRACK, 2, m_nTrackPriority[1][0]);
								break;
							}
						case 2:
							{
								//找到两条进路
								if (m_nTrackPriority[0][0]==m_nTrackPriority[0][1])
								{
									//默认走轨道结束高度低的轨道
									if (m_bDefaultLowEndHigh==TRUE)
									{
										if (m_downtrack[m_nTrackPriority[1][0]].m_TRACKENDHIGH<m_downtrack[m_nTrackPriority[1][1]].m_TRACKENDHIGH)
										{
											::PostMessage((HWND)lpParam, WM_NEXTTRACK, 2, m_nTrackPriority[1][0]);
											m_downtrack[m_nTrackPriority[1][1]].m_btcodesend=TRUE;
										} 
										else
										{
											::PostMessage((HWND)lpParam, WM_NEXTTRACK, 2, m_nTrackPriority[1][1]);
											m_downtrack[m_nTrackPriority[1][0]].m_btcodesend=TRUE;
										}
									}
									else
									{
										if (m_downtrack[m_nTrackPriority[1][0]].m_TRACKENDHIGH<m_downtrack[m_nTrackPriority[1][1]].m_TRACKENDHIGH)
										{
											::PostMessage((HWND)lpParam, WM_NEXTTRACK, 2, m_nTrackPriority[1][1]);
											m_downtrack[m_nTrackPriority[1][0]].m_btcodesend=TRUE;
										} 
										else
										{
											::PostMessage((HWND)lpParam, WM_NEXTTRACK, 2, m_nTrackPriority[1][0]);
											m_downtrack[m_nTrackPriority[1][1]].m_btcodesend=TRUE;
										}
									}
									//轨道优先级自动回复，否则轨道全部走侧向
									m_nNormalTrackPriority=1;
									m_nFoldTrackPriority=10;
								}
								else if (m_nTrackPriority[0][0]<m_nTrackPriority[0][1])
								{
									::PostMessage((HWND)lpParam, WM_NEXTTRACK, 2, m_nTrackPriority[1][0]);
									m_downtrack[m_nTrackPriority[1][1]].m_btcodesend=TRUE;
									if (m_downtrack[m_nTrackPriority[1][0]].m_ISFOLD==TRUE)
									{
										//轨道优先级自动回复，否则轨道全部走侧向
										m_nNormalTrackPriority=1;
										m_nFoldTrackPriority=10;
									}
								} 
								else
								{
									::PostMessage((HWND)lpParam, WM_NEXTTRACK, 2, m_nTrackPriority[1][1]);
									m_downtrack[m_nTrackPriority[1][0]].m_btcodesend=TRUE;
									if (m_downtrack[m_nTrackPriority[1][1]].m_ISFOLD==TRUE)
									{
										//轨道优先级自动回复，否则轨道全部走侧向
										m_nNormalTrackPriority=1;
										m_nFoldTrackPriority=10;
									}
								}
								break;
							}
						case 3:
							{
								//找到三条进路
								//先比较第一个和第二个
								if (m_nTrackPriority[0][0]<m_nTrackPriority[0][1])
								{

								} 
								else
								{

								}
								break;
							}
						}
					}
				}
				break;
			}
		}
		Sleep(1);
	}
	return 0;
}
	
UINT ThreadLoadingTrack(LPVOID lpParam)
{
	//默认数据连接方式为快照方式，应更改为m_nDefaultType = AFX_DB_USE_DEFAULT_TYPE;
	int m_npointer=0;
	CDatabase m_threaddb;

	/*消息定义:
		LPARAM 参数为	0，为进度条控制信息
						1, 提示信息
	*/
	//::PostMessage((HWND)lpParam, WM_DISPLAY, 1, 1);

//	::PostMessage((HWND)lpParam, WM_DISPLAY, m_nprogress++, m_nprompt);
	if (m_threaddb.IsOpen())
	{
		
	}
	else
	{
		try
		{
			m_threaddb.Open(_T("ALLTRACK"),FALSE,FALSE,_T("ODBC"),FALSE);
		}
		catch (CMemoryException* pEx)	//处理内存异常
		{
			pEx->ReportError();
		}
		catch (CFileException* pDBEx)//处理文件异常
		{
			pDBEx->ReportError();
		}
		catch (CException* e)//处理其它异常
		{
			e->ReportError();
		}

	}

	CALLTRACKAUTOSet *m_dbset=new CALLTRACKAUTOSet(&m_threaddb);

	if (m_dbset->IsOpen())
	{
		m_dbset->Close();
	} 
	
	CString m_sql;

	m_sql.Format("select * from toexcel order by tstartpos");

	try
	{
		m_dbset->Open(AFX_DB_USE_DEFAULT_TYPE,m_sql);
	}
	catch (CMemoryException* pEx)	//处理内存异常
	{
		pEx->ReportError();
	}
	catch (CFileException* pDBEx)//处理文件异常
	{
		pDBEx->ReportError();
	}
	catch (CException* e)//处理其它异常
	{
		e->ReportError();
	}

	if (!m_dbset->IsBOF())
	{
		m_dbset->MoveFirst();
	}

	try
	{
		while(!m_dbset->IsEOF())
		{
			m_alltrack[m_npointer].m_Snumber=m_dbset->m_Snumber;
			m_alltrack[m_npointer].m_UpDown=m_dbset->m_UpDown;
			m_alltrack[m_npointer].m_Sname=m_dbset->m_Sname;
			m_alltrack[m_npointer].m_TSname=m_dbset->m_TSname;
			m_alltrack[m_npointer].m_Tsnumber=m_dbset->m_Tsnumber;
			m_alltrack[m_npointer].m_PR=m_dbset->m_PR;
			m_alltrack[m_npointer].m_Tstype=m_dbset->m_Tstype;
			m_alltrack[m_npointer].m_Tsskip=m_dbset->m_Tsskip;
			m_alltrack[m_npointer].m_Tstartpos=m_dbset->m_Tstartpos;
			m_alltrack[m_npointer].m_Slenth=m_dbset->m_Slenth;
			m_alltrack[m_npointer].m_Sstarttospurlenth=m_dbset->m_Sstarttospurlenth;
			m_alltrack[m_npointer].m_stoppos=m_dbset->m_stoppos;
			m_alltrack[m_npointer].m_tgsign=m_dbset->m_tgsign;
			m_alltrack[m_npointer].m_Tgradient=m_dbset->m_Tgradient;
			m_alltrack[m_npointer].m_CF=m_dbset->m_CF;
			m_alltrack[m_npointer].m_PLS=m_dbset->m_PLS;
			m_alltrack[m_npointer].m_OPENDOOR=m_dbset->m_OPENDOOR;
			m_alltrack[m_npointer].m_Signalorpos=m_dbset->m_Signalorpos;
			m_alltrack[m_npointer].m_SignalorV=m_dbset->m_SignalorV;
			m_alltrack[m_npointer].m_NPAPRnumber=m_dbset->m_NPAPRnumber;
			m_alltrack[m_npointer].m_NPAPRpos=m_dbset->m_NPAPRpos;
			m_alltrack[m_npointer].m_PAPRcode=m_dbset->m_PAPRcode;
			m_alltrack[m_npointer].m_Psignalpos=m_dbset->m_Psignalpos;
			m_alltrack[m_npointer].m_FDSNPAPRcode=m_dbset->m_FDSNPAPRcode;
			m_alltrack[m_npointer].m_FRSNPAPRcode=m_dbset->m_FRSNPAPRcode;
			m_alltrack[m_npointer].m_BDSNPAPRcode=m_dbset->m_BDSNPAPRcode;
			m_alltrack[m_npointer].m_BRSNPAPRcode=m_dbset->m_BRSNPAPRcode;
			m_alltrack[m_npointer].m_TOEflag=m_dbset->m_TOEflag;
			m_alltrack[m_npointer].m_NPAPR2number=m_dbset->m_NPAPR2number;
			m_alltrack[m_npointer].m_NPAPR2pos=m_dbset->m_NPAPR2pos;
			m_alltrack[m_npointer].m_CODE7473=m_dbset->m_CODE7473;
			m_alltrack[m_npointer].m_CODE7458=m_dbset->m_CODE7458;
			m_alltrack[m_npointer].m_CODE5958=m_dbset->m_CODE5958;
			m_alltrack[m_npointer].m_CODE5937=m_dbset->m_CODE5937;
			m_alltrack[m_npointer].m_CODE3837=m_dbset->m_CODE3837;
			m_alltrack[m_npointer].m_CODE3827=m_dbset->m_CODE3827;
			m_alltrack[m_npointer].m_CODE3800=m_dbset->m_CODE3800;
			m_alltrack[m_npointer].m_CODE2827=m_dbset->m_CODE2827;
			m_alltrack[m_npointer].m_CODE2819=m_dbset->m_CODE2819;
			m_alltrack[m_npointer].m_CODE2800=m_dbset->m_CODE2800;
			m_alltrack[m_npointer].m_CODE2000=m_dbset->m_CODE2000;
			m_alltrack[m_npointer].m_CODE00=m_dbset->m_CODE00;
			m_alltrack[m_npointer].m_NPAPR3number=m_dbset->m_NPAPR3number;
			m_alltrack[m_npointer].m_NPAPR3pos=m_dbset->m_NPAPR3pos;
			m_alltrack[m_npointer].m_R8=m_dbset->m_R8;
			m_alltrack[m_npointer].m_LNPAPR1number=m_dbset->m_LNPAPR1number;
			m_alltrack[m_npointer].m_LNPAPR1pos=m_dbset->m_LNPAPR1pos;
			m_alltrack[m_npointer].m_LNPAPR2number=m_dbset->m_LNPAPR2number;
			m_alltrack[m_npointer].m_LNPAPR2pos=m_dbset->m_LNPAPR2pos;
			m_alltrack[m_npointer].m_LNPAPR3number=m_dbset->m_LNPAPR3number;
			m_alltrack[m_npointer].m_LNPAPR3pos=m_dbset->m_LNPAPR3pos;
			m_alltrack[m_npointer].m_LNPAPR4number=m_dbset->m_LNPAPR4number;
			m_alltrack[m_npointer].m_LNPAPR4pos=m_dbset->m_LNPAPR4pos;
			m_alltrack[m_npointer].m_LNPAPR5number=m_dbset->m_LNPAPR5number;
			m_alltrack[m_npointer].m_LNPAPR5pos=m_dbset->m_LNPAPR5pos;
			m_alltrack[m_npointer].m_ATOCnumber=m_dbset->m_ATOCnumber;
			m_alltrack[m_npointer].m_ATOCpos=m_dbset->m_ATOCpos;
		 	m_alltrack[m_npointer].m_POINT1ENDx=m_dbset->m_POINT1ENDx;
			m_alltrack[m_npointer].m_POINT1ENDy=m_dbset->m_POINT1ENDy;
			m_alltrack[m_npointer].m_POINT2ENDx=m_dbset->m_POINT2ENDx;
			m_alltrack[m_npointer].m_POINT2ENDy=m_dbset->m_POINT2ENDy;
			m_alltrack[m_npointer].m_POINT3ENDx=m_dbset->m_POINT3ENDx;
			m_alltrack[m_npointer].m_POINT3ENDy=m_dbset->m_POINT3ENDy;
			m_alltrack[m_npointer].m_LINENUMBER=m_dbset->m_LINENUMBER;
			m_alltrack[m_npointer].m_ISFOLD=m_dbset->m_ISFOLD;
			m_alltrack[m_npointer].m_SENDCODE=m_dbset->m_SENDCODE;	
			m_alltrack[m_npointer].m_TRACKSTARTHIGH=m_dbset->m_TRACKSTARTHIGH;	
			m_alltrack[m_npointer].m_TRACKENDHIGH=m_dbset->m_TRACKENDHIGH;	
			m_alltrack[m_npointer].m_PRIORITY=m_dbset->m_PRIORITY;
			m_alltrack[m_npointer].m_Tendpos=m_dbset->m_Tendpos;
			m_alltrack[m_npointer].m_SENDCODE2=m_dbset->m_SENDCODE2;
			m_alltrack[m_npointer].m_SENDCODE2pos=m_dbset->m_SENDCODE2pos;
			m_npointer++;
			m_dbset->MoveNext();
		}
	}
	catch (CException* e)//处理其它异常
	{
		e->ReportError();
	}
	m_dbset->Close();
	//加载站信息
	Station *m_dbsetstation=new Station(&m_threaddb);
	
	if (m_dbsetstation->IsOpen())
	{
		m_dbsetstation->Close();
	} 
	
	CString m_sqls;
	
	m_sqls.Format("select * from station");
	
	try
	{
		m_dbsetstation->Open(AFX_DB_USE_DEFAULT_TYPE,m_sqls);
	}
	catch (CMemoryException* pEx)	//处理内存异常
	{
		pEx->ReportError();
	}
	catch (CFileException* pDBEx)//处理文件异常
	{
		pDBEx->ReportError();
	}
	catch (CException* e)//处理其它异常
	{
		e->ReportError();
	}
	
	if (!m_dbsetstation->IsBOF())
	{
		m_dbsetstation->MoveFirst();
	}
	m_npointer=0;
	try
	{
		while(!m_dbsetstation->IsEOF())
		{
			m_station[m_npointer].m_name=m_dbsetstation->m_name;
			m_station[m_npointer].m_pos=m_dbsetstation->m_pos;
			m_station[m_npointer].m_platformnum=m_dbsetstation->m_platformnum;
			m_station[m_npointer].m_plenth=m_dbsetstation->m_plenth;
			m_station[m_npointer].m_p1high=m_dbsetstation->m_p1high;
			m_station[m_npointer].m_p1width=m_dbsetstation->m_p1width;
			m_station[m_npointer].m_p2high=m_dbsetstation->m_p2high;
			m_station[m_npointer].m_p2width=m_dbsetstation->m_p2width;
			m_station[m_npointer].m_p3high=m_dbsetstation->m_p3high;
			m_station[m_npointer].m_p3width=m_dbsetstation->m_p3width;
			m_npointer++;
			m_dbsetstation->MoveNext();
		}
	}
	catch (CException* e)//处理其它异常
	{
		e->ReportError();
	}
	m_dbsetstation->Close();
	m_threaddb.Close();

	//分开上下行数据
	int	m_nuppointer=0;
	int	m_ndownpointer=0;

	for (int i=0;i<TRACKNUMBER;i++)
	{
		if (m_alltrack[i].m_UpDown=="上行")
		{
			m_uptrack[m_nuppointer++].CopyTrack(&m_alltrack[i]);
		} 
		else
		{
			m_downtrack[m_ndownpointer++].CopyTrack(&m_alltrack[i]);
		}
	}
	::PostMessage((HWND)lpParam, WM_LOADALLTRACK, 0, 0);
	return 0;
}
LRESULT CALLTRACKAUTOView::OnThreadSendAPR(WPARAM wParam,LPARAM lParam)
{
	byte	m_byte=wParam >> 28;
	//无源低速MARK28 无源高速OPEN32 有源openlen

	switch (m_byte)
	{
	case 0:
		{
			//无源低速 mark28 下行
			byte m_byte;
			CString	m_strrunning;
			float	m_fsenddistance;
			m_fsenddistance=(float)lParam;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x06]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x07]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x08]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x09]=m_byte;
			m_byteWritePAPR70[0x14]=NPAPR;
			m_downtrack[m_gnAPRpointer].m_btNPAPRsend=TRUE;
			m_bSendNPAPRF=FALSE;
			m_bSendNPAPR=TRUE;			
			m_strrunning.Format("%0.2f",m_fsenddistance/1000);
			m_strrunning.Insert(0,"APR距离:");
			m_showrunning.AddMsg(m_strrunning);

			m_strrunning.Format("0X%08X",wParam);
			m_strrunning.Insert(0,"APRid:");
			m_showrunning.AddMsg(m_strrunning);

			//MARK28
			m_byte=wParam&0x0000003f;
			m_byte=m_byte<<2;
			m_byteWritePAPR10[0x0b]=m_byte;

			wParam=wParam>>6;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x0a]=m_byte;

			wParam=wParam>>8;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x09]=m_byte;

			wParam=wParam>>8;
			m_byteWritePAPR10[0x08]=wParam;
			
			m_byteWritePAPR10[0x07]=0;
			m_byteWritePAPR10[0x06]=0x81;
			
			//重新发送APR，清除标志无效
			m_bAlreadyClear=FALSE;
			break;
		}
	case 1:
		{
			//无源低速 mark28 上行
			byte m_byte;
			CString	m_strrunning;
			float	m_fsenddistance;

			m_fsenddistance=(float)lParam;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x06]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x07]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x08]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x09]=m_byte;
			m_byteWritePAPR70[0x14]=NPAPR;
			m_uptrack[m_gnAPRpointer].m_btNPAPRsend=TRUE;
			m_bSendNPAPRF=FALSE;
			m_bSendNPAPR=TRUE;			
			m_strrunning.Format("%0.2f",m_fsenddistance/1000);
			m_strrunning.Insert(0,"APR距离:");
			m_showrunning.AddMsg(m_strrunning);

			//去除ID号中的标志
			wParam=wParam&0x0FFFFFFF;

			m_strrunning.Format("0X%08X",wParam);
			m_strrunning.Insert(0,"APRid:");
			m_showrunning.AddMsg(m_strrunning);
			
			//open28 逆向算法
			m_byte=wParam&0x0000003f;
			m_byte=m_byte<<2;
			m_byteWritePAPR10[0x0b]=m_byte;
			
			wParam=wParam>>6;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x0a]=m_byte;
			
			wParam=wParam>>8;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x09]=m_byte;
			
			wParam=wParam>>8;
			m_byteWritePAPR10[0x08]=wParam;
			
			m_byteWritePAPR10[0x07]=0;
			m_byteWritePAPR10[0x06]=0x81;
			
			//重新发送APR，清除标志无效
			m_bAlreadyClear=FALSE;
			break;
		}
	//有源APR
	case 2:
		{
			//下行 80帧 
			/*
			byte m_byte;
			CString	m_strrunning;
			float	m_fsenddistance;
			m_fsenddistance=(float)lParam;
			m_byte=(unsigned char)lParam;
			m_byteWriteNPAPR80[0x06]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWriteNPAPR80[0x07]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWriteNPAPR80[0x08]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWriteNPAPR80[0x09]=m_byte;
			m_byteWriteNPAPR80[0x14]=PAPR;
			m_downtrack[m_gnAPRpointer].m_btPAPRsend=TRUE;
			m_bSendPAPRF=FALSE;
			m_bSendPAPR=TRUE;			
			m_strrunning.Format("%0.2f",m_fsenddistance/1000);
			m_strrunning.Insert(0,"APR距离:");
			m_showrunning.AddMsg(m_strrunning);
			//去除ID号中的标志
			wParam=wParam&0x0FFFFFFF;
			m_strrunning.Format("0X%08X",wParam);
			m_strrunning.Insert(0,"APRid:");
			m_showrunning.AddMsg(m_strrunning);
			//id = ((data[1] & 0x3f) << 22) | (data[2] << 14) | (data[3] << 6) | ((data[4] & 0xfc) >> 2)；
			//ID计算OPEN32 格式解析如下：id = (data[0] << 24) | ((data[1] & 0xC0) << 16) | (data[2] << 14) | (data[3] << 6) | ((data[4] & 0xfc) >> 2)。
			int m_nid=0;

			m_byte=wParam&0x0000003f;
			m_byte=m_byte<<2;
			m_byteWriteNPAPR20[0x0b]=m_byte;
			
			wParam=wParam>>6;
			m_byte=wParam&0x000000ff;
			m_byteWriteNPAPR20[0x0a]=m_byte;
			
			wParam=wParam>>8;
			m_byte=wParam&0x000000ff;
			m_byteWriteNPAPR20[0x09]=m_byte;
			
			wParam=wParam>>2;
			//m_byte=wParam&0x000000ff;
			m_byteWriteNPAPR20[0x08]=wParam;
			
			wParam=wParam>>8;
			m_byteWriteNPAPR20[0x07]=wParam;

			m_byteWriteNPAPR20[0x06]=0x81;
			
			//重新发送APR，清除标志无效
			m_bAlreadyClear=FALSE;
			*/


			//有源openlen 下行 70帧 
			byte m_byte;
			CString	m_strrunning;
			float	m_fsenddistance;
			m_fsenddistance=(float)lParam;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x06]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x07]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x08]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x09]=m_byte;
			m_byteWritePAPR70[0x14]=PAPR;
			m_downtrack[m_gnAPRpointer].m_btPAPRsend=TRUE;
			m_bSendPAPRF=FALSE;
			m_bSendPAPR=TRUE;			
			m_strrunning.Format("%0.2f",m_fsenddistance/1000);
			m_strrunning.Insert(0,"APR距离:");
			m_showrunning.AddMsg(m_strrunning);
			//去除ID号中的标志
			wParam=wParam&0x0FFFFFFF;
			m_strrunning.Format("0X%08X",wParam);
			m_strrunning.Insert(0,"APRid:");
			m_showrunning.AddMsg(m_strrunning);
			//id = ((data[1] & 0x3f) << 22) | (data[2] << 14) | (data[3] << 6) | ((data[4] & 0xfc) >> 2)；
			//ID计算OPEN32 格式解析如下：id = (data[0] << 24) | ((data[1] & 0xC0) << 16) | (data[2] << 14) | (data[3] << 6) | ((data[4] & 0xfc) >> 2)。
			switch (wParam)
			{
			case 0x055ED16F:
				{
					//DATA发送
					m_byteWritePAPR10[0x0E]=m_papr[0].m_bytedata[0];
					m_byteWritePAPR10[0x0F]=m_papr[0].m_bytedata[1];
					m_byteWritePAPR10[0x10]=m_papr[0].m_bytedata[2];
					m_byteWritePAPR10[0x11]=m_papr[0].m_bytedata[3];
					m_byteWritePAPR10[0x12]=m_papr[0].m_bytedata[4];
					m_byteWritePAPR10[0x13]=m_papr[0].m_bytedata[5];
					break;
				}
			case 0x055ED170:
				{
					//DATA发送
					m_byteWritePAPR10[0x0E]=m_papr[1].m_bytedata[0];
					m_byteWritePAPR10[0x0F]=m_papr[1].m_bytedata[1];
					m_byteWritePAPR10[0x10]=m_papr[1].m_bytedata[2];
					m_byteWritePAPR10[0x11]=m_papr[1].m_bytedata[3];
					m_byteWritePAPR10[0x12]=m_papr[1].m_bytedata[4];
					m_byteWritePAPR10[0x13]=m_papr[1].m_bytedata[5];
					break;
				}
			case 0x055ED294:
				{
					//DATA发送
					m_byteWritePAPR10[0x0E]=m_papr[2].m_bytedata[0];
					m_byteWritePAPR10[0x0F]=m_papr[2].m_bytedata[1];
					m_byteWritePAPR10[0x10]=m_papr[2].m_bytedata[2];
					m_byteWritePAPR10[0x11]=m_papr[2].m_bytedata[3];
					m_byteWritePAPR10[0x12]=m_papr[2].m_bytedata[4];
					m_byteWritePAPR10[0x13]=m_papr[2].m_bytedata[5];
					break;
				}
			}
			
			//open28 逆向算法
			/*
			m_byte=wParam&0x0000003f;
			m_byte=m_byte<<2;
			m_byteWritePAPR10[0x0b]=m_byte;
			
			wParam=wParam>>6;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x0a]=m_byte;
			
			wParam=wParam>>8;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x09]=m_byte;
			
			wParam=wParam>>8;
			m_byteWritePAPR10[0x08]=wParam;
			
			m_byteWritePAPR10[0x07]=0;
			m_byteWritePAPR10[0x06]=0x81;
			*/
			//Open32 逆向算法
			/*
			m_byte=wParam&0x0000003f;
			m_byte=m_byte<<2;
			m_byteWritePAPR10[0x0b]=m_byte;
			
			wParam=wParam>>6;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x0a]=m_byte;
			
			wParam=wParam>>8;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x09]=m_byte;
			
			wParam=wParam>>2;
			//m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x08]=wParam|0x3F;
			
			wParam=wParam>>8;
			m_byteWritePAPR10[0x07]=wParam;
			
			m_byteWritePAPR10[0x06]=0x81;
			*/
			
			m_byteWritePAPR10[0x08]=0x3D;
			//重新发送APR，清除标志无效
			m_bAlreadyClear=FALSE;
			break;
		}
	case 3:
		{
			byte m_byte;
			CString	m_strrunning;
			float	m_fsenddistance;
			
			m_fsenddistance=(float)lParam;
			m_byte=(unsigned char)lParam;
			m_byteWriteNPAPR80[0x06]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWriteNPAPR80[0x07]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWriteNPAPR80[0x08]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWriteNPAPR80[0x09]=m_byte;
			m_byteWriteNPAPR80[0x14]=NPAPR;
			m_uptrack[m_gnAPRpointer].m_btPAPRsend=TRUE;
			m_bSendPAPRF=FALSE;
			m_bSendPAPR=TRUE;			
			m_strrunning.Format("%0.2f",m_fsenddistance/1000);
			m_strrunning.Insert(0,"APR距离:");
			m_showrunning.AddMsg(m_strrunning);
			
			//去除ID号中的标志
			wParam=wParam&0x0FFFFFFF;
			
			m_strrunning.Format("0X%08X",wParam);
			m_strrunning.Insert(0,"APRid:");
			m_showrunning.AddMsg(m_strrunning);
			
			//open32

			m_byte=wParam&0x0000003f;
			m_byte=m_byte<<2;
			m_byteWritePAPR10[0x0b]=m_byte;
			
			wParam=wParam>>6;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x0a]=m_byte;
			
			wParam=wParam>>8;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x09]=m_byte;
			
			wParam=wParam>>2;
			//m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x08]=wParam|0x3F;
			
			wParam=wParam>>8;
			m_byteWritePAPR10[0x07]=wParam;
			
			m_byteWritePAPR10[0x06]=0x81;

			//重新发送APR，清除标志无效
			m_bAlreadyClear=FALSE;
			break;
		}
	case 4:
		{

			byte m_byte;
			CString	m_strrunning;
			float	m_fsenddistance;
			m_fsenddistance=(float)lParam;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x06]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x07]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x08]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x09]=m_byte;
			m_byteWritePAPR70[0x14]=NPAPR;
			
			if (m_bDirectorup)	//上行
			{
				m_uptrack[m_gnAPRpointer].m_btNPAPRsend=TRUE;
				//m_uptrack[m_gnAPRpointer].m_btNPAPR2send=TRUE;
			}
			else
			{
				m_downtrack[m_gnAPRpointer].m_btNPAPRsend=TRUE;
				//m_downtrack[m_gnAPRpointer].m_btNPAPR2send=TRUE;
			}

			
			m_bSendNPAPRF=FALSE;
			m_bSendNPAPR=TRUE;			
			m_strrunning.Format("%0.2f",m_fsenddistance/1000);
			m_strrunning.Insert(0,"APR距离:");
			m_showrunning.AddMsg(m_strrunning);
			
			m_strrunning.Format("0X%08X",wParam);
			m_strrunning.Insert(0,"APRid:");
			m_showrunning.AddMsg(m_strrunning);
			
			//去除ID号中的标志open 28
			/*
			wParam=wParam&0x0FFFFFFF;
			
			m_byte=wParam&0x0000003f;
			m_byte=m_byte<<2;
			m_byteWritePAPR10[0x0b]=m_byte;
			
			wParam=wParam>>6;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x0a]=m_byte;
			
			wParam=wParam>>8;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x09]=m_byte;
			
			wParam=wParam>>8;
			m_byteWritePAPR10[0x08]=wParam;
			
			m_byteWritePAPR10[0x07]=0;
			m_byteWritePAPR10[0x06]=0x81;
			*/

			//open32
			if (!m_boolmsb4)
			{
				wParam=wParam&0x0FFFFFFF;	
			} 
			m_byte=wParam&0x0000003f;
			m_byte=m_byte<<2;
			m_byteWritePAPR10[0x0b]=m_byte;
			
			wParam=wParam>>6;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x0a]=m_byte;
			
			wParam=wParam>>8;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x09]=m_byte;
			
			wParam=wParam>>2;
			//m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x08]=wParam|0x3F;
			
			wParam=wParam>>8;
			m_byteWritePAPR10[0x07]=wParam;
			
			m_byteWritePAPR10[0x06]=0x81;
			

			//重新发送APR，清除标志无效
			m_bAlreadyClear=FALSE;
			break;
		}
	case 5:
		{
			byte m_byte;
			CString	m_strrunning;
			float	m_fsenddistance;
			m_fsenddistance=(float)lParam;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x06]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x07]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x08]=m_byte;
			lParam=lParam>>8;
			m_byte=(unsigned char)lParam;
			m_byteWritePAPR70[0x09]=m_byte;
			m_byteWritePAPR70[0x14]=NPAPR;
			m_downtrack[m_gnAPRpointer].m_btNPAPRsend=TRUE;
			m_bSendNPAPRF=FALSE;
			m_bSendNPAPR=TRUE;			
			m_strrunning.Format("%0.2f",m_fsenddistance/1000);
			m_strrunning.Insert(0,"APR距离:");
			m_showrunning.AddMsg(m_strrunning);
			
			m_strrunning.Format("0X%08X",wParam);
			m_strrunning.Insert(0,"APRid:");
			m_showrunning.AddMsg(m_strrunning);
	
			
			m_byte=wParam&0x0000003f;
			m_byte=m_byte<<2;
			m_byteWritePAPR10[0x0b]=m_byte;
			
			wParam=wParam>>6;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x0a]=m_byte;
			
			wParam=wParam>>8;
			m_byte=wParam&0x000000ff;
			m_byteWritePAPR10[0x09]=m_byte;
			
			wParam=wParam>>8;
			m_byteWritePAPR10[0x08]=wParam;
			
			m_byteWritePAPR10[0x07]=0;
			m_byteWritePAPR10[0x06]=0x81;
			
			//重新发送APR，清除标志无效
			m_bAlreadyClear=FALSE;
			break;
		}
	}
	return 0;
}
LRESULT CALLTRACKAUTOView::OnThreadSendCode(WPARAM wParam,LPARAM lParam)
{

	switch (wParam)
	{
		//上行发送轨道码
	case 1:
		{
			CString m_str;
			BYTE	m_byte;
			int		m_ncodepos=0;
			float	m_fchangecodepos;
			//载频
			//判断是否开启载频变换测试
			if (m_bCarrayFruChangeTest==TRUE)
			{
				CString m_strtest;
				if (m_bytepCFCT<40)
				{
					m_byteWriteTrackCode[0x06]=m_byteaCFCT[m_bytepCFCT];
					
					m_strtest.Format("当前测试第:%d个载频",m_bytepCFCT+1);
					m_promptinfoshow.SetCString(7,m_strtest);
					m_strtest.Format("载频码为:F%d",m_byteaCFCT[m_bytepCFCT]);
					m_promptinfoshow.SetCString(8,m_strtest);
					m_bytepCFCT++;
				}
				else
				{
					//载频变换测试结束
					m_bCarrayFruChangeTest=FALSE;
					m_strtest="载频变换测试结束";
					m_promptinfoshow.SetCString(7,m_strtest);
					m_promptinfoshow.SetCString(8,m_strtest);
				}
			} 
			else
			{
				m_str=m_uptrack[lParam].m_CF;
				m_str.Delete(0,3);
				m_byte=atoi(m_str);
				if (m_byte==0x09)
				{
					m_byte=0x08;
				}
				m_byteWriteTrackCode[0x06]=m_byte;
			}
			//码频
			m_byte=m_uptrack[lParam].m_SENDCODE;
			if (m_byte==0)
			{
				return 0;
			}
			m_byteWriteTrackCode[0x07]=m_byte;
			//根据头尾车、前进方向计算变码位置

			m_fchangecodepos=(float)(m_dgmail+DISTANCE);	
			m_str.Format("%0.2f",m_dgmail);
			m_str.Insert(0,"里程:");
			m_showrunning.AddMsg(m_str);
			m_fchangecodepos=m_fchangecodepos*1000;
			m_ncodepos=(int)m_fchangecodepos;
			m_str.Format("%0.2f",m_fchangecodepos/1000);
			m_str.Insert(0,"轨道码:");
			m_showrunning.AddMsg(m_str);
			m_byteWriteTrackCode[0x09]=m_ncodepos;
			m_ncodepos=m_ncodepos>>8;
			m_byteWriteTrackCode[0x0a]=m_ncodepos;
			m_ncodepos=m_ncodepos>>8;
			m_byteWriteTrackCode[0x0b]=m_ncodepos;
			m_ncodepos=m_ncodepos>>8;
			m_byteWriteTrackCode[0x0c]=m_ncodepos;
			//生成握手信息，该信息独立于其它命令信息
			m_byte=m_byteWriteTrackCode[0x07]<<4;
			m_byte+=m_byteWriteTrackCode[0x06];
			m_byteWriteTrackCode[0x14]=m_byte;
			m_uptrack[lParam].m_btcodesend=TRUE;
			m_bSendCode=TRUE;
			m_ngtrackpointer=lParam;
			//重新发送轨道码，清除标志无效
			m_bAlreadyClear=FALSE;
			//将车辆高度更改为轨道高度
			m_ngTrainhigh=m_uptrack[lParam].m_TRACKENDHIGH-TRAINTOTRACK;
			m_pTrainpos.y=m_ngTrainhigh;
			//保存轨道结束点，用于寻找与该轨道连接的轨道
			m_nTrackEndPos=m_uptrack[lParam].m_Tendpos;
			m_bgTrackEndPosCalculate=TRUE;
			//轨道信息赋值
			m_promptinfonexttrack.SetUpDown(m_uptrack[lParam].m_UpDown);
			m_promptinfonexttrack.SetSname(m_uptrack[lParam].m_Sname);
			m_promptinfonexttrack.SetTSname(m_uptrack[lParam].m_TSname);
			m_promptinfonexttrack.SetTSnumber(m_uptrack[lParam].m_Tsnumber);
			m_str.Format("%d",m_uptrack[lParam].m_Slenth);
			m_promptinfonexttrack.SetTSlenth(m_str);
			m_promptinfonexttrack.SetCF(m_uptrack[lParam].m_CF);
			m_promptinfonexttrack.SetNPAPRnumber(m_uptrack[lParam].m_NPAPRnumber);
			m_str.Format("%d",m_uptrack[lParam].m_NPAPRpos);
			m_promptinfonexttrack.SetNPAPRpos(m_str);
			m_str.Format("%d",m_uptrack[lParam].m_SENDCODE);
			m_promptinfonexttrack.SetCodeFru(m_str);

			//自动泊车
			
			break;
		}
		//下行发送轨道码
	case 2:
		{
			CString m_str;
			BYTE	m_byte;
			int		m_ncodepos=0;
			float	m_fchangecodepos;
			//载频
			//判断是否开启载频变换测试
			if (m_bCarrayFruChangeTest==TRUE)
			{
				CString m_strtest;
				if (m_bytepCFCT<40)
				{
					m_byteWriteTrackCode[0x06]=m_byteaCFCT[m_bytepCFCT];
					
					m_strtest.Format("当前测试第:%d个载频",m_bytepCFCT+1);
					m_promptinfoshow.SetCString(7,m_strtest);
					m_strtest.Format("载频码为:F%d",m_byteaCFCT[m_bytepCFCT]);
					m_promptinfoshow.SetCString(8,m_strtest);
					m_bytepCFCT++;
				}
				else
				{
					//载频变换测试结束
					m_bCarrayFruChangeTest=FALSE;
					m_strtest="载频变换测试结束";
					m_promptinfoshow.SetCString(7,m_strtest);
					m_promptinfoshow.SetCString(8,m_strtest);
				}
			} 
			else
			{
				m_str=m_downtrack[lParam].m_CF;
				m_str.Delete(0,3);
				m_byte=atoi(m_str);
				if (m_byte==0x09)
				{
					m_byte=0x08;
				}
				m_byteWriteTrackCode[0x06]=m_byte;
			}
			//码频
			m_byte=m_downtrack[lParam].m_SENDCODE;
			if (m_byte==0)
			{
				return 0;
			}
			m_byteWriteTrackCode[0x07]=m_byte;
			m_fchangecodepos=(float)(m_dgmail+DISTANCE);
			m_str.Format("%0.2f",m_dgmail);
			m_str.Insert(0,"里程:");
			m_showrunning.AddMsg(m_str);
			m_fchangecodepos=m_fchangecodepos*1000;
			m_ncodepos=(int)m_fchangecodepos;
			m_str.Format("%0.2f",m_fchangecodepos/1000);
			m_str.Insert(0,"轨道码:");
			m_showrunning.AddMsg(m_str);
			m_byteWriteTrackCode[0x09]=m_ncodepos;
			m_ncodepos=m_ncodepos>>8;
			m_byteWriteTrackCode[0x0a]=m_ncodepos;
			m_ncodepos=m_ncodepos>>8;
			m_byteWriteTrackCode[0x0b]=m_ncodepos;
			m_ncodepos=m_ncodepos>>8;
			m_byteWriteTrackCode[0x0c]=m_ncodepos;
			//生成握手信息，该信息独立于其它命令信息
			m_byte=m_byteWriteTrackCode[0x07]<<4;
			m_byte+=m_byteWriteTrackCode[0x06];
			m_byteWriteTrackCode[0x14]=m_byte;
			m_downtrack[lParam].m_btcodesend=TRUE;
			m_bSendCode=TRUE;
			m_ngtrackpointer=lParam;
			//重新发送轨道码，清除标志无效
			m_bAlreadyClear=FALSE;
			//将车辆高度更改为轨道高度
			m_ngTrainhigh=m_downtrack[lParam].m_TRACKENDHIGH-TRAINTOTRACK;
			m_pTrainpos.y=m_ngTrainhigh;
			m_Train.SetTrainPos(m_pTrainpos);
			//轨道结束点
			m_nTrackEndPos=m_downtrack[lParam].m_Tendpos;
			m_bgTrackEndPosCalculate=TRUE;
			//轨道信息赋值
			m_promptinfonexttrack.SetUpDown(m_downtrack[lParam].m_UpDown);
			m_promptinfonexttrack.SetSname(m_downtrack[lParam].m_Sname);
			m_promptinfonexttrack.SetTSname(m_downtrack[lParam].m_TSname);
			m_promptinfonexttrack.SetTSnumber(m_downtrack[lParam].m_Tsnumber);
			m_str.Format("%d",m_downtrack[lParam].m_Slenth);
			m_promptinfonexttrack.SetTSlenth(m_str);
			m_promptinfonexttrack.SetCF(m_downtrack[lParam].m_CF);
			m_promptinfonexttrack.SetNPAPRnumber(m_downtrack[lParam].m_NPAPRnumber);
			m_str.Format("%d",m_downtrack[lParam].m_NPAPRpos);
			m_promptinfonexttrack.SetNPAPRpos(m_str);
			m_str.Format("%d",m_downtrack[lParam].m_SENDCODE);
			m_promptinfonexttrack.SetCodeFru(m_str);

			//自动泊车
			if ((m_downtrack[lParam].m_stoppos!=0)&&(m_bAutoStop==TRUE))
			{
				m_promptinfoMailandV.SetCString(2,"已经检测到自动停车点!");
			//	m_bAutoStopPoint=TRUE;
				m_dAutoStopPoint=(double)(m_downtrack[lParam].m_Tstartpos+m_downtrack[lParam].m_stoppos)+1000;
				CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
				m_frame->Ebtotargetspeed((float) AUTOSTOPBREAK);
			}
			//判断当前轨道是否发送二次轨道码
			if ((m_downtrack[lParam].m_SENDCODE2!=0)&&(m_downtrack[lParam].m_SENDCODE2pos!=0))
			{
				//计算二次发送轨道码位置和轨道码
				m_gnSecondCodepos=m_downtrack[lParam].m_Tstartpos/100+m_downtrack[lParam].m_SENDCODE2pos;
				m_gnSecondcode=m_downtrack[lParam].m_SENDCODE2;
				//保存当前车辆位置
				pThreadSCode=AfxBeginThread(ThreadISSendSecondCode,(LPVOID)GetSafeHwnd());
			}

			break;
		}
	}
	return 0;
}
LRESULT CALLTRACKAUTOView::OnThreadMessage(WPARAM wParam,LPARAM lParam)
{
	switch (wParam)
	{
	case 0:
		{
			if (lParam==0)
			{
				//轨道数据加载完成,开始绘制轨道
				m_bLoadAllTrackFinish=TRUE;

				InvalidateRect(m_recttrack,TRUE);

			}
			break;
		}
	default :
		{
			break;
		}
	}
	return 0;
}

void CALLTRACKAUTOView::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	pDC->SetMapMode(MM_ANISOTROPIC);
	GetClientRect(m_rcClient);
	m_recttrack=m_rcClient;
	pDC->SetBkMode(TRANSPARENT);
	CBrush m_brush(HS_DIAGCROSS,RGB(124,24,24));
	CPen	m_pen(PS_SOLID,1,m_colorgline);
	//双缓冲
	CDC MemDC; //首先定义一个显示设备对象 
	CBitmap MemBitmap;//定义一个位图对象 
	MemDC.CreateCompatibleDC(NULL); //随后建立与屏幕显示兼容的内存显示设备 
	MemBitmap.CreateCompatibleBitmap(pDC,m_rcClient.Width(),m_rcClient.Height()); 
	//将位图选入到内存显示设备中 
	//只有选入了位图的内存显示设备才有地方绘图，画到指定的位图上 
	CBitmap *pOldBit=MemDC.SelectObject(&MemBitmap); 
	//先用背景色将位图清除干净，这里我用的是白色作为背景 
	MemDC.FillSolidRect(0,0,m_rcClient.Width(),m_rcClient.Height(),RGB(255,255,255)); 
	MemDC.SelectObject((CPen * )&m_pen);
	MemDC.SelectObject((CBrush * )&m_brush);
	MemDC.SetTextColor(m_colorgfont);	//文字颜色
	if (m_bLoadAllTrackFinish==TRUE)
	{
		//轨道
		for (int i=0;i<TRACKUP;i++)
		{
			m_uptrack[i].ShowTrack(&MemDC);
		}
		for (int k=0;k<TRACKDOWN;k++)
		{
			m_downtrack[k].ShowTrack(&MemDC);
		}
		//站
		for (int j=0;j<20;j++)
		{
			m_station[j].ShowStation(&MemDC);
		}
		//前车速度
		m_speedheadline.ShowLine(&MemDC,1);
		//尾车速度
		m_speedtailline.ShowLine(&MemDC,0);
	}
	if (m_bShowTrain==TRUE)
	{
		m_Train.ShowTrain(&MemDC);
		m_speedtable.ShowSpeedTable(&MemDC);
	}
	if (m_bshowhandle==TRUE)
	{
		m_showmsg.Showmsg(&MemDC);
	}
	if (m_bshowauto==TRUE)
	{
		m_showautomsg.Showmsg(&MemDC);
	}
	if (m_bshowdebug==TRUE)
	{
		m_showstatusmsg.Showmsg(&MemDC);	//状态
	}
	if (m_bshowreturn1==TRUE)
	{
		m_showhdmsg.Showmsg(&MemDC,TRUE);		//头尾车
	}
	if (m_bshowreturn2==TRUE)
	{
		m_showtcode.Showmsg(&MemDC);		//轨道码
	}
	if (m_bshowreturn3==TRUE)
	{
		m_shownpapr.Showmsg(&MemDC);		//无源信标
	}
	
	m_showpapr.Showmsg(&MemDC);			//有源信标	//未实现

	if (m_bshowcalculate==TRUE)
	{
		m_showrunning.Showmsg(&MemDC);		//运行信息
	}
	
	m_promptinfonexttrack.SetPos(SHOWMSGBASEPOS+200,0);
	m_promptinfonexttrack.ShowPromp(&MemDC);	//提示信息
	if (m_bCarrayFruChangeTest==TRUE)
	{
		m_promptinfoCFCT.SetPos(SHOWMSGBASEPOS+1200,0);
		m_promptinfoCFCT.ShowPromp(&MemDC);
	}
	m_promptinfoshow.SetPos(SHOWMSGBASEPOS+630,0);
	m_promptinfoshow.ShowPromp(&MemDC);
	m_promptinfoStatus.SetPos(SHOWMSGBASEPOS+550,0);
	m_promptinfoStatus.ShowPromp(&MemDC);
	m_promptinfoParser.SetPos(SHOWMSGBASEPOS+750,0);
	m_promptinfoParser.ShowPromp(&MemDC);
	m_promptinfoAPRreturn.SetPos(SHOWMSGBASEPOS+350,0);
	m_promptinfoAPRreturn.ShowPromp(&MemDC);
	m_promptinfoMailandV.SetPos(SHOWMSGBASEPOS,0);
	m_promptinfoMailandV.ShowPromp(&MemDC);
	//将内存中的图拷贝到屏幕上进行显示 
	pDC->BitBlt(0,0,m_rcClient.Width(),m_rcClient.Height(),&MemDC,0,0,SRCCOPY); 
	//绘图完成后的清理 
	MemBitmap.DeleteObject(); 
	MemDC.DeleteDC(); 
	
}

BOOL CALLTRACKAUTOView::OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CRecordView::OnScroll(nScrollCode, nPos, bDoScroll);
}

void CALLTRACKAUTOView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent)
	{
		//自动停车
	case 1:
		{
			CheckIsBreak();
			break;
		}
	case 2:
		{
			InitOtherAfter5Second();
			break;
		}

	}
	CRecordView::OnTimer(nIDEvent);
}
LRESULT CALLTRACKAUTOView::OnMyDLGMessage(WPARAM wParam, LPARAM lParam) 
{ 
	Invalidate(TRUE);
	return 0; 
} 
LRESULT CALLTRACKAUTOView::OnMyCOMMessage(WPARAM wParam, LPARAM lParam) 
{ 
	//串口接收到数据消息
	switch (m_byteCom[0x05])
	{
	case 0x80:
		{
			MandV();
			break;
		}
	case 0x90:
		{
			
			for (int i=0;i<24;i++)
			{
				m_byteCom90[i]=m_byteCom[i];
			}
			TrainStatus();
			break;
		}
	case 0xA0:
		{
			int m_naprchange=0;
			int m_ntrackcodechange=0;
			CString	m_str;
			CString m_temp;	
			CString m_strtowrite;
			int m_nadd=0;
			float m_fadd=0;
			float m_fcode=0;
			int m_id=0;
			//apr change add
			m_naprchange=m_byteCom[0x09];
			m_naprchange=m_naprchange<<8;
			m_naprchange+=m_byteCom[0x08];
			m_naprchange=m_naprchange<<8;
			m_naprchange+=m_byteCom[0x07];
			m_naprchange=m_naprchange<<8;
			m_naprchange+=m_byteCom[0x06];
			//apr id
			m_id=((m_byteCom[0x0b] & 0x3f) << 22) | (m_byteCom[0x0c] << 14) | (m_byteCom[0x0d] << 6) | ((m_byteCom[0x0e] & 0xfc) >> 2);
			m_fadd=(float)m_naprchange;
			m_fadd=m_fadd/1000;
			m_str.Format("APR变化位置:%10.1f",m_fadd);
			m_promptinfoAPRreturn.SetCString(0,m_str);
			m_temp.Format("ID号:%08X",m_id);
			m_promptinfoAPRreturn.SetCString(1,m_temp);
			m_str+=m_temp;
			m_strtowrite=m_str;
			m_strtowrite+=" ";
			m_ntrackcodechange=m_byteCom[0x13];
			m_ntrackcodechange=m_ntrackcodechange<<8;
			m_ntrackcodechange+=m_byteCom[0x12];
			m_ntrackcodechange=m_ntrackcodechange<<8;
			m_ntrackcodechange+=m_byteCom[0x11];
			m_ntrackcodechange=m_ntrackcodechange<<8;
			m_ntrackcodechange+=m_byteCom[0x10];

			m_fcode=(float)m_ntrackcodechange;
			m_fcode=m_fcode/1000;
			m_str.Format("轨道码变化位置:%10.1f",m_fcode);
			m_promptinfoAPRreturn.SetCString(2,m_str);
			m_temp.Format("%d",m_byteCom[0x14]);
			m_temp.Insert(0,"载频:F");
			m_promptinfoAPRreturn.SetCString(3,m_temp);
			/*
			if (m_byteCom[0x14]==m_byteWriteTrackCode[0x06])
			{
				m_showhdmsg.AddMsg(m_temp,4,TRUE);
			} 
			else
			{
				m_showhdmsg.AddMsg(m_temp,4,FALSE);
			}
			*/
			m_str+=m_temp;


			m_strtowrite+=m_str;
			m_strtowrite+=" ";
			float		m_foldadd=0;
			float		m_foldcode=0;

			m_foldadd=m_fadd-m_fgaproldadd;
			m_foldcode=m_fcode-m_fgtrackcode;
			
			m_str.Format("APR距离差:%10.1f",m_foldadd);
			m_promptinfoAPRreturn.SetCString(4,m_str);
			m_temp.Format("轨道码距离差:%0.1f",m_foldcode);
			m_promptinfoAPRreturn.SetCString(5,m_temp);
			m_fgaproldadd=m_fadd;
			m_fgtrackcode=m_fcode;
			m_str+=m_temp;

		//	m_showhdmsg.AddMsg(m_str);
			m_strtowrite+=m_str;
			//码频
			m_str.Format("码频:M%d",m_byteCom[0x15]);
			m_promptinfoAPRreturn.SetCString(6,m_str);
			/*
			if (m_byteCom[0x15]==m_byteWriteTrackCode[0x07])
			{
				m_showhdmsg.AddMsg(m_str,7,TRUE);
			} 
			else
			{
				m_showhdmsg.AddMsg(m_str,7,FALSE);
			}
			*/
			m_strtowrite+=m_str;
			WriteRecoder(m_strtowrite);
			/*
			m_str.Format("车辆位置:%f",m_dgTrainRealPos);
			m_showhdmsg.AddMsg(m_str,8,TRUE);
			//显示当前天线位置，应该与APR重合，减去检测范围
			m_str.Format("天线位置:%f",m_fgantennaforshow-DISTANCE);
			m_showhdmsg.AddMsg(m_str,9,TRUE);
			m_str.Format("阅读器位置:%f",m_fgreaderforshow-DISTANCE);
			m_showhdmsg.AddMsg(m_str,10,TRUE);
			*/
		}
	}
	 
	return 0; 
} 
LRESULT CALLTRACKAUTOView::OnMyCOMWrite(WPARAM wParam, LPARAM lParam) 
{ 
	//串口发送消息
	switch (wParam)
	{
		//状态
	case 0x30:
		{
			CString m_str;
			m_str=m_macro.GetCode((unsigned char)lParam,FALSE);
			m_str.Insert(0,"发送:");
			m_showautomsg.AddMsg(m_str);
			break;
		}
		//轨道码
	case 0x40:
		{
			CString m_str;
			m_str=m_trackcode.GetTrackCode((unsigned char)lParam,0);
			m_str.Insert(0,"发送:");
			m_showautomsg.AddMsg(m_str);
			break;
		}
		//头尾车
	case 0x50:
		{
			CString m_str;
			m_str=m_macro.GetCode((unsigned char)lParam,FALSE);
			m_str.Insert(0,"发送:");
			m_showautomsg.AddMsg(m_str);
		}
		//无源信标
	case 0x70:
		{
			CString m_str;
			m_str=m_macro.GetCode((unsigned char)lParam,FALSE);
			m_str.Insert(0,"发送:");
			m_showautomsg.AddMsg(m_str);
			break;
		}
		//有源信标
	case 0x80:
		{
			CString m_str;
			m_str=m_macro.GetCode((unsigned char)lParam,FALSE);
			m_str.Insert(0,"发送:");
			m_showautomsg.AddMsg(m_str);
			break;
		}
		//调试帧
	case 0x0A:
		{
			
		}
	}
	
	return 0; 
} 

void CALLTRACKAUTOView::MandV()
{
	//全局车辆行驶里程，不由下位机直接给出，下位机只给出总计行驶里程
	CalculateTrainPos();	//上位机计算列车实际位置

	pThreadSeek->PostThreadMessage(WM_SEEKTRACKDATA,0,0);	//计算当前里程是否需要发送轨道码
	pThreadAPR->PostThreadMessage(WM_SEEKISSENDAPR,0,0);	//检查是否发送APR
	m_nTrainView=126;										//计算列车显示位置，先钉死列车位置

	m_nTrackView=(int)(m_dgTrainRealPos*AMPLIFICATORY_TIMES-m_nTrainView*AMPLIFICATORY_TIMES);			//计算轨道显示位置


	/*
	//判断里程是否为252，为252则表示工装重新上电，清除所有已存标志
	if (m_dgTrainRealPos==126)
	{
		if (m_bAlreadyClear==FALSE)
		{
			ClearFlagsForReset();
		}
	}
	*/
	//判断里程是否大于最大里程,大于最大里程则自动掉转方向转为上行
	if ((m_dgTrainRealPos>=41000)&&(m_bAutoBreak==FALSE))
	{
		//行驶里程大于最大允许值
		CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
		m_frame->OnMenueb();
		m_bAutoBreak=TRUE;
	}
	//视图显示，暂不调试
	if (m_bViewOn==TRUE)
	{
		//视图位置计算，根据上下行
		m_pTrainpos.x=m_nTrainView*AMPLIFICATORY_TIMES;
		m_pTrainShowpos=m_pTrainpos;	//车辆显示位置赋值
	} 
	else
	{

	}
	//判断车辆是否在该视图内
	POINT	m_ptrainstart=m_pTrainShowpos;
	POINT	m_ptrainend=m_pTrainShowpos;
	m_ptrainstart.x-=119;
	m_ptrainend.x+=119;
	m_bShowTrain=FALSE;
	if (PtInRect(m_rcClient,m_ptrainstart)||PtInRect(m_rcClient,m_ptrainend))
	{
		m_Train.SetTrainPos(m_pTrainShowpos);
		//速度
		m_speedheadline.SetSpeed(m_nTrackView+m_pTrainShowpos.x+TRAINLENTH,(int)Speed()*AMPLIFICATORY_TIMES);
		//m_speedheadline.SetSpeed(m_nTrackView+m_pTrainShowpos.x-TRAINLENTH,(int)Speed()*AMPLIFICATORY_TIMES);
		m_bShowTrain=TRUE;
	}
	//方向
	MilemeterDir();
	//状态信息
	BackStatus();
	if ((m_nTrackView!=m_noldmail)&&(m_bViewOn==TRUE))
	{
		m_noldmail=m_nTrackView;
		//Invalidate(TRUE);
		InvalidateRect(m_recttrack,TRUE);
	} 
}

void CALLTRACKAUTOView::TrainStatus()
{
	//模拟控制台档位信息
	BackGear();
	//ATP控车QN继电器输出的回采
	CirclePickQN();
	//健康信号
	Healthy();
	//继电器
	Relay();
	//下位机软件版本号
	SoftVersion();
	//阅读器信息处理
	Reader();
	InvalidateRect(m_recttrack,TRUE);
}

double CALLTRACKAUTOView::Mail()
{
	//里程为4个字节为测速电机脉冲数寄存器表示脉冲的个数里程的计算为N*((PI*D)/200)（PI为π值D为论经值200为论经的齿数）
	unsigned int m_unmail=0;
	double		m_dmail=0;
	m_unmail=m_byteCom[9];
	m_unmail=m_unmail<<8;
	m_unmail+=m_byteCom[8];
	m_unmail=m_unmail<<8;
	m_unmail+=m_byteCom[7];
	m_unmail=m_unmail<<8;
	m_unmail+=m_byteCom[6];

	if ((m_unmail==0)&&(m_bHardwareReset==TRUE))
	{
		//总里程为0，下位机重启,上位机记录量清零
		m_unmail=0;
		LoadConfig();	//重新加载配置
		m_bHardwareReset=FALSE;
	}
	if ((m_unmail>0)&&(m_bHardwareReset==FALSE))
	{
		m_bHardwareReset=TRUE;
	}
	m_dmail=m_unmail*((PI*Wheel_Diametear[m_byteWriteStatus[0x12]])/130);
	m_dmail=m_dmail/1000;
	CString m_strmail;

	m_strmail.Format("%12f",m_dmail);
	CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
	m_strmail.Insert(0,"里程:");
	m_frame->m_wndStatusBar.SetPaneText(8,m_strmail);
	//放大倍数
	return m_dmail;
}

bool CALLTRACKAUTOView::MilemeterDir()
{

	byte m_bytemilemeterdir=m_byteCom[10];
	CString m_strmilemilemeterdir;
	switch (m_bytemilemeterdir)
	{
	case 0xAA:
		{
			m_strmilemilemeterdir="方向:前";
			break;
		}
	case 0x55:
		{
			m_strmilemilemeterdir="方向:后";
			break;
		}
	}
	CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
	m_frame->m_wndStatusBar.SetPaneText(10,m_strmilemilemeterdir);
	return TRUE;
}

double CALLTRACKAUTOView::Speed()
{
	double m_dspeed=0;
	WORD m_wspeed=0;
	CString m_strspeed;
	m_wspeed=m_byteCom[13];
	m_wspeed=m_wspeed<<8;
	m_wspeed+=m_byteCom[12];
	m_dspeed=m_wspeed;
	m_dspeed=m_dspeed/100;
	m_dgspeed=m_dspeed;
	m_strspeed.Format("%f",m_dspeed);
	m_strspeed.Insert(0,"速度:");
	CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
	m_frame->m_wndStatusBar.SetPaneText(11,m_strspeed);
	return m_dspeed;
}
void CALLTRACKAUTOView::BackStatus()
{
	//返回状态信息
	//对话框显示
	if (m_dlgmsg->IsWindowVisible())
	{
		CString m_strmsg;
		int		m_ncounter=0;
		m_strmsg.Format("%02X",m_byteCom[0x11]);
		m_strmsg.Insert(0,"列车状态:");

		if (m_strmsg!=m_strmsgstatus)
		{
			m_dlgmsg->m_cliststatus.AddString(m_strmsg);
			m_ncounter=m_dlgmsg->m_cliststatus.GetCount();
			m_dlgmsg->m_cliststatus.SetCurSel(m_ncounter-1);
			m_strmsgstatus=m_strmsg;
		}

		m_strmsg.Format("%02X",m_byteCom[0x12]);
		m_strmsg.Insert(0,"头尾车:");

		if (m_strmsg!=m_strmsghd)
		{
			m_dlgmsg->m_clisthd.AddString(m_strmsg);
			m_ncounter=m_dlgmsg->m_clisthd.GetCount();
			m_dlgmsg->m_clisthd.SetCurSel(m_ncounter-1);
			m_strmsghd=m_strmsg;
		}
		
		m_strmsg.Format("%02X",m_byteCom[0x13]);
		m_strmsg.Insert(0,"轨道码:");

		if (m_strmsg!=m_strmsgtrackcode)
		{
			m_dlgmsg->m_clisttrackcode.AddString(m_strmsg);
			m_ncounter=m_dlgmsg->m_clisttrackcode.GetCount();
			m_dlgmsg->m_clisttrackcode.SetCurSel(m_ncounter-1);
			m_strmsgtrackcode=m_strmsg;
		}

		m_strmsg.Format("%02X",m_byteCom[0x14]);
		m_strmsg.Insert(0,"无源信标:");
		if (m_strmsg!=m_strmsgnpapr)
		{
			m_dlgmsg->m_clistnpapr.AddString(m_strmsg);
			m_ncounter=m_dlgmsg->m_clistnpapr.GetCount();
			m_dlgmsg->m_clistnpapr.SetCurSel(m_ncounter-1);
			m_strmsgnpapr=m_strmsg;
		}

		m_strmsg.Format("%02X",m_byteCom[0x15]);
		m_strmsg.Insert(0,"有源信标:");
		if (m_strmsg!=m_strmsgpapr)
		{
			m_dlgmsg->m_clistpapr.AddString(m_strmsg);
			m_ncounter=m_dlgmsg->m_clistpapr.GetCount();
			m_dlgmsg->m_clistpapr.SetCurSel(m_ncounter-1);
			m_strmsgpapr=m_strmsg;
		}
	}
	//即时显示
	if (m_byteCom[0x05]==0x80)
	{
		//状态
		if ((m_byteWriteStatus[0x14]==m_byteCom[0x11])&&(m_byteCom[0x11]!=0))
		{
			m_bSendStatus=FALSE;
			m_showstatusmsg.AddMsg(m_macro.GetCode(m_byteWriteStatus[0x14],TRUE));
			m_byteWriteStatus[0x14]=0;
		}
		//头尾车
		if ((m_byteWriteCaputCauda[0x14]==m_byteCom[0x12])&&(m_byteCom[0x12]!=0))
		{
			m_bSendHD=FALSE;
			m_showhdmsg.AddMsg(m_macro.GetCode(m_byteWriteCaputCauda[0x14],TRUE));
			m_byteWriteCaputCauda[0x14]=0;
		}

		//轨道码
		if ((m_byteWriteTrackCode[0x14]==m_byteCom[0x13])&&(m_byteCom[0x13]!=0))
		{
			m_bSendCode=FALSE;
			m_showtcode.AddMsg(m_trackcode.GetTrackCode(m_byteWriteTrackCode[0x14],TRUE));
			m_byteWriteTrackCode[0x14]=0;
		}
		//无源信标
		if ((m_byteWritePAPR70[0x14]==m_byteCom[0x14])&&(m_byteCom[0x14]!=0)&&(m_bSendNPAPRF==TRUE))
		{
			m_bSendNPAPR=FALSE;
			m_shownpapr.AddMsg(m_macro.GetCode(m_byteWritePAPR70[0x14],TRUE));
			m_byteWritePAPR70[0x14]=0;
			m_bSendNPAPRF=FALSE;
		}
		//有源信标
		if ((m_byteWritePAPR70[0x14]==m_byteCom[0x14])&&(m_byteCom[0x14]!=0)&&(m_bSendPAPRF==TRUE))
		{
			m_bSendPAPR=FALSE;
			m_shownpapr.AddMsg(m_macro.GetCode(m_byteWritePAPR70[0x14],TRUE));
			m_byteWritePAPR70[0x14]=0;
			m_bSendPAPRF=FALSE;
		}
	}
}
byte CALLTRACKAUTOView::BackGear()
{
	byte m_bytegear=0;
	return m_bytegear;
}

byte CALLTRACKAUTOView::CirclePickQN()
{
	byte m_byteQN=0;
	return m_byteQN;
}

void CALLTRACKAUTOView::Healthy()
{
	int m_nhealthy=0;
	__int64 m_n64healthy=1000000000;
	CString m_strhealthy;
	m_nhealthy=m_byteCom90[13];
	m_nhealthy=m_nhealthy<<8;

	m_nhealthy+=m_byteCom90[12];
	m_nhealthy=m_nhealthy<<8;

	m_nhealthy+=m_byteCom90[11];
	m_nhealthy=m_nhealthy<<8;
	m_nhealthy+=m_byteCom90[10];

	if (m_nhealthy>0)
	{
		m_n64healthy=m_n64healthy*m_byteCom90[9];
		m_n64healthy=m_n64healthy/(m_nhealthy*20);
	} 
	else
	{
		m_n64healthy=0;
	}
	m_strhealthy.Format("%d",m_n64healthy+1);
	m_strhealthy.Insert(0,"健康:");
	m_strhealthy+="Hz";
	CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
	m_frame->m_wndStatusBar.SetPaneText(12,m_strhealthy);
}

void CALLTRACKAUTOView::Relay()
{
	CString m_strrelay;
	CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
	//按现场实测数据更改，数据位和数据内容与倪横江文档内容有冲突
	//ZVR
	if (m_byteCom90[0xf]&0x01)
	{
		m_strrelay="ZVR1:1";
		m_frame->m_wndStatusBar2.SetPaneText(4,m_strrelay);
	} 
	else
	{
		m_strrelay="ZVR1:0";
		m_frame->m_wndStatusBar2.SetPaneText(4,m_strrelay);
	}
	if (m_byteCom90[0xf]&0x02)
	{
		m_strrelay="ZVR2:1";
		m_frame->m_wndStatusBar1.SetPaneText(4,m_strrelay);
	} 
	else
	{
		m_strrelay="ZVR2:0";
		m_frame->m_wndStatusBar1.SetPaneText(4,m_strrelay);
	}
	if (m_byteCom90[0xe]&0x80)
	{
		m_strrelay="ZVR:1";
		m_frame->m_wndStatusBar.SetPaneText(4,m_strrelay);
	} 
	else
	{
		m_strrelay="ZVR:0";
		m_frame->m_wndStatusBar.SetPaneText(4,m_strrelay);
	}

	//EB
	if (m_byteCom90[0xe]&0x10)
	{
		m_strrelay="EB1:1";
		m_frame->m_wndStatusBar2.SetPaneText(0,m_strrelay);
	} 
	else
	{
		m_strrelay="EB1:0";
		m_frame->m_wndStatusBar2.SetPaneText(0,m_strrelay);
	}

	if (m_byteCom90[0xe]&0x20)
	{
		m_strrelay="EB2:1";
		m_frame->m_wndStatusBar1.SetPaneText(0,m_strrelay);
	} 
	else
	{
		m_strrelay="EB2:0";
		m_frame->m_wndStatusBar1.SetPaneText(0,m_strrelay);
	}
	if (m_byteCom90[0xe]&0x40)
	{
		m_strrelay="SIR:0";
		m_frame->m_wndStatusBar.SetPaneText(0,m_strrelay);
		if (m_bdisableeb==FALSE)
		{
			CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
			m_frame->OnMenueb();
			m_bEBvalid=TRUE;
			m_bDisableNone=FALSE;
		}
	} 
	else
	{
		m_strrelay="SIR:1";
		m_frame->m_wndStatusBar.SetPaneText(0,m_strrelay);
		if ((m_bdisablefsb==FALSE)&&(m_bDisableNone==FALSE))
		{
			//解决持续空挡
			CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
			m_frame->OnMenunone();
			m_bEBvalid=FALSE;
		}
	}

	//FSB
	if (m_byteCom90[0xe]&0x02)
	{
		m_strrelay="FSB1:0";
		m_frame->m_wndStatusBar2.SetPaneText(1,m_strrelay);
	} 
	else
	{
		m_strrelay="FSB1:1";
		m_frame->m_wndStatusBar2.SetPaneText(1,m_strrelay);
	}

	if (m_byteCom90[0xe]&0x04)
	{
		m_strrelay="FSB2:0";
		m_frame->m_wndStatusBar1.SetPaneText(1,m_strrelay);
	} 
	else
	{
		m_strrelay="FSB2:1";
		m_frame->m_wndStatusBar1.SetPaneText(1,m_strrelay);
	}
	if (m_byteCom90[0xe]&0x08)
	{
		m_strrelay="FSB:0";
		m_frame->m_wndStatusBar.SetPaneText(1,m_strrelay);
		if ((m_bdisablefsb==FALSE)&&(m_bEBvalid==FALSE)&&(m_bDisableNone==FALSE))
		{
			//解决持续空挡
			CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
			m_frame->OnMenunone();
		}
	}
	else
	{
		m_strrelay="FSB:1";
		m_frame->m_wndStatusBar.SetPaneText(1,m_strrelay);
		if ((m_bdisablefsb==FALSE)&&(m_bEBvalid==FALSE))
		{
			CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
			m_frame->OnMenub7();
			m_bDisableNone=FALSE;
		}
	}

	//RDER
	if (m_byteCom90[0xf]&0x20)
	{
		m_strrelay="RDER1:1";
		m_frame->m_wndStatusBar2.SetPaneText(2,m_strrelay);
	} 
	else
	{
		m_strrelay="RDER1:0";
		m_frame->m_wndStatusBar2.SetPaneText(2,m_strrelay);
	}
	if (m_byteCom90[0xf]&0x40)
	{
		m_strrelay="RDER2:1";
		m_frame->m_wndStatusBar1.SetPaneText(2,m_strrelay);
	} 
	else
	{
		m_strrelay="RDER2:0";
		m_frame->m_wndStatusBar1.SetPaneText(2,m_strrelay);
	}
	if (m_byteCom90[0xf]&0x80)
	{
		m_strrelay="RDER:0";
		m_frame->m_wndStatusBar.SetPaneText(2,m_strrelay);
	} 
	else
	{
		m_strrelay="RDER:1";
		m_frame->m_wndStatusBar.SetPaneText(2,m_strrelay);
	}

	//LDER
	if (m_byteCom90[0xf]&0x04)
	{
		m_strrelay="LDER1:1";
		m_frame->m_wndStatusBar2.SetPaneText(3,m_strrelay);
	} 
	else
	{
		m_strrelay="LDER1:0";
		m_frame->m_wndStatusBar2.SetPaneText(3,m_strrelay);
	}
	if (m_byteCom90[0xf]&0x08)
	{
		m_strrelay="LDER2:1";
		m_frame->m_wndStatusBar1.SetPaneText(3,m_strrelay);
	} 
	else
	{
		m_strrelay="LDER2:0";
		m_frame->m_wndStatusBar1.SetPaneText(3,m_strrelay);
	}

	if (m_byteCom90[0xf]&0x10)
	{
		m_strrelay="LDER:0";
		m_frame->m_wndStatusBar.SetPaneText(3,m_strrelay);
	} 
	else
	{
		m_strrelay="LDER:1";
		m_frame->m_wndStatusBar.SetPaneText(3,m_strrelay);
	}
	//CHR
	if (m_byteCom90[0x10]&0x04)
	{
		m_strrelay="CHR1:0";
		m_frame->m_wndStatusBar2.SetPaneText(5,m_strrelay);
	} 
	else
	{
		m_strrelay="CHR1:1";
		m_frame->m_wndStatusBar2.SetPaneText(5,m_strrelay);
	}
	
	if (m_byteCom90[0x10]&0x08)
	{
		m_strrelay="CHR2:0";
		m_frame->m_wndStatusBar1.SetPaneText(5,m_strrelay);
	} 
	else
	{
		m_strrelay="CHR2:1";
		m_frame->m_wndStatusBar1.SetPaneText(5,m_strrelay);
	}
	//TIR
	if (m_byteCom90[0xe]&0x01)
	{
		m_strrelay="TIR:0";
		m_frame->m_wndStatusBar.SetPaneText(5,m_strrelay);
	} 
	else
	{
		m_strrelay="TIR:1";
		m_frame->m_wndStatusBar.SetPaneText(5,m_strrelay);
	}
	//TIRR
	if (m_byteCom90[0x10]&0x02)
	{
		m_strrelay="TIRR:1";
		m_frame->m_wndStatusBar.SetPaneText(6,m_strrelay);
	} 
	else
	{
		m_strrelay="TIRR:0";
		m_frame->m_wndStatusBar.SetPaneText(6,m_strrelay);
	}
	//EUMR
	if (m_byteCom90[0x10]&0x01)
	{
		m_strrelay="EUMR:1";
		m_frame->m_wndStatusBar.SetPaneText(7,m_strrelay);
	} 
	else
	{
		m_strrelay="EUMR:0";
		m_frame->m_wndStatusBar.SetPaneText(7,m_strrelay);
	}
	//以下是按倪横江文档内容
	/*
	//ZVR
	if (m_byteCom90[0xf]&0x01)
	{
		m_strrelay="ZVR1:1";
		m_frame->m_wndStatusBar2.SetPaneText(4,m_strrelay);
	} 
	else
	{
		m_strrelay="ZVR1:0";
		m_frame->m_wndStatusBar2.SetPaneText(4,m_strrelay);
	}
	if (m_byteCom90[0xf]&0x02)
	{
		m_strrelay="ZVR2:1";
		m_frame->m_wndStatusBar1.SetPaneText(4,m_strrelay);
	} 
	else
	{
		m_strrelay="ZVR2:0";
		m_frame->m_wndStatusBar1.SetPaneText(4,m_strrelay);
	}
	if (m_byteCom90[0xe]&0x80)
	{
		m_strrelay="ZVR:1";
		m_frame->m_wndStatusBar.SetPaneText(4,m_strrelay);
	} 
	else
	{
		m_strrelay="ZVR:0";
		m_frame->m_wndStatusBar.SetPaneText(4,m_strrelay);
	}

	//EB
	if (m_byteCom90[0xe]&0x20)
	{
		m_strrelay="EB1:1";
		m_frame->m_wndStatusBar2.SetPaneText(0,m_strrelay);
	} 
	else
	{
		m_strrelay="EB1:0";
		m_frame->m_wndStatusBar2.SetPaneText(0,m_strrelay);
	}

	if (m_byteCom90[0xe]&0x40)
	{
		m_strrelay="EB2:1";
		m_frame->m_wndStatusBar1.SetPaneText(0,m_strrelay);
	} 
	else
	{
		m_strrelay="EB2:0";
		m_frame->m_wndStatusBar1.SetPaneText(0,m_strrelay);
	}
	if (m_byteCom90[0xe]&0x10)
	{
		m_strrelay="SIR:1";
		m_frame->m_wndStatusBar.SetPaneText(0,m_strrelay);
		if ((m_bdisablefsb==FALSE)&&(m_bDisableNone==FALSE))
		{
			//解决持续空挡
			CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
			m_frame->OnMenunone();
			m_bEBvalid=FALSE;
		}
	} 
	else
	{
		m_strrelay="SIR:0";
		m_frame->m_wndStatusBar.SetPaneText(0,m_strrelay);
		if (m_bdisableeb==FALSE)
		{
			CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
			m_frame->OnMenueb();
			m_bEBvalid=TRUE;
			m_bDisableNone=FALSE;
		}
	}


	//FSB
	if (m_byteCom90[0xe]&0x04)
	{
		m_strrelay="FSB1:0";
		m_frame->m_wndStatusBar2.SetPaneText(1,m_strrelay);
	} 
	else
	{
		m_strrelay="FSB1:1";
		m_frame->m_wndStatusBar2.SetPaneText(1,m_strrelay);
	}
	if (m_byteCom90[0xe]&0x08)
	{
		m_strrelay="FSB2:1";
		m_frame->m_wndStatusBar1.SetPaneText(1,m_strrelay);
	}
	else
	{
		m_strrelay="FSB2:0";
		m_frame->m_wndStatusBar1.SetPaneText(1,m_strrelay);
	}
	if (m_byteCom90[0xe]&0x02)
	{
		m_strrelay="FSB:0";
		m_frame->m_wndStatusBar.SetPaneText(1,m_strrelay);
		if ((m_bdisablefsb==FALSE)&&(m_bEBvalid==FALSE))
		{
			CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
			m_frame->OnMenub7();
			m_bDisableNone=FALSE;
		}
	} 
	else
	{
		m_strrelay="FSB:1";
		m_frame->m_wndStatusBar.SetPaneText(1,m_strrelay);
		if ((m_bdisablefsb==FALSE)&&(m_bEBvalid==FALSE)&&(m_bDisableNone==FALSE))
		{
			//解决持续空挡
			CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
			m_frame->OnMenunone();
		}
	}
	//RDER
	if (m_byteCom90[0xf]&0x40)
	{
		m_strrelay="RDER1:1";
		m_frame->m_wndStatusBar2.SetPaneText(2,m_strrelay);
	} 
	else
	{
		m_strrelay="RDER1:0";
		m_frame->m_wndStatusBar2.SetPaneText(2,m_strrelay);
	}
	if (m_byteCom90[0xf]&0x80)
	{
		m_strrelay="RDER2:1";
		m_frame->m_wndStatusBar1.SetPaneText(2,m_strrelay);
	} 
	else
	{
		m_strrelay="RDER2:0";
		m_frame->m_wndStatusBar1.SetPaneText(2,m_strrelay);
	}

	if (m_byteCom90[0xf]&0x20)
	{
		m_strrelay="RDER:1";
		m_frame->m_wndStatusBar.SetPaneText(2,m_strrelay);
	} 
	else
	{
		m_strrelay="RDER:0";
		m_frame->m_wndStatusBar.SetPaneText(2,m_strrelay);
	}
	//LDER
	if (m_byteCom90[0xf]&0x08)
	{
		m_strrelay="LDER1:1";
		m_frame->m_wndStatusBar2.SetPaneText(3,m_strrelay);
	} 
	else
	{
		m_strrelay="LDER1:0";
		m_frame->m_wndStatusBar2.SetPaneText(3,m_strrelay);
	}
	if (m_byteCom90[0xf]&0x10)
	{
		m_strrelay="LDER2:1";
		m_frame->m_wndStatusBar1.SetPaneText(3,m_strrelay);
	} 
	else
	{
		m_strrelay="LDER2:0";
		m_frame->m_wndStatusBar1.SetPaneText(3,m_strrelay);
	}

	if (m_byteCom90[0xf]&0x04)
	{
		m_strrelay="LDER:1";
		m_frame->m_wndStatusBar.SetPaneText(3,m_strrelay);
	} 
	else
	{
		m_strrelay="LDER:0";
		m_frame->m_wndStatusBar.SetPaneText(3,m_strrelay);
	}
	//CHR
	if (m_byteCom90[0x10]&0x04)
	{
		m_strrelay="CHR1:1";
		m_frame->m_wndStatusBar2.SetPaneText(5,m_strrelay);
	} 
	else
	{
		m_strrelay="CHR1:0";
		m_frame->m_wndStatusBar2.SetPaneText(5,m_strrelay);
	}
	
	if (m_byteCom90[0x10]&0x08)
	{
		m_strrelay="CHR2:1";
		m_frame->m_wndStatusBar1.SetPaneText(5,m_strrelay);
	} 
	else
	{
		m_strrelay="CHR2:0";
		m_frame->m_wndStatusBar1.SetPaneText(5,m_strrelay);
	}
	//TIR
	if (m_byteCom90[0xe]&0x01)
	{
		m_strrelay="TIR:1";
		m_frame->m_wndStatusBar.SetPaneText(5,m_strrelay);
	} 
	else
	{
		m_strrelay="TIR:0";
		m_frame->m_wndStatusBar.SetPaneText(5,m_strrelay);
	}
	//TIRR
	if (m_byteCom90[0x10]&0x02)
	{
		m_strrelay="TIRR:1";
		m_frame->m_wndStatusBar.SetPaneText(6,m_strrelay);
	} 
	else
	{
		m_strrelay="TIRR:0";
		m_frame->m_wndStatusBar.SetPaneText(6,m_strrelay);
	}
	//EUMR
	if (m_byteCom90[0x10]&0x01)
	{
		m_strrelay="EUMR:1";
		m_frame->m_wndStatusBar.SetPaneText(7,m_strrelay);
	} 
	else
	{
		m_strrelay="EUMR:0";
		m_frame->m_wndStatusBar.SetPaneText(7,m_strrelay);
	}
	*/

	

}

void CALLTRACKAUTOView::SoftVersion()
{
	CString m_strversion;
	float m_fversion;
	CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
	if (m_byteCom90[0x11]&0x80)
	{
		m_fversion=(float)m_byteCom90[0x11]-128;
		m_fversion=m_fversion/10;
		m_strversion.Format("%f",m_fversion);
		m_strversion.Insert(0,"ATPM:");
		m_frame->m_wndStatusBar.SetPaneText(17,m_strversion.Left(8));
	}
	else
	{
		m_fversion=(float)m_byteCom90[0x11];
		m_fversion=m_fversion/10;
		m_strversion.Format("%f",m_fversion);
		m_strversion.Insert(0,"OMPM:");
		m_frame->m_wndStatusBar.SetPaneText(18,m_strversion.Left(8));
	}
}

void CALLTRACKAUTOView::Reader()
{
	byte m_bytereader=0;
	m_bytereader=m_byteCom90[0x12]&0xc0;
	CString m_strreader;
	CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
	switch (m_bytereader)
	{
	case 0:
		{
			m_strreader="阅读器:无状态";
			m_frame->m_wndStatusBar.SetPaneText(14,m_strreader);
			break;
		}
	case 0x80:
		{
			m_strreader="阅读器:正常";
			m_frame->m_wndStatusBar.SetPaneText(14,m_strreader);
			break;
		}
	case 0x40:
		{
			m_strreader="阅读器:待机";
			m_frame->m_wndStatusBar.SetPaneText(14,m_strreader);
			break;
		}
	case 0xc0:
		{
			m_strreader="阅读器:配置帧";
			m_frame->m_wndStatusBar.SetPaneText(14,m_strreader);
			break;
		}	
	}
	m_bytereader=m_byteCom90[0x12]&0x30;
	switch (m_bytereader)
	{
	case 0:
		{
			m_strreader="阅读距离:最小";
			m_frame->m_wndStatusBar.SetPaneText(15,m_strreader);
			break;
		}
	case 0x10:
		{
			m_strreader="阅读距离:小";
			m_frame->m_wndStatusBar.SetPaneText(15,m_strreader);
			break;
		}
	case 0x20:
		{
			m_strreader="阅读距离:大";
			m_frame->m_wndStatusBar.SetPaneText(15,m_strreader);
			break;
		}
	case 0x30:
		{
			m_strreader="阅读距离:最大";
			m_frame->m_wndStatusBar.SetPaneText(15,m_strreader);
			break;
		}
	}
	m_bytereader=m_byteCom90[0x12]&0x08;
	switch (m_bytereader)
	{
	case 0:
		{
			m_strreader="蜂鸣器:不蜂鸣";
			m_frame->m_wndStatusBar.SetPaneText(16,m_strreader);
			break;
		}
	case 0x08:
		{
			m_strreader="蜂鸣器:蜂鸣";
			m_frame->m_wndStatusBar.SetPaneText(16,m_strreader);
			break;
		}
	}
}

BOOL CALLTRACKAUTOView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	//return CRecordView::OnEraseBkgnd(pDC); 用于取消view擦除背景
	return TRUE;                                                                                                                     
}

void CALLTRACKAUTOView::WriteRecoder(CString m_strtowr)
{
	//加入当前系统时间
	static int m_snrecodercounter=0;
	CString m_strsystime;
	SYSTEMTIME  m_systime;
	GetLocalTime(&m_systime);
	m_strsystime.Format("%4d-%2d-%2d %02d:%02d:%02d %03d ",m_systime.wYear,m_systime.wMonth,m_systime.wDay, m_systime.wHour,m_systime.wMinute,m_systime.wSecond,m_systime.wMilliseconds);
	m_strtowr.Insert(0,m_strsystime);
	m_strsystime.Format("%5d  ",m_snrecodercounter);
	m_strtowr.Insert(0,m_strsystime);
	CFile m_file;
	m_file.Open("RunningRecoder.txt",CFile::modeWrite|CFile::modeCreate|CFile::modeNoTruncate);
	m_strtowr+="\r\n";
	m_file.SeekToEnd();
	m_file.Write(m_strtowr,m_strtowr.GetLength());
	m_file.Close();
	m_snrecodercounter++;
}

void CALLTRACKAUTOView::ClearFlagsForReset()
{
	//清除轨道已发送标志
	//上行轨道
	for (int up=0;up<TRACKUP;up++)
	{ 
		//APR
		if (m_uptrack[up].m_btNPAPRsend==TRUE)
		{
			m_uptrack[up].m_btNPAPRsend=FALSE;
		}
		if (m_uptrack[up].m_btcodesend==TRUE)
		{
			m_uptrack[up].m_btcodesend=FALSE;
		}
		if (m_uptrack[up].m_btPAPRsend==TRUE)
		{
			m_uptrack[up].m_btPAPRsend=FALSE;
		}
		
		if (m_uptrack[up].m_btNPAPR2send==TRUE)
		{
			m_uptrack[up].m_btNPAPR2send=FALSE;
		}
	}
	//下行轨道
	for (int down=0;down<TRACKDOWN;down++)
	{
		if (m_downtrack[down].m_btNPAPRsend==TRUE)
		{
			m_downtrack[down].m_btNPAPRsend=FALSE;
		}
		if (m_downtrack[down].m_btcodesend==TRUE)
		{
			m_downtrack[down].m_btcodesend=FALSE;
		}
		if (m_downtrack[down].m_btPAPRsend==TRUE)
		{
			m_downtrack[down].m_btPAPRsend=FALSE;
		}
		if (m_downtrack[down].m_btNPAPR2send==TRUE)
		{
			m_downtrack[down].m_btNPAPR2send=FALSE;
		}
	}
	//清除完成
	m_bAlreadyClear=TRUE;
	m_bgTrackEndPosCalculate=FALSE;	//是否采用轨道连续方式寻找轨道
}
LRESULT CALLTRACKAUTOView::OnMyClearFlag(WPARAM wParam, LPARAM lParam)
{
	ClearFlagsForReset();
	return 0;
}

void CALLTRACKAUTOView::CalculateTrainPos()
{
	double m_dmail;
	m_dmail=Mail();		//获得下位机给出的列车总里程

	if (m_dmail>0)
	{
		m_dgaddmail=m_dmail-m_dgmail;
		m_dgmail=m_dmail;
		if (m_bDirectorup==TRUE)	//根据上下行判断车辆行走方向
		{
			//用车辆位置减去下位机里程增量
			m_dgTrainRealPos-=m_dgaddmail;
		} 
		else
		{
			//用车辆位置加上下位机里程增量
			m_dgTrainRealPos+=m_dgaddmail;
		}
	}
}
LRESULT CALLTRACKAUTOView::OnMySaveTurnPos(WPARAM wParam, LPARAM lParam)
{
	m_dgTrainTrunPos=Mail();
	m_bReverse=TRUE;
	m_dgTrainAddPos=0;	//列车增量清零
	m_bgTrackEndPosCalculate=FALSE;
	m_bgSendCurrentTrackCode=FALSE;	//折弯时置标志位，发送当前轨道码
	return 0;
}
LRESULT CALLTRACKAUTOView::OnMyAutoStop(WPARAM wParam, LPARAM lParam)
{
	if (!m_bAutoStop)
	{
		m_promptinfoMailandV.SetCString(4,"您已启动自动泊车系统!");
		m_bAutoStop=TRUE;
	} 
	else
	{
		m_promptinfoMailandV.SetCString(4,"您退出动自动泊车系统!");
		m_bAutoStop=FALSE;
		KillTimer(1);
	}
	return 0;
}
LRESULT CALLTRACKAUTOView::OnMyOnTargetSpeed(WPARAM wParam, LPARAM lParam)
{
	//列车已经达到目标速度，开始计算列车到停车点距离
	SetTimer(1,1,NULL);
	return 0;
}
void CALLTRACKAUTOView::FindTrackofTrain(float m_fantennapos)
{
	//该天线为车辆天线，不是阅读器
	CALLTRACKAUTOSet *m_pAlltrack;
	double	m_dtstartpos,m_dtendpos;
	if (m_bDirectorup==TRUE)
	{
		m_pAlltrack=m_uptrack;
		for (int i=0;i<TRACKUP;i++)
		{
			m_dtstartpos=m_pAlltrack->m_Tstartpos;
			m_dtstartpos=m_dtstartpos/100;
			m_dtendpos=m_pAlltrack->m_Tstartpos-m_pAlltrack->m_Slenth;
			m_dtendpos=m_dtendpos/100;
			if ((m_fantennapos<=m_dtstartpos)&&(m_fantennapos>=m_dtendpos)&&(m_pAlltrack->m_TRACKENDHIGH==m_ngTrainhigh+TRAINTOTRACK))
			{
				//找到车辆所在轨道,发送该轨道码，车辆不可停在两条轨道上
				OnThreadSendCode(1,i);
			}
			m_pAlltrack++;
		}
	}
	else
	{
		m_pAlltrack=m_downtrack;
		for (int i=0;i<TRACKDOWN;i++)
		{
			m_dtstartpos=m_pAlltrack->m_Tstartpos;
			m_dtstartpos=m_dtstartpos/100;
			m_dtendpos=m_pAlltrack->m_Tstartpos+m_pAlltrack->m_Slenth;
			m_dtendpos=m_dtendpos/100;
			if ((m_fantennapos>=m_dtstartpos)&&(m_fantennapos<=m_dtendpos)&&(m_pAlltrack->m_TRACKENDHIGH==m_ngTrainhigh+TRAINTOTRACK)) 	
			{
				//找到车辆所在轨道,发送该轨道码，车辆不可停在两条轨道上
				//OnThreadSendCode(2,i);
				SendOnTimeCode( STRCFtoINTCF(m_pAlltrack->m_CF),m_pAlltrack->m_SENDCODE);
				break;
			}
			m_pAlltrack++;
		}
	}
}

LRESULT CALLTRACKAUTOView::OnMySendCurrentTrackCode(WPARAM wParam, LPARAM lParam)
{
	//发送天线所在轨道码频
	float m_fantenna=(float)lParam;
	m_fantenna=m_fantenna/100;
	FindTrackofTrain(m_fantenna);
	return 0;
}

void CALLTRACKAUTOView::LoadConfig()
{
	CString m_strFilePath=CONFIG_FILE_PATH;
	m_nGapOffSet=GetPrivateProfileInt("CONFIG","GAPOFFSET",0,LPCSTR(m_strFilePath));
	m_ngTrainhigh=GetPrivateProfileInt("CONFIG","TRAINHIGH",650,LPCSTR(m_strFilePath));
	m_pTrainpos.y=m_ngTrainhigh;

	m_dgTrainRealPos=(float)GetPrivateProfileInt("CONFIG","TRAINSTART",126,LPCSTR(m_strFilePath));
	m_dgTrainRealPos=m_dgTrainRealPos-TRAINHALFLENTH;
	int m_n=GetPrivateProfileInt("CONFIG","SHOWMSG",0,LPCSTR(m_strFilePath));
	if (!m_n)
	{
		m_bshowhandle=FALSE;
		m_bshowhandle=FALSE;
		m_bshowauto=FALSE;
		m_bshowreturn1=FALSE;
		m_bshowreturn2=FALSE;
		m_bshowreturn3=FALSE;
		m_bshowdebug=FALSE;
		m_bshowcalculate=FALSE;
	}
	//加载有源APR数据
	m_papr[0].m_npaprid=0x055ED16F;
	m_papr[1].m_npaprid=0x055ED170;
	m_papr[2].m_npaprid=0x055ED294;

	m_papr[0].m_bytedata[0]=GetPrivateProfileInt("0x055ED16F","DATA0",0,LPCSTR(m_strFilePath));
	m_papr[0].m_bytedata[1]=GetPrivateProfileInt("0x055ED16F","DATA1",0,LPCSTR(m_strFilePath));
	m_papr[0].m_bytedata[2]=GetPrivateProfileInt("0x055ED16F","DATA2",0,LPCSTR(m_strFilePath));
	m_papr[0].m_bytedata[3]=GetPrivateProfileInt("0x055ED16F","DATA3",0,LPCSTR(m_strFilePath));
	m_papr[0].m_bytedata[4]=GetPrivateProfileInt("0x055ED16F","DATA4",0,LPCSTR(m_strFilePath));
	m_papr[0].m_bytedata[5]=GetPrivateProfileInt("0x055ED16F","DATA5",0,LPCSTR(m_strFilePath));

	m_papr[1].m_bytedata[0]=GetPrivateProfileInt("0x055ED170","DATA0",0,LPCSTR(m_strFilePath));
	m_papr[1].m_bytedata[1]=GetPrivateProfileInt("0x055ED170","DATA1",0,LPCSTR(m_strFilePath));
	m_papr[1].m_bytedata[2]=GetPrivateProfileInt("0x055ED170","DATA2",0,LPCSTR(m_strFilePath));
	m_papr[1].m_bytedata[3]=GetPrivateProfileInt("0x055ED170","DATA3",0,LPCSTR(m_strFilePath));
	m_papr[1].m_bytedata[4]=GetPrivateProfileInt("0x055ED170","DATA4",0,LPCSTR(m_strFilePath));
	m_papr[1].m_bytedata[5]=GetPrivateProfileInt("0x055ED170","DATA5",0,LPCSTR(m_strFilePath));
	
	m_papr[2].m_bytedata[0]=GetPrivateProfileInt("0x055ED294","DATA0",0,LPCSTR(m_strFilePath));
	m_papr[2].m_bytedata[1]=GetPrivateProfileInt("0x055ED294","DATA1",0,LPCSTR(m_strFilePath));
	m_papr[2].m_bytedata[2]=GetPrivateProfileInt("0x055ED294","DATA2",0,LPCSTR(m_strFilePath));
	m_papr[2].m_bytedata[3]=GetPrivateProfileInt("0x055ED294","DATA3",0,LPCSTR(m_strFilePath));
	m_papr[2].m_bytedata[4]=GetPrivateProfileInt("0x055ED294","DATA4",0,LPCSTR(m_strFilePath));
	m_papr[2].m_bytedata[5]=GetPrivateProfileInt("0x055ED294","DATA5",0,LPCSTR(m_strFilePath));
	
	
}

BOOL CALLTRACKAUTOView::CheckIsBreak()
{
	//车钩到停车点距离
	double m_dclasp=0;	//车钩位置
	//为保证车辆停准，采用CM单位
	m_dclasp=m_dgTrainRealPos*100+TRAINHALFLENTH*100+1010;
	double m_dbreakdistance;
	double m_dspeed=m_dgspeed/3.6*100;
	//B6制动
	double m_dacc=1.0285714285714285714285714285*200;
	m_dbreakdistance=m_dspeed*m_dspeed/m_dacc;
	if ((m_dAutoStopPoint-m_dclasp)<(m_dbreakdistance))
	{
		KillTimer(1);
		CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
		m_frame->OnMenub6();
	}
	return TRUE;
}
UINT ThreadISSendSecondCode(LPVOID lpParam)
{
	UINT m_uint=1;
	while(m_uint)
	{
		switch (m_gnAntennaNumber)
		{
		case 1:
			{
				if (m_dgTrainRealPos+(float)TRAINHALFLENTH-(float)ANTENNATOCUSP+DISTANCE>=m_gnSecondCodepos)
				{
					//关闭线程
					::PostMessage((HWND)lpParam, WM_SENDSECONDCODE, m_gnSecondCodepos, m_gnSecondcode);
					m_uint=0;
				}
				break;
			}
		case 2:
			{
				if (m_dgTrainRealPos-DISTANCE<=m_gnSecondCodepos)
				{
					//关闭线程
					::PostMessage((HWND)lpParam, WM_SENDSECONDCODE, m_gnSecondCodepos, m_gnSecondcode);
					m_uint=0;
				}
				break;
			}
		case 3:
			{
				if (m_dgTrainRealPos+DISTANCE>=m_gnSecondCodepos)
				{
					//关闭线程
					::PostMessage((HWND)lpParam, WM_SENDSECONDCODE, m_gnSecondCodepos, m_gnSecondcode);
					m_uint=0;
				}
				break;
			}
		case 4:
			{
				if (m_dgTrainRealPos-DISTANCE<=m_gnSecondCodepos)
				{
					//关闭线程
					::PostMessage((HWND)lpParam, WM_SENDSECONDCODE, m_gnSecondCodepos, m_gnSecondcode);
					m_uint=0;
				}
				break;
			}
		}
		Sleep(1);
	}
	return m_uint;
}
LRESULT CALLTRACKAUTOView::OnResetTrainPos(WPARAM wParam, LPARAM lParam)
{
	//人工设置车辆位置
	
	//变量记录清零
	ClearFlagsForReset();
	m_bgTrackEndPosCalculate=FALSE;	//是否采用轨道连续方式寻找轨道
	//发送车钩所在轨道码和检测是否发送APR
	FindTrackofTrain((float)wParam);
	m_bgTrackEndPosCalculate=FALSE;	//是否采用轨道连续方式寻找轨道
	return 0;
}
LRESULT CALLTRACKAUTOView::OnMySendSecondTrackCode(WPARAM wParam, LPARAM lParam)
{

	float m_fchangecodepos;
	int	m_ncodepos;
	byte m_byte;
	CString m_str;
	//码频
	m_byte=(unsigned int)lParam;
	m_byteWriteTrackCode[0x07]=m_byte;
	m_fchangecodepos=(float)(m_dgmail+DISTANCE);
	m_str.Format("%0.2f",m_dgmail);
	m_str.Insert(0,"里程:");
	m_showrunning.AddMsg(m_str);
	m_fchangecodepos=m_fchangecodepos*1000;
	m_ncodepos=(int)m_fchangecodepos;
	m_str.Format("%0.2f",m_fchangecodepos/1000);
	m_str.Insert(0,"轨道码:");
	m_showrunning.AddMsg(m_str);
	m_byteWriteTrackCode[0x09]=m_ncodepos;
	m_ncodepos=m_ncodepos>>8;
	m_byteWriteTrackCode[0x0a]=m_ncodepos;
	m_ncodepos=m_ncodepos>>8;
	m_byteWriteTrackCode[0x0b]=m_ncodepos;
	m_ncodepos=m_ncodepos>>8;
	m_byteWriteTrackCode[0x0c]=m_ncodepos;
	//生成握手信息，该信息独立于其它命令信息
	m_byte=m_byteWriteTrackCode[0x07]<<4;
	m_byte+=m_byteWriteTrackCode[0x06];
	m_byteWriteTrackCode[0x14]=m_byte;
	m_downtrack[lParam].m_btcodesend=TRUE;
	m_bSendCode=TRUE;
	m_ngtrackpointer=lParam;
	//重新发送轨道码，清除标志无效
	m_bAlreadyClear=FALSE;
	m_promptinfonexttrack.SetUpDown(m_downtrack[lParam].m_UpDown);
	m_promptinfonexttrack.SetSname(m_downtrack[lParam].m_Sname);
	m_promptinfonexttrack.SetTSname(m_downtrack[lParam].m_TSname);
	m_promptinfonexttrack.SetTSnumber(m_downtrack[lParam].m_Tsnumber);
	m_str.Format("%d",m_downtrack[lParam].m_Slenth);
	m_promptinfonexttrack.SetTSlenth(m_str);
	m_promptinfonexttrack.SetCF(m_downtrack[lParam].m_CF);
	m_promptinfonexttrack.SetNPAPRnumber(m_downtrack[lParam].m_NPAPRnumber);
	m_str.Format("%d",m_downtrack[lParam].m_NPAPRpos);
	m_promptinfonexttrack.SetNPAPRpos(m_str);
	m_str.Format("%d",m_downtrack[lParam].m_SENDCODE);
	m_promptinfonexttrack.SetCodeFru(m_str);
	return 0;
}

LRESULT CALLTRACKAUTOView::SendOnTimeCode(int m_cf, int m_code)
{
	m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]^0x40;
	m_byteWriteCaputCauda[0x14]=ONTIME;
	
	m_bSendHD=TRUE;
	/*
	载波频率编码表：
	载频（Hz）	4080	4320	4560	4800	5040	5280	5520	6000  无码
	发送编号(16进制)	1	2	3	4	5	6	7	8	0x0a
	调制频率编码表：
	码频（Hz）	28	32	36	40	44	48	52	56	60	64	68	72	76	80
	发送编号(16进制)	1	2	3	4	5	6	7	8	9	A	B	C	D	E
	*/
	Sleep(200);

	m_byteWriteStatus[0x0b]=0;
	
	switch (m_cf-1)
	{
	case 0:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x10;
		break;
	case 1:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x20;
		break;
	case 2:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x30;
		break;
	case 3:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x40;
		break;
	case 4:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x50;
		break;
	case 5:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x60;
		break;
	case 6:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x70;
		break;
	case 7:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x80;
		break;
	case 8:
		m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0xA0;
		break;
	}
	
	switch (m_code-1)
	{
				case 0:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x01;
					break;
				case 1:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x02;
					break;
				case 2:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x03;
					break;
				case 3:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x04;
					break;
				case 4:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x05;
					break;
				case 5:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x06;
					break;
				case 6:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x07;
					break;
				case 7:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x08;
					break;
				case 8:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x09;
					break;
				case 9:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x0a;
					break;
				case 10:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x0b;
					break;
				case 11:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x0c;
					break;
				case 12:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x0d;
					break;
				case 13:
					m_byteWriteStatus[0x0b]=m_byteWriteStatus[0x0b]^0x0e;
					break;
	}
	m_byteWriteStatus[0x14]=ONTIMECC;
	m_bSendStatus=TRUE;
	Sleep(200);
	
	m_byteWriteCaputCauda[0x07]=m_byteWriteCaputCauda[0x07]&0xbf;
	m_byteWriteCaputCauda[0x14]=NOONTIME;
	
	m_bSendHD=TRUE;

	return 0;
}

int CALLTRACKAUTOView::STRCFtoINTCF(CString m_strcf)
{
	BYTE m_byte;
	m_strcf.Delete(0,3);
	m_byte=atoi(m_strcf);
	return m_byte;
}

LRESULT CALLTRACKAUTOView::OnThreadRXMessage(WPARAM wParam,LPARAM lParam)		//接收串口消息
{
	static int m_snc=0;
	m_snc+=wParam;
	CString m_temp;
	m_temp.Format("%d",m_snc);
//	m_CRXCounterByte.SetWindowText(m_temp);

	static bool m_binitsq=TRUE;
	if (m_binitsq==TRUE)
	{
		m_binitsq=FALSE;
		
		if (InitQueue(q)==-1)
		{
			AfxMessageBox("创建缓冲区失败!");
		}
	}
	//将接收的串口数，全部入队
	for (int i=0;i<(int)wParam;i++)
	{
		EnQueue(q,m_byteRXbuffer[i]);
	}
	//判断缓冲区内是否够一帧数据
	for (int m_nc=QueueLenth(q);m_nc>=24;m_nc--)
	{
		//出队 检查是否收到0xfc
		if(DeQueue(q,m_byteFrame[0])!=0)
		{
			AfxMessageBox("读缓冲区失败");
		}
		if (m_byteFrame[0]==0xfc)
		{
			m_strshowRX+="FC";
			for (int j=1;j<24;j++)
			{
				DeQueue(q,m_byteFrame[j]);
				m_temp.Format("%02X",m_byteFrame[j]);
				m_strshowRX+=m_temp;
			}
			//命令解析
			FrameParse();
			/*
			m_strshowRX+="\r\n";
			m_CRX.SetSel(-1, -1);
			m_CRX.ReplaceSel( (LPCTSTR)m_strshowRX);
			m_CRX.PostMessage(WM_VSCROLL, SB_BOTTOM,0);
			*/
			m_nc-=23;
			m_strshowRX.Empty();
		}
	}

	if (m_strshowRX.GetLength()>1024)
	{
		m_strshowRX.Empty();
	}

	return 0;
}

void CALLTRACKAUTOView::Init()//初始化数据
{
	CCOMPORT m_comport;
	//m_comport.InitPort();	//串口初始化
	m_comport.OpenPort(2);
	InitFrame();
}
LRESULT CALLTRACKAUTOView::OnReceiveAComPort(WPARAM wParam, LPARAM lParam)	//找到串口并添加
{
	static int m_nindex=0;
	CString m_strport;
	m_strport.Format("COM%d",lParam);
//	m_Ccomportnumber.InsertString(m_nindex,m_strport);
	m_nindex++;
//	m_Ccomportnumber.SetCurSel(0);
	return 0;
}
void CALLTRACKAUTOView::InitFrame()//帧值初始化
{
	m_byteWriteFrame1[0x00]=FRAME_HEAD1;
	m_byteWriteFrame2[0x00]=FRAME_HEAD1;
	m_byteWriteFrame3[0x00]=FRAME_HEAD1;
	m_byteWriteFrame4[0x00]=FRAME_HEAD1;
	
	m_byteWriteFrame1[0x01]=FRAME_HEAD2;
	m_byteWriteFrame2[0x01]=FRAME_HEAD2;
	m_byteWriteFrame3[0x01]=FRAME_HEAD2;
	m_byteWriteFrame4[0x01]=FRAME_HEAD2;
	
	m_byteWriteFrame1[0x02]=LOCAL_ADDRESS;
	m_byteWriteFrame2[0x02]=LOCAL_ADDRESS;
	m_byteWriteFrame3[0x02]=LOCAL_ADDRESS;
	m_byteWriteFrame4[0x02]=LOCAL_ADDRESS;
	
	m_byteWriteFrame1[0x05]=FRAME_SEQUENCE_70;
	m_byteWriteFrame2[0x05]=FRAME_SEQUENCE_E0;
	m_byteWriteFrame3[0x05]=FRAME_SEQUENCE_E1;
	m_byteWriteFrame4[0x05]=FRAME_SEQUENCE_E2;
	
}


LRESULT CALLTRACKAUTOView::OnWriteComPortMSG(WPARAM wParam, LPARAM lParam)//串口信息发送显示
{
	//显示发送信息
	CString m_str;
	CString m_strf1,m_strf2,m_strf3,m_strf4;
	for (int i=0;i<24;i++)
	{
		m_str.Format("%02X",m_byteWriteFrame1[i]);
		m_strf1+=m_str;
		m_str.Format("%02X",m_byteWriteFrame2[i]);
		m_strf2+=m_str;
		m_str.Format("%02X",m_byteWriteFrame3[i]);
		m_strf3+=m_str;
		m_str.Format("%02X",m_byteWriteFrame4[i]);
		m_strf4+=m_str;
	}
	m_strf1+="\r\n";
	m_strf2+="\r\n";
	m_strf3+="\r\n";
	m_strf4+="\r\n";
	
	m_str=m_strf1+m_strf2+m_strf3+m_strf4;
	//文件写入记录
//	m_CTX.ReplaceSel(m_str);
//	m_CTX.PostMessage(WM_VSCROLL, SB_BOTTOM,0);
	return 0;
}

void CALLTRACKAUTOView::FrameParse()
{
	//协议解析
	BYTE	m_bytetmp=0;
	WORD		m_nMC=0;
	m_bytetmp=m_byteFrame[DATASTART+1];

	//			//B5档测试
	//解析第一字节，作为最高位
	m_bytetmp=RightMove(m_bytetmp,2,1);
	m_bytetmp=RightMove(m_bytetmp,4,2);
	m_bytetmp=m_bytetmp&0x0F;	//只要低字节
	m_nMC=m_bytetmp;
	//解析第二字节，作为次高位
	m_bytetmp=m_byteFrame[DATASTART+2];
	//m_bytetmp=0x19;			//B5档测试
	m_bytetmp=RightMove(m_bytetmp,2,1);
	m_bytetmp=RightMove(m_bytetmp,3,1);
	m_bytetmp=RightMove(m_bytetmp,4,1);
	m_bytetmp=m_bytetmp&0x0F;	//只要低字节
	m_nMC=m_nMC<<4;
	m_nMC=m_nMC|m_bytetmp;
	//解析第三字节，作为次低位
	m_bytetmp=m_byteFrame[DATASTART+3];
	//m_bytetmp=0x14;			//B5档测试
	m_bytetmp=RightMove(m_bytetmp,2,1);
	m_bytetmp=RightMove(m_bytetmp,3,1);
	m_bytetmp=RightMove(m_bytetmp,4,1);
	m_bytetmp=m_bytetmp&0x0F;	//只要低字节
	m_nMC=m_nMC<<4;
	m_nMC=m_nMC|m_bytetmp;
	//解析第四字节，作为最低位
	m_bytetmp=m_byteFrame[DATASTART+4];
	//m_bytetmp=0xb2;			//B5档测试
	m_bytetmp=m_bytetmp&0x50;
	m_bytetmp=m_bytetmp>>4;
	m_bytetmp=m_bytetmp&0x0F;	//只要低字节
	m_nMC=m_nMC<<4;
	m_nMC=m_nMC|m_bytetmp;
	if ((m_bdisablefsb==FALSE)&&(m_bdisableeb==FALSE))
	{
			switch (m_nMC)
			{
			case MC_P4:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenud4();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO档位P4");
					break;
				}
			case MC_P3:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenud3();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO档位P3");
					break;
				}
			case MC_P2:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenud2();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO档位P2");
					break;
				}
			case MC_P1:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenud1();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO档位P1");
					break;
				}
			case MC_N:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenunone();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO档位P0");
					break;
				}
			case MC_B1:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenub1();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO档位B1");
					break;
				}
			case MC_B2:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenub2();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO档位B2");
					break;
				}
			case MC_B3:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenub3();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO档位B3");
					break;
				}
			case MC_B4:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenub4();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO档位B4");
					break;
				}
			case MC_B5:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenub5();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO档位B5");
					break;
				}
			case MC_B6:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenub6();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO档位B6");
					break;
				}
			case MC_B7:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenub7();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO档位B7");
					break;
				}
			case MC_EB:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenueb();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO档位EB");
					break;
				}
			case MC_EB1:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenueb();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO档位EB");
					break;
				}
			default :
				{
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO档位ERR");
					break;
				}
		}

	}


	//警惕
	if (JudgeBit(m_byteFrame[DATASTART+4],1))
	{
		m_promptinfoParser.SetCString(SHOWLINE1,"警惕!");
	} 
	else
	{
		m_promptinfoParser.SetCString(SHOWLINE1,"");
	}

	//左门门选
	if (JudgeBit(m_byteFrame[DATASTART+7],3))
	{
		m_promptinfoParser.SetCString(SHOWLINE2,"左门门选");
	} 
	else
	{
		m_promptinfoParser.SetCString(SHOWLINE2,"");
	}
	//左开门
	if (JudgeBit(m_byteFrame[DATASTART+7],6))
	{
		m_promptinfoParser.SetCString(SHOWLINE3,"左开门");
	} 
	else
	{
		m_promptinfoParser.SetCString(SHOWLINE3,"");
	}
	//右门门选
	if (JudgeBit(m_byteFrame[DATASTART+7],5))
	{
		m_promptinfoParser.SetCString(SHOWLINE4,"右门门选");
	} 
	else
	{
		m_promptinfoParser.SetCString(SHOWLINE4,"");
	}
	//右开门
	if (JudgeBit(m_byteFrame[DATASTART+7],7))
	{
		m_promptinfoParser.SetCString(SHOWLINE5,"右开门");
	} 
	else
	{
		m_promptinfoParser.SetCString(SHOWLINE5,"");
	}
}

BOOL CALLTRACKAUTOView::JudgeBit(byte m_bytedata, byte m_bit)
{
	return	(m_bytedata>>m_bit) & 0x01;
}

BYTE CALLTRACKAUTOView::RightMove(byte m_bytedata, byte m_bytepos, byte m_bytemn)
{
	BYTE m_byte=0xFF;
	BYTE m_byteclear=0xFF;
	m_byte=m_byte>>(8-(m_bytepos-m_bytemn));
	m_byte=m_byte&m_bytedata;
	m_bytedata=m_bytedata>>m_bytemn;
	m_byteclear=m_byteclear<<(m_bytepos-m_bytemn);
	m_bytedata=m_bytedata&m_byteclear;
	m_byte=m_byte|m_bytedata;
	return m_byte;
}

void CALLTRACKAUTOView::InitOtherAfter5Second()
{
	KillTimer(2);
	CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
	m_frame->OnMenuwheel791();
}
