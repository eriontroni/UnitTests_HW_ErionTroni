#pragma once
#include <string>

// Kthen true nëse password-i është i fortë sipas rregullave me N.
// minLength = 6 + (N % 5).
// N çift  → kërkohet 1 shkronjë e madhe + 1 shifër.
// N tek   → kërkohet 1 shkronjë e madhe + 1 shifër + 1 karakter special (! @ # $ %).
bool IsStrongPassword(const std::string& password, int N);
