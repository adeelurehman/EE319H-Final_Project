// put implementations for functions, explain how it works
// put your names here, date
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"

#include "DAC.h"

void DAC_Init(void){
	SYSCTL_RCGCGPIO_R |= 0x02; 
	
	__asm__ {
		NOP
		NOP
	}
	
	GPIO_PORTB_DIR_R |= 0x3F;
	GPIO_PORTB_DEN_R |= 0x3F;
	
}

void DAC_Out(uint8_t data){
	GPIO_PORTB_DATA_R = data;
}