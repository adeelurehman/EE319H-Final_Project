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
void (*Water_Move)(uint8_t sign); 

void Controls_Init( void (*firemove)(bool pressedRight, bool pressedLeft), 
										void (*firejump)(bool pressed), 
										void (*waterjump)(bool pressed),
										void (*watermove)(uint8_t sign) ) {
										
											//portE GPIO init
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
										
											//ADC on PortD Init
	SYSCTL_RCGCADC_R |= 0x01; //enable ADC0
	SYSCTL_RCGCGPIO_R |= 1<<3; //enable Port D
	
	__nop();
	__nop(); //wait for clock
	
	GPIO_PORTD_DIR_R |= 1<<2; 
	GPIO_PORTD_AFSEL_R |= 1<<2;
	GPIO_PORTD_DEN_R &= ~(1<<2); 
	GPIO_PORTD_AMSEL_R |= 1<<2; 
	
	ADC0_PC_R &= ~(0x0F);
	ADC0_PC_R |= 0x01; 
	ADC0_SSPRI_R = 0x0123; 
	ADC0_ACTSS_R &= ~0x0008; 
	ADC0_EMUX_R &= ~0xF000;
	ADC0_SSMUX3_R &= ~0x000F;
	ADC0_SSMUX3_R += 5;
	ADC0_SSCTL3_R = 0x0006;
	ADC0_IM_R &= ~0x0008;
	ADC0_ACTSS_R |= 0x0008;
											
											//Function Assignment
	Fire_Move = firemove; 
	Fire_Jump = firejump;
	Water_Jump = waterjump; 
	Water_Move = watermove; 
}

void GPIOE_Handler(void) {
	GPIO_PORTE_ICR_R = 0x0F; 
	uint8_t data = ~(GPIO_PORTE_DATA_R & 0x0F);
	(*Fire_Move)(data&0x01, data&0x02);
	(*Fire_Jump)(data&0x04);
	(*Water_Jump)(data&0x08); 
}

void SlidePot_Update() {
	uint32_t result; 
	ADC0_PSSI_R = 0x0008;
	while((ADC0_RIS_R&0x08)==0){};
	result = ADC0_SSFIFO3_R&0xFFF;
	ADC0_ISC_R = 0x0008;
	result /= 1366;
	result -= 1;
	Water_Move(result); 
}
