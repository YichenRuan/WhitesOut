// SetDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WhitesOut.h"
#include "SetDialog.h"
#include "afxdialogex.h"


// CSetDialog �Ի���

IMPLEMENT_DYNAMIC(CSetDialog, CDialog)

CSetDialog::CSetDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSetDialog::IDD, pParent)
{
}


CSetDialog::~CSetDialog()
{
}

void CSetDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_HScrollM);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_HScrollN);
	DDX_Control(pDX, IDC_EDITM, m_EditM);
	DDX_Control(pDX, IDC_EDITN, m_EditN);
	DDX_Control(pDX, IDC_RADIO_PRE, m_RadioBotton_Pre);
	DDX_Control(pDX, IDC_RADIO_THREE, m_RadioBotton_Three);
	DDX_Control(pDX, IDC_RADIO_RANDOM, m_RadioBotton_Random);
	DDX_Control(pDX, IDC_RADIO_FIVE, m_RadioBotton_Five);
	DDX_Control(pDX, IDC_RADIO_FOUR, m_RadioBotton_Four);
}


BEGIN_MESSAGE_MAP(CSetDialog, CDialog)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_RADIO_PRE, &CSetDialog::OnClickedRadioPre)
	ON_BN_CLICKED(IDC_RADIO_RANDOM, &CSetDialog::OnClickedRadioRandom)
	ON_BN_CLICKED(IDC_RADIO_THREE, &CSetDialog::OnClickedRadioThree)
	ON_BN_CLICKED(IDC_RADIO_FOUR, &CSetDialog::OnClickedRadioFour)
	ON_BN_CLICKED(IDC_RADIO_FIVE, &CSetDialog::OnClickedRadioFive)
	ON_EN_CHANGE(IDC_EDITM, &CSetDialog::OnChangeEditm)
	ON_EN_CHANGE(IDC_EDITN, &CSetDialog::OnChangeEditn)
END_MESSAGE_MAP()


// CSetDialog ��Ϣ�������



void CSetDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	int iNowPos;
	if(pScrollBar == &m_HScrollM)
	{
		switch(nSBCode)
		{
		case SB_THUMBTRACK:                  //�϶���������ʱ
			m_HScrollM.SetScrollPos(nPos);
			DisplayEditM(m_HScrollM.GetScrollPos());
			break;
		case SB_LINEDOWN:                     //�������������µļ�ͷ
			iNowPos = m_HScrollM.GetScrollPos();
			iNowPos++;
			if(iNowPos > 7)
				iNowPos = 7;
			m_HScrollM.SetScrollPos(iNowPos);
			DisplayEditM(m_HScrollM.GetScrollPos());
			break;
		case SB_LINEUP:                      //�������������ϵļ�ͷ
			iNowPos = m_HScrollM.GetScrollPos();
			iNowPos--;
			if(iNowPos < 0)
				iNowPos = 0;
			m_HScrollM.SetScrollPos(iNowPos);
			DisplayEditM(m_HScrollM.GetScrollPos());
			break;
		case SB_PAGEDOWN:                    //��������������ļ�ͷ�������֮�������
			iNowPos = m_HScrollM.GetScrollPos();
			iNowPos += 1;
			if(iNowPos > 7)
				iNowPos = 7;
			m_HScrollM.SetScrollPos(iNowPos);
			DisplayEditM(m_HScrollM.GetScrollPos());
			break;
		case SB_PAGEUP:                      //��������������ļ�ͷ�������֮�������
			iNowPos = m_HScrollM.GetScrollPos();
			iNowPos -= 1;
			if(iNowPos < 0)
				iNowPos = 0;
			m_HScrollM.SetScrollPos(iNowPos);
			DisplayEditM(m_HScrollM.GetScrollPos());
			break;
		default:
			break;
		}
	}
	else if (pScrollBar == &m_HScrollN)
	{
		switch(nSBCode)
		{
		case SB_THUMBTRACK:                  //�϶���������ʱ
			m_HScrollN.SetScrollPos(nPos);
			DisplayEditN(m_HScrollN.GetScrollPos());
			break;
		case SB_LINEDOWN:                     //�������������µļ�ͷ
			iNowPos = m_HScrollN.GetScrollPos();
			iNowPos++;
			if(iNowPos > 7)
				iNowPos = 7;
			m_HScrollN.SetScrollPos(iNowPos);
			DisplayEditN(m_HScrollN.GetScrollPos());
			break;
		case SB_LINEUP:                      //�������������ϵļ�ͷ
			iNowPos = m_HScrollN.GetScrollPos();
			iNowPos--;
			if(iNowPos < 0)
				iNowPos = 0;
			m_HScrollN.SetScrollPos(iNowPos);
			DisplayEditN(m_HScrollN.GetScrollPos());
			break;
		case SB_PAGEDOWN:                    //��������������ļ�ͷ�������֮�������
			iNowPos = m_HScrollN.GetScrollPos();
			iNowPos += 1;
			if(iNowPos > 7)
				iNowPos = 7;
			m_HScrollN.SetScrollPos(iNowPos);
			DisplayEditN(m_HScrollN.GetScrollPos());
			break;
		case SB_PAGEUP:                      //��������������ļ�ͷ�������֮�������
			iNowPos = m_HScrollN.GetScrollPos();
			iNowPos -= 1;
			if(iNowPos < 0)
				iNowPos = 0;
			m_HScrollN.SetScrollPos(iNowPos);
			DisplayEditN(m_HScrollN.GetScrollPos());
			break;
		default:
			break;
		}	
	}
}


