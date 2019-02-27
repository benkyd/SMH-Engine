#ifndef SMHENGINE_SRC_UTIL_UTIL_H_
#define SMHENGINE_SRC_UTIL_UTUL_H_

#include <glad/glad.hpp>
#include <glm/glm.hpp>
#include <vector>

#include <tiny_obj_loader.h>

struct ObjLMesh {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
};

void OBJLtoGLM(ObjLMesh& mesh, 
               std::vector<glm::vec3>& outVert,
               std::vector<glm::vec3>& outNorm,
               std::vector<glm::vec3>& outTexCoord,
               std::vector<GLuint>& outIndices);

void UintToGLuint(ObjLMesh& mesh,
                  std::vector<GLuint>& outIndices);

// void OBJLVec3toGLM(objl::Vector3& inVec, glm::vec3& outVec);

#endif
