#include <stdio.h>

void showTable(int t[12][11])
{
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 11; ++j)
            printf("%d ",t[i][j]);

        printf("\n");
    }
}

int main()
{
    int t[12][11];

    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 11; ++j)
            t[i][j] = (j + 2)*(i + 1);

    showTable(t);

    return 0;
}