#pragma once
#include "Model.h"
#include "Vector3D.h"
#include <vector>
#include <string>
#include "Triangle.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class ModelLoader
{

private:
	float scale;
	Model model;
	vector <Vector3D> vertVertex;
	vector <Vector3D> normVertex;
	float maxX;
	float maxY;
	float maxZ;
	float minX;
	float minY;
	float minZ;
	float getWidth() { return(this->maxX - this->minX); }
	float getHeight() { return(this->maxY - this->minY); }
	float getLength() { return(this->maxZ - this->minZ); }

	void calcBoundaries(Vector3D vectorPoint);
	Triangle center(Triangle triangle);
	Vector3D parseObjLineToVector3D(const string& sa);
	Triangle parseObjTriangle(const string& sa);

public:
	Model getModel() { return this->model; }
	float getScale() { return this->scale; }
	void setScale(float sc) { this->scale = sc; }
	void LoadModel(const string& filePath);
	void Clear();

};

