//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2016 Media Design School
//
// File Name   : Camera.cpp
// Description : The camera that handles the view and projection matrices
// Author	   : Juan Rodriguez
// Mail		   : juan.rod6618@mediadesignschool.com
//

#include "Camera.h"

Camera::Camera() {}

Camera::Camera(glm::vec3 _position, int _width, int _height) {

	position = _position;
	up = glm::vec3(0, 1, 0);
	forward = glm::vec3(0, 0, -1);

	width = _width;
	height = _height;

	speed = 1.5f;

	viewMatrix = GetViewMatrix();
	projectionMatrix = GetProjectionMatrix();

}

// Creates a camera with custom paramaters
// author		   : Juan Rodriguez
// param positions : the positions that the camera will face
// param _width    : the width of the camera
// param _height   : the height of the camera
// return		   : void
Camera::Camera(glm::vec3 positions[3], int _width, int _height) {

	position = positions[0];
	forward = positions[1];
	up = positions[2];

	width = _width;
	height = _height;

	viewMatrix = GetViewMatrix();
	projectionMatrix = GetProjectionMatrix();

}

// Create a view matrix with the lookAt function
// author : Juan Rodriguez
// return : mat4
glm::mat4 Camera::GetViewMatrix() const {

	return (glm::lookAt(position, position + forward, up));

}

// Create a projection matrix using the perspective function
// author : Juan Rodriguez
// return : mat4
glm::mat4 Camera::GetProjectionMatrix() const {

	return (glm::perspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 1000.0f));

}

glm::vec3 Camera::GetPosition() const {
	return (position);
}

void Camera::SetSpeed(float _speed) {
	this->speed = _speed;
}

void Camera::MoveForward() {
	
	//position -= glm::vec3(0.0f, 0.0f, 1.0f) * speed;
		

}

void Camera::MoveBackward() {
	
	//position += glm::vec3(0.0f, 0.0f, 1.0f) * speed;
		

}

void Camera::MoveLeft() {
	
	//position -= glm::vec3(1.0f, 0.0f, 0.0f) * speed;
		

}

void Camera::MoveRight() {
	
	//position += glm::vec3(1.0f, 0.0f, 0.0f) * speed;
		

}

void Camera::MoveUp() {
	
	//position += glm::vec3(0.0f, 1.0f, 0.0f) * speed;
		

}

void Camera::MoveDown() {
	position -= glm::vec3(0.0f, 1.0f, 0.0f) * speed;
}