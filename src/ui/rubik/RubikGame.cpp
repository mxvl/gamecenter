#include "RubikGame.h"
#include "RubikMenu.h"
#include <string>

RubikGame::RubikGame(Window *win) : Window(win) {
	scaleX = 5;
	scaleY = 3;
	help = true;
	cube = new Cube;

	init_pair(1, 0, COLOR_RED);
	red = 1;
	init_pair(2, 0, COLOR_YELLOW);
	yellow = 2;
	init_pair(3, 0, COLOR_GREEN);
	green = 3;
	init_pair(4, 0, COLOR_BLUE);
	blue = 4;
	init_pair(5, 0, COLOR_WHITE);
	white = 5;
	init_pair(6, 0, COLOR_MAGENTA);
	orange = 6;

	keypad(getWindow(), TRUE);
	printHelp(getWindow());
	drawCube();
	play();
}

RubikGame::~RubikGame() {
	keypad(getWindow(), FALSE);
}

void RubikGame::play() {
	int move;
	bool validMove;
	WINDOW *localWindow = getWindow();
	
	do {
		validMove = false;
		move = wgetch(localWindow);

		switch (move) {
			case KEY_F(1): help = !help; printHelp(localWindow); break;
			case KEY_F(9): validMove = true; break;
			default: validMove = cube->move(move); break;
		}
		drawCube();
	} while(!validMove || !(move == KEY_F(9) || cube->isSolved()));
	
	wgetch(localWindow);
	new RubikMenu(this);
}

bool RubikGame::drawCube() {
	CubeRep *cubeRep = cube->getCube();
	WINDOW *localWindow = getWindow();
	int y = getHeight()/2 -scaleY*4;
	int x = getWidth()/2 -scaleX*6;
	
	// Draw top
	drawCells(localWindow, cubeRep->top.substr(0, 3), y, x+scaleX*3);
	drawCells(localWindow, cubeRep->top.substr(3, 3), y+scaleY, x+scaleX*3);
	drawCells(localWindow, cubeRep->top.substr(6, 3), y+scaleY*2, x+scaleX*3);

	// Draw left, front, right, back
	y += scaleY*3;
	drawCells(localWindow, cubeRep->left.substr(0, 3), y, x);
	drawCells(localWindow, cubeRep->front.substr(0, 3), y, x+scaleX*3);
	drawCells(localWindow, cubeRep->right.substr(0, 3), y, x+scaleX*6);
	drawCells(localWindow, cubeRep->back.substr(0, 3), y, x+scaleX*9);
	y += scaleY;
	drawCells(localWindow, cubeRep->left.substr(3, 3), y, x);
	drawCells(localWindow, cubeRep->front.substr(3, 3), y, x+scaleX*3);
	drawCells(localWindow, cubeRep->right.substr(3, 3), y, x+scaleX*6);
	drawCells(localWindow, cubeRep->back.substr(3, 3), y, x+scaleX*9);
	y += scaleY;
	drawCells(localWindow, cubeRep->left.substr(6, 3), y, x);
	drawCells(localWindow, cubeRep->front.substr(6, 3), y, x+scaleX*3);
	drawCells(localWindow, cubeRep->right.substr(6, 3), y, x+scaleX*6);
	drawCells(localWindow, cubeRep->back.substr(6, 3), y, x+scaleX*9);

	// Draw bottom
	y += scaleY;
	drawCells(localWindow, cubeRep->bottom.substr(0, 3), y, x+scaleX*3);
	drawCells(localWindow, cubeRep->bottom.substr(3, 3), y+scaleY, x+scaleX*3);
	drawCells(localWindow, cubeRep->bottom.substr(6, 3), y+scaleY*2, x+scaleX*3);

	this->refresh();

	return true;
}

bool RubikGame::drawCells(WINDOW* localWindow, const std::string cells, const int y, const int x) const {
	short color;

	for (int i=0; i<3; i++) {
		switch (cells[i]) {
			case 'W': color = white; break;
			case 'R': color = red; break;
			case 'Y': color = yellow; break;
			case 'G': color = green; break;
			case 'B': color = blue; break;
			case 'O': color = orange; break;
			default: color = 0; break;
		}
		drawCell(localWindow, color, y, x+scaleX*i);
	}

	return true;
}

bool RubikGame::drawCell(WINDOW* localWindow, const short pair, const int y, const int x) const {
	wattron(localWindow, COLOR_PAIR(pair));

	for (int i=0; i<scaleY; i++) {
		wmove(localWindow, y+i, x);
		for (int j=0; j<scaleX; j++) {
			waddch(localWindow, ' ');
		}
	}

	wattroff(localWindow, COLOR_PAIR(pair));
	return true;
}

void RubikGame::printHelp(WINDOW* localWindow) {
	if (help) {
		mvwprintw(localWindow, 1, 1, "-- Help --");
		mvwprintw(localWindow, 2, 1, "Use the following keys to manipulate the cube :");
		mvwprintw(localWindow, 3, 1, "(SHIFT make the movement counter clock)");
		mvwprintw(localWindow, 4, 3, "w to turn the top");
		mvwprintw(localWindow, 5, 3, "a to turn the left");
		mvwprintw(localWindow, 6, 3, "s to turn the bottom");
		mvwprintw(localWindow, 7, 3, "d to turn the right");
		mvwprintw(localWindow, 8, 3, "q to turn the back");
		mvwprintw(localWindow, 9, 3, "e to turn the front");
		mvwprintw(localWindow, 10, 1, "Press F1 to hide/show this help");
		mvwprintw(localWindow, 11, 1, "Press ESC to quit");
	} else {
		wclear(localWindow);
		box(localWindow, 0, 0);
	}
}
