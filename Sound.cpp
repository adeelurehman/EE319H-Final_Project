// Sound.cpp
// Runs on any computer
// Sound assets based off the original Space Invaders 
// Import these constants into your SpaceInvaders.c for sounds!
// Jonathan Valvano
// 1/17/2020
#include <stdint.h>
#include "Sound.h"
#include "DAC.h"
#include "inc/tm4c123gh6pm.h"

extern "C" void SysTick_Handler(void);

void Sound_Init(void){
// write this
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_CURRENT_R = 0;
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x20000000;
	
	DAC_Init(); 
}

void Sound_Play(uint32_t period){
	if (period == 0) {
		NVIC_ST_CTRL_R = 0;
		return; 
	}
	NVIC_ST_RELOAD_R = period-1;
	NVIC_ST_CTRL_R = 7;
}

uint8_t i  = 0; //ranges from 0-63
uint8_t SinWave[64] = {32,35,38,41,44,46,49,51,
									     54,56,58,59,61,62,62,63,
							     		 63,63,62,62,61,59,58,56,
											 54,51,49,46,44,41,38,35,
									     32,28,25,22,19,17,14,12,
									     9,7,5,4,2,1,1,0,
									     0,0,1,1,2,4,5,7,
									     9,12,14,17,19,22,25,28};
void SysTick_Handler(void) {
	i++;
	i &= 0x3F;
	DAC_Out(SinWave[i]);
}
