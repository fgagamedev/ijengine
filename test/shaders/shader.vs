#version 330

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 color;
out vec4 ColorFrag;



void main()
{
    gl_Position = vec4( Position.x,  Position.y, Position.z, 1.0);
    ColorFrag = vec4(color.r,color.g,color.b, 1.0);
}
