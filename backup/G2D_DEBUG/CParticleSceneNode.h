#pragma once

#include "ISceneNode.h"
#include "CSpriteSceneNode.h"
#include "CParticle.h"
#include <vector>
using namespace std;

class CParticleSceneNode : virtual public ISceneNode
{
public:
	vector<char*> spriteList;
	typedef vector<CParticle*> PARTICLE;
	PARTICLE particleList;

	float delay;

	bool check;
public:
	CParticleSceneNode(float ttl, float ttc, int mtc, float startScale, float endScale, D3DCOLOR startColor, D3DCOLOR endColor, float speed, float spread, float radious);
	virtual ~CParticleSceneNode();
public:
	void render();
	void update(float eTime);
public:
	void pushParticle(char* path);
public:
	float ttl;
	float ttlp;
	float ttc;

	int mtc;

	float speed;
	float spread;

	float startScale;
	float endScale;

	D3DCOLOR startColor;
	D3DCOLOR endColor;

	float radious;
};