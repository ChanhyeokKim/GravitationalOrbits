#include"Global.h"
#include"CApplication.h"
#include "CTitle.h"
#include <math.h>
#pragma comment(lib, "./G2D_DEBUG/G2D.lib")

int main(){
	HWND hwnd = GetConsoleWindow();
	Application = new CApplication(L"Gravitational Orbits", 1024, 768, true);
	ShowCursor(false);

	ShowWindow(hwnd,SW_HIDE);

	g_pSceneManager = Application->pSceneManager;
	g_pInputManager = Application->pInputManager;
	g_pSprite = Application->pSprite;
	g_pTextureManager = Application->pTextureManager;

	g_pSceneManager->changeSceneNode(new CTitle());

	G2DLoop();

	SAFE_DELETE(Application);
	return 0;
}