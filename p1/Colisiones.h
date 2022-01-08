#pragma once
#ifndef Colisiones_H_

#include "Rectangulo.h"
#include "Bola.h"
#include <vector>

class Jugador;
class Drop;

class Colisiones
{
	
private:
	Jugador* jugador;

public:
	Colisiones(Jugador* player) { jugador = player; }

	inline Jugador* getJugador() { return this->jugador; }
	bool detectaRectangulo(Bola* bola, Rectangulo* rectangulo);
	bool detectBarra(Bola* bola);
	bool detectDrop(Drop* drop);

};

#endif // !Colisiones_H_
