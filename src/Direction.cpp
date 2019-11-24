#include "../inc/Direction.h"

Direction operator! (const Direction& dir){
	return Direction( (dir==Left || dir==Up) ? dir+1 : dir-1 );
}

