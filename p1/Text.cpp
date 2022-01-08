#include "Text.h"

void Text::Render() {

	glPushMatrix();
	glColor3f(this->GetRedComponent(), this->GetGreenComponent(), this->GetBlueComponent());
	glTranslatef(this->GetCoordinateX(), this->GetCoordinateY(), this->GetCoordinateZ());
	glRasterPos3d(0, 0, 0);
	for (char c : this->texto)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	glPopMatrix();

}
