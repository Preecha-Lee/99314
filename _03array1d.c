#include <stdio.h>

int main()
{
    char name[10];
    printf("What is your name?\n");
    scanf("%s", name);
    printf("You are %s", name);

    return 0;
}