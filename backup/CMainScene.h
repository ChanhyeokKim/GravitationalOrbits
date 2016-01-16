#include "ISceneNode.h"
#include "CPlayer.h"
#include "CPlanet.h"
#include "CGravity.h"

class CMainScene : virtual public ISceneNode{
private :
	CSpriteSceneNode* background;
	CPlayer* a, *A;
	CPlanet* P;
	CGravity* G;
public :
	CMainScene();
	virtual ~CMainScene();
public :
	virtual void render();
	virtual void update(float eTime);
public :

};