// Melakukan operasi perhitungan hardman //
// Dimana perhitungan itu dengan perhitungan //
// matrix 2x2 dan qubit yang sudah di normalisasi //

#ifndef GERBANG_HADAMARD_H
#define GERBANG_HADAMARD_H

#include "Qubit.h"

class gerbang_hadamard {
    public:
    // Complex Number Gerbang Hadamard 2 x 2 //
    ComplexNumber h00, h01, h10, h11;

    gerbang_hadamard() {
        // Kita buat perhitungan kuadrat dahulu //
        // Rumus nya 1/akar kuadrat 2 di kali dengan matrix 2 x 2 //
        double inv = 1.0/ std::sqrt(2.0);
        h00 = ComplexNumber(inv,0);
        h01 = ComplexNumber(inv,0);
        h10 = ComplexNumber(inv,0);
        h11 = ComplexNumber(inv,0);
    }

    // Lalu lakukan operasi linear matrix 2 x 2 //
    Qubit aplikasikan_linear(const Qubit& q) const {
        ComplexNumber a = q.mendapatkan_alpha();
        ComplexNumber b = q.mendapatkan_beta();

        ComplexNumber newA = h00.perkalian(a).pertambahan(h01.perkalian(b));
        ComplexNumber newB = h10.perkalian(a).pertambahan(h11.perkalian(b));

        Qubit hasil(newA, newB);
        hasil.normalize();
        return hasil;
    }
};

#endif