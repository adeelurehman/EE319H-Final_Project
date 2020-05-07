#include "Music.h"
#include "Sound.h"

const int themeSong[32] = {2255, 1896, 1505, 1896, 2389, 1896, 1594, 1896, 
															2389, 2009, 1505, 1896, 2389, 1896, 1594, 1896, 
															2255, 1896, 1505, 1896, 2389, 1896, 1594, 1896, 
															2389, 1896, 1420, 1896, 2389, 1896, 1420, 1896};
int songIndex;
int tickCounter; 
	
void Music_Init() {
	songIndex = 0; 
	tickCounter = 0; 
	Sound_Init(); 
}

void Music_Update() {
		
	if (tickCounter==0) {
		Sound_Play(themeSong[songIndex]);
		songIndex++;
		songIndex %= 32; 
	}
	tickCounter++;
	tickCounter %= SOUND_TEMPO;
}
