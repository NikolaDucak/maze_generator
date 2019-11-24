#ifndef __MAZEGEN__DIRECTION_H__
#define __MAZEGEN__DIRECTION_H__

enum Direction{ Left, Right, Up, Down };
Direction operator!(const Direction& dir);

#endif
