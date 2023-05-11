#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.c"
#include "Process.h"
#include "Device.h"
#include "Job.h"
#include "System.h"
#include "MemoryResource.h"
#include "Queue.h"

//Global Variables
//std::vector<Process> hold_queue;
//LinkedListQueue hold_queue;
Queue* hold_queue1;
Queue* hold_queue2;
Queue* ready_queue;
Queue* wait_queue;
Device devices[MAX_DEVICES];
Process process_table[MAX_PROCESSES];
int time_slice = 4;
int current_time = 0;
int available_memory = 256;
int num_processes = 0;

//sorting hold queue based on SJF algorithm
bool sjf_compare(Process p1, Process p2){
	return p1.burst_time < p2.burst_time;
}

bool fifo_compare(Process p1, Process p2){
	return p1.arrival_time < p2.arrival_time;
}

//adding process to hold queue
void add_to_hold_queue(Process p, std::String algorithm){
	if(available_memory < p.memory_required){
		hold_queue.push_back(p);
		if(algorithm == "sjf"){
			std::sort(hold_queue.begin(), hold_queue.end(), sjf_compare);
		}
		else if (algorithm == "fifo"){
			std::sort(hold_queue.begin(), hold_queue.end(), fifo_compare);
		}
		else{
			available_memory -= p.memory_required;
			p.time_left = p.burst_time;
			ready_queue.push(p);
		}
	}
}

//reading input files function
void read_file(String file_name){


   FILE* ptr;
   char file[500];


   //opening file
   ptr = fopen(file_name, "r");


   if(NULL == ptr){
       printf("File cannot be opened");
   }


   //fgets(file, 500, ptr);


   //reading through each line
   while (fgets(file, sizeof(file), ptr) != NULL){
       if(file[0] == "C"){
           if (fgetc(file) == "M"){
              
           }
       }
   }
}

int main(){
	//struct Devices tmp;
	hold_queue1 = newQueue(1);
	hold_queue1 = newQueue(2);
	ready_queue = newQueue(NULL);
	wait_queue = newQueue(NULL);

}



