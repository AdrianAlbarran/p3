#pragma once
#include <vector>
#include <chrono>
#include <cstdlib>
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Prism.h"
#include "Torus.h"
#include "Cylinder.h"
#include "Scene.h"
#include "Camera.h"
#include "ModelLoader.h"
#include "Text.h"
#include "Bola.h"
#include "Rectangulo.h"
#include "Jugador.h"
#include "Colisiones.h"
#include "Drop.h"



using namespace std;
using namespace chrono;

class Game
{
private: 
	const double TIME_INCREMENT = 0.4; //ms tiempo del juego
	const long UPDATE_PERIOD = 10; //ms tiempo en el mundo real

	milliseconds initalMilliseconds;
	long lastUpdatedTime;
	Scene* activeScene;
	vector<Scene*> scenes;
	Jugador* player;
	Text* vidas;
	Text* puntos;
	Text* puntosFinales;

	//Scenes
	Scene* mainScene = new(nothrow) Scene();
	Scene* inicioScene = new(nothrow) Scene();
	Scene* deadScene = new(nothrow) Scene();
	Scene* winScene = new(nothrow) Scene();

public:
	Game() : initalMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0), player(nullptr) { activeScene = new Scene(); }
	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
	~Game() {
		delete activeScene;
	}
};