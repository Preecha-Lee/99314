public class _09RecurPower {
    
    public static long recursivePower(long a, long n) {
        if (n==0)
            return 1;
        else
            return a * recursivePower(a, n - 1);
    }

    public static void main(String[] args) {
        System.out.println(recursivePower(5, 4));
    }
}
