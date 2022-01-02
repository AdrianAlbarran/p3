#pragma once
#include "Solid.h"
#include "Jugador.h"
#include "Rectangulo.h"
#include "Bola.h"
class Colisiones : public Solid
{
private:
	Jugador* jugador;

public:
	Colisiones	(Jugador* player) :jugador(player), Solid(){}

	inline Jugador* getJugador() {return this->jugador;}
	bool detectaRectangulo(Bola* bola, Rectangulo* rectangulo);
	bool dectectaBarra(Bola* bola, Jugador* player);


};

