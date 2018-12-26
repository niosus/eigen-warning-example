// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <Eigen/StdVector>

#include <vector>

template <class EigenT>
using EigenStdVector = std::vector<EigenT, Eigen::aligned_allocator<EigenT>>;

class SomeClass {
public:
  using PointT = Eigen::Matrix<float, 3, 1>;
};
