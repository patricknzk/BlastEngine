#include "assert.h"
#include "particle.h"

using namespace blast;

void Particle::integrate(real duration) {
    assert(duration > 0.0);

    // Update position
    position.addScaledVector(velocity, duration);

    // Find acceleration from force
    Vector3 resultingAcc = acceleration;
    resultingAcc.addScaledVector(forceAccum, inverseMass);

    // Update velocity
    velocity.addScaledVector(resultingAcc, duration);

    // Add drag
    velocity *= real_pow(damping, duration);

}
