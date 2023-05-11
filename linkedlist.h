
/* typedef struct Job{
    int id;
    int mem;
    int device_num;
    int time;
}Job; */

typedef struct Node{
   void* data;
   struct Node* next; 
}Node;

typedef struct LinkedListQueue{
    Node* front_node;
    int size_num;
}LinkedListQueue;

typedef struct FIFO_Queue{
    struct LinkedListQueue super;
}FIFO_Queue;

typedef struct SJF_Queue{
    struct LinkedListQueue super;
}SJF_Queue;

// creates a new Node 
struct Node* create_node(void* data, struct Node* next);

// initializes a new empty LinkedListQueue
LinkedListQueue init_queue();

// returns true if the queue is empty
int is_empty(struct LinkedListQueue* queue);

// returns the number of elements in the queue
int size(struct LinkedListQueue* queue);

// adds a new element to the back of the queue
void push(struct LinkedListQueue* queue, void* data);

// removes the first element from the queue
void pop(struct LinkedListQueue* queue);

// returns the first element in the queue
void* front(struct LinkedListQueue* queue);

// prints the contents of the queue
void print(struct LinkedListQueue* queue);

// deallocates all nodes in the queue
void clear(struct LinkedListQueue* queue);

//override fifo push
void FIFO_Queue_push(FIFO_Queue* queue, void* data);

//override sjf push
void SJF_Queue_push(SJF_Queue* queue, void* data);