#ifndef Physicsh
#define Physicsh

#include "Player.h"
#define X_GRAVITY 0
#define Y_GRAVITY 1
#define JUMP_VELOCITY -5
#define BACKGROUND_COLOR 0x0000
#define PLAYER_SPEED 2


void gemCollision(Player* p);
void buttonCollision(Player* p);
void endDoorCollision(Player* p);

#endif
