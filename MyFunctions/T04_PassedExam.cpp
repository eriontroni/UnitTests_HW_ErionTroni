#include "T04_PassedExam.h"
#include <stdexcept>  // std::invalid_argument

bool PassedExam(double points, int N)
{
    // Pikët vlejnë vetëm në [0,100]
    if (points < 0.0 || points > 100.0)
    {
        throw std::invalid_argument("Points must be in [0,100].");
    }

    // Parametri sipas N:
    // passLimit = 40 + (N % 21)  → 40–60
    int passLimit = 40 + (N % 21);

    // Nëse points > passLimit → ka kaluar
    if (points > passLimit)
        return true;

    // Përndryshe nuk ka kaluar
    return false;
}
