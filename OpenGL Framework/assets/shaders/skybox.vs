#version 430 core
layout (location = 0) in vec3 position;

out vec3 textureDirection;

uniform mat4 mvp;

void main(void)
{
	vec4 pos = mvp * vec4(position, 1.0);
	gl_Position = pos;
	textureDirection = position;
}



