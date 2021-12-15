#pragma once
#include "Vector3D.h"
#include "Color.h"
#include "Solid.h"

class Torus: public Solid
{
private:
	float internalRad;
	float externalRad;
	float side;
	float ring;

public:
	Torus(Vector3D coord, Color color, Vector3D orientation, Vector3D orientationSpeed, float internalRad, float externalRad, float side, float ring) : Solid(coord, color, orientation, orientationSpeed), internalRad(internalRad),
		externalRad(externalRad), side(side), ring(ring) {}

	Torus() : Solid(), internalRad(), externalRad(), side(), ring() {}

	//Getters & setters
	inline float GetInternalRad() { return this->internalRad; }
	inline float GetExternalRad() { return this->externalRad; }
	inline float GetSide() { return this->side; }
	inline float GetRing() { return this->ring; }

	inline void SetInternalRad(float& InternalRadToSet) { this->internalRad = InternalRadToSet; }
	inline void SetExternalRad(float& ExternalRadToSet) { this->externalRad = ExternalRadToSet; }
	inline void SetSide(float& sideToSet) { this->side = sideToSet; }
	inline void SetRing(float& ringToSet) { this->ring = ringToSet; }

	void Render();
};

