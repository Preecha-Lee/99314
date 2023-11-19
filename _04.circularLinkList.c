#include <stdio.h>

struct node
{
    int INFO;
    int LINK;
}typedef NODE;

const int n = 8;
NODE memory[8];
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
    memory[New].LINK = Avial;
    Avial = New;
}

int INSFIRST(int item, int last)
{
    int New = ALLOCATE();
    if (New != -1)
    {
        memory[New].INFO = item;
        if (last == -1)
        {
            memory[New].LINK = New;
            last = New;
        }
        else
        {
            memory[New].LINK = memory[last].LINK;
            memory[last].LINK = New;
        }
      
    }
    
    return last;
}


int INSLAST(int item, int last)
{
    int New = ALLOCATE();
    if (New != -1)
    {
        memory[New].INFO = item;
        if (last == -1)
        {
            memory[New].LINK = New;
            last = New;
        }
        else
        {
            memory[New].LINK = memory[last].LINK;
            memory[last].LINK = New;
            last = New;
        }
      
    }
    
    return last;
}


int DELLAST(int last)
{
    int next;
    int previous;
    int temp;

    if (last == -1)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        next = memory[last].LINK;
        if (next == last)
        {
            FREE(last);
            return -1;
        }
        else
        {
            temp = next;
            while (temp != last)
            {
                previous = temp;
                temp = memory[temp].LINK;
            }

            memory[previous].LINK = next;
            FREE(last);
            last = previous;

            return last;
        }
        
    }
    
}


void PRINT(int last)
{
    int PTR = last;
    if (last != -1)
    {
        do
        {
            PTR = memory[PTR].LINK;
            printf("%d ", memory[PTR].INFO);
        } while (PTR != last);

        printf("\n");
    }
}


int main()
{
    initialize();
    int last = -1;

    int x;
    do
    {
        printf("Enter for insert FIRST : ");
        scanf("%d", &x);
        if (x>0)
            last=INSFIRST(x,last);
    } while (x > 0);

    PRINT(last);
    printf("\n");

    do
    {
        printf("Enter for insert LAST : ");
        scanf("%d", &x);
        if (x>0)
            last=INSLAST(x,last);
    } while (x > 0);

    PRINT(last);
    printf("\n");

    do
    {
        printf("Do you want to delete : ");
        scanf("%d", &x);
        last = DELLAST(last);
        PRINT(last);
    } while (x>0);
    
}