#include "Player.h"
#include "ST7735.h"
#include "Physics.h"
#include "Sprites.h"
#include "Gem.h"

Player::Player(int type, const unsigned short* rightTxtr, const unsigned short* leftTxtr, const unsigned short* forwardTxtr, int width, int height, int x, int y) {
	this->type = type; 
	Xpos = x;
	Ypos = y;
	facingRightTexture = rightTxtr;
	facingLeftTexture = leftTxtr;
	facingForwardTexture = forwardTxtr;
	this->width = width;
	this->height = height; 
}

void Player::update() {
	//button collision
	for(int i = 0; i < 2; i++)
	{
		if (!levelOneButton[i].testButton(Xpos+Xvel, Ypos+Yvel, width, height))
		{
			levelOneButton[i].pressed();
		}else{
			levelOneButton[i].released();
		}
		//todo Moving Platform update
	}
	
	
	//gem collision
	int progG = 0;
	for(int i = 0; i < 4; i++)
	{
		if (!levelOneG[i].testG(Xpos+Xvel, Ypos+Yvel, width, height))
		{
			if(this->type == levelOneG[i].type)
			{
				levelOneG[i].collected();
				progG = i;
			}
		}
	}
	
	//barrier collision
	int fail = 0;
	int progB = 0;
	for(int i = 0; i < 3; i++)
	{
		if (!levelOneB[i].test(Xpos+Xvel, Ypos+Yvel, width, height))
		{
			fail = 1;
			progB = i;
		}
	}
	if((levelOneB[progB].type == 0 && this->type != 0)||(levelOneB[progB].type == 1 && this->type != 1)||(levelOneB[progB].type == 3))
	{
		int dead = 1; //todo dead function
	}
	if(fail == 1)
	{
		Ypos = levelOneB[progB].y;
		Yvel = 0;
	}
	else{
		Xpos += Xvel;
		Ypos += Yvel;
		Yvel += Y_GRAVITY;
		Xvel += X_GRAVITY; 
	}
		
//		if (floor.test(Xpos+Xvel, Ypos+Yvel, width, height) ) {
//		Xpos += Xvel;
//		Ypos += Yvel;
//		Yvel += Y_GRAVITY;
//		Xvel += X_GRAVITY; 
//	}
}

void Player::drawMe() {
	if (Xvel > 0) {
		ST7735_DrawBitmap(this->Xpos, this->Ypos, this->facingRightTexture, width, height);
	}
	else if (Xvel == 0) {
		ST7735_DrawBitmap(this->Xpos, this->Ypos, this->facingForwardTexture, width, height);
	}
	else if (Xvel < 0) {
		ST7735_DrawBitmap(this->Xpos, this->Ypos, this->facingLeftTexture, width, height);
	}
}

void Player::jump() {
	if (Yvel==0) {
		Yvel = JUMP_VELOCITY;
	}
}
