#ifndef SMHENGINE_SRC_UTIL_UTIL_H_
#define SMHENGINE_SRC_UTIL_UTUL_H_

#include <glad/glad.hpp>
#include <glm/glm.hpp>
#include <vector>
#include <OBJLoader.h>

void OBJLtoGLM(std::vector<objl::Vertex>& inVertArr, 
               std::vector<glm::vec3>& outVert,
               std::vector<glm::vec3>& outNorm,
               std::vector<glm::vec3>& outTexCoord);

void UintToGLuint(std::vector<unsigned int>& inIndices,
                  std::vector<GLuint>& outIndices);

void OBJLVec3toGLM(objl::Vector3& inVec, glm::vec3& outVec);

#endif
