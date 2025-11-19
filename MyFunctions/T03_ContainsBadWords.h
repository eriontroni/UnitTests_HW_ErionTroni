#pragma once
#include <string>

// Kthen true nëse teksti përmban ndonjërën nga fjalët e ndaluara
// (idiot, stupid, dhe bad3 që varet nga N).
bool ContainsBadWords(const std::string& text, int N);
