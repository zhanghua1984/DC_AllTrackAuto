// TRACKCODECHANGE.cpp : implementation file
//

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "TRACKCODECHANGE.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TRACKCODECHANGE dialog

extern CALLTRACKAUTOSet m_uptrack[];	//上行轨道
extern CALLTRACKAUTOSet m_downtrack[];	//下行轨道
CString m_strgstation;
TRACKCODECHANGE::TRACKCODECHANGE(CWnd* pParent /*=NULL*/)
	: CDialog(TRACKCODECHANGE::IDD, pParent)
{
	//{{AFX_DATA_INIT(TRACKCODECHANGE)
	m_strfilepos = _T("");
	m_stroriginallycarray = _T("");
	m_stroriginallycode = _T("");
	//}}AFX_DATA_INIT
}


void TRACKCODECHANGE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TRACKCODECHANGE)
	DDX_Control(pDX, IDC_COMBOUPDOWN, m_cupdown);
	DDX_Control(pDX, IDC_COMBOTRACKNAME, m_ctrackname);
	DDX_Control(pDX, IDC_COMBOSTATION, m_cstation);
	DDX_Control(pDX, IDC_COMBOCODEFRU, m_ccodefru);
	DDX_Control(pDX, IDC_COMBOCARRAYFRU, m_ccarrayfru);
	DDX_Text(pDX, IDC_FILEPOSTION, m_strfilepos);
	DDX_Text(pDX, IDC_ORIGINALLYCARRAY, m_stroriginallycarray);
	DDX_Text(pDX, IDC_ORIGINALLYCODE, m_stroriginallycode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TRACKCODECHANGE, CDialog)
	//{{AFX_MSG_MAP(TRACKCODECHANGE)
	ON_BN_CLICKED(IDC_BUTTONREAD, OnButtonread)
	ON_BN_CLICKED(IDC_BUTTONCHANGE, OnButtonchange)
	ON_CBN_SELCHANGE(IDC_COMBOUPDOWN, OnSelchangeComboupdown)
	ON_CBN_SELCHANGE(IDC_COMBOSTATION, OnSelchangeCombostation)
	ON_CBN_SELCHANGE(IDC_COMBOTRACKNAME, OnSelchangeCombotrackname)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TRACKCODECHANGE message handlers

void TRACKCODECHANGE::OnButtonread() 
{
	// TODO: Add your control notification handler code here
	CString m_strreadfilepath;
	CFileDialog m_FileDlg(TRUE, NULL,NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT , "轨道配置文件(*.ini)|*.ini|All Files (*.*)|*.*|", AfxGetMainWnd());
	
    if(m_FileDlg.DoModal()==IDOK)
	{
		m_strreadfilepath=m_FileDlg.GetPathName();
		m_strfilepos=m_strreadfilepath;
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
			int  m_nSendCode;
			GetPrivateProfileString(m_strseg, "UPDOWN","下行", m_charupdown, 5,m_strreadfilepath);
			GetPrivateProfileString(m_strseg, "STATIONNAME","0", m_charstation, 10,m_strreadfilepath);
			GetPrivateProfileString(m_strseg, "TRACKNAME","0", m_chartrackname, 30,m_strreadfilepath);
			GetPrivateProfileString(m_strseg, "TRACKNUMBER","0", m_chartracknumber, 20,m_strreadfilepath);
			GetPrivateProfileString(m_strseg, "CF","0", m_charcf, 5,m_strreadfilepath);
			GetPrivateProfileString(m_strseg, "TRACKCODE","0", m_charcode, 5,m_strreadfilepath);
			GetPrivateProfileString(m_strseg, "APRID","0", m_charaprid, 20,m_strreadfilepath);
			/*
			GetPrivateProfileInt(
				LPCTSTR lpAppName,  // address of section name
				LPCTSTR lpKeyName,  // address of key name
				INT nDefault,       // return value if key name is not found
				LPCTSTR lpFileName  // address of initialization filename
				);
			*/
			m_nSendCode=GetPrivateProfileInt(m_strseg,"SENDCODE",14,m_strreadfilepath);
			m_str=m_charupdown;
			CString m_strstationname=m_charstation;
			CString m_strtrackname=m_chartrackname;
			CString m_strtracknumber=m_chartracknumber;
			CString m_strcf=m_charcf;
			CString m_strtrackcode=m_charcode;

			//在轨道数据中搜索对应数据
			
			if (m_str=="下行")
			{
				for (int j=0;j<TRACKDOWN;j++)
				{
					if ((m_downtrack[j].m_Sname==m_strstationname)&&(m_downtrack[j].m_TSname==m_strtrackname)&&(m_downtrack[j].m_Tsnumber==m_strtracknumber))
					{
						m_downtrack[j].m_CF=m_strcf;
						m_downtrack[j].m_SENDCODE=m_nSendCode;
						break;
					}
				}
			} 
			else
			{
				for (int j=0;j<TRACKUP;j++)
				{
					if ((m_uptrack[j].m_Sname==m_strstationname)&&(m_uptrack[j].m_TSname==m_strtrackname)&&(m_uptrack[j].m_Tsnumber==m_strtracknumber))
					{
						m_uptrack[j].m_CF=m_strcf;
						m_uptrack[j].m_SENDCODE=m_nSendCode;
						break;
					}
				}
			}
			
		}
	}
	UpdateData(FALSE);
}

