#version 330

// Input vertex attributes (from vertex shader)
in vec3 fragPosition;
in vec2 fragTexCoord;
in vec4 fragColor;
in vec3 fragNormal;

// Output fragment color
out vec4 finalColor;

#define MAX_LIGHTS 4

struct Light {
    int enabled;
    int type;
    vec3 position;
    vec3 target;
    vec4 color;
};
uniform Light lights[MAX_LIGHTS];

// NOTE: Add here your custom variables

void main()
{
    // // Texel color fetching from texture sampler
    // vec4 texelColor = texture(texture0, fragTexCoord);

    // // NOTE: Implement here your fragment shader code

    // finalColor = texelColor*colDiffuse;
    vec3 lightNormal = normalize(lights[0].position - lights[0].target);
    finalColor = vec4(lightNormal, 1.0);
}

