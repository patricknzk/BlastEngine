#ifndef BLAST_CORE_H
#define BLAST_CORE_H

#include "precision.h"

namespace blast{
    // Holds a vector in 3D. 
    class Vector3
    {
    /**
     * Members of classes can be 'public', 'private' or 'protected'. 
     * Essentially 'public' members can be accessed outside of classes.
     * and 'private' within themselves only.
    */
    public:
        // Holds value on x, y, and z respectively.
        real x;
        real y;
        real z;
    
    private:
        // basically fills in missing memory bytes to ensure faster memory usage.
        real pad;

    public:
    /**
     * Constructors are the objects within the classes that have the same name as the class.
     * The constructor initiliazes the object and has no return type.
     * the {} is the constructor body, contains the code that runs when the constructor is called.
    */
        // Default vector is the zero vector.
        Vector3() : x(0), y(0), z(0) {}

        // Vector with components.
        Vector3(const real x, const real y, const real z)
            : x(x), y(y), z(z) {}

        // Inverse of the vector. 'void' does not return a value.
        void invert()
        {
            x = -x;
            y = -y;
            z = -z;
        }

    // Get magnitude
    real magnitude() const {
        return real_sqrt(x*x+y*y+z*z);
    }

    // Squared magnitude
    real squareMagnitude() const {
        return x*x+y*y+z*z;
    }

    // Normalise a vector by dividing it by its magnitude. Checks if vector is non-zero.
    void normalise() {
        real length = magnitude();
        if (length > 0) {
            (*this)*=((real)1)/length;
        }
    }

    // Allows us to multiply elements of vectors.
    void operator*=(const real value) {
        x *= value;
        y *= value;
        z *= value;
    }

    // Returns a copy of the scaled vector.
    Vector3 operator*(const real value) const {
        return Vector3(x*value, y*value, z*value);
    }
    //page 49 continue
    };
}

#endif // BLAST_CORE_H