#version 330 core
layout (location = 0) in vec3 vert_pos;
layout (location = 1) in vec3 vert_color;
layout (location = 2) in vec2 aTex;

out vec3 color;
out vec2 texCoord;
uniform float scale;

void main() {
    gl_Position = vec4( vert_pos + vert_pos * scale, 1.0f);
    color = vert_color;
    texCoord = aTex;
}
