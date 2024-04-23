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
    vec3 lightColor = vec3(0.0);
    vec3 normal = normalize(fragNormal);
    vec3 viewD = normalize(viewPos - fragPosition);
    vec3 specular = vec3(0.0);

    // NOTE: Implement here your fragment shader code

    for (int i = 0; i < lightCount; i++) {
        if (lights[i].enabled == 1) {
            vec3 lightDir = vec3(0.0);

            if (lights[i].type == LIGHT_DIRECTIONAL) {
                lightDir = -normalize(lights[i].target - lights[i].position);
            } else if (lights[i].type == LIGHT_POINT) {
                lightDir = normalize(lights[i].position - fragPosition);
            }

            // - Lambert (diffuse)
            // float NdotL = dot(normal, lightDir); // -1, 0(明暗交界线), 1
            // - Half-Lambert (diffuse)
            float NdotL = dot(normal, lightDir) * 0.5 + 0.5; // 0, 0.5(明暗交界线), 1
            NdotL = max(NdotL, 0.0); // 防止负数

            // 光照颜色
            lightColor += lights[i].color.rgb * NdotL;

            float specCo = 0.0;
            // specular
            if (NdotL > 0.0) {
                // {
                //     // - Phong
                //     float shiness = 8.0; // 越大表面越光滑, 越小表面越粗糙
                //     vec3 reflectVec = reflect(-lightDir, normal);
                //     specCo = pow(max(0.0, dot(viewD, reflectVec)), shiness);
                // }
                {
                    // - Blinn-Phong (性能更好, 效果略有差别-高光弱一些)
                    float shiness = 16.0; // 越大表面越光滑, 越小表面越粗糙
                    vec3 halfVec = normalize(lightDir + viewD);
                    float specCo = pow(max(0.0, dot(halfVec, normal)), shiness);
                }
            }
            specular += specCo;
        }
    }

    finalColor = (texelColor * ((colDiffuse + vec4(specular, 1.0)) * vec4(lightColor, 1.0)));

    // Ambient light
    finalColor += texelColor * (ambient * 0.1) * colDiffuse;

    // Gamma correction
    finalColor = pow(finalColor, vec4(1.0/2.2));
}
