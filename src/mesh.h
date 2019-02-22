#ifndef SMHENGINE_SRC_MESH_H_
#define SMHENGINE_SRC_MESH_H_

#include <string>
#include <vector>

#include <OBJLoader.h>

#include <glad/glad.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "./util/util.h"

class Shader;

class Mesh {
public:
    Mesh();
    Mesh(std::string objPath);
	Mesh(objl::Mesh objMesh);

	void loadFromObj(objl::Mesh objMesh);
    void settup();

    void bind();
    void render(Shader& shader);
    void unbind();

    GLuint VAOid;

    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> texCoords;
    std::vector<glm::vec3> normals;
    std::vector<GLuint> indices;
private:
    GLuint vertexBuffer;
    GLuint indexBuffer;
};

#endif
