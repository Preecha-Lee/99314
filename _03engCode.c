#include <stdio.h>
#include <string.h>

char eng[27];

void initialize()
{
    eng[0] = 'a';
    for (int i = 1; i < 26; ++i)
        eng[i] = eng[i - 1] + 1;

    eng[26] = ' ';
}

void encoding(char sample[], int n)
{
    char encode[20];
    int index;
    for (int i = 0; i < n; ++i)
    {
        if (sample[i] == ' ')
            index = 26;
        else
            index = (int)sample[i] - 97;
        
        encode[i] = eng[(index + 3) % 27];
    }
    encode[n] = '\0';

    printf("%s", encode);
}

void decoding(char sample[], int n)
{
    char decode[20];
    int index;
    for (int i = 0; i < n; ++i)
    {
        if (sample[i] == ' ')
            index = 26;
        else
            index = (int)sample[i] - 97;
        
        decode[i] = eng[(index-3+27) % 27];
    }
    decode[n] = '\0';

    printf("%s", decode);
}

int main()
{
    initialize();
    char sample[20];
    int n;


    printf("Enter text : ");
    fgets(sample, 20, stdin);
    n = strlen(sample);

    //encoding(sample, n);
    decoding(sample, n);

    return 0;
}