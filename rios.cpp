
#include <chrono>
#include "rios.h"

static Task taskList[MAX_TASKS];
static int taskcount = 0;

#ifndef ARDUINO
unsigned long millis(){
    using namespace std::chrono;
    return duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()
        ).count();
}
#endif

void RIOS_AddTask(void (*taskFunc)(), unsigned long period){
    if(taskcount < MAX_TASKS){
        taskList[taskcount].taskFunc = taskFunc;
        taskList[taskcount].period = period;
        taskList[taskcount].lastrun = millis();
        taskList[taskcount].completed = false;
        taskcount++;
    }   
}

void RIOS_MarkTaskCompleted(void (*taskFunc)()){
    for(int i = 0; i < taskcount; i++){
        if(taskList[i].taskFunc == taskFunc){
            taskList[i].completed = true;
            break;
        }
    }
}

void RIOS_GarbageCollect(){
    int i = 0;
    while(i < taskcount){
        if(taskList[i].completed){
            // Shift remaining tasks left
            for(int j = i; j < taskcount - 1; j++){
                taskList[j] = taskList[j + 1];
            }
            taskcount--;
        } else {
            i++;
        }
    }
}

void Rios_Run(){
    unsigned long currentTime = millis();
    for (int i = 0; i < taskcount; i++){
        if (!taskList[i].completed && currentTime - taskList[i].lastrun >= taskList[i].period){
            taskList[i].taskFunc();
            taskList[i].lastrun = currentTime;
        }
    }
}
