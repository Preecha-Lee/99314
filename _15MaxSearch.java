public class _15MaxSearch {
    
    private static int maxSearch(int[] A) {
        int x = A[0];
        
        for (int i = 1; i < A.length; i++) {
            if (A[i] > x)
                x = A[i];
        }

        return x;
    }

    public static void main(String[] args) {
        int[] A = { 15, 19, 9, 7, 23, 64, 11, 53 };
        System.out.println("Maximum of A is "+maxSearch(A));
    }
}
