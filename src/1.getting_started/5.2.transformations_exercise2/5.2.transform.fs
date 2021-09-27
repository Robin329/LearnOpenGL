#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float value;

void main()
{
	// linearly interpolate between both textures (80% container, 20% awesomeface)
	FragColor = mix(texture(texture1, vec2(TexCoord.x, TexCoord.y)), texture(texture2, vec2(TexCoord.x, value - TexCoord.y)), 0.2);
}