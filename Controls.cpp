/* Game Controls:
PORT E:

Pin0: Fire Right
Pin1: Fire Left
Pin2: Fire Jump
Pin3: Water Jump

PORTD:
PD2: Water Move
 */

#include "Controls.h"
#include "inc/tm4c123gh6pm.h"
#include "stdint.h"

void (*Fire_Move)(bool pressedRight, bool pressedLeft);
void (*Fire_Jump)(bool pressed);
void (*Water_Jump)(bool pressed);

void Controls_Init( void (*Fire_Move)(bool pressedRight, bool pressedLeft), 
										void (*Fire_Jump)(bool pressed), 
										void (*Water_Jump)(bool pressed) ) {
	SYSCTL_RCGCGPIO_R |= 0x10;
	__nop();
	__nop(); 
	GPIO_PORTE_DIR_R = 0;
	GPIO_PORTE_DEN_R = 15;
	GPIO_PORTE_PUR_R = 15;
	NVIC_EN0_R |= 0x10; 
}

void GPIO_PortE_Handler(void) {
	uint8_t data = ~(GPIO_PORTE_DATA_R & 0x0F);
	(*Fire_Move)(data&0x01, data&0x02);
	(*Fire_Jump)(data&0x04);
	(*Water_Jump)(data&0x08); 
}
