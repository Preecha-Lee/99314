//Array must be sort first in asc order
public class _15JumpSearch {
    
    private static int jumpSearch(int[] A, int x) {
        int n = A.length;
        int k = (int) Math.sqrt(n);
        int step = k;
        int prev = 0;

        while (step <= (n - 1) && A[step] < x) {
            prev = step;
            step = step + k;
        }
        
        if (step > (n - 1))
            step = n - 1;
        
        if (A[step] == x)
            return step;
        
        while (A[prev] < x) {
            prev += 1;
            if (prev == step)
                return -1;
        }
        
        if (A[prev] == x)
            return prev;
        else
            return -1;
    }

    public static void main(String[] args) {
        int[] A = { 5, 24, 33, 43, 68, 73, 90, 91 };
        int x = 73;
        System.out.println("Found x = "+x+" at position "+jumpSearch(A, x));
    }
}
