#include "Drop.h"

void Drop::Update(const float time)
{
	this->SetPosition(this->GetCoordinate() + this->GetSpeed() * time);
	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * time);

	if (this->GetCoordinateY() < 0.5) {
		float speed = 0;
		Vector3D pos = Vector3D(200, 200, 0);
		this->SetPosition(pos);
		this->SetSpeedY(speed);
	}

}

void Drop::spawn(Vector3D pos)
{
	float speed = -0.07;
	this->SetPosition(pos);
	this->SetSpeedY(speed);
}
