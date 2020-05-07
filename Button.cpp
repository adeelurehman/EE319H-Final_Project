#include "Button.h"
#include "Physics.h"
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
	ST7735_FillRect(x, y, w, h, 0xFFE0);
	//ST7735_DrawBitmap(this->x, this->y, this->buttonTexture, w, h);
}

void Button::pressed()
{
	if(this->press == 0)
	{
		this->press = 1;
		ST7735_FillRect(x, y, w, h, BACKGROUND_COLOR);
	}
}
void Button::released()
{
	if(this->press == 1)
	{
		this->press = 0;
		ST7735_FillRect(x, y, w, h, 0xFFE0);
	}
}
