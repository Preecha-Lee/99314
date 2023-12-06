public class _14MergeSort {

    private static void merge(int[] A, int[] B, int first, int middle, int last) 
    {
        int leftFirst = first;
        int rightFirst = middle + 1;

        int i = first;

        while (i <= last) {
            if (leftFirst > middle) {
                B[i] = A[rightFirst];
                rightFirst += 1;
            } else if (rightFirst > last) {
                B[i] = A[leftFirst];
                leftFirst += 1;
            } else if (A[leftFirst] <= A[rightFirst]) {
                B[i] = A[leftFirst];
                leftFirst += 1;
            } else {
                B[i] = A[rightFirst];
                rightFirst += 1;
            }

            i += 1;
        }

        for(int k=first; k<=last; k++)
            A[k] = B[k];
    }
    
    private static void divide(int[] A, int[] B, int first, int last)
    {
        if (last == first)
            B[last] = A[last];
        else
        {
            int middle = (first + last) / 2;
            divide(A, B, first, middle);
            divide(A, B, middle + 1, last);
            merge(A, B, first, middle, last);
        }
    }
    
    public static void mergeSort(int[] A)
    {
        int n = A.length;
        int[] B = new int[n];
        divide(A, B, 0,n-1);
    }
    
    public static void showArr(int[] A) {
        int n = A.length;
        for (int i = 0; i < n; ++i)
            System.out.print(A[i] + " ");

        System.out.println();
    }
    
    public static void main(String[] args) {
        //int[] A = { 3, 5, 4, 2, 9, 4, 7, 2, 1, 1, 3, 5 };
        int[] A = {12,18,4,27,32,26,11,6,8,19};
        mergeSort(A);
        showArr(A);
    }
}