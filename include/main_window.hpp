#ifndef MAIN_WINDOW_H
# define MAIN_WINDOW_H
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <GL/gl.h>

enum class WinState : char {
	EXIT,
	RUNNING,
};

typedef struct s_cord {
	int x;
	int y;
} t_cord;

class MouseState
{
public:
	MouseState();
	// void setCords(int sx, int sy);
	// void setCords(t_cord src);
	void buttonUp(Uint32 which);
	void buttonDown(Uint32 which);
	// t_cord getCords(void);
	// t_cord getDyDx(int dst_x, int dst_y, bool overwrite_prev = true);
	// t_cord getDyDx(t_cord dst, bool overwrite_prev = true);
	bool left_down;
	bool right_down;
private:
	// t_cord prev;
};

class MainWindow
{
public:
	MainWindow();
	~MainWindow();
	void run(void);

private:
	void draw_window(void);
	void mainloop(void);
	void init_systems(void);
	void process_input(void);
	
	SDL_Window* _window;
	int _screen_width;
	int _screen_height;
	WinState _win_state;
	MouseState mouse;
};

#endif