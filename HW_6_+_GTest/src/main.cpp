#include "pch.h"
#include "Array.h"

#include <iostream>
#include <stdexcept>

int main() {
    const int kSizeInt = 5;
    int data_int[kSizeInt] = { 10, 3, 45, -1, 20 };

    Array<int, kSizeInt> array1(data_int);
    Array<int, kSizeInt> array2;

    std::cout << "Massiv int (array1): ";
    array1.Show();

    try {
        int min_val_int = array1.Minimum(array2);
        std::cout << "\nNaimenshiy element v array1: " << min_val_int << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "\nOshibka: " << e.what() << std::endl;
    }

    std::cout << "\n-------------------------------------------\n";

    const int kSizeDouble = 4;
    double data_double[kSizeDouble] = { 3.14, 1.05, 2.71, 0.99 };

    Array<double, kSizeDouble> array_d1(data_double);
    Array<double, kSizeDouble> array_d2;

    std::cout << "Massiv double (array_d1): ";
    array_d1.Show();

    try {
        double min_val_double = array_d1.Minimum(array_d2);
        std::cout << "\nNaimenshiy element v array_d1: " << min_val_double << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "\nOshibka: " << e.what() << std::endl;
    }

    return 0;
}
