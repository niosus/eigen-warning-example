// Copyright Igor Bogoslavskyi, year 2018.

#include <Eigen/Core>
#include <Eigen/StdVector>
#include <iostream>

template <class EigenT>
using EigenStdVector = std::vector<EigenT, Eigen::aligned_allocator<EigenT>>;

int main() {
  EigenStdVector<Eigen::Vector3f> vec;
  vec.emplace_back(1.0f, 1.0f, 1.0f);
  std::cerr << vec.back().transpose() << std::endl;
  return 0;
}
