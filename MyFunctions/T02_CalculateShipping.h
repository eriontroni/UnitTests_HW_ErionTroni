#pragma once

// Llogarit çmimin e transportit në bazë të peshës, opsionit express dhe N-së tënde.
// weightKg  - pesha në kg
// express   - a është transport express
// N         - numri yt nga lista në Excel (përdoret për parametrat)
double CalculateShipping(double weightKg, bool express, int N);
