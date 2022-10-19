#ifndef LAGR_HPP
#define LAGR_HPP

#include <cstddef>

#include "Table.hpp"

namespace nmath
{
  using num_t = long double;
  num_t LAGR(std::size_t, const std::vector<num_t> &, const std::vector<num_t> &, num_t);
  num_t LAGR(std::size_t, const Table &, num_t);
}

#endif
