#include "Physics.h"
#include "Player.h"
#include "Gem.h"
#include "Sprites.h"
#include "Button.h"
#include "VerticalMovingPlat.h"
#include "ST7735.h"
#include "Timer0.h"
#include "Timer1.h"
#include "strings.h"
#include "inc/tm4c123gh6pm.h"
#include "Sound.h" 

extern "C" void Reset_Handler(void); 

int score = 0;
int gameRunning = 1; 

void gemCollision(Player* p)
{
	int progG = 0;
	for(int i = 0; i < 10; i++)
	{
		if (!levelOneG[i].testG(p->Xpos+p->Xvel, p->Ypos+p->Yvel, p->width, p->height))
		{
			if(p->type == levelOneG[i].type && levelOneG[i].collect == 0)
			{				
				levelOneG[i].collected();
				//levelOneG[i].collect = 1; 
				p->gemCount++;
				score+=100;
				return;
			}
		}
	}
}

void buttonCollision(Player* p)
{
	for(int i = 0; i < 2; i++)
	{
		if (!levelOneButton[i].testButton(p->Xpos+p->Xvel, p->Ypos+p->Yvel, p->width, p->height))
		{
			levelOneButton[i].pressed();
		}else{
			levelOneButton[i].released();
		}
		levelOneVP.updateVP();
	}
}	

void endDoorCollision(Player* p)
{
	
	for(int i = 0; i < 2; i++)
	{
		if (!levelOneEndDoor[i].testEndDoor(p->Xpos+p->Xvel, p->Ypos+p->Yvel, p->width, p->height))
		{
			if(p->type == levelOneEndDoor[i].type && levelOneEndDoor[i].gemsRequired == p->gemCount)
			{				
				//erase door center
				ST7735_FillRect(levelOneEndDoor[i].x+1,levelOneEndDoor[i].y+1, levelOneEndDoor[i].w-2, levelOneEndDoor[i].h-1, BACKGROUND_COLOR);
				
				levelOneEndDoor[i].endFlag = 1;
				return;
			}else{
				levelOneEndDoor[i].endFlag = 0;
			}
		}else{
		levelOneEndDoor[i].endFlag = 0;
		}
	}
}

void dead() {
	Timer0_Pause(); 
	Timer1_STOP(); 
	Sound_Play(0); 
	DrawDead(); 
	for (int i=0; i<20000000; i++);
	gameRunning = 0; 
}

void win() {
	Timer0_Pause();
	Timer1_STOP();
	Sound_Play(0); 
	DrawWin();
	while(true); 
}
