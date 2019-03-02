#ifndef SMHENGINE_SRC_UTIL_UTIL_H_
#define SMHENGINE_SRC_UTIL_UTUL_H_

#include <glad/glad.hpp>
// This is so that i can use 
// glm::vec3 inside of an
// std::unordered_map as it's
// experimental for some reason
// smh
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>
#include <glm/glm.hpp>
#include <vector>

#include <tiny_obj_loader.h>

struct ObjLMesh;

void OBJLtoGLM(ObjLMesh& mesh, 
               std::vector<glm::vec3>& outVert,
               std::vector<glm::vec3>& outNorm,
               std::vector<glm::vec3>& outTexCoord,
               std::vector<GLuint>& outIndices);

void ComputeNormals(std::vector<glm::vec3>& normals, 
                    std::vector<glm::vec3>& vertices,
                    std::vector<GLuint>& elements);

void UintToGLuint(ObjLMesh& mesh,
                  std::vector<GLuint>& outIndices);

// void OBJLVec3toGLM(objl::Vector3& inVec, glm::vec3& outVec);

#endif
