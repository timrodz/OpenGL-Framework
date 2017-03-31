#include "Utils.h"


glm::vec3 Utils::alphaConversionFromRGB(int r, int g, int b) {
	//glm::vec3 alphaColor(_color.r / 255, _color.g / 255, _color.b / 255);
	return glm::vec3(r / 255, g / 255, b / 255);
}

void Utils::setTriData(std::vector<VertexFormat>& vertices, std::vector<GLuint>&indices) {

	std::vector<VertexFormat> Vertices;

	Vertices.push_back(VertexFormat(Position(0.0f, 1.0f, 0.0f), TexCoord(1, 1), Normals(0.0f, 0.0f, 1.0)));
	Vertices.push_back(VertexFormat(Position(1.0, 0.0, 0.0), TexCoord(0, 1), Normals(0.0f, 0.0f, 1.0)));
	Vertices.push_back(VertexFormat(Position(-1.0, 0.0, 0.0), TexCoord(1, 0), Normals(0.0f, 0.0f, 1.0)));


	std::vector<GLuint>Indices;
	Indices.push_back(0);
	Indices.push_back(1);
	Indices.push_back(2);

	//Indices[0] = 0; Indices[1] = 1; Indices[2] = 2;

	vertices.clear(); indices.clear();

	vertices = Vertices;
	indices = Indices;
}

void Utils::setQuadData(std::vector<VertexFormat>& vertices, std::vector<GLuint>& indices) {

	std::vector<VertexFormat> Vertices;
	Vertices.push_back(VertexFormat(Position(-1.0f, -1.0, 0.0), TexCoord(-1.0, -1.0), Normals(0.0f, 0.0f, 1.0)));
	Vertices.push_back(VertexFormat(Position(-1.0, 1.0, 0.0), TexCoord(-1.0, 1.0), Normals(0.0f, 0.0f, 1.0)));
	Vertices.push_back(VertexFormat(Position(1.0, 1.0, 0.0), TexCoord(1.0, 1.0), Normals(0.0f, 0.0f, 1.0)));
	Vertices.push_back(VertexFormat(Position(1.0, -1.0, 0.0), TexCoord(1.0, -1.0), Normals(0.0f, 0.0f, 1.0)));

	std::vector<GLuint> Indices;
	Indices.push_back(0); Indices.push_back(1); Indices.push_back(2);
	Indices.push_back(0); Indices.push_back(2); Indices.push_back(3);
	vertices.clear(); indices.clear();
	vertices = Vertices;
	indices = Indices;

}

