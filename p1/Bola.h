#pragma once
#include "Sphere.h"
#include "Solid.h"
#include "Scene.h"
using namespace std;

class Bola : public Sphere
{
	bool colision = false;
public:
	Bola(Vector3D coord, Color color, Vector3D orientation, Vector3D orientationSpeed, float radius, float slices, float slacks) : 
		Sphere(coord, color, orientation, orientationSpeed, radius, slices, slacks) {}

	Bola() {}

	void Update(const float time);

};



