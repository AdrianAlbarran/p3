#include "Game.h"
#include <iostream>

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{

	cout << "Tecla pulsada: " << key << endl;

	switch (key)
	{
	default:
		cout << key << endl;
		break;
	case 'd':
		this->player->SetSpeed(
			Vector3D(
				0.1,
				this->player->GetSpeed().getY(),
				this->player->GetSpeed().getZ())
		);
		break;

	case 'a':
		this->player->SetSpeed(
			Vector3D(
				-0.1,
				this->player->GetSpeed().getY(),
				this->player->GetSpeed().getZ())
		);
		break;
		
		//0 actua como la spacebar

	case 's':
		float speed = 0;
		this->player->SetSpeedX(speed);
		/*
		if (this->player->GetSpeedX() <= -0.005) {
			this->player->SetSpeed(
				Vector3D(
					this->player->GetSpeed().getX() + 0.005,
					this->player->GetSpeed().getY(),
					this->player->GetSpeed().getZ())
			);
		}

		if (this->player->GetSpeedX() >= 0.005) {
			this->player->SetSpeed(
				Vector3D(
					this->player->GetSpeed().getX() - 0.005,
					this->player->GetSpeed().getY(),
					this->player->GetSpeed().getZ())
			);
		}
		*/
	}

	cout << this->player->GetSpeed().getX() << endl;
}

void Game::ProcessMouseMovement(int x, int y) 
{
	std::cout << "Movimiento del mouse:" << x << ", " << y << std::endl;
}

void Game::ProcessMouseClick(int button, int state, int x, int y)
{
	std::cout << "Clic: " << button << std::endl;
	if (activeScene == inicioScene) {
		this->activeScene = mainScene;
	}
}

