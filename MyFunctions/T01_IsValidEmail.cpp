#include "T01_IsValidEmail.h"

bool IsValidEmail(const std::string& email)
{
    // Gjej pozicionin e '@'
    std::size_t atPos = email.find('@');

    // Duhet te ekzistoje '@' dhe te mos jete karakteri i pare
    if (atPos == std::string::npos || atPos == 0)
        return false;

    // Pjesa pas '@'
    std::string afterAt = email.substr(atPos + 1);

    // Duhet te kete te pakten nje pike pas '@'
    std::size_t dotPos = afterAt.rfind('.');
    if (dotPos == std::string::npos)
        return false;

    // Nuk lejohet qe pika te jete karakteri i pare pas '@'
    // (dmth, duhet te kete diçka ndermjet '@' dhe '.')
    if (dotPos == 0)
        return false;

    // Domain-i eshte pjesa pas pikes se fundit (p.sh. "com", "al")
    std::string domain = afterAt.substr(dotPos + 1);

    // Domain-i duhet te kete te pakten 2 karaktere
    if (domain.size() < 2)
        return false;

    return true;
}
