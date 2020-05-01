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
	GPIO_PORTE_AMSEL_R &= 0xF0;
	GPIO_PORTE_AFSEL_R &= 0xF0; 
	GPIO_PORTE_PCTL_R &= ~0xFFFF;
	GPIO_PORTE_DIR_R = 0;
	GPIO_PORTE_DEN_R = 15;
	GPIO_PORTE_PUR_R = 15;
	GPIO_PORTE_IS_R &= ~0x0F;
	GPIO_PORTE_IBE_R |= 0x0F;
	GPIO_PORTE_IM_R |= 0x0F;
	NVIC_EN0_R |= 0x10; 
}

int count;
void GPIOE_Handler(void) {
	GPIO_PORTE_ICR_R = 0x0F; 
	GPIO_PORTF_DATA_R = 0x04;
	uint8_t data = ~(GPIO_PORTE_DATA_R & 0x0F);
	count++; 
	//(*Fire_Move)(data&0x01, data&0x02);
	//(*Fire_Jump)(data&0x04);
	//(*Water_Jump)(data&0x08); 
}
