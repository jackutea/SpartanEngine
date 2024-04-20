#version 330

// Input vertex attributes
in vec3 vertexPosition;     // location 0

// Input uniform values
uniform mat4 mvp;           // location 6

// Output vertex attributes (to fragment shader)
// out vec2 fragTexCoord;
out vec4 fragColor;

// NOTE: Add here your custom variables

void main()
{
    // Send vertex attributes to fragment shader
    // fragTexCoord = vertexTexCoord01;
    fragColor = vec4(vertexPosition, 1.0);

    // Calculate final vertex position
    gl_Position = mvp*vec4(vertexPosition, 1.0);
}