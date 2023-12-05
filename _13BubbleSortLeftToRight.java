public class _13BubbleSortLeftToRight {

    public static void BubbleSortLeftToRight(int[] A)
    {
        int n = A.length;
        int temp;

        for (int i = 0; i <= n - 2; ++i) {
            for (int j = 1; j <= (n - 1 - i); j++)
                if (A[j - 1] > A[j]) {
                    temp = A[j - 1];
                    A[j - 1] = A[j];
                    A[j] = temp;
                }
        }

    }
    
    public static void showArr(int[] A) {
        int n = A.length;
        for (int i=0; i<n; ++i)
            System.out.print(A[i] + " ");

        System.out.println();
    }

    public static void main(String[] args) {
        int[] A = { 3, 5, 4, 2, 9, 4, 7, 2, 1, 1, 3, 5 };
        BubbleSortLeftToRight(A);
        showArr(A);
    }
}