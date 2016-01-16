#pragma once
#include "ISCeneNode.h"
#include "CSpriteSceneNode.h"

class CPlanet : virtual public ISceneNode
{
private:
	CSpriteSceneNode* P;
	CSpriteSceneNode* G;
public:
	//pPath : �༺�׸� ��ġ, gPath : �߷±׸� ��ġ
	CPlanet(char* pPath, char* gPath);
	virtual ~CPlanet(void);
	float GetWidth() { return P->width; }
	float GetHeight() { return P->height; }
	int flagX, flagY, flagZ;

	float GetGravityWidth() { return G->width; }
public :
	virtual void render();
	virtual void update(float eTime);
};
