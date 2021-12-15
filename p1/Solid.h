#pragma once
#include <GL/glut.h>
#include "RenderUpdateFather.h"

class Solid : public RenderUpdateFather
{
private:

	Vector3D coord;
	Vector3D orientation;
	Vector3D orientationSpeed;
	Vector3D speed;


	Color color;

public:

	inline Solid(Vector3D coord, Color color, Vector3D orientation, Vector3D orientationSpeed, Vector3D speed = Vector3D()) : coord(coord), color(color), orientation(orientation), orientationSpeed(orientationSpeed), speed(speed) {}
	inline Solid() : coord(), color(), orientation(), orientationSpeed() {}
	inline Solid(Vector3D coord, Vector3D orientation) : coord(coord), orientation(orientation), orientationSpeed() {}
	inline Solid(Vector3D coord, Color color, Vector3D orientation) : coord(coord), color(color), orientation(orientation) {}

	//Getters & setters
	inline float GetCoordinateX() { return this->coord.getX(); }
	inline float GetCoordinateY() { return this->coord.getY(); }
	inline float GetCoordinateZ() { return this->coord.getZ(); }
	inline float GetRedComponent() { return this->color.getR(); }
	inline float GetGreenComponent() { return this->color.getG(); }
	inline float GetBlueComponent() { return this->color.getB(); }
	inline float GetOrientationX() { return this->orientation.getX(); }
	inline float GetOrientationY() { return this->orientation.getY(); }
	inline float GetOrientationZ() { return this->orientation.getZ(); }
	inline float GetOrientationSpeedX() { return this->orientationSpeed.getX(); }
	inline float GetOrientationSpeedY() { return this->orientationSpeed.getY(); }
	inline float GetOrientationSpeedZ() { return this->orientationSpeed.getZ(); }
	inline float GetSpeedX() { return this->speed.getX(); }
	inline float GetSpeedY() { return this->speed.getY(); }
	inline float GetSpeedZ() { return this->speed.getZ(); }
	inline Vector3D GetSpeed() { return this->speed; }

	inline void SetPosition(Vector3D positionToSet) { this->coord.set(positionToSet); }
	inline void SetCoordinateX(float& coordinateXToSet) { this->coord.setX(coordinateXToSet); }
	inline void SetCoordinateY(float& coordinateYToSet) { this->coord.setY(coordinateYToSet); }
	inline void SetCoordinateZ(float& coordinateZToSet) { this->coord.setZ(coordinateZToSet); }
	inline void SetColor(Color colorToSet) { this->color.set(colorToSet); }
	inline void SetRedComponent(float& redComponentToSet) { this->color.setR(redComponentToSet); }
	inline void SetGreenComponent(float& greenComponentToSet) { this->color.setG(greenComponentToSet); }
	inline void SetBlueComponent(float& blueComponentToSet) { this->color.setB(blueComponentToSet); }
	inline void SetOrientation(Vector3D orientationToSet) { this->orientation.set(orientationToSet); }
	inline void SetOrientationX(float& orientationXToSet) { this->orientation.setX(orientationXToSet); }
	inline void SetOrientationY(float& orientationYToSet) { this->orientation.setY(orientationYToSet); }
	inline void SetOrientationZ(float& orientationZToSet) { this->orientation.setZ(orientationZToSet); }
	inline void SetOrientationSpeed(Vector3D orientationSpeedToSet) { this->orientationSpeed.set(orientationSpeedToSet); }
	inline void SetOrientationSpeedX(float& orientationXToSet) { this->orientationSpeed.setX(orientationXToSet); }
	inline void SetOrientationSpeedY(float& orientationYToSet) { this->orientationSpeed.setY(orientationYToSet); }
	inline void SetOrientationSpeedZ(float& orientationZToSet) { this->orientationSpeed.setZ(orientationZToSet); }
	inline void SetSpeed(Vector3D speedToSet) { this->speed.set(speedToSet); }
	inline void SetSpeedX(float& speedXToSet) { this->speed.setX(speedXToSet); }
	inline void SetSpeedY(float& speedYToSet) { this->speed.setY(speedYToSet); }
	inline void SetSpeedZ(float& speedZToSet) { this->speed.setZ(speedZToSet); }

	void Update();

};
