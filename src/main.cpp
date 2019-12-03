#include <iostream>
#include "../inc/Maze.h"

void printMaze(const Maze& maze){
	std::cout << std::string(2*maze.getWidth(), '_') << '\n';
	for( int y = 0; y < maze.getHeight(); y++ ){
		for( int x = 0; x < maze.getWidth(); x++ ){
			if(maze.at(x,y).canGo(Left)) std::cout << ' ';
			else::std::cout << '|';

			if(maze.at(x,y).canGo(Down)) std::cout << ' ';
			else::std::cout << '_';
		}
		std::cout << "|\n";
	}
}

int main(){
	const static int w = 10;
	const static int h = 10;
	static Maze maze(w,h);

	printMaze(maze);
	std::cout << "modify at 0,0: conect right\n";
	maze.connect(0,0,Right);
	printMaze(maze);
	maze.disconnect(0,0,Right);
	printMaze(maze);
}
