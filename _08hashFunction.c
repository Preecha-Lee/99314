#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int divisionMethod(int key, int m)
{
    int ind;
    ind = key % m;

    return ind;
}

int midSquare(int key, int pos)
{
    long i;
    i = pow(key, 2);
    
    char s[40];
    char substr[3];
    itoa(i, s, 10);

    substr[0] = s[strlen(s) - pos - 1];
    substr[1] = s[strlen(s) - pos];
    substr[2] = '\0';

    return atoi(substr);
}

int folding(int key, int n)
{
    char s[15];
    itoa(key,s,10);

    int n_fold = strlen(s)/n;
    int m = pow(10, n_fold);
    int sum = 0;

    for (int i = 1; i <= n; ++i)
    {
        sum = sum + (key % m);
        key = key / m;
    }

    return sum % m;
}

int main()
{
    int key = 7396;
    int n = 4;

    printf("%d", midSquare(key,n));
    return 0;
}