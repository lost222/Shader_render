#version 330 core
out vec4 FragColor;
in vec3 Normal;
in vec3 FragPos;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;


void main()
{
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // 片的法向量
    vec3 norm = normalize(Normal);
    // 光的方向
    vec3 lightDir = normalize(lightPos - FragPos);

    // 是0 还是 -dot(norm, lightDir)
    float diff = max(dot(norm, lightDir), 0.0);
    // 目前把漫反射分量置为全1
    vec3 k_diffuse = vec3(1.0 , 1.0, 1.0);
    vec3 diffuse = k_diffuse * diff * lightColor;

    // 高光计算
    float specularStrength = 0.5;
    // 视角方向
    vec3 viewDir = normalize(viewPos - FragPos);
//  这里教程的方式是 :
//    我觉得 核心是 norm 已经是镜面的法向了
    vec3 reflectDir = reflect(-lightDir, norm);
    // n = 1024
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 1024);
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient + diffuse + specular) * objectColor;

    FragColor = vec4(result, 1.0);
}