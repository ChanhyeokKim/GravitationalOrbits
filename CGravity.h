#pragma once
#include "ISCeneNode.h"
#include "CSpriteSceneNode.h"

class CGravity : virtual public ISceneNode
{
private:
	CSpriteSceneNode* G;
public:
	CGravity(void);
	virtual ~CGravity(void);
	
	float GetHeight() { return G->height; }
	float gradient;
public :
	virtual void render();
	virtual void update(float eTime);
};
