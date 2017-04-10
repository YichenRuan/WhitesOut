
// WhitesOutView.cpp : CWhitesOutView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CWhitesOutView ����/����

CWhitesOutView::CWhitesOutView()
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	return CView::PreCreateWindow(cs);
}

// CWhitesOutView ����

void CWhitesOutView::OnDraw(CDC* pDC)
{
	CWhitesOutDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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
		CDC dcMemory;                    	// �����ڴ滺��DC
		dcMemory.CreateCompatibleDC(pDC);
		CBitmap bmp1;                   	 // ����256λͼ
		bmp1.LoadBitmap(IDB_BITMAP_WEL);
		BITMAP bmpInfo1;
		bmp1.GetBitmap(&bmpInfo1);       // ���λͼ�ĳߴ�
		CBitmap* pOldBitmap = dcMemory.SelectObject(&bmp1);
		// ѡ��λͼ���ڴ滺���豸��
		pDC->BitBlt(45,-10,bmpInfo1.bmWidth,bmpInfo1.bmHeight,
			&dcMemory,0,0,SRCCOPY);
	}

	else if (map->IsPlaying() == 2)
	{
		CDC dcMemory;                    	// �����ڴ滺��DC
		dcMemory.CreateCompatibleDC(pDC);
		CBitmap bmp1;                   	 // ����256λͼ
		bmp1.LoadBitmap(IDB_BITMAP_WIN);
		BITMAP bmpInfo1;
		bmp1.GetBitmap(&bmpInfo1);       // ���λͼ�ĳߴ�
		CBitmap* pOldBitmap = dcMemory.SelectObject(&bmp1);
		// ѡ��λͼ���ڴ滺���豸��
		pDC->BitBlt(110,70,bmpInfo1.bmWidth,bmpInfo1.bmHeight,
			&dcMemory,0,0,SRCCOPY);
	}

}


// CWhitesOutView ���

#ifdef _DEBUG
void CWhitesOutView::AssertValid() const
{
	CView::AssertValid();
}

void CWhitesOutView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWhitesOutDoc* CWhitesOutView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWhitesOutDoc)));
	return (CWhitesOutDoc*)m_pDocument;
}
#endif //_DEBUG


// CWhitesOutView ��Ϣ�������


void CWhitesOutView::OnGameSetting()
{
	// TODO: �ڴ���������������
	CSetDialog dialog;
	if(dialog.DoModal() == IDOK)   // ����û����OK��ť
	{ 
		nX = dialog.nX;
		nY = dialog.nY;
		isRandom = dialog.isRandom;
		map->UpdateMap(nX,nY,isRandom,1);
		Invalidate();	                		// ǿ���ػ�
	}

}




void CWhitesOutView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
	CRuleDialog dialog;
	if(dialog.DoModal() == IDOK)
	{
		return;
	}
}


void CWhitesOutView::OnHelpDisplay()
{
	// TODO: �ڴ���������������
	CDisplayDialog dialog;
	if(dialog.DoModal() == IDOK)
	{
		return;
	}
}
