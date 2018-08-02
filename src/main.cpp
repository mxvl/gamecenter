#include <ncurses.h>
#include <iostream>

#include "ui/template/Window.h"
#include "ui/main/MainWindow.h"

int main(int argc, char** argv) {

	wchar_t ch;

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	refresh();

	Window *currentWindow = new MainWindow((Window *)NULL);
	delete currentWindow;

	endwin();
	return 0;
}
