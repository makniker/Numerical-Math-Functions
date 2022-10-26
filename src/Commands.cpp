#include "Commands.hpp"

#include <ostream>
#include <istream>
#include <map>

#include "LAGR.hpp"
#include "Neuton.hpp"
#include "Table.hpp"
#include "Functors.hpp"
#include <iomanip>


void nmath::lab2(std::ostream& out, std::istream& in)
{
	num_t firstPoint;
	num_t step;
	std::size_t order;
	in >> firstPoint >> step >> order;
	nmath::Table table(firstPoint, step, order);
	nmath::tableFormer<nmath::sin2x>(table);
	out << "LAGRANGE:" << "			" << "NEUTON:\n";
	out << std::setprecision(10);
	for (size_t i = 1; i <= order; i++)
	{
		out << "Q" << i - 1 << " = " << nmath::LAGR(i, table, 0.601432) << "  " << "Q" << i - 1 << " = " << nmath::NEUTON(i, table, 0.601432) << "\n";
	}
	return;
}