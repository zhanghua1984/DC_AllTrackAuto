// TRAINSET.cpp : implementation file
//

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "TRAINSET.h"
#include "ANTENNA.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern int			m_nNormalTrackPriority;		//直轨优先级
extern int			m_nFoldTrackPriority;		//折轨优先级
extern BOOL		m_bDefaultLowEndHigh;			//默认走高度低轨道
extern float		m_fgTrainOffSet;			//车辆起始位置
extern int				m_ngTrainhigh;
extern POINT		m_pTrainpos;				//车辆在轨道位置
extern BOOL			m_bprioritygrow;			//折轨优先级
extern double		m_dgTrainRealPos;			//全局车辆实际位置
extern BOOL		m_boolisfold;					//车辆是否走直轨
/////////////////////////////////////////////////////////////////////////////
// TRAINSET dialog


TRAINSET::TRAINSET(CWnd* pParent /*=NULL*/)
	: CDialog(TRAINSET::IDD, pParent)
{
	//{{AFX_DATA_INIT(TRAINSET)
	m_strtrainoffsetpos = _T("");
	//}}AFX_DATA_INIT
}


void TRAINSET::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TRAINSET)
	DDX_Control(pDX, IDC_RADIO6, m_cradio6che);
	DDX_Control(pDX, IDC_RADIO1, m_cradio1che);
	DDX_Control(pDX, IDC_EDITCONFIGPATH, m_cconfigpath);
	DDX_Control(pDX, IDC_PRIORITYGROWUP, m_cprioritygrowup);
	DDX_Control(pDX, IDC_COMBOORIGIN, m_ccomboorigin);
	DDX_Control(pDX, IDC_COMBOHIGH, m_ccombohigh);
	DDX_Control(pDX, IDC_COMBODEFAULTTRACK, m_ccombodefaulttrack);
	DDX_Text(pDX, IDC_TRAINSTARTPOS, m_strtrainoffsetpos);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TRAINSET, CDialog)
	//{{AFX_MSG_MAP(TRAINSET)
	ON_BN_CLICKED(IDC_SETTRAINPOS, OnSettrainpos)
	ON_BN_CLICKED(IDC_HIGHCONFIRM, OnHighconfirm)
	ON_BN_CLICKED(IDC_GROWUPCONFIRM, OnGrowupconfirm)
	ON_BN_CLICKED(IDC_READCONFIG, OnReadconfig)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO6, OnRadio6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TRAINSET message handlers

void TRAINSET::OnOK() 
{
	// TODO: Add extra validation here
	int	m_nsel=0;
	m_nsel=m_ccombodefaulttrack.GetCurSel();
	switch (m_nsel)
	{
	case 0:
		{
			m_nNormalTrackPriority=1;
			m_nFoldTrackPriority=10;
			m_boolisfold=FALSE;
			break;
		}
	case 1:
		{
			m_nNormalTrackPriority=8;
			m_nFoldTrackPriority=4;
			m_boolisfold=TRUE;
			break;
		}
	case 2:
		{
			m_bDefaultLowEndHigh=TRUE;
			m_boolisfold=TRUE;
			break;
		}
	case 3:
		{
			m_bDefaultLowEndHigh=FALSE;
			m_boolisfold=TRUE;
			break;
		}
	}


	CDialog::OnOK();
}

BOOL TRAINSET::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ccomboorigin.InsertString(0,"西直门");
	m_ccomboorigin.InsertString(1,"东直门");
	m_ccomboorigin.InsertString(2,"自定义位置");
	m_ccomboorigin.SetCurSel(0);

	m_ccombohigh.InsertString(0,"286");
	m_ccombohigh.InsertString(1,"296");
	m_ccombohigh.InsertString(2,"300");
	m_ccombohigh.InsertString(3,"310");
	m_ccombohigh.InsertString(4,"341");
	m_ccombohigh.InsertString(5,"352");
	m_ccombohigh.InsertString(6,"382");
	m_ccombohigh.InsertString(7,"415");
	m_ccombohigh.InsertString(8,"423");
	m_ccombohigh.InsertString(9,"432");
	m_ccombohigh.InsertString(10,"445");
	m_ccombohigh.InsertString(11,"500");

	m_ccombohigh.SetCurSel(0);
	m_ccombodefaulttrack.InsertString(0,"直轨");
	m_ccombodefaulttrack.InsertString(1,"侧向");
	m_ccombodefaulttrack.InsertString(2,"上侧向");
	m_ccombodefaulttrack.InsertString(3,"下侧向");
	m_ccombodefaulttrack.SetCurSel(0);


	m_cprioritygrowup.InsertString(0,"升级");
	m_cprioritygrowup.InsertString(1,"降级");
	m_cprioritygrowup.SetCurSel(0);
	m_cradio1che.SetCheck(1);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void TRAINSET::OnSettrainpos() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_cradio1che.GetCheck())	//计算头车车钩位置
	{
		m_dgTrainRealPos=(float)atof(m_strtrainoffsetpos)-TRAINHALFLENTH;
	}
	else	//计算尾车车钩位置
	{
		m_dgTrainRealPos=(float)atof(m_strtrainoffsetpos)+TRAINHALFLENTH;
	}
	CMainFrame* pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;	//先通过获取当前框架指针 
	CView * active = pMF->GetActiveView();					//才能获取当前视类指针 
	if(active != NULL)										//获取了当前视类指针才能发送消息 
		active->PostMessage(WM_SETTRAINPOS,atoi(m_strtrainoffsetpos),0);		//使用PostMessage发送消息 
}

