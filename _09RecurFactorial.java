public class _09RecurFactorial {
    
    public static long recursiveFactorial(long n) {
        if (n==0)
            return 1;
        else
            return n * recursiveFactorial(n - 1);
    }

    public static void main(String[] args) {
        System.out.println(recursiveFactorial(6));
    }
}
