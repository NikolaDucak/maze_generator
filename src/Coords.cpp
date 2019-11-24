#include "../inc/Coords.h"

const Coords Coords::directionOffset[] = {
	Coords{-1, 0 }, // left
	Coords{ 1, 0 }, // right
	Coords{ 0,-1 }, // up
	Coords{ 0, 1 }  // down
};

Coords operator+(const Coords& left, const Coords& right){
	return Coords{left.x + right.x, left.y + right.y };
}

