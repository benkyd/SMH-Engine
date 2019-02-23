#include "mesh.h"

Mesh::Mesh() {
	
}

Mesh::Mesh(std::string objPath) {
	Logger logger;
	objl::Loader loader;
	bool canLoad = loader.LoadFile(objPath);

	if (!canLoad) {
		logger << LOGGER_ERROR << "Cannot load obj '" << objPath << "'" << LOGGER_ENDL;
		return;
	}

	OBJLtoGLM(loader.LoadedMeshes[0].Vertices, vertices, normals, texCoords);
}

Mesh::Mesh(objl::Mesh objMesh) {
    OBJLtoGLM(objMesh.Vertices, vertices, normals, texCoords);
	UintToGLuint(objMesh.Indices, indices);
}

void Mesh::loadFromObj(objl::Mesh objMesh) {
	OBJLtoGLM(objMesh.Vertices, vertices, normals, texCoords);
	UintToGLuint(objMesh.Indices, indices);
}

void Mesh::setup() {
	glGenVertexArrays(1, &VAOid);
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &indexBuffer);

	glBindVertexArray(VAOid);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	std::vector<glm::vec3> toGpu;
	toGpu.insert(toGpu.end(), vertices.begin(), vertices.end());
	toGpu.insert(toGpu.end(), normals.begin(), normals.end());
	toGpu.insert(toGpu.end(), texCoords.begin(), texCoords.end());

	glBufferData(GL_ARRAY_BUFFER, toGpu.size() * sizeof(glm::vec3), 
				 &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint),
				 &indices[0], GL_STATIC_DRAW);

	// Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 
						 (const void*)0);

	// Normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 
						 (const void*)(vertices.size() * sizeof(glm::vec3)));

	// TexCoords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 
						 (const void*)((vertices.size() + texCoords.size()) * sizeof(glm::vec3)));

	glBindVertexArray(0);
}

void Mesh::bind() {
	glBindVertexArray(VAOid);
}

void Mesh::render(Shader& shader) {
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}

void Mesh::unbind() {
	glBindVertexArray(0);
}
