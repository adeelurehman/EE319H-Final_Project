#include "Sprites.h"
#include "Player.h"
#include "images.h"
#include "Physics.h" 

Player* Fireboy_Init(int x, int y) {
	return new Player(1, Fire_left, Fire_Middle, Fire_Right, PLAYER_WIDTH, PLAYER_HEIGHT, x, y);
}

Player* Watergirl_Init(int x, int y) {
	return new Player(0, Water_Left, Water_Middle, Water_Right, PLAYER_WIDTH, PLAYER_HEIGHT, x, y);
}

void Player_Destroy(Player* temp) {
	delete temp; 
}
