#pragma once

#include "DXUT.h"
#include "ISceneNode.h"

class CSpriteSceneNode : virtual public ISceneNode
{
private:
	LPDIRECT3DTEXTURE9 pTexture;
public:
	CSpriteSceneNode(char* path);
	virtual ~CSpriteSceneNode();
public:
	void render();
	void update(float eTime);
public:
	float width;
	float height;
};