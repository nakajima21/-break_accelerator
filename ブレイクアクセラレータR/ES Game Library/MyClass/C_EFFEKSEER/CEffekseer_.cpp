#include "CEffekseer_.h"


CEffekseer_::CEffekseer_()
{
	Effekseer.Attach(GraphicsDevice);
	effekseer.clear();
	effekseer.reserve(4);
}

CEffekseer_::~CEffekseer_()
{
	std::for_each(effekseer.begin(), effekseer.end(), [](EFFEKSEER& _effekseer) {_effekseer = nullptr; });
	effekseer.clear();
}

/**
 * @fn
 * @param (TCHAR* filename) 引数の説明　EFFEKSEERのファイルネームを登録する
 * @return 戻り値の説明　スロット番号を返す後に指定できる
 * @detail 詳細な説明　　エフェクトデータの登録
 */
int CEffekseer_::LoadEffekseer(TCHAR* filename)
{
	EFFEKSEER _effekseer;
	_effekseer = Effekseer.CreateEffectFromFile(filename);

	effekseer.push_back(_effekseer);

	return effekseer.size() - 1;
}

EFFEKSEER CEffekseer_::GetEffekseer(int _number)
{
    return effekseer[_number];
}

/**
 * @fn
 * @param (int _number) 引数の説明　LoadEffekseerの戻り値を代入することで任意のエフェクトにアクセスできる
 * @detail 詳細な説明　大きさと再生座標を決める。
 */
int CEffekseer_::PlayEffekseer(int _number, double _scale, Vector3 _pos)
{
	int id = effekseer[_number]->Play(_pos);

	effekseer[_number]->SetPosition(id, _pos);
	effekseer[_number]->SetScale(id, 0.1);

	return effekseer.size() - 1;
}

void CEffekseer_::Update()
{
	Effekseer.Update();
}

void CEffekseer_::Draw(CAMERA& _camera)
{
	Effekseer.SetCamera(_camera);
	Effekseer.Draw();
}


