#include "../inc/Maze.h"

#include <stack>
#include <random>

Maze::Maze(int width, int height) : width(width), height(height) {
	cells = new MazeCell[width*height];
	Coords currentCellCoords{0,0};
	std::stack<Coords> visitedCellsStack;
	visitedCellsStack.push(currentCellCoords);

	while(true){
		if(connectToNeighbour(currentCellCoords)){
			visitedCellsStack.push(currentCellCoords);
		}else{
			currentCellCoords = visitedCellsStack.top();
			visitedCellsStack.pop();
			if(visitedCellsStack.empty()) break;
		}
	}
}

bool Maze::connectToNeighbour(Coords& cellCoords){
	static std::random_device rd;
	static std::mt19937 eng(rd());
	static std::uniform_int_distribution<std::mt19937::result_type> random(1,4);
	Direction random_direction = Direction(random(eng));

	for(int i = 0; i < 4; i++){
		auto next_rand_direction = Direction( (random_direction + i)%4 );
		auto neighbour_coords = Coords::directionOffset[next_rand_direction] + cellCoords;

		if( areCoordsValid(neighbour_coords) && !cellAt(neighbour_coords).visited() ){
			cellAt(cellCoords).connect( next_rand_direction );
			cellAt(neighbour_coords).connect( !next_rand_direction );	
			cellCoords = neighbour_coords;
			return true;
		}
	}
	return false;
}

bool Maze::areCoordsValid(const Coords& coords) const {
	return coords.x >= 0    && coords.y >= 0 &&
		   coords.x < width && coords.y < height;
}

MazeCell& Maze::cellAt(const Coords& coords) const {
	return cells[coords.x + coords.y*width];
}

MazePosition Maze::at(int  x, int y) const{
	return MazePosition(Coords{(int)x, (int)y}, *this); 
}

void Maze::connect(int x, int y, Direction dir){
	Coords c{x,y};
	Coords next = (Coords{x,y} + Coords::directionOffset[dir]);
	if(areCoordsValid(c) && areCoordsValid(next)){
		cellAt(c).connect(dir);
		cellAt(next).connect(!dir);
	}
}

void Maze::disconnect(int x, int y, Direction dir){
	Coords c{x,y};
	Coords next = (Coords{x,y} + Coords::directionOffset[dir]);
	if(areCoordsValid(c) && areCoordsValid(next)){
		cellAt(c).disconect(dir);
		cellAt(next).disconect(!dir);	
	}
}

Maze::Maze(const Maze& org) : width(org.width), height(org.height){
	cells = new MazeCell[width*height];
	for(int i = 0; i < width*height; i++){
		cells[i] = org.cells[i];
	}
}

Maze& Maze::operator = (const Maze& other){
	width = other.width;
	height = other.height;
	cells = new MazeCell[width*height];
	for(int i = 0; i < width*height; i++)
		cells[i] = other.cells[i];	
	return *this;
}

Maze::~Maze(){
	delete[] cells;
}
