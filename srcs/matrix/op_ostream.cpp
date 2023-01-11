#include "matrix.hpp"

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    m.print_to(os);
	return os;
}