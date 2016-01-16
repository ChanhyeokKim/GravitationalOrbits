#pragma once
#include "ISceneNode.h"
#include "CSpriteSceneNode.h"
#include "CMouse.h"

class CSelectStage : virtual public ISceneNode{
private:
	CSpriteSceneNode* bg;
	CSpriteSceneNode* bBack;
	CSpriteSceneNode* bS1_1;
	CSpriteSceneNode* bS1_2;
	CSpriteSceneNode* bS1_3;
	CSpriteSceneNode* bS1_4;
	CSpriteSceneNode* bS1_5;
	CSpriteSceneNode* bS1_6;
	CSpriteSceneNode* bS1_7;
	CSpriteSceneNode* bS1_8;
	CSpriteSceneNode* bS1_9;
	CSpriteSceneNode* bS1_10;
	CMouse* mouse;

	int stage;
	int levels;
	char* fileName;
public:
	CSelectStage(int level);
	virtual ~CSelectStage();
public:
	virtual void render();
	virtual void update(float eTime);
};