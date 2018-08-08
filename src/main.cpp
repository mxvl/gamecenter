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

	if (has_colors() != FALSE) {
		start_color();
		new MainWindow((Window *)NULL);
	}

	endwin();
	std::cout << "Your terminal does not support color.\n";

	return 0;
}
