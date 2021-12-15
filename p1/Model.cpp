#include "Model.h"


void Model::addTriangle(Triangle triangle)
{
	triangleVector.push_back(triangle);
}

void Model::clear() {
	triangleVector.clear();
}

void Model::paintColor(Color color) {

	for (Triangle& triangle : this->triangleVector) {

		triangle.setColor1(color);
		triangle.setColor2(color);
		triangle.setColor3(color);
	}
}

void Model::Render() {

	glPushMatrix();
	glTranslatef(GetCoordinateX(), GetCoordinateY(), GetCoordinateZ());
	glColor3f(GetRedComponent(), GetGreenComponent(), GetBlueComponent());
	glRotatef(GetOrientationX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientationY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientationZ(), 0.0, 0.0, 1.0);

	for (Triangle& triangle : this->triangleVector) {

		triangle.Render();
	}

	glPopMatrix();
}