#pragma once
#include "Sphere.h"
#include "Solid.h"
#include "Scene.h"
#include "Colisiones.h"

using namespace std;

class Bola : public Sphere
{
	Colisiones* colision;

public:
	Bola(Vector3D coord, Color color, Vector3D orientation, Vector3D orientationSpeed, float radius, float slices, float slacks, Colisiones(colision) ):
		Sphere(coord, color, orientation, orientationSpeed, radius, slices, slacks) {}

	void Update(const float time);

};



