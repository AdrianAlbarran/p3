#pragma once
#include "Sphere.h"
#include "Solid.h"
#include "Scene.h"

using namespace std;

class Bola : public Sphere
{

public:
	Bola(Vector3D coord, Color color, Vector3D orientation, Vector3D orientationSpeed, float radius, float slices, float slacks) : 
		Sphere(coord, color, orientation, orientationSpeed, radius, slices, slacks) {}

	void Update(const float time);

	//Metodos para cambiar la velocidad de la bola de disntintas maneras dependiendo de por donde colisione
	void colisionEjeX();
	void colisionEjeY();

};



