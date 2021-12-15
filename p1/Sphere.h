#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include "Solid.h"

class Sphere: public Solid
{
    

    float radius;
    float slices;
    float slacks;

public:
    Sphere(Vector3D coord, Color color, Vector3D orientation, Vector3D orientationSpeed, float radius, float slices, float slacks) : Solid(coord, color, orientation, orientationSpeed), radius(radius), slices(slices), slacks(slacks) {}
    
    Sphere() : Solid(), radius(), slices(), slacks() {}

    //Getters & setters
    inline float GetRadius() { return this->radius; }
    inline float GetSlices() { return this->slices; }
    inline float GetSlacks() { return this->slacks; }

    inline void SetRadius(float& radiusToSet) { this->radius = radiusToSet; }
    inline void SetSlices(float& slicesToSet) { this->slices = slicesToSet; }
    inline void SetSlacks(float& slacksToSet) { this->slacks = slacksToSet; }



    void Render();
};

