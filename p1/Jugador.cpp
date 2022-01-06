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
	colision.detectDrop(this->drop);
	quitarVida();
}
void Jugador::quitarVida()
{
	if (bola->GetCoordinateY() < 0.5) {
		if (this->getVida() > -1) {
			this->setVida(this->getVida() - 1);
			respawn();
		}
	}
}

void Jugador::respawn()
{
	float newPos = this->GetCoordinateY() +   bola->GetRadius();
	float velocidad = bola->GetSpeedY() * -1;
	bola->SetPosition(this->GetCoordinate());
	bola->SetCoordinateY(newPos);
	bola->SetSpeedY(velocidad);

}

void Jugador::bonus(Vector3D pos)
{	
	int v1;
	v1 = rand() % 4;
	if (v1==2) {
		drop->spawn(pos);
	}
}

