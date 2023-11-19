#include <stdio.h>

struct node
{
    int INFO;
    int LINK;
}typedef NODE;

const int n = 5;
NODE memory[5];
int Avial;

void initialize()
{
    for (int i = 0; i < n - 1; ++i)
        memory[i].LINK = i + 1;

    memory[n-1].LINK = -1;
    Avial = 0;
}

int ALLOCATE()
{
    int New;
    if (Avial==-1)
    {
        printf("Overflow\n");
        return -1;
    }
    else
    {
        New = Avial;
        Avial = memory[Avial].LINK;
    }
    return New;
}

void FREE(int New)
{
    if (Avial==-1)
    {
        Avial = New;
        memory[Avial].LINK = -1;
    }
    else
    {
        memory[New].LINK = Avial;
        Avial = New;
    }
    
}

int INSFIRST(int item, int first)
{
    int New = ALLOCATE();
    if (New != -1)
    {
        memory[New].INFO = item;
        memory[New].LINK = first;
        first = New;
    }

    return first;
}

int DELFIRST(int first)
{
    int temp;
    if (first == -1)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        temp = first;
        first = memory[first].LINK;
        FREE(temp);

        return first;
    }
    
}


void PRINT(int first)
{
    int PTR = first;
    while (PTR != -1)
    {
        printf("%d ", memory[PTR].INFO);
        PTR = memory[PTR].LINK;
    }
    printf("\n");
}

int COUNT(int first)
{
    int NUM = 0;
    int PTR = first;
    
    while (PTR != -1)
    {
        ++NUM;
        PTR = memory[PTR].LINK;
    }

    return NUM;
}

int SEARCH(int first, int item)
{
    int PTR = first;
    int LOC;

    while (PTR != -1)
    {
        if (item == memory[PTR].INFO)
        {
            LOC = PTR;
            return LOC;
        }
        else
            PTR = memory[PTR].LINK;        
    }

    return -1;
}

int main()
{
    initialize();
    int first = -1;

    int x;
    do
    {
        printf("Enter to link list : ");
        scanf("%d", &x);
        if (x>0)
        {
            first=INSFIRST(x,first);
            printf("   Number of elements : %d\n", COUNT(first));
        }
    } while (x > 0);

    PRINT(first);

    do
    {
        printf("Do you want to delete : ");
        scanf("%d", &x);
        if(x>0)
        {
            first = DELFIRST(first);
            PRINT(first);
        }
    } while (x>0);
    

    do
    {
        printf("Do you want to search : ");
        scanf("%d", &x);
        
        if(x>0)
            printf("Found at : %d\n", SEARCH(first,x));
    } while (x>0);
}