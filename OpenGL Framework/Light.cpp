#include "Light.h"

Light::Light() {}

Light::Light(glm::vec3 _position, glm::vec3 _color) {

	position = _position;
	color = _color;
	rotationAxis = glm::bvec3(0.0f, 0.0f, 1.0f);
	speed = 0.1f;

}

Light::~Light() {}

void Light::SetRotation(glm::vec3 angle) {

	this->angle = angle;
}

void Light::SetRotationAxis(glm::vec3 rotationAxis) {

	this->rotationAxis = rotationAxis;
}

void Light::SetPosition(glm::vec3 _position) {


	this->position = _position;

}

void Light::SetColor(glm::vec3 _color) {

	this->color = _color;
}

void Light::SetSpeed(float _speed) {

	this->speed = _speed;

}

void Light::MoveForward() {

	position -= glm::vec3(0.0f, 0.0f, 1.0f) * speed;
}

void Light::MoveBackward() {

	position += glm::vec3(0.0f, 0.0f, 1.0f) * speed;
}

void Light::MoveLeft() {

	position -= glm::vec3(1.0f, 0.0f, 0.0f) * speed;
}

void Light::MoveRight() {

	position += glm::vec3(1.0f, 0.0f, 0.0f) * speed;
}

void Light::MoveUp() {

	position += glm::vec3(0.0f, 1.0f, 0.0f) * speed;
}

void Light::MoveDown() {

	position -= glm::vec3(0.0f, 1.0f, 0.0f) * speed;
}

void Light::Rotate(glm::vec3 axis) {

	this->angle.x += axis.x * speed * 20;
	this->angle.y += axis.y * speed * 20;
	this->angle.z += axis.z * speed * 20;
}

glm::vec3 Light::GetPosition() {

	return position;
}

glm::vec3 Light::GetColor() {

	return this->color;
}

glm::vec3 Light::GetRotation() {

	return this->angle;
}

glm::vec3 Light::GetRotationAxis() {

	return rotationAxis;
}