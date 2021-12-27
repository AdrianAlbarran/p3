#include "Colisiones.h"


bool Colisiones::checkCollisionPalo ()
{
	bool fueHit = false;
	Vector3D posBola = bola->GetCoordinate();
	float radio = bola->GetRadius();

	if ((bola->GetCoordinateY() + radio) > hitboxPalo[3] && (bola->GetCoordinateX() - radio) > hitboxPalo[1] - radio - 0.1 && (bola->GetCoordinateX() + radio) < hitboxPalo[0] + radio + 0.1) {

		fueHit = true;
	}

	return fueHit;

	/*for (int i = 0; i < 3; i++) {

		switch (i)
		{

		default:
			break;

		case 0:
			fueHit = (bolaPtr->GetCoordinateX() + radio) > hitboxPalo[1] && (bolaPtr->GetCoordinateY() + radio) > hitboxPalo[3];
			break;
		}


		if (fueHit)
			break;
	}
	*/
}