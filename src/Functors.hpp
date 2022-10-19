#ifndef FUNCTORS_HPP
#define FUNCTORS_HPP

namespace nmath
{
  using num_t = long double;

  struct sin2x
  {
    sin2x() = default;
    num_t operator()(const num_t &);
  };
}

#endif
