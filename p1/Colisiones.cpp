#include "Colisiones.h"
#include "Jugador.h"

bool Colisiones::detectaRectangulo(Bola* bola, Rectangulo* rectangulo)
{
	for (Rectangulo* i : this->jugador->getVecRectangulo()) {
		if ((bola->GetCoordinateX() - 0.2> (rectangulo->GetCoordinateX() - 0.75) && bola->GetCoordinateX() + 0.2 < (rectangulo->GetCoordinateX() + 0.75)) &&
			(bola->GetCoordinateY() + 0.2 > (rectangulo->GetCoordinateY() - 0.25) && bola->GetCoordinateY() - 0.2 < (rectangulo->GetCoordinateY() + 0.25))) 
		{
			float newPos = bola->GetCoordinateY() - 0.08 ;
			bola->SetCoordinateY(newPos);
			return true;
		}

		else return false;
	}
}
