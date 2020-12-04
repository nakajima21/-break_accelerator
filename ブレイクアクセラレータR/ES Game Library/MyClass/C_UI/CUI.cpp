#include "CUI.h"
#include"../INFORMATION/INFORMATION.h"
CUI::CUI()
{
	//自分をリストに登録
	observer.addListener(this);
}

CUI::~CUI()
{
	//自分をリストから削除
	observer.removeListener(this);
}

void CUI::Init()
{
	sprite_mng.CreateSpriteFromFile(_T("UI/FWゲージ/FW_base.png"),  Vector3(365.0f, 0.0f, 0.0f));
	sprite_mng.CreateSpriteFromFile(_T("UI/FWゲージ/FW_base2.png"), Vector3(365.0f, 0.0f, 0.0f));
	
	gage = sprite_mng.CreateSpriteFromFileRect(_T("UI/FWゲージ/FW_S.png"), Vector3(365.0f, 0.0f, 0.0f));
	
	IUiParametor::Instance().CreateParametor("ui");

	_ui_data.reset(new UiData);
}

void CUI::Update()
{
	
}

void CUI::OnCollisionDamage()
{

}

void CUI::OnCollisionClear()
{
	
}

void CUI::OnCollisionGage()
{

}

void CUI::Draw2D()
{
	sprite_mng.SetRectWH(gage, 0, 0, (540 * 0.01) * _ui_data->GetGageParams("ui"), 48);

	sprite_mng.DrawSprite();
}

