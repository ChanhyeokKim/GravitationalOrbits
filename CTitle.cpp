#include "CTitle.h"
#include "Global.h"
#include "CLevelStage.h"
#include "SoundMgr.h"


CTitle::CTitle(){

	bg = new CSpriteSceneNode("image/mainback/w.png");
	pushSceneNode(-10,bg);

	mouse = new CMouse(true);
	pushSceneNode(100, mouse);
	mouse->mouseFlag = true;

	bStart = new CSpriteSceneNode("image/button/start.png");
	pushSceneNode(-9,bStart);
	bStart->pos = D3DXVECTOR2(-bStart->width/2.f + 460, -bStart->height/2.f + 646);
	bStart->rect = Rect(0, 0, bStart->width, bStart->height);

	bGuide = new CSpriteSceneNode("image/button/guide.png");
	pushSceneNode(-8,bGuide);
	bGuide->pos = D3DXVECTOR2(-bGuide->width/2.f + 660, -bGuide->height/2.f + 646);
	bGuide->rect = Rect(0, 0, bGuide->width, bGuide->height);

	bEnd = new CSpriteSceneNode("image/button/end1.png");
	pushSceneNode(-7,bEnd);
	bEnd->pos = D3DXVECTOR2(-bEnd->width/2.f + 860, -bEnd->height/2.f + 646);
	bEnd->rect = Rect(0, 0, bEnd->width, bEnd->height);
	
	Guide = new CSpriteSceneNode("image/guide.png");
	pushSceneNode(99,Guide);
	Guide->pos = D3DXVECTOR2(1024,768);

	GetSoundMgr().AddSound(SOUND_1,"sound/title.mp3");
}
CTitle::~CTitle(){

}
void CTitle::render(){
	ISceneNode::render();

}
void CTitle::update(float eTime){
	ISceneNode::update(eTime);

	GetSoundMgr().Playis(SOUND_1);
	if(g_pInputManager->keyState(VK_LBUTTON) == 1)
	{
		Guide->pos = D3DXVECTOR2(1024,768);
	}
	if(g_pInputManager->keyState(VK_LBUTTON) == 1 && colCheck(mouse->pos, bStart->pos, mouse->rect, bStart->rect))
	{
		GetSoundMgr().Stop(SOUND_1);
		g_pSceneManager->changeSceneNode(new CLevelStage());
		return ;
	}
	if(g_pInputManager->keyState(VK_LBUTTON) == 1 && colCheck(mouse->pos, bGuide->pos, mouse->rect, bGuide->rect))
	{
		Guide->pos = D3DXVECTOR2(0,0);
	}
	if(g_pInputManager->keyState(VK_LBUTTON) == 1 && colCheck(mouse->pos, bEnd->pos, mouse->rect, bEnd->rect))
	{
		PostQuitMessage(0);
	}
	
}