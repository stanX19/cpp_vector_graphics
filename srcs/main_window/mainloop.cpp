#include <main_window.hpp>

void MainWindow::mainloop(void)
{
	_win_state = WinState::RUNNING;
	while (_win_state != WinState::EXIT) {
		process_input();
		draw_window();
	}
}
