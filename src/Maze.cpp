#include "../inc/Maze.h"

#include <stack>
#include <random>

void Maze::connect(Coords& from, Coords& to, Direction dir){
	cellAt(from).connect(dir);
	cellAt(to).connect(!dir);
}
bool Maze::areCoordsValid(const Coords& coords) const {
	return coords.x >= 0          && coords.y >= 0 &&
		   coords.x <  (int)width && coords.y <  (int)height;
}
MazeCell& Maze::cellAt(const Coords& coords) const {
	return cells[coords.x + coords.y*width];
}
Maze::Maze(unsigned int width, unsigned int height) : width(width), height(height) {
	cells = new MazeCell[width*height];
	Coords currentCellCoords{0,0};
	std::stack<Coords> visitedCellsStack;
	visitedCellsStack.push(currentCellCoords);

	while(true){
		if(succsesfullyConnectedToNeighbour(currentCellCoords)){
			visitedCellsStack.push(currentCellCoords);
		}else{
			currentCellCoords = visitedCellsStack.top();
			visitedCellsStack.pop();
			if(visitedCellsStack.empty()) break;
		}
	}
}
bool Maze::succsesfullyConnectedToNeighbour(Coords& cellCoords){
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<std::mt19937::result_type> random(1,4);
	Direction random_direction = Direction(random(eng));

	for(int i = 0; i < 4; i++){
		auto next_rand_direction = Direction( (random_direction + i)%4 );
		Coords neighbour_coords = Coords::directionOffset[next_rand_direction] + cellCoords;

		if( areCoordsValid(neighbour_coords) && !cellAt(neighbour_coords).visited() ){
			connect(cellCoords, neighbour_coords, next_rand_direction);
			cellCoords = neighbour_coords;
			return true;
		}
	}

	return false;
}
MazePosition Maze::at( unsigned int x, unsigned int y) const{
	return MazePosition(Coords{(int)x, (int)y}, *this); 
}

