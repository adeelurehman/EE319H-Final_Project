#include "Player.h"
#include "ST7735.h"
#include "Physics.h"
#include "Sprites.h"

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
	if (floor.test(Xpos+Xvel, Ypos+Yvel, width, height) ) {
		Xpos += Xvel;
		Ypos += Yvel;
		Yvel += Y_GRAVITY;
		Xvel += X_GRAVITY; 
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
}

void Player::jump() {
	if (Yvel==0) {
		Yvel = JUMP_VELOCITY;
	}
}
