#include "stdafx.h"
#include "MapProcess.h"


MapProcess::MapProcess(int Height,int Width)
	:_height(Height),_width(Width)
{
		pen.CreatePen(PS_SOLID, 3, RGB(128,128,128));			//Grey
		brush_white.CreateSolidBrush(RGB(255,255,255));			//White
		brush_black.CreateSolidBrush(RGB(0,0,0));				//Black
		_oX = _oY = 0;
};

MapProcess::~MapProcess(void)
{
}


void MapProcess::GetDC(CDC* pDC)
{
	_pDC = pDC;
}

void MapProcess::UpdateMap(int nX,int nY,bool isRandom,int playState){
	_nX = nX;
	_nY = nY;
	_isRandom = isRandom;
	_playState = playState;
	_dX = _width/_nX;
	_dY = _height/_nY;
	_numBlack = 1;
	if (!_isRandom)
	{
		for (int i=0;i<9;++i)
		{
			for (int j=0;j<9;++j)
			{
				_savedMap[i][j]=_presentMap[i][j] = _defaultMap[_nX-3][i][j];
			}
		}
	}
	else
	{
		GenerateRandomMap();
	}

}

void MapProcess::DrawMap()
{
	if (_playState == 1)
	{
		_pDC->SelectObject(pen);
		for (int i=1;i<=_nX;++i)
		{
			for (int j=1;j<=_nY;++j)
			{
				if (_presentMap[i][j])
				{
					_pDC->SelectObject(brush_white);
					_pDC->Rectangle(_oX+(i-1)*_dX,_oY+(j-1)*_dY,_oX+i*_dX,_oY+j*_dY);	
				}
				else
				{
					_pDC->SelectObject(brush_black);
					_pDC->Rectangle(_oX+(i-1)*_dX,_oY+(j-1)*_dY,_oX+i*_dX,_oY+j*_dY);
				}
			}
		}
	}
	else if (_playState == 2)
	{
		CString str = L"You Win!";
		_pDC->TextOutW(_width/2,_height/2,str);
	}
}

bool MapProcess::_defaultMap[3][9][9]={
	{0,0,0,0,0,0,0,0,0,
	 0,0,1,0,0,0,0,0,0,
	 0,1,1,1,0,0,0,0,0,
	 0,1,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0},

	{0,0,0,0,0,0,0,0,0,
	 0,1,1,1,0,0,0,0,0,
	 0,1,1,1,1,0,0,0,0,
	 0,0,0,0,1,0,0,0,0,
	 0,0,1,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0},

	{0,0,0,0,0,0,0,0,0,
	 0,1,1,0,1,1,0,0,0,
	 0,1,0,1,0,1,0,0,0,
	 0,0,1,1,1,0,0,0,0,
	 0,1,0,1,0,1,0,0,0,
	 0,1,1,0,1,1,0,0,0,
	 0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0}
};


void MapProcess::GenerateRandomMap()
{
	srand( (unsigned)time( NULL ) );
	for (int i=0;i<9;++i)
	{
		for (int j=0;j<9;++j)
		{
			_savedMap[i][j] = _presentMap[i][j] = rand()%2;
		}
	}
}

void MapProcess::Play(CPoint point)
{
	_numBlack = 0;
	int nx = point.x/_dX + 1;
	int ny = point.y/_dY + 1;
	_presentMap[nx][ny] = !_presentMap[nx][ny];
	_presentMap[nx+1][ny] = !_presentMap[nx+1][ny];
	_presentMap[nx-1][ny] = !_presentMap[nx-1][ny];
	_presentMap[nx][ny+1] = !_presentMap[nx][ny+1];
	_presentMap[nx][ny-1] = !_presentMap[nx][ny-1];
	_GetBlackNum();
	
}

int MapProcess::IsPlaying()
{
	return _playState;
}

void MapProcess::ReGame()
{
	for (int i=0;i<9;++i)
	{
		for (int j=0;j<9;++j)
		{
			_presentMap[i][j] = _savedMap[i][j];
		}
	}
	_playState = 1;
}

void MapProcess::_GetBlackNum()
{
	for (int i=1;i<=_nX;++i)
	{
		for (int j=1;j<=_nY;++j)
		{
			if (!_presentMap[i][j])
			{
				++_numBlack;
			}
		}
	}

	if (_numBlack == 0)
	{
		_playState = 2;
	}
}