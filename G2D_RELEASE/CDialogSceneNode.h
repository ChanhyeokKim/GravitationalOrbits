#pragma once

#include "ISceneNode.h"

class CDialogSceneNode : virtual public ISceneNode
{
private:
public:
	CDialogSceneNode();
	virtual ~CDialogSceneNode();
public:
	virtual void render();
	virtual void update(float eTime);
public:
	void showDialog();
	void hideDialog();
public:
	int state;
};