void TRACKCODECHANGE::OnButtonchange() 
{
	// TODO: Add your control notification handler code here
	//判断是否已经选择站和轨道
	if ((m_bstationselected==TRUE)&&(m_btracknameselected==TRUE))
	{
		//判断路径
		if (m_strfilepath=="")
		{
			//加入当前系统时间
			CString m_strsystime;
			CTime t=CTime::GetCurrentTime();
			m_strsystime=t.Format("%Y%m%d%H%M%S");

			CString m_strtypename="ini";
			CString m_strfilename="轨道码";
			m_strfilename+=m_strsystime;
			char *pFilters = NULL;
			char szfilters1[]="轨道码配置文件(*.ini)|";
			pFilters = szfilters1;
			CFileDialog m_dlgfilepath(FALSE,m_strtypename,m_strfilename,OFN_HIDEREADONLY,pFilters);
			if (m_dlgfilepath.DoModal()==IDOK)
			{
				m_strfilepath=m_dlgfilepath.GetPathName();
				m_strfilepos=m_strfilepath;
				//得到文件名称开始写入信息
				CString m_strxie="\\";
				CString m_strxiexie="\\\\";
				m_ncounterwriter=1;		//写入文件开始至少一个
				m_strfilepath.Replace(m_strxie,m_strxiexie);	//将一个反斜杠替换为双斜杠
				//每次写入一个轨道文件时，将总计数更改为总计数
				CString	m_strtotal;
				m_strtotal.Format("%d",m_ncounterwriter);

				WritePrivateProfileString("SUMMARY", "TOTAL",m_strtotal, m_strfilepath);
				CString m_strsegname="TRACK";
				m_strsegname+=m_strtotal;
				//下行
				if (m_bup==FALSE)
				{
					WritePrivateProfileString(m_strsegname, "UPDOWN","下行", m_strfilepath);
					WritePrivateProfileString(m_strsegname, "STATIONNAME",m_downtrack[m_npoint].m_Sname, m_strfilepath);
					WritePrivateProfileString(m_strsegname, "TRACKNAME",m_downtrack[m_npoint].m_TSname, m_strfilepath);
					WritePrivateProfileString(m_strsegname, "TRACKNUMBER",m_downtrack[m_npoint].m_Tsnumber, m_strfilepath);
					WritePrivateProfileString(m_strsegname, "CF",GetCF(), m_strfilepath);
					WritePrivateProfileString(m_strsegname, "TRACKCODE",GetTrackCode(), m_strfilepath);
				}
				//上行
				else
				{
					WritePrivateProfileString(m_strsegname, "UPDOWN","上行", m_strfilepath);
					WritePrivateProfileString(m_strsegname, "STATIONNAME",m_uptrack[m_npoint].m_Sname, m_strfilepath);
					WritePrivateProfileString(m_strsegname, "TRACKNAME",m_uptrack[m_npoint].m_TSname, m_strfilepath);
					WritePrivateProfileString(m_strsegname, "TRACKNUMBER",m_uptrack[m_npoint].m_Tsnumber, m_strfilepath);
					WritePrivateProfileString(m_strsegname, "CF",GetCF(), m_strfilepath);
					WritePrivateProfileString(m_strsegname, "TRACKCODE",GetTrackCode(), m_strfilepath);
				}

				m_ncounterwriter++;
			}
		} 
		else
		{
			//每次写入一个轨道文件时，将总计数更改为总计数
			CString	m_strtotal;
			m_strtotal.Format("%d",m_ncounterwriter);
			
			WritePrivateProfileString("SUMMARY", "TOTAL",m_strtotal, m_strfilepath);
			CString m_strsegname="TRACK";
			m_strsegname+=m_strtotal;
			//下行
			if (m_bup==FALSE)
			{
				WritePrivateProfileString(m_strsegname, "UPDOWN","下行", m_strfilepath);
				WritePrivateProfileString(m_strsegname, "STATIONNAME",m_downtrack[m_npoint].m_Sname, m_strfilepath);
				WritePrivateProfileString(m_strsegname, "TRACKNAME",m_downtrack[m_npoint].m_TSname, m_strfilepath);
				WritePrivateProfileString(m_strsegname, "TRACKNUMBER",m_downtrack[m_npoint].m_Tsnumber, m_strfilepath);
				WritePrivateProfileString(m_strsegname, "CF",GetCF(), m_strfilepath);
				WritePrivateProfileString(m_strsegname, "TRACKCODE",GetTrackCode(), m_strfilepath);
			}
			//上行
			else
			{
				WritePrivateProfileString(m_strsegname, "UPDOWN","上行", m_strfilepath);
				WritePrivateProfileString(m_strsegname, "STATIONNAME",m_uptrack[m_npoint].m_Sname, m_strfilepath);
				WritePrivateProfileString(m_strsegname, "TRACKNAME",m_uptrack[m_npoint].m_TSname, m_strfilepath);
				WritePrivateProfileString(m_strsegname, "TRACKNUMBER",m_uptrack[m_npoint].m_Tsnumber, m_strfilepath);
				WritePrivateProfileString(m_strsegname, "CF",GetCF(), m_strfilepath);
				WritePrivateProfileString(m_strsegname, "TRACKCODE",GetTrackCode(), m_strfilepath);
			}
			
			m_ncounterwriter++;
		}
		UpdateData(FALSE);
	} 
	else
	{
		AfxMessageBox("您还未选择站名和轨道名!");
	}

}

