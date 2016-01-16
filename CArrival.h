#pragma once
#include "ISCeneNode.h"
#include "CSpriteSceneNode.h"

class CArrival : virtual public ISceneNode
{
private:
	CSpriteSceneNode* arr;
	CSpriteSceneNode* arrG;
public:
	//pPath : 행성그림 위치, gPath : 중력그림 위치
	CArrival(char* arrPath, char* arrGPath);
	virtual ~CArrival(void);
	float GetWidth() { return arr->width; }
	float GetHeight() { return arr->height; }

	float GetGravityWidth() { return arrG->width; }
public :
	virtual void render();
	virtual void update(float eTime);
};
