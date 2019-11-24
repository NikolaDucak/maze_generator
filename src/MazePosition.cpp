#include "../inc/MazePosition.h"

//this has to be includes since MazePosition class uses Maze class as predefined in .h
//so .cpp need to complete the type
#include "../inc/Maze.h"


bool MazePosition::canGo(Direction dir){
	return maze.cellAt(currentCoords).isConnected(dir);
}
void MazePosition::go(Direction dir){
	if(canGo(dir))
		currentCoords = currentCoords + Coords::directionOffset[dir];
}

