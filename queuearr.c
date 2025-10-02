#include <stdio.h>
#include <stdlib.h>
#define MAXQ 5

typedef struct {
    int head;
    int tail;
    int QA[MAXQ];
}QTYPE, *Queue;

Queue initQueue(){
    Queue q = (Queue)malloc(sizeof(QTYPE));
    q->head = q->tail = 0;
    return q;
}

int empty(Queue q){
    return q->head == q->tail;
}

void enQueue(Queue q, int n){
    if(q->tail == MAXQ-1) q->tail = 0;
    else ++(q->tail);
    if(q->head == q->tail){
        printf("\nqueue is full");
        exit(1);
    }
    q->QA[q->tail] = n;
}

int deQueue(Queue q){
    if(empty(q)){
        printf("\nerror: attempt to remove in empty queue");
        exit(1);
    }
    if(q->head == MAXQ-1) q->head = 0;
    else ++(q->head);
    return q->QA[q->head];
}

void printQueue(Queue q){
    int st = q->head;
    while(st != MAXQ){
        printf("%d ", q->QA[st++]);
    }
}

int main(){
    Queue q = initQueue();
    int n;
    scanf("%d", &n);
    while(n != 0){
        enQueue(q, n);
        scanf("%d", &n);
    }
    printf("Queue: \n");
    printQueue(q);
}