#include "RubikGame.h"
#include "RubikMenu.h"
#include <string>

RubikGame::RubikGame() {
	cube = new Cube;
	drawCube();
	play();
}

RubikGame::~RubikGame() {
}

void RubikGame::play() {
	char move;
	bool validMove;
	WINDOW *localWindow = getWindow();
	
	do {
		move = wgetch(localWindow);
		validMove = cube->move(move);
		drawCube();
	} while(!validMove || !(move == 'q' || cube->isSolved()));
	
	wgetch(localWindow);
	delete this;
	new RubikMenu;
}

bool RubikGame::drawCube() {
	CubeRep *cubeRep = cube->getCube();
	WINDOW *localWindow = getWindow();
	int localStarty = getHeight()/2 -4;
	int localStartx = getWidth()/2 -6;
	
	// Draw top
	wmove(localWindow, localStarty, localStartx+3);
	drawCells(localWindow, cubeRep->top.substr(0, 3));
	wmove(localWindow, localStarty+1, localStartx+3);
	drawCells(localWindow, cubeRep->top.substr(3, 3));
	wmove(localWindow, localStarty+2, localStartx+3);
	drawCells(localWindow, cubeRep->top.substr(6, 3));
	
	// Draw left, front, right, back
	wmove(localWindow, localStarty+3, localStartx);
	drawCells(localWindow, cubeRep->left.substr(0, 3));
	drawCells(localWindow, cubeRep->front.substr(0, 3));
	drawCells(localWindow, cubeRep->right.substr(0, 3));
	drawCells(localWindow, cubeRep->back.substr(0, 3));
	wmove(localWindow, localStarty+4, localStartx);
	drawCells(localWindow, cubeRep->left.substr(3, 3));
	drawCells(localWindow, cubeRep->front.substr(3, 3));
	drawCells(localWindow, cubeRep->right.substr(3, 3));
	drawCells(localWindow, cubeRep->back.substr(3, 3));
	wmove(localWindow, localStarty+5, localStartx);
	drawCells(localWindow, cubeRep->left.substr(6, 3));
	drawCells(localWindow, cubeRep->front.substr(6, 3));
	drawCells(localWindow, cubeRep->right.substr(6, 3));
	drawCells(localWindow, cubeRep->back.substr(6, 3));
	
	// Draw bottom
	wmove(localWindow, localStarty+6, localStartx+3);
	drawCells(localWindow, cubeRep->bottom.substr(0, 3));
	wmove(localWindow, localStarty+7, localStartx+3);
	drawCells(localWindow, cubeRep->bottom.substr(3, 3));
	wmove(localWindow, localStarty+8, localStartx+3);
	drawCells(localWindow, cubeRep->bottom.substr(6, 3));
	
	this->refresh();
}

bool RubikGame::drawCells(WINDOW* localWindow, std::string cells) {
	for (int i=0; i<3; i++) {
		waddch(localWindow, cells[i]);
	}
}

