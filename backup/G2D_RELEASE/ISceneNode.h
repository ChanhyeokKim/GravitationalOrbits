#pragma once

#include "DXUT.h"
#include<map>
using namespace std;

class ISceneNode
{
private:
	typedef map<int, ISceneNode*> NODE;
	NODE node;
public:
	D3DXMATRIX mat;

	D3DXVECTOR2 pos;
	D3DXVECTOR2 scale;
	D3DXVECTOR2 rotCenter;
	D3DXVECTOR2 scalingCenter;
	float rot;

	bool visible;

	RECT rect;
	
	ISceneNode* parent;

	D3DCOLOR color;
public:
	ISceneNode();
	virtual ~ISceneNode();
public:
	virtual void render();
	virtual void update(float eTime);
public:
	void pushSceneNode(int id, ISceneNode* p);
	void popSceneNode(int id,bool erase = false);
	ISceneNode* getSceneNode(int id);
public:
};