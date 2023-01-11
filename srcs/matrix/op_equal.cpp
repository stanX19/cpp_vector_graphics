#include <matrix.hpp>

Matrix &Matrix::operator=(const Matrix &other)
{
	rows_ = other.rows_;
	cols_ = other.cols_;
	data_ = other.data_;
	return *this;
}
