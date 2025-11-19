#include "T03_ContainsBadWords.h"
#include <algorithm> // std::transform
#include <cctype>    // std::tolower
#include <vector>

static std::string ToLower(const std::string& s)
{
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return result;
}

bool ContainsBadWords(const std::string& text, int N)
{
    // Fjalët bazë të ndaluara
    const std::string bad1 = "idiot";
    const std::string bad2 = "stupid";

    std::string bad3;
    int mod = N % 3;
    if (mod == 0)
        bad3 = "hate";
    else if (mod == 1)
        bad3 = "noob";
    else
        bad3 = "trash";

    // E bëjmë tekstin lowercase për krahasim case-insensitive
    std::string lowerText = ToLower(text);

    // Edhe fjalët i kemi lowercase (veç janë, por është safe)
    std::vector<std::string> badWords = {
        ToLower(bad1),
        ToLower(bad2),
        ToLower(bad3)
    };

    // Kontrollo nëse cilado nga fjalët ndaluese gjendet si substring
    for (const auto& w : badWords)
    {
        if (w.empty())
            continue;

        if (lowerText.find(w) != std::string::npos)
            return true;
    }

    return false;
}
