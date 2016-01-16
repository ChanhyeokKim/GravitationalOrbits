#pragma once
#include "ISceneNode.h"
#include "CSpriteSceneNode.h"

class CMouse : virtual public ISceneNode{
private:
	CSpriteSceneNode* mouse;
	CSpriteSceneNode* mouse2;
	CSpriteSceneNode* range;
	POINT mousePos;
public:
	CMouse(bool rangeFlag);
	virtual ~CMouse();
	bool mouseFlag;
	
public:
	virtual void render();
	virtual void update(float eTime);

	float GetRangeWidth() { return range->width; }
	POINT getMousePos(){ return this->mousePos; }
};