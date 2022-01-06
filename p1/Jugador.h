#pragma once
#include "Model.h"
#include <vector>
#include "Colisiones.h"
#include "Drop.h"


class Jugador : public Model
{
private:

	int puntos = 0;
	int vida;

	vector<Rectangulo*> rectangulos;
	Drop* drop;
	Bola* bola;
	Colisiones colision = Colisiones (this);

public:
	Jugador(Model model) :vida (3), Model(model){}

	inline vector<Rectangulo*> getVecRectangulo() { return this->rectangulos; }
	inline void setVecRectangulo(vector<Rectangulo*> nuevosRectangulos) { this->rectangulos = nuevosRectangulos; }
	inline int getVida() { return this->vida; }
	inline int getPuntos() { return this->puntos; }
	inline void setPuntos(const int& puntostoset) { puntos = puntostoset; }
	inline void setVida(const int& vidatoset) { vida = vidatoset; }
	inline void setBola(Bola* newBola) { this->bola = newBola; }
	inline void setDrop(Drop* newDrop) { this->drop = newDrop; }
	void Update(const float time);
	void quitarVida();
	void respawn();
	void bonus(Vector3D pos);

};
