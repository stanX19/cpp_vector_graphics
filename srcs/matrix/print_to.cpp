#include "matrix.hpp"

void Matrix::print_to(std::ostream &os) const {
	for (size_t i = 0; i < rows_; i++)
    {
        os << "[";
        for (size_t j = 0; j < cols_; j++)
        {
            os << data_[i][j];
            if (j < cols_ - 1)
            {
                os << ", ";
            }
        }
        os << "]";
        if (i < rows_ - 1)
        {
            os << std::endl;
        }
    }
}