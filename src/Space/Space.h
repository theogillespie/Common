#pragma once

namespace Space {
    #include "Orbit.h"
    #include "au.h"
    #define GC 6.67408 * 10E-11 // gravitational constant

    double universalGravitation(double mass1, double mass2, double distance) {
        return GC * ((mass1 * mass2) / distance);
    };

};