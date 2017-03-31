#pragma once

#include "Utils.h"

class Light {
public:
	Light();
	Light(glm::vec3 _position, glm::vec3 _color);
	~Light();

	//void Update(GLfloat time);
	//void Render();

	void SetPosition(glm::vec3 _position);
	//void SetScale(glm::vec3 _scale);
	void SetRotation(glm::vec3 angle);
	void SetRotationAxis(glm::vec3 rotationAxis);

	void SetColor(glm::vec3 _color);
	//void SetCamera(Camera* camera);
	void SetSpeed(float _speed);
	//void SetProgram(GLuint program);
	//void SetTexture(std::string texFileName);
	//void SetSpecularStrength(float strength);

	glm::vec3 GetPosition();
	//glm::vec3 GetScale();
	glm::vec3 GetRotation();
	glm::vec3 GetRotationAxis();
	glm::vec3 GetColor();

	void MoveForward();
	void MoveBackward();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void Rotate(glm::vec3 axis);

private:
	//bool bIsTextureSet = false;

	float speed;

	//std::vector<VertexFormat>vertices;
	//std::vector<GLuint>indices;

	glm::vec3 position;
	//glm::vec3 scale;
	glm::vec3 angle;
	glm::vec3 rotationAxis;
	glm::vec3 color;

	//GLuint vao;
	//GLuint vbo;
	//GLuint ebo;
	//GLuint texture;
	//GLuint program;

	//float specularStrength;
	//float ambientStrength;

};