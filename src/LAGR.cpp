#include "LAGR.hpp"

#include <iostream>

nmath::num_t nmath::LAGR(std::size_t numberOfPoints, const Table &table, num_t point)
{
  nmath::num_t Q = 0;
  for (size_t k = 0; k < numberOfPoints; k++)
  {
    num_t wxk = 1;
    num_t wx = 1;
    for (size_t j = 0; j < numberOfPoints; j++)
    {
      if (j != k)
      {
        wx *= (point - table.xk_[j]);
        wxk *= (table.xk_[k] - table.xk_[j]);
      }
    }
    Q += (wx / wxk) * table.fk_[k];
    wxk = 1;
    wx = 1;
  }
  return Q;
}

nmath::num_t nmath::LAGR(std::size_t numberOfPoints, const std::vector<num_t> &xk, const std::vector<num_t> &fk, num_t point)
{
  nmath::num_t Q = 0;
  for (size_t k = 0; k < numberOfPoints; k++)
  {
    num_t wxk = 1;
    num_t wx = 1;
    for (size_t j = 0; j < numberOfPoints; j++)
    {
      if (j != k)
      {
        wx *= (point - xk[j]);
        wxk *= (xk[k] - xk[j]);
      }
    }
    Q += (wx / wxk) * fk[k];
    wxk = 1;
    wx = 1;
  }
  return Q;
}
