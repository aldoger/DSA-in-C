#include <stdlib.h>
typedef struct node {
    QueueData data;
    struct node *next;
}Node, *NodePtr;

typedef struct {
    NodePtr head;;
    NodePtr tail;
}QueueType, *Queue;

Queue initQueue(){
    Queue q = (Queue)malloc(sizeof(QueueType));
    q->head =  NULL;
    q->tail =  NULL;
    return q;
}

int empty(Queue q){
    return (q->head == NULL);
}

void enQueue(Queue q, QueueData d){
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    np->data = d;
    np->next = NULL;
    if(empty(q)){
        q->head = np;
        q->tail = np;
    }else{
        q->tail->next = np;
        q->tail = np;
    }
}

QueueData deQueue(Queue q){
    if(empty(q)){
        printf("\nerror: attempt dequeue empty queue");
        exit(1);
    }

    NodePtr temp = q->head;
    QueueData hold = q->head->data;
    q->head = q->head->next;
    if(q->head == NULL) q->tail = NULL;
    free(temp);
    return hold;
}