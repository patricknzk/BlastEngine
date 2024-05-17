#ifndef BLAST_PRECISION_H
#define BLAST_PRECISION_H

#include <cmath>

namespace blast {
    /**
     * Defines a real number precision. Blast can be compiled in single or double precision versions. Single precision is by default.
     * This essentially means at double precision, calculations will be more accurate, but more demanding for the computer.
     * 'float real' is single precision. 'double real' is double precision.
    */
   typedef float real;

    // rename sqrtf to real_sqrt.
    #define real_sqrt sqrtf

}

#endif // BLAST_PRECISION_H