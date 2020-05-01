#include "Button.h"

#include "ST7735.h"
#include "Sprites.h"

Button::Button(int x, int y, int w, int h, int t) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->type = t;
	this->press = 0;
}

bool Button::testButton(int x, int y, int w, int h) const {
	return !(this->x < x+w && this->x+this->w > x &&
    this->y < y+h && this->y+this->h > y);
}

void Button::drawMe() 
{
	ST7735_DrawBitmap(this->x, this->y, this->buttonTexture, w, h);
}

void Button::pressed()
{
	this->press = 1;
}
void Button::released()
{
	this->press = 0;
}
