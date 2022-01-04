#include "Jugador.h"

void Jugador::Update(const float time)
{

	this->SetPosition(this->GetCoordinate() + this->GetSpeed() * time);
	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * time);

	//Colisiones con los rectangulos cubos
	for (Rectangulo* i : rectangulos) {

		if (colision.detectaRectangulo(this->bola, i) == true) {
			this->bola->setColisionado(true);
			break;
		}
	}

}
