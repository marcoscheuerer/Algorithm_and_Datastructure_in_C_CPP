#ifndef __QUEUE_H
#define __QUEUE_H

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

/**
 * @brief Prints the queue on screen
 *
 * @param q Queue-Structure
 */
void display(struct Queue q);

/**
 * @brief Initialize the structure of the queue
 *
 * @param q Queue-Structure
 */
void initializeQueue(struct Queue *q, int size);

/**
 * @brief Adds a new value to the queue
 *
 * @param q Queue-Structure
 * @param x New Value added to queue
 */
void enqueue(struct Queue *q, int x);

/**
 * @brief Deletes the front value of the queue
 *
 * @param q Queue-Structure
 * @return int returns the value to delete
 */
int dequeue(struct Queue *q);

/**
 * @brief Destroys the queue on the heap
 *
 * @param q Queue-Structure
 */
void destroyQueue(struct Queue *q);

#endif
