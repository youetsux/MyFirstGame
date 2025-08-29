#pragma once

#include <d3d11.h>
#include <fbxsdk.h>
#include <string>
#include "Transform.h"

#pragma comment(lib, "LibFbxSDK-MD.lib")
#pragma comment(lib, "LibXml2-MD.lib")
#pragma comment(lib, "zlib-MD.lib")


class Fbx
{
	struct CONSTANT_BUFFER
	{
		XMMATRIX	matWVP;
		XMMATRIX	matNormal;
	};
	struct VERTEX
	{
		XMVECTOR position;
	};

	//バッファの皆さん
	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer* pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;

	int vertexCount_;
	int polygonCount_;

public:

	Fbx();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();

	void InitVertex(FbxMesh* mesh);
	void InitIndex(FbxMesh* mesh);
	void InitConstantBuffer();
};

