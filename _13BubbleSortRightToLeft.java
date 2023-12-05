public class _13BubbleSortRightToLeft {
    public static void BubbleSortRightToLeft(int[] A) {
        int n = A.length;
        int temp;

        for (int i = 1; i <= n - 1; i++) {
            for (int j = n - 1; j >= i; j--)
                if (A[j] < A[j - 1]) 
                {
                    temp = A[j];
                    A[j] = A[j-1];
                    A[j-1] = temp;
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
        BubbleSortRightToLeft(A);
        showArr(A);
    }
}
