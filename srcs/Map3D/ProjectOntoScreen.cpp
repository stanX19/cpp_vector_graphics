#include <Map3D.hpp>

std::vector<std::array<double, 2>> Map3D::projectOntoScreen(void) {
	std::vector<std::array<double, 2>> projectedCoords;
	for (const auto& coord : cords)
	{
		// Apply transformation matrix to coord
		double x = coord[0] * transformMatrix[0][0] + coord[1] * transformMatrix[0][1] + coord[2] * transformMatrix[0][2] + transformMatrix[0][3];
		double y = coord[0] * transformMatrix[1][0] + coord[1] * transformMatrix[1][1] + coord[2] * transformMatrix[1][2] + transformMatrix[1][3];
		double z = coord[0] * transformMatrix[2][0] + coord[1] * transformMatrix[2][1] + coord[2] * transformMatrix[2][2] + transformMatrix[2][3];

		// Perform projection onto 2D screen
		double screenX = x - z;
		double screenY = y - z;
		projectedCoords.push_back({screenX, screenY});
	}
	return projectedCoords;
}