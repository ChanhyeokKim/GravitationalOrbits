#include "CPlanet.h"

CPlanet::CPlanet(char* pPath, char* gPath)
{
	P = new CSpriteSceneNode(pPath);
	P->pos = D3DXVECTOR2(-P->width/2.f, -P->height/2.f);
	pushSceneNode(1,P);
	rotCenter = D3DXVECTOR2(0, 0);

	G = new CSpriteSceneNode(gPath);
	G->pos = D3DXVECTOR2(-G->width/2.f, -G->height/2.f);
	pushSceneNode(0,G);
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