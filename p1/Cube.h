#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include "Solid.h"

class Cube:public Solid
{
private:
	float size;

public:
	Cube(Vector3D coord, Color color, Vector3D orientation, Vector3D orientationSpeed, Vector3D speed,float size) : Solid(coord, color, orientation, orientationSpeed, speed), size(size) {}
    Cube() : Solid(), size() {}
    //Getters & setters

    inline float GetSize()  { return this->size; }

    inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }


    void Render();
};

