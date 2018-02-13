#ifndef RUBIKGAME_H
#define RUBIKGAME_H

#include "../template/Window.h"
#include "../../game/rubik/Cube.h"

class RubikGame : public Window {
public:
	RubikGame();
	virtual ~RubikGame();
	
private:
	Cube *cube;
	bool drawCube();
	bool drawCells(WINDOW *localWindow, std::string cells);
	void play();
};

#endif /* RUBIKGAME_H */

