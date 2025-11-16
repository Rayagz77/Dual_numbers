#include <iostream>
#include <cmath>
#include "dual_numbers.hpp"

int main()
{
    Dual a{2.0, 3.0}; // 2 + 3ε
    Dual b{5.0, 1.0}; // 5 + 1ε

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    std::cout << "a + b = " << (a + b) << "\n"; 
    std::cout << "a - b = " << (a - b) << "\n";
    std::cout << "a * b = " << (a * b) << "\n";
    std::cout << "a / b = " << (a / b) << "\n"; 

    std::cout << "a + 10 = " << (a + 10.0) << "\n";
    std::cout << "3 + a  = " << (3.0 + a) << "\n";
    std::cout << "a * 4  = " << (a * 4.0) << "\n";
    std::cout << "7 / b  = " << (7.0 / b) << "\n";

    // Taylor expansion of the exponential function.
    Dual x{2.0, 1.0};
    Dual y = exp(x);
    std::cout << "exp(2 + 1*eps) = " << y << "\n";

    // Vérif
    std::cout << "check real ~= exp(2) : " << y.real << " vs " << std::exp(2.0) << "\n";
    std::cout << "check dual ~= exp(2) : " << y.dual << " vs " << std::exp(2.0) << "\n";

    return 0;
}
