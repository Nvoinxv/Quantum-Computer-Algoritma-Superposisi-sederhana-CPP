#ifndef TENSOR_PRODUCT_H
#define TENSOR_PRODUCT_H

#include "Qubit.h"
#include <vector>

// Ini biar perhitungan nya bisa multi dimensi //
// Jadi gak sebatas 2 dimensi doang //
// Bisa 3 atau lebih dari 4 dimensi //
// untuk 3 qubit itu ada 8 basis kalau 4 qubit itu ada 16 dan seterus nya di kali 4 //
class TensorProduct {
public:
    static std::vector<ComplexNumber> hitung(const std::vector<Qubit>& qubits) {

        if (qubits.empty()) return {};  

        std::vector<ComplexNumber> hasil;

        // Start qubit pertama //
        hasil.push_back(qubits[0].mendapatkan_alpha());
        hasil.push_back(qubits[0].mendapatkan_beta());

        // Tensor product untuk qubit berikutnya //
        // Ini biar bisa multi dimensi array //
        for (size_t i = 1; i < qubits.size(); i++) {

            std::vector<ComplexNumber> hasil_baru;
            hasil_baru.reserve(hasil.size() * 2);

            ComplexNumber a = qubits[i].mendapatkan_alpha();
            ComplexNumber b = qubits[i].mendapatkan_beta();

            // Broadcasting manual //
            for (size_t j = 0; j < hasil.size(); j++) {
                hasil_baru.push_back(hasil[j] * a);  // Sisi 0 //
                hasil_baru.push_back(hasil[j] * b);  // Sisi 1 //
            }

            hasil = hasil_baru;
        }

        return hasil;
    }
};

#endif