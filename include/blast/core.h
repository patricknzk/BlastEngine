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
    
    // Adds vectors together
    void operator+=(const Vector3& v) {
        x+=v.x;
        y+=v.y;
        z+=v.z;
    }

    // Returns a copy of the added vector
    Vector3 operator+(const Vector3& v) const {
        return Vector3(x+v.x, y+v.y, z+v.z);
    }

    // Subtracts vectors
    void operator-=(const Vector3& v) {
        x-=v.x;
        y-=v.y;
        z-=v.z;
    }

    // Returns a copy of the added vector
    Vector3 operator-(const Vector3& v) const {
        return Vector3(x-v.x, y-v.y, z-v.z);
    }

    // Add scaled vectors
    void addScaledVector(const Vector3& vector, real scale) {
        x += vector.x*scale;
        y += vector.y*scale;
        z += vector.z*scale;
    }

    // Vector multiplication (component wise)
    Vector3 componentProduct(const Vector3& vector) const {
        return Vector3(x * vector.x, y * vector.y, z * vector.z);
    }

    void componentProductUpdate(const Vector3& vector) {
        x *= vector.x;
        y *= vector.y;
        z *= vector.z;
    }

    // Dot product (two versions of the same thing)
    real scalarProduct(const Vector3& vector) const {
        return x*vector.x + y*vector.y + z*vector.z;
    }

    real operator *(const Vector3& vector) const {
        return x*vector.x + y*vector.y + z*vector.z;
    }

    // Cross product (multiply two vectors)
    Vector3 vectorProduct(const Vector3& vector) const {
        return Vector3(y*vector.z-z*vector.y, z*vector.x - x*vector.z, x*vector.y - y*vector.x);
    }

    void operator %=(const Vector3& vector) {
        *this = vectorProduct(vector);
    }
    
    };
}

#endif // BLAST_CORE_H