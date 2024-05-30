#version 450 core
precision highp float;

out vec4 color;
in vec2 TexCoord;

uniform vec4 InputColor;
uniform sampler2D Tex;

void main() { 
	color = InputColor + texture(Tex, TexCoord);
};