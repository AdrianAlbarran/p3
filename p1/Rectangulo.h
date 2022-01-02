#pragma once
#include "Prism.h"
class Rectangulo :public Prism
{
private:

	int dureza;
	
public:
	Rectangulo(Vector3D coord, Color color, Vector3D orientation, Vector3D orientationSpeed, float length, float height, float width, int dureza) :
		Prism(coord, color, orientation, orientationSpeed, length, height, width){}

	void Update();
	
};

