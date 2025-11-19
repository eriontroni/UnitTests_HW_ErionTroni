#include "T02_CalculateShipping.h"
#include <algorithm> // për std::max nëse të duhet

double CalculateShipping(double weightKg, bool express, int N)
{
    // Nëse pesha është zero ose negative, s’ka kosto
    if (weightKg <= 0.0)
        return 0.0;

    // ================= Parametrat sipas N (si në PDF) =================
    // freeLimit: kufiri mes medium/large (5–8 kg)
    double freeLimit = 5.0 + (N % 4);                 // [5, 8]
    double baseSmall = 2.0 + (N % 3) * 0.5;           // 2.0, 2.5, 3.0
    double baseMedium = baseSmall + 2.0;               // 4.0, 4.5, 5.0

    // Këto dy i kam zgjedhur në mënyrë të arsyeshme (nuk duken në tekst):
    double extraPerKg = 1.0 + (N % 2) * 0.5;         // 1.0 ose 1.5 €/kg mbi freeLimit
    double expressFactor = 1.5;                        // factor për express

    double cost = 0.0;

    // ================= Logjika e çmimit =================
    // Shembull i thjeshtë:
    //  - deri 1 kg       → baseSmall
    //  - nga 1 deri freeLimit kg → baseMedium
    //  - mbi freeLimit   → baseMedium + (weight - freeLimit) * extraPerKg
    if (weightKg <= 1.0)
    {
        cost = baseSmall;
    }
    else if (weightKg <= freeLimit)
    {
        cost = baseMedium;
    }
    else
    {
        double extraWeight = weightKg - freeLimit;
        cost = baseMedium + extraWeight * extraPerKg;
    }

    // Nëse është express, shumëzo me expressFactor
    if (express)
    {
        cost *= expressFactor;
    }

    return cost;
}
