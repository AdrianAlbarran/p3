#include "Bola.h"

using namespace std;

void Bola::Update(const float time)
{
	this->SetPosition(this->GetCoordinate() + this->GetSpeed() * time);
	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * time);


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
