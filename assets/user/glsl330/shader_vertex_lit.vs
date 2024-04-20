#version 330

// Input vertex attributes
// 注: 内置变量名字不能改变
in vec3 vertexPosition;
in vec3 vertexNormal;

// Input uniform values
// 注: 内置变量名字不能改变
uniform mat4 mvp;

// Output vertex attributes (to fragment shader)
// out vec2 fragTexCoord;
out vec4 fragColor;

// NOTE: Add here your custom variables

void main()
{
    // Send vertex attributes to fragment shader
    // fragTexCoord = vertexTexCoord01;
    fragColor = vec4(vertexNormal, 1.0);

    // Calculate final vertex position
    gl_Position = mvp*vec4(vertexPosition, 1.0);
}