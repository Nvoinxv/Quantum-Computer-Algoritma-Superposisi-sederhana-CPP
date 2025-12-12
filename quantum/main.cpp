#include "include/Complex_Number.h"
#include "include/Qubit.h"
#include "include/Superposisi.h"
#include <iostream>

int main() {
    // Set nilai dummy yang kita ingin gunakan //
    ComplexNumber z1;
    ComplexNumber z2;
    
    // Masukkan nilai untuk complex number //
    std::cin >> z1;
    std::cin >> z2;
    std::cout << "z1 = " << z1 << "\n";
    std::cout << "z2 = " << z2 << "\n";

    // Gw pakai Qubit saja dummy  nya //
    // Kalau Z itu buat complex number test saja //
    Qubit q (ComplexNumber(1,1), ComplexNumber(0,1));
    
    // Buat print makin gacor //
    // Dan ui kelihatan bagus //
    std::cout << "=== Memulai Perhitungan Bilangan Kompleks ===" << std::endl;
    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;
    
    std::cout << "=== Pertambahan Bilangan Kompleks ===" << std::endl;
    std::cout << "z1 + z2 = " << z1.pertambahan(z2) << std::endl;

    std::cout << "=== Pengurangan Bilangan Kompleks ===" << std::endl;
    std::cout << "z1 - z2 = " << z1.pengurangan(z2) << std::endl;

    std::cout << "=== Perkalian Bilangan Kompleks ===" << std::endl;
    std::cout << "z1 * z2 = " << z1.perkalian(z2) << std::endl;

    std::cout << "=== Pembagian Bilangan Kompleks ===" << std::endl;
    std::cout << "z1 / z2 = " << z1.pembagian(z2) << std::endl;

    std::cout << "=== Selesai Perhitungan ===" << std::endl;

    // Testing Perhitungan Qubit //
    std::cout << "=== Memulai Perhitungan Qubit ===" << std::endl;
    q.normalize();
    std::cout << "q = " << q << std::endl;
    std::cout << "=== Selesai Perhitungan Qubit ===" << std::endl;

    // Testing perhitungan superposisi //
    std::cout << "=== Memulai Perhitungan Superposisi ===" << std::endl;
    Superposisi_Quantum superposisi(q);
    superposisi.pengaplikasian_hardman();

    std::cout << "Perhitungan Tensor Product: " << std::endl;
    superposisi.set_dua_qubits(q, q);
    superposisi.pengaplikasian_tensor_product();
    superposisi.print_langkah();

    std::cout << "=== Perhitungan trigonometri rotasi quantum superposisi ===" << std::endl;
    // Untuk mendapatkan rotasi di qubit ini rada beda //
    // Karna kita ukur cari rotasi nya lewat radian //
    // Rumus nya kek gini radian = derajat x phi/180 //
    std::cout << "Masukkan nilai derajat: ";
    double derajat;
    std::cin >> derajat;
    double theta = derajat * M_PI / 180; // Disini gw pakai 45 derajat //

    std::cout << "Target rotasi yang di inginkan: " << theta << std::endl;

    std::cout << "Perhitungan rotasi RX: " << std::endl;
    superposisi.gerbang_rotasi_x(theta);
    std::cout << "Perhitungan rotasi RY: " << std::endl;
    superposisi.gerbang_rotasi_y(theta);
    std::cout << "Perhitungan rotasi RZ: " << std::endl;
    superposisi.gerbang_rotasi_z(theta);

    std::cout << "=== Selesai Perhitungan Superposisi ===" << std::endl;

    return 0;
}