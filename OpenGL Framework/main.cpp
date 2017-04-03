//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2016 Media Design School
//
// File Name   : main.cpp
// Description : main implementation file; creates the window, checks for user input, loads images
// Author	   : Juan Rodriguez
// Mail		   : juan.rod6618@mediadesignschool.com
//

#include <iostream>

#include "Utils.h"
#include "Camera.h"
#include "GameModel.h"
#include "Cubemap.h"
#include "model.h"

#define DOWN 1
#define UP 0

using std::cout;
using glm::vec3;

// Classes
Utils* ut;
ShaderLoader shaderLoader;
Camera* camera;
Light* light;
GameModel* Sphere;
Cubemap* skybox;

// Custom models
Model *Castle, *Nanosuit;

unsigned char KeyCode[255];

void Render();
void Update();
void KeyDown(unsigned char key, int x, int y);
void KeyUp(unsigned char key, int x, int y);

void AnimateModel(GameModel* _model, vec3 _moveDirection, float _deltaTime);
void AnimateModel(Model* _model, vec3 _moveDirection, float _deltaTime);

int main(int argc, char **argv) {

	// init glut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(GLUT_WINDOW_WIDTH / 2, GLUT_WINDOW_HEIGHT / 2);
	glutInitWindowSize(ut->WIDTH, ut->HEIGHT);
	glutCreateWindow("OpenGL Framework - Juan Rodriguez");
	glutSetOption(GLUT_MULTISAMPLE, 8);

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);               // Set background color to black and opaque
	glClearDepth(1.0f);                                 // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);                            // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);                             // Set the type of depth-test
	glShadeModel(GL_SMOOTH);                            // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
	glEnable(GL_MULTISAMPLE);

	glewInit();

	// -- Object creation
	camera = new Camera(vec3(0, 0, 8), ut->WIDTH, ut->HEIGHT);
	light = new Light(vec3(0, 0, -2), vec3(0.5f, 0.5f, 0.5f));

	GLuint triangleProgram = shaderLoader.CreateProgram("assets/shaders/specular.vs", "assets/shaders/specular.fs");
	Sphere = new GameModel(ModelType::kSphere, camera, "assets/textures/books.jpg", light, 0.65f, 4.3f);
	Sphere->SetProgram(triangleProgram);
	Sphere->SetPosition(vec3(-6, -0.5f, 0));
	Sphere->SetSpeed(0.005f);

	// Skybox
	GLuint cubemapProgram = shaderLoader.CreateProgram("assets/shaders/skybox.vs", "assets/shaders/skybox.fs");
	skybox = new Cubemap(cubemapProgram, camera);

	// Model
	GLuint modelProgram = shaderLoader.CreateProgram("assets/shaders/model.vs", "assets/shaders/model.fs");
	Nanosuit = new Model("assets/models/Nanosuit/nanosuit.obj", camera, modelProgram);
	Nanosuit->SetPosition(vec3(-0.05, -2, 2.75));
	Nanosuit->SetScale(vec3(0.04f));

	Castle = new Model("assets/models/Castle/Castle OBJ.obj", camera, modelProgram);
	Castle->SetPosition(vec3(0, -2, 0));
	Castle->SetScale(vec3(0.1f));



	// -- Object creation

	glutDisplayFunc(Render);
	glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(KeyUp);
	glutIdleFunc(Update);

	glutMainLoop();

	return (EXIT_SUCCESS);

}

void Render() {

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	skybox->Render();
	Sphere->Render();
	Castle->Draw();
	Nanosuit->Draw();

	glutSwapBuffers();

}

void Update() {

	GLfloat deltaTime = (GLfloat)glutGet(GLUT_ELAPSED_TIME);
	deltaTime *= 0.001f;

	Sphere->Update(deltaTime);

	// Light controls
	if (KeyCode[(unsigned char)'q'] == KeyState::Pressed) {
		light->MoveUp();
	}
	if (KeyCode[(unsigned char)'e'] == KeyState::Pressed) {
		light->MoveDown();
	}
	if (KeyCode[(unsigned char)'a'] == KeyState::Pressed) {
		light->MoveLeft();
	}
	if (KeyCode[(unsigned char)'d'] == KeyState::Pressed) {
		light->MoveRight();
	}
	if (KeyCode[(unsigned char)'w'] == KeyState::Pressed) {
		light->MoveForward();
	}
	if (KeyCode[(unsigned char)'s'] == KeyState::Pressed) {

		light->MoveBackward();
	}

}

void KeyDown(unsigned char key, int x, int y) {

	KeyCode[key] = KeyState::Pressed;
	cout << "Key pressed: " << key << "\n";

}

void KeyUp(unsigned char key, int x, int y) {

	KeyCode[key] = KeyState::Released;
	cout << "Key Released: " << key << "\n";

}