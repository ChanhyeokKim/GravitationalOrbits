#pragma once
#include "ISCeneNode.h"
#include "CSpriteSceneNode.h"

class CPlanet : virtual public ISceneNode
{
private:
	CSpriteSceneNode* P;
public:
	CPlanet(void);
	virtual ~CPlanet(void);
	float GetWidth() { return P->width; }
	float GetHeight() { return P->height; }
	float vX, vY;
public :
	virtual void render();
	virtual void update(float eTime);
};
