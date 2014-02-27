#version 330

in vec4 Position;
in vec4 Colour;
in vec2 TexCoord;

out vec4 vColour;
out vec2 texCoord;

void main()
{
	texCoord = TexCoord;
	gl_Position = Position;
}