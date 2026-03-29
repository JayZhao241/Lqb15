#include "led.h"

void LED_Disp(uint8_t led_num, uint8_t state)
{
	static uint8_t led_control;
	if(state==1)
	{
		led_control |= (0x01<<(led_num-1));
	}
	else if(state==0)
	{
		led_control &= ~(0x01<<(led_num-1));
	}
	
	HAL_GPIO_WritePin(LE_GPIO_Port,LE_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_All,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,(led_control<<8),GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LE_GPIO_Port,LE_Pin,GPIO_PIN_RESET);
}

void LED_Proc(void)
{
	if(lcd_state==0 || lcd_state==1)
	{
		LED_Disp(1,1);
	}
	else
	{
		LED_Disp(1,0);
	}
	
	if(A_f>PH)
	{
		LED_Disp(2,1);
	}
	else
	{
		LED_Disp(2,0);
	}
	
	if(NDA>=3||NDB>=3)
	{
		LED_Disp(8,1);
	}
	else
	{
		LED_Disp(8,0);
	}
}
