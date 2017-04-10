#pragma once
#include "cwmpplayer4.h"
//#include "CWMPPlayer4.h“


// CDisplayDialog 对话框

class CDisplayDialog : public CDialog
{
	DECLARE_DYNAMIC(CDisplayDialog)

public:
	CDisplayDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDisplayDialog();

// 对话框数据
	enum { IDD = IDD_DISPLAYDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CWMPPlayer4 m_MediaPlayer;
	DECLARE_EVENTSINK_MAP()
	void OnDoubleclickOcx1(short nButton, short nShiftState, long fX, long fY);
};
