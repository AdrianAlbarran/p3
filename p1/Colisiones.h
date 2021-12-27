#pragma once
#include "Solid.h";
#include "Bola.h";
#include "ModelLoader.h";
#include "Model.h";
#include "Vector3D.h";
#include <vector>

class Colisiones
{
private:
	vector <float> hitboxPalo;
	Model* palo = new Model();
	Bola* bola = new Bola();

public:

	Colisiones(Model* palo1, Bola* bola1) {
		
		hitboxPalo = palo1->getHitbox();
		palo = palo1;
		bola = bola1;
	}

	Colisiones() {}

	bool checkCollisionPalo();


};

