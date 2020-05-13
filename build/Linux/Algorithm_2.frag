#version 140
#extension GL_ARB_explicit_attrib_location : require
#extension GL_ARB_explicit_uniform_location : require

in vec4 v_colour;

void main(void)
{
    gl_FragColor = v_colour;
}
