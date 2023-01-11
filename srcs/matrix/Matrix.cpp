#include "matrix.hpp"

Matrix::Matrix(size_t rows, size_t cols) :
	rows_(rows),
	cols_(cols),
	data_(rows, std::vector<double>(cols, 0))
{
}

Matrix::Matrix(const std::vector<std::vector<double>> &data) :
    rows_(data.size()),
    data_(data)
{
    if (data.empty())
        throw std::string("cannot initialize an empty matrix");
    cols_ = data[0].size();
    for (size_t i = 1; i < rows_; i++)
    {
        if (data[i].size() != cols_)
            throw std::string("all rows must have the same number of columns");
    }
}


Matrix::Matrix(const Matrix &other) :
	rows_(other.rows_),
	cols_(other.cols_),
	data_(other.data_)
{
}



