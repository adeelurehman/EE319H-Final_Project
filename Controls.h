#ifndef GPIOButtonsH
#define GPIOButtonsH

#include "inc/tm4c123gh6pm.h"

extern "C" void GPIOE_Handler(void); 

void Controls_Init( void (*Fire_Move)(bool pressedRight, bool pressedLeft), 
										void (*Fire_Jump)(bool pressed), 
										void (*Water_Jump)(bool pressed) );

void GPIOE_Handler(void); 

#endif
