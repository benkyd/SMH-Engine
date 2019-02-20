#ifndef SRC_OBJECT_H_
#define SRC_OBJECT_H_

// General includes
#include <vector>

// GL includes
#include <glad/glad.h>

#if _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Custom includes
#include <logger.h>

void LoadOBJ(Logger& logger, 
             std::string file,
             std::vector<glm::vec3>& vertices,
             std::vector<glm::vec3>& normals,
             std::vector<GLushort>& elements);

void FlatShade(std::vector<glm::vec3>& vertices,
               std::vector<glm::vec3>& normals,
               std::vector<GLushort>& elements);

#endif
