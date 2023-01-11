#include <iostream>
#include <string>
#include <array>
#include <main_window.hpp>
#include <matrix.hpp>

int main(int argc, char **argv)
{
	// MainWindow main_window;
	// main_window.run();
	Matrix m1 = {{{1, 1, 2, 0},
				{0, 0, 0, 0},
				{0, 0, 0, 0},
				{0, 0, 0, 0}}};
	std::vector<double> v1 = {1, 2, 3};
	v1 = m1 * v1;
	std::cout << v1[0] << std::endl;

	(void)argc; (void)argv;
	return 0;
}