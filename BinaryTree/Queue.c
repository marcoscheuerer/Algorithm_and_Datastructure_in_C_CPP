#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

void display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

void initializeQueue(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int*)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
    // check if queue is full
    if (q->rear == q->size - 1)
    {
        printf("Queue is Full!");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;

    // check if q is empty
    if (q->front == q->rear)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }

    return x;
}

void destroyQueue(struct Queue *q)
{
    free(q->Q);
}
