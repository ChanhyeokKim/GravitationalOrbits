#include "SDKSound.h"
#include <map>
using namespace std;

class CGSoundManager
{
private :
	typedef map<int,CSound*> SOUND;
	SOUND m_Sound;

	CSoundManager g_SndMgr;
public :
	CGSoundManager();
	~CGSoundManager();

	void pushSound(int,LPWSTR);
	void popSound(int);

	void Play(int);
	
	void Stop();
	void Stop(int);
	
	void Reset();
	void Reset(int);
};

extern CGSoundManager* SoundManager;