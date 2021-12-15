#include "Cube.h"

void Cube::Render() {
	glPushMatrix();
	glTranslatef(this-> GetCoordinateX(), this->GetCoordinateY(), this->GetCoordinateZ());
	glColor3f(this-> GetRedComponent(), this-> GetGreenComponent(), this-> GetBlueComponent());
	glRotatef(this -> GetOrientationX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientationY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientationZ(), 0.0, 0.0, 1.0);
	glutSolidCube(this->GetSize());
	glPopMatrix();

}