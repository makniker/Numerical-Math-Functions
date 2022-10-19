#include <map>
#include <iostream>

#include "LAGR.hpp"
#include "Table.hpp"
#include "Functors.hpp"

int main()
{
  std::vector<long double> xk;
  xk.push_back(1.2);
  xk.push_back(1.3);
  xk.push_back(1.4);
  xk.push_back(1.5);
  std::vector<long double> fk;
  fk.push_back(0.6754);
  fk.push_back(0.5155);
  fk.push_back(0.3349);
  fk.push_back(0.1411);

  std::cout << "Q with 2 vectors:\n";
  for (size_t i = 1; i <= xk.size(); i++)
  {
    std::cout << "Q" << i << " = " << nmath::LAGR(i, xk, fk, 1.298568) << "\n";
  }

  nmath::Table table(xk);

  nmath::tableFormer<nmath::sin2x>(table);

  std::cout << "Q with tables:\n";
  for (size_t i = 1; i <= xk.size(); i++)
  {
    std::cout << "Q" << i << " = " << nmath::LAGR(i, table, 1.298568) << "\n";
  }
  return 0;
}
