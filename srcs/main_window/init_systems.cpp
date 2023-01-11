#include <main_window.hpp>
#include <sdl_helper.hpp>

void MainWindow::init_systems(void)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("graphics engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
								 _screen_width, _screen_height, SDL_WINDOW_OPENGL);
	if (_window == nullptr)
	{
		fatal_error("Error: SDL window could not be created! exiting");
	}

	SDL_GLContext glContex = SDL_GL_CreateContext(_window);

	if (glContex == nullptr)
	{
		fatal_error("Error: SDL_GL context could not be created! exiting");
	}

	//glew for opengl function if mising

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // swapping window for smoothness
	glClearColor(0.2f, 0.5f, 0.0f, 1.0f); // backgroud color
}