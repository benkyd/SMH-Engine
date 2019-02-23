#include "util.h"

void OBJLtoGLM(std::vector<objl::Vertex>& inVertArr, 
               std::vector<glm::vec3>& outVert,
               std::vector<glm::vec3>& outNorm,
               std::vector<glm::vec2>& outTexCoord) {

    for (int i = 0; i < inVertArr.size(); i++) {

        glm::vec3 tempVert {inVertArr[i].Position.X, inVertArr[i].Position.Y, inVertArr[i].Position.Z};
        outVert.push_back(tempVert);

        glm::vec3 tempNorm {inVertArr[i].Normal.X, inVertArr[i].Normal.Y, inVertArr[i].Normal.Z};
        outNorm.push_back(tempNorm);

        glm::vec2 tempTexCoord {inVertArr[i].TextureCoordinate.X, inVertArr[i].TextureCoordinate.Y};
        outTexCoord.push_back(tempTexCoord);

    }

}

void UintToGLuint(std::vector<unsigned int>& inIndices,
                  std::vector<GLuint>& outIndices) {

    for (int i = 0; i < inIndices.size(); i++) {
        outIndices.push_back(inIndices[i]);
    }

}
