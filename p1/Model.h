#pragma once
#include "Solid.h"
#include "Triangle.h"
#include <vector>
#include <iostream>

using namespace std;
class Model : public Solid
{
private:

	vector <Triangle> triangleVector;
	vector <float> hitbox;

public:

	void setHitbox(vector <float> newHitbox) { hitbox = newHitbox; }
	vector <float> getHitbox() { return hitbox; }
	void addTriangle(Triangle triangle);
	void clear();
	void paintColor(Color color);
	void Render();
	void Update(const float time);
};

