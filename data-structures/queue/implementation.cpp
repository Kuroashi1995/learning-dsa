#include <stdio.h>
#include <stdlib.h>

class Queue
{
private:
    int front = -1, rear = -1, size;
    int *queue;

public:
    void enque(int value)
    {
        if (rear - front == size - 1)
        {
            printf("Error: Queue is full");
            return;
        }
        if (front == -1)
        {
            front++;
        }
        queue[++rear % size] = value;
        return;
    };
    int deque()
    {
        if (isEmpty())
        {
            printf("Error: Queue is empty");
            return -1;
        }
        return queue[front++ % size];
    };
    int isEmpty()
    {
        return (rear == front);
    };
    Queue(int paramSize)
    {
        queue = new int[paramSize];
        size = paramSize;
    };
    void printQueue()
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d", queue[i % size]);
        }
        printf("\n");
    }
};

int main()
{
    Queue *queue = new Queue(4);
    printf("Is the queue empty?: %d\n", queue->isEmpty());
    queue->enque(1);
    queue->printQueue();
    queue->enque(2);
    queue->printQueue();
    queue->enque(3);
    queue->printQueue();
    queue->enque(4);
    queue->printQueue();
    printf("Element out of the queue!: %d\n", queue->deque());
    printf("Element out of the queue!: %d\n", queue->deque());
    printf("Element out of the queue!: %d\n", queue->deque());
    queue->enque(5);
    queue->printQueue();
    queue->enque(6);
    queue->printQueue();
    delete (queue);
}