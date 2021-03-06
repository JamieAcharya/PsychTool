#version 140
#extension GL_ARB_explicit_attrib_location : require
#extension GL_ARB_explicit_uniform_location : require

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 colour;

uniform mat4 u_mvp;

out vec4 v_colour;
void main(void)
{
    gl_Position = u_mvp * position;
    v_colour = colour;
}
