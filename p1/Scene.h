#pragma once
#include <vector>
#include "Solid.h"
#include "Colisiones.h"

using namespace std;

class Scene 
{
private:
	
	using solidPtr = Solid*;
	vector <solidPtr> gameObjects;
	Vector3D boundary;
	const double TIME_INCREMENT=0.4;
	void checkBoundary();


public: 
	inline Scene(Vector3D boundary = Vector3D(16, 12, 1)) : boundary(boundary) {}
	void AddGameObject(Solid* solidPtr);

	inline Vector3D getBoundary() { return boundary; }
	inline void setBoundary(Vector3D& boundaryToSet) { this->boundary = boundaryToSet; }

	void Render();
	void Update(const double TIME_INCREMENT);
};
