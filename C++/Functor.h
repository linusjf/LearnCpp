/*
 * Functor.h
 * Copyright (C) 2021  <@localhost>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef FUNCTOR_H
#define FUNCTOR_H

class Functor {
 public:
  Functor(int i, int &j) : my_i{i}, my_jRef{j} {
  }
 
  int operator()(int k0, int &l0) {
    my_jRef = 2 * my_jRef;
    k0 = 2 * k0;
    l0 = 2 * l0;
    return my_i + my_jRef + k0 + l0;
  }

 private:
  int my_i;
  int &my_jRef;
};

#endif /* !FUNCTOR_H */
