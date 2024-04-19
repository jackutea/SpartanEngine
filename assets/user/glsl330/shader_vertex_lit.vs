#version 330

// Input vertex attributes
in vec3 vertexPosition; // location 0
in vec2 vertexTexCoord; // location 1
in vec3 vertexNormal;  // location 2
in vec4 vertexColor;  // location 3

// Input uniform values
uniform mat4 mvp;

// Output vertex attributes (to fragment shader)
out vec2 fragTexCoord;
out vec4 fragColor;

// NOTE: Add here your custom variables

void main()
{
    // Send vertex attributes to fragment shader
    fragTexCoord = vertexTexCoord;
    fragColor = vertexColor;

    // Calculate final vertex position
    gl_Position = mvp*vec4(vertexPosition, 1.0);
}