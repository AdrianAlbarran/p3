#include "Scene.h"

void Scene::AddGameObject(Solid* solidPtr) 
{
	gameObjects.push_back(solidPtr);
}

void Scene::Render()
{
	for (solidPtr i : gameObjects) {
		i->Render();
	}
}

void Scene::Update(const double TIME_INCREMENT)
{
	for (solidPtr i : gameObjects) 
	{
		i->Update(TIME_INCREMENT);
	}

	checkBoundary();
}

void Scene::checkBoundary() 
{
	for (solidPtr i : gameObjects) 
	{
		if (i->GetCoordinateX() >= boundary.getX() || i->GetCoordinateX() < 0)
		{
			float a = i->GetSpeedX();
			a = a * -1;
			i->SetSpeedX(a);
		}
		if (i->GetCoordinateY() >= boundary.getY() || i->GetCoordinateY() < 0)
		{
			float a = i->GetSpeedY();
			a = a * -1;
			i->SetSpeedY(a);
		}	
		if (i->GetCoordinateZ() >= boundary.getZ() || i->GetCoordinateZ() < 0)
		{
			float a = i->GetSpeedZ();
			a = a * -1;
			i->SetSpeedZ(a);
		}
	}
}