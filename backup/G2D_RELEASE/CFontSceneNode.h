#pragma once

#include "ISceneNode.h"
#include "CSpriteSceneNode.h"

class CFontSceneNode : virtual public ISceneNode
{
private:
	CSpriteSceneNode* number[10];
	
	int value;
	int len;
public:
	CFontSceneNode();
	virtual ~CFontSceneNode();
public:
	void render();
	void update(float eTime);
public:
	void setValue(int _value);
};