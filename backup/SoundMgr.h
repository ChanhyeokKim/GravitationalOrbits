#ifndef __Sound__
#define __Sound__


#include "Fmod/inc/fmod.hpp" //���� �ִ°����� ����
#pragma comment (lib, "Fmod/lib/fmodex_vc.lib") //���� �ִ°����� ����

using namespace FMOD; 

// ���ǰ���
enum{
	SOUND1,
	SOUND_END
};

class SoundMgr
{
private:
	System*  pSystem; 

	Sound*  pSound[SOUND_END];  // SOUND_END�� SOUND_MAX�� ����
	Channel* pChannel[SOUND_END]; // SOUND_END�� SOUND_MAX�� ����

	bool	m_NowPlaying[SOUND_END]; // SOUND_END�� SOUND_MAX�� ����

	SoundMgr(void);
public:
	~SoundMgr(void);

	static SoundMgr& GetInstance()
	{
		static SoundMgr Instance;
		return Instance;
	}

	void Init();
	void Update();
	void Playis(int num);
	void Play(int num);
	void Stop(int num);
	void Release();

	bool GetisPlaying(int num) 
	{
		pChannel[num]->isPlaying(&m_NowPlaying[num]);
		return m_NowPlaying[num];
	}
};

inline SoundMgr& GetSoundMgr()
{
	return SoundMgr::GetInstance();
}

#endif