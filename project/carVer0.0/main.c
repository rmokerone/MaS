/**********************************************************************
	> File Name: main.c
	> Author: Rmoker
	> Mail: rmokerone@gmail.com 
	> Created Time: Tue 14 Oct 2014 05:53:45 PM CST
 *********************************************************************/
#include "common.h"
#include "main.h"

#define MOTOR_SWITCH    FALSE

/* --------------------------------------------------------------------------*/
/**
* @brief 程序主函数
*
* @Returns  程序正常完成返回0 
*/
/* ----------------------------------------------------------------------------*/
int main(void)
{
    sizeof(int);
    /* -------------------------------------------------------*/
    /**
    * @brief Led spoot initliztion
    */
    /* ---------------------------------------------------------*/
    ledInit();
    LED_Init();
    ledBlink();
    //舵机控制
    servoAttch();
    servoWrite(120);
    motorsInit();
    //从车头方向看
#if (MOTOR_SWITCH == TRUE)
    motorsSetRatio(MOTOR_R, 5000);
    motorsSetRatio(MOTOR_L, 5000);
#endif
    LED_Set_Pos(0,0);
    LED_P6x8Str(0,0, "MaScar terminal:");
    oledPrintLine(0,0, 127, 0);
    //oledPrintLine(0,0, 0, 63);
    while (1){
    }

    return 0;
}

