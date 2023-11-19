#include <stdio.h>

int main()
{
    float w, h;
    printf("Enter width and height respectiely : ");
    scanf("%f %f", &w,&h);

    float area = w * h;
    printf("Area of a reagtangle is : %.2f", area);

    return 0;
}