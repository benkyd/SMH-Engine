#version 330 core

in vec3 Normal;
in vec3 FragPos;
in vec4 FragPosLightSpace;

uniform vec3 lightPos;
uniform vec3 viewPos;

out vec4 outColour;

vec3 objectColour = vec3(1.0, 1.0, 1.0);
vec3 lightColour = vec3(0.7, 0.3, 0.65);
// vec3 lightColour = vec3(0.3, 0.85, 1.0);

void main() {
    vec3 normal = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = diff * lightColour;


    float specularStrength = 1;

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, normal);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColour;


    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColour;

    vec3 result = (ambient + diffuse + specular) * objectColour;   

    outColour = vec4(result, 1.0);
}
