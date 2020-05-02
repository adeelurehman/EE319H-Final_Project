#include "ST7735.h"
#include "Barrier.h"

Barrier::Barrier(int x, int y, int w, int h, int t) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->type = t;
}

void Barrier::drawMe() const {
	ST7735_FillRect(x, y, w, h, 0xA01F);
}

//this is rectangle 1, parm is rectangle 2
bool Barrier::test(int x, int y, int w, int h) const {
	return !(this->x <= x+w+1 && this->x+this->w+1 >= x &&
    this->y <= y+h+1 && this->y+this->h+1 >= y);
}
