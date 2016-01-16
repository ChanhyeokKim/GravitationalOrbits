#include "CPlayer.h"
#include "Global.h"

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
	//ON / OFF 플래그
	if(!ON)
	{
		ON = true;
		vX=-3;
		vY=0;
	}
	//이동
	if(g_pInputManager->keyState('D') > 0){
		vX += 0.1;
	}
	if(g_pInputManager->keyState('A') > 0 ){
		vX -= 0.1;
	}
	if(g_pInputManager->keyState('W') > 0){
		vY -= 0.1;
	}
	if(g_pInputManager->keyState('S') > 0 ){
		vY += 0.1;
	}
	if(g_pInputManager->keyState(VK_SPACE) > 0 ){
		vX = -5;
		vY = 0;
	}

	pos.x += vX;
	pos.y += vY;

}