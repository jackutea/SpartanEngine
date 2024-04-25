#version 330

// Input vertex attributes (from vertex shader)
in vec3 fragPosition;

// Input uniform values
uniform samplerCube environmentMap;

// Output fragment color
out vec4 finalColor;

void main()
{
    // Fetch color from texture map
    vec3 color = vec3(0.0);
    bool isFlipped = false;
    bool isGammaCorrection = false;

    if (isFlipped) {
        color = texture(environmentMap, vec3(fragPosition.x, -fragPosition.y, fragPosition.z)).rgb;
    } else {
        color = texture(environmentMap, fragPosition).rgb;
    }

    if (isGammaCorrection)// Apply gamma correction
    {
        color = color/(color + vec3(1.0));
        color = pow(color, vec3(1.0/2.2));
    }

    // Calculate final fragment color
    finalColor = vec4(color, 1.0);
}
