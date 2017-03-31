#version 430 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normVec;
layout (location = 2) in vec2 texCoord;

out vec2 TexCoord;
out vec3 OutNormVec;
out vec3 OutFragPosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform mat4 transform;

void main(void) {

	gl_Position = projection * view * model * vec4(position, 1.0f);

	OutFragPosition = vec3(model * vec4(position, 1.0f));

	OutNormVec = mat3(transpose(inverse(model))) * normVec;

	TexCoord = vec2(texCoord.x, 1 - texCoord.y);

}