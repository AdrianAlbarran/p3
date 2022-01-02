#include "Colisiones.h"

bool Colisiones::detectaRectangulo(Bola* bola, Rectangulo* rectangulo)
{
	if ((bola->GetCoordinateX() > (rectangulo->GetCoordinateX() + 0.75) || bola->GetCoordinateX() < (rectangulo->GetCoordinateX() - 0.75)) ||
		(bola->GetCoordinateY() > (rectangulo->GetCoordinateY() + 0.25) || bola->GetCoordinateY() < (rectangulo->GetCoordinateY() - 0.25)) ||
		(bola->GetCoordinateZ() > (rectangulo->GetCoordinateZ() + 0.1) || bola->GetCoordinateZ() < (rectangulo->GetCoordinateZ() - 0.1))) {
		return true;
	}
	else return false;
}
