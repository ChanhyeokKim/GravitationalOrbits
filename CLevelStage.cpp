#include "CLevelStage.h"
#include "Global.h"
#include "CTitle.h"
#include "CSelectStage.h"
#include "CMouse.h"
#include <windows.h>
#include <string.h>

CLevelStage::CLevelStage(){
	
	bg = new CSpriteSceneNode("image/background.jpg");
	pushSceneNode(-20,bg);

	mouse = new CMouse(true);
	pushSceneNode(1, mouse);
	mouse->mouseFlag=true;

	bBack = new CSpriteSceneNode("image/button/back.png");
	pushSceneNode(-16,bBack);
	bBack->pos = D3DXVECTOR2(-bBack->width/2.f + 100, -bBack->height/2.f + 700);
	bBack->rect = Rect(0, 0, bBack->width, bBack->height);

	easy = new CSpriteSceneNode("image/button/easy.png");
	pushSceneNode(-19,easy);
	easy->pos = D3DXVECTOR2(-easy->width/2.f + 245, -easy->height/2.f + 350);
	
	normal = new CSpriteSceneNode("image/button/normal.png");
	pushSceneNode(-18,normal);
	normal->pos = D3DXVECTOR2(-normal->width/2.f + 550, -normal->height/2.f + 450);

	hard = new CSpriteSceneNode("image/button/hard.png");
	pushSceneNode(-17,hard);
	hard->pos = D3DXVECTOR2(-hard->width/2.f + 855, -hard->height/2.f + 360);

}
CLevelStage::~CLevelStage(){

}
void CLevelStage::render(){
	ISceneNode::render();
}
void CLevelStage::update(float eTime){
	ISceneNode::update(eTime);

	if(g_pInputManager->keyState(VK_LBUTTON) == 1 )
	{
		if(colCheck(mouse->pos, bBack->pos, mouse->rect, bBack->rect)){
				g_pSceneManager->changeSceneNode(new CTitle());
				return ;
		}
		if(pow(mouse->pos.x - (easy->pos.x + easy->width/2 ),2) + pow(mouse->pos.y - (easy->pos.y + easy->width/2 ),2) <= pow(easy->width/2,2) )
		{
			g_pSceneManager->changeSceneNode(new CSelectStage(1));
			return ;
		}
		if(pow(mouse->pos.x - (normal->pos.x + normal->width/2 ),2) + pow(mouse->pos.y - (normal->pos.y + normal->width/2 ),2) <= pow(normal->width/2,2) )
		{
			g_pSceneManager->changeSceneNode(new CSelectStage(2));
			return ;
		}
		if(pow(mouse->pos.x - (hard->pos.x + hard->width/2 ),2) + pow(mouse->pos.y - (hard->pos.y + hard->width/2 ),2) <= pow(hard->width/2,2) )
		{
			g_pSceneManager->changeSceneNode(new CSelectStage(3));
			return ;
		}
	}
}