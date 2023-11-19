#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *link;
}typedef NODE;

struct set
{
    NODE* first;
    int count;
}typedef Set;


NODE* createNode(int item, NODE* link_item)
{
    NODE *N = (NODE *)malloc(sizeof(NODE));
    N->data = item;
    N->link = link_item;

    return N;
}

Set createSet()
{
    Set S;
    S.first = NULL;
    S.count = 0;

    return S;
}

bool isEmpty(Set S)
{
    if (S.count==0)
        return true;
    else
        return false;
}

bool contain(Set S, int item)
{
    NODE *ptr = S.first;
    while (ptr != NULL)
    {
        if (ptr->data == item)
            return true;

        ptr = ptr->link;
    }

    return false;
}

Set add(Set S, int item)
{
    NODE *ptr = S.first;

    if (!contain(S, item))
    {
        S.first = createNode(item, ptr);
        S.count += 1;
    }

    return S;
}

Set Remove(Set S, int item)
{
    NODE *temp;
    NODE *ptr;

    if (S.first != NULL)
    {
        if (S.first->data==item)
        {
            temp = S.first;
            S.first = S.first->link;
            free(temp);
            S.count -= 1;
        }
        else
        {
            ptr = S.first;
            while (ptr->link != NULL && ptr->link->data != item)
                ptr = ptr->link;
            
            if (ptr->link != NULL)
            {
                temp = ptr->link;
                ptr->link = ptr->link->link;
                free(temp);
                S.count -= 1;
            }
            
        }
    
    }

    return S;
}

int size(Set S)
{
    return S.count;
}


void display(Set S)
{
    NODE *ptr = S.first;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}


int main()
{
    Set S = createSet();

    int x;
    do
    {
        printf("Enter to link list : ");
        scanf("%d", &x);
        if (x>0)
        {
            S = add(S, x);
            printf("   Number of elements : %d\n", size(S));
        }
    } while (x > 0);

    display(S);

    do
    {
        printf("What member do you want to delete : ");
        scanf("%d", &x);
        if(x>0)
        {
            S = Remove(S,x);
            
            if(contain(S,x))
                printf("Set contain %d\n", x);
            else
                printf("Set NOT contain %d\n", x);

            display(S);
        }
    } while (x>0);

    return 0;
}