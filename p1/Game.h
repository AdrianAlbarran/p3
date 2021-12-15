#pragma once
#include <vector>
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



using namespace std;
using namespace chrono;

class Game
{
private: 
	Scene escena;
	Model* player;

public:
	Game() : activeScene(nullptr), initalMilliseconds(duration_cast<millisenconds>(sysatem_clock::now().time_since_epoch())), lastUpdatedTime(0), player(nullptr) {}
	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);

};