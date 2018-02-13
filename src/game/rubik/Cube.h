#ifndef CUBE_H
#define CUBE_H

#include <string>
#include "CubeRep.h"

class Cube {
public:
	Cube();
	Cube(const Cube& orig);
	virtual ~Cube();
	bool move(const char move);
	std::string move(std::string moves);
	CubeRep *getCube() const;
	bool isSolved() const;
	
private:
	CubeRep *cube;
	void moveTop(const bool clockwise);
	void moveBottom(const bool clockwise);
	void moveLeft(const bool clockwise);
	void moveFront(const bool clockwise);
	void moveRight(const bool clockwise);
	void moveBack(const bool clockwise);
	std::string turnFace(const std::string &face, bool clockwise) const;
};

#endif /* CUBE_H */

