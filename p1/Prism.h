#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include "Solid.h"
class Prism: public Solid
{
private:
	float length;
	float height;
	float width;

public:
	Prism(Vector3D coord, Color color, Vector3D orientation, Vector3D orientationSpeed, float length, float height, float width) : 
		Solid(coord, color, orientation, orientationSpeed), length(length), height(height), width(width) {}

	Prism() : Solid(), length(), height(), width() {}

	//Getters & setters
	inline float GetLength() { return this->length; }
	inline float GetHeight() { return this->height; }
	inline float GetWidth() { return this->width; }

	inline void SetLength(float& lengthToSet) { this->length = lengthToSet; }
	inline void SetHeight(float& heightToSet) { this->height = heightToSet; }
	inline void SetWidth(float& widthToSet) { this->width = widthToSet; }
	 
	void Render();
};
