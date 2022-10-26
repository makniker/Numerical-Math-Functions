#include "Table.hpp"

nmath::Table::Table(const num_t& x1, const num_t& step, std::size_t size): xk_(size), fk_(size), size_(size), step_(step)
{
	for (size_t i = 0; i < size; i++)
	{
	  xk_[i] = x1 + step_ * i;
	}
}

nmath::Table::Table(const std::vector<num_t> &x) : xk_(x), fk_(x.size()), size_(x.size()), step_(x.size() > 1 ? xk_[1] - xk_[1] : 0)
{
}
