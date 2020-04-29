//these functions have not yet been implemented in Grid.cpp

#ifndef Gridh
#define Gridh

#include <stdint.h>

class Grid {
public:
	//stores which pixels are occupied, and which are not
	//player location is not stored in grid
	uint8_t data[128][160];
	
	//initializes empty grid
	Grid();

	//determines if a rectangular sprite may move to the specified area
	uint8_t testRect(int x, int y, int w, int h);

	//force add rectangle to grid
	void addRect(int x, int y, int w, int h);

	//forcefully move rectangle from old to new position
	void moveRect(int oldX, int oldY, int newX, int newY, int w, int h);
};

#endif
