#include "matrix.hpp"

Matrix::Matrix(int rows, int cols) :
	rows_(rows),
	cols_(cols),
	data_(rows, std::vector<double>(cols, 0))
{
}

Matrix::Matrix(const std::vector<std::vector<double>> &data) :
	rows_(data.size()),
	data_(data)
{
	if (!rows_)
		return ;
	cols_ = data[0].size();
}


Matrix::Matrix(const Matrix &other) :
	rows_(other.rows_),
	cols_(other.cols_),
	data_(other.data_)
{
}



