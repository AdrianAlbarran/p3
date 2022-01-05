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

		if ((bola->GetCoordinateX() - 0.2 > (rectangulo->GetCoordinateX() - 0.75)) && (bola->GetCoordinateX() + 0.2 < (rectangulo->GetCoordinateX() + 0.75))) {


			std::cout << (bola->GetCoordinateY() - 0.2 < (rectangulo->GetCoordinateY() + 0.25)) << endl;
			std::cout << ((rectangulo->GetCoordinateY() - 0.25)) << endl;
			std::cout << (bola->GetCoordinateY() + 0.2) << endl;



			if (bola->GetCoordinateY() + 0.2 > (rectangulo->GetCoordinateY() - 0.35) && bola->GetCoordinateY() - 0.2 < (rectangulo->GetCoordinateY() + 0.35)) {

				std::cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;

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

			}
		}

		return true;
		
}

bool Colisiones::detectBarra(Bola* bola)
{

	if ((bola->GetCoordinateX() - 0.2 > (jugador->GetCoordinateX() - 1.65)) && (bola->GetCoordinateX() + 0.2 < (jugador->GetCoordinateX() + 1.65))) {
	
		if (bola->GetCoordinateY() + 0.2 > (jugador->GetCoordinateY() - 0.1) && bola->GetCoordinateY() - 0.2 < (jugador->GetCoordinateY() + 0.1)) {
			float newPos;
			newPos = bola->GetCoordinateY() + 0.08;
			bola->SetCoordinateY(newPos);
			bola->colisionEjeX();
		}

	}


	return true;
}
