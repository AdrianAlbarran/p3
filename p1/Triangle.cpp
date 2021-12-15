#include "Triangle.h"

void Triangle::Render()
{
	glBegin(GL_TRIANGLES);
	//vértice 1
	glColor3f(getColor1().getR(), getColor1().getG(), getColor1().getB());
	glNormal3f(getNormal1().getX(), getNormal1().getY(), getNormal1().getZ());
	glVertex3f(getVert1().getX(), getVert1().getY(), getVert1().getZ());

	//vértice 2
	glColor3f(getColor2().getR(), getColor2().getG(), getColor2().getB());
	glNormal3f(getNormal2().getX(), getNormal2().getY(), getNormal2().getZ());
	glVertex3f(getVert2().getX(), getVert2().getY(), getVert2().getZ());

	//vértice 3
	glColor3f(getColor3().getR(), getColor3().getG(), getColor3().getB());
	glNormal3f(getNormal3().getX(), getNormal3().getY(), getNormal3().getZ());
	glVertex3f(getVert3().getX(), getVert3().getY(), getVert3().getZ());
	glEnd();

}