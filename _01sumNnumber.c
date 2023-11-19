#include <stdio.h>

int main()
{
    int N;

    printf("N = ");
    scanf("%d",&N);

    int sum = 0;
    int x;
    for (int i = 1; i <= N; ++i)
    {
        printf("Enter your number : ");
        scanf("%d", &x);
        sum += x;
    }

    printf("Sum of all number is : %d", sum);

    return 0;
}