#pragma once
#include "Model.h"
#include <vector>
#include "Rectangulo.h"
class Jugador :public Model
{
private:

	int vida;

	vector<Rectangulo*> rectangulos;



public:
	Jugador(Model model) :vida (3), Model(model){}

	inline vector<Rectangulo*> getVectoR() { return this->rectangulos; }
	inline void  setVectoR(vector<Rectangulo*> nuevosRectangulos) { rectangulos = nuevosRectangulos; }
	inline int getVida() { return this->vida; }
	inline void setVida(const int& vidatoset) { vida = vidatoset; }
};

