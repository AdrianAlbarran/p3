#pragma once
#include "Model.h"
#include <vector>
#include "Colisiones.h"


class Jugador : public Model
{
private:

	
	int vida;

	vector<Rectangulo*> rectangulos;
	Bola* bola;
	Colisiones colision = Colisiones (this);

public:
	Jugador(Model model) :vida (3), Model(model){}

	inline vector<Rectangulo*> getVecRectangulo() { return this->rectangulos; }
	inline void setVecRectangulo(vector<Rectangulo*> nuevosRectangulos) { this->rectangulos = nuevosRectangulos; }
	inline int getVida() { return this->vida; }
	inline void setVida(const int& vidatoset) { vida = vidatoset; }
	inline void setBola(Bola* newBola) { this->bola = newBola; }

	void Update(const float time);
};
