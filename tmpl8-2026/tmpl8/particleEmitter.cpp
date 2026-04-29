#include "particleEmitter.h"




void ParticleEmitter::DrawParticles()
{
	for (Particle p : particles)
	{
		GameObject::surface->Plot(p.x, p.y, p.colour);
	}

}



