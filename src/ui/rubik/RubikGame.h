#ifndef RUBIKGAME_H
#define RUBIKGAME_H

#include "../template/Window.h"
#include "../../game/rubik/Cube.h"

class RubikGame : public Window {
public:
	RubikGame(Window *win);
	virtual ~RubikGame();
	
private:
	short scaleX, scaleY;
	short red, yellow, green, orange, blue, white;
	Cube *cube;
	bool drawCube();
	bool drawCells(WINDOW *localWindow, const std::string cells, const int y, const int x) const;
	bool drawCell(WINDOW* localWindow, const short pair, const int y, const int x) const;
	void play();
};

#endif /* RUBIKGAME_H */

