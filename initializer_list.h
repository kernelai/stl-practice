
#include<initializer_list>
#include<iostream>
void print(std::initializer_list<int> vals);

template <typename T>
void PrintElement(const T& collects) {
  for (const auto& elem : collects) {
    std::cout << elem << std::endl;
  }
}

