#include "GameObject.h"

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const string& name)
	:pParent_(parent), objectName_(name)
{
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
