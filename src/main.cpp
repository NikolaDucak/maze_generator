#include <iostream>
#include "../inc/Maze.h"

int main(){
	const static int w = 30;
	const static int h = 70;
	const static Maze maze(w,h);

	//printing maze 
	std::cout << std::string(2*w, '_') << '\n';
	for(unsigned int y = 0; y < h; y++){
		for(unsigned int x = 0; x < w; x++){
			if(maze.at(x,y).canGo(Left)) std::cout << ' ';
			else::std::cout << '|';

			if(maze.at(x,y).canGo(Down)) std::cout << ' ';
			else::std::cout << '_';
		}
		std::cout << "|\n";
	}
}
