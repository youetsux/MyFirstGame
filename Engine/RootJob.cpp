#include "RootJob.h"
#include "..\\PlayScene.h"

RootJob::RootJob(GameObject* parent)
	:GameObject(parent, "RootJob")
{
}

RootJob::~RootJob()
{
}

void RootJob::Initialize()
{
	//
	//PlayScene�𐶐����āA�q�I�u�W�F�N�g�ɒǉ�����
	//0. PlayScene�̕ϐ���錾
	//1. PlayScene�̃C���X�^���X�𐶐�
	//2. PlayScene��Initialize���Ă�
	//3. childList_�ɒǉ�����
	//PlayScene* pPlayScene; //0. PlayScene�̕ϐ���錾
	//pPlayScene = new PlayScene(this); //1. PlayScene�̃C���X�^���X�𐶐�
	//pPlayScene->Initialize(); //2. PlayScene��Initialize���Ă�
	//childList_.push_back(pPlayScene); //3. childList_�ɒǉ�����
	Instantiate<PlayScene>(this);
}

void RootJob::Update()
{
}

void RootJob::Draw()
{
}

void RootJob::Release()
{
}
