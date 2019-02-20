#version 330

in vec3 Normal;
in vec3 FragPos;
in vec4 FragPosLightSpace;

uniform vec3 lightPos;

out vec4 outColour;

uniform sampler2D diffuseTexture;
uniform sampler2D shadowMap;

vec3 viewPos = vec3(0.0, 0.0, 0.0);
vec3 objectColour = vec3(1.0, 1.0, 1.0);
vec3 lightColour = vec3(1.0, 1.0, 1.0);
// vec3 lightColour = vec3(0.1, 0.45, 0.9);

float calculateShadow(vec4 fragPosLightSpace) {
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    projCoords = projCoords * 0.5 + 0.5;
    float closestDepth = texture(shadowMap, projCoords.xy).r; 
    float currentDepth = projCoords.z;
    float shadow = currentDepth > closestDepth  ? 1.0 : 0.0;

    return shadow;
}

void main() {
    vec3 normal = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = diff * lightColour;


    float specularStrength = 0.2;

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, normal);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColour;


    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColour;

    float shadow = calculateShadow(FragPosLightSpace);       
    vec3 result = (ambient + (1.0 - shadow) * (diffuse + specular)) * objectColour;   

    outColour = vec4(result, 1.0);
}
