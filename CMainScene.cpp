#include "CLevelStage.h"
#include "SoundMgr.h"
#include "StageRecord.h"
#include "CMainScene.h"
#include "Global.h"
#include "CSelectStage.h"
#include "SoundMgr.h"
#include "CLevelStage.h"
#include <windows.h>
#include <time.h>
#include <string.h>
#include "stageRecord.h"
#include "CTitle.h"
#include "ISceneNode.h"

CMainScene::CMainScene(char* fileName)
{
	GetSoundMgr().AddSound(SOUND_2,"sound/boom.wav");
	GetSoundMgr().Stop(SOUND_2);

	fail = false;

	clecle =false;
	if(fileName == "stage/3-T.txt")
	{
		clecle = true;
	}

	//배경 초기화
	if(*( fileName + 6 ) == '1')
		background = new CSpriteSceneNode("image/background.jpg");
	else if(*( fileName + 6 ) == '2')
		background = new CSpriteSceneNode("image/background2.png");
	else if(*( fileName + 6 ) == '3')
		background = new CSpriteSceneNode("image/background3.png");
	pushSceneNode(-10,background);

	//일시정지 버튼 초기화
	pauseBtn = new CSpriteSceneNode("image/button/pause.png");
	pushSceneNode(499, pauseBtn);
	pauseBtn->pos = D3DXVECTOR2(0,718);
	pauseOn = false;

	//스테이지 클리어창 초기화
	clearWin = new CSpriteSceneNode("image/ui/clears.png");
	pushSceneNode(552, clearWin);
	clearWin->pos = D3DXVECTOR2(512-clearWin->width/2, 354-clearWin->height/2);
	clearWin->visible = false;

	//스테이지 탈락 창 초기화
	failWin = new CSpriteSceneNode("image/ui/fails.png");
	pushSceneNode(551, failWin);
	failWin->pos = D3DXVECTOR2(512-failWin->width/2, 354-failWin->height/2);
	failWin->visible = false;

	//일시정지 창 초기화
	pauseWin = new CSpriteSceneNode("image/ui/pauses.png");
	pushSceneNode(550, pauseWin);
	pauseWin->pos = D3DXVECTOR2(512-pauseWin->width/2, 320-pauseWin->height/2);
	pauseWin->visible = false;

	//다시시작 버튼 초기화
	retry = new CSpriteSceneNode("image/button/retry.png");
	pushSceneNode(553, retry);
	retry->visible = false;

	//스테이지선택 버튼 초기화
	selectScene = new CSpriteSceneNode("image/button/menu.png");
	pushSceneNode(554, selectScene);
	selectScene->pos = D3DXVECTOR2(selectScene->width,0);
	selectScene->visible = false;

	//계속버튼 초기화
	conBtn = new CSpriteSceneNode("image/button/go.png");
	pushSceneNode(555, conBtn);
	conBtn->visible = false;

	//다음시작 버튼 초기화
	//next = new CSpriteSceneNode("image/button/next.png");
	//pushSceneNode(502, next);
	//next->pos = D3DXVECTOR2(790, 600);

	ptStar = new CParticleSceneNode(10.f,0.05f,1000.f,1.f,0.5f,D3DCOLOR_ARGB(255,255,255,255),D3DCOLOR_ARGB(90,255,255,255),0.f,50000.f,2000.f);
	ptStar->pushParticle("image/particle/ptStar.png");
	ptStar->pos = D3DXVECTOR2(0,10);
	pushSceneNode(-9,ptStar);
	//추진력 파티클 초기화
	ptFire = new CParticleSceneNode(0.5f,0.002f,10000.f,2.f,4.f,D3DCOLOR_ARGB(255,255,220,50),D3DCOLOR_ARGB(90,255,0,0),100.f,3000.f,1.f);
	ptFire->pushParticle("image/particle/ptFire.png");
	ptFire->pos = D3DXVECTOR2(-1000, -1000);
	pushSceneNode(104,ptFire);

	//Fiar = new CParticleSceneNode(0.5f,0.002f,10000.f,2.f,4.f,D3DCOLOR_ARGB(255,255,220,50),D3DCOLOR_ARGB(90,255,0,0),100.f,3000.f,1.f);
	//Fiar->pushParticle("image/particle/ptFire.png");
	//Biar = new CParticleSceneNode(0.5f,0.002f,10000.f,2.f,4.f,D3DCOLOR_ARGB(255,255,255,255),D3DCOLOR_ARGB(90,0,0,255),100.f,3000.f,1.f);
	//Biar->pushParticle("image/particle/ptFire.png");
	
	//플레이어 초기화
	player = new CPlayer();
	player->pos = D3DXVECTOR2(800, 320);
	pushSceneNode(105,player);
	player->pauseOn = false;
	
	open = fopen(fileName, "r");
	//for문 횟수지정
	fscanf(open, "%d", &num);
	
	//행성 그림지정
	while(fgetc(open) != '@'){
		fscanf(open, "%d %s %s", &tempNum,path1,path2);
		planet[tempNum] = new CPlanet(path1, path2);
	}
	//행성 위치지정
	while(fgetc(open) != '@'){
		fscanf(open, "%d %f %f %d %d %d", &tempNum, &x, &y, &flagX, &flagY, &flagZ);
		planet[tempNum]->pos = D3DXVECTOR2(x,y);
		planet[tempNum]->flagX = flagX;
		planet[tempNum]->flagY = flagY;
		planet[tempNum]->flagZ = flagZ;
	}
	
	//목표 행성 초기화 & 폭발횟수
	fscanf(open, "%s %s %f %f %d", path1, path2, &x, &y, &boom);
	arrival = new CArrival(path1, path2);
	arrival->pos = D3DXVECTOR2(x,y);

	//행성출력
	for(int i = 0;i<num;i++){
		pushSceneNode(i,planet[i]);
	}
	pushSceneNode(num,arrival);

	//플레이어 시작위치 초기화
	fscanf(open, "%f %f", &pX,&pY);
	
	player->pos = D3DXVECTOR2(pX, pY);
	pushSceneNode(105,player);
	player->failCall = false;

	fscanf(open, "%s", nextStage);

	fclose(open);

	//boomPad 초기화
	boomPad = new CSpriteSceneNode("image/ui/boomPad.png");
	pushSceneNode(400,boomPad);
	boomPad->pos = D3DXVECTOR2(1024 - boomPad->width , 0);

	//stageNum 초기화
	char stageNumber = *(fileName + 8);
	if(stageNumber == '1')
		stageNum = new CSpriteSceneNode("image/ui/stageNum/1.png");
	else if(stageNumber == '2')
		stageNum = new CSpriteSceneNode("image/ui/stageNum/2.png");
	else if(stageNumber == '3')
		stageNum = new CSpriteSceneNode("image/ui/stageNum/3.png");
	else if(stageNumber == '4')
		stageNum = new CSpriteSceneNode("image/ui/stageNum/4.png");
	else if(stageNumber == '5')
		stageNum = new CSpriteSceneNode("image/ui/stageNum/5.png");
	else if(stageNumber == '6')
		stageNum = new CSpriteSceneNode("image/ui/stageNum/6.png");
	else if(stageNumber == '7')
		stageNum = new CSpriteSceneNode("image/ui/stageNum/7.png");
	else if(stageNumber == '8')
		stageNum = new CSpriteSceneNode("image/ui/stageNum/8.png");
	else if(stageNumber == '9')
		stageNum = new CSpriteSceneNode("image/ui/stageNum/9.png");
	else if(stageNumber == 'T')
		stageNum = new CSpriteSceneNode("image/ui/stageNum/10.png");
	pushSceneNode(402,stageNum);
	stageNum->pos = D3DXVECTOR2(1024 - boomPad->width - stageNum->width  , 0);

	//boomPad 초기화
	char type = *(fileName + 6);
	if(type == '1')
		levelType = new CSpriteSceneNode("image/ui/easy.png");
	else if(type == '2')
		levelType = new CSpriteSceneNode("image/ui/normal.png");
	else if(type == '3')
		levelType = new CSpriteSceneNode("image/ui/hard.png");
	pushSceneNode(401,levelType);
	levelType->pos = D3DXVECTOR2(1024 - boomPad->width - stageNum->width - levelType->width , 0);

	//boomAmount 초기화
	for( int i=0; i<boom; ++i )
	{
		boomAmount[i] = new CSpriteSceneNode("image/boom.png");
	}
    
       
	//마우스 초기화
	mouse = new CMouse(true);
	pushSceneNode(600, mouse);
	mouse->mouseFlag = false;

	//현재 스테이지 초기화
	strcpy(thisStage, fileName);

	//폭탄
	boomOn = true;

	//실패 했을경우 화면
	background = new CSpriteSceneNode("image/gameend.png");
	endColor = 0x00000000;
	background->color = 0x00000000;

	//클리어 여부
	clear = false;

	//공이 안에 있는지
	playerLost = false;

	//폭탄 절대갯수와 현재갯수로 분리
	curBoom = boom;
}

