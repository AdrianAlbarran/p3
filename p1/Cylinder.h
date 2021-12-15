#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include "Solid.h"
class Cylinder:public Solid
{
private:
	float rBase;
	float rUpperside;
	float slices;
	float height;
	float stacks;

public:
	Cylinder(Vector3D coord, Color color, Vector3D orientation, Vector3D orientationSpeed, float rBase, float rUpperside, float height, float slices, float stacks) : Solid(coord, color, orientation, orientationSpeed),
		rBase(rBase), rUpperside(rUpperside), slices(slices), height(height), stacks(stacks) {}

	Cylinder() : Solid(), rBase(), rUpperside(), slices(), height(), stacks() {}

	//Getters & setters
	inline float GetrBase() { return this->rBase; }
	inline float GetrUpperside() { return this->rUpperside; }
	inline float GetHeight() { return this->height; }
	inline float GetSlices() { return this->slices; }
	inline float GetStacks() { return this->stacks; }

	inline void SetrBase(float& rBaseToSet) { this->rBase = rBaseToSet; }
	inline void SetrUpperside(float& rUppersideToSet) { this->rUpperside = rUppersideToSet; }
	inline void SetHeight(float& heightToSet) { this->height = heightToSet; }
	inline void SetSlices(float& slicesToSet) { this->slices = slicesToSet; }
	inline void SetStacks(float& stacksToSet) { this->stacks = stacksToSet; }

	void Render();
};
