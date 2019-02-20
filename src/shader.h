#ifndef SRC_SHADER_H_
#define SRC_SHADER_H_

#include <glad/glad.h>
#include <string>
#include <logger.h>

class Shader {
public:
	Shader(Logger& logger);

    Shader& use();
    Shader& link();
    Shader& attatch();
    Shader& load(GLenum type, std::string sourceLoc);
    Shader& load(std::string sourceLoc);
	Shader& reload();

    GLuint getProgram();
    GLuint getVertex();
    GLuint getFragment();

    virtual ~Shader();
private:
    Shader(Shader const &) = delete;
    Shader & operator=(Shader const &) = delete;
  
    GLuint m_program;
    GLuint m_vert;
    GLuint m_frag;

    std::string m_vertSource;
    std::string m_fragSource;
    std::string m_vertLoc;
    std::string m_fragLoc;

	Logger& logger;

    GLint m_status;
};

#endif
