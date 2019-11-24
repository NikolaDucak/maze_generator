#ifndef __MAZEGEN__MAZE_H__
#define __MAZEGEN__MAZE_H__

#include "MazeCell.h"
#include "Coords.h"
#include "Direction.h"
#include "MazePosition.h"

class Maze{
	friend MazePosition;
	unsigned int width,height;
	MazeCell* cells;

public:
	Maze(unsigned int width, unsigned int height);
	//const MazeCell& at(unsigned int x, unsigned int y) const;
	MazePosition at(unsigned int x, unsigned int y) const;
private:
	bool succsesfullyConnectedToNeighbour(Coords& cellCoords);
	void connect(Coords& from, Coords& to, Direction dir);
	bool areCoordsValid(const Coords& coords) const;
	MazeCell& cellAt(const Coords& coords) const;
};

#endif
