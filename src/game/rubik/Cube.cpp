#include "Cube.h"

Cube::Cube() {
	cube->top = "WWWWWWWWW";
	cube->bottom = "YYYYYYYYYY";
	cube->left = "GGGGGGGGG";
	cube->right = "BBBBBBBBB";
	cube->front = "RRRRRRRRR";
	cube->back = "OOOOOOOOO";
}

Cube::Cube(const Cube& orig) {
	cube = orig.getCube();
}

Cube::~Cube() {
	delete cube;
}

bool Cube::move(const char move) {
	bool validMove = false;
	
	switch(move) {
	case 'U':
		moveTop(true);
		validMove = true;
		break;
		
	case 'u':
		moveTop(false);
		validMove = true;
		break;
	}
	
	return validMove;
}

void Cube::moveTop(const bool clockwise) {
	std::string newTop, newLeft, newRight, newFront, newBack;
	
	if (clockwise) {
		
	} else {
		newTop = cube->top[2];
		newTop += cube->top[5];
		newTop += cube->top[8];
		newTop += cube->top[1];
		newTop += cube->top[4];
		newTop += cube->top[7];
		newTop += cube->top[0];
		newTop += cube->top[3];
		newTop += cube->top[6];
	}
	
	cube->top = newTop;
	cube->left = newLeft;
	cube->right = newRight;
	cube->front = newFront;
	cube->back = newBack;
}

CubeRep *Cube::getCube() const {
	CubeRep *localCube = new CubeRep;
	
	localCube->top = std::string(cube->top);
	localCube->bottom = std::string(cube->bottom);
	localCube->left = std::string(cube->left);
	localCube->right = std::string(cube->right);
	localCube->front = std::string(cube->front);
	localCube->back = std::string(cube->back);
	
	return localCube;
}

