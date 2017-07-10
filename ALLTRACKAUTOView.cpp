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
CALLTRACKAUTOSet m_alltrack[TRACKNUMBER];	//ȫ�߹��
CALLTRACKAUTOSet m_uptrack[TRACKUP];	//���й��
CALLTRACKAUTOSet m_downtrack[TRACKDOWN];	//���й��
Station m_station[20];
SpeedLine	m_speedheadline;
SpeedLine	m_speedtailline;
BOOL	m_bLoadAllTrackFinish;
CSpeedTable m_speedtable;
int		m_nTrackView;	//�����ͼ
int		m_nTrainView;	//�г���ͼ
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
POINT m_pTrainpos;				//�����ڹ��λ��
POINT m_pTrainShowpos;			//������ʾλ��
CRUNNINGMSG * m_dlgmsg;
CSHOWMSG	m_showmsg;			//����������ʾ
CSHOWMSG	m_showautomsg;		//�Զ�����
CSHOWMSG	m_showstatusmsg;	//״̬
CSHOWMSG	m_showhdmsg;		//ͷβ��
CSHOWMSG	m_showtcode;		//�����
CSHOWMSG	m_shownpapr;		//��Դ�ű�
CSHOWMSG	m_showpapr;			//��Դ�ű�
CSHOWMSG	m_showrunning;		//������Ϣ
MACRO	m_macro;
CTRACKCODE	m_trackcode;
CRect		m_rcClient;					//�ͻ���
double		m_dgmail;			//ȫ����ʻ���
double		m_dgaddmail;		//ȫ����ʻ�������
BOOL		m_bDirectorup;
int			m_ngTrainpos;		//ȫ�ֳ�����ʾλ��
int			m_ngTrainhigh;		//ȫ�ֳ����߶�
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
BOOL		m_bprioritygrow;			//�۹����ȼ�
CTrain		m_Train;
BOOL		m_bAutoBreak;
BOOL		m_bShowTrain;
int			m_nTrackPriority[2][3];		//�����·���ȼ�
int			m_nNormalTrackPriority;		//ֱ�����ȼ�
int			m_nFoldTrackPriority;		//�۹����ȼ�
BOOL		m_bgoahead;					//�г�����
BOOL		m_bhead1;					//1�ų��Ƿ�Ϊͷ��
BOOL		m_bDefaultLowEndHigh;		//Ĭ���߸߶ȵ͹��
int			m_nTrackEndPos;				//���������
int			m_nGapOffSet;				//���϶ƫ����
BOOL		m_bAutoStop;
ANTENNA		m_antenna;
READER		m_reader;
BOOL		m_bSendAPR;
//���±������ڼ��㳵��λ��
double		m_dgTrainTrunPos;			//������ͷβλ��
double		m_dgTrainRealPos;			//ȫ�ֳ���ʵ��λ��
double		m_dgTrainAddPos;			//���������
double		m_dgTrainReverseDis;
float		m_fgTrainOffSet;
BOOL		m_bgFirstReverse;
BOOL		m_bgTrackEndPosCalculate;	//����������Ƿ��Ѿ����й�����
BOOL		m_bgSendCurrentTrackCode;
float		m_fgantennaforshow;
float		m_fgreaderforshow;
BOOL		m_bAutoStopPoint;
double		m_dAutoStopPoint;
float		m_fgtrainclasp;
//���η���
int			m_gnAntennaNumber;
int			m_gnSecondCodepos;
int			m_gnSecondcode;

//������ҷ���
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

//������ر���
#include "Includes.h"
#include "COMPORT.h"

BOOL	m_bWorking;
BOOL	m_bHighSpeed;
extern BOOL	m_bThreadRXrunning;
extern BOOL	m_bThreadTXrunning;
extern HANDLE hCom2; //����
extern  BYTE	m_byteRXbuffer[BUFFERLENTH];
BYTE	m_byteFrame[24];
extern BYTE	m_byteWriteFrame1[24];
extern BYTE	m_byteWriteFrame2[24];
extern BYTE	m_byteWriteFrame3[24];
extern BYTE	m_byteWriteFrame4[24];
BOOL	m_bConnectCom;	//�����Ƿ�����
extern BOOL	m_bSendPackage;
#define MAXQSIZE BUFFERLENTH

/*����ѭ������ʵ��ѭ������*/

typedef BYTE QElemType ; //������������ 

typedef struct
{
	QElemType *base;  //ѭ�����еĴ洢�ռ� �� ������ָ��ָʾ�洢ʵ�ʳ���10�ֽڵ��ַ���) 
	int front;  //��ͷԪ���±꣨ȡԪ�أ� 
	int rear;  //��βԪ���±꣨����Ԫ�أ� 
}SqQueue;            

//����ѭ�����У�ѭ����������
int InitQueue(SqQueue &Q)
{
    Q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
    if(!Q.base) 
		return -1;  //����ʧ�ܣ�����-1 
    Q.front=0;
    Q.rear=0;
    return 0;    //�����ɹ�������0 
}    

//����Ԫ�أ�����У�
int EnQueue(SqQueue &Q,QElemType e)
{
    if((Q.rear+1)%MAXQSIZE==Q.front)	//��һ���Ƿ�Ͷ�ȡָ���ػ�
		return -1;  //����
    //memcpy(Q.base[Q.rear],e);  //��ֵ
	Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;  //�±��һ 
    return 0;  //��ӳɹ�
}

//ȡԪ��(����ָ�룬ָ��ȡ����ֵ�� 
int DeQueue(SqQueue &Q,QElemType &e)
{
    if(Q.rear==Q.front)
        return -1;   //�ӿ�
    //memcpy(e,Q.base[Q.front]);
	e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE; //�±��һ 
    return 0;  //�ɹ�
}  

