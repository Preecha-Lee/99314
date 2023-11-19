#include <stdio.h>

void showArray(int arr[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j<3; ++j)
            printf("%d ", arr[i][j]);
        
        printf("\n");
    }
}

void addArray(int arr1[3][3],int arr2[3][3], int arr3[3][3])
{
    for (int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            arr3[i][j] = arr1[i][j] + arr2[i][j];
}

void subtractArray(int arr1[3][3],int arr2[3][3], int arr3[3][3])
{
    for (int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            arr3[i][j] = arr1[i][j] - arr2[i][j];
}

int main()
{
    int dummy = 1;
    int arr1[3][3];

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            arr1[i][j] = dummy;
            ++dummy;
        }

    showArray(arr1);

    int arr2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int arr3[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int sum[3][3];
    int minus[3][3];

    addArray(arr2, arr3, sum);
    subtractArray(arr2, arr3, minus);
    
    printf("\n");
    showArray(sum);
    
    printf("\n");
    showArray(minus);

    return 0;
}