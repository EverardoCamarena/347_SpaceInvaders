// Sound.h
// Runs on TM4C123 or LM4F120
// Prototypes for basic functions to play sounds from the
// original Space Invaders.
// Jonathan Valvano
// November 19, 2012
#include <stdint.h>


void Sound_Init(void);
void Sound_Play(const uint8_t *pt, uint16_t count);
void Sound_Shoot(void);
void Sound_Explosion(void);