int QueueLenth(SqQueue Q)
{
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

SqQueue q;  //���ݽṹ ���λ���������
int flag; 
QElemType strIn,strOut;


//���ڱ�������





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
	m_bViewOn=TRUE;	//�ӽǸ����г�
	//������ʾλ��
	m_showautomsg.SetPos(SHOWMSGPOS,0);		//�Զ�����
	m_showstatusmsg.SetPos(SHOWMSGPOS+SHOWMSGGAP,0);	//״̬
	m_showhdmsg.SetPos(SHOWMSGPOS+SHOWMSGGAP*2,0);		//ͷβ��
	m_showhdmsg.SetStyle(4);
	m_showtcode.SetPos(SHOWMSGPOS+SHOWMSGGAP*3,0);		//�����
	m_shownpapr.SetPos(SHOWMSGPOS+SHOWMSGGAP*4,0);		//��Դ�ű�
	m_showrunning.SetPos(SHOWMSGPOS+SHOWMSGGAP*5,0);		//������Ϣ
	m_showpapr.SetPos(SHOWMSGPOS+SHOWMSGGAP*7,0);			//��Դ�ű�
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
	//��ʼ��
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
	//�����Ϣ�����߳�
	pThread=AfxBeginThread(ThreadLoadingTrack,(LPVOID)GetSafeHwnd());
	//���ҹ�����߳�
	pThreadSeek=AfxBeginThread(ThreadSeekTrackData,(LPVOID)GetSafeHwnd());
	//�����Ƿ���APR�߳�
	pThreadAPR=AfxBeginThread(ThreadISSendAPR,(LPVOID)GetSafeHwnd());
	//��ʼ����λ��
	m_ngTrainpos=0;		//ȫ�ֳ�����ʾλ��
	m_pTrainpos.x=m_ngTrainpos;
	m_ngTrainhigh=494;		//ȫ�ֳ����߶�
	m_pTrainpos.y=m_ngTrainhigh;
	m_nTrackView=0;
	m_nTrainView=0;
//	SetTimer(1,1,NULL);
	CCom	m_com;
	m_dlgmsg = new CRUNNINGMSG();
	m_dlgmsg->Create(IDD_DIALOGMSG);
	m_dgmail=0;
	m_bDirectorup=FALSE;	//Ĭ������
	m_fgantennapos=(float)3.2;
	m_ngtrackpointer=0;
	m_fgaproldadd=0;
	m_fgtrackcode=0;
	m_dgspeed=0;
	m_bAlreadyClear=FALSE;

	m_colorgline=RGB(50,80,180);
	m_colorgfont=RGB(16, 78, 139);
	m_colorgapr=RGB(20,180,80);
	//Ĭ�ϲ�������Ƶ�任����
	m_bCarrayFruChangeTest=FALSE;
	//��Ƶ���Ը�ֵ
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
	//����ԽС���ȼ�Խ��
	m_nNormalTrackPriority=1;		//ֱ�����ȼ�
	m_nFoldTrackPriority=10;		//�۹����ȼ�
	m_bgoahead=TRUE;					//Ĭ��ǰ��
	m_bhead1=TRUE;					//Ĭ��1�ų�Ϊͷ��
	m_bDefaultLowEndHigh=TRUE;		//Ĭ���߹���߶ȵ͵Ĳ���
	m_nTrackEndPos=0;
	m_dgTrainTrunPos=0;			//������ͷβλ��
	m_dgTrainRealPos=0;			//ȫ�ֳ���ʵ��λ��
	m_dgTrainAddPos=0;			//���������
	m_fgTrainOffSet=126;
	m_dgTrainReverseDis=0;
	m_bReverse=FALSE;
	m_bgFirstReverse=TRUE;		//�״η���
	m_bgTrackEndPosCalculate=FALSE;
	m_bgSendCurrentTrackCode=FALSE;	//�Ƿ��͵�ǰ�����
	m_bprioritygrow=TRUE;			//������ȼ�Ĭ�ϲ��ý�����������ʽ
	m_bAutoStop=FALSE;
	m_bAutoStopPoint=FALSE;
	m_bSendAPR=TRUE;
	m_bHardwareReset=TRUE;
	m_gnuplastpointer=TRACKUP;		//�Ӻ���ǰ��
	m_gndownlastpointer=0;			//��ǰ�����

	m_bForbidSendPAPR=FALSE;
	LoadConfig();					//����ȫ�������ļ�
	Init();
	SetTimer(2,2000,NULL);			//5����ʼ����������

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
					//�Ķ������복����ǰ��18.574��
					//1�ų�Ϊͷ��
					if (m_bhead1==TRUE)
					{
						//��ǰ
						if (m_bgoahead==TRUE)
						{
							//�Ķ���λ�ü���
							m_reader.SetReaderNumber(1);
							m_fantenna=m_reader.GetReaderPos();
							m_fgreaderforshow=m_fantenna;
							CString m_str;
							m_str.Format("%f",m_fantenna-DISTANCE);
							m_str.Insert(0,"1���Ķ���λ��:");
							m_promptinfoMailandV.SetCString(9,m_str);
						} 
						//���
						else
						{
							m_reader.SetReaderNumber(2);
							m_fantenna=m_reader.GetReaderPos();
							m_fgreaderforshow=m_fantenna;
							CString m_str;
							m_str.Format("%f",m_fantenna+DISTANCE);
							m_str.Insert(0,"2���Ķ���λ��:");
							m_promptinfoMailandV.SetCString(9,m_str);
						}
					} 
					else
					{
						//��ǰ
						if (m_bgoahead==TRUE)
						{
							//�Ķ���λ�ü���
							m_reader.SetReaderNumber(4);
							m_fantenna=m_reader.GetReaderPos();
							m_fgreaderforshow=m_fantenna;
							CString m_str;
							m_str.Format("%f",m_fantenna+DISTANCE);
							m_str.Insert(0,"4���Ķ���λ��:");
							m_promptinfoMailandV.SetCString(9,m_str);
						} 
						//���
						else
						{
							//�Ķ���λ�ü���
							m_reader.SetReaderNumber(3);
							m_fantenna=m_reader.GetReaderPos();
							m_fgreaderforshow=m_fantenna;
							CString m_str;
							m_str.Format("%f",m_fantenna-DISTANCE);
							m_str.Insert(0,"3���Ķ���λ��:");
							m_promptinfoMailandV.SetCString(9,m_str);
						}
					}
					//������
					if (m_bDirectorup)
					{

						//�ı䷢��APR��ʽ
						int	m_ndowntrackendhigh;
						for (int up= m_gnuplastpointer;up>0;up--)
						{
							//APR����������APR���ڹ���ͳ�����ͬһ�߶��ϣ�APRδ���͹����Ķ�����APR��ⷶΧ��
							m_ndowntrackendhigh=m_uptrack[up].m_TRACKENDHIGH;
							//�Ķ����ڸù���ϣ����������߶Ⱥͳ����߶����
							//Ѱ����ԴAPR
							if ((m_ndowntrackendhigh==(m_ngTrainhigh+TRAINTOTRACK))&&(m_uptrack[up].m_btNPAPRsend==FALSE)&&(m_uptrack[up].m_ISFOLD==m_boolisfold))	//�뵱ǰ��������Ϊ�ó��ڵ�ǰ����
							{

								m_ftrackstartpos=(float)(m_uptrack[up].m_Tstartpos);
								m_fnpapr=(float)(m_uptrack[up].m_NPAPRpos);
								m_fnpapr=m_ftrackstartpos-m_fnpapr;
								m_fnpapr=m_fnpapr/100;
								if ((m_fantenna>=m_fnpapr)&&(m_fantenna<=m_fnpapr+1))
								{				
									//��Դ	���ָ��
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
							//���ҵڶ�����ԴAPR
							if ((m_ndowntrackendhigh==(m_ngTrainhigh+TRAINTOTRACK))&&(m_uptrack[up].m_btNPAPR2send==FALSE))	//�뵱ǰ��������Ϊ�ó��ڵ�ǰ����
							{
								m_ftrackstartpos=(float)(m_uptrack[up].m_Tstartpos);
								m_fnpapr=(float)(m_uptrack[up].m_NPAPR2pos);
								if (m_fnpapr!=0)
								{
									m_fnpapr=m_ftrackstartpos-m_fnpapr;
									m_fnpapr=m_fnpapr/100;
									if ((m_fantenna>=m_fnpapr)&&(m_fantenna<=m_fnpapr+1))
									{				
										//��Դ	���ָ��
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

							//Ѱ����ԴARP
							if (m_bForbidSendPAPR==FALSE)
							{
								if ((m_ndowntrackendhigh==(m_ngTrainhigh+TRAINTOTRACK))&&(m_uptrack[up].m_btNPAPRsend==FALSE)&&(m_uptrack[up].m_Psignalpos!=0))	//�뵱ǰ��������Ϊ�ó��ڵ�ǰ����
								{
									m_ftrackstartpos=(float)(m_uptrack[up].m_Tstartpos);
									m_fnpapr=(float)(m_uptrack[up].m_Psignalpos);
									m_fnpapr=m_ftrackstartpos-m_fnpapr;
									m_fnpapr=m_fnpapr/100;
									if ((m_fantenna>=m_fnpapr)&&(m_fantenna<=m_fnpapr+1))
									{				
										//��Դ	���ָ��
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

						//�ı䷢��APR��ʽ
						int	m_ndowntrackendhigh;
						for (int down=0;down<TRACKDOWN;down++)
						{
							//APR����������APR���ڹ���ͳ�����ͬһ�߶��ϣ�APRδ���͹����Ķ�����APR��ⷶΧ��

							m_ndowntrackendhigh=m_downtrack[down].m_TRACKENDHIGH;
							//�Ķ����ڸù���ϣ����������߶Ⱥͳ����߶����
							//Ѱ����ԴAPR
							if ((m_ndowntrackendhigh==(m_ngTrainhigh+TRAINTOTRACK))&&(m_downtrack[down].m_btNPAPRsend==FALSE))	//�뵱ǰ��������Ϊ�ó��ڵ�ǰ����
							{
								m_ftrackstartpos=(float)(m_downtrack[down].m_Tstartpos);
								m_fnpapr=(float)(m_downtrack[down].m_NPAPRpos);
								m_fnpapr+=m_ftrackstartpos;
								m_fnpapr=m_fnpapr/100;
								if ((m_fantenna>=m_fnpapr)&&(m_fantenna<=m_fnpapr+1))
								{				
									//��Դ	���ָ��
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
							//���ҵڶ�����ԴAPR
							if ((m_ndowntrackendhigh==(m_ngTrainhigh+TRAINTOTRACK))&&(m_downtrack[down].m_btNPAPR2send==FALSE))	//�뵱ǰ��������Ϊ�ó��ڵ�ǰ����
							{
								m_ftrackstartpos=(float)(m_downtrack[down].m_Tstartpos);
								m_fnpapr=(float)(m_downtrack[down].m_NPAPR2pos);
								if (m_fnpapr!=0)
								{
									m_fnpapr+=m_ftrackstartpos;
									m_fnpapr=m_fnpapr/100;
									if ((m_fantenna>=m_fnpapr)&&(m_fantenna<=m_fnpapr+1))
									{				
										//��Դ	���ָ��
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

							//Ѱ����ԴAPR
							if (m_bForbidSendPAPR==FALSE)
							{
								if ((m_ndowntrackendhigh==(m_ngTrainhigh+TRAINTOTRACK))&&(m_downtrack[down].m_btPAPRsend==FALSE)&&(m_downtrack[down].m_Psignalpos!=0))	//�뵱ǰ��������Ϊ�ó��ڵ�ǰ����
								{
									m_ftrackstartpos=(float)(m_downtrack[down].m_Tstartpos);
									m_fnpapr=(float)(m_downtrack[down].m_Psignalpos);
									m_fnpapr+=m_ftrackstartpos;
									m_fnpapr=m_fnpapr/100;
									if ((m_fantenna>=m_fnpapr)&&(m_fantenna<=m_fnpapr+1))
									{				
										//��Դ	���ָ��
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
							//��Դ����APR
							
							if ((m_ndowntrackendhigh==(m_ngTrainhigh+TRAINTOTRACK)))	//�뵱ǰ��������Ϊ�ó��ڵ�ǰ����
							{
								if ((m_downtrack[down].m_LNPAPR1pos)&&(m_downtrack[down].m_LNPAPR1number))
								{
									m_ftrackstartpos=(float)(m_downtrack[down].m_Tstartpos);
									m_fnpapr=(float)(m_downtrack[down].m_LNPAPR1pos);
									m_fnpapr+=m_ftrackstartpos;
									m_fnpapr=m_fnpapr/100;
									if ((m_fantenna>=m_fnpapr)&&(m_fantenna<=m_fnpapr+2))
									{				
										//��Դ	���ָ��
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
				//ÿ�μ�������λ�ã�������������
				//����λ��=��λ��+������/2 - ���߰�װλ�� +�г�����
				//�ж�����λ���Ƿ񵽴�����ʼ��+-2��λ��
				if (m_bLoadAllTrackFinish==TRUE)
				{
					float	m_fantenna=0;
					float	m_ftrackstartpos=0;
					int		m_ntrainhigh=0;
					int		m_ntrackhigh=0;
					//���㳵���߶�
					m_ntrainhigh=m_ngTrainhigh+TRAINTOTRACK;	//�뵱ǰ��������Ϊ�ó��ڵ�ǰ����
					if (m_bhead1==TRUE)
					{
						//1�ų�Ϊͷ��
						if (m_bgoahead==TRUE)
						{
							//�г�����ǰ��
							m_bDirectorup=FALSE;
							m_antenna.SetAntennaNumber(1);
							m_gnAntennaNumber=1;
							m_fantenna=m_antenna.GetAntennaPos();
							m_fgantennaforshow=m_fantenna;
							//δ���͵�ǰ�����
							if (m_bgSendCurrentTrackCode==FALSE)
							{
								::PostMessage((HWND)lpParam, WM_SENDCURRENTTRACKCODE, 1, (int)m_fantenna*100);
								m_bgSendCurrentTrackCode=TRUE;
							}
							CString m_str;
							m_str.Format("%f",m_fantenna-DISTANCE);
							m_str.Insert(0,"1������λ��:");
							m_promptinfoMailandV.SetCString(8,m_str);

							//��Ϊ����
							m_ftrackstartpos=(float)m_downtrack[m_ngtrackpointer].m_Tstartpos;
							m_ftrackstartpos=m_ftrackstartpos/100;
							
							m_fgtrainclasp=m_fantenna-DISTANCE+(float)ANTENNATOCUSP;
							m_str.Format("%f",m_fgtrainclasp);
							m_str.Insert(0,"1�ų���λ��:");
							m_promptinfoMailandV.SetCString(3,m_str);
							//λ���ٶ�
							m_str.Format("%f",m_fgtrainclasp);
							m_str.Insert(0,"����λ��:");
							m_promptinfoMailandV.SetCString(1,m_str);
							
							m_str.Format("%f",m_dgspeed);
							m_str.Insert(0,"�����ٶ�:");
							m_promptinfoMailandV.SetCString(0,m_str);
						} 
						else
						{
							//�г����򣬺���
							m_bDirectorup=TRUE;
							m_antenna.SetAntennaNumber(2);
							m_gnAntennaNumber=2;
							m_fantenna=m_antenna.GetAntennaPos();
							m_fgantennaforshow=m_fantenna;
							//δ���͵�ǰ�����
							if (m_bgSendCurrentTrackCode==FALSE)
							{
								::PostMessage((HWND)lpParam, WM_SENDCURRENTTRACKCODE, 2, (int)m_fantenna*100);
								m_bgSendCurrentTrackCode=TRUE;
							}
							CString m_str;
							m_str.Format("%f",m_fantenna+DISTANCE);
							m_str.Insert(0,"2������λ��:");
							m_promptinfoMailandV.SetCString(8,m_str);

							//λ���ٶ�
							m_fgtrainclasp=m_fantenna+DISTANCE+(float)ANTENNATOCUSP;
							m_str.Format("%f",m_fgtrainclasp);
							m_str.Insert(0,"1�ų���λ��:");
							m_promptinfoMailandV.SetCString(3,m_str);

							m_str.Format("%f",m_fgtrainclasp);
							m_str.Insert(0,"����λ��:");
							m_promptinfoMailandV.SetCString(1,m_str);
							
							m_str.Format("%f",m_dgspeed);
							m_str.Insert(0,"�����ٶ�:");
							m_promptinfoMailandV.SetCString(0,m_str);

						}
					} 
					else
					{
						//1�ų�Ϊβ��
						if (m_bgoahead==TRUE)
						{
							//�г�����ǰ��
							m_bDirectorup=TRUE;
							m_antenna.SetAntennaNumber(4);
							m_gnAntennaNumber=4;
							m_fantenna=m_antenna.GetAntennaPos();
							m_fgantennaforshow=m_fantenna;
							//δ���͵�ǰ�����
							if (m_bgSendCurrentTrackCode==FALSE)
							{
								::PostMessage((HWND)lpParam, WM_SENDCURRENTTRACKCODE, 4, (int)m_fantenna*100);
								m_bgSendCurrentTrackCode=TRUE;
							}
							CString m_str;
							m_str.Format("%f",m_fantenna+DISTANCE);
							m_str.Insert(0,"4������λ��:");
							m_promptinfoMailandV.SetCString(8,m_str);
							//��Ϊ����
							m_fgtrainclasp=m_fantenna+DISTANCE-(float)ANTENNATOCUSP;
							m_str.Format("%f",m_fgtrainclasp);
							m_str.Insert(0,"6�ų���λ��:");
							m_promptinfoMailandV.SetCString(3,m_str);

							//λ���ٶ�
							m_str.Format("%f",m_fgtrainclasp);
							m_str.Insert(0,"����λ��:");
							m_promptinfoMailandV.SetCString(1,m_str);
							
						} 
						else
						{
							//�г����򣬺���
							m_bDirectorup=FALSE;
							m_antenna.SetAntennaNumber(3);
							m_gnAntennaNumber=3;
							m_fantenna=m_antenna.GetAntennaPos();
							m_fgantennaforshow=m_fantenna;
							//δ���͵�ǰ�����
							if (m_bgSendCurrentTrackCode==FALSE)
							{
								::PostMessage((HWND)lpParam, WM_SENDCURRENTTRACKCODE, 3, (int)m_fantenna*100);
								m_bgSendCurrentTrackCode=TRUE;
							}
							CString m_str;
							m_str.Format("%f",m_fantenna-DISTANCE);
							m_str.Insert(0,"3������λ��:");
							m_promptinfoMailandV.SetCString(8,m_str);


						}
					}
					//��������
					if (m_bDirectorup)
					{
						//���������ʼ��
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
							//�ù�����ѷ��ͣ����ٷ���
							if (!m_uptrack[up].m_btcodesend)
							{
								m_ntrackhigh=(m_uptrack[up].m_TRACKSTARTHIGH);
								//���ڴ˹�, ����Ϊ����복���߶���ͬ���߹���߶Ȳ�������Χ�ڣ�������һ�����ʼ�������ڵ��ڵ�ǰ���������
								int	m_nHighDis=0;	//����߶��ݲ�
								m_nHighDis=abs(m_ntrackhigh-m_ntrainhigh);
								if (m_nHighDis<=TRACKHIGHDIS)		
								{
									//�����ʼ�����
									m_ftrackstartpos=(float)m_uptrack[up].m_Tstartpos;
									m_ftrackstartpos=m_ftrackstartpos/100;
									//���������δ���й�����
									if (m_bgTrackEndPosCalculate==FALSE)
									{
										if ((m_fantenna>=m_ftrackstartpos-1)&&(m_fantenna<=m_ftrackstartpos+1))
										{
											//�ж��Ƿ����۹죬�����������ȼ�
											//����ԽС���ȼ�Խ��
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
											m_nTrackPriority[1][m_nEnterNumber]=up;		//�����·���ȼ�
											m_nEnterNumber++;
										}
									}
									else
									{																				//��һ���������������һ�����ʼ�����
										if ((m_fantenna>=m_ftrackstartpos-1)&&(m_fantenna<=m_ftrackstartpos+1)&&(m_nTrackEndPos==m_uptrack[up].m_Tstartpos))
										{
											//�ж��Ƿ����۹죬�����������ȼ�
											//����ԽС���ȼ�Խ��
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
											m_nTrackPriority[1][m_nEnterNumber]=up;		//�����·���ȼ�
											m_nEnterNumber++;
										}
									}
								}
							}
						}

						//�������
						switch (m_nEnterNumber)
						{
						case 0:
							{
								//δ�ҵ����
								break;
							}
						case 1:
							{
								//ֻ�ҵ�һ����·
								::PostMessage((HWND)lpParam, WM_NEXTTRACK, 1, m_nTrackPriority[1][0]);
								m_boolisfold=m_uptrack[m_nTrackPriority[1][0]].m_ISFOLD;
								break;
							}
						case 2:
							{
								//�ҵ�������·����ѡ��Ĺ�����ݷ��ͺ󣬽�����һ�����������ϢҲͬʱ��λ����������һ�μ���н�����û���͵Ĺ�����ݷ���
								//���ж���������Ƿ����۹죬��������۹�,���ݹ��������߶��ж���������������˹����Ʒ���
								if (m_nTrackPriority[0][0]==m_nTrackPriority[0][1])
								{
									//Ĭ���߹�������߶ȵ͵Ĺ��
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
									//������ȼ��Զ��ظ���������ȫ���߲���
									m_nNormalTrackPriority=1;
									m_nFoldTrackPriority=10;

								}
								else if (m_nTrackPriority[0][0]<m_nTrackPriority[0][1])
								{
									::PostMessage((HWND)lpParam, WM_NEXTTRACK, 1, m_nTrackPriority[1][0]);
									m_uptrack[m_nTrackPriority[1][1]].m_btcodesend=TRUE;
									//�����������������
									if (m_uptrack[m_nTrackPriority[1][0]].m_ISFOLD==TRUE)
									{
										//������ȼ��Զ��ظ���������ȫ���߲���
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
										//������ȼ��Զ��ظ���������ȫ���߲���
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
								//�ҵ�������·
								//�ȱȽϵ�һ���͵ڶ���
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
					//��������
					else
					{
						//���������ʼ��
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
							//�ù�����ѷ��ͣ����ٷ���
							if (!m_downtrack[down].m_btcodesend)
							{
								m_ntrackhigh=(m_downtrack[down].m_TRACKSTARTHIGH);
								//���ڴ˹�, ����Ϊ����복���߶���ͬ���߹���߶Ȳ�������Χ�ڣ�������һ�����ʼ�������ڵ��ڵ�ǰ���������
								int	m_nHighDis=0;	//����߶Ȳ�
								m_nHighDis=abs(m_ntrackhigh-m_ntrainhigh);
								if (m_nHighDis<=TRACKHIGHDIS)		
								{
									//�����ʼ�����
									m_ftrackstartpos=(float)m_downtrack[down].m_Tstartpos;
									m_ftrackstartpos=m_ftrackstartpos/100;
									//���������δ���й�����
									if (m_bgTrackEndPosCalculate==FALSE)
									{
										if ((m_fantenna>=m_ftrackstartpos-1)&&(m_fantenna<=m_ftrackstartpos+1))
										{
											//�ҵ�һ����������Ѱ�ң�ֱ��������ȫ�����ݣ���Ϊ��ͬһ�����ж�����·���������ȼ��ж�ʻ���������
											
											//�ж��Ƿ����۹죬�����������ȼ�
											//����ԽС���ȼ�Խ��
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

											m_nTrackPriority[1][m_nEnterNumber]=down;		//�����·���ȼ�
											m_nEnterNumber++;
										}
									} 
									else
									{
										if ((m_fantenna>=m_ftrackstartpos-1)&&(m_fantenna<=m_ftrackstartpos+1)&&(m_nTrackEndPos==m_downtrack[down].m_Tstartpos))
										{
											//�ҵ�һ����������Ѱ�ң�ֱ��������ȫ�����ݣ���Ϊ��ͬһ�����ж�����·���������ȼ��ж�ʻ���������
											
											//�ж��Ƿ����۹죬�����������ȼ�
											//����ԽС���ȼ�Խ��
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
											m_nTrackPriority[1][m_nEnterNumber]=down;		//�����·���ȼ�
											m_nEnterNumber++;
										}
									}

								}
							}
						}

						//�������,�������ȼ��ж�ʻ��������·
						switch (m_nEnterNumber)
						{
						case 0:
							{
								//δ�ҵ����
								break;
							}
						case 1:
							{
								//ֻ�ҵ�һ����·
								::PostMessage((HWND)lpParam, WM_NEXTTRACK, 2, m_nTrackPriority[1][0]);
								break;
							}
						case 2:
							{
								//�ҵ�������·
								if (m_nTrackPriority[0][0]==m_nTrackPriority[0][1])
								{
									//Ĭ���߹�������߶ȵ͵Ĺ��
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
									//������ȼ��Զ��ظ���������ȫ���߲���
									m_nNormalTrackPriority=1;
									m_nFoldTrackPriority=10;
								}
								else if (m_nTrackPriority[0][0]<m_nTrackPriority[0][1])
								{
									::PostMessage((HWND)lpParam, WM_NEXTTRACK, 2, m_nTrackPriority[1][0]);
									m_downtrack[m_nTrackPriority[1][1]].m_btcodesend=TRUE;
									if (m_downtrack[m_nTrackPriority[1][0]].m_ISFOLD==TRUE)
									{
										//������ȼ��Զ��ظ���������ȫ���߲���
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
										//������ȼ��Զ��ظ���������ȫ���߲���
										m_nNormalTrackPriority=1;
										m_nFoldTrackPriority=10;
									}
								}
								break;
							}
						case 3:
							{
								//�ҵ�������·
								//�ȱȽϵ�һ���͵ڶ���
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
	//Ĭ���������ӷ�ʽΪ���շ�ʽ��Ӧ����Ϊm_nDefaultType = AFX_DB_USE_DEFAULT_TYPE;
	int m_npointer=0;
	CDatabase m_threaddb;

	/*��Ϣ����:
		LPARAM ����Ϊ	0��Ϊ������������Ϣ
						1, ��ʾ��Ϣ
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
		catch (CMemoryException* pEx)	//�����ڴ��쳣
		{
			pEx->ReportError();
		}
		catch (CFileException* pDBEx)//�����ļ��쳣
		{
			pDBEx->ReportError();
		}
		catch (CException* e)//���������쳣
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
	catch (CMemoryException* pEx)	//�����ڴ��쳣
	{
		pEx->ReportError();
	}
	catch (CFileException* pDBEx)//�����ļ��쳣
	{
		pDBEx->ReportError();
	}
	catch (CException* e)//���������쳣
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
	catch (CException* e)//���������쳣
	{
		e->ReportError();
	}
	m_dbset->Close();
	//����վ��Ϣ
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
	catch (CMemoryException* pEx)	//�����ڴ��쳣
	{
		pEx->ReportError();
	}
	catch (CFileException* pDBEx)//�����ļ��쳣
	{
		pDBEx->ReportError();
	}
	catch (CException* e)//���������쳣
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
	catch (CException* e)//���������쳣
	{
		e->ReportError();
	}
	m_dbsetstation->Close();
	m_threaddb.Close();

	//�ֿ�����������
	int	m_nuppointer=0;
	int	m_ndownpointer=0;

	for (int i=0;i<TRACKNUMBER;i++)
	{
		if (m_alltrack[i].m_UpDown=="����")
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
	//��Դ����MARK28 ��Դ����OPEN32 ��Դopenlen

	switch (m_byte)
	{
	case 0:
		{
			//��Դ���� mark28 ����
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
			m_strrunning.Insert(0,"APR����:");
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
			
			//���·���APR�������־��Ч
			m_bAlreadyClear=FALSE;
			break;
		}
	case 1:
		{
			//��Դ���� mark28 ����
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
			m_strrunning.Insert(0,"APR����:");
			m_showrunning.AddMsg(m_strrunning);

			//ȥ��ID���еı�־
			wParam=wParam&0x0FFFFFFF;

			m_strrunning.Format("0X%08X",wParam);
			m_strrunning.Insert(0,"APRid:");
			m_showrunning.AddMsg(m_strrunning);
			
			//open28 �����㷨
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
			
			//���·���APR�������־��Ч
			m_bAlreadyClear=FALSE;
			break;
		}
	//��ԴAPR
	case 2:
		{
			//���� 80֡ 
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
			m_strrunning.Insert(0,"APR����:");
			m_showrunning.AddMsg(m_strrunning);
			//ȥ��ID���еı�־
			wParam=wParam&0x0FFFFFFF;
			m_strrunning.Format("0X%08X",wParam);
			m_strrunning.Insert(0,"APRid:");
			m_showrunning.AddMsg(m_strrunning);
			//id = ((data[1] & 0x3f) << 22) | (data[2] << 14) | (data[3] << 6) | ((data[4] & 0xfc) >> 2)��
			//ID����OPEN32 ��ʽ�������£�id = (data[0] << 24) | ((data[1] & 0xC0) << 16) | (data[2] << 14) | (data[3] << 6) | ((data[4] & 0xfc) >> 2)��
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
			
			//���·���APR�������־��Ч
			m_bAlreadyClear=FALSE;
			*/


			//��Դopenlen ���� 70֡ 
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
			m_strrunning.Insert(0,"APR����:");
			m_showrunning.AddMsg(m_strrunning);
			//ȥ��ID���еı�־
			wParam=wParam&0x0FFFFFFF;
			m_strrunning.Format("0X%08X",wParam);
			m_strrunning.Insert(0,"APRid:");
			m_showrunning.AddMsg(m_strrunning);
			//id = ((data[1] & 0x3f) << 22) | (data[2] << 14) | (data[3] << 6) | ((data[4] & 0xfc) >> 2)��
			//ID����OPEN32 ��ʽ�������£�id = (data[0] << 24) | ((data[1] & 0xC0) << 16) | (data[2] << 14) | (data[3] << 6) | ((data[4] & 0xfc) >> 2)��
			switch (wParam)
			{
			case 0x055ED16F:
				{
					//DATA����
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
					//DATA����
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
					//DATA����
					m_byteWritePAPR10[0x0E]=m_papr[2].m_bytedata[0];
					m_byteWritePAPR10[0x0F]=m_papr[2].m_bytedata[1];
					m_byteWritePAPR10[0x10]=m_papr[2].m_bytedata[2];
					m_byteWritePAPR10[0x11]=m_papr[2].m_bytedata[3];
					m_byteWritePAPR10[0x12]=m_papr[2].m_bytedata[4];
					m_byteWritePAPR10[0x13]=m_papr[2].m_bytedata[5];
					break;
				}
			}
			
			//open28 �����㷨
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
			//Open32 �����㷨
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
			//���·���APR�������־��Ч
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
			m_strrunning.Insert(0,"APR����:");
			m_showrunning.AddMsg(m_strrunning);
			
			//ȥ��ID���еı�־
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

			//���·���APR�������־��Ч
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
			
			if (m_bDirectorup)	//����
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
			m_strrunning.Insert(0,"APR����:");
			m_showrunning.AddMsg(m_strrunning);
			
			m_strrunning.Format("0X%08X",wParam);
			m_strrunning.Insert(0,"APRid:");
			m_showrunning.AddMsg(m_strrunning);
			
			//ȥ��ID���еı�־open 28
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
			

			//���·���APR�������־��Ч
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
			m_strrunning.Insert(0,"APR����:");
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
			
			//���·���APR�������־��Ч
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
		//���з��͹����
	case 1:
		{
			CString m_str;
			BYTE	m_byte;
			int		m_ncodepos=0;
			float	m_fchangecodepos;
			//��Ƶ
			//�ж��Ƿ�����Ƶ�任����
			if (m_bCarrayFruChangeTest==TRUE)
			{
				CString m_strtest;
				if (m_bytepCFCT<40)
				{
					m_byteWriteTrackCode[0x06]=m_byteaCFCT[m_bytepCFCT];
					
					m_strtest.Format("��ǰ���Ե�:%d����Ƶ",m_bytepCFCT+1);
					m_promptinfoshow.SetCString(7,m_strtest);
					m_strtest.Format("��Ƶ��Ϊ:F%d",m_byteaCFCT[m_bytepCFCT]);
					m_promptinfoshow.SetCString(8,m_strtest);
					m_bytepCFCT++;
				}
				else
				{
					//��Ƶ�任���Խ���
					m_bCarrayFruChangeTest=FALSE;
					m_strtest="��Ƶ�任���Խ���";
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
			//��Ƶ
			m_byte=m_uptrack[lParam].m_SENDCODE;
			if (m_byte==0)
			{
				return 0;
			}
			m_byteWriteTrackCode[0x07]=m_byte;
			//����ͷβ����ǰ������������λ��

			m_fchangecodepos=(float)(m_dgmail+DISTANCE);	
			m_str.Format("%0.2f",m_dgmail);
			m_str.Insert(0,"���:");
			m_showrunning.AddMsg(m_str);
			m_fchangecodepos=m_fchangecodepos*1000;
			m_ncodepos=(int)m_fchangecodepos;
			m_str.Format("%0.2f",m_fchangecodepos/1000);
			m_str.Insert(0,"�����:");
			m_showrunning.AddMsg(m_str);
			m_byteWriteTrackCode[0x09]=m_ncodepos;
			m_ncodepos=m_ncodepos>>8;
			m_byteWriteTrackCode[0x0a]=m_ncodepos;
			m_ncodepos=m_ncodepos>>8;
			m_byteWriteTrackCode[0x0b]=m_ncodepos;
			m_ncodepos=m_ncodepos>>8;
			m_byteWriteTrackCode[0x0c]=m_ncodepos;
			//����������Ϣ������Ϣ����������������Ϣ
			m_byte=m_byteWriteTrackCode[0x07]<<4;
			m_byte+=m_byteWriteTrackCode[0x06];
			m_byteWriteTrackCode[0x14]=m_byte;
			m_uptrack[lParam].m_btcodesend=TRUE;
			m_bSendCode=TRUE;
			m_ngtrackpointer=lParam;
			//���·��͹���룬�����־��Ч
			m_bAlreadyClear=FALSE;
			//�������߶ȸ���Ϊ����߶�
			m_ngTrainhigh=m_uptrack[lParam].m_TRACKENDHIGH-TRAINTOTRACK;
			m_pTrainpos.y=m_ngTrainhigh;
			//�����������㣬����Ѱ����ù�����ӵĹ��
			m_nTrackEndPos=m_uptrack[lParam].m_Tendpos;
			m_bgTrackEndPosCalculate=TRUE;
			//�����Ϣ��ֵ
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

			//�Զ�����
			
			break;
		}
		//���з��͹����
	case 2:
		{
			CString m_str;
			BYTE	m_byte;
			int		m_ncodepos=0;
			float	m_fchangecodepos;
			//��Ƶ
			//�ж��Ƿ�����Ƶ�任����
			if (m_bCarrayFruChangeTest==TRUE)
			{
				CString m_strtest;
				if (m_bytepCFCT<40)
				{
					m_byteWriteTrackCode[0x06]=m_byteaCFCT[m_bytepCFCT];
					
					m_strtest.Format("��ǰ���Ե�:%d����Ƶ",m_bytepCFCT+1);
					m_promptinfoshow.SetCString(7,m_strtest);
					m_strtest.Format("��Ƶ��Ϊ:F%d",m_byteaCFCT[m_bytepCFCT]);
					m_promptinfoshow.SetCString(8,m_strtest);
					m_bytepCFCT++;
				}
				else
				{
					//��Ƶ�任���Խ���
					m_bCarrayFruChangeTest=FALSE;
					m_strtest="��Ƶ�任���Խ���";
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
			//��Ƶ
			m_byte=m_downtrack[lParam].m_SENDCODE;
			if (m_byte==0)
			{
				return 0;
			}
			m_byteWriteTrackCode[0x07]=m_byte;
			m_fchangecodepos=(float)(m_dgmail+DISTANCE);
			m_str.Format("%0.2f",m_dgmail);
			m_str.Insert(0,"���:");
			m_showrunning.AddMsg(m_str);
			m_fchangecodepos=m_fchangecodepos*1000;
			m_ncodepos=(int)m_fchangecodepos;
			m_str.Format("%0.2f",m_fchangecodepos/1000);
			m_str.Insert(0,"�����:");
			m_showrunning.AddMsg(m_str);
			m_byteWriteTrackCode[0x09]=m_ncodepos;
			m_ncodepos=m_ncodepos>>8;
			m_byteWriteTrackCode[0x0a]=m_ncodepos;
			m_ncodepos=m_ncodepos>>8;
			m_byteWriteTrackCode[0x0b]=m_ncodepos;
			m_ncodepos=m_ncodepos>>8;
			m_byteWriteTrackCode[0x0c]=m_ncodepos;
			//����������Ϣ������Ϣ����������������Ϣ
			m_byte=m_byteWriteTrackCode[0x07]<<4;
			m_byte+=m_byteWriteTrackCode[0x06];
			m_byteWriteTrackCode[0x14]=m_byte;
			m_downtrack[lParam].m_btcodesend=TRUE;
			m_bSendCode=TRUE;
			m_ngtrackpointer=lParam;
			//���·��͹���룬�����־��Ч
			m_bAlreadyClear=FALSE;
			//�������߶ȸ���Ϊ����߶�
			m_ngTrainhigh=m_downtrack[lParam].m_TRACKENDHIGH-TRAINTOTRACK;
			m_pTrainpos.y=m_ngTrainhigh;
			m_Train.SetTrainPos(m_pTrainpos);
			//���������
			m_nTrackEndPos=m_downtrack[lParam].m_Tendpos;
			m_bgTrackEndPosCalculate=TRUE;
			//�����Ϣ��ֵ
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

			//�Զ�����
			if ((m_downtrack[lParam].m_stoppos!=0)&&(m_bAutoStop==TRUE))
			{
				m_promptinfoMailandV.SetCString(2,"�Ѿ���⵽�Զ�ͣ����!");
			//	m_bAutoStopPoint=TRUE;
				m_dAutoStopPoint=(double)(m_downtrack[lParam].m_Tstartpos+m_downtrack[lParam].m_stoppos)+1000;
				CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
				m_frame->Ebtotargetspeed((float) AUTOSTOPBREAK);
			}
			//�жϵ�ǰ����Ƿ��Ͷ��ι����
			if ((m_downtrack[lParam].m_SENDCODE2!=0)&&(m_downtrack[lParam].m_SENDCODE2pos!=0))
			{
				//������η��͹����λ�ú͹����
				m_gnSecondCodepos=m_downtrack[lParam].m_Tstartpos/100+m_downtrack[lParam].m_SENDCODE2pos;
				m_gnSecondcode=m_downtrack[lParam].m_SENDCODE2;
				//���浱ǰ����λ��
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
				//������ݼ������,��ʼ���ƹ��
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
	//˫����
	CDC MemDC; //���ȶ���һ����ʾ�豸���� 
	CBitmap MemBitmap;//����һ��λͼ���� 
	MemDC.CreateCompatibleDC(NULL); //���������Ļ��ʾ���ݵ��ڴ���ʾ�豸 
	MemBitmap.CreateCompatibleBitmap(pDC,m_rcClient.Width(),m_rcClient.Height()); 
	//��λͼѡ�뵽�ڴ���ʾ�豸�� 
	//ֻ��ѡ����λͼ���ڴ���ʾ�豸���еط���ͼ������ָ����λͼ�� 
	CBitmap *pOldBit=MemDC.SelectObject(&MemBitmap); 
	//���ñ���ɫ��λͼ����ɾ����������õ��ǰ�ɫ��Ϊ���� 
	MemDC.FillSolidRect(0,0,m_rcClient.Width(),m_rcClient.Height(),RGB(255,255,255)); 
	MemDC.SelectObject((CPen * )&m_pen);
	MemDC.SelectObject((CBrush * )&m_brush);
	MemDC.SetTextColor(m_colorgfont);	//������ɫ
	if (m_bLoadAllTrackFinish==TRUE)
	{
		//���
		for (int i=0;i<TRACKUP;i++)
		{
			m_uptrack[i].ShowTrack(&MemDC);
		}
		for (int k=0;k<TRACKDOWN;k++)
		{
			m_downtrack[k].ShowTrack(&MemDC);
		}
		//վ
		for (int j=0;j<20;j++)
		{
			m_station[j].ShowStation(&MemDC);
		}
		//ǰ���ٶ�
		m_speedheadline.ShowLine(&MemDC,1);
		//β���ٶ�
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
		m_showstatusmsg.Showmsg(&MemDC);	//״̬
	}
	if (m_bshowreturn1==TRUE)
	{
		m_showhdmsg.Showmsg(&MemDC,TRUE);		//ͷβ��
	}
	if (m_bshowreturn2==TRUE)
	{
		m_showtcode.Showmsg(&MemDC);		//�����
	}
	if (m_bshowreturn3==TRUE)
	{
		m_shownpapr.Showmsg(&MemDC);		//��Դ�ű�
	}
	
	m_showpapr.Showmsg(&MemDC);			//��Դ�ű�	//δʵ��

	if (m_bshowcalculate==TRUE)
	{
		m_showrunning.Showmsg(&MemDC);		//������Ϣ
	}
	
	m_promptinfonexttrack.SetPos(SHOWMSGBASEPOS+200,0);
	m_promptinfonexttrack.ShowPromp(&MemDC);	//��ʾ��Ϣ
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
	//���ڴ��е�ͼ��������Ļ�Ͻ�����ʾ 
	pDC->BitBlt(0,0,m_rcClient.Width(),m_rcClient.Height(),&MemDC,0,0,SRCCOPY); 
	//��ͼ��ɺ������ 
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
		//�Զ�ͣ��
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
	//���ڽ��յ�������Ϣ
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
			m_str.Format("APR�仯λ��:%10.1f",m_fadd);
			m_promptinfoAPRreturn.SetCString(0,m_str);
			m_temp.Format("ID��:%08X",m_id);
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
			m_str.Format("�����仯λ��:%10.1f",m_fcode);
			m_promptinfoAPRreturn.SetCString(2,m_str);
			m_temp.Format("%d",m_byteCom[0x14]);
			m_temp.Insert(0,"��Ƶ:F");
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
			
			m_str.Format("APR�����:%10.1f",m_foldadd);
			m_promptinfoAPRreturn.SetCString(4,m_str);
			m_temp.Format("���������:%0.1f",m_foldcode);
			m_promptinfoAPRreturn.SetCString(5,m_temp);
			m_fgaproldadd=m_fadd;
			m_fgtrackcode=m_fcode;
			m_str+=m_temp;

		//	m_showhdmsg.AddMsg(m_str);
			m_strtowrite+=m_str;
			//��Ƶ
			m_str.Format("��Ƶ:M%d",m_byteCom[0x15]);
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
			m_str.Format("����λ��:%f",m_dgTrainRealPos);
			m_showhdmsg.AddMsg(m_str,8,TRUE);
			//��ʾ��ǰ����λ�ã�Ӧ����APR�غϣ���ȥ��ⷶΧ
			m_str.Format("����λ��:%f",m_fgantennaforshow-DISTANCE);
			m_showhdmsg.AddMsg(m_str,9,TRUE);
			m_str.Format("�Ķ���λ��:%f",m_fgreaderforshow-DISTANCE);
			m_showhdmsg.AddMsg(m_str,10,TRUE);
			*/
		}
	}
	 
	return 0; 
} 
LRESULT CALLTRACKAUTOView::OnMyCOMWrite(WPARAM wParam, LPARAM lParam) 
{ 
	//���ڷ�����Ϣ
	switch (wParam)
	{
		//״̬
	case 0x30:
		{
			CString m_str;
			m_str=m_macro.GetCode((unsigned char)lParam,FALSE);
			m_str.Insert(0,"����:");
			m_showautomsg.AddMsg(m_str);
			break;
		}
		//�����
	case 0x40:
		{
			CString m_str;
			m_str=m_trackcode.GetTrackCode((unsigned char)lParam,0);
			m_str.Insert(0,"����:");
			m_showautomsg.AddMsg(m_str);
			break;
		}
		//ͷβ��
	case 0x50:
		{
			CString m_str;
			m_str=m_macro.GetCode((unsigned char)lParam,FALSE);
			m_str.Insert(0,"����:");
			m_showautomsg.AddMsg(m_str);
		}
		//��Դ�ű�
	case 0x70:
		{
			CString m_str;
			m_str=m_macro.GetCode((unsigned char)lParam,FALSE);
			m_str.Insert(0,"����:");
			m_showautomsg.AddMsg(m_str);
			break;
		}
		//��Դ�ű�
	case 0x80:
		{
			CString m_str;
			m_str=m_macro.GetCode((unsigned char)lParam,FALSE);
			m_str.Insert(0,"����:");
			m_showautomsg.AddMsg(m_str);
			break;
		}
		//����֡
	case 0x0A:
		{
			
		}
	}
	
	return 0; 
} 

void CALLTRACKAUTOView::MandV()
{
	//ȫ�ֳ�����ʻ��̣�������λ��ֱ�Ӹ�������λ��ֻ�����ܼ���ʻ���
	CalculateTrainPos();	//��λ�������г�ʵ��λ��

	pThreadSeek->PostThreadMessage(WM_SEEKTRACKDATA,0,0);	//���㵱ǰ����Ƿ���Ҫ���͹����
	pThreadAPR->PostThreadMessage(WM_SEEKISSENDAPR,0,0);	//����Ƿ���APR
	m_nTrainView=126;										//�����г���ʾλ�ã��ȶ����г�λ��

	m_nTrackView=(int)(m_dgTrainRealPos*AMPLIFICATORY_TIMES-m_nTrainView*AMPLIFICATORY_TIMES);			//��������ʾλ��


	/*
	//�ж�����Ƿ�Ϊ252��Ϊ252���ʾ��װ�����ϵ磬��������Ѵ��־
	if (m_dgTrainRealPos==126)
	{
		if (m_bAlreadyClear==FALSE)
		{
			ClearFlagsForReset();
		}
	}
	*/
	//�ж�����Ƿ����������,�������������Զ���ת����תΪ����
	if ((m_dgTrainRealPos>=41000)&&(m_bAutoBreak==FALSE))
	{
		//��ʻ��̴����������ֵ
		CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
		m_frame->OnMenueb();
		m_bAutoBreak=TRUE;
	}
	//��ͼ��ʾ���ݲ�����
	if (m_bViewOn==TRUE)
	{
		//��ͼλ�ü��㣬����������
		m_pTrainpos.x=m_nTrainView*AMPLIFICATORY_TIMES;
		m_pTrainShowpos=m_pTrainpos;	//������ʾλ�ø�ֵ
	} 
	else
	{

	}
	//�жϳ����Ƿ��ڸ���ͼ��
	POINT	m_ptrainstart=m_pTrainShowpos;
	POINT	m_ptrainend=m_pTrainShowpos;
	m_ptrainstart.x-=119;
	m_ptrainend.x+=119;
	m_bShowTrain=FALSE;
	if (PtInRect(m_rcClient,m_ptrainstart)||PtInRect(m_rcClient,m_ptrainend))
	{
		m_Train.SetTrainPos(m_pTrainShowpos);
		//�ٶ�
		m_speedheadline.SetSpeed(m_nTrackView+m_pTrainShowpos.x+TRAINLENTH,(int)Speed()*AMPLIFICATORY_TIMES);
		//m_speedheadline.SetSpeed(m_nTrackView+m_pTrainShowpos.x-TRAINLENTH,(int)Speed()*AMPLIFICATORY_TIMES);
		m_bShowTrain=TRUE;
	}
	//����
	MilemeterDir();
	//״̬��Ϣ
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
	//ģ�����̨��λ��Ϣ
	BackGear();
	//ATP�س�QN�̵�������Ļز�
	CirclePickQN();
	//�����ź�
	Healthy();
	//�̵���
	Relay();
	//��λ������汾��
	SoftVersion();
	//�Ķ�����Ϣ����
	Reader();
	InvalidateRect(m_recttrack,TRUE);
}

double CALLTRACKAUTOView::Mail()
{
	//���Ϊ4���ֽ�Ϊ���ٵ���������Ĵ�����ʾ����ĸ�����̵ļ���ΪN*((PI*D)/200)��PIΪ��ֵDΪ�۾�ֵ200Ϊ�۾��ĳ�����
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
		//�����Ϊ0����λ������,��λ����¼������
		m_unmail=0;
		LoadConfig();	//���¼�������
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
	m_strmail.Insert(0,"���:");
	m_frame->m_wndStatusBar.SetPaneText(8,m_strmail);
	//�Ŵ���
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
			m_strmilemilemeterdir="����:ǰ";
			break;
		}
	case 0x55:
		{
			m_strmilemilemeterdir="����:��";
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
	m_strspeed.Insert(0,"�ٶ�:");
	CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
	m_frame->m_wndStatusBar.SetPaneText(11,m_strspeed);
	return m_dspeed;
}
void CALLTRACKAUTOView::BackStatus()
{
	//����״̬��Ϣ
	//�Ի�����ʾ
	if (m_dlgmsg->IsWindowVisible())
	{
		CString m_strmsg;
		int		m_ncounter=0;
		m_strmsg.Format("%02X",m_byteCom[0x11]);
		m_strmsg.Insert(0,"�г�״̬:");

		if (m_strmsg!=m_strmsgstatus)
		{
			m_dlgmsg->m_cliststatus.AddString(m_strmsg);
			m_ncounter=m_dlgmsg->m_cliststatus.GetCount();
			m_dlgmsg->m_cliststatus.SetCurSel(m_ncounter-1);
			m_strmsgstatus=m_strmsg;
		}

		m_strmsg.Format("%02X",m_byteCom[0x12]);
		m_strmsg.Insert(0,"ͷβ��:");

		if (m_strmsg!=m_strmsghd)
		{
			m_dlgmsg->m_clisthd.AddString(m_strmsg);
			m_ncounter=m_dlgmsg->m_clisthd.GetCount();
			m_dlgmsg->m_clisthd.SetCurSel(m_ncounter-1);
			m_strmsghd=m_strmsg;
		}
		
		m_strmsg.Format("%02X",m_byteCom[0x13]);
		m_strmsg.Insert(0,"�����:");

		if (m_strmsg!=m_strmsgtrackcode)
		{
			m_dlgmsg->m_clisttrackcode.AddString(m_strmsg);
			m_ncounter=m_dlgmsg->m_clisttrackcode.GetCount();
			m_dlgmsg->m_clisttrackcode.SetCurSel(m_ncounter-1);
			m_strmsgtrackcode=m_strmsg;
		}

		m_strmsg.Format("%02X",m_byteCom[0x14]);
		m_strmsg.Insert(0,"��Դ�ű�:");
		if (m_strmsg!=m_strmsgnpapr)
		{
			m_dlgmsg->m_clistnpapr.AddString(m_strmsg);
			m_ncounter=m_dlgmsg->m_clistnpapr.GetCount();
			m_dlgmsg->m_clistnpapr.SetCurSel(m_ncounter-1);
			m_strmsgnpapr=m_strmsg;
		}

		m_strmsg.Format("%02X",m_byteCom[0x15]);
		m_strmsg.Insert(0,"��Դ�ű�:");
		if (m_strmsg!=m_strmsgpapr)
		{
			m_dlgmsg->m_clistpapr.AddString(m_strmsg);
			m_ncounter=m_dlgmsg->m_clistpapr.GetCount();
			m_dlgmsg->m_clistpapr.SetCurSel(m_ncounter-1);
			m_strmsgpapr=m_strmsg;
		}
	}
	//��ʱ��ʾ
	if (m_byteCom[0x05]==0x80)
	{
		//״̬
		if ((m_byteWriteStatus[0x14]==m_byteCom[0x11])&&(m_byteCom[0x11]!=0))
		{
			m_bSendStatus=FALSE;
			m_showstatusmsg.AddMsg(m_macro.GetCode(m_byteWriteStatus[0x14],TRUE));
			m_byteWriteStatus[0x14]=0;
		}
		//ͷβ��
		if ((m_byteWriteCaputCauda[0x14]==m_byteCom[0x12])&&(m_byteCom[0x12]!=0))
		{
			m_bSendHD=FALSE;
			m_showhdmsg.AddMsg(m_macro.GetCode(m_byteWriteCaputCauda[0x14],TRUE));
			m_byteWriteCaputCauda[0x14]=0;
		}

		//�����
		if ((m_byteWriteTrackCode[0x14]==m_byteCom[0x13])&&(m_byteCom[0x13]!=0))
		{
			m_bSendCode=FALSE;
			m_showtcode.AddMsg(m_trackcode.GetTrackCode(m_byteWriteTrackCode[0x14],TRUE));
			m_byteWriteTrackCode[0x14]=0;
		}
		//��Դ�ű�
		if ((m_byteWritePAPR70[0x14]==m_byteCom[0x14])&&(m_byteCom[0x14]!=0)&&(m_bSendNPAPRF==TRUE))
		{
			m_bSendNPAPR=FALSE;
			m_shownpapr.AddMsg(m_macro.GetCode(m_byteWritePAPR70[0x14],TRUE));
			m_byteWritePAPR70[0x14]=0;
			m_bSendNPAPRF=FALSE;
		}
		//��Դ�ű�
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
	m_strhealthy.Insert(0,"����:");
	m_strhealthy+="Hz";
	CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
	m_frame->m_wndStatusBar.SetPaneText(12,m_strhealthy);
}

void CALLTRACKAUTOView::Relay()
{
	CString m_strrelay;
	CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
	//���ֳ�ʵ�����ݸ��ģ�����λ�������������ߺὭ�ĵ������г�ͻ
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
			//��������յ�
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
			//��������յ�
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
	//�����ǰ��ߺὭ�ĵ�����
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
			//��������յ�
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
			//��������յ�
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
			m_strreader="�Ķ���:��״̬";
			m_frame->m_wndStatusBar.SetPaneText(14,m_strreader);
			break;
		}
	case 0x80:
		{
			m_strreader="�Ķ���:����";
			m_frame->m_wndStatusBar.SetPaneText(14,m_strreader);
			break;
		}
	case 0x40:
		{
			m_strreader="�Ķ���:����";
			m_frame->m_wndStatusBar.SetPaneText(14,m_strreader);
			break;
		}
	case 0xc0:
		{
			m_strreader="�Ķ���:����֡";
			m_frame->m_wndStatusBar.SetPaneText(14,m_strreader);
			break;
		}	
	}
	m_bytereader=m_byteCom90[0x12]&0x30;
	switch (m_bytereader)
	{
	case 0:
		{
			m_strreader="�Ķ�����:��С";
			m_frame->m_wndStatusBar.SetPaneText(15,m_strreader);
			break;
		}
	case 0x10:
		{
			m_strreader="�Ķ�����:С";
			m_frame->m_wndStatusBar.SetPaneText(15,m_strreader);
			break;
		}
	case 0x20:
		{
			m_strreader="�Ķ�����:��";
			m_frame->m_wndStatusBar.SetPaneText(15,m_strreader);
			break;
		}
	case 0x30:
		{
			m_strreader="�Ķ�����:���";
			m_frame->m_wndStatusBar.SetPaneText(15,m_strreader);
			break;
		}
	}
	m_bytereader=m_byteCom90[0x12]&0x08;
	switch (m_bytereader)
	{
	case 0:
		{
			m_strreader="������:������";
			m_frame->m_wndStatusBar.SetPaneText(16,m_strreader);
			break;
		}
	case 0x08:
		{
			m_strreader="������:����";
			m_frame->m_wndStatusBar.SetPaneText(16,m_strreader);
			break;
		}
	}
}

BOOL CALLTRACKAUTOView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	//return CRecordView::OnEraseBkgnd(pDC); ����ȡ��view��������
	return TRUE;                                                                                                                     
}

void CALLTRACKAUTOView::WriteRecoder(CString m_strtowr)
{
	//���뵱ǰϵͳʱ��
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
	//�������ѷ��ͱ�־
	//���й��
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
	//���й��
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
	//������
	m_bAlreadyClear=TRUE;
	m_bgTrackEndPosCalculate=FALSE;	//�Ƿ���ù��������ʽѰ�ҹ��
}
LRESULT CALLTRACKAUTOView::OnMyClearFlag(WPARAM wParam, LPARAM lParam)
{
	ClearFlagsForReset();
	return 0;
}

void CALLTRACKAUTOView::CalculateTrainPos()
{
	double m_dmail;
	m_dmail=Mail();		//�����λ���������г������

	if (m_dmail>0)
	{
		m_dgaddmail=m_dmail-m_dgmail;
		m_dgmail=m_dmail;
		if (m_bDirectorup==TRUE)	//�����������жϳ������߷���
		{
			//�ó���λ�ü�ȥ��λ���������
			m_dgTrainRealPos-=m_dgaddmail;
		} 
		else
		{
			//�ó���λ�ü�����λ���������
			m_dgTrainRealPos+=m_dgaddmail;
		}
	}
}
LRESULT CALLTRACKAUTOView::OnMySaveTurnPos(WPARAM wParam, LPARAM lParam)
{
	m_dgTrainTrunPos=Mail();
	m_bReverse=TRUE;
	m_dgTrainAddPos=0;	//�г���������
	m_bgTrackEndPosCalculate=FALSE;
	m_bgSendCurrentTrackCode=FALSE;	//����ʱ�ñ�־λ�����͵�ǰ�����
	return 0;
}
LRESULT CALLTRACKAUTOView::OnMyAutoStop(WPARAM wParam, LPARAM lParam)
{
	if (!m_bAutoStop)
	{
		m_promptinfoMailandV.SetCString(4,"���������Զ�����ϵͳ!");
		m_bAutoStop=TRUE;
	} 
	else
	{
		m_promptinfoMailandV.SetCString(4,"���˳����Զ�����ϵͳ!");
		m_bAutoStop=FALSE;
		KillTimer(1);
	}
	return 0;
}
LRESULT CALLTRACKAUTOView::OnMyOnTargetSpeed(WPARAM wParam, LPARAM lParam)
{
	//�г��Ѿ��ﵽĿ���ٶȣ���ʼ�����г���ͣ�������
	SetTimer(1,1,NULL);
	return 0;
}
void CALLTRACKAUTOView::FindTrackofTrain(float m_fantennapos)
{
	//������Ϊ�������ߣ������Ķ���
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
				//�ҵ��������ڹ��,���͸ù���룬��������ͣ�����������
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
				//�ҵ��������ڹ��,���͸ù���룬��������ͣ�����������
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
	//�����������ڹ����Ƶ
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
	//������ԴAPR����
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
	//������ͣ�������
	double m_dclasp=0;	//����λ��
	//Ϊ��֤����ͣ׼������CM��λ
	m_dclasp=m_dgTrainRealPos*100+TRAINHALFLENTH*100+1010;
	double m_dbreakdistance;
	double m_dspeed=m_dgspeed/3.6*100;
	//B6�ƶ�
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
					//�ر��߳�
					::PostMessage((HWND)lpParam, WM_SENDSECONDCODE, m_gnSecondCodepos, m_gnSecondcode);
					m_uint=0;
				}
				break;
			}
		case 2:
			{
				if (m_dgTrainRealPos-DISTANCE<=m_gnSecondCodepos)
				{
					//�ر��߳�
					::PostMessage((HWND)lpParam, WM_SENDSECONDCODE, m_gnSecondCodepos, m_gnSecondcode);
					m_uint=0;
				}
				break;
			}
		case 3:
			{
				if (m_dgTrainRealPos+DISTANCE>=m_gnSecondCodepos)
				{
					//�ر��߳�
					::PostMessage((HWND)lpParam, WM_SENDSECONDCODE, m_gnSecondCodepos, m_gnSecondcode);
					m_uint=0;
				}
				break;
			}
		case 4:
			{
				if (m_dgTrainRealPos-DISTANCE<=m_gnSecondCodepos)
				{
					//�ر��߳�
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
	//�˹����ó���λ��
	
	//������¼����
	ClearFlagsForReset();
	m_bgTrackEndPosCalculate=FALSE;	//�Ƿ���ù��������ʽѰ�ҹ��
	//���ͳ������ڹ����ͼ���Ƿ���APR
	FindTrackofTrain((float)wParam);
	m_bgTrackEndPosCalculate=FALSE;	//�Ƿ���ù��������ʽѰ�ҹ��
	return 0;
}
LRESULT CALLTRACKAUTOView::OnMySendSecondTrackCode(WPARAM wParam, LPARAM lParam)
{

	float m_fchangecodepos;
	int	m_ncodepos;
	byte m_byte;
	CString m_str;
	//��Ƶ
	m_byte=(unsigned int)lParam;
	m_byteWriteTrackCode[0x07]=m_byte;
	m_fchangecodepos=(float)(m_dgmail+DISTANCE);
	m_str.Format("%0.2f",m_dgmail);
	m_str.Insert(0,"���:");
	m_showrunning.AddMsg(m_str);
	m_fchangecodepos=m_fchangecodepos*1000;
	m_ncodepos=(int)m_fchangecodepos;
	m_str.Format("%0.2f",m_fchangecodepos/1000);
	m_str.Insert(0,"�����:");
	m_showrunning.AddMsg(m_str);
	m_byteWriteTrackCode[0x09]=m_ncodepos;
	m_ncodepos=m_ncodepos>>8;
	m_byteWriteTrackCode[0x0a]=m_ncodepos;
	m_ncodepos=m_ncodepos>>8;
	m_byteWriteTrackCode[0x0b]=m_ncodepos;
	m_ncodepos=m_ncodepos>>8;
	m_byteWriteTrackCode[0x0c]=m_ncodepos;
	//����������Ϣ������Ϣ����������������Ϣ
	m_byte=m_byteWriteTrackCode[0x07]<<4;
	m_byte+=m_byteWriteTrackCode[0x06];
	m_byteWriteTrackCode[0x14]=m_byte;
	m_downtrack[lParam].m_btcodesend=TRUE;
	m_bSendCode=TRUE;
	m_ngtrackpointer=lParam;
	//���·��͹���룬�����־��Ч
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
	�ز�Ƶ�ʱ����
	��Ƶ��Hz��	4080	4320	4560	4800	5040	5280	5520	6000  ����
	���ͱ��(16����)	1	2	3	4	5	6	7	8	0x0a
	����Ƶ�ʱ����
	��Ƶ��Hz��	28	32	36	40	44	48	52	56	60	64	68	72	76	80
	���ͱ��(16����)	1	2	3	4	5	6	7	8	9	A	B	C	D	E
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

LRESULT CALLTRACKAUTOView::OnThreadRXMessage(WPARAM wParam,LPARAM lParam)		//���մ�����Ϣ
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
			AfxMessageBox("����������ʧ��!");
		}
	}
	//�����յĴ�������ȫ�����
	for (int i=0;i<(int)wParam;i++)
	{
		EnQueue(q,m_byteRXbuffer[i]);
	}
	//�жϻ��������Ƿ�һ֡����
	for (int m_nc=QueueLenth(q);m_nc>=24;m_nc--)
	{
		//���� ����Ƿ��յ�0xfc
		if(DeQueue(q,m_byteFrame[0])!=0)
		{
			AfxMessageBox("��������ʧ��");
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
			//�������
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

void CALLTRACKAUTOView::Init()//��ʼ������
{
	CCOMPORT m_comport;
	//m_comport.InitPort();	//���ڳ�ʼ��
	m_comport.OpenPort(2);
	InitFrame();
}
LRESULT CALLTRACKAUTOView::OnReceiveAComPort(WPARAM wParam, LPARAM lParam)	//�ҵ����ڲ����
{
	static int m_nindex=0;
	CString m_strport;
	m_strport.Format("COM%d",lParam);
//	m_Ccomportnumber.InsertString(m_nindex,m_strport);
	m_nindex++;
//	m_Ccomportnumber.SetCurSel(0);
	return 0;
}
void CALLTRACKAUTOView::InitFrame()//ֵ֡��ʼ��
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


LRESULT CALLTRACKAUTOView::OnWriteComPortMSG(WPARAM wParam, LPARAM lParam)//������Ϣ������ʾ
{
	//��ʾ������Ϣ
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
	//�ļ�д���¼
//	m_CTX.ReplaceSel(m_str);
//	m_CTX.PostMessage(WM_VSCROLL, SB_BOTTOM,0);
	return 0;
}

void CALLTRACKAUTOView::FrameParse()
{
	//Э�����
	BYTE	m_bytetmp=0;
	WORD		m_nMC=0;
	m_bytetmp=m_byteFrame[DATASTART+1];

	//			//B5������
	//������һ�ֽڣ���Ϊ���λ
	m_bytetmp=RightMove(m_bytetmp,2,1);
	m_bytetmp=RightMove(m_bytetmp,4,2);
	m_bytetmp=m_bytetmp&0x0F;	//ֻҪ���ֽ�
	m_nMC=m_bytetmp;
	//�����ڶ��ֽڣ���Ϊ�θ�λ
	m_bytetmp=m_byteFrame[DATASTART+2];
	//m_bytetmp=0x19;			//B5������
	m_bytetmp=RightMove(m_bytetmp,2,1);
	m_bytetmp=RightMove(m_bytetmp,3,1);
	m_bytetmp=RightMove(m_bytetmp,4,1);
	m_bytetmp=m_bytetmp&0x0F;	//ֻҪ���ֽ�
	m_nMC=m_nMC<<4;
	m_nMC=m_nMC|m_bytetmp;
	//���������ֽڣ���Ϊ�ε�λ
	m_bytetmp=m_byteFrame[DATASTART+3];
	//m_bytetmp=0x14;			//B5������
	m_bytetmp=RightMove(m_bytetmp,2,1);
	m_bytetmp=RightMove(m_bytetmp,3,1);
	m_bytetmp=RightMove(m_bytetmp,4,1);
	m_bytetmp=m_bytetmp&0x0F;	//ֻҪ���ֽ�
	m_nMC=m_nMC<<4;
	m_nMC=m_nMC|m_bytetmp;
	//���������ֽڣ���Ϊ���λ
	m_bytetmp=m_byteFrame[DATASTART+4];
	//m_bytetmp=0xb2;			//B5������
	m_bytetmp=m_bytetmp&0x50;
	m_bytetmp=m_bytetmp>>4;
	m_bytetmp=m_bytetmp&0x0F;	//ֻҪ���ֽ�
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
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO��λP4");
					break;
				}
			case MC_P3:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenud3();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO��λP3");
					break;
				}
			case MC_P2:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenud2();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO��λP2");
					break;
				}
			case MC_P1:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenud1();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO��λP1");
					break;
				}
			case MC_N:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenunone();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO��λP0");
					break;
				}
			case MC_B1:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenub1();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO��λB1");
					break;
				}
			case MC_B2:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenub2();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO��λB2");
					break;
				}
			case MC_B3:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenub3();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO��λB3");
					break;
				}
			case MC_B4:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenub4();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO��λB4");
					break;
				}
			case MC_B5:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenub5();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO��λB5");
					break;
				}
			case MC_B6:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenub6();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO��λB6");
					break;
				}
			case MC_B7:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenub7();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO��λB7");
					break;
				}
			case MC_EB:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenueb();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO��λEB");
					break;
				}
			case MC_EB1:
				{
					CMainFrame * m_frame=(CMainFrame*)AfxGetMainWnd();
					m_frame->OnMenueb();
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO��λEB");
					break;
				}
			default :
				{
					m_promptinfoParser.SetCString(SHOWLINE0,"ATO��λERR");
					break;
				}
		}

	}


	//����
	if (JudgeBit(m_byteFrame[DATASTART+4],1))
	{
		m_promptinfoParser.SetCString(SHOWLINE1,"����!");
	} 
	else
	{
		m_promptinfoParser.SetCString(SHOWLINE1,"");
	}

	//������ѡ
	if (JudgeBit(m_byteFrame[DATASTART+7],3))
	{
		m_promptinfoParser.SetCString(SHOWLINE2,"������ѡ");
	} 
	else
	{
		m_promptinfoParser.SetCString(SHOWLINE2,"");
	}
	//����
	if (JudgeBit(m_byteFrame[DATASTART+7],6))
	{
		m_promptinfoParser.SetCString(SHOWLINE3,"����");
	} 
	else
	{
		m_promptinfoParser.SetCString(SHOWLINE3,"");
	}
	//������ѡ
	if (JudgeBit(m_byteFrame[DATASTART+7],5))
	{
		m_promptinfoParser.SetCString(SHOWLINE4,"������ѡ");
	} 
	else
	{
		m_promptinfoParser.SetCString(SHOWLINE4,"");
	}
	//�ҿ���
	if (JudgeBit(m_byteFrame[DATASTART+7],7))
	{
		m_promptinfoParser.SetCString(SHOWLINE5,"�ҿ���");
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