BOOL TRACKCODECHANGE::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//条件加载
	m_cupdown.InsertString(0,"上行");
	m_cupdown.InsertString(1,"下行");
	m_cupdown.SetCurSel(1);

	m_ccarrayfru.InsertString(0,"F1:4080");
	m_ccarrayfru.InsertString(1,"F2:4320");
	m_ccarrayfru.InsertString(2,"F3:4560");
	m_ccarrayfru.InsertString(3,"F4:4800");
	m_ccarrayfru.InsertString(4,"F5:5040");
	m_ccarrayfru.InsertString(5,"F6:5280");
	m_ccarrayfru.InsertString(6,"F7:5520");
	m_ccarrayfru.InsertString(7,"F9:6000");
	m_ccarrayfru.InsertString(8,"F10:无码");
	m_ccarrayfru.SetCurSel(0);

	m_ccodefru.InsertString(0,"M1:28:74/73");
	m_ccodefru.InsertString(1,"M2:32:74/58");
	m_ccodefru.InsertString(2,"M3:36:59/58");
	m_ccodefru.InsertString(3,"M4:40:59/37");
	m_ccodefru.InsertString(4,"M5:44:38/37");
	m_ccodefru.InsertString(5,"M6:48:38/27");
	m_ccodefru.InsertString(6,"M7:52:NONE");
	m_ccodefru.InsertString(7,"M8:56:38/0");
	m_ccodefru.InsertString(8,"M9:60:28/27");
	m_ccodefru.InsertString(9,"M10:64:28/19");
	m_ccodefru.InsertString(10,"M11:68:28/0");
	m_ccodefru.InsertString(11,"M12:72:NONE");
	m_ccodefru.InsertString(12,"M13:76:20/0");
	m_ccodefru.InsertString(13,"M14:80:0/0");
	m_ccodefru.InsertString(14,"M15:100");

	m_ccodefru.SetCurSel(0);
	m_ncounterwriter=0;
	m_btracknameselected=FALSE;
	m_bstationselected=FALSE;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void TRACKCODECHANGE::OnSelchangeComboupdown() 
{
	// TODO: Add your control notification handler code here
	/*
	extern CALLTRACKAUTOSet m_uptrack[];	//上行轨道
	extern CALLTRACKAUTOSet m_downtrack[];	//下行轨道
	*/
	m_cstation.ResetContent();
	
	//下行
	if (m_cupdown.GetCurSel())
	{
		int m_ninsertcounter=0;
		CString m_str;
		BOOL	m_bhad=FALSE;
		for (int i=0;i<TRACKUP;i++)
		{
			m_bhad=FALSE;
			for(int j=0;j<m_ninsertcounter;j++)
			{
				m_cstation.GetLBText(j,m_str);
				if (m_str==m_downtrack[i].m_Sname)
				{
					m_bhad=TRUE;
					break;
				}
			}
			if (m_bhad==FALSE)
			{
				m_cstation.InsertString(m_ninsertcounter,m_downtrack[i].m_Sname);
				m_ninsertcounter++;
			}
		}
	} 
	//上行
	else
	{
		int m_ninsertcounter=0;
		CString m_str;
		BOOL	m_bhad=FALSE;
		for (int i=0;i<TRACKUP;i++)
		{
			m_bhad=FALSE;
			for(int j=0;j<m_ninsertcounter;j++)
			{
				m_cstation.GetLBText(j,m_str);
				if (m_str==m_uptrack[i].m_Sname)
				{
					m_bhad=TRUE;
					break;
				}
			}
			if (m_bhad==FALSE)
			{
				m_cstation.InsertString(m_ninsertcounter,m_uptrack[i].m_Sname);
				m_ninsertcounter++;
			}
		}
	}
	m_cstation.SetCurSel(0);
}

