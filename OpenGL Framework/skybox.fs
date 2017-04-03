#version 430 core

in vec3 textureDirection;
out vec4 color;

uniform samplerCube cubeSampler;

void main()
{
    color = texture(cubeSampler, textureDirection);
}