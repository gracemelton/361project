#include "Job.h"

typedef struct System{
    int time; //current time
    int totalMemory;
    int curMemory;
    int totalDevice;
    int curDevice;
    int timeQuantum;
    Queue* holdQueue1;
    Queue* holdQueue2;
    Queue* waitQueue;
    Queue* readyQueue;
    Queue* leaveQueue;
    Job* running;
    int startTime;
}System;