#include <main_window.hpp>

void MainWindow::draw_window(void){
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// glBegin(GL_TRIANGLES);
	// glColor3f(1.0f, 0.0f, 0.0f);
	// glVertex2f(-1.0f, -1.0f);
	// glVertex2f(0.0f, 1.0f);
	// glVertex2f(1.0f, 0.0f);
	// glEnd();

	SDL_GL_SwapWindow(_window);
}