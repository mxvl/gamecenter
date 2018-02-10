#include "terminate.h"
#include <ncurses.h>
#include <stdlib.h>

void endGamecenter() {
	endwin();
	exit(0);
}