#include <gtest/gtest.h>
#include "initializer_list.h"

TEST(TestInitializerList, Print) { print({1, 2, 3}); }
TEST(TestInitializerList, PrintElement) {
  std::vector<int> collects{1, 2, 3, 4};
  PrintElement(collects);
}