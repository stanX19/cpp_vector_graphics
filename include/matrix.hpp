#pragma once

#include <vector>
#include <iostream>
#include <sdl_helper.hpp>

class Matrix
{
public:
	Matrix(size_t rows, size_t cols);
	Matrix(const std::vector<std::vector<double>> &data);
	Matrix(const Matrix &other);
	Matrix &operator=(const Matrix &other);

	void applyTranslation(double x, double y, double z);
	void print_to(std::ostream &os) const;

	std::vector<double> operator*(const std::vector<double> &vec) const;
	Matrix operator*(const Matrix &other) const;
	Matrix operator*(const float scale) const;
	Matrix &operator*=(const Matrix &other);
	Matrix &operator*=(const float scale);

private:
	size_t rows_;
	size_t cols_;
	std::vector<std::vector<double>> data_;
};

std::ostream& operator<<(std::ostream& os, const Matrix& m);

