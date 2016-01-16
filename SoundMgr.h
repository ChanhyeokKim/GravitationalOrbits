#ifndef __Sound__
#define __Sound__


#include "Fmod/inc/fmod.hpp"
#pragma comment (lib, "Fmod/lib/fmodex_vc.lib")
#include "Thread.h"

enum SOUND
{
	SOUND_1,
	SOUND_2,

	SOUND_END
};

using namespace FMOD; 

class SoundMgr
{
private:
	System*  pSystem; 

	Sound*  pSound[SOUND_END]; 
	Channel* pChannel[SOUND_END];

	bool	m_NowPlaying[SOUND_END];

	Thread* m_Thread;


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

	void AddSound(unsigned int SoundNum, char* szFileName);
	void SetVolume(unsigned int SoundNum, float fVolume);
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