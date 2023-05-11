#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

//cosntructor
struct Job default_job(){
    Job default_job;
    default_job.jobId = -1;
    default_job.needMemory = -1;
    default_job.needDevice= -1;
    default_job.totalTime = -1;
    return default_job;
}

struct Job values_job(int id, int mem, int device_num, int time){
    Job values_job;
    values_job.jobId = id;
    values_job.needMemory = mem;
    values_job.needDevice= device_num;
    values_job.totalTime = time;
    return values_job;
}


// creates a new Node 
struct Node* create_node(void* data, struct Node* next) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = next;
    return new_node;
}


// initializes a new empty LinkedListQueue
LinkedListQueue init_queue() {
    LinkedListQueue* queue = (struct LinkedListQueue*) malloc(sizeof(struct LinkedListQueue));
    queue->front_node = NULL;
    queue->size_num = 0;
    // *queue = (LinkedListQueue*)malloc(sizeof(LinkedListQueue));
    // (*queue) -> front_node = NULL;
    // (*queue) ->size_num = 0;
}

// returns true if the queue is empty
int is_empty(struct LinkedListQueue* queue) {
    return queue->size_num == 0;
}

// returns the number of elements in the queue
int size(struct LinkedListQueue* queue) {
    return queue->size_num;
}

// adds a new element to the back of the queue
void push(struct LinkedListQueue* queue, void* data) {
    struct Node* new_node = create_node(data, NULL);
    if (is_empty(queue)) {
        queue->front_node = new_node;
    } else {
        struct Node* back_node = queue->front_node;
        while (back_node->next != NULL) {
            back_node = back_node->next;
        }
        back_node->next = new_node;
    }
    queue->size_num++;
}

// removes the first element from the queue
void pop(struct LinkedListQueue* queue) {
    if (!is_empty(queue)) {
        struct Node* old_front_node = queue->front_node;
        queue->front_node = queue->front_node->next;
        free(old_front_node->data);
        free(old_front_node);
        queue->size_num--;
    }
}

// returns the first element in the queue
void* front(struct LinkedListQueue* queue) {
    if (!is_empty(queue)) {
        return queue->front_node->data;
    } else {
        return NULL;
    }
}

// prints the contents of the queue
void print(struct LinkedListQueue* queue) {
    struct Node* current_node = queue->front_node;
    while (current_node != NULL) {
        printf("%d ", *(int*)current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// deallocates all nodes in the queue
void clear(struct LinkedListQueue* queue) {
    while (!is_empty(queue)) {
        pop(queue);
    }
}

//override fifo push
void FIFO_Queue_push(FIFO_Queue* queue, void* data) {
    Node* new_node = LinkedListNode_create(data);
    push(queue, new_node);
}

//override sjf push
void SJF_Queue_push(SJF_Queue* queue, void* data) {
   struct Node* new_node = create_node(data, NULL);
    if (is_empty(queue)) {
        queue->front_node = new_node;
    }
}





