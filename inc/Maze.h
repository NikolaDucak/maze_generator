#ifndef __MAZEGEN__MAZE_H__
#define __MAZEGEN__MAZE_H__

#include "MazeCell.h"
#include "Coords.h"
#include "Direction.h"
#include "MazePosition.h"

class Maze{
	friend MazePosition;
	int width,height;
	MazeCell* cells;

public:
	Maze(int width, int height);
	Maze(const Maze& org);
	Maze& operator = (const Maze& other);

	int getWidth() const { return width; }	
	int getHeight() const { return height; }
	MazePosition at(int x, int y) const;
	void connect(int x,int y, Direction dir);
	void disconnect(int x, int y, Direction dir);

	~Maze();

private:
	bool connectToNeighbour(Coords& cellCoords);
	bool areCoordsValid(const Coords& coords) const;
	MazeCell& cellAt(const Coords& coords) const;
};

#endif
