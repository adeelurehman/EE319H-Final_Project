#include "Sprites.h"
#include "Player.h"
#include "images.h"
#include "Physics.h" 

Gem levelOneG[10] = {Gem(63,42,9,7,0), Gem(73,42,9,7,0), Gem(83,42,9,7,0), Gem(104,44,9,7,1), Gem(101,82,9,7,1),
Gem(63,74,9,7,0), Gem(73,74,9,7,0), Gem(83,74,9,7,0), Gem(69,117,9,7,1), Gem(89,117,9,7,0)};
Button levelOneButton[2] = {Button(36,60,8,2,1), Button(24,83,8,2,1)}; //done
VertPlat levelOneVP = VertPlat(4,62,15,3); //done
EndDoor levelOneEndDoor[2] = {EndDoor(9,13,9,13,1), EndDoor(29,13,9,13,0)}; //done

Player* Fireboy_Init(int x, int y) {
	return new Player(1, Fire_Right, Fire_left, Fire_Middle, PLAYER_WIDTH, PLAYER_HEIGHT, x, y);
}

Player* Watergirl_Init(int x, int y) {
	return new Player(0, Water_Right, Water_Left, Water_Middle, PLAYER_WIDTH, PLAYER_HEIGHT, x, y);
}

void Player_Destroy(Player* temp) {
	delete temp; 
}
