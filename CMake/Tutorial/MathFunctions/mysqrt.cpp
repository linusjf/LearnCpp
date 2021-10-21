/*
 * mysqrt.cpp
 * Copyright (C) 2021  <@localhost>
 *
 * Distributed under terms of the MIT license.
 */
#include "mysqrt.h"
#include <cmath>
 
// Function to find the square-root of N
double mysqrt(double N) { 
  return pow(2, 0.5 * log2(N)); 
}
