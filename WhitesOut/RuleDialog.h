#pragma once
#include "afxwin.h"


// CRuleDialog �Ի���

class CRuleDialog : public CDialog
{
	DECLARE_DYNAMIC(CRuleDialog)

public:
	CRuleDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRuleDialog();

// �Ի�������
	enum { IDD = IDD_RULEDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_EditR;
	virtual BOOL OnInitDialog();
};
