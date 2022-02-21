#pragma once

#include <vector>
#include <string>
#include "Misc.h"

struct Curve {
    vector<double> x;
    vector<double> y;

    double* xMax;
    double* xMin;
    
    
    Curve(vector<double> _x, vector<double> _y) {
        this->x = _x;
        this->y = _y;

        this->xMin = &this->x[0];
        this->xMax = &this->x[this->x.size()-1];
    };

    Curve() {};

    static Curve fromFile(string path) {
        CurveReader cr(path);
        vector<double> x;
        vector<double> y;
        cr.parse(&x, &y);
        return Curve(x, y);
    }

    // uses interpolation
    double getValue(double _x) {

        if(_x <= *this->xMin) {
            return *this->xMin;
        }
        if(_x >= *this->xMax) {
            return *this->xMax;
        }

        double index = vectorIncludes(&this->x, _x);
        if(index != 0) {
            return this->y[index];
        }

        int x1 = vectorClosest(&this->x, _x);
        int x2 = ++x1;
        return Interpolate::lerp2(_x, this->x[x1], this->y[x1], this->x[x2], this->y[x2]);
    };

};

