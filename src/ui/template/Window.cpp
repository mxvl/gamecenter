#include "Window.h"

Window::Window(Window *win) {
	height = LINES;
	width = COLS;
	starty = (LINES - height) / 2;
	startx = (COLS - width) / 2;

	window = createNewWindow();
	delete win;
	this->refresh();
}

Window::~Window() {
	wborder(window, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(window);
	delwin(window);
}

WINDOW *Window::createNewWindow() {
	WINDOW *localWindow = newwin(height, width, starty, startx);
	box(localWindow, 0, 0);
	
	return localWindow;
}

WINDOW *Window::getWindow() {
	return window;
}

void Window::refresh() {
	wrefresh(window);
}

int Window::getHeight() {
	return height;
}

int Window::getWidth() {
	return width;
}
