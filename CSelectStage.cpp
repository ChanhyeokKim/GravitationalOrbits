#include "CSelectStage.h"
#include "Global.h"
#include "CTitle.h"
#include "CLevelStage.h"
#include "CMainScene.h"
#include "SoundMgr.h"
#include "StageRecord.h"

CSelectStage::CSelectStage(int level){

	GetSoundMgr().AddSound(SOUND_1,"sound/main.wav");
	GetSoundMgr().SetVolume(SOUND_1,10);

	stage = 1;

	bg = new CSpriteSceneNode("image/background.jpg");
	pushSceneNode(-20,bg);

	mouse = new CMouse(true);
	pushSceneNode(0, mouse);
	mouse->mouseFlag=true;

	levels = level;


	bBack = new CSpriteSceneNode("image/button/back.png");
	pushSceneNode(-19,bBack);
	bBack->pos = D3DXVECTOR2(-bBack->width/2.f + 150, -bBack->height/2.f + 680);
	bBack->rect = Rect(0, 0, bBack->width, bBack->height);

	bS1_1 = new CSpriteSceneNode("image/button/1.png");
	pushSceneNode(-18,bS1_1);
	bS1_1->pos = D3DXVECTOR2(-bS1_1->width/2.f + 200, -bS1_1->height/2.f + 200);
	bS1_1->rect = Rect(0, 0, bS1_1->width, bS1_1->height);

	bS1_2 = new CSpriteSceneNode("image/button/2.png");
	pushSceneNode(-17,bS1_2);
	bS1_2->pos = D3DXVECTOR2(-bS1_2->width/2.f + 350, -bS1_2->height/2.f + 150);
	bS1_2->rect = Rect(0, 0, bS1_2->width, bS1_2->height);

	bS1_3 = new CSpriteSceneNode("image/button/3.png");
	pushSceneNode(-16,bS1_3);
	bS1_3->pos = D3DXVECTOR2(-bS1_3->width/2.f + 500, -bS1_3->height/2.f + 200);
	bS1_3->rect = Rect(0, 0, bS1_3->width, bS1_3->height);

	bS1_4 = new CSpriteSceneNode("image/button/4.png");
	pushSceneNode(-15,bS1_4);
	bS1_4->pos = D3DXVECTOR2(-bS1_4->width/2.f + 650, -bS1_4->height/2.f + 150);
	bS1_4->rect = Rect(0, 0, bS1_4->width, bS1_4->height);

	bS1_5 = new CSpriteSceneNode("image/button/5.png");
	pushSceneNode(-14,bS1_5);
	bS1_5->pos = D3DXVECTOR2(-bS1_5->width/2.f + 800, -bS1_5->height/2.f + 200);
	bS1_5->rect = Rect(0, 0, bS1_5->width, bS1_5->height);

	bS1_6 = new CSpriteSceneNode("image/button/6.png");
	pushSceneNode(-13,bS1_6);
	bS1_6->pos = D3DXVECTOR2(-bS1_6->width/2.f + 200, -bS1_6->height/2.f + 450);
	bS1_6->rect = Rect(0, 0, bS1_6->width, bS1_6->height);

	bS1_7 = new CSpriteSceneNode("image/button/7.png");
	pushSceneNode(-12,bS1_7);
	bS1_7->pos = D3DXVECTOR2(-bS1_7->width/2.f + 350, -bS1_7->height/2.f + 400);
	bS1_7->rect = Rect(0, 0, bS1_7->width, bS1_7->height);

	bS1_8 = new CSpriteSceneNode("image/button/8.png");
	pushSceneNode(-11,bS1_8);
	bS1_8->pos = D3DXVECTOR2(-bS1_8->width/2.f + 500, -bS1_8->height/2.f + 450);
	bS1_8->rect = Rect(0, 0, bS1_8->width, bS1_8->height);

	bS1_9 = new CSpriteSceneNode("image/button/9.png");
	pushSceneNode(-10,bS1_9);
	bS1_9->pos = D3DXVECTOR2(-bS1_9->width/2.f + 650, -bS1_9->height/2.f + 400);
	bS1_9->rect = Rect(0, 0, bS1_9->width, bS1_9->height);

	bS1_10 = new CSpriteSceneNode("image/button/10.png");
	pushSceneNode(-9,bS1_10);
	bS1_10->pos = D3DXVECTOR2(-bS1_10->width/2.f + 800, -bS1_10->height/2.f + 450);
	bS1_10->rect = Rect(0, 0, bS1_10->width, bS1_10->height);
}
CSelectStage::~CSelectStage(){

}
void CSelectStage::render(){
	ISceneNode::render();
}
void CSelectStage::update(float eTime){
	ISceneNode::update(eTime);

	
	if(levels == 1)
	{
		if(g_pInputManager->keyState(VK_LBUTTON) == 1 )
		{
			if(colCheck(mouse->pos, bBack->pos, mouse->rect, bBack->rect)){
				g_pSceneManager->changeSceneNode(new CLevelStage());
				return ;
			}
			if(colCheck(mouse->pos, bS1_1->pos, mouse->rect, bS1_1->rect) && ((StageRecord::GetInstance()->GetLevel() >= '1' && StageRecord::GetInstance()->GetstNum() >= '1') || StageRecord::GetInstance()->GetLevel() >= '2')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/1-1.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_2->pos, mouse->rect, bS1_2->rect) && ((StageRecord::GetInstance()->GetLevel() >= '1' && StageRecord::GetInstance()->GetstNum() >= '2') || StageRecord::GetInstance()->GetLevel() >= '2')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/1-2.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_3->pos, mouse->rect, bS1_3->rect) && ((StageRecord::GetInstance()->GetLevel() >= '1' && StageRecord::GetInstance()->GetstNum() >= '3') || StageRecord::GetInstance()->GetLevel() >= '2')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/1-3.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_4->pos, mouse->rect, bS1_4->rect) && ((StageRecord::GetInstance()->GetLevel() >= '1' && StageRecord::GetInstance()->GetstNum() >= '4') || StageRecord::GetInstance()->GetLevel() >= '2')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/1-4.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_5->pos, mouse->rect, bS1_5->rect) && ((StageRecord::GetInstance()->GetLevel() >= '1' && StageRecord::GetInstance()->GetstNum() >= '5') || StageRecord::GetInstance()->GetLevel() >= '2')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/1-5.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_6->pos, mouse->rect, bS1_6->rect) && ((StageRecord::GetInstance()->GetLevel() >= '1' && StageRecord::GetInstance()->GetstNum() >= '6') || StageRecord::GetInstance()->GetLevel() >= '2')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/1-6.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_7->pos, mouse->rect, bS1_7->rect) && ((StageRecord::GetInstance()->GetLevel() >= '1' && StageRecord::GetInstance()->GetstNum() >= '7') || StageRecord::GetInstance()->GetLevel() >= '2')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/1-7.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_8->pos, mouse->rect, bS1_8->rect)  && ((StageRecord::GetInstance()->GetLevel() >= '1' && StageRecord::GetInstance()->GetstNum() >= '8') || StageRecord::GetInstance()->GetLevel() >= '2')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/1-8.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_9->pos, mouse->rect, bS1_9->rect) && ((StageRecord::GetInstance()->GetLevel() >= '1' && StageRecord::GetInstance()->GetstNum() >= '9') || StageRecord::GetInstance()->GetLevel() >= '2')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/1-9.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_10->pos, mouse->rect, bS1_10->rect) && ((StageRecord::GetInstance()->GetLevel() >= '1' && StageRecord::GetInstance()->GetstNum() >= '9'+1) || StageRecord::GetInstance()->GetLevel() >= '2')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/1-T.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
		}
	}
	else if(levels == 2)
	{
		if(g_pInputManager->keyState(VK_LBUTTON) == 1 )
		{
			if(colCheck(mouse->pos, bBack->pos, mouse->rect, bBack->rect)){
				g_pSceneManager->changeSceneNode(new CLevelStage());
				return ;
			}
			if(colCheck(mouse->pos, bS1_1->pos, mouse->rect, bS1_1->rect) && ((StageRecord::GetInstance()->GetLevel() >= '2' && StageRecord::GetInstance()->GetstNum() >= '1') || StageRecord::GetInstance()->GetLevel() >= '3')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/2-1.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_2->pos, mouse->rect, bS1_2->rect) && ((StageRecord::GetInstance()->GetLevel() >= '2' && StageRecord::GetInstance()->GetstNum() >= '2') || StageRecord::GetInstance()->GetLevel() >= '3')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/2-2.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_3->pos, mouse->rect, bS1_3->rect)&& ((StageRecord::GetInstance()->GetLevel() >= '2' && StageRecord::GetInstance()->GetstNum() >= '3') || StageRecord::GetInstance()->GetLevel() >= '3')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/2-3.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_4->pos, mouse->rect, bS1_4->rect)&& ((StageRecord::GetInstance()->GetLevel() >= '2' && StageRecord::GetInstance()->GetstNum() >= '4') || StageRecord::GetInstance()->GetLevel() >= '3')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/2-4.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_5->pos, mouse->rect, bS1_5->rect)&& ((StageRecord::GetInstance()->GetLevel() >= '2' && StageRecord::GetInstance()->GetstNum() >= '5') || StageRecord::GetInstance()->GetLevel() >= '3')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/2-5.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_6->pos, mouse->rect, bS1_6->rect)&& ((StageRecord::GetInstance()->GetLevel() >= '2' && StageRecord::GetInstance()->GetstNum() >= '6') || StageRecord::GetInstance()->GetLevel() >= '3')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/2-6.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_7->pos, mouse->rect, bS1_7->rect) && ((StageRecord::GetInstance()->GetLevel() >= '2' && StageRecord::GetInstance()->GetstNum() >= '7') || StageRecord::GetInstance()->GetLevel() >= '3')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/2-7.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_8->pos, mouse->rect, bS1_8->rect) && ((StageRecord::GetInstance()->GetLevel() >= '2' && StageRecord::GetInstance()->GetstNum() >= '8') || StageRecord::GetInstance()->GetLevel() >= '3')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/2-8.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_9->pos, mouse->rect, bS1_9->rect) && ((StageRecord::GetInstance()->GetLevel() >= '2' && StageRecord::GetInstance()->GetstNum() >= '9') || StageRecord::GetInstance()->GetLevel() >= '3')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/2-9.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_10->pos, mouse->rect, bS1_10->rect) && ((StageRecord::GetInstance()->GetLevel() >= '2' && StageRecord::GetInstance()->GetstNum() >= '9'+1) || StageRecord::GetInstance()->GetLevel() >= '3')){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/2-T.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
		}
	}
	else if(levels == 3)
	{
		if(g_pInputManager->keyState(VK_LBUTTON) == 1 )
		{
			if(colCheck(mouse->pos, bBack->pos, mouse->rect, bBack->rect)){
				g_pSceneManager->changeSceneNode(new CLevelStage());
				return ;
			}
			if(colCheck(mouse->pos, bS1_1->pos, mouse->rect, bS1_1->rect) && StageRecord::GetInstance()->GetLevel() >= '3' && StageRecord::GetInstance()->GetstNum() >= '1'){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/3-1.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_2->pos, mouse->rect, bS1_2->rect) && StageRecord::GetInstance()->GetLevel() >= '3' && StageRecord::GetInstance()->GetstNum() >= '2'){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/3-2.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_3->pos, mouse->rect, bS1_3->rect) && StageRecord::GetInstance()->GetLevel() >= '3' && StageRecord::GetInstance()->GetstNum() >= '3'){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/3-3.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_4->pos, mouse->rect, bS1_4->rect) && StageRecord::GetInstance()->GetLevel() >= '3' && StageRecord::GetInstance()->GetstNum() >= '4'){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/3-4.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_5->pos, mouse->rect, bS1_5->rect) && StageRecord::GetInstance()->GetLevel() >= '3' && StageRecord::GetInstance()->GetstNum() >= '5'){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/3-5.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_6->pos, mouse->rect, bS1_6->rect) && StageRecord::GetInstance()->GetLevel() >= '3' && StageRecord::GetInstance()->GetstNum() >= '6'){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/3-6.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_7->pos, mouse->rect, bS1_7->rect) && StageRecord::GetInstance()->GetLevel() >= '3' && StageRecord::GetInstance()->GetstNum() >= '7'){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/3-7.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_8->pos, mouse->rect, bS1_8->rect) && StageRecord::GetInstance()->GetLevel() >= '3' && StageRecord::GetInstance()->GetstNum() >= '8'){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/3-8.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_9->pos, mouse->rect, bS1_9->rect) && StageRecord::GetInstance()->GetLevel() >= '3' && StageRecord::GetInstance()->GetstNum() >= '9'){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/3-9.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
			if(colCheck(mouse->pos, bS1_10->pos, mouse->rect, bS1_10->rect) && StageRecord::GetInstance()->GetLevel() >= '3' && StageRecord::GetInstance()->GetstNum() >= '9'+1){
				g_pSceneManager->changeSceneNode(new CMainScene("stage/3-T.txt"));
				GetSoundMgr().Playis(SOUND_1);
				return ;
			}
		}
	}
}