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

	//�ý��� ����
	System_Create(&pSystem); 
	
	//pSystem->init(ä�μ�, ���� ���, 0���� ����)
	//�� : pSystem->init(10, FMOD_INIT_NORMAL , 0);
	pSystem->init(1,FMOD_INIT_NORMAL, 0);

	//pSystem->createSound(���� ��ġ, ���� �ɼ�, , ���忡 �´� Sound[�迭])
	//�� : pSystem->createSound("��ġ",FMOD_HARDWARE | FMOD_LOOP_OFF , 0 , &pSound[0]);

	//pChannel[�迭]->setVolume(0 ~ 1��) ���� ���� ���� �⺻�� 1
	//�� : pChannel[�迭]->setVolume(0.7f);
	

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