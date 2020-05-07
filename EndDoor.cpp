#include "EndDoor.h"
#include "ST7735.h"


EndDoor::EndDoor(int x, int y, int w, int h, int t) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->type = t;
	this->gemsRequired = 4;
	this->endFlag = 0;
}

void EndDoor::drawMe() const {
	if(this->type == 0)
	{
		ST7735_FillRect(x, y, w, 1, 0xFF08);
		ST7735_FillRect(x, y+1, 1, h-1, 0xFF08);
		ST7735_FillRect(x+w, y+1, 1, h-1, 0xFF08);
		ST7735_FillRect(x+1, y+1, x-1, h-1, 0xFA08);
	}
	if(this->type == 1)
	{
		ST7735_FillRect(x, y, w, 1, 0x001F);
		ST7735_FillRect(x, y+1, 1, h-1, 0x001F);
		ST7735_FillRect(x+w, y+1, 1, h-1, 0x001F);
		ST7735_FillRect(x+1, y+1, x-1, h-1, 0x001C);
	}
}

bool EndDoor::testEndDoor(int x, int y, int w, int h) const {
	return !(this->x <= x+w+1 && this->x+this->w+1 >= x &&
    this->y <= y+h+1 && this->y+this->h+1 >= y);
}
