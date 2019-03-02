#ifndef SMHENGINE_SRC_OBJECT_H_
#define SMHENGINE_SRC_OBJECT_H_

#include <string>
#include <vector>

#include <glad/glad.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <OBJLoader.h>

#include <logger.h>

#include "model.h"
#include "shader.h"

class Object {
public:
	Object();

	std::vector<Model> models;
	std::vector<Shader> shaders;
};

#endif
