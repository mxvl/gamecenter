#include "Cube.h"

Cube::Cube() {
	cube = new CubeRep;
	cube->top = std::string("WWWWWWWWW");
	cube->bottom = std::string("YYYYYYYYYY");
	cube->left = std::string("GGGGGGGGG");
	cube->right = std::string("BBBBBBBBB");
	cube->front = std::string("RRRRRRRRR");
	cube->back = std::string("OOOOOOOOO");
}

Cube::Cube(const Cube& orig) {
	cube = orig.getCube();
}

Cube::~Cube() {
	delete cube;
}

bool Cube::move(const int move) {
	bool validMove = false;
	
	switch(move) {
	case 'w':
		moveTop(true);
		validMove = true;
		break;
	case 'W':
		moveTop(false);
		validMove = true;
		break;
	case 'a':
		moveLeft(true);
		validMove = true;
		break;
	case 'A':
		moveLeft(false);
		validMove = true;
		break;
	case 'e':
		moveFront(true);
		validMove = true;
		break;
	case 'E':
		moveFront(false);
		validMove = true;
		break;
	case 'd':
		moveRight(true);
		validMove = true;
		break;
	case 'D':
		moveRight(false);
		validMove = true;
		break;
	case 'q':
		moveBack(true);
		validMove = true;
		break;
	case 'Q':
		moveBack(false);
		validMove = true;
		break;
	case 's':
		moveBottom(true);
		validMove = true;
		break;
	case 'S':
		moveBottom(false);
		validMove = true;
		break;
	case 'z':
		validMove = true;
		break;
	default:
		break;
	}
	
	return validMove;
}

void Cube::moveTop(const bool clockwise) {
	std::string frontTmp = cube->front.substr(0, 3);
	
	if (clockwise) {
		cube->front.replace(0, 3, cube->right.substr(0, 3));
		cube->right.replace(0, 3, cube->back.substr(0, 3));
		cube->back.replace(0, 3, cube->left.substr(0, 3));
		cube->left.replace(0, 3, frontTmp);
	} else {
		cube->front.replace(0, 3, cube->left.substr(0, 3));
		cube->left.replace(0, 3, cube->back.substr(0, 3));
		cube->back.replace(0, 3, cube->right.substr(0, 3));
		cube->right.replace(0, 3, frontTmp);
	}
	
	cube->top = turnFace(cube->top, clockwise);
}

void Cube::moveLeft(const bool clockwise) {
	std::string topTmp = cube->top;
	
	if (clockwise) {
		cube->top[0] = cube->back[8];
		cube->top[3] = cube->back[5];
		cube->top[6] = cube->back[2];
		cube->back[8] = cube->bottom[0];
		cube->back[5] = cube->bottom[3];
		cube->back[2] = cube->bottom[6];
		cube->bottom[0] = cube->front[0];
		cube->bottom[3] = cube->front[3];
		cube->bottom[6] = cube->front[6];
		cube->front[0] = topTmp[0];
		cube->front[3] = topTmp[3];
		cube->front[6] = topTmp[6];
	} else {
		cube->top[0] = cube->front[0];
		cube->top[3] = cube->front[3];
		cube->top[6] = cube->front[6];
		cube->front[0] = cube->bottom[0];
		cube->front[3] = cube->bottom[3];
		cube->front[6] = cube->bottom[6];
		cube->bottom[0] = cube->back[8];
		cube->bottom[3] = cube->back[5];
		cube->bottom[6] = cube->back[2];
		cube->back[8] = topTmp[0];
		cube->back[5] = topTmp[3];
		cube->back[2] = topTmp[6];
	}
	
	cube->left = turnFace(cube->left, clockwise);
}

