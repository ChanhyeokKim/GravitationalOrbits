#include "SoundMgr.h"

struct tagSoundInfo
{
	unsigned int SoundNum;
	char* szFileName;
	Sound** pSound;
	System* pSystem;
};

SoundMgr::SoundMgr(void)
{
	Init();
}

SoundMgr::~SoundMgr(void)
{
	Release();
	delete[] m_Thread;
}

void SoundMgr::Init()
{

	//시스템 생성
	System_Create(&pSystem); 
	
	//pSystem->init(채널수, 사운드 모드, 0으로 하자)
	//예 : pSystem->init(10, FMOD_INIT_NORMAL , 0);
	pSystem->init(1000, FMOD_INIT_NORMAL , 0);
	m_Thread = new Thread[SOUND_END];
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
DWORD WINAPI CreateSound(LPVOID _Info)
{
	tagSoundInfo* Info = (tagSoundInfo*)_Info;
	//pSystem->createSound(사운드 위치, 사운드 옵션, , 사운드에 맞는 Sound[배열])
	//예 : pSystem->createSound("위치",FMOD_HARDWARE | FMOD_LOOP_OFF , 0 , &pSound[0]);
	Info->pSystem->createSound(Info->szFileName,FMOD_HARDWARE | FMOD_LOOP_OFF , 0 , Info->pSound);
	return 0;
}
void SoundMgr::AddSound(unsigned int SoundNum, char* szFileName)
{
	tagSoundInfo* Info = new tagSoundInfo;
	Info->SoundNum = SoundNum;
	Info->szFileName = szFileName;
	Info->pSound = &pSound[SoundNum];
	Info->pSystem = pSystem;
	m_Thread[SoundNum].SetUp(CreateSound,Info);
	m_Thread[SoundNum].Start();
	SetVolume(SoundNum,1.0f);
}
void SoundMgr::SetVolume(unsigned int SoundNum, float fVolume)
{
	pChannel[SoundNum]->setVolume(fVolume);
}