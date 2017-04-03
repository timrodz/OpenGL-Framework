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
#include "GameModel.h"
#include "Camera.h"
#include "Cubemap.h"

using std::cout;
using glm::vec3;

// Classes
Utils* ut;
ShaderLoader shaderLoader;
Camera* camera;
Light* light;
GameModel* triangle;
Cubemap* skybox;

unsigned char KeyCode[255];

void Render();
void Update();
void KeyDown(unsigned char key, int x, int y);
void KeyUp(unsigned char key, int x, int y);
void AnimateModel(GameModel* _model, vec3 _moveDirection);

int main(int argc, char **argv) {

	// init glut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(GLUT_WINDOW_WIDTH / 2, GLUT_WINDOW_HEIGHT / 2);
	glutInitWindowSize(ut->WIDTH, ut->HEIGHT);
	glutCreateWindow("OpenGL Framework - Juan Rodriguez");

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);               // Set background color to black and opaque
	glClearDepth(1.0f);                                 // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);                            // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);                             // Set the type of depth-test
	glShadeModel(GL_SMOOTH);                            // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections

	glewInit();

	//glewExperimental = true;

	// -- Object creation
	camera = new Camera(vec3(0, 0, 8), ut->WIDTH, ut->HEIGHT);
	light = new Light(vec3(0, 0, -2), vec3(0.5f, 0.5f, 0.5f));

	GLuint triangleProgram = shaderLoader.CreateProgram("shaders/specular.vs", "shaders/specular.fs");
	triangle = new GameModel(ModelType::kSphere, camera, "textures/books.jpg", light, 0.65f, 4.3f);
	triangle->SetProgram(triangleProgram);
	triangle->SetPosition(vec3(-3, -0.5f, 0));
	triangle->SetSpeed(0.005f);

	// Skybox
	GLuint cubemapProgram = shaderLoader.CreateProgram("shaders/skybox.vs", "shaders/skybox.fs");
	skybox = new Cubemap(cubemapProgram, camera);

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

	triangle->Render();
	skybox->Render();

	glutSwapBuffers();

}

void Update() {

	GLfloat deltaTime = (GLfloat)glutGet(GLUT_ELAPSED_TIME);
	deltaTime *= 0.001f;

	triangle->Update(deltaTime);

	if (KeyCode[(unsigned char)'q'] == KeyState::Pressed) {
		light->MoveDown();
	}
	if (KeyCode[(unsigned char)'e'] == KeyState::Pressed) {
		light->MoveUp();
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

// Function AnimateModel
// Animates the model by moving it in a few spaces in the given direction
// author : Juan Rodriguez
// param _model : The game model that will be animated
// param _moveDirection : The direction of the movement
void AnimateModel(GameModel* _model, vec3 _moveDirection) {
	


}