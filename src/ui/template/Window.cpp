#include "Window.h"

Window::Window() {
	height = LINES;
	width = COLS;
	starty = (LINES - height) / 2;
	startx = (COLS - width) / 2;

	window = createNewWindow();
	this->refresh();
}

Window::~Window() {
	wborder(window, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(window);
	delwin(window);
}

WINDOW *Window::createNewWindow() {
	return newwin(height, width, starty, startx);
}

WINDOW *Window::getWindow() {
	return window;
}

void Window::refresh() {
	wrefresh(window);
}