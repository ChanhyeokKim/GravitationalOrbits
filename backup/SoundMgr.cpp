#include "SoundMgr.h"

SoundMgr::SoundMgr(void)
{
	Init();
}

SoundMgr::~SoundMgr(void)
{
	Release();
}

void SoundMgr::Init()
{

	//시스템 생성
	System_Create(&pSystem); 
	
	//pSystem->init(채널수, 사운드 모드, 0으로 하자)
	//예 : pSystem->init(10, FMOD_INIT_NORMAL , 0);
	pSystem->init(1,FMOD_INIT_NORMAL, 0);

	//pSystem->createSound(사운드 위치, 사운드 옵션, , 사운드에 맞는 Sound[배열])
	//예 : pSystem->createSound("위치",FMOD_HARDWARE | FMOD_LOOP_OFF , 0 , &pSound[0]);

	//pChannel[배열]->setVolume(0 ~ 1값) 사운드 볼륨 설정 기본값 1
	//예 : pChannel[배열]->setVolume(0.7f);
	

}

void SoundMgr::Update()
{
	//업데이트가 안될시 소리가 나오지 않음
	pSystem->update();
}

void SoundMgr::Playis(int num)
{
	//현재 플레이중일경우 재생하지 않음
	pChannel[num]->isPlaying(&m_NowPlaying[num]);
	if(!m_NowPlaying[num])
		pSystem->playSound(FMOD_CHANNEL_FREE , pSound[num] , 0 , &pChannel[num]);
}
void SoundMgr::Play(int num)
{
	//현재 플레이중이여도 재생시킴
	pSystem->playSound(FMOD_CHANNEL_FREE , pSound[num] , 0 , &pChannel[num]);
}
void SoundMgr::Stop(int num)
{
	//노래를 멈춤
	pChannel[num]->stop();
}
void SoundMgr::Release()
{
	pSystem->release();
	pSystem->close();
}