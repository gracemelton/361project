typedef struct Job{
    int jobId;
    int priority;
    int needMemory;
    int needDevice;
    int holdDevice;
    int requestDevice;
    int totalTime;
    int leftTime;
    int leaveTime;
    int arrivalTime;
    struct Job* next;
}Job;

typedef struct Queue{
    Job* head;
    Job* tail;
    int queueType; //1:SJF 2:FIFO
}Queue;