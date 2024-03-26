#version 450 core
precision highp float;

out vec4 color;

uniform vec4 InputColor;


void main() { 
	color = InputColor;
};