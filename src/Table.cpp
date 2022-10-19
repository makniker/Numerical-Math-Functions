#include "Table.hpp"

nmath::Table::Table(const std::vector<num_t> &x) : xk_(x), fk_(x.size())
{
}
