#ifndef Spritesh
#define Spritesh

#include "Player.h"
#include "Barrier.h"
#include "Gem.h"

const Barrier levelOneB[3] = {Barrier(0,110,50,18,2), Barrier(51,110,50,18,0), Barrier(101,110,59,18,2)};
static Gem levelOneG[4] = {Gem(0,0,5,5,1), Gem(20,20,5,5,1), Gem(20,0,5,5,1), Gem(0,20,5,5,0)};

//returns pointer to fireboy
//parms: coords for inital position
Player* Fireboy_Init(int x, int y);

//returns pointer to watergirl
//parms: coords for inital position
Player* Watergirl_Init(int x, int y); 

//destroys player object (or just use delete)
void Player_Destroy(Player* temp);

#endif
