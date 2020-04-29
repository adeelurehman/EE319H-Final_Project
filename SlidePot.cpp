// SlidePot.cpp
// Runs on LM4F120/TM4C123
// Provide functions that initialize ADC0
// Student names: change this to your names or look very silly
// Last modification date: change this to the last modification date or look very silly

#include <stdint.h>
#include "SlidePot.h"
#include "inc/tm4c123gh6pm.h"

// ADC initialization function 
// Input: none
// Output: none
// measures from PD2, analog channel 5
void ADC_Init(void){ 
// lab 8
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
	
	#ifdef Hardware
	ADC0_SAC_R = 0x06; 
	#endif
	
	//copied from textbook
}

//------------ADCIn------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 12-bit result of ADC conversion
// measures from PD2, analog channel 5
uint32_t ADC_In(void){  

// lab 8
	uint32_t result; 
	ADC0_PSSI_R = 0x0008;
	while((ADC0_RIS_R&0x08)==0){};
	result = ADC0_SSFIFO3_R&0xFFF;
	ADC0_ISC_R = 0x0008;
	return result; 
}

// constructor, invoked on creation of class
// m and b are linear calibration coeffients 
SlidePot::SlidePot(uint32_t m, uint32_t b){
// lab 8
}

void SlidePot::Save(uint32_t n){
// lab 9
}
uint32_t SlidePot::Convert(uint32_t n){
  // lab 8
  return 0;
}

void SlidePot::Sync(void){
// lab 8
// 1) wait for semaphore flag to be nonzero
// 2) set semaphore flag to 0
	while(flag==0);
	flag = 0;
}

uint32_t SlidePot::ADCsample(void){ // return ADC sample value (0 to 4095)

  // return last calculated ADC sample
  return data; // replace this with solution
}

uint32_t SlidePot::Distance(void){  // return distance value (0 to 2000), 0.001cm
// lab 8
  return 0;
}


