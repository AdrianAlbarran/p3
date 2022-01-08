#include "Jugador.h"

void Jugador::Update(const float time)
{
	bool destruccion = true;
	vector<Rectangulo*> nuevosRectangulos;
	this->SetPosition(this->GetCoordinate() + this->GetSpeed() * time);
	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * time);
	int j = 0;

	//Colisiones con los rectangulos
	for (Rectangulo* i : rectangulos) {
		//el bool y nuevo array es usado para eliminar aquellos rectangulos que han sido eliminados
		destruccion = colision.detectaRectangulo(this->bola, i);
		if (destruccion) {
		}
		else {
			nuevosRectangulos.push_back(i);
		}
	}

	rectangulos = nuevosRectangulos;
	//Colision con la barra y el drop 
	colision.detectBarra(this->bola);
	colision.detectDrop(this->drop);
	this->quitarVida();
}

//Metodo por si la bola cae por debajo de la plataforma 
void Jugador::quitarVida()
{
	if (bola->GetCoordinateY() < 0.5) {
		if (this->getVida() > -1) {
			this->setVida(this->getVida() - 1);
			this->respawn();
		}
	}
}

//Metodo para que la bola reaparezca y quitar una vida
void Jugador::respawn()
{
	float newPos = this->GetCoordinateY() + bola->GetRadius();
	float velocidad = bola->GetSpeedY() * -1;
	bola->SetPosition(this->GetCoordinate());
	bola->SetCoordinateY(newPos);
	bola->SetSpeedY(velocidad);

}

//Metodo que determina cuando se spawnea un bonus (+1 vida)
void Jugador::bonus(Vector3D pos)
{	
	int v1;
	v1 = rand() % 10;
	if (v1==2) {
		drop->spawn(pos);
	}
}
