#include <Map3D.hpp>

std::vector<std::array<double, 2>> Map3D::projectOntoScreen(void) {
	std::vector<std::array<double, 2>> projectedCoords;
	for (const std::array<double, 3>& cord : cords)
	{
		std::array<double, 3> cord_cpy(cord);

		// Perform projection onto 2D screen
		double screenX = x - z;
		double screenY = y - z;
		projectedCoords.push_back({screenX, screenY});
	}
	return projectedCoords;
}