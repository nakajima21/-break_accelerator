#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"

class C_MAP : public Object
{
public:

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override;

	virtual void DrawAlpha3D() override { return; };
	virtual void Draw2D()      override;


private:

	enum MAP_MODEL
	{
		GROUND,
		PILLAR,
		MAP_MODEL_SIZE,
	};

	MODEL model;
	std::vector<Vector3> model_pos;

	Vector3 player_pos = Vector3(0.0f,0.0f,0.0f); 

	inline void CreateMapPrefarence();

	MODEL model_road;
	std::vector<Vector3> model_road_pos;

	MODEL model_bill;
	std::vector<Vector3> model_bill_pos;

	MEDIA bg;

protected:

};