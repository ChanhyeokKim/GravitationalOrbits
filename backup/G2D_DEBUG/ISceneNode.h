#pragma once

#include "DXUT\\core\\DXUT.h"
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
	//마우스 위치받아오는 함수
	POINT mousePos;//사용할 변수명
	HWND hWnd;//핸들

	POINT setMousePos(){
		GetCursorPos(&this->mousePos);
		this->hWnd = WindowFromPoint(this->mousePos);
		
		ScreenToClient(this->hWnd, &this->mousePos);

		return this->mousePos;
	}

	HCURSOR hCursor;
};