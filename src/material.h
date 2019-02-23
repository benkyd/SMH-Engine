#ifndef SMHENGINE_SRC_MATERIAL_H_
#define SMHENGINE_SRC_MATERIAL_H_

#include <string>
#include <vector>

#include <glad/glad.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <OBJLoader.h>

#include <logger.h>
#include "./util/util.h"

class Material {
public:
	Material();
	Material(std::string objPath);
	Material(objl::Mesh objMesh);

	void loadFromObj(objl::Mesh objMesh);
	void loadFromMat(objl::Material mat);

	// Material Name
	std::string name;
	// Ambient Color
	glm::vec3 Ka;
	// Diffuse Color
	glm::vec3 Kd;
	// Specular Color
	glm::vec3 Ks;
	// Specular Exponent
	float Ns;
	// Optical Density
	float Ni;
	// Dissolve
	float d;
	// Illumination model 0->10
	// TODO: Make an enum for this
	int illum;
	// Ambient Texture Map
	std::string map_Ka;
	// Diffuse Texture Map
	std::string map_Kd;
	// Specular Texture Map
	std::string map_Ks;
	// Specular Hightlight Map
	std::string map_Ns;
	// Alpha Texture Map
	std::string map_d;
	// Bump Map
	std::string map_bump;
};

#endif
