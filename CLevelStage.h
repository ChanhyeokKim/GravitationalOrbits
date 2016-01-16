#pragma once
#include "ISceneNode.h"
#include "CSpriteSceneNode.h"
#include "CMouse.h"

class CLevelStage : virtual public ISceneNode{
private:
	
	CSpriteSceneNode* bg;
	CMouse* mouse;

	
	CSpriteSceneNode* bBack;

	CSpriteSceneNode* easy;
	
	CSpriteSceneNode* normal;

	CSpriteSceneNode* hard;

public:
	CLevelStage();
	virtual ~CLevelStage();
public:
	virtual void render();
	virtual void update(float eTime);
};