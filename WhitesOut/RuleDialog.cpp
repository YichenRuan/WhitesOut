// RuleDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WhitesOut.h"
#include "RuleDialog.h"
#include "afxdialogex.h"


// CRuleDialog �Ի���

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


// CRuleDialog ��Ϣ�������


BOOL CRuleDialog::OnInitDialog()
{
	CString str = L"     �ص���һ��Ȥζ����ս�Ժ�ǿ��������Ϸ,��Ϸ��ܼ򵥵�ȴ��Ҫ��������ǻ�.\r\n\r\n     ��Ϸ�������£�\r\n     1.��Ϸͼ����ֶ������,ÿ�����ӷֱ����һյ��.�ɷֱ��úڰ���ɫ��ʾ����Ϊ��ƣ���Ϊ����.ÿյ�ƺ��������������ڵĵ����һ������.\r\n     2.����Ϸ��ʼʱ,���м��������,���������Ļ�ϵ�ĳյ�ƿɽ������������������ڷ���ĵ���򿪻�ر�.\r\n     3.��Ϸ��һ�����еĵƾ��ص�,��˳������,��ʱ�����Ļ�������ͼ����.\r\n     4.���������Ϸ���в�����ĵط������Ե�������˵��µ���ʾѡ��ۿ���ʾ����.\r\n\r\n     ף����Ŀ��ģ�";
	CDialog::OnInitDialog();
	m_EditR.SetWindowTextW(str);
	return TRUE;
}
