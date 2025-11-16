/********************************************/
/*                  TASKS                   */
/********************************************/

//3) Create an overloaded exponential function working on double and dual numbers.

#include "dual_numbers.hpp"
#include <stdexcept>
#include <cmath>

// *********** Dual and  Dual *******************

// Addition : (u+u'ε) + (v+v'ε) = (u+v) + (u'+v')ε
Dual operator+(const Dual &a, const Dual &b)
{
    return {a.real + b.real, a.dual + b.dual};
}

// Soustraction : (u+u'ε) − (v+v'ε) = (u−v) + (u'−v')ε
Dual operator-(const Dual &a, const Dual &b)
{
    return {a.real - b.real, a.dual - b.dual};
}

// Multiplication : (u+u'ε)(v+v'ε) = (uv) + (uv' + u'v)ε  (ε² = 0)
Dual operator*(const Dual &a, const Dual &b)
{
    return {a.real * b.real, a.real * b.dual + a.dual * b.real};
}

// Division : (u+u'ε)/(v+v'ε) = (u/v) + (u'v − uv')/v² ε   (v ≠ 0)
Dual operator/(const Dual &a, const Dual &b)
{
    if (b.real == 0.0)
    {
        throw std::runtime_error("la Division par un dual réelle de valeur zero n'est pas possible.");
    }
    return {
        a.real / b.real,
        (a.dual * b.real - a.real * b.dual) / (b.real * b.real)};
}

//**********Mixtes Operators (Dual and double or double and Dual)**********

Dual operator+(const Dual &a, double b) { return {a.real + b, a.dual}; }
Dual operator+(double a, const Dual &b) { return {a + b.real, b.dual}; }

Dual operator-(const Dual &a, double b) { return {a.real - b, a.dual}; }
Dual operator-(double a, const Dual &b) { return {a - b.real, -b.dual}; }

Dual operator*(const Dual &a, double b) { return {a.real * b, a.dual * b}; }
Dual operator*(double a, const Dual &b) { return {a * b.real, a * b.dual}; }

Dual operator/(const Dual &a, double b)
{
    if (b == 0.0)
    {
        throw std::runtime_error("Division by zero (double).");
    }
    return {a.real / b, a.dual / b};
}

Dual operator/(double a, const Dual &b)
{
    if (b.real == 0.0)
    {
        throw std::runtime_error("Division par un dual de partie réelle nulle.");
    }
    // (a + 0ε) / (v + v'ε) = (a/v) + (0*v − a*v')/v² ε = a/v − (a*v')/v² ε
    return {a / b.real, (-a * b.dual) / (b.real * b.real)};
}

//Taylor expansion of the exponential 
Dual exp(const Dual& x) {
    // e^(u + u'ε) = e^u + (u' e^u) ε
    const double eu = std::exp(x.real);  
    return { eu, x.dual * eu };
}


// ===== Affichage =====
std::ostream &operator<<(std::ostream &os, const Dual &x)
{
    os << x.real;
    if (x.dual != 0.0)
    {
        os << " + " << x.dual << "eps";
    }
    return os;
}
