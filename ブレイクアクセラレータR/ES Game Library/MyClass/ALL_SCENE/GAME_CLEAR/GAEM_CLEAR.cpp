#include "GAEM_CLEAR.h"
#include "../SCENEMANAGER/SceneManager.h"
#include <algorithm>


void GAEM_CLEAR::Initialize()
{
	Add_Sprite(_T("SPRITE/game crear.png"));
}

void GAEM_CLEAR::Update()
{
	if (Input.GetKeyInputDown(Keys_Enter)) { SceneManager::ChangeScene(SceneManager::TITLE); }
}

void GAEM_CLEAR::Draw2D()
{
	std::for_each(sprite_list_name.begin(), sprite_list_name.end(), [](SPRITE& _sprite) {SpriteBatch.Draw(*_sprite, Vector3(0, 0, 0)); });
}

void GAEM_CLEAR::Add_Sprite(LPCTSTR _sprite_name)
{
	sprite = GraphicsDevice.CreateSpriteFromFile(_sprite_name);
	sprite_list_name.push_back(sprite);
}