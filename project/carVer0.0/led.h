/**********************************************************************
	> File Name: led.h
	> Author: Rmoker
	> Mail: rmokerone@gmail.com 
	> Created Time: Mon 28 Apr 2014 06:38:28 PM CST
 *********************************************************************/

#ifndef __LED_H__
#define __LED_H__

#include "common.h"

//define LED GPIO port
#define LED1 (1 << 20)
#define LED2 (1 << 21)
#define LED3 (1 << 22)
#define LED4 (1 << 23)

//define status
#define  OPEN       0
#define  CLOSE      1

typedef enum {LED_1 = 0,
              LED_2,
              LED_3,
              LED_4} led_t;

void ledInit ();

void ledSet (led_t led, uint8 value);

void ledTest();

void ledBlink();

#endif
