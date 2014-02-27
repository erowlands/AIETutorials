#version 150

in vec3 Position;
in vec3 Velocity;
in float Lifetime;
in float Lifespan;

out vec3 position;
out float lifetime;
out float lifespan;

void main()
{
	position = Position;
	lifetime = Lifetime;
	lifespan = Lifespan;

	position.x = sin(Position.x);
	position.z = sin(Position.z);
	position.y = abs(Position.y);
}