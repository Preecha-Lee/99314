public class _13ShellSort {
    
    public static void ShellSort(int[] A) {
        int n = A.length;
        int temp;
        int j;
        int increment = n/2;
        
        while (increment > 0) 
        {
            for (int i = increment; i < n; i++)
            {
                temp = A[i];
                j = i-increment;
                while (j >= 0 && A[j] > temp) {
                    A[j+increment] = A[j];
                    j -= increment;
                }

                A[j+increment] = temp;
            }
            
            increment /= 2;

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
        //int[] A = {12,18,4,27,32,26,11,6,8,19};
        ShellSort(A);
        showArr(A);
    }
}
