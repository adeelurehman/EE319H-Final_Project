#include "Physics.h"
#include "Player.h"
#include "Gem.h"
#include "Sprites.h"
#include "Button.h"
#include "VerticalMovingPlat.h"

int gemCollision(Player* p)
{
	int progG = 0;
	for(int i = 0; i < 4; i++)
	{
		if (!levelOneG[i].testG(p->Xpos+p->Xvel, p->Ypos+p->Yvel, p->width, p->height))
		{
			if(p->type == levelOneG[i].type && levelOneG[i].collect == 0)
			{				
				levelOneG[i].collected();
				p->gemCount++;
				return i;
			}
		}
	}
	return -1;
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
