#pragma once

#include <vector>
#include <iostream>
#include <sdl_helper.hpp>

class Matrix
{
public:
	Matrix(int rows, int cols);
	Matrix(const std::vector<std::vector<double>> &data);
	Matrix(const Matrix &other);
	Matrix &operator=(const Matrix &other);

	void apply_translation(double x, double y, double z);
	void print_to(std::ostream &os) const;

	Matrix operator*(const Matrix &other) const;
	std::vector<double> operator*(const std::vector<double> &vec) const;
	Matrix operator*(const float scale) const;
	Matrix &operator*=(const Matrix &other);
	Matrix &operator*=(const float scale);

private:
	int rows_;
	int cols_;
	std::vector<std::vector<double>> data_;
};

std::ostream& operator<<(std::ostream& os, const Matrix& m);