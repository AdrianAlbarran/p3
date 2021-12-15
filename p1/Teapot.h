    #pragma once
    #include <GL/glut.h>
    #include "Vector3D.h"
    #include "Color.h"
    #include "Solid.h"

class Teapot:public Solid
{
private: 

	float size;

public:
	Teapot(Vector3D coord, Color color, Vector3D orientation, Vector3D orientationSpeed, float size) : Solid(coord, color, orientation, orientationSpeed), size(size) {}
    Teapot() : Solid(), size() {}

    //metodos de acceso

    inline float GetSize()  { return this->size; }

    inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }


    void Render();
};

