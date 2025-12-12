#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <iostream>
#include <cmath>

class ComplexNumber {
private:
    double real;
    double imag;

public:
    ComplexNumber(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    void set_nilai(double r, double i) {
        real = r;
        imag = i;
    }

    ComplexNumber pertambahan(const ComplexNumber& z) const {
        return ComplexNumber(real + z.real, imag + z.imag);
    }

    ComplexNumber pengurangan(const ComplexNumber& z) const {
        return ComplexNumber(real - z.real, imag - z.imag);
    }

    ComplexNumber perkalian(const ComplexNumber& z) const {
        double real_part = real * z.real - imag * z.imag;
        double imag_part = real * z.imag + imag * z.real;
        return ComplexNumber(real_part, imag_part);
    }

    ComplexNumber pembagian(const ComplexNumber& z) const {
        double penyebut = z.real * z.real + z.imag * z.imag;
        double real_part = (real * z.real + imag * z.imag) / penyebut;
        double imag_part = (imag * z.real - real * z.imag) / penyebut;
        return ComplexNumber(real_part, imag_part);
    }

    // operator bagi dengan double //
    ComplexNumber operator/(double val) const {
        return ComplexNumber(real / val, imag / val);
    }
     
    // Ini wajib di tambah overload buat perhitungan superposisi nya //
    // Overload + //
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    // Overload - //
    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    // Overload * //
    ComplexNumber operator*(const ComplexNumber& other) const {
        return ComplexNumber(real * other.real - imag * other.imag,
                             real * other.imag + imag * other.real);
    }

    // Overload * dengan double //
    ComplexNumber operator*(double val) const {
        return ComplexNumber(real * val, imag * val);
    }

    // Overload operator >> untuk ComplexNumber //
    friend std::istream& operator>>(std::istream& in, ComplexNumber& z) {
        double real, imag;
        std::cout << "Masukkan bagian real: ";
        in >> real;
        std::cout << "Masukkan bagian imaginer: ";
        in >> imag;
        z = ComplexNumber(real, imag);
        return in;
    }

    // Ini buat print complex number nya //
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& z) {
        os << z.real << " + " << z.imag << "i";
        return os;
    }

    // Ini buat perhitungan magnitude squared yang //
    // akan di gunakan untuk perhitungan qubit //
    double magnitudeSquared() const {
        return real*real + imag*imag;
    }
};

#endif
