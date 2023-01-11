#include <matrix.hpp>

void Matrix::applyTranslation(double dx, double dy, double dz)
{
	Matrix newTransform = {{{1, 0, 0, dx},
							{0, 1, 0, dy},
							{0, 0, 1, dz},
							{0, 0, 0, 0}}};
	*this *= newTransform;
}