#version 330

// Input vertex attributes (from vertex shader)
in vec3 fragPosition;
in vec2 fragTexCoord;
//in vec4 fragColor;
in vec3 fragNormal;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Output fragment color
out vec4 finalColor;

// NOTE: Add here your custom variables

#define     MAX_LIGHTS              4
#define     LIGHT_DIRECTIONAL       0
#define     LIGHT_POINT             1

struct Light {
    int enabled;
    int type;
    vec3 position;
    vec3 target;
    vec4 color;
};

// Input lighting values
uniform Light lights[MAX_LIGHTS];
uniform int lightCount;
uniform vec4 ambient;
uniform vec3 viewPos;

void main()
{
    // Texel color fetching from texture sampler
    vec4 texelColor = texture(texture0, fragTexCoord);
    vec3 lightDot = vec3(0.0);
    vec3 normal = normalize(fragNormal);
    vec3 viewD = normalize(viewPos - fragPosition);
    vec3 specular = vec3(0.0);

    // NOTE: Implement here your fragment shader code

    for (int i = 0; i < lightCount; i++) {
        if (lights[i].enabled == 1) {
            vec3 light = vec3(0.0);

            if (lights[i].type == LIGHT_DIRECTIONAL) {
                light = -normalize(lights[i].target - lights[i].position);
            } else if (lights[i].type == LIGHT_POINT) {
                light = normalize(lights[i].position - fragPosition);
            }

            // - Lambert (diffuse)
            float NdotL = dot(normal, light); // -1, 0(明暗交界线), 1
            // - Half-Lambert (diffuse)
            // float NdotL = dot(normal, light) * 0.5 + 0.5; // 0, 0.5(明暗交界线), 1
            NdotL = max(NdotL, 0.0); // 防止负数
            lightDot += lights[i].color.rgb*NdotL;

            float specCo = 0.0;
            if (NdotL > 0.0) {
                // specular
                float shiness = 16.0; // 越大表面越光滑, 越小表面越粗糙
                // - Phong
                // vec3 reflectVec = reflect(-light, normal);
                // specCo = pow(max(0.0, dot(viewD, reflectVec)), shiness);
                // - Blinn-Phong (性能更好, 效果略有差别-高光弱一些)
                vec3 halfVec = normalize(light + viewD);
                float specCo = pow(max(0.0, dot(halfVec, normal)), shiness);
            }
            specular += specCo;
        }
    }

    finalColor = (texelColor*((colDiffuse + vec4(specular, 1.0))*vec4(lightDot, 1.0)));

    // Ambient light
    finalColor += texelColor*(ambient/10.0)*colDiffuse;

    // Gamma correction
    finalColor = pow(finalColor, vec4(1.0/2.2));
}
