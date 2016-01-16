#pragma once

#include "DXUT\\core\\DXUT.h"
#include "CSceneManager.h"
#include "CTextureManager.h"
#include "CInputManager.h"

extern CSceneManager* g_pSceneManager;
extern LPD3DXSPRITE g_pSprite;
extern CTextureManager* g_pTextureManager;
extern CInputManager* g_pInputManager;

class Rect : virtual public RECT
{
public:
	Rect(float left, float top, float right, float bottom){
		this->left = (int)left;
		this->top = (int)top;
		this->right = (int)right;
		this->bottom = (int)bottom;
	}
};

int colCheck(D3DXVECTOR2 p1, D3DXVECTOR2 p2, RECT r1, RECT r2);