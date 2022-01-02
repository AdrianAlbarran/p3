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
	//Camara

	Vector3D cameraCoord(8, 6.0, 12.0);
	Vector3D cameraOrientation(0.0, 0.0, 0.0);

	Camera* cameraPtr = new Camera(cameraCoord, cameraOrientation);

	mainScene->AddGameObject(cameraPtr);
	inicioScene->AddGameObject(cameraPtr);

	
	ModelLoader* loader = new ModelLoader();
	loader->setScale(1.0f);

	// Jugador 

	vector<Rectangulo*> rectangulos;

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


	for (double i = 0.5; i < 16; i=i+1.65) {
		Vector3D prismCoord3(i, 11.5, 0.0);
		Color prismColor3(1, 0, 0);
		Vector3D prismOrientation3(0, 0, 0);
		Vector3D prismOrientationSpeed3(0, 0, 0);
		Vector3D prismSpeed3(0.0, 0.0, 0.0);
		Rectangulo* prismPtr3 = new Rectangulo(prismCoord3, prismColor3, prismOrientation3, prismOrientationSpeed3, 1.5, 0.5, 0.2, 1);
		mainScene->AddGameObject(prismPtr3);

		rectangulos.push_back(prismPtr3);
	}
	for (double i = 0.5; i < 16; i = i + 1.65) {
		Vector3D prismCoord3(i, 10.80, 0.0);
		Color prismColor3(1,0,0.5);
		Vector3D prismOrientation3(0, 0, 0);
		Vector3D prismOrientationSpeed3(0, 0, 0);
		Vector3D prismSpeed3(0.0, 0.0, 0.0);
		Rectangulo* prismPtr3 = new Rectangulo(prismCoord3, prismColor3, prismOrientation3, prismOrientationSpeed3, 1.5, 0.5, 0.2, 1);
		mainScene->AddGameObject(prismPtr3);

		rectangulos.push_back(prismPtr3);
	}
	for (double i = 0.5; i < 16; i = i + 1.65) {
		Vector3D prismCoord3(i, 10.1, 0.0);
		Color prismColor3(1, 1, 0);
		Vector3D prismOrientation3(0, 0, 0);
		Vector3D prismOrientationSpeed3(0, 0, 0);
		Vector3D prismSpeed3(0.0, 0.0, 0.0);
		Rectangulo* prismPtr3 = new Rectangulo(prismCoord3, prismColor3, prismOrientation3, prismOrientationSpeed3, 1.5, 0.5, 0.2, 1);
		mainScene->AddGameObject(prismPtr3);

		rectangulos.push_back(prismPtr3);
	}

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

