#include <stdio.h>

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 2; j <= 6; j++)
            printf("%d*%d = %d ", j, i, j * i);

        printf("\n");
    }
            return 0;
}