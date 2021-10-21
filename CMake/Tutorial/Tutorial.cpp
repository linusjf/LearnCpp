/*
 * Tutorial.cpp
 * Copyright (C) 2021  <@localhost>
 *
 * Distributed under terms of the MIT license.
 */
#include <iostream>
#include "TutorialConfig.h"
using namespace std;

int main(const int argc,const char* argv[]) {
  cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
            << Tutorial_VERSION_MINOR << std::endl;
  cout << "Usage: " << argv[0] << endl;
  cout << "Hello, world!" << endl;
}
