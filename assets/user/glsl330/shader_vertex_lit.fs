#version 330

// Input vertex attributes (from vertex shader)
in vec3 fragPosition;
in vec2 fragTexCoord;
in vec4 fragColor;
in vec3 fragNormal;

// Output fragment color
out vec4 finalColor;

// NOTE: Add here your custom variables

void main()
{
    // // Texel color fetching from texture sampler
    // vec4 texelColor = texture(texture0, fragTexCoord);

    // // NOTE: Implement here your fragment shader code

    // finalColor = texelColor*colDiffuse;
    finalColor = vec4(fragTexCoord, 1.0, 1.0);
}

