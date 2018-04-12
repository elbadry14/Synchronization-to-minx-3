#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

struct Node
{
	int process;
	struct Node* next;
};

struct Queue
{
	int size;
	struct Node *rear, *front;
};

struct Queue* init_queue(){
	struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
	q->rear = NULL;
	q->front = NULL;
	q->size = 0;
	debug("initalized a que, q->front address: %p", q->front);
	return q;
}

int dequeue(struct Queue* q){
	struct Node *temp = q->front;
	if(temp == NULL){
		// queue empty, should never reach here
		return -1;
	}
	q->front = q->front->next;
	temp->next = NULL;
	q->size--;
	return temp->process;
}

void enqueue(struct Queue* q, int process){
	struct Node *var = (struct Node*)malloc(sizeof(struct Node));
	var->process = process;
	printf("null = %p\n", NULL);
	printf("about to check front of que, %p\n", q->front);
	if(q->front == NULL){
		printf("inside if statement");
		q->front = var;
		q->front->next = NULL;
		q->rear = q->front;
	}
	else{
		printf("inside else statement");
		q->rear->next = var;
		q->rear = var;
		//front->next = NULL;
	}
	q->size++;
	printf("%d was added to the queue and the new size: %d\n", q->rear->process, q->size);
}


int queue_size(struct Queue* q){
	return q->size;
}

void clear_queue(struct Queue *q){
	q->rear = NULL;
	q->front = NULL;
	q->size = 0;
}

// int main(){
// 	printf("about to add to queue\n");
// 	struct Queue *q = init_queue();
// 	enqueue(q, 1);
// 	enqueue(q, 2);
// 	enqueue(q, 3);
// 	printf("%d was removed from the queue\n", dequeue(q));
// 	printf("Current queue size: %d\n", queue_size(q));
// 	printf("%d was removed from the queue\n", dequeue(q));
// 	enqueue(q, 4);
// 	printf("%d was removed from the queue\n", dequeue(q));
// 	printf("%d was removed from the queue\n", dequeue(q));
// 	return 0;
// }