#ifndef Spritesh
#define Spritesh

#include "Player.h"
#include "Barrier.h"
#include "Gem.h"
#include "Button.h"
#include "VerticalMovingPlat.h"
#include "EndDoor.h"

const Barrier levelOneB[33] = {Barrier(0,0,160,3,2), Barrier(3,26,117,3,2), Barrier(134,26,12,3,2), Barrier(123,39,10,3,1), 
Barrier(147,39,10,3,0), Barrier(135,52,10,10,2), Barrier(116,62,41,3,2), Barrier(101,64,15,1,2), Barrier(93,62,8,3,2),
Barrier(63,64,30,1,2), Barrier(63,52,30,1,2), Barrier(19,62,44,3,2), Barrier(3,85,61,3,2), Barrier(64,85,15,15,2),
Barrier(79,97,19,3,2), Barrier(98,99,15,1,2), Barrier(113,97,29,3,2), Barrier(3,107,30,3,2), Barrier(152,105,5,10,2),
Barrier(142,115,15,10,2), Barrier(0,125,65,3,2), Barrier(65,127,16,1,2), Barrier(81,125,5,3,2), Barrier(86,127,15,1,2),
Barrier(101,125,59,3,2), Barrier(65,125,16,2,1), Barrier(86,125,15,2,0), Barrier(98,97,15,2,3), Barrier(101,62,15,2,3),
Barrier(63,50,30,2,0), Barrier(63,62,30,2,1), Barrier(0,3,3,122,2), Barrier(157,3,3,122,2)}; //DONE

extern Gem levelOneG[10];

extern Button levelOneButton[2];
extern VertPlat levelOneVP;
extern EndDoor levelOneEndDoor[2];

//returns pointer to fireboy
//parms: coords for inital position
Player* Fireboy_Init(int x, int y);

//returns pointer to watergirl
//parms: coords for inital position
Player* Watergirl_Init(int x, int y); 

//destroys player object (or just use delete)
void Player_Destroy(Player* temp);

#endif
