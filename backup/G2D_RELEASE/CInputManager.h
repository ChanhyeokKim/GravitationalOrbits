#pragma once

#include<windows.h>

class CInputManager
{
private:
	bool lkey[256], rkey[256];
public:
	CInputManager();
	~CInputManager();
public:
	void getKey();
	int keyState(int key);
};