public class _09Fibonacci {
    
    public static long fibonacci(long n) {
        if (n <= 2)
            return 1;
        else
            return fibonacci(n - 1) + fibonacci(n - 2);
    }

    public static void main(String[] args) {
        System.out.println(fibonacci(9));
    }
}
