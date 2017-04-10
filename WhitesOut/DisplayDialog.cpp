// DisplayDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WhitesOut.h"
#include "DisplayDialog.h"
#include "afxdialogex.h"


// CDisplayDialog �Ի���

IMPLEMENT_DYNAMIC(CDisplayDialog, CDialog)

CDisplayDialog::CDisplayDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CDisplayDialog::IDD, pParent)
{

}

CDisplayDialog::~CDisplayDialog()
{
}

void CDisplayDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OCX1, m_MediaPlayer);
}


BEGIN_MESSAGE_MAP(CDisplayDialog, CDialog)
END_MESSAGE_MAP()


// CDisplayDialog ��Ϣ�������
BEGIN_EVENTSINK_MAP(CDisplayDialog, CDialog)
	ON_EVENT(CDisplayDialog, IDC_OCX1, 6506, CDisplayDialog::OnDoubleclickOcx1, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
END_EVENTSINK_MAP()


void CDisplayDialog::OnDoubleclickOcx1(short nButton, short nShiftState, long fX, long fY)
{
	// TODO: �ڴ˴������Ϣ����������
	CFileDialog dlg(TRUE,NULL,L"*.*",
		OFN_FILEMUSTEXIST,
		L"ActiveStreamingFormat(*.asf)|*.asf|"
		L"AudioVideoInterleaveFormat(*.avi)|*.avi|"
		L"RealAudio/RealVideo(*.rm)|*.rm|"
		L"WaveAudio(*.wav)|*.wav|"
		L"MIDIFile(*.mid)|*.mid|"
		L"�����ļ�(*.*)|*.*||" ); 
	if (dlg.DoModal()==IDOK)
		m_MediaPlayer.put_URL(dlg.GetPathName());   
	// ����ý���ļ���������������ʼ����

}
