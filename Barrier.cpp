#include "ST7735.h"
#include "Barrier.h"

Barrier::Barrier(int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void Barrier::drawMe() const {
	ST7735_FillRect(x, y, w, h, 0xA01F);
}

//this is rectangle 1, parm is rectangle 2
bool Barrier::test(int x, int y, int w, int h) const {
	return !(this->x < x+w && this->x+this->w > x &&
    this->y > y+h && this->y+this->h < y);
}