#include "Rectangulo.h"

bool Rectangulo::colision()
{
	dureza--;
	if (dureza == 0) {
		float aux= 0;
		this->SetHeight(aux);
		this->SetWidth(aux);
		return true;
	}
	return false;
}

void Rectangulo::Update(const float time)
{
	this->SetPosition(this->GetCoordinate() + this->GetSpeed() * time);
	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * time);


	switch (dureza)
	{
	case 1:
		this->SetColor(Color(1.0, 1.0, 0));
		break;
	case 2:
		this->SetColor(Color(1.0, 0, 1));
		break;
	case 3:
		this->SetColor(Color(1.0, 0, 0));
		break;

		
		
	}
}
