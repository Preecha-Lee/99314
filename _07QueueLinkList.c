#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Entry;
    struct Node *NextNode;
}typedef QueueNode;

struct QueueType
{
    int Count;
    QueueNode *Front;
    QueueNode *Rear;
}typedef QueueType;

QueueType Q;

void CreateQueue()
{
    Q.Count = 0;
    Q.Front = NULL;
    Q.Rear = NULL;
}

QueueNode* CreateNode(int x)
{
    QueueNode *p;
    p = (QueueNode *)malloc(sizeof(QueueNode));
    p->Entry = x;

    return p;
}


void EnQueue(QueueNode* p)
{
    if(p == NULL)
        printf("Error : Try to add nothing to queue\n");
    else
    {
        Q.Count += 1;

        if (Q.Front == NULL)
        {
            Q.Front = p;
            Q.Rear = p;
        }
        else
        {
            Q.Rear->NextNode = p;
            Q.Rear = p;
        }

        p->NextNode = NULL;
    }
}

int Dequeue()
{
    QueueNode *p;

    if(Q.Front==NULL)
    {
        printf("Error : try to delete a node from empty queue\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        Q.Count -= 1;
        p = Q.Front;
        int data = p->Entry;

        Q.Front = Q.Front->NextNode;

        if(Q.Front == NULL)
            Q.Rear = NULL;

        free(p);

        return data;
    }
}

int peek()
{
    if (Q.Front == NULL)
        printf("Error : try to peek a node from empty queue\n");
    else
        return Q.Front->Entry;
}

void showQueue()
{
    QueueNode *ptr;
    ptr = Q.Front;
    while (ptr != NULL)
    {
        printf("%d ", ptr->Entry);
        ptr = ptr->NextNode;
    }

    printf("\n");
}

int main()
{
    CreateQueue();
    EnQueue(CreateNode(5));
    EnQueue(CreateNode(10));
    EnQueue(CreateNode(20));
    EnQueue(CreateNode(30));
    printf("Q.Count = %d\n",Q.Count);
    showQueue();
    printf("Remove : %d\n",Dequeue());
    EnQueue(CreateNode(40));
    EnQueue(CreateNode(50));
    showQueue();
    printf("Peek : %d, Q.Count = %d \n", peek(),Q.Count);

    return 0;
}