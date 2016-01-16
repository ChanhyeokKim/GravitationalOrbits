#pragma once

#include "DXUT.h"

class CParticle
{
private:
	LPDIRECT3DTEXTURE9 pTexture;
public:
	CParticle(char* path, D3DXMATRIX pmat, D3DXVECTOR2 pos, float ttl, float speed, float angle, float startScale, float endScale, D3DCOLOR startColor, D3DCOLOR endColor);
	~CParticle();
public:
	void render();
	void update(float eTime);
public:

	D3DXMATRIX pmat;
	D3DXMATRIX mat;

	D3DXVECTOR2 pos;

	float width;
	float height;

	float ttl;
	float time;

	float speed;
	float angle;

	float startScale;
	float endScale;

	D3DCOLOR startColor;
	D3DCOLOR endColor;
};