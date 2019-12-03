#ifndef __MAZEGEN__MAZECELL_H__
#define __MAZEGEN__MAZECELL_H__

#include "Direction.h"

struct MazeCell{
	static const unsigned char connectionMask[];
	unsigned char connections = 0;

	bool isConnected(Direction dir) const;
	void connect(Direction dir);
	void disconect(Direction dir);
	bool visited() const;
};

#endif
