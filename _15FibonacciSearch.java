public class _15FibonacciSearch {

    private static int fibonacciSearch(int[] A, int x)
    {
        int n = A.length-1;
        int f1 = 1;
        int f2 = 1;
        int remain = 2;

        while (f1 <= n) 
        {
            f1 = f1 + f2;
            f2 = f1 - f2;
            remain += 1;
        }
        
        f2 = f1 - f2;
        f1 = f1 - f2;
        remain -= 1;

        int first = 0;
        int index;

        while (remain > 0) 
        {
            index = first + f1;
            if(index > n || x < A[index])
            {
                remain -= 1;
                f2 = f1 - f2;
                f1 = f1 - f2;
            }
            else if(x == A[index])
                return index;
            else
            {
                first = index;
                remain -= 2;
                f1 = f1 - f2;
                f2 = f2 - f1;
            }
            
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] A = { -1, 10,20,30,40,50,60,70,80,90,100,110,120,130};
        int x = 120;
        System.out.println("x = "+x+" found at position "+fibonacciSearch(A, x)); 
    }
}