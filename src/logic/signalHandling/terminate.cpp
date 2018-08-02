#include "terminate.h"
#include <ncurses.h>
#include <stdlib.h>

void endGamecenter(Window *win) {
	delete win;
	endwin();
	exit(0);
}
