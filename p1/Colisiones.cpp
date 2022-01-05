#include "Colisiones.h"
#include "Jugador.h"
#include <iostream>


bool Colisiones::detectaRectangulo(Bola* bola, Rectangulo* rectangulo)
{


		
		/*if ((bola->GetCoordinateX() - 0.2> (rectangulo->GetCoordinateX() - 0.75) && bola->GetCoordinateX() + 0.2 < (rectangulo->GetCoordinateX() + 0.75)) &&
			(bola->GetCoordinateY() + 0.2 > (rectangulo->GetCoordinateY() - 0.25) && bola->GetCoordinateY() - 0.2 < (rectangulo->GetCoordinateY() + 0.25))) 
		{
			float newPos = bola->GetCoordinateY() - 0.08 ;
			bola->SetCoordinateY(newPos);
			return true;
		}

		else return false;*/

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
				else if (bola->GetCoordinateY() > rectangulo->GetCoordinateY() && col == false){
					newPos = bola->GetCoordinateY() + 0.08;
					bola->SetCoordinateY(newPos);
					bola->colisionEjeX();
					col = true;
				} else if (bola->GetCoordinateX() < rectangulo->GetCoordinateX() && col == false) {
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
				bool destruido;
				destruido = rectangulo->colision();
				if (destruido) {
					return true;
					//vector<Rectangulo*>::iterator a;
					//a = remove(jugador->getVecRectangulo().begin(), jugador->getVecRectangulo().end(), rectangulo);


	

				}
			}
		}

		return false;
		
}

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
				k=k * -1;
			}
			Vector3D bolaVel = Vector3D((bola->GetSpeedX() * (jugador->GetSpeedX() *5)+k), bola->GetSpeedY() , bola->GetSpeedZ());
			bola->SetSpeed(bolaVel);
		}

	}


	return true;
}
