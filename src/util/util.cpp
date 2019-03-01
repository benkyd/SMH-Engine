#include "util.h"

#include <unordered_map>

#include <logger.h>

#include "../mesh.h"


void OBJLtoGLM(ObjLMesh& mesh, 
               std::vector<glm::vec3>& outVert,
               std::vector<glm::vec3>& outNorm,
               std::vector<glm::vec3>& outTexCoord,
               std::vector<GLuint>& outIndices) {

    std::unordered_map<glm::vec3, uint64_t> uniqueVertices {{{1.0f, 1.0f, 1.0f}, 1}};

    for (const auto &shape : mesh.shapes) {
        for (const auto& index : shape.mesh.indices) {
            glm::vec3 vertex {
                mesh.attrib.vertices[3 * index.vertex_index + 0],
                mesh.attrib.vertices[3 * index.vertex_index + 1],
                mesh.attrib.vertices[3 * index.vertex_index + 2]
            };

            // outNorm.push_back({
            //     mesh.attrib.normals[3 * index.normal_index + 0],
            //     mesh.attrib.normals[3 * index.normal_index + 1],
            //     mesh.attrib.normals[3 * index.normal_index + 2]
            // });

            // outTexCoord.push_back({
            //     mesh.attrib.texcoords[2 * index.texcoord_index + 0],
            //     mesh.attrib.texcoords[2 * index.texcoord_index + 1],
            //     0.0f
            // });

            if (uniqueVertices.count(vertex) == 0) {
                uniqueVertices[vertex] = static_cast<uint32_t>(outVert.size());
                outVert.push_back(vertex);
            }

            outIndices.push_back(uniqueVertices[vertex]);
        }
    }

    ComputeNormals(outNorm, outVert, outIndices);
}

void ComputeNormals(std::vector<glm::vec3>& normals, 
                    std::vector<glm::vec3>& vertices,
                    std::vector<GLuint>& elements) {

    normals.resize(vertices.size(), glm::vec3(0.0, 0.0, 0.0));
    for (int i = 0; i < elements.size(); i += 3) {
        GLushort ia = elements[i];
        GLushort ib = elements[i+1];
        GLushort ic = elements[i+2];
        glm::vec3 normal = glm::normalize(glm::cross(
        glm::vec3(vertices[ib]) - glm::vec3(vertices[ia]),
        glm::vec3(vertices[ic]) - glm::vec3(vertices[ia])));
        normals[ia] = normals[ib] = normals[ic] = normal;
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
