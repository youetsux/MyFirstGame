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
	//0.自分を描画
	Draw();
	//1.子オブジェクトを描画 childList_の各要素に対してDrawを呼ぶ
	//for (auto itr = childList_.begin(); itr != childList_.end(); itr++)
	//{
	//	(*itr)->DrawSub();
	//}
	for (auto child : childList_)
	{
		child->DrawSub();
	}
}
