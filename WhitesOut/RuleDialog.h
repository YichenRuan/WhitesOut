#pragma once
#include "afxwin.h"


// CRuleDialog 对话框

class CRuleDialog : public CDialog
{
	DECLARE_DYNAMIC(CRuleDialog)

public:
	CRuleDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRuleDialog();

// 对话框数据
	enum { IDD = IDD_RULEDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_EditR;
	virtual BOOL OnInitDialog();
};
