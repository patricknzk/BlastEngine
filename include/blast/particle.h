#ifndef PARTICLE_H
#define PARTICLE_H

#include "core.h"
#include "precision.h"

// Particle; the simplest physics object.
namespace blast{

    class Particle {
    public:
        // Hold position, velocity, and acceleration.
        Vector3 position;

        Vector3 velocity;

        Vector3 acceleration;

    // Add damping to prevent numerical errors creating weird physics.
    real damping;

    // Hold inverse mass. This rids divide by zero errors and allows us to compute acceleration more efficiently. Inf mass is an immovable object. i.e, acceleration is 0.
    real inverseMass;

    // Integration iteration
    void integrate(real duration);

    };
}

#endif //PARTICLE_H
