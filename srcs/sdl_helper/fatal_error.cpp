#include <sdl_helper.hpp>

void fatal_error(std::string errorStr)
{
	std::cout << errorStr << std::endl
			  << "Enter any key to quit" << std::endl;
	std::string buf;
	std::cin >> buf;
	SDL_Quit();
}