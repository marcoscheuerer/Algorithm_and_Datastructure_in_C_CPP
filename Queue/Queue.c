#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void display(struct Queue q);
void initializeQueue(struct Queue *q, int size);
void enqueue(struct Queue *q, int x);
int dequeue(struct Queue *q);
void destroyQueue(struct Queue *q);

int main()
{
    struct Queue q;
    initializeQueue(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(q);

    printf("Removed: %d\n", dequeue(&q));
    display(q);
    printf("Removed: %d\n", dequeue(&q));
    display(q);
    printf("Removed: %d\n", dequeue(&q));
    display(q);
    printf("Removed: %d\n", dequeue(&q));
    display(q);

    destroyQueue(&q);

    return 0;
}

/**
 * @brief Prints the queue on screen
 *
 * @param q Queue-Structure
 */
void display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

/**
 * @brief Initialize the structure of the queue
 *
 * @param q Queue-Structure
 */
void initializeQueue(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int*)malloc(q->size * sizeof(int));
}

/**
 * @brief Adds a new value to the queue
 *
 * @param q Queue-Structure
 * @param x New Value added to queue
 */
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

/**
 * @brief Deletes the front value of the queue
 *
 * @param q Queue-Structure
 * @return int returns the value to delete
 */
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

/**
 * @brief Destroys the queue on the heap
 *
 * @param q Queue-Structure
 */
void destroyQueue(struct Queue *q)
{
    free(q->Q);
}
