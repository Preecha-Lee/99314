#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}typedef NODE;


NODE *Stack = NULL;

NODE* push(NODE *stack, int data)
{
    NODE *newNode = malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = stack;
    stack = newNode;

    return stack;
}

int pop()
{
    NODE *current = Stack;
    int dataout;
    if(current == NULL)
    {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        Stack = current->next;
        dataout = current->data;
        free(current);
        return dataout;
    }
}

int peek()
{
    if(Stack == NULL)
    {
        printf("Stack is empty!!\n");
        exit(EXIT_FAILURE);
    }
    else
        return Stack->data;
}

void ClearStackNode()
{
    NODE *temp=Stack;
    while (temp != NULL)
    {
        Stack = Stack->next;
        free(temp);
        temp = Stack;
    }
    
}

int length(NODE* stack)
{
    int len = 0;
    NODE *current = stack;

    while (current != NULL)
    {
        len += 1;
        current = current->next;
    }
    return len;
}

void display(NODE* stack)
{
    NODE *save = stack;
    if (save==NULL)
        printf("Stack is empty\n");
    else
    {
        printf("The elements of the stack are : ");
        while (save != NULL)
        {
            printf("%d ", save->data);
            save = save->next;
        }

        printf("\nTop element is : %d\n", peek());
    }
    
    
}

int maxElement(NODE* stack)
{
    NODE *current = stack;
    int maxnum;

    if(current == NULL)
    {
        printf("Stack is Empty!!");
        exit(EXIT_FAILURE);
    }
    else
    {
        maxnum = current->data;
        while (current != NULL)
        {
            if(maxnum < current->data)
                maxnum = current->data;
            current = current->next;
        }
        return maxnum;
    }
    

}

int main()
{
    
    int x;

    do
    {
        printf("Enter element to stack : ");
        scanf("%d", &x);
        
        if(x>0)
        {
            Stack = push(Stack, x);
            display(Stack);
            printf("Length of stack is : %d\n", length(Stack));
            printf("The maximum element is : %d\n",maxElement(Stack));
            printf("\n");
        }
    } while (x>0);

    printf("\n");

    char decision;
    do
    {
        printf("Do you want pop element in stack? : ");
        scanf("%s", &decision);
        
        if(decision=='y')
        {
            printf("The element you pop is : %d\n", pop());
            display(Stack);
            printf("Length of stack is : %d\n", length(Stack));
        }
    } while (decision=='y');

    printf("\nClear Stack!!\n");
    ClearStackNode();

    display(Stack);

    return 0;
}