void TRAINSET::OnHighconfirm() 
{
	// TODO: Add your control notification handler code here
	int	m_nsel=0;
	m_nsel=m_ccombohigh.GetCurSel();
	switch (m_nsel)
	{
	case 0:
		{
			m_ngTrainhigh=286;
			break;
		}
	case 1:
		{
			m_ngTrainhigh=296;
			break;
		}
	case 2:
		{
			m_ngTrainhigh=300;
			break;
		}
	case 3:
		{
			m_ngTrainhigh=310;
			break;
		}
	case 4:
		{
			m_ngTrainhigh=341;
			break;
		}
	case 5:
		{
			m_ngTrainhigh=352;
			break;
		}
	case 6:
		{
			m_ngTrainhigh=382;
			break;
		}
	case 7:
		{
			m_ngTrainhigh=415;
			break;
		}
	case 8:
		{
			m_ngTrainhigh=423;
			break;
		}
	case 9:
		{
			m_ngTrainhigh=432;
			break;
		}
	case 10:
		{
			m_ngTrainhigh=445;
			break;
		}
	case 11:
		{
			m_ngTrainhigh=500;
			break;
		}
	}
	m_pTrainpos.y=m_ngTrainhigh-TRAINONTRACKHIGH;
}

void TRAINSET::OnGrowupconfirm() 
{
	// TODO: Add your control notification handler code here
	int m_n=m_cprioritygrowup.GetCurSel();
	if (m_n==0)
	{
		//升级
		m_bprioritygrow=TRUE;
	} 
	else
	{
		//降级
		m_bprioritygrow=FALSE;
	}
}

void TRAINSET::OnReadconfig() 
{
	// TODO: Add your control notification handler code here
	CString m_strreadfilepath;
	CString m_strreadpath;
	CFileDialog m_FileDlg(TRUE, NULL,NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT , "试车线轨道配置文件(*.ini)|*.ini|All Files (*.*)|*.*|", AfxGetMainWnd());
	
    if(m_FileDlg.DoModal()==IDOK)
	{
		m_strreadfilepath=m_FileDlg.GetPathName();
		m_strreadpath=m_strreadfilepath;
		CString m_strxie="\\";
		CString m_strxiexie="\\\\";
		m_strreadfilepath.Replace(m_strxie,m_strxiexie);	//将一个反斜杠替换为双斜杠
		//读取摘要信息
		char	m_char[5];
		GetPrivateProfileString("SUMMARY", "TOTAL","0", m_char, 5,m_strreadfilepath);
		int m_ntracknumber=0;
		m_ntracknumber=atoi(m_char);
		//将读取数据写入当前内存中
		for (int i=1;i<=m_ntracknumber;i++)
		{
			CString m_strseg="TRACK";
			CString m_str;
			m_str.Format("%d",i);
			m_strseg+=m_str;
			CHAR m_charupdown[5];
			CHAR m_charstation[10];
			CHAR m_chartrackname[30];
			CHAR m_chartracknumber[20];
			CHAR m_charcf[5];
			CHAR m_charcode[5];
			CHAR m_charaprid[20];
			
			GetPrivateProfileString(m_strseg, "UPDOWN","下行", m_charupdown, 5,m_strreadfilepath);
			GetPrivateProfileString(m_strseg, "STATIONNAME","0", m_charstation, 10,m_strreadfilepath);
			GetPrivateProfileString(m_strseg, "TRACKNAME","0", m_chartrackname, 30,m_strreadfilepath);
			GetPrivateProfileString(m_strseg, "TRACKNUMBER","0", m_chartracknumber, 20,m_strreadfilepath);
			GetPrivateProfileString(m_strseg, "CF","0", m_charcf, 5,m_strreadfilepath);
			GetPrivateProfileString(m_strseg, "TRACKCODE","0", m_charcode, 5,m_strreadfilepath);
			GetPrivateProfileString(m_strseg, "APRID","0", m_charaprid, 20,m_strreadfilepath);

			m_str=m_charupdown;
			CString m_strstationname=m_charstation;
			CString m_strtrackname=m_chartrackname;
			CString m_strtracknumber=m_chartracknumber;
			CString m_strcf=m_charcf;
			CString m_strtrackcode=m_charcode;
		}
	}
	UpdateData(FALSE);
}

void TRAINSET::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	m_cradio1che.SetCheck(1);
	m_cradio6che.SetCheck(0);
}

void TRAINSET::OnRadio6() 
{
	// TODO: Add your control notification handler code here
	m_cradio1che.SetCheck(0);
	m_cradio6che.SetCheck(1);
}
