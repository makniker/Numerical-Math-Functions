#include "LAGR.hpp"

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
  }
  return Q;
}
