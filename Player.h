#ifndef PlayerClass
#define PlayerClass

#include "Drawable.h"

class Player: public Drawable {
public:
	const unsigned short* facingRightTexture;
	const unsigned short* facingLeftTexture;
	const unsigned short* facingForwardTexture;
	int width;
	int height;

	int Xpos;
	int Ypos;
	int Xvel;
	int Yvel;
	int gemCount;

	int prevX;
	int prevY;
	
	int type; //0 for water, 1 for fire
	
	Player(int type, const unsigned short* rightTxtr, const unsigned short* leftTxtr, const unsigned short* forwardTxtr, int width, int height, int x, int y);
	
	void update(); 
	virtual void drawMe(); 
	virtual void eraseMe(); 
	void jump();
};

#endif
