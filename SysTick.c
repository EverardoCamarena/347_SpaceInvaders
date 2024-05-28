// SysTick.c
// Runs on LM4F120/TM4C123
#include "tm4c123gh6pm.h"

// Initialize SysTick timer with interrupt enabled
void SysTick_Init(unsigned long period){
  NVIC_ST_CTRL_R = 0;                                        // disable SysTick during setup
  NVIC_ST_RELOAD_R = period - 1;                             // maximum reload value
  NVIC_ST_CURRENT_R = 0;                                     // any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0xFF1FFFFF)|0x00400000; // enable SysTick with core clock priority 1

  NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE + NVIC_ST_CTRL_INTEN + NVIC_ST_CTRL_CLK_SRC;
}
