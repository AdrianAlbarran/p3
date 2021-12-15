#pragma once
#include "Solid.h"
#include <string>
using namespace std;
class Text : public Solid{
	
private: 

	string texto;


public:
	Text(Vector3D pos, Color color, Vector3D orientation, string texto) : Solid(pos, color, orientation), texto(texto) {};

	void setTexto(string& text) { this->texto = text; }
	string getTexto() { return this->texto; }

	void Render();

};

