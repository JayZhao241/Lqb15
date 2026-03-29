#include "key.h"

uint16_t press_time;

void KEY_Time(void)
{
	key[0].state=HAL_GPIO_ReadPin(B1_GPIO_Port,B1_Pin);
	key[1].state=HAL_GPIO_ReadPin(B2_GPIO_Port,B2_Pin);
	key[2].state=HAL_GPIO_ReadPin(B3_GPIO_Port,B3_Pin);
	key[3].state=HAL_GPIO_ReadPin(B4_GPIO_Port,B4_Pin);
	
	for(uint8_t i=0;i<4;i++)
	{
		switch(key[i].judge)
		{
			case 0:
				if(key[i].state==0)
				{
					key[i].judge=1;
				}
				break;
			case 1:
				if(key[i].state==0)
				{
					key[i].judge=2;
				}
				break;
			case 2:
				if(key[i].state==1)
				{
					press_time=key[i].press_time*10;
					if(press_time>1000)
					{
						key[i].long_press=1;
					}
					else
					{
						key[i].short_press=1;
					}
					key[i].press_time=0;
					key[i].judge=0;
				}
				else
				{
					key[i].press_time++;
				}
				break;
			default:
				break;
		}
	}
}

void KEY_Proc(void)
{
	if(key[3].short_press)
	{
		switch(lcd_state)
		{
			case 0:
				lcd_state=2;
				para_state=0;
				break;
			case 1:
				lcd_state=2;
				para_state=0;
				break;
			case 2:
				lcd_state=3;
				break;
			case 3:
				lcd_state=0;
				break;
			default:
				break;
		}
		key[3].short_press=0;
	}
	
	if(lcd_state==0 || lcd_state==1)
	{
		if(key[2].short_press)
		{
			if(lcd_state==0)
			{
				lcd_state=1;
			}
			else if(lcd_state==1)
			{
				lcd_state=0;
			}
			key[2].short_press=0;
		}
	}
	
	if(lcd_state==2)
	{
		if(key[2].short_press)
		{
			switch(para_state)
			{
				case 0:
					para_state=1;
					break;
				case 1:
					para_state=2;
					break;
				case 2:
					para_state=0;
					break;
				default:
					break;
			}
			key[2].short_press=0;
		}
		
		if(key[0].short_press)
		{
			switch(para_state)
			{
				case 0:
					PD +=100;
					if(PD>1000)PD=1000;
					break;
				case 1:
					PH +=100;
					if(PH>10000)PH=10000;
					break;
				case 2:
					PX +=100;
					if(PX>1000)PX=1000;
					break;
				default:
					break;
			}
			key[0].short_press=0;
		}
		
		if(key[1].short_press)
		{
			switch(para_state)
			{
				case 0:
					PD -=100;
					if(PD<100)PD=100;
					break;
				case 1:
					PH -=100;
					if(PH<1000)PH=1000;
					break;
				case 2:
					PX -=100;
					if(PX<-1000)PX=-1000;
					break;
				default:
					break;
			}
			key[1].short_press=0;
		}
	}
	
	if(lcd_state==3)
	{
		if(key[2].long_press)
		{
			NDA=0;
			NDB=0;
			NHA=0;
			NHB=0;
			key[2].long_press=0;
		}
	}
	
}
