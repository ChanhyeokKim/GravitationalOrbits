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

	//�ý��� ����
	System_Create(&pSystem); 
	
	//pSystem->init(ä�μ�, ���� ���, 0���� ����)
	//�� : pSystem->init(10, FMOD_INIT_NORMAL , 0);
	pSystem->init(1000, FMOD_INIT_NORMAL , 0);
	m_Thread = new Thread[SOUND_END];
}

void SoundMgr::Update()
{
	//������Ʈ�� �ȵɽ� �Ҹ��� ������ ����
	pSystem->update();
}

void SoundMgr::Playis(int num)
{
	//���� �÷������ϰ�� ������� ����
	pChannel[num]->isPlaying(&m_NowPlaying[num]);
	if(!m_NowPlaying[num])
		pSystem->playSound(FMOD_CHANNEL_FREE , pSound[num] , 0 , &pChannel[num]);
}
void SoundMgr::Play(int num)
{
	//���� �÷������̿��� �����Ŵ
	pSystem->playSound(FMOD_CHANNEL_FREE , pSound[num] , 0 , &pChannel[num]);
}
void SoundMgr::Stop(int num)
{
	//�뷡�� ����
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
	//pSystem->createSound(���� ��ġ, ���� �ɼ�, , ���忡 �´� Sound[�迭])
	//�� : pSystem->createSound("��ġ",FMOD_HARDWARE | FMOD_LOOP_OFF , 0 , &pSound[0]);
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