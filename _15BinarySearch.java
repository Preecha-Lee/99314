//Array must be sort first in asc order
public class _15BinarySearch {

    private static int binarySearch(int[] A,int x)
    {
        int left = 0;
        int right = A.length - 1;
        int pos;

        while (left <= right) 
        {
            pos = (left + right) / 2;
            if(x == A[pos])
                return pos;
            else if( x < A[pos])
                right = pos - 1;
            else
                left = pos + 1;
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] A = { 5, 24, 33, 43, 68, 73, 90, 91 };
        int x = 40;
        System.out.println("x = "+x+" is found at position "+binarySearch(A, x));
    }
}
