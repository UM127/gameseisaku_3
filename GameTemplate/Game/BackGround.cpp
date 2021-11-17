#include "stdafx.h"
#include "BackGround.h"
#include "Player.h"

BackGround::BackGround()
{

}

BackGround::~BackGround()
{

}
bool BackGround::Start()
{

	m_backGround.Init("Assets/modelData/stage/stagewater.tkm");
	m_backGround.SetScale(Vector3::One * 20.0f);
	m_backGround.Update();

	m_backGround2.Init("Assets/modelData/stage/darkstagewater.tkm");
	m_backGround2.SetScale(Vector3::One * 20.0f);
	m_backGround2.Update();

	//PhysicsStaticObjectを初期化。
	m_physicsStaticObject.CreateFromModel(
	m_backGround.GetModel(),
	m_backGround.GetModel().GetWorldMatrix());
	//当たり判定の可視化。
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	return true;
}
void BackGround::Render(RenderContext& rc)
{
	if (FindGO<Player>("player")->GetWorldState() == 0)
	{
		m_backGround.Draw(rc);
	}
	if (FindGO<Player>("player")->GetWorldState() == 1)
	{
		m_backGround2.Draw(rc);
	}
}