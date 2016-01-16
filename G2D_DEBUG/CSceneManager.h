#pragma once

#include "ISceneNode.h"
#include<map>
using namespace std;

class CSceneManager
{
private:
	ISceneNode* now;
public:
	CSceneManager();
	~CSceneManager();
public:
	void render();
	void update(float eTime);
public:
	void changeSceneNode(ISceneNode* p);
};