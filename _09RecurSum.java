public class _09RecurSum {
    
    public static int recursiveSum(int n) {
        if (n == 1) {
            System.out.println("Returned (base case) " + n);
            return n;
        }
        else {
            int tmp;
            tmp = n + recursiveSum(n - 1);
            System.out.println("Returned (general case) " + tmp);
            return tmp;
        }
    }

    public static void main(String[] args) {
        recursiveSum(5);
    }
}
