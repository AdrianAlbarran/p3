#include "Camera.h"

/*
glTranslatef(-1 * <posición x>, -1 * <posición y>, -1 * <posición z>);
glRotatef(<ángulo de rotación en x>, 1.0, 0.0, 0.0);
glRotatef(<ángulo de rotación en y>, 0.0, 1.0, 0.0);
glRotatef(<ángulo de rotación en z>, 0.0, 0.0, 1.0);
*/

void Camera::Render()
{
	glTranslatef(-1 * this->GetCoordinateX(), -1 * this->GetCoordinateY(), -1 * this->GetCoordinateZ());
	glRotatef(this->GetOrientationX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientationY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientationZ(), 0.0, 0.0, 1.0);

}
