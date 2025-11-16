#ifndef DUAL_NUMBERS_HPP
#define DUAL_NUMBERS_HPP

#include <ostream>

// 1)  Define a type for the dual number
struct Dual
{
    double real{0.0}; // réelle
    double dual{0.0}; // coefficient de ε

    Dual() = default;
    constexpr Dual(double r, double d = 0.0) noexcept : real(r), dual(d) {}
};

// 2) Overload the arithmetic operators +, -, *, / to implement these operations.********

// --- Opérateurs Dual and Dual ---
Dual operator+(const Dual &a, const Dual &b);
Dual operator-(const Dual &a, const Dual &b);
Dual operator*(const Dual &a, const Dual &b);
Dual operator/(const Dual &a, const Dual &b);

// --- Opérateurs mixtes (Dual and double or  double and Dual) ---
Dual operator+(const Dual &a, double b);
Dual operator+(double a, const Dual &b);

Dual operator-(const Dual &a, double b);
Dual operator-(double a, const Dual &b);

Dual operator*(const Dual &a, double b);
Dual operator*(double a, const Dual &b);

Dual operator/(const Dual &a, double b);
Dual operator/(double a, const Dual &b);

// Taylor expansion of the exponential
Dual exp(const Dual &x); // exp(u + u'ε) = (e^u, u' e^u)

// --- Affichage ---
std::ostream &operator<<(std::ostream &os, const Dual &x);

#endif // DUAL_NUMBERS_HPP
