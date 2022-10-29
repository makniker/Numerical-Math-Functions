#include "Commands.hpp"

#include <ostream>
#include <istream>
#include <iomanip>

#include "LAGR.hpp"
#include "Neuton.hpp"
#include "Table.hpp"
#include "Functors.hpp"

std::ostream &nmath::printLabsList(std::ostream &out, const LabDict &dict)
{
  for (auto i = dict.begin(); i != dict.end(); i++)
  {
    out << "Lab " << (*i).first << ": complete!\n";
  }
  out << "Other labs [IN CONSTRUCT]\n";
  return out;
}

void nmath::lab2(std::ostream &out, std::istream &in)
{
  out << "Interpolation polynomial in Lagrange and Newton form\n";
  num_t firstPoint;
  num_t point;
  num_t step;
  std::size_t order;
  out << "Enter point:\n";
  in >> point;
  out << "Enter first point in table:\n";
  in >> firstPoint;
  out << "Enter step in table:\n";
  in >> step;
  out << "Enter order\n";
  in >> order;
  nmath::Table table(firstPoint, step, order);
  nmath::tableFormer<nmath::sin2x>(table);
  out << "LAGRANGE:"
      << "  "
      << "NEUTON:\n";
  out << std::setprecision(10);
  for (size_t i = 1; i <= order; i++)
  {
    out << "Q" << i - 1 << " = " << nmath::LAGR(i, table, point) << "  "
        << "Q" << i - 1 << " = " << nmath::NEUTON(i, table, point) << "\n";
  }
  if (order > 3)
  {
    out << "Notice that when building a formula of the fourth order and higher,\nthe error in the Newton polynomial becomes so significant\nthat it does not give exact values.\n";
  }
  return;
}
