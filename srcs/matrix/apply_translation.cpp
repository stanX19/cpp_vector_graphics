#include <matrix.hpp>

void Matrix::apply_translation(double dx, double dy, double dz)
{
	
	data_[0][3] += dx;
	data_[1][3] += dy;
	data_[2][3] += dz;
}