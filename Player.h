#pragma once
#include "Engine\\GameObject.h"


class Fbx;
class ChildOden;

class Player :
    public GameObject
{
public:
	Player(GameObject* parent);
	~Player();
	//�������z�֐��̃I�[�o�[���C�h
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	int hModel;
	//Fbx* pFbx_;
	ChildOden* pRChildOden_;
	ChildOden* pLChildOden_;
};

