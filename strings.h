#ifndef STRINGSH
#define STRINGSH

#include <stdint.h>

extern char language; 

extern const uint8_t scoreLen[2];
extern const char* scorePrefix[2];

extern const char* deathMessagePrefix[2]; 

#define TimeSpot 12,0

void strings_init();
void updateStrings();
void timerAdd();
void DrawDead(); 

#endif