void Utils::setCubeData(std::vector<VertexFormat>& vertices, std::vector<GLuint>& indices) {

	std::vector<VertexFormat> Vertices;
	//back
	Vertices.push_back(VertexFormat(Position(-1.0f, -1.0, -1.0), TexCoord(0.0, 1.0), Normals(0.0f, 0.0f, -1.0)));
	Vertices.push_back(VertexFormat(Position(1.0, -1.0, -1.0), TexCoord(0.0, 0.0), Normals(0.0f, 0.0f, -1.0)));
	Vertices.push_back(VertexFormat(Position(1.0, 1.0, -1.0), TexCoord(1.0, 0.0), Normals(0.0f, 0.0f, -1.0)));
	Vertices.push_back(VertexFormat(Position(-1.0, 1.0, -1.0), TexCoord(1.0, 1.0), Normals(0.0f, 0.0f, -1.0)));

	//front
	Vertices.push_back(VertexFormat(Position(-1.0f, -1.0f, 1.0f), TexCoord(1.0, 1.0), Normals(0.0f, 0.0f, 1.0)));
	Vertices.push_back(VertexFormat(Position(1.0f, -1.0f, 1.0f), TexCoord(0.0, 1.0), Normals(0.0f, 0.0f, 1.0)));
	Vertices.push_back(VertexFormat(Position(1.0f, 1.0f, 1.0f), TexCoord(0.0, 0.0), Normals(0.0f, 0.0f, 1.0)));
	Vertices.push_back(VertexFormat(Position(-1.0f, 1.0f, 1.0f), TexCoord(1.0, 0.0), Normals(0.0f, 0.0f, 1.0)));

	//left
	Vertices.push_back(VertexFormat(Position(-1.0, 1.0, 1.0), TexCoord(0.0, 0.0), Normals(-1.0f, 0.0f, 0.0)));
	Vertices.push_back(VertexFormat(Position(-1.0, 1.0, -1.0), TexCoord(1.0, 0.0), Normals(-1.0f, 0.0f, 0.0)));
	Vertices.push_back(VertexFormat(Position(-1.0, -1.0, -1.0), TexCoord(1.0, 1.0), Normals(-1.0f, 0.0f, 0.0)));
	Vertices.push_back(VertexFormat(Position(-1.0f, -1.0, 1.0), TexCoord(0.0, 1.0), Normals(-1.0f, 0.0f, 0.0)));

	//right
	Vertices.push_back(VertexFormat(Position(1.0, 1.0, 1.0), TexCoord(1.0, 0.0), Normals(1.0f, 0.0f, 0.0)));
	Vertices.push_back(VertexFormat(Position(1.0, 1.0, -1.0), TexCoord(0.0, 0.0), Normals(1.0f, 0.0f, 0.0)));
	Vertices.push_back(VertexFormat(Position(1.0f, -1.0, -1.0), TexCoord(0.0, 1.0), Normals(1.0f, 0.0f, 0.0)));
	Vertices.push_back(VertexFormat(Position(1.0, -1.0, 1.0), TexCoord(1.0, 1.0), Normals(1.0f, 0.0f, 0.0)));

	//bottom
	Vertices.push_back(VertexFormat(Position(-1.0f, -1.0, -1.0), TexCoord(1.0, 1.0), Normals(0.0f, -1.0f, 0.0)));
	Vertices.push_back(VertexFormat(Position(1.0, -1.0, -1.0), TexCoord(0.0, 1.0), Normals(0.0f, -1.0f, 0.0)));
	Vertices.push_back(VertexFormat(Position(1.0, -1.0, 1.0), TexCoord(0.0, 0.0), Normals(0.0f, -1.0f, 0.0)));
	Vertices.push_back(VertexFormat(Position(-1.0, -1.0, 1.0), TexCoord(1.0, 0.0), Normals(0.0f, -1.0f, 0.0)));

	//top
	Vertices.push_back(VertexFormat(Position(-1.0f, 1.0f, -1.0f), TexCoord(0.0, 1.0), Normals(0.0f, 1.0f, 0.0)));
	Vertices.push_back(VertexFormat(Position(1.0f, 1.0f, -1.0f), TexCoord(1.0, 1.0), Normals(0.0f, 1.0f, 0.0)));
	Vertices.push_back(VertexFormat(Position(1.0f, 1.0f, 1.0f), TexCoord(1.0, 0.0), Normals(0.0f, 1.0f, 0.0)));
	Vertices.push_back(VertexFormat(Position(-1.0f, 1.0f, 1.0f), TexCoord(0.0, 0.0), Normals(0.0f, 1.0f, 0.0)));





	std::vector<GLuint> Indices;
	//cubeIndices.push_back(IndexFormat(0, 1, 2));
	//cubeIndices.push_back(IndexFormat(0, 2, 3));
	//cubeIndices.push_back(IndexFormat(4, 5, 6));
	//cubeIndices.push_back(IndexFormat(4, 6, 7));
	//cubeIndices.push_back(IndexFormat(8, 9, 10));
	//cubeIndices.push_back(IndexFormat(8, 10, 11));
	//cubeIndices.push_back(IndexFormat(12, 13, 14));
	//cubeIndices.push_back(IndexFormat(12, 14, 15));
	//cubeIndices.push_back(IndexFormat(16, 17, 18));
	//cubeIndices.push_back(IndexFormat(16, 18, 19));
	//cubeIndices.push_back(IndexFormat(20, 21, 22));
	//cubeIndices.push_back(IndexFormat(20, 22, 23));
	Indices.push_back(0); Indices.push_back(1); Indices.push_back(2);
	Indices.push_back(2); Indices.push_back(3); Indices.push_back(0);

	Indices.push_back(4); Indices.push_back(5); Indices.push_back(6);
	Indices.push_back(6); Indices.push_back(7); Indices.push_back(4);

	Indices.push_back(8); Indices.push_back(9); Indices.push_back(10);
	Indices.push_back(10); Indices.push_back(11); Indices.push_back(8);

	Indices.push_back(12); Indices.push_back(13); Indices.push_back(14);
	Indices.push_back(12); Indices.push_back(14); Indices.push_back(15);

	Indices.push_back(16); Indices.push_back(17); Indices.push_back(18);
	Indices.push_back(18); Indices.push_back(19); Indices.push_back(16);

	Indices.push_back(20); Indices.push_back(21); Indices.push_back(22);
	Indices.push_back(22); Indices.push_back(23); Indices.push_back(20);

	vertices.clear(); indices.clear();
	vertices = Vertices;
	indices = Indices;
}


void Utils::setSphereData(std::vector<VertexFormat>& vertices, std::vector<GLuint>& indices) {

	std::vector<VertexFormat> Vertices;
	std::vector<GLuint> Indices;

	double latitudeBands = 30;
	double longitudeBands = 30;
	double radius = 1.0f;

	for (double latNumber = 0; latNumber <= latitudeBands; latNumber++) {
		double theta = latNumber * 3.14 / latitudeBands;
		double sinTheta = sin(theta);
		double cosTheta = cos(theta);

		for (double longNumber = 0; longNumber <= longitudeBands; longNumber++) {
			double phi = longNumber * 2 * 3.14 / longitudeBands;
			double sinPhi = sin(phi);
			double cosPhi = cos(phi);

			VertexFormat vs;

			vs.texCoord.u = 1 - (longNumber / longitudeBands); // u
			vs.texCoord.v = 1 - (latNumber / latitudeBands);   // v

			vs.normal.x = cosPhi * sinTheta;   // x
			vs.normal.y = cosTheta;            // y
			vs.normal.z = sinPhi * sinTheta;   // z

			vs.pos.x = radius * vs.normal.x;
			vs.pos.y = radius * vs.normal.y;
			vs.pos.z = radius * vs.normal.z;

			Vertices.push_back(vs);
		}
	}



	for (GLuint latNumber = 0; latNumber < latitudeBands; latNumber++) {
		for (GLuint longNumber = 0; longNumber < longitudeBands; longNumber++) {
			GLuint first = (latNumber * (longitudeBands + 1)) + longNumber;
			GLuint second = first + longitudeBands + 1;

			Indices.push_back(first);
			Indices.push_back(second);
			Indices.push_back(first + 1);

			Indices.push_back(second);
			Indices.push_back(second + 1);
			Indices.push_back(first + 1);

		}
	}

	vertices.clear(); indices.clear();
	vertices = Vertices;
	indices = Indices;

}