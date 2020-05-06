#include "EndDoor.h"
#include "ST7735.h"

EndDoor::EndDoor(int x, int y, int w, int h, int t) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->type = t;
	this->gemsRequired = 4;
}

void EndDoor::drawMe() const {
	ST7735_FillRect(x, y, w, h, 0xA01F);
}

bool EndDoor::test(int x, int y, int w, int h) const {
	return !(this->x <= x+w+1 && this->x+this->w+1 >= x &&
    this->y <= y+h+1 && this->y+this->h+1 >= y);
}
