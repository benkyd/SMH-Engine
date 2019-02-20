#version 330 

in vec3 position;
in vec3 normal;

out vec3 Normal;
out vec3 FragPos;
out vec4 FragPosLightSpace;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

uniform mat4 lightSpaceMatrix;

void main() {
    gl_Position = proj * view * model * vec4(position, 1.0);
    FragPos = vec3(model * vec4(position, 1.0));
    FragPosLightSpace = lightSpaceMatrix * vec4(FragPos, 1.0);
    Normal = mat3(model) * normal;
}
