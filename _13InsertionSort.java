public class _13InsertionSort {
    
    public static void insertionSort(int[] A) {
        int n = A.length;
        int temp;
        int j;

        for (int i=1; i<=(n-1); i++)
        {
            temp = A[i];
            j = i - 1;

            while (j >= 0 && A[j] > temp) 
            {
                A[j + 1] = A[j];
                j -= 1;
            }
            
            A[j + 1] = temp;
        }
    }

    public static void showArr(int[] A) {
        int n = A.length;
        for (int i = 0; i < n; ++i)
            System.out.print(A[i] + " ");

        System.out.println();
    }
    
    public static void main(String[] args) {
        int[] A = { 3, 5, 4, 2, 9, 4, 7, 2, 1, 1, 3, 5 };
        insertionSort(A);
        showArr(A);
    }
}
