#include "Sprite_Init.h"
#include "Player.h"
#include "images.h"

Player* Fireboy_Init(int x, int y) {
	return new Player(1, SmallEnemy20pointB, SmallEnemy20pointB, SmallEnemy20pointB, 16, 10, x, y);
}

Player* Watergirl_Init(int x, int y) {
	return new Player(0, Bunker0, Bunker0, Bunker0, 18, 5, x, y);
}

void Player_Destroy(Player* temp) {
	delete temp; 
}
