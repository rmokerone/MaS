/**********************************************************************
	> File Name: main.h
	> Author: Rmoker
	> Mail: rmokerone@gmail.com 
	> Created Time: Thu 16 Oct 2014 12:04:12 AM CST
 *********************************************************************/

#ifndef __MAIN_H__
#define __MAIN_H__

//速度监控
typedef struct {
    //速度设定
    uint32_t speed；
    //左轮速度期望值
    uint32_t leftDesire;
    //右轮速度期望值
    uint32_t rightDesire;
    //左轮速度测量值
    uint32_t leftMesure;
    //右轮速度测量值
    uint32_t rightMesure;
}RatioObject;

#endif 
