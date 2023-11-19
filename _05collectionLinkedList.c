#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *link;
}typedef NODE;

struct collection
{
    NODE* first;
    int count;
}typedef Collection;


NODE* createNode(int item, NODE* link_item)
{
    NODE *N = (NODE *)malloc(sizeof(NODE));
    N->data = item;
    N->link = link_item;

    return N;
}

Collection createCollection()
{
    Collection C;
    C.first = NULL;
    C.count = 0;

    return C;
}

bool isEmpty(Collection C)
{
    if (C.count==0)
        return true;
    else
        return false;
}

bool contain(Collection C, int item)
{
    NODE *ptr = C.first;
    while (ptr != NULL)
    {
        if (ptr->data == item)
            return true;

        ptr = ptr->link;
    }

    return false;
}

Collection add(Collection C, int item)
{
    NODE *ptr = C.first;
    C.first = createNode(item, ptr);
    C.count += 1;
    return C;
}

Collection Remove(Collection C, int item)
{
    NODE *temp;
    NODE *ptr;

    if (C.first != NULL)
    {
        if (C.first->data==item)
        {
            temp = C.first;
            C.first = C.first->link;
            free(temp);
            C.count -= 1;
        }
        else
        {
            ptr = C.first;
            while (ptr->link != NULL && ptr->link->data != item)
                ptr = ptr->link;
            
            if (ptr->link != NULL)
            {
                temp = ptr->link;
                ptr->link = ptr->link->link;
                free(temp);
                C.count -= 1;
            }
            
        }
    
    }

    return C;
}

int size(Collection C)
{
    return C.count;
}


void display(Collection C)
{
    NODE *ptr = C.first;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}


int main()
{
    Collection C = createCollection();

    int x;
    do
    {
        printf("Enter to link list : ");
        scanf("%d", &x);
        if (x>0)
        {
            C = add(C, x);
            printf("   Number of elements : %d\n", size(C));
        }
    } while (x > 0);

    display(C);

    do
    {
        printf("What member do you want to delete : ");
        scanf("%d", &x);
        if(x>0)
        {
            C = Remove(C,x);
            
            if(contain(C,x))
                printf("Collection contain %d\n", x);
            else
                printf("Collection NOT contain %d\n", x);

            display(C);
        }
    } while (x>0);

    return 0;
}