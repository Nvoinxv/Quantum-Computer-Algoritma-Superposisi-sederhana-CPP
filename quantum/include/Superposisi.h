#ifndef SUPERPOSISI_H
#define SUPERPOSISI_H

#include "Qubit.h"
#include "Gerbang_Hadamard.h"
#include "Tensor_Product.h"
#include <cmath>

class Superposisi_Quantum {
    private:
    Qubit qubit;
    std::vector<Qubit> qubits;   
    std::vector<ComplexNumber> langkah;
    double theta;


    public:
    Superposisi_Quantum(Qubit q) : qubit(q) {}
    
    // Melakukan operasi perhitungan hardman //
    // Dimana perhitungan itu dengan perhitungan //
    // matrix 2x2 dan qubit yang sudah di normalisasi //
    void pengaplikasian_hardman() {
        gerbang_hadamard hadamard;
        std::cout << "Sebelum di hadamard: " << qubit << "\n";
        qubit = hadamard.aplikasikan_linear(qubit);
        std::cout << "Setelah di hadamard: " << qubit << "\n";
    }

    // Melakukan Operasi perhitungan Tensor product //
    // Biar lebih multi dimensi array //
    void set_dua_qubits(const Qubit& q1, const Qubit& q2) {
        qubits = {q1, q2};
    }

    void pengaplikasian_tensor_product() {
        langkah = TensorProduct::hitung(qubits);
    }

    void print_langkah() {
        for (auto& amp : langkah) {
            std::cout << amp << "\n";
        }
    }

    // Kalau mau lebih fleksibel kita tambahkan rotasi //
    // Dan juga perhitungan phase gate //
    // Biar gak cuma + dan - doang tetapi juga bisa di pakai trigonometri dll //
    // Btw ini gw buat single rotasi saja //
    // Bukan multi dimensi //

    // Kita buat versi rotasi x //
    void gerbang_rotasi_x(double theta) {
        double c = std::cos(theta / 2.0);
        double s = std::sin(theta / 2.0);

        ComplexNumber alpha = qubit.mendapatkan_alpha();
        ComplexNumber beta  = qubit.mendapatkan_beta();

        ComplexNumber neg_i_s(0, -s);
        ComplexNumber pos_i_s(0, s);
        ComplexNumber alpha_baru = (alpha * c) - (beta * pos_i_s);
        ComplexNumber beta_baru  = (alpha * neg_i_s) + (beta * c);

        qubit.set_alpha(alpha_baru);
        qubit.set_beta(beta_baru);

        // Buat muncul print nya //
        std::cout << "RX -> alpha: " << alpha_baru << ", beta: " << beta_baru << "\n";
    }

    // Kita buat versi rotasi Y //
    // Perhitungan rotasi Y di superposisi ini //
    // Tidak ada bilangan imajiner karna sumbu Y jadi rotasi nyata //
    // Cuma nanti hasil nya itu ada bilangan imajiner karna di gabung sama perhitungan qubit //
    // Tapi secara teori si rotasi Y ini gak ada imajiner nya semua real //
    void gerbang_rotasi_y(double theta) {
        double c = std::cos(theta / 2.0);
        double s = std::sin(theta / 2.0);

        ComplexNumber alpha = qubit.mendapatkan_alpha();
        ComplexNumber beta  = qubit.mendapatkan_beta();

        ComplexNumber alpha_baru = (alpha * c) - (beta * s);
        ComplexNumber beta_baru  = (alpha * s) + (beta * c);

        qubit.set_alpha(alpha_baru);
        qubit.set_beta(beta_baru);

        std::cout << "RY -> alpha: " << alpha_baru << ", beta: " << beta_baru << "\n";
    }

    // Kita buat rotasi versi Z //
    void gerbang_rotasi_z(double theta) {
        double half = theta / 2.0;
        
        ComplexNumber fase_alpha(std::cos(half), -std::sin(half));
        ComplexNumber fase_beta(std::cos(half), std::sin(half));

        ComplexNumber alpha = qubit.mendapatkan_alpha();
        ComplexNumber beta = qubit.mendapatkan_beta();

        ComplexNumber alpha_baru = alpha * fase_alpha;
        ComplexNumber beta_baru = beta * fase_beta;

        qubit.set_alpha(alpha_baru);
        qubit.set_beta(beta_baru);

        std::cout << "RZ -> alpha: " << alpha_baru << ", beta: " << beta_baru << "\n";
    }

};

#endif