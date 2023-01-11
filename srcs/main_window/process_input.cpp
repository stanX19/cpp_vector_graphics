#include <main_window.hpp>
#include <iostream>

void MainWindow::process_input(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			_win_state = WinState::EXIT;
			break;

		case SDL_MOUSEWHEEL:
			if (event.wheel.y < 0)
				std::cout << "foward" << abs(event.wheel.y) << std::endl;
			else
				std::cout << "backward" << event.wheel.y << std::endl;;
			break;

		case SDL_MOUSEBUTTONDOWN:
			mouse.buttonDown(event.button.button);
			break;

		case SDL_MOUSEBUTTONUP:
			mouse.buttonUp(event.button.button);
			break;

		case SDL_MOUSEMOTION:
			if (mouse.left_down) {
				t_cord dydx = {event.motion.xrel, event.motion.yrel};

				std::cout << "dy/dx = " << dydx.y << '/' << dydx.x << std::endl;
			}
			break;
		}
	}
}