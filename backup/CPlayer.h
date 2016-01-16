#pragma once
#include "ISCeneNode.h"
#include "CSpriteSceneNode.h"

class CPlayer : virtual public ISceneNode
{
private:
	CSpriteSceneNode* a;
	bool ON;

public:
	CPlayer(void);
	virtual ~CPlayer(void);
	float GetWidth() { return a->width; }
	float GetHeight() { return a->height; }
	float vX, vY;
	float gradient , virtualGradient;
public :
	virtual void render();
	virtual void update(float eTime);
};
