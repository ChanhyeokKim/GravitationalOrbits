#include"Global.h"
#include"CApplication.h"
#include "CMainScene.h"
#include <math.h>
#pragma comment(lib, "./G2D_DEBUG/G2D.lib")

int main(){

	Application = new CApplication(L"¿ìÁÖ", 1024, 768, true);
	ShowCursor(true);

	g_pSceneManager = Application->pSceneManager;
	g_pInputManager = Application->pInputManager;
	g_pSprite = Application->pSprite;
	g_pTextureManager = Application->pTextureManager;

	g_pSceneManager->changeSceneNode(new CMainScene());

	G2DLoop();

	SAFE_DELETE(Application);
	return 0;
}