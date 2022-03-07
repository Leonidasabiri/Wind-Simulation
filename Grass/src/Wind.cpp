#include "Wind.h"

// MUST BE DONE ASPA: Use the noise shader to simulate the wind by getting the x and y value and applying a deformation
// on each vertex position !!
Wind::Wind(float _velocity)
{
	this->velocity = _velocity;
}

void	Wind::applyingNoise(float x, float y)
{
	static	float	v;
	velocity = v;
	ImGui::Begin("Wind Parameters:");
	ImGui::SliderFloat("Velocity", &v, 0, 10);
	ImGuiCond_FirstUseEver;

	ImGui::End();
}