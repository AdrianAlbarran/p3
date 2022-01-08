#include "Colisiones.h"
#include "Jugador.h"
#include "Drop.h"
#include <iostream>

bool Colisiones::detectaRectangulo(Bola* bola, Rectangulo* rectangulo)
{
	//Ifs para comprobar si la bola colisiona con el rectangulo
	if ((bola->GetCoordinateX() - 0.2 > (rectangulo->GetCoordinateX() - 0.85)) && (bola->GetCoordinateX() + 0.2 < (rectangulo->GetCoordinateX() + 0.85))) {
		if (bola->GetCoordinateY() + 0.2 > (rectangulo->GetCoordinateY() - 0.35) && bola->GetCoordinateY() - 0.2 < (rectangulo->GetCoordinateY() + 0.35)) {
			float newPos;
			bool col = false;

			if (bola->GetCoordinateY() < rectangulo->GetCoordinateY() && col == false) {
				newPos = bola->GetCoordinateY() - 0.08;
				bola->SetCoordinateY(newPos);
				bola->colisionEjeX();
				col = true;
			}
			else if (bola->GetCoordinateY() > rectangulo->GetCoordinateY() && col == false) {
				newPos = bola->GetCoordinateY() + 0.08;
				bola->SetCoordinateY(newPos);
				bola->colisionEjeX();
				col = true;
			}
			else if (bola->GetCoordinateX() < rectangulo->GetCoordinateX() && col == false) {
				newPos = bola->GetCoordinateX() - 0.08;
				bola->SetCoordinateX(newPos);
				bola->colisionEjeY();
				col = true;
			}
			else if (bola->GetCoordinateX() > rectangulo->GetCoordinateX() && col == false) {
				newPos = bola->GetCoordinateX() + 0.08;
				bola->SetCoordinateX(newPos);
				bola->colisionEjeY();
				col = true;
			}

			jugador->setPuntos(jugador->getPuntos() + 5);

			//Comprobar si el rectangulo es destruido o no, para devolver true en caso de que sí sea destruido
			bool destruido;
			destruido = rectangulo->colision();
			if (destruido) {
				jugador->bonus(rectangulo->GetCoordinate());
				return true;
			}
		}
	}

	return false;
}

//Codigo identico a "detectaRectangulo" pero modificado para las dimensiones de la barra
bool Colisiones::detectBarra(Bola* bola)
{
	if ((bola->GetCoordinateX() - 0.2 > (jugador->GetCoordinateX() - 1.65)) && (bola->GetCoordinateX() + 0.2 < (jugador->GetCoordinateX() + 1.65))) {
		if (bola->GetCoordinateY() + 0.2 > (jugador->GetCoordinateY() - 0.1) && bola->GetCoordinateY() - 0.2 < (jugador->GetCoordinateY() + 0.1)) {
			float newPos;
			newPos = bola->GetCoordinateY() + 0.08;
			bola->SetCoordinateY(newPos);
			bola->colisionEjeX();
			float k = 0.07;
			if (bola->GetSpeedX() < 0) {
				k = k * -1;
			}

			Vector3D bolaVel = Vector3D((bola->GetSpeedX() * (jugador->GetSpeedX() * 5) + k), bola->GetSpeedY(), bola->GetSpeedZ());
			bola->SetSpeed(bolaVel);
		}
	}

	return true;
}

//Comprobar si el drop toca la plataforma de jugador, si lo hace el jugador gana una vida y el drop "desaparece"
bool Colisiones::detectDrop(Drop* drop) {
	if ((drop->GetCoordinateX() - 0.2 > (jugador->GetCoordinateX() - 1.65)) && (drop->GetCoordinateX() + 0.2 < (jugador->GetCoordinateX() + 1.65))) {
		if (drop->GetCoordinateY() + 0.2 > (jugador->GetCoordinateY() - 0.1) && drop->GetCoordinateY() - 0.2 < (jugador->GetCoordinateY() + 0.1)) {
			Vector3D newPos = Vector3D(200, 200, 0);
			drop->SetPosition(newPos);
			float speed = 0;
			drop->SetSpeedY(speed);
			jugador->setVida(jugador->getVida() + 1);
		}

		return true;
	}
}