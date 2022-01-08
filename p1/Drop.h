#pragma once
#include "Cylinder.h"

class Drop :public Cylinder
{
private:

public:
	Drop(Vector3D coord, Color color, Vector3D orientation, Vector3D orientationSpeed, float rBase, float rUpperside, float height, float slices, float stacks) :
		Cylinder(coord, color, orientation, orientationSpeed, rBase, rUpperside, height, slices, stacks) {};
	
	void Update(const float time);

	void spawn(Vector3D pos);


};