void Cube::moveFront(const bool clockwise) {
	std::string topTmp = cube->top.substr(6, 3);
	
	if (clockwise) {
		cube->top[6] = cube->left[8];
		cube->top[7] = cube->left[5];
		cube->top[8] = cube->left[2];
		cube->left[8] = cube->bottom[2];
		cube->left[5] = cube->bottom[1];
		cube->left[2] = cube->bottom[0];
		cube->bottom[2] = cube->right[0];
		cube->bottom[1] = cube->right[3];
		cube->bottom[0] = cube->right[6];
		cube->right[0] = topTmp[0];
		cube->right[3] = topTmp[1];
		cube->right[6] = topTmp[2];
	} else {
		cube->top[6] = cube->right[0];
		cube->top[7] = cube->right[3];
		cube->top[8] = cube->right[6];
		cube->right[0] = cube->bottom[2];
		cube->right[3] = cube->bottom[1];
		cube->right[6] = cube->bottom[0];
		cube->bottom[2] = cube->left[8];
		cube->bottom[1] = cube->left[5];
		cube->bottom[0] = cube->left[2];
		cube->left[8] = topTmp[0];
		cube->left[5] = topTmp[1];
		cube->left[2] = topTmp[2];
	}
	
	cube->front = turnFace(cube->front, clockwise);
}

void Cube::moveRight(const bool clockwise) {
	std::string frontTmp = cube->front;
	
	if (clockwise) {
		cube->front[2] = cube->bottom[2];
		cube->front[5] = cube->bottom[5];
		cube->front[8] = cube->bottom[8];
		cube->bottom[2] = cube->back[6];
		cube->bottom[5] = cube->back[3];
		cube->bottom[8] = cube->back[0];
		cube->back[6] = cube->top[2];
		cube->back[3] = cube->top[5];
		cube->back[0] = cube->top[8];
		cube->top[2] = frontTmp[2];
		cube->top[5] = frontTmp[5];
		cube->top[8] = frontTmp[8];
	} else {
		cube->front[2] = cube->top[2];
		cube->front[5] = cube->top[5];
		cube->front[8] = cube->top[8];
		cube->top[2] = cube->back[6];
		cube->top[5] = cube->back[3];
		cube->top[8] = cube->back[0];
		cube->back[6] = cube->bottom[2];
		cube->back[3] = cube->bottom[5];
		cube->back[0] = cube->bottom[8];
		cube->bottom[2] = frontTmp[2];
		cube->bottom[5] = frontTmp[5];
		cube->bottom[8] = frontTmp[8];
	}
	
	cube->right = turnFace(cube->right, clockwise);
}

void Cube::moveBack(const bool clockwise) {
	std::string topTmp = cube->top.substr(0, 3);
	
	if (clockwise) {
		cube->top[0] = cube->right[2];
		cube->top[1] = cube->right[5];
		cube->top[2] = cube->right[8];
		cube->right[2] = cube->bottom[8];
		cube->right[5] = cube->bottom[7];
		cube->right[8] = cube->bottom[6];
		cube->bottom[8] = cube->left[6];
		cube->bottom[7] = cube->left[3];
		cube->bottom[6] = cube->left[0];
		cube->left[6] = topTmp[0];
		cube->left[3] = topTmp[1];
		cube->left[0] = topTmp[2];
	} else {
		cube->top[0] = cube->left[6];
		cube->top[1] = cube->left[3];
		cube->top[2] = cube->left[0];
		cube->left[6] = cube->bottom[6];
		cube->left[3] = cube->bottom[7];
		cube->left[0] = cube->bottom[8];
		cube->bottom[6] = cube->right[8];
		cube->bottom[7] = cube->right[5];
		cube->bottom[8] = cube->right[2];
		cube->right[8] = topTmp[2];
		cube->right[5] = topTmp[1];
		cube->right[2] = topTmp[0];
	}
	
	cube->back = turnFace(cube->back, clockwise);
}

