#pragma once
#include "cwmpplayer4.h"
//#include "CWMPPlayer4.h��


// CDisplayDialog �Ի���

class CDisplayDialog : public CDialog
{
	DECLARE_DYNAMIC(CDisplayDialog)

public:
	CDisplayDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDisplayDialog();

// �Ի�������
	enum { IDD = IDD_DISPLAYDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CWMPPlayer4 m_MediaPlayer;
	DECLARE_EVENTSINK_MAP()
	void OnDoubleclickOcx1(short nButton, short nShiftState, long fX, long fY);
};
