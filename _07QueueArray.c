#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 5

struct QueueArray
{
    int Count;
    int Front;
    int Rear;
    int Entry[N];
}typedef QueueArray;


QueueArray Q;


void CreateQueue()
{
    Q.Count = 0;
    Q.Front = 0;
    Q.Rear = -1;
}

void EnQueue(int x)
{
    if(Q.Count == N)
        printf("Queue Overflow");
    else
    {
        Q.Count += 1;
        Q.Rear = (Q.Rear + 1) % N;
        Q.Entry[Q.Rear] = x;
    }

}

void showQueue()
{
    if (Q.Count==0)
        printf("Queue is empty\n");
    else
    {
        for (int i = 0; i < Q.Count; i++)
        {
            printf("%d ", Q.Entry[(Q.Front+i)%N]);
        }
        printf("\n");
    }
}

int QueueSize()
{
    return Q.Count;
}

int DeQueue()
{
    if (Q.Count == 0)
    {
        printf("Queue Underflow\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        int x;
        x = Q.Entry[Q.Front];
        Q.Count -= 1;
        Q.Front = (Q.Front + 1) % N;
        return x;
    }
}

bool isEmpty()
{
    if (Q.Count == 0)
        return true;
    else
        return false;
}

bool isFull()
{
    if (Q.Count == N)
        return true;
    else
        return false;
}

int peek()
{
    if (Q.Count==0)
    {
        printf("Queue Underflow\n");
        exit(EXIT_FAILURE);
    }
    else
        return Q.Entry[Q.Front];
}

int main()
{
    CreateQueue();
    EnQueue(5);
    EnQueue(10);
    EnQueue(15);
    EnQueue(20);
    EnQueue(25);
    EnQueue(30);
    showQueue();
    printf("%d\n", DeQueue());
    printf("%d\n", DeQueue());
    EnQueue(35);
    showQueue();
    printf("%d", peek());

    return 0;
}