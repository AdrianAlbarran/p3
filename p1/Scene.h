#pragma once
#include <vector>
#include "Solid.h"

using namespace std;

class Scene 
{
private:
	
	using solidPtr = Solid*;
	vector <solidPtr> gameObjects;
	Vector3D boundary;

	void checkBoundary();

public: 
	inline Scene(Vector3D boundary = Vector3D(8, 6, 4)) : boundary(boundary) {}
	void AddGameObject(Solid* solidPtr);

	inline Vector3D getBoundary() { return boundary; }
	inline void setBoundary(Vector3D& boundaryToSet) { this->boundary = boundaryToSet; }

	void Render();
	void Update();
};
