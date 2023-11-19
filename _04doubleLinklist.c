#include <stdio.h>

struct node
{
    int INFO;
    int LLINK;
    int RLINK;
}typedef NODE;

const int n = 5;
NODE memory[5];
int Avail;

void initialize()
{
    for (int i = 0; i < n - 1; ++i)
        memory[i].RLINK = i + 1;

    memory[n - 1].RLINK = -1;
    Avail = 0;
}

int ALLOCATE()
{
    int New;
    if (Avail==-1)
    {
        printf("OVERFLOW\n");
        return -1;
    }
    else
    {
        New = Avail;
        Avail = memory[Avail].RLINK;
        return New;
    }

}

void FREE(int New)
{
    memory[New].RLINK = Avail;
    Avail = New;
}

int INSFIRST(int item, int first)
{
    int New = ALLOCATE();
    if (New != -1)
    {
        memory[New].INFO = item;
        memory[New].LLINK = -1;
        memory[New].RLINK = first;

        if (first != -1)
            memory[first].LLINK = New;
        
        first = New;
    }

    return first;
}

int DELFIRST(int first)
{
    int temp;
    if (first == -1)
    {
        printf("UNDERFLOW\n");
        return -1;
    }
    else
    {
        temp = first;
        first = memory[first].RLINK;
        memory[first].LLINK = -1;
        FREE(temp);

        return first;
    }
    
}

void PRINT(int first)
{
    int PTR = first;
    int last = first;

    printf("Forward : ");
    while (PTR !=-1)
    {
        printf("%d ", memory[PTR].INFO);
        last = PTR;
        PTR = memory[PTR].RLINK;
    }

    printf("\nReverse : ");
    PTR = last;
    while (PTR != -1)
    {
        printf("%d ", memory[PTR].INFO);
        PTR = memory[PTR].LLINK;
    }
    
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
            first=INSFIRST(x,first);
    } while (x > 0);

    PRINT(first);

    do
    {
        printf("\nDo you want to delete : ");
        scanf("%d", &x);
        first = DELFIRST(first);
        PRINT(first);
    } while (x>0);
    
    return 0;
}
