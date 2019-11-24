#ifndef __MAZEGEN__MAZEPOSITION_H__
#define __MAZEGEN__MAZEPOSITION_H__ 

#include "Direction.h"
#include "Coords.h"

class Maze;
struct MazePosition{
	const Maze& maze;
	Coords currentCoords;
	MazePosition(Coords coords, const Maze& maze): maze(maze), currentCoords(coords){};
	bool canGo(Direction dir);
	void go(Direction dir);
};

#endif
