// RuleDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "WhitesOut.h"
#include "RuleDialog.h"
#include "afxdialogex.h"


// CRuleDialog 对话框

IMPLEMENT_DYNAMIC(CRuleDialog, CDialog)

CRuleDialog::CRuleDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CRuleDialog::IDD, pParent)
{
}

CRuleDialog::~CRuleDialog()
{
}

void CRuleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_RULE, m_EditR);
}


BEGIN_MESSAGE_MAP(CRuleDialog, CDialog)
END_MESSAGE_MAP()


// CRuleDialog 消息处理程序


BOOL CRuleDialog::OnInitDialog()
{
	CString str = L"     关灯是一款趣味和挑战性很强益智类游戏,游戏规很简单但却需要考验你的智慧.\r\n\r\n     游戏规则如下：\r\n     1.游戏图面呈现多个格子,每个格子分别代表一盏灯.可分别用黑白两色表示，黑为灭灯，白为亮灯.每盏灯和其上下左右相邻的灯组成一个灯组.\r\n     2.当游戏开始时,会有几个灯组打开,用鼠标点击屏幕上的某盏灯可将它和其上下左右相邻方向的灯组打开或关闭.\r\n     3.游戏中一旦所有的灯均关掉,即顺利过关,此时点击屏幕将进入地图设置.\r\n     4.如果您对游戏还有不清楚的地方，可以点击帮助菜单下的演示选项观看演示动画.\r\n\r\n     祝您玩的开心！";
	CDialog::OnInitDialog();
	m_EditR.SetWindowTextW(str);
	return TRUE;
}
