#include "Gem.h"
#include "ST7735.h"
#include "Sprites.h"
#include "images.h"


Gem::Gem(int x, int y, int w, int h, int t) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->type = t;
	this->collect = 0;
	if(t == 0)
	{
		this->gemTexture = Water_Gem;
	}
	if(t == 1)
	{
		this->gemTexture = Fire_Gem;
	}
}

bool Gem::testG(int x, int y, int w, int h) const {
	return !(this->x < x+w && this->x+this->w > x &&
    this->y < y+h && this->y+this->h > y);
}

void Gem::drawMe() 
{
	if(this->collect == 0)
	{
		ST7735_DrawBitmap(this->x, this->y, this->gemTexture, w, h);
	}
}

void Gem::collected()
{
	if(collect == 0)
	{
		this->collect = 1;
	}
}
