#pragma once

#include "camera.h"
#include "utils.h"
#include <vector>

class Cubemap
{
public:

	Cubemap(GLuint program, Camera* camera);
	~Cubemap();
	void Render();

	Camera* camera;

	std::vector<VertexFormat> vertices;
	std::vector<GLuint>indices;

	GLuint loadCubemap(std::vector<const GLchar*> faces);

	GLuint vao;
	GLuint vbo;
	GLuint ebo;
	GLuint texture;
	GLuint program;
	GLuint getTextureID();

private:

	//GLuint program;
	//GLuint vao, vbo, ebo;
	//GLuint texture, texture2;
	//vec3 m_position;
	//GLsizei m_numVertices;
	//Camera m_Camera;
	//ModelType m_ModelType;
};