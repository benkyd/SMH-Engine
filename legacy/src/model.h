#ifndef SMHENGINE_SRC_MODEL_H_
#define SMHENGINE_SRC_MODEL_H_

#include <string>
#include <vector>

#include <glad/glad.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <logger.h>

#include "mesh.h"
#include "material.h"

class Model {
public:
	Model();
	Model(std::string loadPath);

	std::vector<std::pair<Mesh, Material>> modelData;
};

#endif