void Game::Init() 
{



	
	int v1;
	//Camara

	Vector3D cameraCoord(8, 6.0, 12.0);
	Vector3D cameraOrientation(0.0, 0.0, 0.0);

	Camera* cameraPtr = new Camera(cameraCoord, cameraOrientation);

	mainScene->AddGameObject(cameraPtr);
	inicioScene->AddGameObject(cameraPtr);

	/*
	//Cubo
	Vector3D cubeCoord(1.0, 0.0, -2.0);
	Color cubeColor(1, 0.3, 1.0);
	Vector3D cubeOrientation(30, 100, -30);
	Vector3D cubeOrientationSpeed(3, 0, 0);
	Vector3D cubeSpeed(-0.06, 0.03, 0.0);
	Cube* cubePtr = new Cube(cubeCoord, cubeColor, cubeOrientation, cubeOrientationSpeed, cubeSpeed, 0.2);

	activeScene->AddGameObject(cubePtr);

	//Esfera
	Vector3D sphereCoord(1.0, 0.0, -2.0);
	Color sphereColor(1, 0.3, 0.0);
	Vector3D sphereOrientation(30, 10, 0);
	Vector3D sphereOrientationSpeed(1, 0, 0);
	Vector3D sphereSpeed(0.06, 0.03, 0.0);
	Sphere* spherePtr = new Sphere(sphereCoord, sphereColor, sphereOrientation, sphereOrientationSpeed,0.2, 100.0, 100.0);
	spherePtr->SetSpeed(sphereSpeed);

	activeScene->AddGameObject(spherePtr);

	//TeaPot
	//Teapot() : coord(0.0, 0.0, -2.0), teaColor(0.2, 0.3, 0.4), size(0.4), orientation(30, 150, 0) {}
	Vector3D teaPotCoord(0.0, 0.0, -2.0);
	Color teaPotColor(0.2, 0.3, 0.4);
	Vector3D teaPotOrientation(30, 150, 0);
	Vector3D teaPotOrientationSpeed(2, 0, 6);
	Vector3D teaPotSpeed(0.0, 0.05, 0.02);
	Teapot* teapotPtr = new Teapot(teaPotCoord, teaPotColor, teaPotOrientation, teaPotOrientationSpeed, 0.2);
	teapotPtr->SetSpeed(teaPotSpeed);

	activeScene->AddGameObject(teapotPtr);

	//Prisma
	Vector3D prismCoord(0.0, 1.0, -3.0);
	Color prismColor(0.47, 0, 1);
	Vector3D prismOrientation(170, 50, 143);
	Vector3D prismOrientationSpeed(2, 0, 1);
	Vector3D prismSpeed(0.02, 0.01, 0.02);
	Prism* prismPtr = new Prism(prismCoord, prismColor, prismOrientation, prismOrientationSpeed, 0.8, 0.31, 0.2);
	prismPtr->SetSpeed(prismSpeed);

	activeScene->AddGameObject(prismPtr);
	
	//Toroide
	Vector3D torusCoord(0.0, -0.7, -2.0);
	Color torusColor(1, 0.3, 0.0);
	Vector3D torusOrientation(150, 120, 500);
	Vector3D torusOrientationSpeed(0, 3, 1);
	Vector3D torusSpeed(0.1, 0.03, 0.0);
	Torus* torusPtr = new Torus(torusCoord, torusColor, torusOrientation, torusOrientationSpeed, 0.1, 0.15, 50, 50);
	torusPtr->SetSpeed(torusSpeed);

	activeScene->AddGameObject(torusPtr);

	//Cylinder
	Vector3D cylinderCoord(1.0, -0.5, -2.5);
	Color cylinderColor(1.0, 0.9, 1.0);
	Vector3D cylinderOrientation(-50, 0, 0);
	Vector3D cylinderOrientationSpeed(4, 4, 4);
	Vector3D cylinderSpeed(0.02, 0.03, 0.0);
	Cylinder* cylinderPtr = new Cylinder(cylinderCoord, cylinderColor, cylinderOrientation, cylinderOrientationSpeed, 0.2, 0.2, 0.5, 100, 100);
	cylinderPtr->SetSpeed(cylinderSpeed);

	activeScene->AddGameObject(cylinderPtr);
	*/

	//Objetos Varios
	
	ModelLoader* loader = new ModelLoader();
	loader->setScale(1.0f);
	/*
	Model* star = new Model();
	loader->LoadModel("..\\models\\ca.obj");
	*star = loader->getModel();
	star->SetPosition(Vector3D(1, 1, 0));
	star->SetOrientation(Vector3D(30, -60, -10));
	star->SetOrientationSpeed(Vector3D(3, 2, 1));
	star->SetSpeed(Vector3D(0.0, 0.3, 0.0));
	star->paintColor(Color(0.2, 0.5, 0.1));
	mainScene->AddGameObject(star);
	loader->Clear();
	*/

	// Jugador 

	this->player = new Model();
	loader->setScale(2.0f);
	loader->LoadModel("..\\models\\velvetBar.obj");//models.resources.com
	player =new Jugador( loader->getModel());
	this->player->SetPosition(Vector3D(1, 1, 0));
	this->player->SetOrientation(Vector3D(0, 0, 0));
	this->player->SetOrientationSpeed(Vector3D(0, 0, 0));
	this->player->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	this->player->paintColor(Color(0.4, 0.99, 0.0));
	mainScene->AddGameObject(player);
	loader->Clear();

	//Bola

	Vector3D bolaCoord(1.0, 2.0, 0.0);
	Color bolaColor(1, 0.3, 0.0);
	Vector3D bolaOrientation(30, 10, 0);
	Vector3D bolaOrientationSpeed(1, 0, 0);
	Vector3D bolaSpeed(0.06, 0.08, 0.0);
	Bola* bolaPtr = new Bola(bolaCoord, bolaColor, bolaOrientation, bolaOrientationSpeed, 0.2, 100.0, 100.0);
	bolaPtr->SetSpeed(bolaSpeed);

	mainScene->AddGameObject(bolaPtr);

	//Rectangulos
	/*
	Vector3D prismCoord(5, 5, 0.0);
	Color prismColor(1, 0.3, 0);
	Vector3D prismOrientation(0, 0, 0);
	Vector3D prismOrientationSpeed(0, 0, 0);
	Vector3D prismSpeed(0.0, 0.0, 0.0);
	Rectangulo* prismPtr = new Rectangulo(prismCoord, prismColor, prismOrientation, prismOrientationSpeed, 1.5, 0.5, 0.2,1);
	prismPtr->SetSpeed(prismSpeed);

	activeScene->AddGameObject(prismPtr);
	
	
	Vector3D prismCoord1(1.55, 12.0, 0.0);
	Color prismColor1(1, 1, 1);
	Vector3D prismOrientation1(0, 0, 0);
	Vector3D prismOrientationSpeed1(0, 0, 0);
	Vector3D prismSpeed1(0.0, 0.0, 0.0);
	Rectangulo* prismPtr1 = new Rectangulo(prismCoord1, prismColor1, prismOrientation1, prismOrientationSpeed1, 1.5, 0.5, 0.2, 1);
	prismPtr->SetSpeed(prismSpeed);

	activeScene->AddGameObject(prismPtr1);

	Vector3D prismCoord2(3.1, 12.0, 0.0);
	Color prismColor2(1, 1, 2);
	Vector3D prismOrientation2(0, 0, 0);
	Vector3D prismOrientationSpeed2(0, 0, 0);
	Vector3D prismSpeed2(0.0, 0.0, 0.0);
	Rectangulo* prismPtr2 = new Rectangulo(prismCoord2, prismColor2, prismOrientation2, prismOrientationSpeed2, 1.5, 0.5, 0.2, 1);
	prismPtr->SetSpeed(prismSpeed);

	activeScene->AddGameObject(prismPtr2);


	Vector3D prismCoord3(12, 12, 0.0);
	Color prismColor3(1, 1, 0);
	Vector3D prismOrientation3(0, 0, 0);
	Vector3D prismOrientationSpeed3(0, 0, 0);
	Vector3D prismSpeed3(0.0, 0.0, 0.0);
	prismPtr2 = new Rectangulo(prismCoord3, prismColor3, prismOrientation3, prismOrientationSpeed3, 1.5, 0.5, 0.2, 1);
	prismPtr->SetSpeed(prismSpeed);

	activeScene->AddGameObject(prismPtr2);
	*/

	for (double i = 0.5; i < 16; i=i+1.65) {
		Vector3D prismCoord3(i, 11.5, 0.0);
		Color prismColor3(1, 0, 0);
		Vector3D prismOrientation3(0, 0, 0);
		Vector3D prismOrientationSpeed3(0, 0, 0);
		Vector3D prismSpeed3(0.0, 0.0, 0.0);
		Rectangulo* prismPtr3 = new Rectangulo(prismCoord3, prismColor3, prismOrientation3, prismOrientationSpeed3, 1.5, 0.5, 0.2, 1);
		mainScene->AddGameObject(prismPtr3);
	}
	for (double i = 0.5; i < 16; i = i + 1.65) {
		Vector3D prismCoord3(i, 10.80, 0.0);
		Color prismColor3(1,0,0.5);
		Vector3D prismOrientation3(0, 0, 0);
		Vector3D prismOrientationSpeed3(0, 0, 0);
		Vector3D prismSpeed3(0.0, 0.0, 0.0);
		Rectangulo* prismPtr3 = new Rectangulo(prismCoord3, prismColor3, prismOrientation3, prismOrientationSpeed3, 1.5, 0.5, 0.2, 1);
		mainScene->AddGameObject(prismPtr3);
	}
	for (double i = 0.5; i < 16; i = i + 1.65) {
		Vector3D prismCoord3(i, 10.1, 0.0);
		Color prismColor3(1, 1, 0);
		Vector3D prismOrientation3(0, 0, 0);
		Vector3D prismOrientationSpeed3(0, 0, 0);
		Vector3D prismSpeed3(0.0, 0.0, 0.0);
		Rectangulo* prismPtr3 = new Rectangulo(prismCoord3, prismColor3, prismOrientation3, prismOrientationSpeed3, 1.5, 0.5, 0.2, 1);
		mainScene->AddGameObject(prismPtr3);
	}
	

	/*
	v1 = rand() % 100;

	for (int i = 0; 1 < v1; i++) {
		int v2;
		v2 = (rand() % 100) / 100;
		Vector3D cubeCoord(v2, 0.0, -2.0);
		Color cubeColor(1, 0.3, 1.0);
		Vector3D cubeOrientation(30, 100, -30);
		Vector3D cubeOrientationSpeed(3, 0, 0);
		Vector3D cubeSpeed(-0.06, 0.03, 0.0);

		Rectangulo* cubePtr = new Rectangulo(cubeCoord, cubeColor, cubeOrientation, cubeOrientationSpeed, cubeSpeed, 0.2,1);

		activeScene->AddGameObject(cubePtr);


	}

	*/



	//Texto
	string texto = "matame";
	Text* texto1 = new Text(Vector3D(0, 0, 0), Color(0.5, 0.2, 0), Vector3D(0, 0, 0), texto);
	
	mainScene->AddGameObject(texto1);

	string texto3 = "Haz Click para empezar";
	Text* texto2 = new Text(Vector3D(7, 6.0, 0), Color(0.5, 0.2, 0), Vector3D(0, 0, 0), texto3);
	inicioScene->AddGameObject(texto2);

	this->scenes.push_back(inicioScene);
	this->scenes.push_back(mainScene);
	this->activeScene = inicioScene;
}

void Game::Render() 
{
	activeScene->Render();

}

void Game::Update() 
{

	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	if ((currentTime.count() - this->initalMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD)
	{
		this->activeScene->Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initalMilliseconds.count();
	}

	//Metodo para que frene la plataforma de manera automatica

}

