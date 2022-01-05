#include "Bola.h"

using namespace std;

void Bola::Update(const float time)
{
	this->SetPosition(this->GetCoordinate() + this->GetSpeed() * time);
	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * time);

	if (this->GetCoordinateY() < 0.5) {
		float radius = 0;
		this->SetRadius(radius);
	}

	//if (this->colisionado == true) {

	//	float a = this->GetSpeedX();
	//	//a = a * -1;
	//	//this->SetSpeedX(a);

	//	a = this->GetSpeedY();
	//	a = a * -1;
	//	this->SetSpeedY(a);

	//	this->colisionado = false;
	//}
}

void Bola::colisionEjeX() {
	float a;

	a = this->GetSpeedY();
	a = a * -1;
	this->SetSpeedY(a);
}

void Bola::colisionEjeY() {
	float a = this->GetSpeedX();
	a = a * -1;
	this->SetSpeedX(a);

}
