#include <iostream>
#include <cstdlib>

/**
 * @brief Class for the datastructure queue - FIFO
 *
 */
class Queue
{
private:
    std::int32_t size;
    std::int32_t front;
    std::int32_t rear;
    std::int32_t *Q;

public:
    Queue()
    {
        front=rear=-1;
        size=10;
        Q=new std::int32_t[size];
    }

    Queue(std::int32_t size)
    {
        front=rear=-1;
        this->size = size;
        Q = new std::int32_t[this->size];
    }

    void enqueue(std::int32_t x);
    int dequeue();
    void display();
};

/**
 * @brief Adds a new value to the queue
 *
 * @param x New Value added to queue
 */
void Queue::enqueue(int x)
{
    // check if queue is full
    if (rear==size-1)
        std::cout << "Queue is Full!" << std::endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

/**
 * @brief Deletes the front value of the queue
 *
 * @return int returns the value to delete
 */
int Queue::dequeue()
{
    int x = -1;

    // check if queue is empty
    if (front == rear)
    {
        std::cout << "Queue is Empty!" << std::endl;
    }
    else
    {
        front++;
        x = Q[front];
    }

    return x;
}

/**
 * @brief Prints the queue on screen
 *
 */
void Queue::display()
{
    for (auto i = front + 1; i <= rear; i++)
    {
        std::cout << Q[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    // Queue at heap
    Queue *heapQueue = new Queue(5);

    heapQueue->display();
    heapQueue->enqueue(3);
    heapQueue->enqueue(5);
    heapQueue->enqueue(10);
    heapQueue->display();

    std::cout << heapQueue->dequeue() << std::endl;
    heapQueue->display();
    std::cout << heapQueue->dequeue() << std::endl;
    heapQueue->display();
    std::cout << heapQueue->dequeue() << std::endl;
    heapQueue->display();
    std::cout << heapQueue->dequeue() << std::endl;
    heapQueue->display();

    delete heapQueue;

    // Queue at stack
    Queue stackQueue(5);

    stackQueue.display();
    stackQueue.enqueue(3);
    stackQueue.enqueue(5);
    stackQueue.enqueue(10);
    stackQueue.display();

    std::cout << stackQueue.dequeue() << std::endl;
    stackQueue.display();
    std::cout << stackQueue.dequeue() << std::endl;
    stackQueue.display();
    std::cout << stackQueue.dequeue() << std::endl;
    stackQueue.display();
    std::cout << stackQueue.dequeue() << std::endl;
    stackQueue.display();

    return 0;
}
