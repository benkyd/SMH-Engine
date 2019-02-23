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

void Mesh::settup() {

}

void Mesh::bind() {

}

void Mesh::render(Shader& shader) {

}

void Mesh::unbind() {

}
