#ifndef QUBIT_H
#define QUBIT_H

// Membuat perhitungan Qubit //
// Dengan penggabungan aljabar linear terutama vektor //
// Dengan perhitungan bilangan kompleks //
#include "Complex_Number.h"
#include <cmath>
#include <set>

class Qubit {
private:
    ComplexNumber alpha;
    ComplexNumber beta;

public:
    // Constructor //
    Qubit(ComplexNumber a = {}, ComplexNumber b = {}) 
        : alpha(a), beta(b) {}

    // Normalisasi qubit //
    void normalize() {
        double mag = std::sqrt(
            alpha.magnitudeSquared() +
            beta.magnitudeSquared()
        );

        if (mag == 0) {
            std::cout << "Magnitude 0, tidak bisa normalisasi!\n";
            return;
        }

        alpha = alpha / mag;
        beta  = beta / mag;
    }

    // Mendapatkan alpha parameter //
    ComplexNumber mendapatkan_alpha() const {
        return alpha;
    }

    // Mendapatkan beta parameter //
    ComplexNumber mendapatkan_beta() const {
        return beta;
    }

    void set_alpha(const ComplexNumber& a) { alpha = a; }
    void set_beta(const ComplexNumber& b) { beta = b; }

    friend std::ostream& operator<<(std::ostream& os, const Qubit& q) {
        os << "[" << q.alpha << ", " << q.beta << "]";
        return os;
    }
};

#endif