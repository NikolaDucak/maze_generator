#include "../inc/MazeCell.h"

bool MazeCell::isConnected(Direction dir) const{
	return connections & connectionMask[dir];
}
void MazeCell::connect(Direction dir){
	connections |= connectionMask[dir];
}
void MazeCell::disconect(Direction dir){
	connections &= ~(connectionMask[dir]);
}
bool MazeCell::visited() const{
	return connections;
}
const unsigned char MazeCell::connectionMask[] = {
	(1 << 0), // left
	(1 << 1), // right
	(1 << 2), // up
	(2 << 3)  // down
};
