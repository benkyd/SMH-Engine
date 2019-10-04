#ifndef SMHENGINE_SRC_CAMERA_H_
#define SMHENGINE_SRC_CAMERA_H_

#if _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
public:
    Camera();

    void updateView();
    glm::mat4 getViewMatrix();
    glm::vec3 getPos();

    void handleMouse(SDL_Event e);
    void moveCamera();
    void mouseMoved(glm::vec2 mouseDelta);

    float mouseSensitivity = 0.0025f;
    float cameraSpeed = 1.12f;

private:
    float roll, pitch, yaw;
    glm::vec3 eyeVector;
    glm::mat4 viewMatrix;
};

#endif
