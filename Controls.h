#ifndef GPIOButtonsH
#define GPIOButtonsH

#include "inc/tm4c123gh6pm.h"
#include "stdint.h" 

extern "C" void GPIOE_Handler(void); 
extern "C" void GPIOF_Handler(void); 

void Controls_Init( void (*firemove)(bool pressedRight, bool pressedLeft), 
										void (*firejump)(bool pressed), 
										void (*waterjump)(bool pressed),
										void (*watermove)(int8_t sign) );

void GPIOE_Handler(void); 
void GPIOF_Handler(void); 
										
void SlidePot_Update();

#endif
