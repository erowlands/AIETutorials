#version 330

in vec4 vColour;
in vec2 texCoord;

uniform sampler2D DiffuseTexture;
uniform sampler2D NormalTexture;
uniform sampler2D WorldTexture;

uniform vec3 camera_pos;
uniform vec2 screenSize;

uniform vec3 light_dir;

void main()
{
	vec2 UV = gl_FragCoord.xy / screenSize;

	vec4 DiffuseColor = texture(DiffuseTexture, UV).xyz;
	vec3 Normal = normalize(texture(NormalTexture, UV).xyz);
	vec3 WorldPosition = texture(WorldTexture, UV).xyz;
	vec3 Eye = normalize(camera_pos - texture(WorldTexture, UV).xyz);
	vec3 Light = normalize(light_dir);

	gl_FragColor = texture(DiffuseTexture, UV);
}