void TRACKCODECHANGE::OnSelchangeCombostation() 
{
	// TODO: Add your control notification handler code here
	
	m_ctrackname.ResetContent();
	int m_nsel=0;
	int m_ninsertstring=0;
	CString m_strstation;
	m_nsel=m_cstation.GetCurSel();
	m_cstation.GetLBText(m_nsel,m_strstation);
	m_strgstation=m_strstation;
	//判断上下行
	//下行
	if (m_cupdown.GetCurSel())
	{
		for (int i=0;i<TRACKDOWN;i++)
		{
			if (m_strstation==m_downtrack[i].m_Sname)
			{
				m_ctrackname.InsertString(m_ninsertstring++,m_downtrack[i].m_TSname);
			}
		}
	} 
	else
	{
		for (int i=0;i<TRACKUP;i++)
		{
			if (m_strstation==m_uptrack[i].m_Sname)
			{
				m_ctrackname.InsertString(m_ninsertstring++,m_uptrack[i].m_TSname);
			}
		}
	}
	m_ctrackname.SetCurSel(0);
	m_btracknameselected=TRUE;

}

void TRACKCODECHANGE::OnSelchangeCombotrackname() 
{
	// TODO: Add your control notification handler code here
	CString m_strseltrackname;
	int		m_nseltn=0;
	m_nseltn=m_ctrackname.GetCurSel();
	m_ctrackname.GetLBText(m_nseltn,m_strseltrackname);

	//判断上下行
	//下行
	
	if (m_cupdown.GetCurSel())
	{
		for (int i=0;i<TRACKDOWN;i++)
		{
			//判断上下行、站名称、轨道名称
			if (("下行"==m_downtrack[i].m_UpDown)&&(m_strgstation==m_downtrack[i].m_Sname)&&(m_strseltrackname==m_downtrack[i].m_TSname))
			{
				m_stroriginallycarray=m_downtrack[i].m_CF;
				m_stroriginallycode.Format("%d",m_downtrack[i].m_SENDCODE);
				m_stroriginallycode.Insert(0,"M");
				m_bup=FALSE;
				m_npoint=i;
			}
		}
	} 
	else
	{
		for (int i=0;i<TRACKUP;i++)
		{
			//判断上下行、站名称、轨道名称
			if (("上行"==m_uptrack[i].m_UpDown)&&(m_strgstation==m_uptrack[i].m_Sname)&&(m_strseltrackname==m_uptrack[i].m_TSname))
			{
				m_stroriginallycarray=m_uptrack[i].m_CF;
				m_stroriginallycode.Format("%d",m_uptrack[i].m_SENDCODE);
				m_stroriginallycode.Insert(0,"M");
				m_bup=TRUE;
				m_npoint=i;
			}
		}
	}
	UpdateData(FALSE);
	m_bstationselected=TRUE;
}

CString TRACKCODECHANGE::GetCF()
{
	CString m_cf;
	int		m_nsel=0;
	m_nsel=m_ccarrayfru.GetCurSel();
	//选择从0开始
	m_nsel++;
	if (m_nsel==8)
	{
		m_cf.Format("0xF%d",9);
	}
	else
	{
		m_cf.Format("0xF%d",m_nsel);
	}
	return m_cf;
}

CString TRACKCODECHANGE::GetTrackCode()
{
	CString m_trackcode;
	int m_nsel=0;
	m_nsel=m_ccodefru.GetCurSel();
	m_nsel++;
	m_trackcode.Format("%d",m_nsel);
	return m_trackcode;
}
