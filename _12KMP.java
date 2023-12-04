public class _12KMP {
    public static int[] preKMP(String P) {
        int m = P.length();
        int[] w = new int[m + 1];

        int i = 0;
        int j = -1;
        w[i] = j;

        while (i < m) {
            while (j >= 0 && P.charAt(i) != P.charAt(j))
                j = w[j];

            i += 1;
            j += 1;
            w[i] = j;
        }

        return w;
    }
    
    public static int kmpSearch(String T, String P) {
        int i = 0;
        int j = 0;
        int n = T.length();
        int m = P.length();
        int[] w = preKMP(P);

        while (i<n) {
            while (j>=0 && T.charAt(i) != P.charAt(j))
                j = w[j];
            
            i += 1;
            j += 1;

            if (j == m)
                return i - j;
        }

        return -1;
    }

    public static void main(String[] args) {
        String T = "dffhhbbaabdfbbbaabbbbvffgaa";
        String P = "bbbaab";

        System.out.println(kmpSearch(T, P));
    }
}
