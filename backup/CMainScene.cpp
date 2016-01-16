#include "CMainScene.h"
#include "Global.h"
#include <math.h>

CMainScene::CMainScene(){
	
	background = new CSpriteSceneNode("image/background.png");
	pushSceneNode(-10,background);

	a = new CPlayer();

	a->pos = D3DXVECTOR2(700, 320+a->GetHeight());
	pushSceneNode(1,a);

	//A = new CPlayer();

	//A->pos = D3DXVECTOR2(100,600);
	//pushSceneNode(10,A);

	P = new CPlanet();

	P->pos = D3DXVECTOR2(500, 310);
	pushSceneNode(0,P);

	G = new CGravity();

	G->pos = D3DXVECTOR2(P->pos.x, P->pos.y);
	pushSceneNode(-1,G);
}

CMainScene::~CMainScene(){
}

void CMainScene::render(){
	ISceneNode::render();
	
}

float GetTX( float x1, float x2, float y1, float y2 )
{
	if((x2 <= x1 && y2 <= y1) || (x2 >= x1 && y2 >= y1))
	{
		return x2 - x1;
	}
	else
		return x1 - x2;
}

float GetTY( float y1, float y2, float x1, float x2 )
{
	if((x2 <= x1 && y2 <= y1) || (x2 >= x1 && y2 >= y1))
	{
		return y2 - y1;
	}
	else
		return y1 - y2;
}

float TryLength( float x1, float x2, float y1, float y2 )
{
	return sqrt(pow((x1-x2), 2) + pow((y1-y2),2));
}

float Sin( float x1, float x2, float y1, float y2 )
{
	float x , y , r;
	x = GetTX(x1,x2,y1,y2);
	y = GetTY(y1,y2,x1,x2);
	r = sqrt( pow(x,2) + pow(y,2) );

	if(!x)
	{
		if(y1>y2)
			return -1;
		else
			return 1;
	}
	else if(!y)
		return 0;

	return y/r;
}

float Cos( float x1, float x2, float y1, float y2 )
{
	float x , y , r;
	x = GetTX(x1,x2,y1,y2);
	y = GetTY(y1,y2,x1,x2);
	r = sqrt( pow(x, 2) + pow(y,2) );

	if(!y)
	{
		if(x1>x2)
			return -1;
		else
			return 1;
	}
	else if(!x)
		return 0;

	return x/r;
}

float absF( float a )
{
	if(a<0)
		return -a;
	else
		return a;
}

float plma( float a, float b, float c, float d )
{
	if( ((a >= 0 && b <= 0) || (a <= 0 && b >= 0)) && ((c >= 0 && d <= 0) || (c <= 0 && d >= 0)) )
		return 1;
	else
		return 0;
}
/*
수정내역
1. pows함수 math의 pow함수로 대체 pows제거
2. bool ON Player로 이동
3. if(!ON) Player로 이동
4. 이동조건문 Player로 이동
*/
void CMainScene::update(float eTime){
	ISceneNode::update(eTime);
	float temp, tX, tY, tvX, tvY;
	

	if(pow((a->pos.x-P->pos.x),2)+pow((a->pos.y-P->pos.y),2) <= pow( ((a->GetWidth()/2)+(P->GetWidth()/2)+60),2 ))
	{
		if((P->pos.x <= a->pos.x && P->pos.y <= a->pos.y) || (P->pos.x >= a->pos.x && P->pos.y >= a->pos.y))
		{
			a->vY+=Sin(a->pos.x , P->pos.x, a->pos.y, P->pos.y) / 15;
			a->vX+=Cos(a->pos.x , P->pos.x, a->pos.y, P->pos.y) / 15;
		}
		else
		{
			a->vY+=-Sin(a->pos.x , P->pos.x, a->pos.y, P->pos.y) / 15;
			a->vX+=-Cos(a->pos.x , P->pos.x, a->pos.y, P->pos.y) / 15;
		}
		if(pow((a->pos.x - P->pos.x),2) + pow((a->pos.y - P->pos.y),2) <= pow( ((a->GetWidth() / 2) + (P->GetWidth() / 2)),2) )
		{
			printf("a\n");
			tX = a->pos.x;
			tY = a->pos.y;
			tvX = a->vX;
			tvY = a->vY;

			temp = tvX;
			tvX = -tvY;
			tvY = -temp;
			
			tX += 2*tvX;
			tY += 2*tvY;

			if( pow((tX - P->pos.x), 2)+pow((tY - P->pos.y), 2) <= pow( ((a->GetWidth() / 2) + (P->GetWidth() / 2)),2 ) || plma(tX,a->vX,tY,a->vY) )
			{
				printf("s\n");
				tX = a->pos.x;
				tY = a->pos.y;
				tvX = a->vX;
				tvY = a->vY;

				temp = tvX;
				tvX = -tvY;
				tvY = temp;

				tX += 2*tvX;
				tY += 2*tvY;

				if( pow((tX - P->pos.x),2) + pow((tY - P->pos.y),2) <= pow( ((a->GetWidth() / 2) + (P->GetWidth() / 2)),2 ) || plma(tX,a->vX,tY,a->vY) )
				{
					printf("d\n");
					tX = a->pos.x;
					tY = a->pos.y;
					tvX = a->vX;
					tvY = a->vY;

					temp = tvX;
					a->vX = tvY;
					a->vY = -temp;

					tX += 2*tvX;
					tY += 2*tvY;
					if( pow((tX - P->pos.x),2) + pow((tY - P->pos.y),2) <= pow( ((a->GetWidth() / 2) + (P->GetWidth() / 2)),2 ) || plma(tX,a->vX,tY,a->vY) )
					{
						printf("f\n");
						tX = a->pos.x;
						tY = a->pos.y;
						tvX = a->vX;
						tvY = a->vY;

						temp = tvX;
						a->vX = tvY;
						a->vY = temp;

						a->vX = tvX;
						a->vY = tvY;
					}
					else
					{
						a->vX = tvX;
						a->vY = tvY;
					}
				}
				else
				{
					a->vX = tvX;
					a->vY = tvY;
				}
			}
			else
			{
				a->vX = tvX;
				a->vY = tvY;
			}
			a->vX-=a->vX/(TryLength(a->pos.x , P->pos.x, a->pos.y, P->pos.y)*0.85+((a->vX/(TryLength(a->pos.x , P->pos.x, a->pos.y, P->pos.y))/100000000)));
			a->vY-=a->vY/(TryLength(a->pos.x , P->pos.x, a->pos.y, P->pos.y)*0.85+((a->vY/(TryLength(a->pos.x , P->pos.x, a->pos.y, P->pos.y))/100000000)));
			
		}
		else
		{
			a->vX-=a->vX/(TryLength(a->pos.x , P->pos.x, a->pos.y, P->pos.y)*0.85+((a->vX/(TryLength(a->pos.x , P->pos.x, a->pos.y, P->pos.y))/100000000)));
			a->vY-=a->vY/(TryLength(a->pos.x , P->pos.x, a->pos.y, P->pos.y)*0.85+((a->vY/(TryLength(a->pos.x , P->pos.x, a->pos.y, P->pos.y))/100000000)));
			if((absF(a->vX) <= 0.4 && absF(a->vY) <= 0.4) && pow((a->pos.x - P->pos.x),2) + pow((a->pos.y - P->pos.y),2) <= pow( ((a->GetWidth() / 2) + (P->GetWidth() / 2)+0.5),2 ))
			{
				a->vX = 0;
				a->vY = 0;
			}
		}
	}


	 
}
