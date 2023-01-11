#include <main_window.hpp>

MouseState::MouseState() : left_down(false), right_down(false)
{
}

// void MouseState::setCords(int sx, int sy)
// {
// 	prev.x = sx;
// 	prev.y = sy;
// }

// void MouseState::setCords(t_cord src)
// {
// 	prev = src;
// }

// t_cord MouseState::getCords(void)
// {
// 	return prev;
// }

void MouseState::buttonUp(Uint32 button)
{
	switch (button)
	{
	case SDL_BUTTON_LEFT:
		left_down = false;
		break;
	case SDL_BUTTON_RIGHT:
		right_down = false;
		break;
	}
}

void MouseState::buttonDown(Uint32 button)
{
	switch (button)
	{
	case SDL_BUTTON_LEFT:
		left_down = true;
		break;
	case SDL_BUTTON_RIGHT:
		right_down = true;
		break;
	}
}

// t_cord MouseState::getDyDx(int dst_x, int dst_y, bool overwrite_prev)
// {
// 	t_cord ret;

// 	ret.x = prev.x - dst_x;
// 	ret.y = prev.y - dst_y;
// 	if (overwrite_prev)
// 		setCords(dst_x, dst_y);
// 	return ret;
// }

// t_cord MouseState::getDyDx(t_cord dst, bool overwrite_prev)
// {
// 	t_cord ret;

// 	ret.x = prev.x - dst.x;
// 	ret.y = prev.y - dst.y;
// 	if (overwrite_prev)
// 		setCords(dst);
// 	return ret;
// }