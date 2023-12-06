public class _15BruteForceSearch {
    
    private static int bruteForceSearch(int[] A, int x)
    {
        for (int i = 0; i < A.length; i++)
            if(A[i]==x)
                return i;

        return -1;
    }

    public static void main(String[] args) {
        int[] A = { 5, 90, 70, 93, 68, 73, 24, 91 };
        int x = 93;
        System.out.println("Find x = "+x+" at position "+bruteForceSearch(A, x));
    }
}
