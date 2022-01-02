#pragma once
#include "Solid.h"
#include "Jugador.h"
#include "Rectangulo.h"
#include "Bola.h"

class Colisiones
{
private:
	Jugador* jugador;
	//En la clase jugador habria que añadir la clase bola, para poder controlar desde jugador todas las colisiones, el problema es como realizar el update desde esa clase. 
	//Es posible que gracias a los punteros la solucion a controlar los update y atributos sea mucho mas sencilla de lo que creo, pero ahora es algo tarde y me lio si no lo veo mientras lo hago


public:
	Colisiones(Jugador* player) : jugador(player) {}

	inline Jugador* getJugador() { return this->jugador; }
	bool detectaRectangulo(Bola* bolita, Rectangulo* rectangulo);
	bool detectBarra(Bola* bolita);

};

