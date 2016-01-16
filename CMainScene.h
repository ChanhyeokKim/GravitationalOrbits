#include "ISceneNode.h"
#include "CSpriteSceneNode.h"
#include "CParticleSceneNode.h"

#include "CPlayer.h"
#include "CPlanet.h"
#include "CArrival.h"
#include "CMouse.h"

class CMainScene : virtual public ISceneNode{
private :
	CSpriteSceneNode* background;
	CSpriteSceneNode* retry;
	CSpriteSceneNode* selectScene;
	CSpriteSceneNode* next;
	CSpriteSceneNode* pauseBtn;
	CSpriteSceneNode* boomAmount[10];
	CSpriteSceneNode* boomPad;
	CSpriteSceneNode* levelType;
	CSpriteSceneNode* stageNum;
	CSpriteSceneNode* pauseWin;
	CSpriteSceneNode* failWin;
	CSpriteSceneNode* clearWin;
	CSpriteSceneNode* conBtn;
	CSpriteSceneNode* end;

	CParticleSceneNode* ptStar;
	CParticleSceneNode* ptFire;
	CPlayer* player;
	CPlanet* planet[50];
	CArrival* arrival;
	CMouse* mouse;

	FILE* open;
	int num;
	int tempNum;
	int Ctime;
	int outTime;
	int curBoom;
	int boomTime;
	char path1[20];
	char path2[20];
	char temp,n;
	float x,y;
	float pX, pY;
	int flagX, flagY, flagZ;
	char thisStage[64];
	char nextStage[20];
	bool boomOn, clear, playerLost, pauseOn, fail;
	bool soundOn;
	bool clecle;
	D3DCOLOR endColor;
	

public :
	CMainScene(char* fileName);
	virtual ~CMainScene();
	int boom;
public :
	virtual void render();
	virtual void update(float eTime);
public :

};