void Cube::moveBottom(const bool clockwise) {
	std::string frontTmp = cube->front.substr(6, 3);
	
	if (clockwise) {
		cube->front.replace(6, 3, cube->left.substr(6, 3));
		cube->left.replace(6, 3, cube->back.substr(6, 3));
		cube->back.replace(6, 3, cube->right.substr(6, 3));
		cube->right.replace(6, 3, frontTmp);
	} else {
		cube->front.replace(6, 3, cube->right.substr(6, 3));
		cube->right.replace(6, 3, cube->back.substr(6, 3));
		cube->back.replace(6, 3, cube->left.substr(6, 3));
		cube->left.replace(6, 3, frontTmp);
	}
	
	cube->bottom = turnFace(cube->bottom, clockwise);
}

std::string Cube::turnFace(const std::string &face, bool clockwise) const {
	std::string newFace;
	
	if (clockwise) {
		newFace = face[6];
		newFace += face[3];
		newFace += face[0];
		newFace += face[7];
		newFace += face[4];
		newFace += face[1];
		newFace += face[8];
		newFace += face[5];
		newFace += face[2];
	} else {
		newFace = face[2];
		newFace += face[5];
		newFace += face[8];
		newFace += face[1];
		newFace += face[4];
		newFace += face[7];
		newFace += face[0];
		newFace += face[3];
		newFace += face[6];
	}
	
	return newFace;
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

bool Cube::isSolved() const {
	bool solved = true;
	
	if (cube->top[0] != cube->top[4] ||
		cube->top[1] != cube->top[4] ||
		cube->top[2] != cube->top[4] ||
		cube->top[3] != cube->top[4] ||
		cube->top[5] != cube->top[4] ||
		cube->top[6] != cube->top[4] ||
		cube->top[7] != cube->top[4] ||
		cube->top[8] != cube->top[4]) {
		solved = false;
	} else if (cube->left[0] != cube->left[4] ||
		cube->left[1] != cube->left[4] ||
		cube->left[2] != cube->left[4] ||
		cube->left[3] != cube->left[4] ||
		cube->left[5] != cube->left[4] ||
		cube->left[6] != cube->left[4] ||
		cube->left[7] != cube->left[4] ||
		cube->left[8] != cube->left[4]) {
		solved = false;
	} else if (cube->front[0] != cube->front[4] ||
		cube->front[1] != cube->front[4] ||
		cube->front[2] != cube->front[4] ||
		cube->front[3] != cube->front[4] ||
		cube->front[5] != cube->front[4] ||
		cube->front[6] != cube->front[4] ||
		cube->front[7] != cube->front[4] ||
		cube->front[8] != cube->front[4]) {
		solved =false;
	} else if (cube->right[0] != cube->right[4] ||
		cube->right[1] != cube->right[4] ||
		cube->right[2] != cube->right[4] ||
		cube->right[3] != cube->right[4] ||
		cube->right[5] != cube->right[4] ||
		cube->right[6] != cube->right[4] ||
		cube->right[7] != cube->right[4] ||
		cube->right[8] != cube->right[4]) {
		solved =false;
	} else if (cube->back[0] != cube->back[4] ||
		cube->back[1] != cube->back[4] ||
		cube->back[2] != cube->back[4] ||
		cube->back[3] != cube->back[4] ||
		cube->back[5] != cube->back[4] ||
		cube->back[6] != cube->back[4] ||
		cube->back[7] != cube->back[4] ||
		cube->back[8] != cube->back[4]) {
		solved =false;
	} else if (cube->bottom[0] != cube->bottom[4] ||
		cube->bottom[1] != cube->bottom[4] ||
		cube->bottom[2] != cube->bottom[4] ||
		cube->bottom[3] != cube->bottom[4] ||
		cube->bottom[5] != cube->bottom[4] ||
		cube->bottom[6] != cube->bottom[4] ||
		cube->bottom[7] != cube->bottom[4] ||
		cube->bottom[8] != cube->bottom[4]) {
		solved =false;
	}
	
	return solved;
}
