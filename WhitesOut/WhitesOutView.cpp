
// WhitesOutView.cpp : CWhitesOutView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "WhitesOut.h"
#endif

#include "WhitesOutDoc.h"
#include "WhitesOutView.h"
#include "SetDialog.h"
#include "RuleDialog.h"
#include "DisplayDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWhitesOutView

IMPLEMENT_DYNCREATE(CWhitesOutView, CView)

BEGIN_MESSAGE_MAP(CWhitesOutView, CView)
	ON_COMMAND(ID_GAME_SETTING, &CWhitesOutView::OnGameSetting)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_GAME_REGAME, &CWhitesOutView::OnGameRegame)
	ON_COMMAND(ID_HELP_RULE, &CWhitesOutView::OnHelpRule)
	ON_COMMAND(ID_HELP_DISPLAY, &CWhitesOutView::OnHelpDisplay)
END_MESSAGE_MAP()

// CWhitesOutView 构造/析构

CWhitesOutView::CWhitesOutView()
{
	// TODO: 在此处添加构造代码
	nX = 3;
	nY = 3;
	isRandom = false;
	isMapInitialized = false;

}

CWhitesOutView::~CWhitesOutView()
{
}

BOOL CWhitesOutView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	return CView::PreCreateWindow(cs);
}

// CWhitesOutView 绘制

void CWhitesOutView::OnDraw(CDC* pDC)
{
	CWhitesOutDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (!isMapInitialized)
	{
		CRect rt;
		GetClientRect(&rt);
		map = new MapProcess(rt.Height(),rt.Width());
		map->UpdateMap(nX,nY,isRandom,0);
		isMapInitialized = true;
	}
	
	if (map->IsPlaying() == 1)
	{	
		pDC->SetWindowOrg(0,0);
		map->GetDC(pDC);
		map->DrawMap();
	}

	else if (map->IsPlaying() == 0)
	{
		CDC dcMemory;                    	// 创建内存缓冲DC
		dcMemory.CreateCompatibleDC(pDC);
		CBitmap bmp1;                   	 // 加载256位图
		bmp1.LoadBitmap(IDB_BITMAP_WEL);
		BITMAP bmpInfo1;
		bmp1.GetBitmap(&bmpInfo1);       // 获得位图的尺寸
		CBitmap* pOldBitmap = dcMemory.SelectObject(&bmp1);
		// 选择位图到内存缓冲设备中
		pDC->BitBlt(45,-10,bmpInfo1.bmWidth,bmpInfo1.bmHeight,
			&dcMemory,0,0,SRCCOPY);
	}

	else if (map->IsPlaying() == 2)
	{
		CDC dcMemory;                    	// 创建内存缓冲DC
		dcMemory.CreateCompatibleDC(pDC);
		CBitmap bmp1;                   	 // 加载256位图
		bmp1.LoadBitmap(IDB_BITMAP_WIN);
		BITMAP bmpInfo1;
		bmp1.GetBitmap(&bmpInfo1);       // 获得位图的尺寸
		CBitmap* pOldBitmap = dcMemory.SelectObject(&bmp1);
		// 选择位图到内存缓冲设备中
		pDC->BitBlt(110,70,bmpInfo1.bmWidth,bmpInfo1.bmHeight,
			&dcMemory,0,0,SRCCOPY);
	}

}


// CWhitesOutView 诊断

#ifdef _DEBUG
void CWhitesOutView::AssertValid() const
{
	CView::AssertValid();
}

void CWhitesOutView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWhitesOutDoc* CWhitesOutView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWhitesOutDoc)));
	return (CWhitesOutDoc*)m_pDocument;
}
#endif //_DEBUG


// CWhitesOutView 消息处理程序


void CWhitesOutView::OnGameSetting()
{
	// TODO: 在此添加命令处理程序代码
	CSetDialog dialog;
	if(dialog.DoModal() == IDOK)   // 如果用户点击OK按钮
	{ 
		nX = dialog.nX;
		nY = dialog.nY;
		isRandom = dialog.isRandom;
		map->UpdateMap(nX,nY,isRandom,1);
		Invalidate();	                		// 强制重绘
	}

}




void CWhitesOutView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	if (map->IsPlaying() == 1)
	{
		map->Play(point);
		Invalidate();
	}
	else
	{
		OnGameSetting();
	}
}


void CWhitesOutView::OnGameRegame()
{
	// TODO: 在此添加命令处理程序代码
	if(map->IsPlaying() != 0)
	{
		map->ReGame();
		Invalidate();
	}
	else
	{
		OnGameSetting();
	}

}


void CWhitesOutView::OnHelpRule()
{
	// TODO: 在此添加命令处理程序代码
	CRuleDialog dialog;
	if(dialog.DoModal() == IDOK)
	{
		return;
	}
}


void CWhitesOutView::OnHelpDisplay()
{
	// TODO: 在此添加命令处理程序代码
	CDisplayDialog dialog;
	if(dialog.DoModal() == IDOK)
	{
		return;
	}
}
