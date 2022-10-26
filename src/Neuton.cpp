#include "Neuton.hpp"

#include <cmath>

namespace
{
	nmath::num_t factorial(std::size_t x)
	{
		return x == 1 ? x : factorial(x - 1);
	}

	struct TableOfFinDiff
	{
		TableOfFinDiff(const nmath::Table& table);
		std::size_t width_;
		std::size_t height_;
		std::vector< std::vector < nmath::num_t > > table_;
		void calculateOrder(std::size_t order);
	};

	TableOfFinDiff::TableOfFinDiff(const nmath::Table& table): width_(table.size_), height_(4), table_(width_)
	{
		table_[0] = table.fk_;
		for (size_t i = 1; i < width_; i++)
		{
			std::vector < nmath::num_t > column(height_, 0);
			table_[i] = column;
		}
	}

	void TableOfFinDiff::calculateOrder(std::size_t order)
	{
		if (order <= width_ && order != 0)
		{
			for (size_t i = 0; i < height_ - 1; i++)
			{
				table_[order][i] = table_[order - 1][i + 1] - table_[order - 1][i];
			}
		}
	}
}

nmath::num_t nmath::NEUTON(std::size_t numberOfPoints, const Table& table, num_t point)
{
	num_t Q = table.fk_[0];
	num_t t = (point - table.xk_[0]) / table.step_;
	TableOfFinDiff helpTable(table);
	for (size_t i = 1; i < numberOfPoints; i++)
	{
		num_t additional = 1;
		num_t findiff = 1;
		helpTable.calculateOrder(i);
		findiff = helpTable.table_[i][0];
		for (size_t j = 0; j < i; j++)
		{
			additional *= (t - j);
		}
		Q += (additional / factorial(i)) * findiff;
	}
	return Q;
}