#ifndef SMHENGINE_SRC_MESH_H_
#define SMHENGINE_SRC_MESH_H_

#include <string>
#include <vector>

#include <glad/glad.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <tiny_obj_loader.h>

#include <logger.h>
#include "shader.h"
#include "./util/util.h"

// Not in use yet
// Will be used as a vector, enabling
// the use of strides when sending the 
// vertex data to the GPU
struct Vertex {
	glm::vec3 vertice;
	glm::vec3 normal;
	glm::vec2 texCoord;
};

class Mesh {
public:
    Mesh();
    Mesh(std::string objPath);
	Mesh(tinyobj::attrib_t attribArr);

	void loadFromObj(tinyobj::attrib_t attribArr);
    void setup();

    void bind();
    void render(Shader& shader);
    static void unbind();

    GLuint VAOid;

	std::string name;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
	// This is a vec3 so it can all pop into
	//one buffer :)
    std::vector<glm::vec3> texCoords;
    std::vector<unsigned int> indices;
private:
    GLuint vertexBuffer;
    GLuint indexBuffer;
};

#endif
