#pragma once

#include "ISceneNode.h"
#include "CSpriteSceneNode.h"

class CAniSceneNode : virtual public ISceneNode
{
private:
public:
	CAniSceneNode();
	virtual ~CAniSceneNode();
public:
	void render();
	void update(float eTime);
public:
	float frameSpeed;
	float nowFrame;
	int frame;
	int state;

	float width;
	float height;

	D3DCOLOR color;
public:
	void pushSprite(char* path);
	void pushSprite(char* path, int cnt);
	void play();
};