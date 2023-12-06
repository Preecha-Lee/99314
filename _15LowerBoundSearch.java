public class _15LowerBoundSearch {
    
    private static int lowerBoundSearch(int[] A, int x) {
        int left = 0;
        int right = A.length - 1;
        int pos;

        while (left < right) 
        {
            pos = (left + right) / 2;
            
            if(x <= A[pos])
                right = pos;
            else
                left = pos + 1;
        }
        if (x <= A[left])
            return left;
        else
            return -1;

    }
    
    public static void main(String[] args) {
        int[] A = { 5, 24, 33, 43, 68, 73, 90, 91 };
        int x = 69;
        System.out.println(x+" is Lower bound at position "+lowerBoundSearch(A, x));
    }
}
