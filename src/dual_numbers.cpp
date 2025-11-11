/********************************************/
/*                  TASKS                   */
/********************************************/

//Define a type for the dual numbers and initialize the attributes to 0 

struct Dual {
    double real  = 0.0;   // real avec valeur par défaut = 0
    double dual  = 0.0;   // epsilon avec valeur par défaut = 0

    Dual() = default;     // utilise les valeurs ci-dessus
    Dual(double r, double d = 0.0) : real(r), dual(d) {}
};
