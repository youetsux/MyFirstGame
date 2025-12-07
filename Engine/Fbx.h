#pragma once

#include <d3d11.h>
#include <fbxsdk.h>
#include <string>
#include "Transform.h"
#include "Texture.h"
#include <vector>

#pragma comment(lib, "LibFbxSDK-MD.lib")
#pragma comment(lib, "LibXml2-MD.lib")
#pragma comment(lib, "zlib-MD.lib")

struct RayCastData
{
	XMFLOAT4 start;
	XMFLOAT4 dir;
	bool hit;
	float dist;
};


class Fbx
{
public:
	Fbx();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();

	void InitVertex(FbxMesh* mesh);
	void InitIndex(FbxMesh* mesh);
	void InitConstantBuffer();
	void InitMaterial(FbxNode* pNode);

	void RayCast(RayCastData& rayData);
private:
	struct MATERIAL
	{
		Texture* pTexture;
		XMFLOAT4 diffuse;
	};

	struct CONSTANT_BUFFER
	{
		XMMATRIX	matWVP;
		XMMATRIX	matNormal;
		XMFLOAT4	diffuse;
		BOOL		materialFlag; //マテリアルがあるかないか
	};
	struct VERTEX
	{
		XMVECTOR position;
		XMVECTOR uv;
		XMVECTOR normal;
	};

	//バッファの皆さん
	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer** pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;
	std::vector<MATERIAL> pMaterialList_;
	std::vector<int> indexCount_;//マテリアルごとのインデックス数

	int vertexCount_;
	int polygonCount_;
	int materialCount_;

	// 新（vector版）
	std::vector<VERTEX>                 vertices_;        // 頂点配列
	std::vector<std::vector<int>>       indicesPerMat_;   // [material][index]
	
};

