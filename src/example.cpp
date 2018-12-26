// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#include <test_lib.h>

#include <Eigen/Core>
#include <iostream>

int main() {
  EigenStdVector<SomeClass::PointT> vec;
  vec.reserve(10);
  for (int i = 0; i < 10; ++i) {
    vec.emplace_back(i, i, i);
    std::cerr << vec.back().transpose() << std::endl;
  }
  return 0;
}
