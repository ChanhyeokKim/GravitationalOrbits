#pragma once
#include "ISceneNode.h"
#include "CSpriteSceneNode.h"
#include "CMouse.h"

class CTitle : virtual public ISceneNode{
private:
	CSpriteSceneNode* bg;
	CSpriteSceneNode* bStart;
	CSpriteSceneNode* bGuide;
	CSpriteSceneNode* bEnd;
	CSpriteSceneNode* Guide;
	CMouse* mouse;
public:
	CTitle();
	virtual ~CTitle();
public:
	virtual void render();
	virtual void update(float eTime);
};