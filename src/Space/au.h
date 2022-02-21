#pragma once

// astronomical unit

#define KMAU 1.495978707e+8 // conversion constant

class au {
    private:
        double value;
    public:

        au(double n=0) {
            this->value = n;
        }

        double toKM() {
            return this->value * KMAU;
        }

        static au fromKM(double n) {
            return n / KMAU;
        }

        void toString() const;

        au& operator = (const au& n) {
            this->value = n.value;
            return *this;
        }

        au& operator = (const double& n) {
            this->value = n;
            return *this;
        }

        bool operator == (const au& n) const {
            return this->value == n.value;
        }

        bool operator == (const double& n) const {
            return this->value == n;
        }

        bool operator != (const au& n) const {
            return this->value != n.value;
        }

        bool operator != (const double& n) const {
            return this->value != n;
        }

        bool operator < (const au& n) const {
            return this->value < n.value;
        }

        bool operator < (const double& n) const {
            return this->value < n;
        }

        bool operator > (const au& n) const {
            return this->value > n.value;
        }

        bool operator > (const double& n) const {
            return this->value > n;
        }

        bool operator <= (const au& n) const {
            return this->value <= n.value;
        }

        bool operator <= (const double& n) const {
           return this->value <= n;
        }

        bool operator >= (const au& n) const {
            return this->value >= n.value;
        }

        bool operator >= (const double& n) const {
            return this->value >= n;
        }

        au operator += (const au& n) {
            this->value += n.value;
            return *this;
        }

        au operator += (const double& n) {
            this->value += n;
            return *this;
        }

        au operator + (const au& n) const {
            return *new au(this->value + n.value);
        }

        au operator + (const double& n) const {
            return *new au(this->value + n);
        }

        au operator -= (const au& n) {
            this->value += n.value;
            return *this;
        }

        au operator -= (const double& n) {
            this->value += n;
            return *this;
        }

        au operator - (const au& n) const {
            return *new au(this->value - n.value);
        }

        au operator - (const double& n) const {
            return *new au(this->value - n);
        }

        au operator *= (const au& n) {
            this->value *= n.value;
            return *this;
        }

        au operator *= (const double& n) {
            this->value *= n;
            return *this;
        }

        au operator * (const au& n) const {
            return *new au(this->value * n.value);
        }

        au operator * (const double& n) const {
            return *new au(this->value * n);
        }

        au operator /= (const au& n);
        au operator /= (const double& n);
        au operator / (const au& N) const;
        au operator / (const double& n);
};