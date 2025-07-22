#pragma once
#include "Direct3D.h"
#include <DirectXMath.h>

using namespace DirectX;

struct CONSTANT_BUFFER
{
	DirectX::XMMATRIX matWVP; //world*view*projection�̍s��
	DirectX::XMMATRIX matNormal; //�@���ϊ��p�̍s��
	DirectX::XMMATRIX matWorld; //���[���h�s��
};

struct VERTEX
{
	XMFLOAT4 pos;	//�ʒu
	XMFLOAT2 uv;	//UV���W
	XMFLOAT4 normal; //�@���x�N�g��
};

//�O���錾
class Texture;//Texture�N���X���Ă̂��ǂ����ɂ����Ă��Ȃ��錾

class Quad
{
public:
	Quad();
	virtual ~Quad();
	virtual HRESULT Initialize();
	virtual void Draw(XMMATRIX& worldMatrix);
	void Release();
protected:
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;	//�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�萔�o�b�t�@
	Texture* pTexture_;	//�e�N�X�`��
};

