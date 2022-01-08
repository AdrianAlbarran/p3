#include "Game.h"
#include <iostream>

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{

	cout << "Tecla pulsada: " << key << endl;

	//Con este switch simplemente vamos a controlar el movimiento de la plataforma inferior, que es el jugador
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
		
	case 's':
		float speed = 0;
		this->player->SetSpeedX(speed);
		break;
	}

}

void Game::ProcessMouseMovement(int x, int y) 
{
	std::cout << "Movimiento del mouse:" << x << ", " << y << std::endl;
}

void Game::ProcessMouseClick(int button, int state, int x, int y)
{
	std::cout << "Clic: " << button << std::endl;
	//Cambio de escena
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

	//Añadimos la camara a las distintas escenas
	inicioScene->AddGameObject(cameraPtr);
	mainScene->AddGameObject(cameraPtr);
	deadScene->AddGameObject(cameraPtr);
	winScene->AddGameObject(cameraPtr);
	
	//Inicializamos el loader de modelos
	ModelLoader* loader = new ModelLoader();
	loader->setScale(2.0f);

	//Asignaoms la plataforma al jugador
	loader->LoadModel("..\\models\\velvetBar.obj");//models.resources.com
	this->player = new Jugador(loader->getModel());
	this->player->SetPosition(Vector3D(8, 1, 0));
	this->player->SetOrientation(Vector3D(0, 0, 0));
	this->player->SetOrientationSpeed(Vector3D(0, 0, 0));
	this->player->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	this->player->paintColor(Color(0.4, 0.99, 0.0));
	mainScene->AddGameObject(player);
	loader->Clear();

	//Bola
	Vector3D bolaCoord(8, 5, 0);
	Color bolaColor(1, 0.3, 0.0);
	Vector3D bolaOrientation(0, 0, 0);
	Vector3D bolaOrientationSpeed(0, 0, 0);
	Vector3D bolaSpeed(0.14, 0.14, 0.0);
	Bola* bolaPtr = new Bola(bolaCoord, bolaColor, bolaOrientation, bolaOrientationSpeed, 0.2, 100, 100);
	bolaPtr->SetSpeed(bolaSpeed);
	mainScene->AddGameObject(bolaPtr);

	//Drop
	Vector3D dropCoord(200, 200, 0.0);
	Color dropColor(0, 0, 1.0);
	Vector3D dropOrientation(0,90, 0);
	Vector3D dropOS(0, 0, 0);
	Vector3D dropS(0, 0, 0);
	Drop* dropPtr = new Drop(dropCoord, dropColor, dropOrientation,dropOS, 0.2, 0.2, 0.5, 100, 100);
	dropPtr->SetSpeed(dropS);
	mainScene->AddGameObject(dropPtr);

	//Vector de rectangulos 
	vector<Rectangulo*> rectangulos;

	for (double i = 0.5; i < 16; i=i+1.55) {
		Vector3D prismCoord3(i, 11.5, 0.0);
		Color prismColor3(1, 0, 0);
		Vector3D prismOrientation3(0, 0, 0);
		Vector3D prismOrientationSpeed3(0, 0, 0);
		Vector3D prismSpeed3(0.0, 0.0, 0.0);
		Rectangulo* prismPtr3 = new Rectangulo(prismCoord3, prismColor3, prismOrientation3, prismOrientationSpeed3, 1.5, 0.5, 0.2, 3);
		mainScene->AddGameObject(prismPtr3);
		rectangulos.push_back(prismPtr3);
	}
	for (double i = 0.5; i < 16; i = i + 1.55) {
		Vector3D prismCoord3(i, 10.80, 0.0);
		Color prismColor3(1,0,1);
		Vector3D prismOrientation3(0, 0, 0);
		Vector3D prismOrientationSpeed3(0, 0, 0);
		Vector3D prismSpeed3(0.0, 0.0, 0.0);
		Rectangulo* prismPtr3 = new Rectangulo(prismCoord3, prismColor3, prismOrientation3, prismOrientationSpeed3, 1.5, 0.5, 0.2, 2);
		mainScene->AddGameObject(prismPtr3);
		rectangulos.push_back(prismPtr3);
	}
	for (double i = 0.5; i < 16; i = i + 1.55) {
		Vector3D prismCoord3(i, 10.1, 0.0);
		Color prismColor3(1, 1, 0);
		Vector3D prismOrientation3(0, 0, 0);
		Vector3D prismOrientationSpeed3(0, 0, 0);
		Vector3D prismSpeed3(0.0, 0.0, 0.0);
		Rectangulo* prismPtr3 = new Rectangulo(prismCoord3, prismColor3, prismOrientation3, prismOrientationSpeed3, 1.5, 0.5, 0.2, 1);
		mainScene->AddGameObject(prismPtr3);
		rectangulos.push_back(prismPtr3);
	}

	//Le otorgamos al jugador aquellos objetos que son esenciales
	//para el funcionamiento de la clase y del propio juego
	player->setVecRectangulo(rectangulos);
	player->setBola(bolaPtr);
	player->setDrop(dropPtr);

	//Texto
	string vida = to_string(player->getVida());
	vidas = new Text(Vector3D(0, 0, 0), Color(0.5, 0.2, 0), Vector3D(0, 0, 0), vida);

	string punto = to_string(player->getPuntos());
	puntos = new Text(Vector3D(5, 0, 0), Color(0.5, 0.2, 0), Vector3D(0, 0, 0), punto);
	
	string strPuntosFinales = "Tus puntos son " + to_string(player->getPuntos());
	puntosFinales = new Text(Vector3D(6.8, 4.0, 0), Color(0.5, 0.2, 0), Vector3D(0, 0, 0), strPuntosFinales);

	mainScene->AddGameObject(vidas);
	mainScene->AddGameObject(puntos);
	deadScene->AddGameObject(puntosFinales);
	winScene->AddGameObject(puntosFinales);


	string empezar = "Haz Click para empezar";
	Text* inicio = new Text(Vector3D(7, 6.0, 0), Color(0.5, 0.2, 0), Vector3D(0, 0, 0), empezar);
	inicioScene->AddGameObject(inicio);

	this->scenes.push_back(inicioScene);
	this->scenes.push_back(mainScene);
	this->activeScene = inicioScene;

	string dead = "Game Over";
	Text* gameover = new Text(Vector3D(6.8, 6.0, 0), Color(0.5, 0.2, 0), Vector3D(0, 0, 0), dead);
	deadScene->AddGameObject(gameover);

	string win = "You Win";
	Text* victoria = new Text(Vector3D(6.8, 6.0, 0), Color(0.5, 0.2, 0), Vector3D(0, 0, 0), win);
	winScene->AddGameObject(victoria);

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

		//Control de los textos
		if (player->getVida() < 0) {
			activeScene = deadScene;
			string strPuntosFinales = "Tus puntos son " + to_string(player->getPuntos());
			puntosFinales->setTexto(strPuntosFinales);
		}
		if (player->getPuntos() == 300) {
			activeScene = winScene;
			string strPuntosFinales = "Tus puntos son " + to_string(player->getPuntos());
			puntosFinales->setTexto(strPuntosFinales);

		}
		string strVidas = "Vidas: " + to_string(player->getVida());
		vidas->setTexto(strVidas);
		string strPuntos = "Puntos: " + to_string(player->getPuntos());
		puntos->setTexto(strPuntos);
	}

}

