#include "Player.h"
#include "ST7735.h"
#include "Physics.h"
#include "Sprites.h"
#include "Gem.h"
#include "EndDoor.h"

Player::Player(int type, const unsigned short* rightTxtr, const unsigned short* leftTxtr, const unsigned short* forwardTxtr, int width, int height, int x, int y) {
	this->type = type; 
	Xpos = x;
	Ypos = y;
	facingRightTexture = rightTxtr;
	facingLeftTexture = leftTxtr;
	facingForwardTexture = forwardTxtr;
	this->width = width;
	this->height = height; 
	gemCount = 0;
	
	prevX = -50;
	prevY = -50;
	
	playerstate = 0; 
}

void Player::update() {
	buttonCollision(this);
	//button collision        has its own function now
//	for(int i = 0; i < 2; i++)
//	{
//		if (!levelOneButton[i].testButton(Xpos+Xvel, Ypos+Yvel, width, height))
//		{
//			levelOneButton[i].pressed();
//		}else{
//			levelOneButton[i].released();
//		}
//		//todo Moving Platform update
//	}
	
	gemCollision(this);
	//gem collision     has its own function now
//	int progG = 0;
//	for(int i = 0; i < 4; i++)
//	{
//		if (!levelOneG[i].testG(Xpos+Xvel, Ypos+Yvel, width, height))
//		{
//			if(this->type == levelOneG[i].type)
//			{
//				levelOneG[i].collected();
//				progG = i;
//			}
//		}
//	}
	
	//barrier collision
	int fail = 0;
	int progB = 0;
	for(int i = 0; i < 33; i++)
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
	
	//VP collision
	int failVP = 0;
	if (!levelOneVP.testVP(Xpos+Xvel, Ypos+Yvel, width, height))
	{
		failVP = 1;
	}
	
	if(failVP == 1)
	{
		Ypos = levelOneVP.y-height;
		Yvel = 0;
		Xpos += Xvel;
	}
	else if(fail == 1)
	{
		Ypos = levelOneB[progB].y-height;
		Yvel = 0;
		Xpos += Xvel;
	//	if(fail == 1)
	//{
	//	if(this->Ypos+this->height >= levelOneB[progB].y)
	//	{
	//		Ypos = levelOneB[progB].y-height;
	//		Yvel = 0;
	//		Xpos += Xvel;
	//	}
	//	else
	//	{
	//		Xpos = levelOneB[progB].x-width;
	//		Xvel = 0;
	//		Ypos += Yvel;
	//		Yvel += Y_GRAVITY;
	//	}
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
	endDoorCollision(this);
	if(levelOneEndDoor[0].endFlag == 1 && levelOneEndDoor[1].endFlag == 1)
	{
		//todo victory
	}
}

void Player::drawMe() {
	
	if (prevY != Ypos) {
		playerstate = 1;
	}
	else {
		playerstate = 0;
	}
	
	if (prevX == Xpos && prevY==Ypos)
		return;
	
	this->eraseMe();
	prevX = Xpos;
	prevY = Ypos; 
	
	if (Xvel > 0) {
		ST7735_DrawBitmapNormal(this->Xpos, this->Ypos, this->facingRightTexture, width, height);
	}
	else if (Xvel == 0) {
		ST7735_DrawBitmapNormal(this->Xpos, this->Ypos, this->facingForwardTexture, width, height);
	}
	else if (Xvel < 0) {
		ST7735_DrawBitmapNormal(this->Xpos, this->Ypos, this->facingLeftTexture, width, height);
	}
}

void Player::eraseMe() {
	ST7735_FillRect(prevX, prevY, width, height, BACKGROUND_COLOR);
}

void Player::jump() {
	if (playerstate  == 0) {
		Yvel = JUMP_VELOCITY;
	}
}
