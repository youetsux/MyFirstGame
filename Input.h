#pragma once
#include <dInput.h>

#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dInput8.lib")

#define SAFE_RELEASE(p) if(p != nullptr){ p->Release(); p = nullptr;}

namespace Input
{
	void Initialize(HWND hWnd);
	void Update();
	bool IsKey(int keyCode);
	//�L�[�グ���艺������
	bool IsKeyUp(int keyCode);
	bool IsKeyDown(int keyCode);

	void Release();
};