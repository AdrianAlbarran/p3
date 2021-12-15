#include "Camera.h"

/*
glTranslatef(-1 * <posici�n x>, -1 * <posici�n y>, -1 * <posici�n z>);
glRotatef(<�ngulo de rotaci�n en x>, 1.0, 0.0, 0.0);
glRotatef(<�ngulo de rotaci�n en y>, 0.0, 1.0, 0.0);
glRotatef(<�ngulo de rotaci�n en z>, 0.0, 0.0, 1.0);
*/

void Camera::Render()
{
	glTranslatef(-1 * this->GetCoordinateX(), -1 * this->GetCoordinateY(), -1 * this->GetCoordinateZ());
	glRotatef(this->GetOrientationX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientationY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientationZ(), 0.0, 0.0, 1.0);

}
