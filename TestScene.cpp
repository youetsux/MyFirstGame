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
	//�X�y�[�X�L�[�������� 
	// SceneManager::ChangeScene(SCENE_ID_PLAY); ���Ăяo���Ă�
}

void TestScene::Draw()
{
}

void TestScene::Release()
{
}
