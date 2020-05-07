#ifndef Physicsh
#define Physicsh

#include "Player.h"
#define X_GRAVITY 0
#define Y_GRAVITY 1
#define JUMP_VELOCITY -4
#define BACKGROUND_COLOR 0x0000
#define PLAYER_SPEED 3

#define PLAYER_WIDTH 5
#define PLAYER_HEIGHT 10

extern int score; 
extern int gameRunning; 

void gemCollision(Player* p);
void buttonCollision(Player* p);
void endDoorCollision(Player* p);

void dead();

#endif
