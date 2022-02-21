#pragma once

#include <cmath>
#include <math.h>

#include "au.h"
#include "../Math/Vector3.h"

class OrbitalBody {
    public:
    Vector3 position;
    double gravitationalParamater;
    double mass;
    Vector3 angularMomentum;
};

class Orbit {
    public:
        //in meters
        double apoapsis;
        double periapsis;
        double inclination;

        double eccentricity;
        double period;

        double specificOrbitalEnergy;
        double orbitalDistance;
        double orbitalVelocity;

        double semiMajorAxis; // meters
        double semiMinorAxis;
        OrbitalBody barycenter;
        OrbitalBody body;

        Orbit() {

        }

        // change to this:https://en.wikipedia.org/wiki/Semi-major_and_semi-minor_axes
        void recalculate() {

            this->semiMajorAxis = this->apoapsis - this->periapsis;
            this->semiMinorAxis = this->semiMajorAxis * sqrt(1-(this->eccentricity * this->eccentricity));
            double semiLatusRectum = this->semiMajorAxis * (1-(this->eccentricity * this->eccentricity));
            double semiMajorAxisLength = 0;
            

            this->orbitalDistance = Vector3::distance(this->body.position, this->barycenter.position);
            this->orbitalVelocity = (2 * PI * this->semiMajorAxis.magnitude()) / this->period;
            
            double u = this->barycenter.gravitationalParamater + this->body.gravitationalParamater;
            this->specificOrbitalEnergy = ((this->orbitalVelocity * this->orbitalVelocity)/2) - (u/this->orbitalDistance);

            Vector3 h = this->body.angularMomentum / this->body.mass;
            this->eccentricity = ((((h*h) * 2 * this->specificOrbitalEnergy) / (u*u)) + 1).magnitude();
        }

};