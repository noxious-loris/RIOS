#ifndef RIOS_H
#define RIOS_H
#ifndef ARDUINO

#include <Arduino.h>
#else
#include<iostream>
#include<chrono>
#include<thread>
#endif

#define MAX_TASKS 10  // Define maximum number of tasks

typedef struct{
    void(*taskFunc)();
    unsigned long period;
    unsigned long lastrun;
    bool complete;
} Task;


void RIOS_AddTask(void(*taskFunc)(), unsigned long period);
void RIOS_MarkTaskCompleted(void(*taskFunc)());
void RIOS_GarbageCollect();
void Rios_Run();
#ifndef ARDUINO
unsigned long millis();//add function prototype
#endif

#endif//Rios_h
