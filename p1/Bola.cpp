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

	//if(this->colision->detectaRectangulo(this,))
}