#include "dxut\\core\\DXUT.h"
#include "CSceneManager.h"
#include "CTextureManager.h"
#include "CInputManager.h"

class CApplication
{
private:
public:
	static bool CALLBACK IsD3D9DeviceAcceptable( D3DCAPS9* pCaps, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat,
		bool bWindowed, void* pUserContext );
	static bool CALLBACK ModifyDeviceSettings( DXUTDeviceSettings* pDeviceSettings, void* pUserContext );
	static HRESULT CALLBACK OnD3D9CreateDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,
		void* pUserContext );
	static HRESULT CALLBACK OnD3D9ResetDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,
		void* pUserContext );
	static void CALLBACK OnFrameMove( double fTime, float fElapsedTime, void* pUserContext );
	static void CALLBACK OnD3D9FrameRender( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext );
	static LRESULT CALLBACK MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam,
		bool* pbNoFurtherProcessing, void* pUserContext );
	static void CALLBACK OnD3D9LostDevice( void* pUserContext );
	static void CALLBACK OnD3D9DestroyDevice( void* pUserContext );
	CApplication(wchar_t* title, int width, int height, bool window);
	~CApplication();
public:
	CSceneManager* pSceneManager;
	CTextureManager* pTextureManager;
	CInputManager* pInputManager;
	LPD3DXSPRITE pSprite;
public:
	static CApplication* getMe(CApplication* _this = NULL)
	{
		static CApplication* __this = _this;
		return __this;
	}
};

extern CApplication* Application;