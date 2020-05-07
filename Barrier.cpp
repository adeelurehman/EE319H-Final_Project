#include "ST7735.h"
#include "Barrier.h"

Barrier::Barrier(int x, int y, int w, int h, int t) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->type = t;
}

void Barrier::drawMe() const {//put ifs based on type to change color of barrier
	if(this->type == 2)
	{
		ST7735_FillRect(x, y, w, h, 0x6286);
	}
	if(this->type == 0)
	{
		ST7735_FillRect(x, y, w, h, 0x001F);
	}
	if(this->type == 1)
	{
		ST7735_FillRect(x, y, w, h, 0xF800);
	}
	if(this->type == 3)
	{
		ST7735_FillRect(x, y, w, h, 0x07E0);
	}
}

//this is rectangle 1, parm is rectangle 2
bool Barrier::test(int x, int y, int w, int h) const {
	return !(this->x <= x+w+1 && this->x+this->w+1 >= x &&
    this->y <= y+h+1 && this->y+this->h+1 >= y);
}
