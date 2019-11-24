#ifndef __MAZEGEN__COORDS_H__
#define __MAZEGEN__COORDS_H__

struct Coords{
	int x, y;
	static const Coords directionOffset[];
};

Coords operator+ (const Coords& left, const Coords& right);

#endif
