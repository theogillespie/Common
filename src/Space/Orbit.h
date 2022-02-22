#pragma once

#include <cmath>
#include <math.h>
#include <vector>

#include "au.h"
#include "../Math/Vector3.h"
#include "../Constants.h"

using namespace std;

class OrbitalBody {
    public:
    Vector3 position;
    double gravitationalParamater;
    double mass;
    Vector3 angularMomentum;
};

class Orbit {
    public:
        // all in meters
        double apoapsis;
        double periapsis;
        double inclination;

        double eccentricity;
        double period;

        double semiMajorAxis; 
        double semiMinorAxis;
        Vector3 barycenter;
        Vector3 geometricCenter;
        OrbitalBody body;
        OrbitalBody satellite;

        Orbit() {
            this->semiMajorAxis = (this->apoapsis + this->periapsis) / 2;
            this->semiMinorAxis = sqrt(this->apoapsis * this->periapsis);
            this->eccentricity = sqrt(1 - ((this->semiMinorAxis * this->semiMinorAxis) / (this->semiMajorAxis * this->semiMajorAxis)));

            // wrong
            double x = Vector3::distance(this->body.position, this->satellite.position) / (1 + (this->body.mass / this->satellite.mass));
            this->barycenter = new Vector3(this->body.position.x + x, this->body.position.y,this->body.position.z);
        }

        update() {
            //https://space.stackexchange.com/questions/8911/determining-orbital-position-at-a-future-point-in-time
        }

        vector<Vector3> rotatePoints(vector<Vector3> points) {
            for(unsigned int = 0; i < points.size(); i++) {
                
            }
        }

        vector<Vector3> generateGeometry(double resolution=1000) {
            vector<Vector3> points;
            
            double dt = THETA / resolution;
            double h = geometricCenter.x;
            double k = geometricCenter.y;
            double rh = apoapsis;
            double rk = periapsis;

            for(double x = 0; x < THETA; x += dt) {
                points.push_back(Vector3(h + rh * cos(x), k - rk * sin(x),));
            }

        }
};