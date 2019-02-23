#ifndef SMHENGINE_SRC_MESH_H_
#define SMHENGINE_SRC_MESH_H_

#include <string>
#include <vector>

#include <glad/glad.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <OBJLoader.h>

#include <logger.h>
#include "./util/util.h"

class Shader;

class Mesh {
public:
    Mesh();
    Mesh(std::string objPath);
	Mesh(objl::Mesh objMesh);

	void loadFromObj(objl::Mesh objMesh);
    void setup();

    void bind();
    void render(Shader& shader);
    static void unbind();

    GLuint VAOid;

    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
	// This is a vec3 so it can all pop into
	//one buffer :)
    std::vector<glm::vec3> texCoords;
    std::vector<GLuint> indices;
private:
    GLuint vertexBuffer;
    GLuint indexBuffer;
};

#endif
