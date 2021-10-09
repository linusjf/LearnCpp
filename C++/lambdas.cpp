/*
 * lambdas.cpp
 * Copyright (C) 2021  <@localhost>
 *
 * Distributed under terms of the MIT license.
 */
#include "lambdas.h"
#include <iostream>

using namespace std;

void print_values(int i, int j, int k, int l) {
  cout << "i == " << i << endl;
  cout << "j == " << j << endl;
  cout << "k == " << k << endl;
  cout << "l == " << l << endl;
}

int main() {
  int i = 1, j = 10, k = 100, l = 1000;
  auto lambda = [i, &j](int k0, int &l0) -> int {
    j = 2 * j;
    k0 = 2 * k0;
    l0 = 2 * l0;
    return i + j + k0 + l0;
  };
  print_values(i, j, k, l);
  cout << "First call returned " << lambda(k, l) << "\n";
  print_values(i, j, k, l);
  cout << "Second call returned " << lambda(k, l) << "\n";
  print_values(i, j, k, l);
}
