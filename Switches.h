// Switches.h
// Runs on LM4F120/TM4C123
// define necessary constants
#define NVIC_EN0_PORTF 0x40000000
#define SW1 				0x10
#define SW2 				0x01

// Initialize Switches
void Switch_Init(void);