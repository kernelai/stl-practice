#include "initializer_list.h"
void print(std::initializer_list<int> vals) {
  for (auto &&v : vals) {
    std::cout << "value: " << v << "\n";
  }
}

