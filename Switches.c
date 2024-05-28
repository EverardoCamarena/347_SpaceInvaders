//Switches.c
// Runs on TM4C123
#include "switches.h"
#include "tm4c123gh6pm.h"

// Initialize the onboard two switches.
void Switch_Init(void){
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;         // activate F clock
  while ((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOF)==0){};

  GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;                 // 1) unlock PortF
  GPIO_PORTF_CR_R |= 0x11;                           // 2) allow changes to PF4 & 0 :10001->0x11
  GPIO_PORTF_AMSEL_R &= ~0x11;                       // 3) disable analog function
  GPIO_PORTF_PCTL_R &= ~0x000F000F;                  // 4) GPIO clear bit PCTL
  GPIO_PORTF_DIR_R &= ~0x11;                         // 5) PF4, PF0 input
  GPIO_PORTF_AFSEL_R &= ~0x11;                       // 6) no alternate function
	GPIO_PORTF_PUR_R |= 0x11;                          // 8) enable pullup resistors on PF4, PF0
  GPIO_PORTF_DEN_R |= 0x11;                          // 7) enable digital pins PF4, PF0

	GPIO_PORTF_IS_R &= ~0x11;                          // 9) PF0 & PF4 is edge-sensitive
	GPIO_PORTF_IBE_R &= ~0x11;                         // 10) PF0 & PF4 not both edge
	GPIO_PORTF_IEV_R |= ~0x11;                         // 11) PF4,PF0 falling edge event
	GPIO_PORTF_ICR_R |= 0x11;                          // 12) clear flag 4
	GPIO_PORTF_IM_R |= 0x11;                           // 13) arm interrupt on PF0 & PF4
	NVIC_PRI7_R = (NVIC_PRI7_R&0xFF1FFFFF)|0x00600000; // 14) priority 3
	NVIC_EN0_R |= NVIC_EN0_PORTF;                      // 15) enable inturrupt 30 in NVIC
}