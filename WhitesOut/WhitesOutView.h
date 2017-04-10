
// WhitesOutView.h : CWhitesOutView 类的接口
//

#pragma once
#include "MapProcess.h"


class CWhitesOutView : public CView
{
protected: // 仅从序列化创建
	CWhitesOutView();
	DECLARE_DYNCREATE(CWhitesOutView)

// 特性
public:
	CWhitesOutDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWhitesOutView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // WhitesOutView.cpp 中的调试版本
inline CWhitesOutDoc* CWhitesOutView::GetDocument() const
   { return reinterpret_cast<CWhitesOutDoc*>(m_pDocument); }
#endif

