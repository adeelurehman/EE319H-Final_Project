// main.cpp
// Runs on LM4F120/TM4C123
// Jonathan Valvano and Daniel Valvano
// This is a starter project for the EE319K Lab 10 in C++

// Last Modified: 1/17/2020 
// http://www.spaceinvaders.de/
// sounds at http://www.classicgaming.cc/classics/spaceinvaders/sounds.php
// http://www.classicgaming.cc/classics/spaceinvaders/playguide.php
/* This example accompanies the books
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2017

   "Embedded Systems: Introduction to Arm Cortex M Microcontrollers",
   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2017

 Copyright 2018 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */
// ******* Possible Hardware I/O connections*******************
// Slide pot pin 1 connected to ground
// Slide pot pin 2 connected to PD2/AIN5
// Slide pot pin 3 connected to +3.3V 
// fire button connected to PE0
// special weapon fire button connected to PE1
// 8*R resistor DAC bit 0 on PB0 (least significant bit)
// 4*R resistor DAC bit 1 on PB1
// 2*R resistor DAC bit 2 on PB2
// 1*R resistor DAC bit 3 on PB3 (most significant bit)
// LED on PB4
// LED on PB5

// Backlight (pin 10) connected to +3.3 V
// MISO (pin 9) unconnected
// SCK (pin 8) connected to PA2 (SSI0Clk)
// MOSI (pin 7) connected to PA5 (SSI0Tx)
// TFT_CS (pin 6) connected to PA3 (SSI0Fss)
// CARD_CS (pin 5) unconnected
// Data/Command (pin 4) connected to PA6 (GPIO), high for data, low for command
// RESET (pin 3) connected to PA7 (GPIO)
// VCC (pin 2) connected to +3.3 V
// Gnd (pin 1) connected to ground

#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "ST7735.h"
#include "Random.h"
#include "PLL.h"
#include "SlidePot.h"
#include "Images.h"
#include "UART.h"
#include "Timer0.h"
#include "Timer1.h"
#include "Player.h"
#include "Sprites.h"
#include "Barrier.h"
#include "Physics.h"
#include "Systick.h" 
#include "Controls.h" 

extern "C" void DisableInterrupts(void);
extern "C" void EnableInterrupts(void);

#define MoveTest //Options: OGcode, FallTest, BarrierTest, drawlevel0

#ifdef MoveTest

Player* fireboy;
Player* watergirl;

void moveWater(int8_t sign) {
	watergirl->Xvel = sign * PLAYER_SPEED; 
}

void jumpWater(bool jump) {
	if (jump)
		watergirl->jump();
}

void jumpFire(bool jump) {
	if (jump)
		fireboy->jump(); 
}

void moveFire(bool right, bool left) {
	if (right&&left)
		fireboy->Xvel = 0;
	else if (right)
		fireboy->Xvel = PLAYER_SPEED;
	else if (left)
		fireboy->Xvel = PLAYER_SPEED*-1;
	else
		fireboy->Xvel = 0; 
}

void tickUpdate() {
	SlidePot_Update(); 
	fireboy->update(); 	
	watergirl->update();
}

int main(void) {
	PLL_Init(Bus80MHz);       // Bus clock is 80 MHz 
  Random_Init(1);
  Output_Init();
	ST7735_SetRotation(1); 
	fireboy = Fireboy_Init(7,115);
	watergirl = Watergirl_Init(21,115); 
	SysTick_Init(&tickUpdate, 0x3D08FF);
	SysTick_Start(); 
	Controls_Init(&moveFire,&jumpFire,&jumpWater,&moveWater); 
	EnableInterrupts();
	for (int i=0; i<33; i++) {
			levelOneB[i].drawMe(); 
	}
	
	while(true) {
		fireboy->drawMe();
		watergirl->drawMe();
		for (int i=0; i<4; i++) {
			levelOneG[i].drawMe(); 
		}
	}
}
#endif

#ifdef ControlsTest
void LEDInit() {
	SYSCTL_RCGCGPIO_R |= 0x20;
	__asm__ {
		NOP
		NOP
	}
	GPIO_PORTF_DIR_R |= 0x04;
	GPIO_PORTF_DEN_R |= 0x04;
}

int main(void) {
	PLL_Init(Bus80MHz);       // Bus clock is 80 MHz 
	Controls_Init(0,0,0); 
	LEDInit(); 
	EnableInterrupts(); 
	while(true) {
		int x = GPIO_PORTE_DATA_R;
		x = GPIO_PORTE_DATA_R; 
		int y = 3;
		y++; 
	}
}
#endif

#ifdef BarrierTest
int main() {
	//int x = 50;
	//int y = 50;
	//int w = 5;
	//int h = 5;
	//volatile int test = floor.test(x,y,w,h);
	//test = test;
	Player* Fireboy = Fireboy_Init(0,0);
	Fireboy->update();
}
#endif

#ifdef OGcode
SlidePot my(1500,0);

// Creating a struct for the Sprite.
typedef enum {dead,alive} status_t;
struct sprite{
  uint32_t x;      // x coordinate
  uint32_t y;      // y coordinate
  const unsigned short *image; // ptr->image
  status_t life;            // dead/alive
};          
typedef struct sprite sprite_t;

sprite_t bill={60,9,SmallEnemy20pointB,alive};

uint32_t time = 0;
volatile uint32_t flag;
void background(void){
  flag = 1; // semaphore
  if(bill.life == alive){
    bill.y++;
  }
  if(bill.y>155){
    bill.life = dead;
  }
}
void clock(void){
  time++;
}
int main(void){
  PLL_Init(Bus80MHz);       // Bus clock is 80 MHz 
  Random_Init(1);
  Output_Init();
  Timer0_Init(&background,1600000); // 50 Hz
  Timer1_Init(&clock,80000000); // 1 Hz
  EnableInterrupts();
  ST7735_DrawBitmap(52, 159, PlayerShip0, 18,8); // player ship middle bottom
  ST7735_DrawBitmap(53, 151, Bunker0, 18,5);
  ST7735_DrawBitmap(0, 9, SmallEnemy10pointA, 16,10);
  ST7735_DrawBitmap(20,9, SmallEnemy10pointB, 16,10);
  ST7735_DrawBitmap(40, 9, SmallEnemy20pointA, 16,10);
  ST7735_DrawBitmap(80, 9, SmallEnemy30pointA, 16,10);
  ST7735_DrawBitmap(100, 9, SmallEnemy30pointB, 16,10);
  while(bill.life == alive){
    while(flag==0){};
    flag = 0;
    ST7735_DrawBitmap(bill.x,bill.y,bill.image,16,10);
  }

  ST7735_FillScreen(0x0000);            // set screen to black
  ST7735_SetCursor(1, 1);
  ST7735_OutString((char*)"GAME OVER");
  ST7735_SetCursor(1, 2);
  ST7735_SetTextColor(ST7735_WHITE);
  ST7735_OutString((char*)"Nice try,");
  ST7735_SetCursor(1, 3);
  ST7735_OutString((char*)"Earthling!");
  ST7735_SetCursor(2, 4);
  ST7735_SetTextColor(ST7735_WHITE);
  while(1){
    while(flag==0){};
    flag = 0;
    ST7735_SetCursor(2, 4);
    ST7735_OutUDec(time);
  }

}
#endif
