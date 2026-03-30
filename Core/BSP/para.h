#include "stm32g4xx_hal.h"
#include "stdio.h"

// LCD
extern uint8_t lcd_state;
extern int16_t A_f,B_f, A_t, B_t;
extern float Ak,Bk, Am, Bm;
extern uint16_t PD,PH;
extern int16_t PX;
extern uint16_t NDA,NDB,NHA,NHB;

// KEY
typedef struct{
	uint8_t judge;
	uint8_t state;
	uint8_t short_press;
	uint8_t long_press;
	uint8_t press_time;
}KEY_T;

extern KEY_T key[4];
extern uint8_t para_state;
