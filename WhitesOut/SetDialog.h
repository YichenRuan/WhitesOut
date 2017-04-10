#pragma once
#include "afxwin.h"


// CSetDialog 对话框

class CSetDialog : public CDialog
{
	DECLARE_DYNAMIC(CSetDialog)

public:
	CSetDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetDialog();

// 对话框数据
	enum { IDD = IDD_SETDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CScrollBar m_HScrollM;
	CScrollBar m_HScrollN;
	CEdit m_EditM;
	CEdit m_EditN;

private:
	void DisplayEditM(int pos);
	void DisplayEditN(int pos);
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedRadioPre();
	CButton m_RadioBotton_Pre;
	CButton m_RadioBotton_Three;
	CButton m_RadioBotton_Random;
	afx_msg void OnClickedRadioRandom();
	CButton m_RadioBotton_Five;
	CButton m_RadioBotton_Four;
	afx_msg void OnClickedRadioThree();
	afx_msg void OnClickedRadioFour();
	afx_msg void OnClickedRadioFive();


public:
	bool isRandom;
	int nX,nY;
	afx_msg void OnChangeEditm();
	afx_msg void OnChangeEditn();
};
