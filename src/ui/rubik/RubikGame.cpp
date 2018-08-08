#include "RubikGame.h"
#include "RubikMenu.h"
#include <string>

RubikGame::RubikGame(Window *win) : Window(win) {
	scaleX = 5;
	scaleY = 3;
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
		move = wgetch(localWindow);
		validMove = cube->move(move);
		drawCube();
	} while(!validMove || !(move == 'z' || cube->isSolved()));
	
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
