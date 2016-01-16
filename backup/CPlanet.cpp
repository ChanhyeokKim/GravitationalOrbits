#include "CPlanet.h"

CPlanet::CPlanet(void)
{
	P = new CSpriteSceneNode("image/planet.png");
	P->pos = D3DXVECTOR2(-P->width/2.f, -P->height/2.f);
	pushSceneNode(1,P);
	rotCenter = D3DXVECTOR2(0, 0);
}

CPlanet::~CPlanet(void)
{
}

void CPlanet::render(){
	ISceneNode::render();
}

void CPlanet::update(float eTime){
	ISceneNode::update(eTime);
}