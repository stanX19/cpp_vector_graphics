#pragma once
#include <vector>
#include <array>
#include <matrix.hpp>

class Map3D
{
public:
	Map3D() : transformMatrix( {{1, 0, 0, 0}, 
								{0, 1, 0, 0},
								{0, 0, 1, 0},
								{0, 0, 0, 1}})
	{
	}

    void addCoordinate(double x, double y, double z)
    {
        cords.push_back({x, y, z});
		transformedCords.push_back({});
		edges.push_back({});
    }

    void applyTranslation(double dx, double dy, double dz)
    {
        Matrix newTransform = {{{1, 0, 0, dx},
								{0, 1, 0, dy},
								{0, 0, 1, dz},
								{0, 0, 0, 0}}};
        transformMatrix *= newTransform;
    }

    // Function to project the 3D coordinates onto a 2D screen
    std::vector<std::array<double, 2>> projectOntoScreen(void);

private:
	std::vector<std::vector<int>> edges;
    std::vector<std::array<double, 3>> cords;
	std::vector<std::array<double, 3>> transformedCords;
    Matrix transformMatrix;
};