void CSetDialog::DisplayEditM(int pos)
{
	wchar_t sPos[10];
	_itow_s(pos, sPos,10);
	m_EditM.SetSel(0, -1);
	m_EditM.ReplaceSel((LPCTSTR)sPos);
	UpdateData(FALSE);
	nX = pos;
	return;
}

void CSetDialog::DisplayEditN(int pos)
{
	wchar_t sPos[10];
	_itow_s(pos, sPos,10);
	m_EditN.SetSel(0, -1);
	m_EditN.ReplaceSel((LPCTSTR)sPos);
	UpdateData(FALSE);
	nY = pos;
	return;
}


BOOL CSetDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_HScrollM.SetScrollRange(3,7);
	m_HScrollN.SetScrollRange(3,7);
	m_HScrollM.SetScrollPos(3);
	m_HScrollN.SetScrollPos(3);
	DisplayEditM(3);
	DisplayEditN(3);
	nX = 3;
	nY = 3;

	m_RadioBotton_Three.SetCheck(TRUE);
	m_RadioBotton_Random.SetCheck(TRUE);
	isRandom = true;
	OnClickedRadioRandom();
	return TRUE;
}

void CSetDialog::OnClickedRadioPre()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	isRandom = false;
	m_RadioBotton_Random.SetCheck(FALSE);
	m_RadioBotton_Three.EnableWindow(TRUE);
	m_RadioBotton_Four.EnableWindow(TRUE);
	m_RadioBotton_Five.EnableWindow(TRUE);
	m_EditM.EnableWindow(FALSE);
	m_EditN.EnableWindow(FALSE);
	m_HScrollM.EnableWindow(FALSE);
	m_HScrollN.EnableWindow(FALSE);
	if (m_RadioBotton_Three.GetCheck())
	{
		nX = nY = 3;
	}
	else if (m_RadioBotton_Four.GetCheck())
	{
		nX = nY = 4;
	}
	else if (m_RadioBotton_Five.GetCheck())
	{
		nX = nY = 5;
	}
}


void CSetDialog::OnClickedRadioRandom()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	isRandom = true;
	m_RadioBotton_Pre.SetCheck(FALSE);
	m_EditM.EnableWindow(TRUE);
	m_EditN.EnableWindow(TRUE);
	m_HScrollM.EnableWindow(TRUE);
	m_HScrollN.EnableWindow(TRUE);
	m_RadioBotton_Three.EnableWindow(FALSE);
	m_RadioBotton_Four.EnableWindow(FALSE);
	m_RadioBotton_Five.EnableWindow(FALSE);
	nX = m_HScrollM.GetScrollPos();
	nY = m_HScrollN.GetScrollPos();
}


void CSetDialog::OnClickedRadioThree()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_RadioBotton_Four.SetCheck(FALSE);
	m_RadioBotton_Five.SetCheck(FALSE);
	nX = 3;
	nY = 3;
}


void CSetDialog::OnClickedRadioFour()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_RadioBotton_Three.SetCheck(FALSE);
	m_RadioBotton_Five.SetCheck(FALSE);
	nX = 4;
	nY = 4;
}


void CSetDialog::OnClickedRadioFive()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_RadioBotton_Three.SetCheck(FALSE);
	m_RadioBotton_Four.SetCheck(FALSE);
	nX = 5;
	nY = 5;
}


void CSetDialog::OnChangeEditm()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�


	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString sTemp = L"";
	int iData;
	m_EditM.GetWindowTextW(sTemp);
	iData = _tstoi( sTemp );// ���壺int iData;
	if (iData<3)
	{
		m_EditM.SetWindowTextW(L"3");
		m_HScrollM.SetScrollPos(3);
		nX = 3;
	}
	else if (iData == 3)
	{
		m_HScrollM.SetScrollPos(3);
		nX = 3;
		return;
	}
	else if (3<iData && iData<7)
	{
		m_HScrollM.SetScrollPos(iData);
		nX = iData;
	}
	else if (iData == 7)
	{
		m_HScrollM.SetScrollPos(7);
		nX = 7;
		return;
	}
	else
	{
		m_EditM.SetWindowTextW(L"7");
		m_HScrollM.SetScrollPos(7);
		nX = 7;
	}

}


void CSetDialog::OnChangeEditn()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�


	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString sTemp = L"";
	int iData;
	m_EditN.GetWindowTextW(sTemp);
	iData = _tstoi( sTemp );// ���壺int iData;
	if (iData<3)
	{
		m_EditN.SetWindowTextW(L"3");
		m_HScrollN.SetScrollPos(3);
		nY = 3;
	}
	else if (iData == 3)
	{
		m_HScrollN.SetScrollPos(3);
		nY = 3;
		return;
	}
	else if (3<iData && iData<7)
	{
		m_HScrollN.SetScrollPos(iData);
		nY = iData;
	}
	else if (iData == 7)
	{
		m_HScrollN.SetScrollPos(7);
		nY = 7;
		return;
	}
	else
	{
		m_EditN.SetWindowTextW(L"7");
		m_HScrollN.SetScrollPos(7);
		nY = 7;
	}
}
