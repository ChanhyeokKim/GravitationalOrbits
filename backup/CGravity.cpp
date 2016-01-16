#include "CGravity.h"

CGravity::CGravity(void)
{
	G = new CSpriteSceneNode("image/gravity.png");
	G->pos = D3DXVECTOR2(-G->width/2.f, -G->height/2.f);
	pushSceneNode(1,G);
	rotCenter = D3DXVECTOR2(0, 0);
}

CGravity::~CGravity(void)
{
}

void CGravity::render(){
	ISceneNode::render();
}

void CGravity::update(float eTime){
	ISceneNode::update(eTime);
}