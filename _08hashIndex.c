#include <stdio.h>
#include <string.h>

int indAlphabet(char s[])
{
    int ind = 0;
    for (int i = 0; i < strlen(s); ++i)
    {
        ind = ind + (s[i]-64);
    }
    
    return ind;
}

int main()
{
    char subject[8][15] = {"ALGEBRA","ALGORITHM","CALCULUS","COMPILER","DATABASE","MULTIMEDIA","PROBABILITY","STATISTICS"};

    for (int i = 0; i < 8; ++i)
        printf("%s %d\n", subject[i] ,indAlphabet(subject[i]));
    
    return 0;
}