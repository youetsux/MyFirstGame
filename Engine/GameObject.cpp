#include "GameObject.h"

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const string& name)
	:pParent_(parent), objectName_(name)
{
	if (parent != nullptr)
	{
		transform_.pParent_ = &(parent->transform_);
	}
}

GameObject::~GameObject()
{
}

void GameObject::DrawSub()
{
	//0.������`��
	Draw();
	//1.�q�I�u�W�F�N�g��`�� childList_�̊e�v�f�ɑ΂���Draw���Ă�
	//for (auto itr = childList_.begin(); itr != childList_.end(); itr++)
	//{
	//	(*itr)->DrawSub();
	//}
	for (auto child : childList_)
	{
		child->DrawSub();
	}
}

void GameObject::UpdateSub()
{
	this->Update();
	for (auto child : childList_)
	{
		child->UpdateSub();
	}
}

void GameObject::ReleaseSub()
{
	this->Release();//���������
	for (auto child : childList_)
	{
		child->ReleaseSub();
	}
}
void GameObject::SetPosition(XMFLOAT3 position)
{
	transform_.position_ = position;
}

void GameObject::SetPosition(float x, float y, float z)
{
	SetPosition(XMFLOAT3(x, y, z));
}
