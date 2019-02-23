#include "mesh.h"

Mesh::Mesh() {
	
}

Mesh::Mesh(std::string objPath) {

}

Mesh::Mesh(objl::Mesh objMesh) {
    OBJLtoGLM(objMesh.Vertices, vertices, normals, texCoords);
    // objMesh.Vertices includes normals, positions and texcoords
    // it must convert them to the neccesary GLM shit
}

void Mesh::loadFromObj(objl::Mesh objmesh) {

}

void Mesh::settup() {

}

void Mesh::bind() {

}

void Mesh::render(Shader& shader) {

}

void Mesh::unbind() {

}
