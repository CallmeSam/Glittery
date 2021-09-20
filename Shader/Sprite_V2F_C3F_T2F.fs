#version 330
in vec4 vertexColor;
in vec2 texCoord;

uniform sampler2D ourTexture;

out vec4 FragColor;

void main()
{
    FragColor = texture(ourTexture, texCoord) * vertexColor;
}