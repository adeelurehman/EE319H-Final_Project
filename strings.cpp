#include "strings.h"
#include "Physics.h"
#include "Timer1.h" 
#include "ST7735.h" 

char language = 0; 

const char* scorePrefix[2] = {"Score: ", "Resultado: "};
const char* deathMessagePrefix[2] = {"LOL U SUCK", "JAJAJA TU CHUPAR"}; 
const char* winMessagePrefix[2] = {"VICTORY SCREAM", "GRITO VICTORIA" }; 

const uint8_t scoreLen[2] = {6,10};

int seconds;
int minutes;

void strings_init() {
	Timer1_Init(&timerAdd,0x4C4B400);
	ST7735_SetCursor(TimeSpot); 
	ST7735_DrawString(TimeSpot, "0:00", ST7735_YELLOW);
}

void timerAdd() {
	seconds++;
	if (seconds/60)
		minutes++;
	seconds %= 60;
	minutes %= 60;
	
	ST7735_SetTextColor(ST7735_YELLOW); 
	ST7735_SetCursor(TimeSpot); 
	ST7735_OutUDec(minutes);
	ST7735_OutChar(':');
	if (seconds<10)
		ST7735_OutChar('0'); 
	ST7735_OutUDec(seconds); 
}

void updateStrings() {
	
}

#define DeadStringX 8
#define DeadStringY 5

void DrawDead() {
	ST7735_FillRect(45,45,85,30,0xffff); 
	ST7735_DrawString(DeadStringX,DeadStringY,deathMessagePrefix[language],ST7735_CYAN);
	ST7735_DrawString(DeadStringX,DeadStringY+1,scorePrefix[language],ST7735_CYAN); 
	ST7735_SetCursor(DeadStringX+scoreLen[language], DeadStringY+1); 
	ST7735_SetTextColor(ST7735_CYAN); 
	ST7735_OutUDec(score); 
}

void DrawWin() {
	ST7735_FillRect(45,45,85,30,0xffff); 
	ST7735_DrawString(DeadStringX,DeadStringY,winMessagePrefix[language],ST7735_CYAN);
	ST7735_DrawString(DeadStringX,DeadStringY+1,scorePrefix[language],ST7735_CYAN); 
	ST7735_SetCursor(DeadStringX+scoreLen[language], DeadStringY+1); 
	ST7735_SetTextColor(ST7735_CYAN); 
	ST7735_OutUDec(score); 
}
