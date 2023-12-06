public class _15InterpolationSearch {
    
    private static int interpolationSearch(int[] A, int x)
    {
        int left = 0;
        int right = A.length - 1;
        float adjust;
        int mid;

        while (left <= right) 
        {
            if (A[left] == A[right]) {
                if (A[left] == x)
                    return left;
                else
                    return -1;
            }
            
            adjust = (float) (x - A[left]) / (float) (A[right] - A[left]);

            if (adjust < 0 || adjust > 1)
                return -1;

            mid = left + (int) (adjust * (right - left));

            if (x<A[mid])
                right = mid - 1;
            else if(x>A[mid])
                left = mid + 1;
            else
                return mid;
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] A = { 5, 24, 33, 43, 68, 73, 90, 91 };
        int x = 200;
        System.out.println("Found x = "+x+" at position "+interpolationSearch(A, x));
    }
}
