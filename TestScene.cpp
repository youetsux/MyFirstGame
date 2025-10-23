#include "TestScene.h"

TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene")
{
}

TestScene::~TestScene()
{
}

void TestScene::Initialize()
{
}

void TestScene::Update()
{
	//スペースキー押したら 
	// SceneManager::ChangeScene(SCENE_ID_PLAY); を呼び出してね
}

void TestScene::Draw()
{
}

void TestScene::Release()
{
}
