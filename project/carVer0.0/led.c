/**********************************************************************
	> File Name: led.c
	> Author: Rmoker
	> Mail: rmokerone@gmail.com 
	> Created Time: Tue 29 Apr 2014 09:05:40 AM CST
 *********************************************************************/

#include "common.h"
#include "led.h"

static void ledPitInit();
static void ledBlinkIsr();
GPIO_InitTypeDef gpio_init_struct;
PIT_InitTypeDef led_pit_init_struct;

void ledInit ()
{
    gpio_init_struct.GPIO_PTx = PTB;
    gpio_init_struct.GPIO_Pins = LED1|LED2|LED3|LED4;
    gpio_init_struct.GPIO_Dir = DIR_OUTPUT;
    gpio_init_struct.GPIO_Output = OUTPUT_H;
    gpio_init_struct.GPIO_PinControl = IRQC_DIS;
    //init
    LPLD_GPIO_Init (gpio_init_struct);
}

void ledSet (led_t led, uint8 value)
{
    switch(led)
    {
        case LED_1:
            LPLD_GPIO_Output_b (PTB, 20, value);
            break;
        case LED_2:
            LPLD_GPIO_Output_b (PTB, 21, value);
            break;
        case LED_3:
            LPLD_GPIO_Output_b (PTB, 22, value);
            break;
        case LED_4:
            LPLD_GPIO_Output_b (PTB, 23, value);
            break;
    }
    
}

void ledTest ()
{
    led_t i;
    for (i = LED_1; i <= LED_4; i ++)
    {
        ledSet (i, OPEN);
    }
}

void ledBlinkIsr()
{
    LPLD_GPIO_Toggle(PTB, LED1|LED2|LED3|LED4);
}

void ledPitInit()
{
    led_pit_init_struct.PIT_Pitx = PIT0;
    led_pit_init_struct.PIT_PeriodMs = 500;
    led_pit_init_struct.PIT_Isr = ledBlinkIsr;
    LPLD_PIT_Init(led_pit_init_struct);
}

void ledBlink(void)
{
    ledPitInit();
    LPLD_PIT_EnableIrq(led_pit_init_struct);
}
