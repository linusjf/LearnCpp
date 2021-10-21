/*
 * Tutorial.cpp
 * Copyright (C) 2021  <@localhost>
 *
 * Distributed under terms of the MIT license.
 */
#ifdef USE_MYMATH
#include "MathFunctions/mysqrt.h"
#endif
#include "TutorialConfig.h"
#include <cmath>
#include <iostream>
using namespace std;

int main(const int /*argc*/,const char* argv[]) {
  cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
            << Tutorial_VERSION_MINOR << std::endl;
  cout << "Usage: " << argv[0] << endl;
  cout << "Hello, world!" << endl;
  double outputValue;
#ifdef USE_MYMATH
  outputValue = mysqrt(49.0);
#else
  outputValue = sqrt(49.0);
#endif
}
