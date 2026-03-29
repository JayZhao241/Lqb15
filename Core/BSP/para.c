#include "para.h"

// LCD
uint8_t lcd_state=0;
uint16_t A_f,B_f, A_t, B_t;
float Ak,Bk, Am, Bm;
uint16_t PD=1000,PH=5000;
int16_t PX=0;
uint16_t NDA=0,NDB=0,NHA=0,NHB=0;


KEY_T key[4];
uint8_t para_state=0;
