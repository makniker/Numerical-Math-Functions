#include "Functors.hpp"

#include <cmath>

nmath::num_t nmath::sin2x::operator()(const num_t &x)
{
  return std::sin(2 * x);
}
