#pragma once

#include "ISceneNode.h"

class CPopupSceneNode : virtual public ISceneNode
{
private:
public:
	CPopupSceneNode();
	virtual ~CPopupSceneNode();
public:
	virtual void render();
	virtual void update(float eTime);
public:
	void showPopup();
	void hidePopup();
public:
	int state;
};