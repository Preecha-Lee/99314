//Array must be sort first in asc order
public class _15LinearSearch {
    
    private static int linearSearch(int[] A, int x) {
        for (int i = 0; i < A.length; i++) {
            if (A[i] == x)
                return i;
            else if (A[i] > x)
                return -1;
        }
        
        return -1;
    }
    
    public static void main(String[] args) {
        int[] A = { 5, 24, 33, 43, 68, 73, 90, 91 };
        int x = 90;
        System.out.println("x = "+x+" is found at position "+linearSearch(A, x));
    }
}
