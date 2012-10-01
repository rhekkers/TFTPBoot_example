#include "LPC17xx.h"
#include "lpc_types.h"
#include "GPIO.h"
#include "timer.h"

uint32_t toggle = 0;
uint32_t toggle1 = 0;
uint32_t toggle2 = 0;
uint32_t toggle3 = 0;
uint32_t ttu=0;



int main(void)
{
	//SystemInit();
	TimerInit(0, 15000000);
	TimerInit(1, 30000000);
	TimerInit(2, 60000000);
	TimerInit(3, 120000000);
//	enable_timer(0);
//	enable_timer(1);
	enable_timer(2);
//	enable_timer(3);
	GPIOSetDir(1, 18, 1);
	GPIOSetDir(1, 19, 1);
	GPIOSetDir(1, 24, 1);
	GPIOSetDir(1, 25, 1);
	GPIOSetDir(0, 26, 1);

	GPIOSetValue(1, 18, 1);
	GPIOSetValue(0,26, 1);

	delayMs(0,2000);

	GPIOSetValue(1, 18, 0);
	GPIOSetValue(0,26, 0);


    while(1)
    {
    	GPIOSetValue(1, 18, HIGH);
    	delayMs(ttu,300);
    	GPIOSetValue(1, 19, HIGH);
    	delayMs(ttu,300);
    	GPIOSetValue(1, 24, HIGH);
    	delayMs(ttu,300);
    	GPIOSetValue(1, 25, HIGH);
    	delayMs(ttu,300);
    	GPIOSetValue(0, 26, HIGH);
    	delayMs(ttu,1000);

    	GPIOSetValue(0, 26, LOW);
    	delayMs(ttu,300);
    	GPIOSetValue(1, 25, LOW);
    	delayMs(ttu,300);
    	GPIOSetValue(1, 24, LOW);
    	delayMs(ttu,300);
    	GPIOSetValue(1, 19, LOW);
    	delayMs(ttu,300);
    	GPIOSetValue(1, 18, LOW);
    	delayMs(ttu,300);
    }
}

void TIMER0_IRQHandler (void)
{
	TIMER0_interrupt();
	toggle = ~toggle;
	GPIOSetValue(1, 18, toggle);
}

void TIMER1_IRQHandler (void)
{
	TIMER1_interrupt();
	toggle1 = ~toggle1;
	GPIOSetValue(1, 19, toggle1);
}

void TIMER2_IRQHandler (void)
{
	TIMER2_interrupt();
	toggle2 = ~toggle2;
	GPIOSetValue(1, 24, toggle2);
}

void TIMER3_IRQHandler (void)
{
	TIMER3_interrupt();
	toggle3 = ~toggle3;
	GPIOSetValue(1, 25, toggle3);
}
