/*
 * transred.cpp
 * Copyright (C) 2021  <@localhost>
 *
 * Distributed under terms of the MIT license.
 */

#include <execution>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<double> xvalues(10007, 1.0), yvalues(10007, 1.0);

  double result = std::transform_reduce(std::execution::par,
                                        xvalues.begin(),
                                        xvalues.end(),
                                        yvalues.begin(),
                                        0.0);
  std::cout << result << '\n';
}
