// SetPAPR.cpp : implementation file
//

#include "stdafx.h"
#include "ALLTRACKAUTO.h"
#include "SetPAPR.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetPAPR dialog
extern CALLTRACKAUTOSet m_uptrack[];	//���й��
extern CALLTRACKAUTOSet m_downtrack[];	//���й��

int m_i=0;
CString m_strstation;
CString m_strtrack;
int m_icounter=0;
CString m_strinifilepath;
CSetPAPR::CSetPAPR(CWnd* pParent /*=NULL*/)
	: CDialog(CSetPAPR::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetPAPR)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSetPAPR::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetPAPR)
	DDX_Control(pDX, IDC_EDITFILEPATH, m_cFilePath);
	DDX_Control(pDX, IDC_EDIT6, m_byte6);
	DDX_Control(pDX, IDC_EDIT5, m_byte5);
	DDX_Control(pDX, IDC_EDIT4, m_byte4);
	DDX_Control(pDX, IDC_EDIT3, m_byte3);
	DDX_Control(pDX, IDC_EDIT2, m_byte2);
	DDX_Control(pDX, IDC_EDIT1, m_byte1);
	DDX_Control(pDX, IDC_COMBOUPDOWN, m_cUpDown);
	DDX_Control(pDX, IDC_COMBOTRACKNAME, m_cTrackName);
	DDX_Control(pDX, IDC_COMBOSTATIONNAME, m_cStationName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetPAPR, CDialog)
	//{{AFX_MSG_MAP(CSetPAPR)
	ON_CBN_SELCHANGE(IDC_COMBOSTATIONNAME, OnSelchangeCombostationname)
	ON_BN_CLICKED(IDC_BUTTONSAVE, OnButtonsave)
	ON_CBN_SELCHANGE(IDC_COMBOTRACKNAME, OnSelchangeCombotrackname)
	ON_BN_CLICKED(IDC_BUTTONFILESELECT, OnButtonfileselect)
	ON_BN_CLICKED(IDC_BUTTONREADFILE, OnButtonreadfile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetPAPR message handlers

void CSetPAPR::Init()
{
	m_cUpDown.InsertString(0,"����");
	m_cUpDown.InsertString(1,"����");
	m_cUpDown.SetCurSel(1);
	m_cStationName.InsertString(0,"�Գ���");
	m_cStationName.InsertString(1,"��ֱ��");
	m_cStationName.InsertString(2,"������");
	m_cStationName.InsertString(3,"֪��·");
	m_cStationName.InsertString(4,"�����");
	m_cStationName.InsertString(5,"�ϵ�");
	m_cStationName.InsertString(6,"������");
	m_cStationName.InsertString(7,"����");
	m_cStationName.InsertString(8,"������");
	m_cStationName.InsertString(9,"��Ӫ");
	m_cStationName.InsertString(10,"��ˮ��");
	m_cStationName.InsertString(11,"��Է");
	m_cStationName.InsertString(12,"������");
	m_cStationName.InsertString(13,"��ҩ��");
	m_cStationName.InsertString(14,"������");
	m_cStationName.InsertString(15,"����");
	m_cStationName.InsertString(16,"��ֱ��");
	m_cStationName.SetCurSel(0);

}

BOOL CSetPAPR::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSetPAPR::OnSelchangeCombostationname() 
{
	// TODO: Add your control notification handler code here
	m_i=0;
	m_cStationName.GetLBText(m_cStationName.GetCurSel(),m_strstation);
	if (m_cUpDown.GetCurSel())
	{
		//������������
		for (int i=0;i<TRACKDOWN;i++)
		{
			if (m_downtrack[i].m_Sname==m_strstation)
			{
				m_cTrackName.InsertString(m_i++,m_downtrack[i].m_TSname);
			}
		}
	} 
	else
	{
		//������������
		for (int i=0;i<TRACKUP;i++)
		{
			if (m_uptrack[i].m_Sname==m_strstation)
			{
				m_cTrackName.InsertString(m_i++,m_uptrack[i].m_TSname);
			}
		}
	}
	m_cTrackName.SetCurSel(0);
}

void CSetPAPR::OnButtonsave() 
{
	// TODO: Add your control notification handler code here
	CString m_str;
	char m_char[4];
	if (m_cUpDown.GetCurSel())
	{
		m_byte1.GetWindowText(m_char,4);
		m_downtrack[m_icounter].m_PAPRDATA[0]=(unsigned char)strtol(m_char,NULL,16);
		m_byte2.GetWindowText(m_char,4);
		m_downtrack[m_icounter].m_PAPRDATA[1]=(unsigned char)strtol(m_char,NULL,16);
		m_byte3.GetWindowText(m_char,4);
		m_downtrack[m_icounter].m_PAPRDATA[2]=(unsigned char)strtol(m_char,NULL,16);
		m_byte4.GetWindowText(m_char,4);
		m_downtrack[m_icounter].m_PAPRDATA[3]=(unsigned char)strtol(m_char,NULL,16);
		m_byte5.GetWindowText(m_char,4);
		m_downtrack[m_icounter].m_PAPRDATA[4]=(unsigned char)strtol(m_char,NULL,16);
		m_byte6.GetWindowText(m_char,4);
		m_downtrack[m_icounter].m_PAPRDATA[5]=(unsigned char)strtol(m_char,NULL,16);
		
	} 
	else
	{
		m_byte1.GetWindowText(m_char,4);
		m_uptrack[m_icounter].m_PAPRDATA[0]=(unsigned char)strtol(m_char,NULL,16);
		m_byte2.GetWindowText(m_char,4);
		m_uptrack[m_icounter].m_PAPRDATA[1]=(unsigned char)strtol(m_char,NULL,16);
		m_byte3.GetWindowText(m_char,4);
		m_uptrack[m_icounter].m_PAPRDATA[2]=(unsigned char)strtol(m_char,NULL,16);
		m_byte4.GetWindowText(m_char,4);
		m_uptrack[m_icounter].m_PAPRDATA[3]=(unsigned char)strtol(m_char,NULL,16);
		m_byte5.GetWindowText(m_char,4);
		m_uptrack[m_icounter].m_PAPRDATA[4]=(unsigned char)strtol(m_char,NULL,16);
		m_byte6.GetWindowText(m_char,4);
		m_uptrack[m_icounter].m_PAPRDATA[5]=(unsigned char)strtol(m_char,NULL,16);
		
	}
}

void CSetPAPR::OnSelchangeCombotrackname() 
{
	// TODO: Add your control notification handler code here
	CString m_str;
	m_cTrackName.GetLBText(m_cTrackName.GetCurSel(),m_strtrack);
	if (m_cUpDown.GetCurSel())
	{
		//������������
		for (int i=0;i<TRACKDOWN;i++)
		{
			if ((m_downtrack[i].m_Sname==m_strstation)&&(m_downtrack[i].m_TSname==m_strtrack))
			{
				m_icounter=i;
				m_str.Format("%02X",m_downtrack[i].m_PAPRDATA[0]);
				m_byte1.SetWindowText(m_str);
				m_str.Format("%02X",m_downtrack[i].m_PAPRDATA[1]);
				m_byte2.SetWindowText(m_str);
				m_str.Format("%02X",m_downtrack[i].m_PAPRDATA[2]);
				m_byte3.SetWindowText(m_str);
				m_str.Format("%02X",m_downtrack[i].m_PAPRDATA[3]);
				m_byte4.SetWindowText(m_str);
				m_str.Format("%02X",m_downtrack[i].m_PAPRDATA[4]);
				m_byte5.SetWindowText(m_str);
				m_str.Format("%02X",m_downtrack[i].m_PAPRDATA[5]);
				m_byte6.SetWindowText(m_str);
				break;
			}
		}
	} 
	else
	{
		//������������
		for (int i=0;i<TRACKUP;i++)
		{
			if (m_uptrack[i].m_Sname==m_strstation)
			{
				m_icounter=i;
				m_str.Format("%02X",m_uptrack[i].m_PAPRDATA[0]);
				m_byte1.SetWindowText(m_str);
				m_str.Format("%02X",m_uptrack[i].m_PAPRDATA[1]);
				m_byte2.SetWindowText(m_str);
				m_str.Format("%02X",m_uptrack[i].m_PAPRDATA[2]);
				m_byte3.SetWindowText(m_str);
				m_str.Format("%02X",m_uptrack[i].m_PAPRDATA[3]);
				m_byte4.SetWindowText(m_str);
				m_str.Format("%02X",m_uptrack[i].m_PAPRDATA[4]);
				m_byte5.SetWindowText(m_str);
				m_str.Format("%02X",m_uptrack[i].m_PAPRDATA[5]);
				m_byte6.SetWindowText(m_str);
			}
		}
	}
}

void CSetPAPR::OnButtonfileselect() 
{
	// TODO: Add your control notification handler code here
	CFileDialog mFileDlg(TRUE, NULL,NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT , "INI�ļ�(*.INI)|*.INI|INI�����ļ�(*.ini)|*.ini|All Files (*.*)|*.*|", AfxGetMainWnd());
    if(mFileDlg.DoModal()==IDOK)
	{
		m_strinifilepath=mFileDlg.GetPathName();//������ʾ·������
		m_cFilePath.SetWindowText(m_strinifilepath);
	}
	else
	{
		m_strinifilepath="";
	}
}

void CSetPAPR::OnButtonreadfile() 
{
	// TODO: Add your control notification handler code here
	if (m_strinifilepath=="")
	{
		AfxMessageBox("��ѡ��INI�����ļ�");
		return ;
	}

	//����·�������������ļ�
	CString m_strxie="\\";
	CString m_strxiexie="\\\\";
	m_strinifilepath.Replace(m_strxie,m_strxiexie);	//��һ����б���滻Ϊ˫б��

	//��ȡժҪ��Ϣ
	char	m_char[5];
	GetPrivateProfileString("SUMMARY", "TOTAL","0", m_char, 5,m_strinifilepath);
	int m_ntracknumber=0;
	m_ntracknumber=atoi(m_char);
	//����ȡ����д�뵱ǰ�ڴ���
	for (int i=1;i<=m_ntracknumber;i++)
	{
		CString m_strseg="TRACK";
		CString m_str;
		m_str.Format("%d",i);
		m_strseg+=m_str;
		CHAR m_charupdown[5];
		CHAR m_charstation[10];
		CHAR m_chartrackname[30];
		CString m_strstation;
		CString m_strtrack;
		CHAR m_charA[5];
		CHAR m_charB[5];
		CHAR m_charC[5];
		CHAR m_charD[5];
		CHAR m_charE[5];
		CHAR m_charF[5];
		GetPrivateProfileString(m_strseg, "UPDOWN","����", m_charupdown, 5,m_strinifilepath);
		GetPrivateProfileString(m_strseg, "STATION","", m_charstation, 10,m_strinifilepath);
		GetPrivateProfileString(m_strseg, "TRACKNAME","", m_chartrackname, 30,m_strinifilepath);
		GetPrivateProfileString(m_strseg, "A","0", m_charA, 5,m_strinifilepath);
		GetPrivateProfileString(m_strseg, "B","0", m_charB, 5,m_strinifilepath);
		GetPrivateProfileString(m_strseg, "C","0", m_charC, 5,m_strinifilepath);
		GetPrivateProfileString(m_strseg, "D","0", m_charD, 5,m_strinifilepath);
		GetPrivateProfileString(m_strseg, "E","0", m_charE, 5,m_strinifilepath);
		GetPrivateProfileString(m_strseg, "F","0", m_charF, 5,m_strinifilepath);
		m_str=m_charupdown;
		m_strstation=m_charstation;
		m_strtrack=m_chartrackname;
		if (m_str=="����")
		{
			//������������
			for (int j=0;j<TRACKDOWN;j++)
			{
				if ((m_downtrack[j].m_Sname==m_strstation)&&(m_downtrack[j].m_TSname==m_strtrack))
				{
					m_str=m_charA;
					m_downtrack[j].m_PAPRDATA[0]=(unsigned char)strtoul(m_str,NULL,16);
					m_str=m_charB;
					m_downtrack[j].m_PAPRDATA[1]=(unsigned char)strtoul(m_str,NULL,16);
					m_str=m_charC;
					m_downtrack[j].m_PAPRDATA[2]=(unsigned char)strtoul(m_str,NULL,16);
					m_str=m_charD;
					m_downtrack[j].m_PAPRDATA[3]=(unsigned char)strtoul(m_str,NULL,16);
					m_str=m_charE;
					m_downtrack[j].m_PAPRDATA[4]=(unsigned char)strtoul(m_str,NULL,16);
					m_str=m_charF;
					m_downtrack[j].m_PAPRDATA[5]=(unsigned char)strtoul(m_str,NULL,16);
					break;
				}
			}
		}
		else
		{
			//������������
			for (int j=0;j<TRACKUP;j++)
			{
				if ((m_uptrack[j].m_Sname==m_strstation)&&(m_uptrack[j].m_TSname==m_strtrack))
				{
					m_str=m_charA;
					m_uptrack[j].m_PAPRDATA[0]=(unsigned char)strtoul(m_str,NULL,16);
					m_str=m_charB;
					m_uptrack[j].m_PAPRDATA[1]=(unsigned char)strtoul(m_str,NULL,16);
					m_str=m_charC;
					m_uptrack[j].m_PAPRDATA[2]=(unsigned char)strtoul(m_str,NULL,16);
					m_str=m_charD;
					m_uptrack[j].m_PAPRDATA[3]=(unsigned char)strtoul(m_str,NULL,16);
					m_str=m_charE;
					m_uptrack[j].m_PAPRDATA[4]=(unsigned char)strtoul(m_str,NULL,16);
					m_str=m_charF;
					m_uptrack[j].m_PAPRDATA[5]=(unsigned char)strtoul(m_str,NULL,16);
					break;
				}
			}
		}
	}
}
