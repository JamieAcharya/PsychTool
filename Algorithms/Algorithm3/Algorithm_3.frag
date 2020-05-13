#version 450 core

uniform float time;
out vec3 FragColor;

void main(void)
{
    FragColor = vec3( sin(time), 1.0f, 0.0f);
}
