#include "CPlayer.h"
#include "Global.h"
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

CPlayer::CPlayer(void)
{
	a = new CSpriteSceneNode("image/2.png");
	a->pos = D3DXVECTOR2(-a->width/2.f, -a->height/2.f);
	pushSceneNode(1,a);
	rotCenter = D3DXVECTOR2(0, 0);

	ON = false;
}

CPlayer::~CPlayer(void)
{
}

void CPlayer::render(){
	ISceneNode::render();
}

void CPlayer::update(float eTime){
	ISceneNode::update(eTime);
	if(!pauseOn)
	{
		//ON / OFF 플래그
		if(!ON)
		{
			ON = true;
			vX=0;
			vY=0;
		}

		pos.x += vX;
		pos.y += vY;
	}

	

}

void CPlayer::gravity(float Px, float Py, float pWidth, float gWidth, int flagX, int flagY, int flagZ){
	if(!pauseOn)
	{
		if(pow(( pos.x - Px),2) + pow(( pos.y - Py),2) <= pow( (( a->width/2) + (gWidth/2)),2 ))
		{
			//중력(끌어당기는 값)
			if((Px <=  pos.x && Py <=  pos.y) || (Px >=  pos.x && Py >=  pos.y))
			{
				if(flagY)
				{
				 vY-=Sin( pos.x , Px,  pos.y, Py ) / 15;
				 vX-=Cos( pos.x , Px,  pos.y, Py ) / 15;
				}
				else
				{
				 vY+=Sin( pos.x , Px,  pos.y, Py ) / 15;
				 vX+=Cos( pos.x , Px,  pos.y, Py ) / 15;
				}
			}
			else
			{
				if(flagY)
				{
				 vY-=-Sin( pos.x , Px,  pos.y, Py) / 15;
				 vX-=-Cos( pos.x , Px,  pos.y, Py) / 15;
				}
				else
				{
				 vY+=-Sin( pos.x , Px,  pos.y, Py) / 15;
				 vX+=-Cos( pos.x , Px,  pos.y, Py) / 15;
				}
			}
			//충돌 처리
			if(pow(( pos.x - Px),2) + pow(( pos.y - Py),2) <= pow( (( a->width / 2) + (pWidth / 2)),2) )
			{
				tX =  pos.x;
				tY =  pos.y;
				tvX =  vX;
				tvY =  vY;

				temp = tvX;
				tvX = -tvY;
				tvY = -temp;
				
				tX += 2*tvX;
				tY += 2*tvY;
				if(flagX == 1)
				{
					failCall = true;
					vX = 0;
					vY = 0;
					tX = 0;
					tY = 0;
				}

				if( pow((tX - Px), 2)+pow((tY - Py), 2) <= pow( (( a->width / 2) + (pWidth / 2)),2 ) || plma(tX, vX,tY, vY) )
				{
					tX =  pos.x;
					tY =  pos.y;
					tvX =  vX;
					tvY =  vY;

					temp = tvX;
					tvX = -tvY;
					tvY = temp;

					tX += 2*tvX;
					tY += 2*tvY;
					if(flagX == 1)
					{
						failCall = true;
						vX = 0;
						vY = 0;
						tX = 0;
						tY = 0;
					}

					if( pow((tX - Px),2) + pow((tY - Py),2) <= pow( (( a->width / 2) + (pWidth / 2)),2 ) || plma(tX, vX,tY, vY) )
					{
						tX =  pos.x;
						tY =  pos.y;
						tvX =  vX;
						tvY =  vY;

						temp = tvX;
						 vX = tvY;
						 vY = -temp;

						tX += 2*tvX;
						tY += 2*tvY;
						if(flagX == 1)
						{
							failCall = true;
							vX = 0;
							vY = 0;
							tX = 0;
							tY = 0;
						}
						if( pow((tX - Px),2) + pow((tY - Py),2) <= pow( (( a->width / 2) + (pWidth / 2)),2 ) || plma(tX, vX,tY, vY) )
						{
							tX =  pos.x;
							tY =  pos.y;
							tvX =  vX;
							tvY =  vY;

							temp = tvX;
							 vX = tvY;
							 vY = temp;

							 vX = tvX * 0.9;
							 vY = tvY * 0.9;
							 if(flagX == 1)
							 {
								 failCall = true;
								 vX = 0;
								 vY = 0;
								 tX = 0;
								 tY = 0;
							 }
						}
						else
						{
							 vX = tvX * 0.9;
							 vY = tvY * 0.9;
						}
					}
					else
					{
						 vX = tvX * 0.9;
						 vY = tvY * 0.9;
					}
				}
				else
				{
					 vX = tvX * 0.9;
					 vY = tvY * 0.9;
				}
				 vX-= vX/(TryLength( pos.x , Px,  pos.y, Py)*0.85+(( vX/(TryLength( pos.x , Px,  pos.y, Py))/100000000)));
				 vY-= vY/(TryLength( pos.x , Px,  pos.y, Py)*0.85+(( vY/(TryLength( pos.x , Px,  pos.y, Py))/100000000)));
			}
			else
			{
				vX-= vX/(TryLength( pos.x , Px,  pos.y, Py)*0.85+(( vX/(TryLength( pos.x , Px,  pos.y, Py))/100000000)));
				vY-= vY/(TryLength( pos.x , Px,  pos.y, Py)*0.85+(( vY/(TryLength( pos.x , Px,  pos.y, Py))/100000000)));
				if((absF( vX) <= 0.4 && absF( vY) <= 0.4) && pow(( pos.x - Px),2) + pow(( pos.y - Py),2) <= pow( (( a->width / 2) + (pWidth / 2)+0.5),2 ))
				{
					 vX = 0;
					 vY = 0;
				}
			}
		}
	}
}
void CPlayer::move(float mX, float mY, float mWidth){
	if(pow(( pos.x - mX),2) + pow(( pos.y - mY),2) <= pow( (( a->width/2) + (mWidth/2)),2 ))
	{
		if((mX <=  pos.x && mY <=  pos.y) || (mX >=  pos.x && mY >=  pos.y))
		{
			 vY+=-Sin( pos.x , mX,  pos.y, mY) * 7;
			 vX+=-Cos( pos.x , mX,  pos.y, mY) * 7;
		}
		else
		{
			 vY+=Sin( pos.x , mX,  pos.y, mY) * 7;
			 vX+=Cos( pos.x , mX,  pos.y, mY) * 7;
		}
	}
}
int CPlayer::clearCheck(float arrX, float arrY, float arrGWidth)
{
	if(pow(( pos.x - arrX),2) + pow(( pos.y - arrY),2) <= pow( (( a->width/2) + (arrGWidth/2)),2 ))
		return 1;
	return 0;
}