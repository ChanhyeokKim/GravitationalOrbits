#pragma once

#include "DXUT.h"
#include<map>
#include<string>
using namespace std;

class CTextureManager
{
private:
	typedef map<string, LPDIRECT3DTEXTURE9> TEXTURE;
	TEXTURE texMap;
public:
	CTextureManager();
	~CTextureManager();
public:
	LPDIRECT3DTEXTURE9 loadTextureFormFile(char* path);
};