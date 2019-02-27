#include "util.h"

#include <logger.h>

void OBJLtoGLM(ObjLMesh& mesh, 
               std::vector<glm::vec3>& outVert,
               std::vector<glm::vec3>& outNorm,
               std::vector<glm::vec3>& outTexCoord,
               std::vector<GLuint>& outIndices) {

    for (const auto &shape : mesh.shapes) {
        for (const auto& index : shape.mesh.indices) {

            outVert.push_back({
                mesh.attrib.vertices[3 * index.vertex_index + 0],
                mesh.attrib.vertices[3 * index.vertex_index + 1],
                mesh.attrib.vertices[3 * index.vertex_index + 2]
            });

            outNorm.push_back({
                mesh.attrib.normals[0],
                mesh.attrib.normals[0],
                mesh.attrib.normals[0]
            });

            outTexCoord.push_back({
                mesh.attrib.texcoords[2 * index.texcoord_index + 0],
                mesh.attrib.texcoords[2 * index.texcoord_index + 1],
                0.0f
            });
        }
    }

}

void UintToGLuint(ObjLMesh& mesh,
                  std::vector<GLuint>& outIndices) {
    
}



// void OBJLVec3toGLM(objl::Vector3& inVec, glm::vec3& outVec) {

// 	outVec.x = inVec.X;
// 	outVec.y = inVec.Y;
// 	outVec.z = inVec.Z;

// }