CMainScene::~CMainScene(){
}

void CMainScene::render(){
	ISceneNode::render();
	
}

void CMainScene::update(float eTime){
	ISceneNode::update(eTime);

	if(clecle)
	{
		Sleep(2000);
		end = new CSpriteSceneNode("image/cradit.png");
		Sleep(2000);
		pushSceneNode(700,end);
		Sleep(4000);
		g_pSceneManager->changeSceneNode(new CTitle());
		return ;
	}

	player->failCall = false;

	//행성 충돌처리
	for(int i = 0;i<num;i++)
	{
		player->gravity(planet[i]->pos.x, planet[i]->pos.y, planet[i]->GetWidth(), planet[i]->GetGravityWidth(), planet[i]->flagX, planet[i]->flagY, planet[i]->flagZ);
	}
	player->gravity(arrival->pos.x, arrival->pos.y, arrival->GetWidth(), arrival->GetGravityWidth(), 0, 0, 0);
	//마우스 클릭시 추진력
	if(g_pInputManager->keyState(VK_LBUTTON) == 1 && curBoom > 0 && (pow(( player->pos.x - mouse->getMousePos().x),2) + pow(( player->pos.y - mouse->getMousePos().y),2) <= pow( (( player->GetWidth()/2) + (mouse->GetRangeWidth()/2)),2 )) && !clear && !pauseOn){
		ptFire->pos = D3DXVECTOR2(player->pos.x, player->pos.y);
		player->move(mouse->getMousePos().x, mouse->getMousePos().y, mouse->GetRangeWidth());
		--curBoom;
		GetSoundMgr().Stop(SOUND_2);
		GetSoundMgr().Playis(SOUND_2);
	}
	else
		ptFire->pos = D3DXVECTOR2(-1000,-1000);

	//도착지에 닿으면 게임클리어
	if((player->clearCheck(arrival->pos.x, arrival->pos.y, arrival->GetGravityWidth())) && ((player->vX == 0) && (player->vY == 0)) && !pauseOn)
	{
		//g_pSceneManager->changeSceneNode(new CSelectStage());
		//return ;
		clear = true;
		mouse->mouseFlag = true;
		if(StageRecord::GetInstance()->GetstNum() == *(thisStage+8) && StageRecord::GetInstance()->GetLevel() == *(thisStage+6))
		{
			if(StageRecord::GetInstance()->GetstNum() == 'T')
			{
				StageRecord::GetInstance()->SetLevel(StageRecord::GetInstance()->GetLevel()+1);
				StageRecord::GetInstance()->SetstNum('1');
			}
			else if(StageRecord::GetInstance()->GetstNum() == '9')
			{
				StageRecord::GetInstance()->SetstNum('T');
			}
			else{
				StageRecord::GetInstance()->SetstNum(StageRecord::GetInstance()->GetstNum()+1);
			}
		}
	}

	//다음시작 버튼 초기화
	if(clear)
	{
		next = new CSpriteSceneNode("image/button/next.png");
		pushSceneNode(556, next);
		next->pos = D3DXVECTOR2(512-next->width/2,434);
		retry->visible = true;
		retry->pos = D3DXVECTOR2(512-retry->width*2,434);
		clearWin->visible = true;
		selectScene->visible = true;
		selectScene->pos = D3DXVECTOR2(512+selectScene->width,434);
	}

	//boomAmount 갯수 결정->출력
	for( int i=0; i<boom; ++i )
	{
		if(curBoom < boom && curBoom < i+1)
		{
			boomAmount[i]->visible = false;
		}
		else
		{
			pushSceneNode(403+i, boomAmount[i]);
			boomAmount[i]->pos = D3DXVECTOR2( 1034 - boomPad->width + i*(boomAmount[i]->width+8), (boomPad->height - boomAmount[i]->height)/2);
		}
	}

	//폭탄 갯수가 다 닿으면 시간 저장

	if( curBoom <= 0 && boomOn )
	{
		Ctime = clock()/1000;
		boomOn = false;
	}
	if(!boomOn && pauseOn)
	{
		Ctime = clock()/1000;
	}

	//printf("%f %f %d\n",player->pos.x, player->pos.y, outTime);

	if( ((player->pos.x <= 0 || player->pos.x >= 1024) || (player->pos.y <= 0 || player->pos.y >= 768)) && !playerLost )
	{
		outTime = clock()/1000;
		playerLost = true;	
	}
	else if( !((player->pos.x <= 0 || player->pos.x >= 1024) || (player->pos.y <= 0 || player->pos.y >= 768)) )
		playerLost = false;

	if(((((clock()/1000 - Ctime >= 3 && !boomOn && !(player->vX) && !(player->vY)) && !clear) || (clock()/1000 - outTime >= 5 && playerLost)) || player->failCall) && !clecle)
	{
		fail = true;
		//끝나면[실패] 흐림효과
		if(background->color <= 0xff000000)
		{
			endColor += 0x05050505;
			background->color = endColor;
			mouse->mouseFlag = true;
		}
		pushSceneNode(500,background);
		retry->visible = true;
		retry->pos = D3DXVECTOR2(512-retry->width*2,434);
		failWin->visible = true;
		selectScene->visible = true;
		selectScene->pos = D3DXVECTOR2(512+selectScene->width,434);
	}

	if(nextStage == "abc")
	{
		boomOn = true;
		end = new CSpriteSceneNode("image/button/end.png");
		pushSceneNode(428, end);
	}

	//일시정지 버튼 클릭
	if(g_pInputManager->keyState(VK_LBUTTON) == 1)
	{
		if(pow(mouse->pos.x- (pauseBtn->pos.x + pauseBtn->width/2 ),2) + pow(mouse->pos.y - (pauseBtn->pos.y + pauseBtn->width/2 ),2) <= pow(pauseBtn->width/2,2) )
		{
			if(!pauseOn && !fail)
			{
				pauseOn = true;
				player->pauseOn = true;
			}
		}
		if(pow(mouse->pos.x- (conBtn->pos.x + conBtn->width/2 ),2) + pow(mouse->pos.y - (conBtn->pos.y + conBtn->width/2 ),2) <= pow(conBtn->width/2,2) )
		{
				pauseOn = false;	
				player->pauseOn = false;
		}
	}

	if(g_pInputManager->keyState(VK_LBUTTON) == 1)
	{
		if(pow(mouse->pos.x- (retry->pos.x + retry->width/2 ),2) + pow(mouse->pos.y - (retry->pos.y + retry->width/2 ),2) <= pow(retry->width/2,2) )
		{
			g_pSceneManager->changeSceneNode(new CMainScene(thisStage));
			return ;
		}
		if(pow(mouse->pos.x- (selectScene->pos.x + selectScene->width/2 ),2) + pow(mouse->pos.y - (selectScene->pos.y + selectScene->width/2 ),2) <= pow(selectScene->width/2,2) )
		{
			g_pSceneManager->changeSceneNode(new CLevelStage());
			GetSoundMgr().Stop(SOUND_1);
			return ;
		}
		if(clear)
		{
			if(pow(mouse->pos.x- (next->pos.x + next->width/2 ),2) + pow(mouse->pos.y - (next->pos.y + next->width/2 ),2) <= pow(next->width/2,2) )
			{
				g_pSceneManager->changeSceneNode(new CMainScene(nextStage));
				return ;
			}
		}
	}
	//일시정지가 켜질경우
	if(pauseOn)
	{
		retry->visible = true;
		retry->pos = D3DXVECTOR2(512-retry->width*2,434);
		selectScene->visible = true;
		selectScene->pos = D3DXVECTOR2(512+selectScene->width,434);
		pauseWin->visible = true;
		conBtn->visible = true;
		conBtn->pos = D3DXVECTOR2(512-conBtn->width/2,434);
	}
	else if(!fail && !clear)
	{
		retry->visible = false;
		retry->pos = D3DXVECTOR2(1024,768);
		selectScene->visible = false;
		selectScene->pos = D3DXVECTOR2(1024,768);
		pauseWin->visible = false;
		conBtn->visible = false;
		conBtn->pos = D3DXVECTOR2(1024,768);
	}
	
}
