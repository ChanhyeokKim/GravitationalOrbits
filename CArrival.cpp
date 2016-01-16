#include "CArrival.h"

CArrival::CArrival(char* arrPath, char* arrGPath)
{
	arr = new CSpriteSceneNode(arrPath);
	arr->pos = D3DXVECTOR2(-arr->width/2.f, -arr->height/2.f);
	pushSceneNode(1,arr);
	rotCenter = D3DXVECTOR2(0, 0);

	arrG = new CSpriteSceneNode(arrGPath);
	arrG->pos = D3DXVECTOR2(-arrG->width/2.f, -arrG->height/2.f);
	pushSceneNode(0,arrG);
	rotCenter = D3DXVECTOR2(0, 0);
}

CArrival::~CArrival(void)
{
}

void CArrival::render(){
	ISceneNode::render();
}

void CArrival::update(float eTime){
	ISceneNode::update(eTime);
}