#include "Cylinder.h"

void Cylinder::Render() {

	GLUquadricObj* quadricTemp = gluNewQuadric();
	glPushMatrix();
	glTranslatef(this->GetCoordinateX(), this->GetCoordinateY(), this->GetCoordinateZ());
	glColor3f(this->GetRedComponent(), this->GetGreenComponent(), this->GetBlueComponent());
	glRotatef(this->GetOrientationX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientationY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientationZ(), 0.0, 0.0, 1.0);
	gluCylinder(quadricTemp, rBase, rUpperside, height, slices, stacks);
	glPopMatrix();
	gluDeleteQuadric(quadricTemp);

}