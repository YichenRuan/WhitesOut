
// WhitesOutView.h : CWhitesOutView ��Ľӿ�
//

#pragma once
#include "MapProcess.h"


class CWhitesOutView : public CView
{
protected: // �������л�����
	CWhitesOutView();
	DECLARE_DYNCREATE(CWhitesOutView)

// ����
public:
	CWhitesOutDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CWhitesOutView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnGameSetting();

private:
	int nX,nY;
	bool isRandom;
	MapProcess *map;
	bool isMapInitialized;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnGameRegame();
	afx_msg void OnHelpRule();
	afx_msg void OnHelpDisplay();
};

#ifndef _DEBUG  // WhitesOutView.cpp �еĵ��԰汾
inline CWhitesOutDoc* CWhitesOutView::GetDocument() const
   { return reinterpret_cast<CWhitesOutDoc*>(m_pDocument); }
#endif

