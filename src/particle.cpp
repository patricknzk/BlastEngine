#include <cassert>
#include <particle.h>

using namespace blast;

void Particle::integrate(real duration) {

    // Make sure duration is above zero.
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
