#pragma once

#include "Utils.h"
#include "Light.h"

class Camera {
public:
	Camera();
	~Camera();
	Camera(glm::vec3 _position, int _width, int _height);
	Camera(glm::vec3 positions[3], int _width, int _height);
	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;
	glm::vec3 GetPosition() const;

	void SetSpeed(float _speed);

	void MoveForward();
	void MoveBackward();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

private:
	int width, height;

	float speed;

	glm::vec3 position, up, forward;

	glm::mat4 viewMatrix, projectionMatrix;

};