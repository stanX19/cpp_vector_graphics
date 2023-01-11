#include "matrix.hpp"

Matrix Matrix::operator*(const Matrix &other) const
{
	Matrix result(rows_, other.cols_);

	if (cols_ != other.rows_)
		fatal_error("Invalid matrix multiplication!");
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < other.cols_; j++)
		{
			for (int k = 0; k < cols_; k++)
			{
				result.data_[i][j] += data_[i][k] * other.data_[k][j];
			}
		}
	}
	return result;
}

std::vector<double> Matrix::operator*(const std::vector<double> &vec) const
{
	std::vector<double> result(vec.size(), 0);

	if (cols_ != vec.size()) // invalid multiplication
	{
		for (int i = 0; i < rows_; i++)
		{
			int j;
			for (j = 0; j < vec.size(); j++)
			{
				result[i] += data_[i][j] * vec[j];
			}
			while (j < cols_)
			{
				result[i] += data_[i][j++]; // multiplied by 1, as filler
			}
		}
	}
	else
	{
		for (int i = 0; i < rows_; i++)
		{
			for (int j = 0; j < cols_; j++)
			{
				result[i] += data_[i][j] * vec[j];
			}
		}
	}
	return result;
}

Matrix Matrix::operator*(const float scale) const
{
	Matrix result(data_);

	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			result.data_[i][j] = data_[i][j] * scale;
		}
	}
	return result;
}

Matrix &Matrix::operator*=(const Matrix &other)
{
	*this = *this * other;
	return *this;
}

Matrix &Matrix::operator*=(const float scale)
{
	*this = *this * scale;
	return *this;
}