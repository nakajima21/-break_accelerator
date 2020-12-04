#pragma once
#include "../../ESGLib.h"
#include "../C_STATE/C_STATE.h"
#include "../C_OBJECT/Object.h"
#include "../c_Hitbox/HitBox.h"
#include "../C_INPUT/C_INPUT.h"
#include "../C_SE/C_SE.h"
#include "../INFORMATION/INFORMATION.h"
#include "../C_EFFEKSEER/CEffekseer_.h"


#include <functional>


class CPlayerStateProcessor;
class CPlayer;

class CPlayerStateProcessor : public  StateProcessor {
public:
	CPlayer* player_manager;
};

class CPlayer : public Object
{
public:
	CPlayerStateProcessor player_state_processor;
	
	CPlayer(Vector3  _pos);
	virtual ~CPlayer();

	virtual void CPlayer::Init()        override;
	virtual void CPlayer::Update()      override;
	virtual void CPlayer::Draw3D()      override;

	virtual void CPlayer::DrawAlpha3D() override { return; };
	virtual void CPlayer::Draw2D()      override { return; };

private:

	class IDOL : public State
	{
	private:
		CPlayerStateProcessor* _owner;
	public:
		IDOL(CPlayerStateProcessor* owner) : _owner(owner) { };
		virtual ~IDOL() {};

		virtual int    CancelLv() { return INT_MAX; };
		virtual int    ExitTime() { return INT_MAX; };

		virtual void Update() override;
	};

	class RUN : public State
	{
	private:
		CPlayerStateProcessor* _owner;
	public:
		RUN(CPlayerStateProcessor* owner) : _owner(owner) {}
		virtual ~RUN() {}

		virtual int    CancelLv() { return INT_MAX; };
		virtual int    ExitTime() { return INT_MAX; };

		virtual void Update() override;
	};

	class DAMAGE : public State
	{
	private:
		CPlayerStateProcessor* _owner;
	public:
		DAMAGE(CPlayerStateProcessor* owner) : _owner(owner) {}
		virtual ~DAMAGE() {}

		virtual int    CancelLv() { return INT_MAX; };
		virtual int    ExitTime() { return 30; };

		virtual void Update() override;
	};



private:
	//関数宣言
	Material SetMaterial(Color _color);
	int      IsHitObjectsInit();
	void	 IsHitObjectsDraw();

	double CPlayer::clamp(double x, double low, double high);

	bool   CPlayer::FrameTimeObsever(int _index);

    //変数宣言

	std::unique_ptr <HitBox> c_hitbox;

	MODEL player_model;
	Vector3 position = Vector3_Zero;
	float  speed = 0.0f;
	double rotation = 0.0f; 

	MONOSTATE monostate;

	int _time = 0;

	int effcseer_test;
	EFFEKSEER effekseer;
	int effcseer_id;


};