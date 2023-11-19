#include <stdio.h>

int firstMethod(int arr[], int n)
{
    int maxSum = arr[0];
    int thisSum;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            thisSum = 0;
            for (int k = i; k <= j; ++k)
                thisSum = thisSum + arr[k];
            
            if(thisSum>maxSum)
                maxSum = thisSum;
        }
    }

    return maxSum;
}

int secondMethod(int arr[], int n)
{
    int maxSum = arr[0];
    int thisSum;

    for (int i = 0; i < n; ++i)
    {
        thisSum = 0;
        for (int j = i; j < n; ++j)
        {
            thisSum = thisSum + arr[j];

            if (thisSum>maxSum)
                maxSum = thisSum;
        }
    }

    return maxSum;
}

int max(int a, int b, int c)
{
    if (a>b && a>c)
        return a;
    else if(b>c)
        return b;
    else
        return c;
}

int thirdMethod(int arr[],int left, int right)
{
    if(left==right)
        return arr[left];

    int center = (left + right) / 2;
    int maxLeftSum = thirdMethod(arr, left, center);
    int maxRightSum = thirdMethod(arr, center + 1, right);
    
    int leftBorderSum = 0;
    int maxLeftBoderSum = arr[center];

    for (int i = center; i >= left; --i)
    {
        leftBorderSum = leftBorderSum + arr[i];
        if(leftBorderSum>maxLeftBoderSum)
            maxLeftBoderSum = leftBorderSum;
    }

    int rightBorderSum = 0;
    int maxRightBoderSum = arr[center+1];

    for (int j = center+1; j <= right; ++j)
    {
        rightBorderSum = rightBorderSum + arr[j];
        if(rightBorderSum>maxRightBoderSum)
            maxRightBoderSum = rightBorderSum;
    }

    return max(maxLeftSum, maxRightSum, maxLeftBoderSum + maxRightBoderSum);
}

int forthMethod(int arr[],int n)
{
    int thisSum = 0;
    int maxSum = arr[0];

    for (int i = 0; i < n; ++i)
    {
        thisSum = thisSum + arr[i];
        if (thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum<0)
            thisSum = 0;
    }

    return maxSum;
}

int main()
{
    int x[] = {-12, 5, -7, 9, 14, -5, 2, -24, 14};
    int n = sizeof(x) / sizeof(int);

    int maxsum1 = firstMethod(x, n);
    int maxsum2 = secondMethod(x, n);
    int maxsum3 = thirdMethod(x, 0, n-1);
    int maxsum4 = forthMethod(x, n);

    printf("maximum subarray sum form First method : %d\n", maxsum1);
    printf("maximum subarray sum form Second method : %d\n", maxsum2);
    printf("maximum subarray sum form Third method : %d\n", maxsum3);
    printf("maximum subarray sum form Forth method : %d\n", maxsum4);
    return 0;
}