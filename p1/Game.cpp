#include "Game.h"
#include <iostream>

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{

	std::cout << "Tecla pulsada:" << key << std::endl;
}

void Game::ProcessMouseMovement(int x, int y) 
{
	std::cout << "Movimiento del mouse:" << x << ", " << y << std::endl;
}

void Game::ProcessMouseClick(int button, int state, int x, int y)
{
	std::cout << "Clic: " << button << std::endl;
}

void Game::Init() 
{
	//Camara

	Vector3D cameraCoord(4.0, 3.0, 12.0);
	Vector3D cameraOrientation(0.0, 0.0, 0.0);

	Camera* cameraPtr = new Camera(cameraCoord, cameraOrientation);

	escena.AddGameObject(cameraPtr);

	//Cubo
	Vector3D cubeCoord(1.0, 0.0, -2.0);
	Color cubeColor(1, 0.3, 1.0);
	Vector3D cubeOrientation(30, 100, -30);
	Vector3D cubeOrientationSpeed(3, 0, 0);
	Vector3D cubeSpeed(-0.06, 0.03, 0.0);
	Cube* cubePtr = new Cube(cubeCoord, cubeColor, cubeOrientation, cubeOrientationSpeed, cubeSpeed, 0.2);

	escena.AddGameObject(cubePtr);

	//Esfera
	Vector3D sphereCoord(1.0, 0.0, -2.0);
	Color sphereColor(1, 0.3, 0.0);
	Vector3D sphereOrientation(30, 10, 0);
	Vector3D sphereOrientationSpeed(1, 0, 0);
	Vector3D sphereSpeed(0.06, 0.03, 0.0);
	Sphere* spherePtr = new Sphere(sphereCoord, sphereColor, sphereOrientation, sphereOrientationSpeed,0.2, 100.0, 100.0);
	spherePtr->SetSpeed(sphereSpeed);

	escena.AddGameObject(spherePtr);

	//TeaPot
	//Teapot() : coord(0.0, 0.0, -2.0), teaColor(0.2, 0.3, 0.4), size(0.4), orientation(30, 150, 0) {}
	Vector3D teaPotCoord(0.0, 0.0, -2.0);
	Color teaPotColor(0.2, 0.3, 0.4);
	Vector3D teaPotOrientation(30, 150, 0);
	Vector3D teaPotOrientationSpeed(2, 0, 6);
	Vector3D teaPotSpeed(0.0, 0.05, 0.02);
	Teapot* teapotPtr = new Teapot(teaPotCoord, teaPotColor, teaPotOrientation, teaPotOrientationSpeed, 0.2);
	teapotPtr->SetSpeed(teaPotSpeed);
	escena.AddGameObject(teapotPtr);

	//Prisma
	Vector3D prismCoord(0.0, 1.0, -3.0);
	Color prismColor(1, 1, 0);
	Vector3D prismOrientation(170, 50, 143);
	Vector3D prismOrientationSpeed(2, 0, 1);
	Vector3D prismSpeed(0.02, 0.01, 0.02);
	Prism* prismPtr = new Prism(prismCoord, prismColor, prismOrientation, prismOrientationSpeed, 0.8, 0.31, 0.2);
	prismPtr->SetSpeed(prismSpeed);

	escena.AddGameObject(prismPtr);

	//Toroide
	Vector3D torusCoord(0.0, -0.7, -2.0);
	Color torusColor(0.3, 0.2, 1.0);
	Vector3D torusOrientation(150, 120, 500);
	Vector3D torusOrientationSpeed(0, 3, 1);
	Vector3D torusSpeed(0.1, 0.03, 0.0);
	Torus* torusPtr = new Torus(torusCoord, torusColor, torusOrientation, torusOrientationSpeed, 0.1, 0.15, 50, 50);
	torusPtr->SetSpeed(torusSpeed);

	escena.AddGameObject(torusPtr);

	//Cylinder
	Vector3D cylinderCoord(1.0, -0.5, -2.5);
	Color cylinderColor(1.0, 0.9, 1.0);
	Vector3D cylinderOrientation(-50, 0, 0);
	Vector3D cylinderOrientationSpeed(4, 4, 4);
	Vector3D cylinderSpeed(0.02, 0.03, 0.0);
	Cylinder* cylinderPtr = new Cylinder(cylinderCoord, cylinderColor, cylinderOrientation, cylinderOrientationSpeed, 0.2, 0.2, 0.5, 100, 100);
	cylinderPtr->SetSpeed(cylinderSpeed);

	escena.AddGameObject(cylinderPtr);
	
	//Objetos Varios

	ModelLoader* loader = new ModelLoader();
	loader->setScale(1.0f);

	Model* star = new Model();
	loader->LoadModel("..\\models\\ca.obj");
	*star = loader->getModel();
	star->SetPosition(Vector3D(1, 1, 1));
	star->SetOrientation(Vector3D(30, -60, -10));
	star->SetOrientationSpeed(Vector3D(3, 2, 1));
	star->SetSpeed(Vector3D(0.01, 0.02, 0.03));
	star->paintColor(Color(0.2, 0.5, 0.1));
	this->escena.AddGameObject(star);
	loader->Clear();
	



	//Texto
	string texto = "matame";
	Text* texto1 = new Text(Vector3D(0, 0, 0), Color(0.5, 0.2, 0), Vector3D(0, 0, 0), texto);
	
	this->escena.AddGameObject(texto1);

}

void Game::Render() 
{
	escena.Render();
}

void Game::Update() 
{
	escena.Update();
}
