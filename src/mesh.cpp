#include "mesh.h"

Mesh::Mesh() {
	
}

Mesh::Mesh(std::string objPath) {
	Logger logger;

	ObjLMesh mesh;
	std::string warn, err;

	bool canLoad = tinyobj::LoadObj(&mesh.attrib, &mesh.shapes, &mesh.materials, &warn, &err, objPath.c_str());

	if (!err.empty() || !canLoad) {
		logger << LOGGER_ERROR << "Cannot load obj '" << objPath << "': " << err << LOGGER_ENDL;
		return;
	}

	if (!warn.empty()) {
		logger << LOGGER_WARN << "Warning from obj loader while loading obj '" << objPath << "': " << warn << LOGGER_ENDL;
	}

	logger << LOGGER_INFO << "Loaded: " << objPath << LOGGER_ENDL;

	loadFromObj(mesh);
}

Mesh::Mesh(ObjLMesh mesh) {
	// loadFromObj(objMesh);
}

void Mesh::loadFromObj(ObjLMesh mesh) {
	OBJLtoGLM(mesh, vertices, normals, texCoords, indices);
	// OBJLtoIndices(mesh, indices);

	//Logger logger;
	//for (int i = 0; i < 100; i++) {
	//	logger << LOGGER_DEBUG << normals[i].x << " " << normals[i].y << " " << normals[i].z << LOGGER_ENDL;
	//}
}

void Mesh::setup() {
	Logger logger;

	glGenVertexArrays(1, &VAOid);
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &indexBuffer);

	glBindVertexArray(VAOid);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	std::vector<glm::vec3> toGpu;
	toGpu.insert(toGpu.end(), vertices.begin(), vertices.end());
	toGpu.insert(toGpu.end(), normals.begin(), normals.end());
	toGpu.insert(toGpu.end(), texCoords.begin(), texCoords.end());

	glBufferData(GL_ARRAY_BUFFER, toGpu.size() * sizeof(glm::vec3), 
				 &toGpu[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint),
				 &indices[0], GL_STATIC_DRAW);

	// Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 
						 (const void*)0);

	// Normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 
						 (const void*)(vertices.size() * sizeof(glm::vec3)));

	// TexCoords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 
						 (const void*)((vertices.size() + texCoords.size()) * sizeof(glm::vec3)));

	logger << LOGGER_INFO << "Mesh setup" << LOGGER_ENDL;

	glBindVertexArray(0);
}

void Mesh::bind() {
	glBindVertexArray(VAOid);
}

void Mesh::render(Shader& shader) {

	// Model matrice
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, { -170.0f, -170.0f, -170.0f });
	model = glm::rotate(model, glm::radians(-160.0f + this->rotation), glm::vec3(0.0f, 1.0f, 0.0f));
	// Gets uniform for model matrice, to be used later
	GLint uniTrans = glGetUniformLocation(shader.getProgram(), "model");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(model));


	// View matrice
	glm::mat4 view = glm::lookAt(
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.4f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);
	// Get uniform and send it to the GPU
	GLint uniView = glGetUniformLocation(shader.getProgram(), "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));

	// Projection matrice
	glm::mat4 proj = glm::perspective(glm::radians(45.0f), 1280.0f / 720.0f, 1.0f, 1000.0f);//camera.perspective;
	// Get uniform and send it to the GPU
	GLint uniProj = glGetUniformLocation(shader.getProgram(), "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));


	glm::vec3 lightPos = { -2.0f, 4.0f, -1.0f };

	GLint uniLight = glGetUniformLocation(shader.getProgram(), "lightpos");
	glUniformMatrix3fv(uniLight, 1, GL_FALSE, glm::value_ptr(lightPos));

	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}

void Mesh::unbind() {
	glBindVertexArray(0);
}
