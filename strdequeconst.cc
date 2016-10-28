#include "cstrdeque"
#include "cstrdequeconst"
#include <iostream>

namespace jnp1 {

unsigned long emptystrdeque() {
  static unsigned long empty = jnp1::strdeque_new();
  return empty;
}
}
