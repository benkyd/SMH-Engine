#include "material.h"

Material::Material() {

}

Material::Material(std::string objPath) {
	// Logger logger;
	// objl::Loader loader;
	// bool canLoad = loader.LoadFile(objPath);

	// if (!canLoad) {
	// 	logger << LOGGER_ERROR << "Cannot load material '" << objPath << "'" << LOGGER_ENDL;
	// 	return;
	// }

	// loadFromObj(loader.LoadedMeshes[0]);
}

// Material::Material(objl::Mesh objMesh) {
// 	loadFromObj(objMesh);
// }

// void Material::loadFromObj(objl::Mesh objMesh) {
// 	loadFromMat(objMesh.MeshMaterial);
// }

// void Material::loadFromMat(objl::Material mat) {
// 	this->name = mat.name;
// 	OBJLVec3toGLM(mat.Ka, this->Ka);
// 	OBJLVec3toGLM(mat.Kd, this->Kd);
// 	OBJLVec3toGLM(mat.Ks, this->Ks);
// 	this->Ns = mat.Ns;
// 	this->Ni = mat.Ni;
// 	this->d = mat.d;
// 	this->illum = mat.illum;
// 	this->map_Ka = mat.map_Ka;
// 	this->map_Kd = mat.map_Kd;
// 	this->map_Ks = mat.map_Ks;
// 	this->map_Ns = mat.map_Ns;
// 	this->map_d = mat.map_d;
// 	this->map_bump = mat.map_bump;
// }
