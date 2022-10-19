#ifndef TABLE_HPP
#define TABLE_HPP

#include <vector>

namespace nmath
{
  using num_t = long double;
  struct Table
  {
    Table(const std::vector<num_t> &);
    std::vector<num_t> xk_;
    std::vector<num_t> fk_;
  };

  template <typename T>
  void tableFormer(Table &t)
  {
    T f;
    for (size_t i = 0; i < t.xk_.size(); i++)
    {
      t.fk_[i] = f(t.xk_[i]);
    }
  }
}

#endif
