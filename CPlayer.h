#pragma once
#include "ISCeneNode.h"
#include "CSpriteSceneNode.h"

class CPlayer : virtual public ISceneNode
{
private:
	CSpriteSceneNode* a;
	bool ON;
	float temp, tX, tY, tvX, tvY;

public:
	CPlayer(void);
	virtual ~CPlayer(void);
	float GetWidth() { return a->width; }
	float GetHeight() { return a->height; }
	float vX, vY;
	bool pauseOn;
	bool failCall;
	float gradient , virtualGradient;
public :
	virtual void render();
	virtual void update(float eTime);
	void gravity(float Px, float Py, float pWidth, float gWidth, int flagX, int flagY, int flagZ);
	void move(float mX, float mY, float mWidth);
	int clearCheck(float arrX, float arrY, float arrWidth);
};
