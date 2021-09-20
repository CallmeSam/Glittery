#version 330
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;

out vec4 vertexColor;
out vec2 texCoord;

void main()
{
    gl_Position = vec4(aPos, 0, 1.0);
    vertexColor = vec4(aColor, 1.0);
    texCoord = aTex;
}