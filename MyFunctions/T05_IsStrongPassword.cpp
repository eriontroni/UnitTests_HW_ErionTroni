#include "T05_IsStrongPassword.h"
#include <cctype>   // std::isupper, std::isdigit

bool IsStrongPassword(const std::string& password, int N)
{
    // minLength = 6 + (N % 5)  ? 6–10
    int minLength = 6 + (N % 5);

    // Kontrollo gjatësinë
    if (static_cast<int>(password.size()) < minLength)
        return false;

    bool hasUpper = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    // Karakteret speciale të lejuara për N tek
    const std::string specials = "!@#$%";

    for (char ch : password)
    {
        if (std::isupper(static_cast<unsigned char>(ch)))
            hasUpper = true;

        if (std::isdigit(static_cast<unsigned char>(ch)))
            hasDigit = true;

        if (specials.find(ch) != std::string::npos)
            hasSpecial = true;
    }

    // N çift: kërkohet uppercase + digit
    if (N % 2 == 0)
    {
        return hasUpper && hasDigit;
    }
    // N tek: kërkohet uppercase + digit + special
    else
    {
        return hasUpper && hasDigit && hasSpecial;
    }
}
