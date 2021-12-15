#include "Sphere.h"

void Sphere::Render() {
	glPushMatrix();
	glTranslatef(this->GetCoordinateX(), this->GetCoordinateY(), this->GetCoordinateZ());
	glColor3f(this->GetRedComponent(), this->GetGreenComponent(), this->GetBlueComponent());
	glRotatef(this->GetOrientationX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientationY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientationZ(), 0.0, 0.0, 1.0);
	glutSolidSphere(this->GetRadius(), this-> GetSlices(), this-> GetSlacks());
	glPopMatrix();
}