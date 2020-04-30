#include "Player.h"
#include "ST7735.h"
#include "Physics.h"
#include "Sprites.h"
#include "queue"

Player::Player(int type, const unsigned short* rightTxtr, const unsigned short* leftTxtr, const unsigned short* forwardTxtr, int width, int height, int x, int y) {
	this->type = type; 
	Xpos = x;
	Ypos = y;
	facingRightTexture = rightTxtr;
	facingLeftTexture = leftTxtr;
	facingForwardTexture = forwardTxtr;
	this->width = width;
	this->height = height; 
	
	prevX = -1;
	prevY = -1;
}

void Player::update(std::queue<Drawable*>* toDraw) {
	if (Purplefloor.test(Xpos+Xvel, Ypos+Yvel, width, height) ) {
		Xpos += Xvel;
		Ypos += Yvel;
		Yvel += Y_GRAVITY;
		Xvel += X_GRAVITY; 
		
		if (prevX != Xpos || prevY != Ypos) {
			toDraw->push(this); 
		}
	}
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
	
	prevX = Xpos;
	prevY = Ypos; 
}

void Player::jump() {
	if (Yvel==0) {
		Yvel = JUMP_VELOCITY;
	}
}
