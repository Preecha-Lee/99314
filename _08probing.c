#include <stdio.h>
#include <stdbool.h>

void initialize(int t[], int n)
{
    for (int i = 0; i < n; ++i)
        t[i] = -1;
}

bool isFull(int t[], int n)
{
    for (int i = 0; i < n; ++i)
        if(t[i]==-1)
            return false;

    return true;
}


void showTable(int t[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d\n",t[i]);
}

int h(int i, int m)
{
    return i % m;
}

void linearProbing(int key, int t[], int n)
{
    if (isFull(t,n))
    {
        printf("Full Table!!!");
        return;
    }

    int first = h(key,n);
    int probe = first;
    int i = 1;

    while (t[probe] !=-1)
    {
        probe = (first + i)%n;
        i++;
    }

    t[probe] = key;
    printf(" iterate = %d\n",i);
}


void quadraticProbing(int key, int t[], int n)
{
    if (isFull(t,n))
    {
        printf("Full Table!!!");
        return;
    }

    int first = h(key, n);
    int probe = first;
    int i = 1;

    if (t[probe] != -1)
    {
        do
        {
            probe = (first + i*i)%n;
            i++;
        } while (t[probe] != -1 && probe != first);
        
        if (probe == first)
        {
            printf("Secondary Clustering!!!\n");
            return;
        }
        
    }

    t[probe] = key;
    printf(" iterate = %d\n",i);
}


int h2(int key, int p)
{
    return 1 + (key % p);
}

int h3(int key, int p)
{
    return p-(key % p);
}


void doubleProbing(int key, int t[], int n, int p)
{
    if (isFull(t,n))
    {
        printf("Full Table!!!");
        return;
    }

    int first = h(key,n);
    int second = h2(key, p);
    int probe = first;

    int i = 1;

    while (t[probe] !=-1)
    {
        probe = (first + i*second)%n;
        i++;
    }

    t[probe] = key;
    printf(" iterate = %d\n",i);
}


int n = 13;
int p = 11;

int main()
{
    int table[13];
    int key;
    initialize(table, n);

    do
    {
        printf("Enter Key : ");
        scanf("%d", &key);

        if(key>0)
            //linearProbing(key, table, n);
            //quadraticProbing(key, table, n);
            doubleProbing(key,table,n,p);

    }while(key !=0);

    showTable(table, n);

    return 0;
}