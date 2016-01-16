#pragma once
#include "ISCeneNode.h"
#include "CSpriteSceneNode.h"

class CArrival : virtual public ISceneNode
{
private:
	CSpriteSceneNode* arr;
	CSpriteSceneNode* arrG;
public:
	//pPath : �༺�׸� ��ġ, gPath : �߷±׸� ��ġ
	CArrival(char* arrPath, char* arrGPath);
	virtual ~CArrival(void);
	float GetWidth() { return arr->width; }
	float GetHeight() { return arr->height; }

	float GetGravityWidth() { return arrG->width; }
public :
	virtual void render();
	virtual void update(float eTime);
};
