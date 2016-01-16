#ifndef __Sound__
#define __Sound__


#include "Fmod/inc/fmod.hpp" //파일 있는곳으로 변경
#pragma comment (lib, "Fmod/lib/fmodex_vc.lib") //파일 있는곳으로 변경

using namespace FMOD; 

// 음악갯수
enum{
	SOUND1,
	SOUND_END
};

class SoundMgr
{
private:
	System*  pSystem; 

	Sound*  pSound[SOUND_END];  // SOUND_END는 SOUND_MAX와 같음
	Channel* pChannel[SOUND_END]; // SOUND_END는 SOUND_MAX와 같음

	bool	m_NowPlaying[SOUND_END]; // SOUND_END는 SOUND_MAX와 같음

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