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

public:

	void addTriangle(Triangle triangle);
	void clear();
	void paintColor(Color color);
	void Render();
	void Update();
};

