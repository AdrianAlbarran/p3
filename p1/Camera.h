#pragma once
#include "Solid.h"
class Camera : public Solid
{

public: 
	
	Camera(Vector3D coord = Vector3D(0,0,0), Vector3D orientation=Vector3D(0,0,0)) : Solid(coord, orientation) {}
	void Render();

};

