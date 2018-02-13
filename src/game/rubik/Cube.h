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
};

#endif /* CUBE_H */

