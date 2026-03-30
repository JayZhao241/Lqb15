#include "display.h"

void LCD_Proc(void)
{
	unsigned char lcd_str[30];
	
	// DATA
	if(lcd_state==0)
	{
		
		sprintf((char*)lcd_str, "        DATA");
		LCD_DisplayStringLine(Line1, (uint8_t *)lcd_str);
		
		if(A_f>=1000)
		{
			Ak=A_f*0.001;
			sprintf((char*)lcd_str, "     A=%0.2fKHz      ", Ak);
			LCD_DisplayStringLine(Line3, (uint8_t *)lcd_str);
		}
		else if(A_f<1000&&A_f>=0)
		{
			sprintf((char*)lcd_str, "     A=%dHz          ", A_f);
			LCD_DisplayStringLine(Line3, (uint8_t *)lcd_str);
		}
		else if(A_f<0)
		{
			sprintf((char*)lcd_str, "     A=NULL          ");
			LCD_DisplayStringLine(Line3, (uint8_t *)lcd_str);
		}
		
		if(B_f>=1000)
		{
			Bk=B_f*0.001;
			sprintf((char*)lcd_str, "     B=%.2fKHz       ", Bk);
			LCD_DisplayStringLine(Line4, (uint8_t *)lcd_str);
		}
		else if(B_f<1000&&B_f>=0)
		{
			sprintf((char*)lcd_str, "     B=%dHz         ", B_f);
			LCD_DisplayStringLine(Line4, (uint8_t *)lcd_str);
		}
		else if(B_f<0)
		{
			sprintf((char*)lcd_str, "     B=NULL          ");
			LCD_DisplayStringLine(Line4, (uint8_t *)lcd_str);
		}
		
		sprintf((char*)lcd_str, "                    ");
		LCD_DisplayStringLine(Line5, (uint8_t *)lcd_str);
		
		sprintf((char*)lcd_str, "                    ");
		LCD_DisplayStringLine(Line6, (uint8_t *)lcd_str);
	}
	
	// Period
	if(lcd_state==1)
	{
		sprintf((char*)lcd_str, "        DATA");
		LCD_DisplayStringLine(Line1, (uint8_t *)lcd_str);
		
		if(A_t>=1000)
		{
			Ak=A_t*0.001;
			sprintf((char*)lcd_str, "     A=%0.2fmS       ", Am);
			LCD_DisplayStringLine(Line3, (uint8_t *)lcd_str);
		}
		else if(A_t<1000)
		{
			sprintf((char*)lcd_str, "     A=%duS          ", A_t);
			LCD_DisplayStringLine(Line3, (uint8_t *)lcd_str);
		}
		else if(A_f<0)
		{
			sprintf((char*)lcd_str, "     A=NULL          ");
			LCD_DisplayStringLine(Line3, (uint8_t *)lcd_str);
		}
		
		if(B_t>=1000)
		{
			Bk=B_t*0.001;
			sprintf((char*)lcd_str, "     B=%.2fmS       ", Bm);
			LCD_DisplayStringLine(Line4, (uint8_t *)lcd_str);
		}
		else if(B_t<1000)
		{
			sprintf((char*)lcd_str, "     B=%duS         ", B_t);
			LCD_DisplayStringLine(Line4, (uint8_t *)lcd_str);
		}
		
		sprintf((char*)lcd_str, "                    ");
		LCD_DisplayStringLine(Line5, (uint8_t *)lcd_str);
		
		sprintf((char*)lcd_str, "                    ");
		LCD_DisplayStringLine(Line6, (uint8_t *)lcd_str);
	}
	
	// Para
	if(lcd_state==2)
	{
		sprintf((char*)lcd_str, "        PARA        ");
		LCD_DisplayStringLine(Line1, (uint8_t *)lcd_str);
		
		sprintf((char*)lcd_str, "     PD=%dHz        ", PD);
		LCD_DisplayStringLine(Line3, (uint8_t *)lcd_str);
		
		sprintf((char*)lcd_str, "     PH=%dHz        ", PH);
		LCD_DisplayStringLine(Line4, (uint8_t *)lcd_str);
		
		sprintf((char*)lcd_str, "     PX=%dHz        ", PX);
		LCD_DisplayStringLine(Line5, (uint8_t *)lcd_str);
		
		sprintf((char*)lcd_str, "                    ");
		LCD_DisplayStringLine(Line6, (uint8_t *)lcd_str);
	}
	
	//Record
	if(lcd_state==3)
	{
		sprintf((char*)lcd_str, "        RECD        ");
		LCD_DisplayStringLine(Line1, (uint8_t *)lcd_str);
		
		sprintf((char*)lcd_str, "     NDA=%d          ", NDA);
		LCD_DisplayStringLine(Line3, (uint8_t *)lcd_str);
		
		sprintf((char*)lcd_str, "     NDB=%d          ", NDB);
		LCD_DisplayStringLine(Line4, (uint8_t *)lcd_str);
		
		sprintf((char*)lcd_str, "     NHA=%d          ", NHA);
		LCD_DisplayStringLine(Line5, (uint8_t *)lcd_str);
		
		sprintf((char*)lcd_str, "     NHB=%d          ", NHB);
		LCD_DisplayStringLine(Line6, (uint8_t *)lcd_str);
	}
}
