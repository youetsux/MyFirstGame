#include "Input.h"


namespace Input
{
    //�L�[�{�[�h�C���v�b�g
    LPDIRECTINPUT8   pDInput = nullptr;
    LPDIRECTINPUTDEVICE8 pKeyDevice = nullptr;
    BYTE keyState[256] = { 0 };
	BYTE prevKeyState[256] = { 0 };
	//�}�E�X�C���v�b�g
	LPDIRECTINPUTDEVICE8 pMouseDevice = nullptr;
	DIMOUSESTATE mouseState; //�}�E�X�̏��
	DIMOUSESTATE prevMouseState; //�O��̃}�E�X�̏��
    XMVECTOR mouseposition;
};

void Input::Initialize(HWND hWnd)
{
	//�L�[�{�[�h�f�o�C�X������
    DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDInput, nullptr);
    pDInput->CreateDevice(GUID_SysKeyboard, &pKeyDevice, nullptr);
    pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
    pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);

    //�}�E�X�f�o�C�X������
    pDInput->CreateDevice(GUID_SysMouse, &pMouseDevice, nullptr);
    pMouseDevice->SetDataFormat(&c_dfDIMouse);
    pMouseDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);

}

void Input::Update()
{
	memcpy(prevKeyState, keyState, sizeof(keyState));
    for (auto i = 0; i < 256; i++)
    {
		prevKeyState[i] = keyState[i];
    }
    pKeyDevice->Acquire();
    pKeyDevice->GetDeviceState(sizeof(keyState), &keyState);

	//�}�E�X�̏�Ԃ�ۑ�
    pMouseDevice->Acquire();
    memcpy(&prevMouseState, &mouseState, sizeof(mouseState));
    pMouseDevice->GetDeviceState(sizeof(mouseState), &mouseState);
}

bool Input::IsKey(int keyCode)
{
    if (keyState[keyCode] & 0x80)
    {
        return true;
    }
    return false;
}

bool Input::IsKeyUp(int keyCode)
{
    //���͗����Ă��āA�O��͉����Ă���@���=Release
    if (!IsKey(keyCode) && (prevKeyState[keyCode] & 0x80) )
    {
        return true;
    }
    return false;
}

bool Input::IsKeyDown(int keyCode)
{
    //���͉����Ă��āA�O��͉����ĂȂ��@����=Push
    if (IsKey(keyCode) && !(prevKeyState[keyCode] & 0x80) )
    {
        return true;
    }
    return false;
}

XMVECTOR Input::GetMousePosition()
{
    return mouseposition;
}

void Input::SetMousePosition(int x, int y)
{
	//mouseposition = XMVectorSet((float)x, (float)y, 0.0f, 1.0f);
	mouseposition = { (float)x, (float)y, 0.0f, 1.0f };
}

bool Input::IsMouseButton(int btnCode)
{
	if (mouseState.rgbButtons[btnCode] & 0x80)
	{
		return true;
	}
	return false;
}

bool Input::IsMouseButtonUp(int btnCode)
{
    return false;
}

bool Input::IsMouseButtonDown(int btnCode)
{
    return false;
}

void Input::Release()
{
	SAFE_RELEASE(pDInput);
}
