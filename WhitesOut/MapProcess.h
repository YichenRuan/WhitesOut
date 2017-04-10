#pragma once
#include "WhitesOutDoc.h"
class MapProcess
{
public:
	MapProcess(int Height,int Width);
	~MapProcess(void);
	void DrawMap();
	void UpdateMap(int nX,int nY,bool isRandom,int playState);
	void GetDC(CDC* pDC);
	void Play(CPoint point);
	int IsPlaying();			//0:not yet started, 1:playing, 2:win
	void ReGame();
private:
	int *map;
	CDC* _pDC;
	int _height,_width,_nX,_nY;
	double _oX,_oY,_dX,_dY;
	bool _isRandom;
	static bool _defaultMap[3][9][9];
	bool _presentMap[9][9];
	bool _savedMap[9][9];
	CPen pen; 
	CBrush brush_white,brush_black;
	void GenerateRandomMap();
	int _numBlack;
	void _GetBlackNum();
	int _playState;				//0:not yet started, 1:playing, 2:win
};

