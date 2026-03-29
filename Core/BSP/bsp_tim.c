#include "bsp_tim.h"

uint8_t overA=1,overB=1;

void TIM_Proc(void)
{
	A_t=(1/A_f)*1000000;
	B_t=(1/B_f)*1000000;
	
	if(A_f>PH&&overA==1)
	{
		NHA++;
		overA=0;
	}
	else if(A_f<PH&&overA==0)
	{
		overA=1;
	}
	if(B_f>PH&&overB==1)
	{
		NHB++;
		overB=0;
	}
	else if(B_f<PH&&overB==0)
	{
		overB=1;
	}
}
