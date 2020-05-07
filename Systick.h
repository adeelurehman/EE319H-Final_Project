#ifdef SystickH
#define SystickH

#include <stdint.h>

//DO NOT USE SYSTICKH

void SysTick_Init(void(*task)(void), uint32_t period);

void SysTick_Pause();
void SysTick_Start(); 

#endif
