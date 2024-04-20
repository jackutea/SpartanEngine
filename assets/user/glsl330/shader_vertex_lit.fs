#version 330

// Input vertex attributes (from vertex shader)
// in vec2 fragTexCoord;
in vec4 fragColor;

// Output fragment color
out vec4 finalColor;

// NOTE: Add here your custom variables

void main()
{
    // // Texel color fetching from texture sampler
    // vec4 texelColor = texture(texture0, fragTexCoord);

    // // NOTE: Implement here your fragment shader code

    // finalColor = texelColor*colDiffuse;
    finalColor = fragColor;
}

