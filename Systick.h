#ifndef SystickH
#define SystickH

#include <stdint.h>

void SysTick_Init(void(*task)(void), uint32_t period);
void SysTick_Handler();
void SysTick_Pause();
void SysTick_Start(); 

#endif
