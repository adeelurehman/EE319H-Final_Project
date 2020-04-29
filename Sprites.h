#ifndef Spritesh
#define Spritesh

#include "Player.h"
#include "Barrier.h"

const Barrier floor = Barrier(0,110,160,18);

//returns pointer to fireboy
//parms: coords for inital position
Player* Fireboy_Init(int x, int y);

//returns pointer to watergirl
//parms: coords for inital position
Player* Watergirl_Init(int x, int y); 

//destroys player object (or just use delete)
void Player_Destroy(Player* temp);

void Floor_Init(int x, int y, int w, int h);
#endif
