public class _12BruceForceStringMatch {

    public static int bruceForceStringMatch(String T, String P) {
        int n = T.length();
        int m = P.length();

        for (int i = 0; i <= (n - m); i++){
            int j = 0;
            
            while (j < m && (P.charAt(j) == T.charAt(i + j)))
                j += 1;
            
            if(j==m)
                return i;
        }

        return -1;
    }

    public static void main(String[] args) {
        String T = "kjhpreecloipreechakiju";
        String P = "preecha";
        System.out.println("Match at index : "+bruceForceStringMatch(T, P));
    }
}