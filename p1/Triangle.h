#pragma once
#include "RenderUpdateFather.h"


class Triangle : public RenderUpdateFather
{
private: 
	//Valores de cada vertice
	Vector3D vert1;
	Vector3D normal1;
	Color color1;

	Vector3D vert2;
	Vector3D normal2;
	Color color2;

	Vector3D vert3;
	Vector3D normal3;
	Color color3;

public:
	
	Triangle(Vector3D vert1, Vector3D normal1, Color color1, Vector3D vert2, Vector3D normal2, Color color2, Vector3D vert3, Vector3D normal3, Color color3) :
		vert1(vert1), normal1(normal1), color1(color1),
		vert2(vert2), normal2(normal2), color2(color2),
		vert3(vert3), normal3(normal3), color3(color3) {}

	Triangle(Vector3D vert1, Vector3D normal1, Vector3D vert2, Vector3D normal2, Vector3D vert3, Vector3D normal3) :
		vert1(vert1), normal1(normal1), color1(),
		vert2(vert2), normal2(normal2), color2(),
		vert3(vert3), normal3(normal3), color3() {}

	//Getters
	inline Vector3D getVert1() { return this->vert1; }
	inline Vector3D getNormal1() { return this->normal1; }
	inline Color getColor1() { return this->color1; }

	inline Vector3D getVert2() { return this->vert2; }
	inline Vector3D getNormal2() { return this->normal2; }
	inline Color getColor2() { return this->color2; }
	
	inline Vector3D getVert3() { return this->vert3; }
	inline Vector3D getNormal3() { return this->normal3; }
	inline Color getColor3() { return this->color3; }

	//Setters
	//Sería apropiado añadir setters de cada coord.

	inline void setVert1(Vector3D& vertex) { this->vert1 = vertex; }
	inline void setNormal1(Vector3D& vertex) { this->normal1 = vertex; }
	inline void setColor1(Color& vertex) { this->color1 = vertex; }

	inline void setVert2(Vector3D& vertex) { this->vert2 = vertex; }
	inline void setNormal2(Vector3D& vertex) { this->normal2 = vertex; }
	inline void setColor2(Color& vertex) { this->color2 = vertex; }

	inline void setVert3(Vector3D& vertex) { this->vert3 = vertex; }
	inline void setNormal3(Vector3D& vertex) { this->normal3 = vertex; }
	inline void setColor3(Color& vertex) { this->color3 = vertex; }

	void Render();
};

