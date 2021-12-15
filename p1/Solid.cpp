#include "Solid.h"

void Solid::Update() {

	orientation = orientation + (orientationSpeed * 1);
	coord = coord + speed * 1;
}