#include "Jugador.h"

void Jugador::Update(const float time)
{
	bool alacama = true;
	vector<Rectangulo*> nuevosRectangulos;
	this->SetPosition(this->GetCoordinate() + this->GetSpeed() * time);
	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * time);
	int j = 0;
	//Colisiones con los rectangulos cubos
	for (Rectangulo* i : rectangulos) {
		alacama=colision.detectaRectangulo(this->bola, i);
		if (alacama) {
		}
		else {
			nuevosRectangulos.push_back(i);
		}
	}
	
	rectangulos = nuevosRectangulos;
	colision.detectBarra(this->bola);
}
