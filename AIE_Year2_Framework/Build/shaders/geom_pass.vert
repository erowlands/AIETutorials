#version 330

in vec4 Position;
in vec4 Normal;
in vec2 TexCoord;
in vec4 Colour;

out vec2 texCoord;
out vec4 normal;
out vec4 wPos;

uniform mat4 perspectiveView;
uniform mat4 Model; 

void main()
{
	texCoord = TexCoord;
	normal = normalize(Model * Normal);
	wPos = Model * Position;
	gl_Position = perspectiveView * wPos;
}