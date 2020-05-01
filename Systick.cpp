#include "Systick.h"
#include "stdint.h"
#include "inc/tm4c123gh6pm.h"

void (*PeriodicTask)(void);

void SysTick_Init(void(*task)(void), uint32_t period) {
	PeriodicTask = task; 
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_CURRENT_R = 0;
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x20000000;
	NVIC_ST_RELOAD_R = period;
}

void SysTick_Handler() {
	(*PeriodicTask)(); 
}

void SysTick_Pause() {
	NVIC_ST_CTRL_R = 0; 
}

void SysTick_Start() {
	NVIC_ST_CTRL_R = 7;
}
